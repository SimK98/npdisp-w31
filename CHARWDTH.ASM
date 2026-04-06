.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for GetCharWidth
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpDestDevAddr		dd	?
npdr_lpBufferAddr		dd	?
npdr_wFirstChar			dw	?
npdr_wLastChar			dw	?
npdr_lpFontInfoAddr		dd	?
npdr_lpDrawModeAddr		dd	?
npdr_lpFontTransAddr	dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	GetCharWidth,<FAR,PUBLIC,WIN,PASCAL>,<si,di>
	parmD	lpDestDev;
	parmD	lpBuffer
	parmW	wFirstChar
	parmW	wLastChar
	parmD	lpFontInfo
	parmD	lpDrawMode
	parmD	lpFontTrans
cBegin

    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 15
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpDestDev
		mov dx, WORD PTR lpDestDev+2
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr+2, dx
		mov ax, WORD PTR lpBuffer
		mov dx, WORD PTR lpBuffer+2
		mov WORD PTR npdisp_request.npdr_lpBufferAddr, ax
		mov WORD PTR npdisp_request.npdr_lpBufferAddr+2, dx
		mov ax, WORD PTR wFirstChar
		mov WORD PTR npdisp_request.npdr_wFirstChar, ax
		mov ax, WORD PTR wLastChar
		mov WORD PTR npdisp_request.npdr_wLastChar, ax
		mov ax, WORD PTR lpFontInfo
		mov dx, WORD PTR lpFontInfo+2
		mov WORD PTR npdisp_request.npdr_lpFontInfoAddr, ax
		mov WORD PTR npdisp_request.npdr_lpFontInfoAddr+2, dx
		mov ax, WORD PTR lpFontTrans
		mov dx, WORD PTR lpFontTrans+2
		mov WORD PTR npdisp_request.npdr_lpFontTransAddr, ax
		mov WORD PTR npdisp_request.npdr_lpFontTransAddr+2, dx
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
