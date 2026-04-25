.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

VDD = 000Ah
MINIVDD_SVC_BASE_OFFSET	= 80h
VDD_GET_DISPLAY_CONFIG = 85h

externFP  GetPrivateProfileString
externFP  GetPrivateProfileInt

sBegin	Data

PUBLIC npdisp_request
npdisp_request	db	100	DUP(?)
PUBLIC npdisp_retValue
npdisp_retValue	dd	?

PUBLIC g_cfgLoaded
g_cfgLoaded     db  0

PUBLIC g_isWin9x
g_isWin9x       db  0

szSystemIni		db	"system.ini",0
szBootDesc      db  'boot.description',0
szAspect        db  'aspect',0

szDrvSect       db  'npdisp.drv',0
szWidth         db  'width',0
szHeight        db  'height',0
szColors        db  'bpp',0

; default aspect
szAspectDef     db  '100,0,0',0

; work buffer
aspectBuf       db  32 dup (0)

; public g_DpiX, g_DpiY, g_ScreenWidth, g_ScreenHeight, g_bpp
g_DpiX          dw  96
g_DpiY          dw  96
g_ScreenWidth   dw  640
g_ScreenHeight  dw  480
g_bpp     		dw  4

NPDISP_REQUEST_Init struc
npdr_init_version   		dw	?
npdr_init_funcOrder 		dw	?
npdr_init_returnCode		dw	?
npdr_init_reserved  		dw	?
npdr_init_dpiX				dw	?
npdr_init_dpiY				dw	?
npdr_init_width				dw	?
npdr_init_height			dw	?
npdr_init_bpp				dw	?
NPDISP_REQUEST_Init ends

; for Win9x
PUBLIC VDDEntryPoint
VDDEntryPoint	dd	0
PUBLIC OurVMHandle
OurVMHandle		dw	0

NPDISP_DISPLAYINFO  struc
diHdrSize				dw  ?
diInfoFlags				dw  ?
diDevNodeHandle			dd  ?
diDriverName			db  16 dup(?)
diXRes					dw  ?
diYRes					dw  ?
diDPI					dw  ?
diPlanes				db  ?
diBpp					db  ?
diRefreshRateMax		dw  ?
diRefreshRateMin		dw  ?
diLowHorz				dw  ?
diHighHorz				dw  ?
diLowVert				dw  ?
diHighVert				dw  ?
diMonitorDevNodeHandle	dd  ?
diHorzSyncPolarity		db  ?
diVertSyncPolarity		db  ?
NPDISP_DISPLAYINFO ends

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

;-----------------------------------------------------------------------
; DriverInit
;
; Windows display driver initialization.  Called at driver load time.
; Entry:
;       CX = size of heap
;       DI = module handle
;       DS = automatic data segment
;       ES:SI = address of command line (not used)
;-----------------------------------------------------------------------
cProc   DriverInit,<FAR,PUBLIC,WIN>,<si,di>
cBegin
	;push	_TEXT
	;call	GlobalSmartPageLock

	mov     ax,1684h ; INT 2Fh GET DEVICE API ENTRY POINT
	mov     bx,VDD ; VDDのVxD ID
	int     2fh ; VDDのAPI Entry Point
	mov     ax,es
	or      ax,di
	jz      .NoVDDApi ; VDDがとれなければWin3.1
	
	mov     word ptr VDDEntryPoint,di
	mov     word ptr VDDEntryPoint+2,es
	mov     ax,1683h
	int     2fh
	mov     OurVMHandle,bx
	
	mov		g_isWin9x,1

.NoVDDApi:

	call far ptr SendNPDispInitialize
	
    mov     ax,1                    ;initialization successful.
cEnd

public	SendNPDispInitialize
SendNPDispInitialize proc far

	push ax
	push dx
	
	call far ptr LoadDisplaySettingsFromSystemIni
	
	; Win9xならVDDから取得 
	cmp g_isWin9x, 1
	jne .loadSettingsEnd
	call far ptr LoadDisplaySettingsFromVDD
.loadSettingsEnd:
	
;NPDISP_REQUEST_Init struc
;npdr_init_version   		dw	?
;npdr_init_funcOrder 		dw	?
;npdr_init_returnCode		dw	?
;npdr_init_reserved  		dw	?
;npdr_init_dpiX				dw	?
;npdr_init_dpiY				dw	?
;npdr_init_width			dw	?
;npdr_init_height			dw	?
;npdr_init_bpp				dw	?
;NPDISP_REQUEST_Init ends

	EnterCrit
	mov npdisp_request.npdr_init_version, NPDISP_VERSION
	mov npdisp_request.npdr_init_funcOrder, 0
	mov npdisp_request.npdr_init_returnCode, 0ffffh ; あり得ない値にしておく 
	mov ax, g_DpiX
	mov npdisp_request.npdr_init_dpiX, ax
	mov ax, g_DpiY
	mov npdisp_request.npdr_init_dpiY, ax
	mov ax, g_ScreenWidth
	mov npdisp_request.npdr_init_width, ax
	mov ax, g_ScreenHeight
	mov npdisp_request.npdr_init_height, ax
	mov ax, g_bpp
	mov npdisp_request.npdr_init_bpp, ax
    mov dx, 07e8h
	mov ax, OFFSET npdisp_request
	out dx, al
	mov al, ah
	out dx, al
	mov ax, SEG npdisp_request
	out dx, al
	mov al, ah
	out dx, al
    mov dx, 07e9h
    mov al, 'N'
    out dx, al
    mov al, 'P'
    out dx, al
    mov al, '2'
    out dx, al
    mov al, '1'
    out dx, al
    LeaveCrit
	pop dx
	pop ax
	
	mov		g_cfgLoaded, 1

	retf
SendNPDispInitialize endp

;-----------------------------------------------------------
; skip_to_next_field
;   DS:SI = current string position
;   moves SI to char after next ',' or to NUL
;-----------------------------------------------------------
skip_to_next_field proc near
.stnf_loop:
    lodsb
    or      al, al
    jz      .stnf_done
    cmp     al, ','
    jne     .stnf_loop
.stnf_done:
    ret
skip_to_next_field endp

;-----------------------------------------------------------
; parse_dec
;   DS:SI = decimal string
;   Parses consecutive decimal digits
;   Returns AX=value
;   SI stops at first non-digit
;-----------------------------------------------------------
parse_dec proc near
    xor     ax, ax            ; result
.pd_loop:
    mov     bl, [si]
    cmp     bl, '0'
    jb      .pd_done
    cmp     bl, '9'
    ja      .pd_done

    ; ax = ax * 10 + (bl - '0')
    mov     dx, ax
    shl     ax, 1             ; x2
    shl     dx, 3             ; x8
    add     ax, dx            ; x10

    xor     bh, bh
    sub     bl, '0'
    add     ax, bx

    inc     si
    jmp     .pd_loop
.pd_done:
    ret
parse_dec endp

;-----------------------------------------------------------
; parse_aspect_string
;   aspectBuf = "AspectXY,LogPixelsX,LogPixelsY"
;   we ignore first field and read 2nd/3rd into g_DpiX/g_DpiY
;-----------------------------------------------------------
parse_aspect_string proc near
    push    ds
    push    si

    ; DS assumed valid for our data segment in display driver context
    mov     si, OFFSET aspectBuf

    ; skip field 1 (AspectXY)
    call    skip_to_next_field

    ; field 2 = LogPixelsX
    call    parse_dec
    mov     g_DpiX, ax

    ; if current char is ',', skip it
    cmp     byte ptr [si], ','
    jne     .parse_y
    inc     si

.parse_y:
    ; field 3 = LogPixelsY
    call    parse_dec
    mov     g_DpiY, ax

    pop     si
    pop     ds
    ret
parse_aspect_string endp

;-----------------------------------------------------------
; LoadDisplaySettingsFromSystemIni
;
; Reads:
;   [boot.description] aspect=100,96,96
;   [npdisp.drv] width=...
;   [npdisp.drv] height=...
;   [npdisp.drv] bpp=...
;-----------------------------------------------------------
LoadDisplaySettingsFromSystemIni proc far

	;---------------------------------------
	; aspect string
	;---------------------------------------
	push	ds
	push	OFFSET szBootDesc       ; lpAppName
	push	ds
	push	OFFSET szAspect         ; lpKeyName
	push	ds
	push	OFFSET szAspectDef      ; lpDefault
	push	ds
	push	OFFSET aspectBuf        ; lpReturnedString
	push	32                      ; nSize
	push	ds
	push	OFFSET szSystemIni      ; lpFileName
	call	GetPrivateProfileString

	call	parse_aspect_string

	;---------------------------------------
	; Width
	;---------------------------------------
	push	ds
	push	OFFSET szDrvSect
	push	ds
	push	OFFSET szWidth
	push	0
	push	ds
	push	OFFSET szSystemIni
	call	GetPrivateProfileInt
	mov		g_ScreenWidth, ax

	;---------------------------------------
	; Height
	;---------------------------------------
	push	ds
	push	OFFSET szDrvSect
	push	ds
	push	OFFSET szHeight
	push	0
	push	ds
	push	OFFSET szSystemIni
	call	GetPrivateProfileInt
	mov		g_ScreenHeight, ax

	;---------------------------------------
	; Colors
	;---------------------------------------
	push	ds
	push	OFFSET szDrvSect
	push	ds
	push	OFFSET szColors
	push	0
	push	ds
	push	OFFSET szSystemIni
	call	GetPrivateProfileInt
	mov		g_bpp, ax

	mov		g_cfgLoaded, 1

.finish:
	retf
LoadDisplaySettingsFromSystemIni endp

cProc	LoadDisplaySettingsFromVDD,<FAR,PUBLIC>
	localV	DispInfo,%(SIZE NPDISP_DISPLAYINFO)
cBegin
.386
	mov	ax,ss
	mov	es,ax
    lea edi, DispInfo              ; DI = offset of DispInfo
	mov	eax, VDD_GET_DISPLAY_CONFIG
	movzx	ebx, OurVMHandle
	mov	cx, size NPDISP_DISPLAYINFO
	call	dword ptr VDDEntryPoint
	
	cmp	eax, VDD_GET_DISPLAY_CONFIG ; eaxが変わらないならVDD_GET_DISPLAY_CONFIG自体がない
	je	.fromvdd_finish
	inc	ax ; axが-1なら失敗
	jz	.fromvdd_finish
	
	mov	ax, DispInfo.diXRes
	mov	g_ScreenWidth, ax
	mov	ax, DispInfo.diYRes
	mov	g_ScreenHeight, ax
	xor ax, ax
	mov al, DispInfo.diBpp
	mov	g_bpp, ax
	mov	ax, DispInfo.diDPI
	test ax, ax ; 0でないならDPI指示有効 
	jz	.fromvdd_finish
	
	mov	g_DpiX, ax
	mov	g_DpiY, ax
.fromvdd_finish:

cEnd

sEnd	Code

end		DriverInit ; エントリポイントはDriverInit 

