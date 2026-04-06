.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for StretchBlt
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpDestDevAddr		dd	?
npdr_wDestX				dw	?
npdr_wDestY				dw	?
npdr_wDestXext			dw	?
npdr_wDestYext			dw	?
npdr_lpSrcDevAddr		dd	?
npdr_wSrcX				dw	?
npdr_wSrcY				dw	?
npdr_wSrcXext			dw	?
npdr_wSrcYext			dw	?
npdr_Rop3				dd	?
npdr_lpPBrushAddr		dd	?
npdr_lpDrawModeAddr		dd	?
npdr_lpClipAddr			dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data


sBegin	Code
assumes cs,Code
assumes ds,Data

cProc	StretchBlt,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lpDestDev;
	parmW	wDestX;
	parmW	wDestY;
	parmW	wDestXext;
	parmW	wDestYext;
	parmD	lpSrcDev;
	parmW	wSrcX;
	parmW	wSrcY;
	parmW	wSrcXext;
	parmW	wSrcYext;
	parmD	Rop3;
	parmD	lpPBrush;
	parmD	lpDrawMode;
	parmD	lpClip;

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 27
    	mov npdisp_request.npdr_returnCode, 0
    	mov npdisp_request.npdr_reserved, ax
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpDestDev
		mov dx, WORD PTR lpDestDev+2
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr+2, dx
		mov ax, WORD PTR wDestX
		mov WORD PTR npdisp_request.npdr_wDestX, ax
		mov ax, WORD PTR wDestY
		mov WORD PTR npdisp_request.npdr_wDestY, ax
		mov ax, WORD PTR wDestXext
		mov WORD PTR npdisp_request.npdr_wDestXext, ax
		mov ax, WORD PTR wDestYext
		mov WORD PTR npdisp_request.npdr_wDestYext, ax
		mov ax, WORD PTR lpSrcDev
		mov dx, WORD PTR lpSrcDev+2
		mov WORD PTR npdisp_request.npdr_lpSrcDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpSrcDevAddr+2, dx
		mov ax, WORD PTR wSrcX
		mov WORD PTR npdisp_request.npdr_wSrcX, ax
		mov ax, WORD PTR wSrcY
		mov WORD PTR npdisp_request.npdr_wSrcY, ax
		mov ax, WORD PTR wSrcXext
		mov WORD PTR npdisp_request.npdr_wSrcXext, ax
		mov ax, WORD PTR wSrcYext
		mov WORD PTR npdisp_request.npdr_wSrcYext, ax
		mov ax, WORD PTR Rop3
		mov dx, WORD PTR Rop3+2
		mov WORD PTR npdisp_request.npdr_Rop3, ax
		mov WORD PTR npdisp_request.npdr_Rop3+2, dx
		mov ax, WORD PTR lpPBrush
		mov dx, WORD PTR lpPBrush+2
		mov WORD PTR npdisp_request.npdr_lpPBrushAddr, ax
		mov WORD PTR npdisp_request.npdr_lpPBrushAddr+2, dx
		mov ax, WORD PTR lpDrawMode
		mov dx, WORD PTR lpDrawMode+2
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr+2, dx
		mov ax, WORD PTR lpClip
		mov dx, WORD PTR lpClip+2
		mov WORD PTR npdisp_request.npdr_lpClipAddr, ax
		mov WORD PTR npdisp_request.npdr_lpClipAddr+2, dx
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
