.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

; for Control
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_lpRetValueAddr		dd	?
npdr_lpDestDevAddr		dd	?
npdr_wFunction			dw	?
npdr_lpInObjAddr		dd	?
npdr_lpOutObjAddr		dd	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	Control,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

	parmD	lp_device
	parmW	function
	parmD	lp_in_data
	parmD	lp_out_data

cBegin
    	push ax
    	push dx
    	EnterCrit
    	mov npdisp_request.npdr_version, NPDISP_VERSION
    	mov npdisp_request.npdr_funcOrder, 3
    	mov npdisp_request.npdr_returnCode, 0
    	mov WORD PTR npdisp_retValue, 100
    	mov WORD PTR npdisp_retValue+2, 0
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr, OFFSET npdisp_retValue
    	mov WORD PTR npdisp_request.npdr_lpRetValueAddr+2, SEG npdisp_retValue
		mov ax, WORD PTR lp_device
		mov dx, WORD PTR lp_device+2
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr, ax
		mov WORD PTR npdisp_request.npdr_lpDestDevAddr+2, dx
		mov ax, WORD PTR function
		mov WORD PTR npdisp_request.npdr_wFunction, ax
		mov ax, WORD PTR lp_in_data
		mov dx, WORD PTR lp_in_data+2
		mov WORD PTR npdisp_request.npdr_lpInObjAddr, ax
		mov WORD PTR npdisp_request.npdr_lpInObjAddr+2, dx
		mov ax, WORD PTR lp_out_data
		mov dx, WORD PTR lp_out_data+2
		mov WORD PTR npdisp_request.npdr_lpOutObjAddr, ax
		mov WORD PTR npdisp_request.npdr_lpOutObjAddr+2, dx
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

cProc DeviceBitmap,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

      parmD lpDevice
      parmW command
      parmD lpBitmap
      parmD lpBits

cBegin

	xor	ax,ax

cEnd

cProc SetAttribute,<FAR,PUBLIC,WIN,PASCAL>,<si,di>

      parmD  lpDevice
      parmW  stateNum
      parmW  index
      parmD  attribute

cBegin

	xor	ax,ax

cEnd

sEnd Code

end
