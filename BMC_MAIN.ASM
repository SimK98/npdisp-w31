.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for DeviceBitmapBits
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpBitmapAddr		dd	?
npdr_fGet				dw	?
npdr_iStart				dw	?
npdr_cScans				dw	?
npdr_lpDIBitsAddr		dd	?
npdr_lpBitmapInfoAddr	dd	?
npdr_lpDrawModeAddr		dd	?
npdr_lpTranslateAddr	dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

;----------------------------------------------------------------------------;

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	DeviceBitmapBits,<FAR,PUBLIC,WIN,PASCAL>,<si,di,es>

	parmD	lp_dst_dev
	parmW	set_or_get
	parmW	iStart
	parmW	num_scans
	parmD	lp_bits_ind
	parmD	lpbi
	parmD	lpDrawMode
	parmD	dwColorInfo

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 19
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 100
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lp_dst_dev
		mov dx, WORD PTR lp_dst_dev+2
		mov WORD PTR npdisp_request.npdr_lpBitmapAddr, ax
		mov WORD PTR npdisp_request.npdr_lpBitmapAddr+2, dx
		mov ax, WORD PTR set_or_get
		mov WORD PTR npdisp_request.npdr_fGet, ax
		mov ax, WORD PTR iStart
		mov WORD PTR npdisp_request.npdr_iStart, ax
		mov ax, WORD PTR num_scans
		mov WORD PTR npdisp_request.npdr_cScans, ax
		mov ax, WORD PTR lp_bits_ind
		mov dx, WORD PTR lp_bits_ind+2
		mov WORD PTR npdisp_request.npdr_lpDIBitsAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDIBitsAddr+2, dx
		mov ax, WORD PTR lpbi
		mov dx, WORD PTR lpbi+2
		mov WORD PTR npdisp_request.npdr_lpBitmapInfoAddr, ax
		mov WORD PTR npdisp_request.npdr_lpBitmapInfoAddr+2, dx
		mov ax, WORD PTR lpDrawMode
		mov dx, WORD PTR lpDrawMode+2
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr+2, dx
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
        LeaveCrit
    	pop dx
    	pop ax

		mov ax, WORD PTR npdisp_retValue
cEnd

cProc	CreateBitmap,<PUBLIC,FAR>

cBegin
		xor	ax,ax
cEnd

sEnd	Code
end
