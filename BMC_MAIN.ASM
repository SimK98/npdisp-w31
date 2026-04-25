.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

sBegin	Data

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

;----------------------------------------------------------------------------;

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

cProc	DeviceBitmapBits,<FAR,PUBLIC,WIN,PASCAL> ;,<si,di,es>

;	parmD	lp_dst_dev
;	parmW	set_or_get
;	parmW	iStart
;	parmW	num_scans
;	parmD	lp_bits_ind
;	parmD	lpbi
;	parmD	lpDrawMode
;	parmD	dwColorInfo

cBegin <nogen>
    push bp
    mov  bp,sp
    push si
	push di
    EnterCrit
    mov bx, 19
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    LeaveCrit
    pop  di
    pop  si
    pop bp
    ret 26
cEnd <nogen>

cProc	CreateBitmap,<PUBLIC,FAR>

cBegin
		xor	ax,ax
cEnd

sEnd	Code
end
