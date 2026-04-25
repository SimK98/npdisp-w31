.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for BitmapBits
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpDeviceAddr		dd	?
npdr_fFlags				dd	?
npdr_dwCount			dd	?
npdr_lpBitsAddr			dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	BitmapBits,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lpDevice
	parmD	fFlags
	parmD	dwCount
	parmD	lpBits

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 30
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 0
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lpDevice
		mov dx, WORD PTR lpDevice+2
		mov WORD PTR npdisp_request.npdr_lpDeviceAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDeviceAddr+2, dx
		mov ax, WORD PTR fFlags
		mov dx, WORD PTR fFlags+2
		mov WORD PTR npdisp_request.npdr_fFlags, ax
		mov WORD PTR npdisp_request.npdr_fFlags+2, dx
		mov ax, WORD PTR dwCount
		mov dx, WORD PTR dwCount+2
		mov WORD PTR npdisp_request.npdr_dwCount, ax
		mov WORD PTR npdisp_request.npdr_dwCount+2, dx
		mov ax, WORD PTR lpBits
		mov dx, WORD PTR lpBits+2
		mov WORD PTR npdisp_request.npdr_lpBitsAddr, ax
		mov WORD PTR npdisp_request.npdr_lpBitsAddr+2, dx
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
