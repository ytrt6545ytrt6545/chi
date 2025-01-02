;无头码，收全后返回。

INT0ZD: PUSH  PSW
        PUSH  A
        anl   p0,#11100001b    ;;jian ji 20050114
        SETB  TR0
        CLR   rs0
        SETB  RS1
        LCALL YK_CLR
        LCALL delay140us
        JB    INT_D,YKRET
        ANL   p0,#1h     ;^-^
        ANL   p2,#0h     ;^-^
        ORL   p0,#2h     ;^-^
        ORL   p2,#80h    ;^-^
        MOV   TL0,#0h
        MOV   TH0,#0
PDGD:   MOV   A,TH0
        SUBB  A,#8
        JZ    YKRET
        JNB   INT_D,PDGD ;;DENG DAI GAO
        ;anl  p0,#1h     ;^-^
        ;anl  p2,#0h     ;^-^
        ;orl  p0,#2h     ;^-^
        ;orl  p2,#80h     ;^-^
        MOV   A,TH0
        MOV   TH0,#0
        MOV   TL0,#0
        clr   c
        SUBB  A,#3H
        Jc    DI
   GAO: mov   a,@r0
        rl    a
        orl   a,#1b
        mov   @r0,a
        lJMP  PDWAN
     DI:MOV   A,@R0
        Rl    A
        ANL   A,#11111110B
        MOV   @R0,A
 PDWAN: DJNZ  R7,NHUANSHU
        MOV   A,YKDAD
        CJNE  A,#2,YK_NW
        lJMP  YK_WAN

;YK_NWW: call yk_nowan
      ;  JMP PDGD
YK_WAN:; CLR B_YK_DA
        CLR IE0
        MOV A,YKDA4
        ADD A,YKDA2
        CJNE A,YKDA1,YKRET
        mov POWER_DATA,#03FH
        SETB B_POWER
        ;mov  P0,#10001000B
        ;MOV  P2,A
        ;CALL DLA2S
        lCALL COMM_YK

;======================
        ;lcall send_cpu_id
        MOV A,#00H
YKRET:  anl  p0,#00000001b
        MOV YKDA1,A
        POP A
        POP PSW
        RETI
YK_NW: lcall yk_nowan
NHUANSHU:;anl  p0,#1h     ;^-^
        ;anl  p2,#0h     ;^-^
        ;orl  p0,#2h     ;^-^
        ;orl  p2,#80h     ;^-^
        MOV A,TH0
        SUBB A,#8
        JZ YKRET
        JB INT_D,NHUANSHU   ;; DENG DAI DI
        MOV A,TH0
        MOV TH0,#0
        MOV TL0,#0
        clr c
        SUBB A,#3H
        Jc  DII
GAOO:   mov a,@r0
        rl a
        orl a,#1b
        mov @r0,a
        lJMP PDWANN
DII:    MOV A,@R0
        Rl A
        ANL A,#11111110B
        MOV @R0,A
PDWANN: ;anl  p0,#00000001b     ;^-^
        DJNZ R7,PDGD1
        MOV A,YKDAD
        CJNE A,#2,YK_NWW
        lJMP YK_WAN
PDGD1:  ljmp PDGD
YK_NWW: lcall yk_nowan
        lJMP PDGD
YK_NOWAN: inc YKDAD
          dec r0
          mov @r0,#0
          mov r7,#8h
          ret
YK_CLR:; MOV YKDA,#0
        MOV 17H,#7H     ;MOV R7,#8
;;;     MOV YKDA1,#0
;       MOV YKDA2,#77h
;       MOV YKDA3,#0
        MOV YKDA4,#0
        MOV YKDAD,#0
;       MOV YKTR1,#YKTR11
;
;       MOV TL1,#0
;       mov   th1,#0f3h
        MOV 10H,#036h     ;DATA ADD     chu shi yao kong di zhi
        RET

comm_yk:
;anl  p0,#00000001b     ;^-^
CJNE A,#0FcH,N_YKC11
MOV YKDA1,#0
setb B_COM
MOV  COMMSADA,#01h
CALL POWER_COM2    ;;;;;;;;;;         power
RET
N_YKC11:
JB P_ON,K_YK  ;KE YI YAO KONG
RET
K_YK:
CJNE A,#0feH,N_YKC21
MOV YKDA1,#0
setb B_COM
MOV  COMMSADA,#02h
CALL MUTE_COM   ;;;;;;;;;;;        mute
RET
N_YKC21:
cjne a,#01dh,N_YKC12
call KCOM12     ;;;;;;;;;;;;;;;V1+++
JMP YK_MU_RET
N_YKC12:
CJNE A,#005H,N_YKC_sw1
CALL KCOM22     ;;;;;;;;;;;;;;;V1---
JMP YK_MU_RET
N_YKC_sw1:
cjne a,#04H,N_YKC_sw2
;;;///call kcom13     ;;;;;;;;;;;;;;;SW1;;;;;;;;;;;;;
setb B_COM
MOV  COMMSADA,#03h
CPL B_SW1
JMP YK_MU_RET
n_YKC_sw2:
CJNE A,#01CH,N_YKC_sw3
;;;///CALL KCOM23    ;;;;;;;;;;;;;;;;SW2;;;;;;;;;;;
setb B_COM
MOV  COMMSADA,#04h
CPL B_SW2
JMP YK_MU_RET
N_YKC_sw3:
CJNE A,#7CH,N_YKC23
setb B_COM
MOV  COMMSADA,#05h
CPL B_SW3              ;;;;;;;;;;;;;;;;;;SW3;;;;;;;;;;;
JMP YK_MU_RET
N_YKC23:
CJNE A,#0fdH,N_YKC233
;;CALL YKFUNUP     ;;;;;;;;;;;;;;;;; fun sou UP
setb B_COM
MOV  COMMSADA,#0ah
call kcom14
CALL LINE_SET
JMP YK_MU_RET
N_YKC233:
CJNE A,#07dh,N_YKC26
;;CALL YKFUNDO  ;;;;;;;;;;;;;;;;;;;; fun sou DO
setb B_COM
MOV  COMMSADA,#0ah
call kcom24
CALL LINE_SET
JMP YK_MU_RET
;;;///N_YKC14:
;;;///CJNE A,#0f9H,N_YKC16
;;;\\\MOV YKDA1,#0
;;;\\\CALL KCOM16   ;;;;;;;;;;;;;;;;;;;;;;key 0
;;;///JMP YK_MU_RET
;;;///N_YKC16:
;;;///CJNE A,#0FaH,N_YKC15
;;;\\\CALL KCOM15   ;;;;;;;;;;;;;;;;;;;;;;key up
;;;///JMP YK_MU_RET
;;;///N_YKC15:
;;;///CJNE A,#0f8H,N_YKC25
;;;\\\CALL KCOM25   ;;;;;;;;;;;;;;;;;;;;;;;; key do
;;;///JMP YK_MU_RET
;;;///N_YKC25:
;;;///CJNE A,#0ffH,N_YKC26
;;;///MOV YKDA1,#0
;;;\\CALL KCOM26  ;;;;;;;;;;;;;;;;;;;;;   off auto on
;;;///JMP YK_MU_RET
N_YKC26:
ret
YK_MU_RET:
CLR B_MU
SETB MUTE
CALL MUTEOFF
RET

;===================================
;====================================
yccomret: mov  ykda2,#77h
          ret
delay140us:
          mov  r3,#70
          djnz r3,$
          ret
