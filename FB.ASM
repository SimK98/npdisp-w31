.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for FastBorder
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpRectAddr			dd	?
npdr_wHorizBorderThick	dw	?
npdr_wVertBorderThick	dw	?
npdr_dwRasterOp			dd	?
npdr_lpDestDevAddr		dd	?
npdr_lpPBrushAddr		dd	?
npdr_lpDrawModeAddr		dd	?
npdr_lpClipRectAddr		dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	FastBorder,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lpRect
	parmW	wHorizBorderThick
	parmW	wVertBorderThick
	parmD	dwRasterOp
	parmD	lpDestDev
	parmD	lpPBrush
	parmD	lpDrawMode
	parmD	lpClipRect

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 17
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpRect
		mov dx, WORD PTR lpRect+2
		mov WORD PTR npdisp_request.npdr_lpRectAddr, ax
		mov WORD PTR npdisp_request.npdr_lpRectAddr+2, dx
		mov ax, WORD PTR wHorizBorderThick
		mov WORD PTR npdisp_request.npdr_wHorizBorderThick, ax
		mov ax, WORD PTR wVertBorderThick
		mov WORD PTR npdisp_request.npdr_wVertBorderThick, ax
		mov ax, WORD PTR dwRasterOp
		mov dx, WORD PTR dwRasterOp+2
		mov WORD PTR npdisp_request.npdr_dwRasterOp, ax
		mov WORD PTR npdisp_request.npdr_dwRasterOp+2, dx
		mov ax, WORD PTR lpDestDev
		mov dx, WORD PTR lpDestDev+2
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr+2, dx
		mov ax, WORD PTR lpPBrush
		mov dx, WORD PTR lpPBrush+2
		mov WORD PTR npdisp_request.npdr_lpPBrushAddr, ax
		mov WORD PTR npdisp_request.npdr_lpPBrushAddr+2, dx
		mov ax, WORD PTR lpDrawMode
		mov dx, WORD PTR lpDrawMode+2
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr+2, dx
		mov ax, WORD PTR lpClipRect
		mov dx, WORD PTR lpClipRect+2
		mov WORD PTR npdisp_request.npdr_lpClipRectAddr, ax
		mov WORD PTR npdisp_request.npdr_lpClipRectAddr+2, dx
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

sEnd	Code
end
