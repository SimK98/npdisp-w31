.xlist
include CMACROS.INC
include WINDEFS.INC
include NPDISP.INC
.list

externFP AllocCSToDSAlias
externFP FreeSelector

sBegin	Data

prev_int_2Fh	dd	0

; for INT2Fh
NPDISP_REQUEST struc
npdr_version        	dw	?
npdr_funcOrder      	dw	?
npdr_returnCode     	dw	?
npdr_reserved       	dw	?
npdr_ax					dw	?
NPDISP_REQUEST ends

EXTRN npdisp_request:BYTE
EXTRN npdisp_retValue:DWORD

sEnd	Data

sBegin	Code
assumes cs,Code
assumes ds,Data
assumes es,nothing

; データセグメント保持用
_cstods 		dw	0

public	hook_int_2Fh
hook_int_2Fh proc far
    push ds
    mov ax, 352Fh
    int 21h
    mov word ptr prev_int_2Fh, bx
    mov word ptr prev_int_2Fh+2, es
    
    ; csに直接書くことは出来ない 
    ; なので、AllocCSToDSAliasで書き込み用エイリアスを取得 
    push es
    mov     ax, seg _TEXT
	cCall   AllocCSToDSAlias, <cs>
	mov es, ax
	mov ax, ds
    mov word ptr es:[_cstods], ax
	mov ax, es
	cCall   FreeSelector, <ax>
	pop es
	
    mov dx, OFFSET screen_switch_hook
    mov ax, SEG screen_switch_hook
    mov ds, ax
    mov ax, 252Fh
    int 21h
    pop ds
    retf
hook_int_2Fh endp

public	unhook_int_2Fh
unhook_int_2Fh proc far
    push ds
    lds dx, prev_int_2Fh
    mov ax, 252Fh
    int 21h
    pop ds
    retf
unhook_int_2Fh endp

screen_switch_hook proc far
    push    ds
    mov     ds, [_cstods] ; Data セグメントへ
    
    cmp ax, 4001h
    je  .sendnp2

    cmp ax, 4002h
    je  .sendnp2
    
    jmp  .chain

.sendnp2:
	push ax
	push dx
	mov npdisp_request.npdr_version, NPDISP_VERSION
	mov npdisp_request.npdr_funcOrder, 0ff2fh
	mov npdisp_request.npdr_returnCode, 0
	mov WORD PTR npdisp_request.npdr_ax, ax
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
	
.chain:
    push    word ptr [prev_int_2Fh+2]  ; segment
    push    word ptr [prev_int_2Fh+0]  ; offset
    push    bp
    mov     bp, sp
    mov     ds, [bp+6]                 ; 元の DS を復元
    pop     bp
    retf    2                          ; push ds 分を捨てて旧ハンドラへ

screen_switch_hook endp

sEnd	Code
end
