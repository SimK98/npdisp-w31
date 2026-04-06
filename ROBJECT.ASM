.286p

.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	RealizeObject,<FAR,PUBLIC,WIN,PASCAL>

;	parmD	lp_device
;	parmW	style
;	parmD	lp_in_obj
;	parmD	lp_out_obj
;	parmD	lp_text_xform

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 10
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 18
cEnd <nogen>

sEnd	Code
end
