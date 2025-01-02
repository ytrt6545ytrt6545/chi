;=======================
commzd:
PUSH A
jb   ti,commout
jnb  7fh,commra
jmp  commrd
;;;;;;;;;;;;;;;;;;;;;;;;
commra:  ;read addrss
mov   a,sbuf
mov   sbuf_id,a
anl   a,#11110000b
cjne  a,#10h,commout
mov   60h,sbuf_id
MOV   SBUF_P,#60h
setb  7fh
mov   a,sbuf_id
jmp   commout
;;;;;;;;;;;;;;;;;;;;;;;;;
commrd:  ;read data
mov    a,sbuf
INC    SBUF_P
mov    r0,sbuf_p
mov    @r0,a
mov    a,r0
CJNE   A,#66h,COMMOUT
clr    7fh
lcall  ID_DATA
jmp    commout
;========================
commout:
clr  ti
clr  ri
POP  A
reti
;=========================
ID_DATA:
    MOV  a,60H
    anl  a,#11110000b
    mov  68h,a
    MOV  a,61H
    cpl  a
    anl  a,#11110000b
    cjne a,68h,ID_DATA_out
;;;;;
    MOV  a,62H
    anl  a,#11110000b
    mov  68h,a
    MOV  a,63H
    cpl  a
    anl  a,#11110000b
    cjne a,68h,ID_DATA_out
;;;;;
    ;MOV  a,64H
    ;anl  a,#11110000b
    ;mov  68h,a
    ;MOV  a,65H
    ;cpl  a
    ;anl  a,#11110000b
    ;cjne a,68h,ID_DATA_out
;;;;;
    MOV  a,65H
    anl  a,#11110000b
    mov  68h,a
    MOV  a,66H
    cpl  a
    anl  a,#11110000b
    cjne a,68h,ID_DATA_out
;;;;;
    MOV  a,60H
    anl  a,#00001111b
    swap a
    mov  68h,a
    MOV  a,61H
    anl  a,#00001111b
    ;swap a
    orl  a,68h
    ;mov  2ch,a     ;;;;addr
    mov  SBUF_ID,a
;;;;
    MOV  a,62H
    anl  a,#00001111b
    swap a
    mov  68h,a
    MOV  a,63H
    anl  a,#00001111b
    ;swap a
    orl  a,68h
    mov  SBUF1,a
;;;;
    MOV  a,64H
    ;anl  a,#00001111b
    ;swap a
    ;mov  68h,a
    ;MOV  a,65H
    ;anl  a,#00001111b
    ;swap a
    ;orl  a,68h
    mov  SBUF2,a
;;;;
    MOV  a,65H     ;66h
    anl  a,#00001111b
    swap a
    mov  68h,a
    MOV  a,66H     ;67h
    anl  a,#00001111b
    ;swap a
    orl  a,68h
    mov  SBUF3,a
    mov  a,61h
    cjne a,#0e6h,tongbu202
    call send_cpu_id
    ret
tongbu202:
    call COMM_TB
ID_DATA_out:
    ret
;=========================
send_cpu_id:
push  a
MOV   RT_DATA,#0FFH
clr   ren   ; jin zhi shou
clr   es    ; jin zhi zhong duan
SETB  RT_485
ORL   P3,#11110000B
mov   a,p3
nop
anl   a,#11110000b
swap  a
orl   a,#10h                    ;;;;;; 1
;setb  tb8
mov   sbuf,a                    ;;;;;; 1
deng:
jbc   ti,send_addr   ;send over , clr ti
jmp   deng
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
send_addr:                     ;;;;;; 2
     mov  a,#0e0h
     mov   sbuf,a              ;;;;;; 2
deng0:
jbc   ti,send_da1    ;send over , clr ti
jmp   deng0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
send_da1:
         mov a,#20h
         mov c,B_V_L
         MOV ACC.0,C
         MOV C,B_P
         MOV ACC.1,C
         MOV C,B_PAGE
         mov acc.2,c
         MOV C,B_PRI
         MOV ACC.3,C
         ;CLR B_POWER
         mov sbuf,A          ;;;;;; 3
   deng11:
         jbc ti,SEND_DA6
         jmp deng11
SEND_DA6:
         mov a,21h ;; send (sw1 sw2 sw3  mute) wei
;        ANL A,#11101111B
         anl a,#0fh
         orl a,#0d0h
         mov sbuf,A         ;;;;;; 4
deng2:
         jbc ti,SEND_DA2
         jmp deng2
SEND_DA2:
         mov a,v1da    ;;send vol1
         ;clr tb8
         mov sbuf,A         ;;;;;; 5
deng3:
        jbc  ti,SEND_DA3
        jmp  deng3
SEND_DA3:
        mov  a,#40h
        mov  sbuf,A        ;;;;;; 6
deng4:
        jbc  ti,SEND_DA4
        ljmp deng4
SEND_DA4:
        mov  a,LINE_DA  ;;send line
        anl  a,#0fh
        orl  a,#0b0h
        mov  sbuf,A       ;;;;;; 7
deng5:
       jbc   ti,SEND_OUT
       ljmp  deng5
SEND_OUT:
CLR RT_485
setb ren
setb es
pop a
retI
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
