.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

	public	ExtTextOut
	public	StrBlt

	
sBegin	Code
	assumes	cs,Code
	assumes	ds,Data
	assumes	es,nothing

cProc	ExtTextOut,<FAR,PUBLIC,WIN,PASCAL>

;    parmD   lpDestDevAddr
;    parmW   wDestXOrg
;    parmW   wDestYOrg
;    parmD   lpClipRectAddr
;    parmD   lpStringAddr
;    parmW   wCount
;    parmD   lpFontInfoAddr
;    parmD   lpDrawModeAddr
;    parmD   lpTextXFormAddr
;    parmD   lpCharWidthsAddr
;    parmD   lpOpaqueRectAddr
;    parmW   wOptions
    
cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 14
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 40
cEnd <nogen>

cProc	StrBlt,<FAR,PUBLIC,WIN,PASCAL>

;    parmD   lpDestDevAddr
;    parmW   wDestXOrg
;    parmW   wDestYOrg
;    parmD   lpClipRectAddr
;    parmD   lpStringAddr
;    parmW   wCount
;    parmD   lpFontInfoAddr
;    parmD   lpDrawModeAddr
;    parmD   lpTextXFormAddr

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 11
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 30
cEnd <nogen>

sEnd 	Code

end

