.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	Control,<FAR,PUBLIC,WIN,PASCAL> ;,<si,di>

;	parmD	lp_device
;	parmW	function
;	parmD	lp_in_data
;	parmD	lp_out_data
    
cBegin <nogen>
    push bp
    mov  bp,sp
    ;push si
	;push di
    ;EnterCrit
    mov bx, 3
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    ;LeaveCrit
    ;pop  di
    ;pop  si
    pop bp
    ret 14
cEnd <nogen>

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
