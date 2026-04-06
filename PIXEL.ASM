.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for Pixel
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpDestDevAddr		dd	?
npdr_X					dw	?
npdr_Y					dw	?
npdr_dwPhysColor		dd	?
npdr_lpDrawModeAddr		dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	Pixel,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lpDestDev
	parmW	X
	parmW	Y
	parmD	dwPhysColor
	parmD	lpDrawMode

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 9
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 08000h
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpDestDev
		mov dx, WORD PTR lpDestDev+2
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr+2, dx
		mov ax, WORD PTR X
		mov WORD PTR npdisp_request.npdr_X, ax
		mov ax, WORD PTR Y
		mov WORD PTR npdisp_request.npdr_Y, ax
		mov ax, WORD PTR dwPhysColor
		mov dx, WORD PTR dwPhysColor+2
		mov WORD PTR npdisp_request.npdr_dwPhysColor, ax
		mov WORD PTR npdisp_request.npdr_dwPhysColor+2, dx
		mov ax, WORD PTR lpDrawMode
		mov dx, WORD PTR lpDrawMode+2
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDrawModeAddr+2, dx
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
		mov dx, WORD PTR npdisp_retValue+2
cEnd

sEnd	Code

end
