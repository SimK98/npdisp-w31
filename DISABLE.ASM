.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

externFP hook_int_2Fh
externFP unhook_int_2Fh

sBegin	Data

; for Disable
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpDestDevAddr		dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data


sBegin	Code
assumes cs,Code
assumes ds,Data

cProc	Disable,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lp_device

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 4
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
		mov ax, WORD PTR lp_device
		mov dx, WORD PTR lp_device+2
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr+2, dx
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
		
		call	far ptr unhook_int_2Fh
		
cEnd

sEnd	Code
end
