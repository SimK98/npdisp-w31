.xlist
include WINDEFS.INC
include CMACROS.INC
include NPDISP.INC
.list

EXTRN npdisp_ddHalInfo:BYTE
EXTRN npdisp_ddSetInfo:DWORD

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
    push si
    push di
    push ds
    push es

    ; Controlは呼び出し側のDSで入るため、共有Dataセグメントへ切り替えてから
    ; DirectDrawの共有状態へアクセスする。
    mov  ax, SEG npdisp_ddHalInfo
    mov  ds, ax

    ; 先にnp21/wへ渡し、DDCREATEDRIVEROBJECTではnpdisp_ddHalInfoを構築させる。
    mov bx, 3
    mov cx, 0504eh
    mov dx, 07e9h
    mov al, 'F'
    out dx, al
    mov di, ax

    cmp WORD PTR ss:[bp+14], NPDISP_DCICOMMAND
    je  short .control_command_ok
    jmp .return_host
.control_command_ok:
    les si, DWORD PTR ss:[bp+10]
    mov ax, es
    or  ax, si
    jnz short .control_input_ok
    jmp .return_host
.control_input_ok:
    cmp WORD PTR es:[si+12], NPDISP_DD_VERSION
    je  short .control_version_ok
    jmp .return_host
.control_version_ok:
    cmp WORD PTR es:[si+14], 0
    je  short .control_version_high_ok
    jmp .return_host
.control_version_high_ok:
    cmp WORD PTR es:[si+2], 0
    je  short .control_command_high_ok
    jmp .return_host
.control_command_high_ok:
    mov ax, WORD PTR es:[si]
    cmp ax, NPDISP_DDNEWCALLBACKFNS
    je  .new_callbacks
    cmp ax, NPDISP_DDCREATEDRIVEROBJECT
    je  .create_driver
    jmp .return_host

.new_callbacks:
    ; dwParam1のDDHALDDRAWFNSからlpSetInfoを取得して保持する。
    mov ax, WORD PTR es:[si+4]
    mov dx, WORD PTR es:[si+6]
    mov bx, ax
    or  bx, dx
    jz  .new_callbacks_fail
    mov es, dx
    mov si, ax
    mov ax, WORD PTR es:[si+4]
    mov dx, WORD PTR es:[si+6]
    mov WORD PTR npdisp_ddSetInfo, ax
    mov WORD PTR npdisp_ddSetInfo+2, dx
    or  ax, dx
    jz  .new_callbacks_fail
    mov ax, 1
    jmp .done

.new_callbacks_fail:
    mov WORD PTR npdisp_ddSetInfo, 0
    mov WORD PTR npdisp_ddSetInfo+2, 0
    xor ax, ax
    jmp .done

.create_driver:
    ; DDCREATEDRIVEROBJECTはlpSetInfoがDDHALINFOを受理して初めて成功とする。
    mov ax, WORD PTR npdisp_ddSetInfo
    mov dx, WORD PTR npdisp_ddSetInfo+2
    or  ax, dx
    jnz short .create_driver_have_setinfo
    jmp .create_driver_fail
.create_driver_have_setinfo:
    ; DDHALINFO.hInstanceはNPDISPDD.DLLのDriverInitが設定した値をそのまま使う。

    ; 初回登録なのでlpSetInfoにはbReset=FALSEを渡す。ReEnable時だけTRUEを使う。
    xor cx, cx
    push ds
    push ds
    push OFFSET npdisp_ddHalInfo
    push cx
    call DWORD PTR npdisp_ddSetInfo
    pop ds

    or  ax, ax
    jz  .create_driver_fail

    les di, DWORD PTR ss:[bp+6]
    mov bx, es
    or  bx, di
    jz  .create_driver_fail
    mov bx, WORD PTR npdisp_ddHalInfo+NPDISP_DDHALINFO_HINSTANCE
    mov WORD PTR es:[di], bx
    mov bx, WORD PTR npdisp_ddHalInfo+NPDISP_DDHALINFO_HINSTANCE+2
    mov WORD PTR es:[di+2], bx

    mov ax, 1
    jmp short .done

.create_driver_fail:
    xor ax, ax
    jmp short .done

.return_host:
    mov ax, di

.done:
    ; 拡張されたControlの戻り値はLONGらしい？のでDX:AXへ符号拡張する。
    cwd
    pop es
    pop ds
    pop di
    pop si
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
