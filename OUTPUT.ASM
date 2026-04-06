.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	Output,<FAR,PUBLIC,WIN,PASCAL>

;	parmD	lpDestDevAddr
;	parmW	wStyle
;	parmW	wCount
;	parmD	lpPointsAddr
;	parmD	lpPPenAddr
;	parmD	lpPBrushAddr
;	parmD	lpDrawModeAddr
;	parmD	lpClipRectAddr
	
cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 8
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 28
cEnd <nogen>

sEnd	Code

end