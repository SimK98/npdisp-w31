.286p

.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

externFP  GetPrivateProfileString
externFP  GetPrivateProfileInt

externFP hook_int_2Fh
externFP unhook_int_2Fh

sBegin	Data

; ---------- section / key names ----------
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

;public g_DpiX, g_DpiY, g_ScreenWidth, g_ScreenHeight, g_bpp
g_cfgLoaded     db  0
g_DpiX          dw  96
g_DpiY          dw  96
g_ScreenWidth   dw  640
g_ScreenHeight  dw  480
g_bpp     		dw  4


NPDISP_REQUEST struc
npdr_version         dw ?
npdr_funcOrder       dw ?
npdr_returnCode      dw ?
npdr_reserved        dw ?
npdr_reserved2	db	48 DUP(?)
NPDISP_REQUEST ends

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

NPDISP_REQUEST_Enable struc
npdr_enable_version         dw ?
npdr_enable_funcOrder       dw ?
npdr_enable_returnCode      dw ?
npdr_enable_reserved        dw ?
npdr_enable_lpRetValueAddr	dd	?
npdr_enable_lpDevInfoAddr		dd	?
npdr_enable_wStyle			dw	?
npdr_enable_lpDestDevTypeAddr	dd	?
npdr_enable_lpOutputFileAddr	dd	?
npdr_enable_lpDataAddr		dd	?
NPDISP_REQUEST_Enable ends

NPDISP_REQUEST_GetDriverResourceID struc
npdr_gdrid_version         dw ?
npdr_gdrid_funcOrder       dw ?
npdr_gdrid_returnCode      dw ?
npdr_gdrid_reserved        dw ?
npdr_gdrid_lpRetValueAddr	dd	?
npdr_gdrid_iResId			dw	?
npdr_gdrid_lpResTypeAddr	dd	?
NPDISP_REQUEST_GetDriverResourceID ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	Enable,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lp_device
	parmW	style
	parmD	lp_device_type
	parmD	lp_output_file
	parmD	lp_stuff

cBegin

    	push ax
    	push dx
    	
		; 必要ならINIから設定を読む 
		cmp g_cfgLoaded, 1
		je .cfgloaded
		call far ptr SendNPDispInitialize
.cfgloaded:

; NPDISP_REQUEST_Enable struc
; npdr_enable_version         dw ?
; npdr_enable_funcOrder       dw ?
; npdr_enable_returnCode      dw ?
; npdr_enable_reserved        dw ?
; npdr_enable_lpRetValueAddr	dd	?
; npdr_enable_lpDevInfoAddr		dd	?
; npdr_enable_wStyle			dw	?
; npdr_enable_lpDestDevTypeAddr	dd	?
; npdr_enable_lpOutputFileAddr	dd	?
; npdr_enable_lpDataAddr		dd	?
; NPDISP_REQUEST_Enable ends

    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 5
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_enable_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_enable_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lp_device
		mov dx, WORD PTR lp_device+2
		mov WORD PTR npdisp_request.npdr_enable_lpDevInfoAddr, ax
		mov WORD PTR npdisp_request.npdr_enable_lpDevInfoAddr+2, dx
    	mov ax, style
    	mov npdisp_request.npdr_enable_wStyle, ax
		mov ax, WORD PTR lp_device_type
		mov dx, WORD PTR lp_device_type+2
		mov WORD PTR npdisp_request.npdr_enable_lpDestDevTypeAddr, ax
		mov WORD PTR npdisp_request.npdr_enable_lpDestDevTypeAddr+2, dx
		mov ax, WORD PTR lp_output_file
		mov dx, WORD PTR lp_output_file+2
		mov WORD PTR npdisp_request.npdr_enable_lpOutputFileAddr, ax
		mov WORD PTR npdisp_request.npdr_enable_lpOutputFileAddr+2, dx
		mov ax, WORD PTR lp_stuff
		mov dx, WORD PTR lp_stuff+2
		mov WORD PTR npdisp_request.npdr_enable_lpDataAddr, ax
		mov WORD PTR npdisp_request.npdr_enable_lpDataAddr+2, dx
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

		mov ax, WORD PTR npdisp_retValue
		
		and ax, ax
		jz .endinit
		
		cmp style, 0
		jne .endinit
		
		call	far ptr hook_int_2Fh
		
.endinit:

cEnd	Enable

cProc   GetDriverResourceID,<FAR,PUBLIC,WIN,PASCAL>

        parmW  iResID
        parmD  lpResType

cBegin
    	push ax
    	push dx
    	
		; 必要ならINIから設定を読む 
		cmp g_cfgLoaded, 1
		je .cfgloadedGDRID
		call far ptr SendNPDispInitialize
.cfgloadedGDRID:

;NPDISP_REQUEST_GetDriverResourceID struc
;npdr_gdrid_version         dw ?
;npdr_gdrid_funcOrder       dw ?
;npdr_gdrid_returnCode      dw ?
;npdr_gdrid_reserved        dw ?
;npdr_gdrid_lpRetValueAddr	dd	?
;npdr_gdrid_iResId			dw	?
;npdr_gdrid_lpResTypeAddr	dd	?
;NPDISP_REQUEST_GetDriverResourceID ends

    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 450
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_enable_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_enable_lpRetValueAddr+2, SEG npdisp_retValue
    	mov ax, iResID
    	mov npdisp_request.npdr_gdrid_iResId, ax
		mov ax, WORD PTR lpResType
		mov dx, WORD PTR lpResType+2
		mov WORD PTR npdisp_request.npdr_gdrid_lpResTypeAddr, ax
		mov WORD PTR npdisp_request.npdr_gdrid_lpResTypeAddr+2, dx
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

		mov ax, WORD PTR npdisp_retValue
		mov dx, dx
cEnd	GetDriverResourceID

msgNoNPDISP      db  'Neko Project II Display Adapter not found.$',0

SendNPDispInitialize proc far

	push ax
	push dx
	
	call far ptr LoadDisplaySettingsFromSystemIni

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
	mov npdisp_request.npdr_version, NPDISP_VERSION
	mov npdisp_request.npdr_funcOrder, 0
	mov npdisp_request.npdr_returnCode, 0ffffh ; あり得ない値にしておく 
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

sEnd	Code
end
