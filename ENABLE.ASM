.286p

.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

externFP hook_int_2Fh
externFP unhook_int_2Fh

externFP SendNPDispInitialize

sBegin	Data

NPDISP_REQUEST struc
npdr_version         dw ?
npdr_funcOrder       dw ?
npdr_returnCode      dw ?
npdr_reserved        dw ?
npdr_reserved2	db	48 DUP(?)
NPDISP_REQUEST ends

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

NPDISP_REQUEST_ReEnable struc
npdr_re_version         dw ?
npdr_re_funcOrder       dw ?
npdr_re_returnCode      dw ?
npdr_re_reserved        dw ?
npdr_re_lpRetValueAddr	dd	?
npdr_re_lpPDeviceAddr	dd	?
npdr_re_lpGDIInfoAddr	dd	?
NPDISP_REQUEST_ReEnable ends

NPDISP_REQUEST_GetDriverResourceID struc
npdr_gdrid_version         dw ?
npdr_gdrid_funcOrder       dw ?
npdr_gdrid_returnCode      dw ?
npdr_gdrid_reserved        dw ?
npdr_gdrid_lpRetValueAddr	dd	?
npdr_gdrid_iResId			dw	?
npdr_gdrid_lpResTypeAddr	dd	?
NPDISP_REQUEST_GetDriverResourceID ends

NPDISP_REQUEST_ValidateMode struc
npdr_vmode_version         dw ?
npdr_vmode_funcOrder       dw ?
npdr_vmode_returnCode      dw ?
npdr_vmode_reserved        dw ?
npdr_vmode_lpRetValueAddr	dd	?
npdr_vmode_lpValModeAddr	dd	?
NPDISP_REQUEST_ValidateMode ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD
EXTRN g_cfgLoaded:BYTE

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

cProc	ReEnable,<FAR,PUBLIC,WIN,PASCAL>,<si,di>
        parmD   lpPDevice
        parmD   lpGDIInfo
cBegin

;NPDISP_REQUEST_ReEnable struc
;npdr_re_version         dw ?
;npdr_re_funcOrder       dw ?
;npdr_re_returnCode      dw ?
;npdr_re_reserved        dw ?
;npdr_re_lpRetValueAddr	dd	?
;npdr_re_lpPDeviceAddr	dd	?
;npdr_re_lpGDIInfoAddr	dd	?
;NPDISP_REQUEST_ReEnable ends

		; 初期化を再送信 
		call far ptr SendNPDispInitialize

    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 31
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_enable_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_enable_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpPDevice
		mov dx, WORD PTR lpPDevice+2
		mov WORD PTR npdisp_request.npdr_re_lpPDeviceAddr, ax
		mov WORD PTR npdisp_request.npdr_re_lpPDeviceAddr+2, dx
		mov ax, WORD PTR lpGDIInfo
		mov dx, WORD PTR lpGDIInfo+2
		mov WORD PTR npdisp_request.npdr_re_lpGDIInfoAddr, ax
		mov WORD PTR npdisp_request.npdr_re_lpGDIInfoAddr+2, dx
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
		
cEnd	ReEnable

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

cProc   ValidateMode,<FAR,PUBLIC,WIN,PASCAL>

        parmD  lpValMode

cBegin
    	push ax
    	push dx
    
;NPDISP_REQUEST_ValidateMode struc
;npdr_vmode_version         dw ?
;npdr_vmode_funcOrder       dw ?
;npdr_vmode_returnCode      dw ?
;npdr_vmode_reserved        dw ?
;npdr_vmode_lpRetValueAddr	dd	?
;npdr_vmode_lpValModeAddr	dd	?
;NPDISP_REQUEST_ValidateMode ends

    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 700
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_vmode_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_vmode_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpValMode
		mov dx, WORD PTR lpValMode+2
		mov WORD PTR npdisp_request.npdr_vmode_lpValModeAddr, ax
		mov WORD PTR npdisp_request.npdr_vmode_lpValModeAddr+2, dx
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
cEnd	ValidateMode

sEnd	Code
end
