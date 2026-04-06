.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	ColorInfo,<FAR,PUBLIC,WIN,PASCAL>

;	parmD	lp_device
;	parmD	color_in
;	parmD	lp_phys_bits

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 2
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 12
cEnd <nogen>

sEnd	Code
end
