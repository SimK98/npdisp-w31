.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for DIBScreenBlt (SetDIBitsToDevice)
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpDestDevAddr		dd	?
npdr_X					dw	?
npdr_Y					dw	?
npdr_iScan				dw	?
npdr_cScans				dw	?
npdr_lpClipRectAddr		dd	?
npdr_lpDrawModeAddr		dd	?
npdr_lpDIBitsAddr		dd	?
npdr_lpBitmapInfoAddr	dd	?
npdr_lpTranslateAddr	dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
	assumes	cs,Code
	assumes	ds,Data
	assumes	es,nothing

cProc	DIBScreenBlt,<FAR,PUBLIC,WIN,PASCAL>,<si,di> ; = SetDIBitsToDevice

	parmD	lp_pdevice
	parmW	ScrXorg
	parmW	ScrYorg
	parmW	StartScan
	parmW	NumScan
	parmD	lpClipRect
	parmD	lpDrawMode
	parmD	lp_bits
    parmD   lp_bi
    parmD   dwColorInfo

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 21
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lp_pdevice
		mov dx, WORD PTR lp_pdevice+2
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr+2, dx
		mov ax, WORD PTR ScrXorg
		mov WORD PTR npdisp_request.npdr_X, ax
		mov ax, WORD PTR ScrYorg
		mov WORD PTR npdisp_request.npdr_Y, ax
		mov ax, WORD PTR StartScan
		mov WORD PTR npdisp_request.npdr_iScan, ax
		mov ax, WORD PTR NumScan
		mov WORD PTR npdisp_request.npdr_cScans, ax
		mov ax, WORD PTR lpClipRect
		mov dx, WORD PTR lpClipRect+2
		mov WORD PTR npdisp_request.npdr_lpClipRectAddr, ax
		mov WORD PTR npdisp_request.npdr_lpClipRectAddr+2, dx
		mov ax, WORD PTR lpDrawMode
		mov dx, WORD PTR lpDrawMode+2
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr+2, dx
		mov ax, WORD PTR lp_bits
		mov dx, WORD PTR lp_bits+2
		mov WORD PTR npdisp_request.npdr_lpDIBitsAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDIBitsAddr+2, dx
		mov ax, WORD PTR lp_bi
		mov dx, WORD PTR lp_bi+2
		mov WORD PTR npdisp_request.npdr_lpBitmapInfoAddr, ax
		mov WORD PTR npdisp_request.npdr_lpBitmapInfoAddr+2, dx
		mov ax, WORD PTR dwColorInfo
		mov dx, WORD PTR dwColorInfo+2
		mov WORD PTR npdisp_request.npdr_lpTranslateAddr, ax
		mov WORD PTR npdisp_request.npdr_lpTranslateAddr+2, dx
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
    	pop dx
    	pop ax
    	LeaveCrit
    	
		mov ax, WORD PTR npdisp_retValue
cEnd

sEnd	Code
end
