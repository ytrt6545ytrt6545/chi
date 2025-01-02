K_COM:
       MOV   TMP_A,A
       MOV   TMP_PSW,PSW
       PUSH  PSW
       PUSH  A
       JNB   B_K_TRU,NOCOM
       MOV   A,KEYDA
       JNZ   COMMAND
NOCOM:
       MOV   KEYDA,#00H
       MOV   KJS,#00H
       POP   A
       POP   PSW
       JB    B_PRI,PRI_CHICK
PRI_CHICK_OUT:
;       JB    B_PAGE,PAGE_CHICK
;PAGE_CHICK_OUT:
       RET
PRI_CHICK:
       JB    B_KK,PRI_CHICK_OUT
       JB    B_COMM_PRI,PRI_CHICK_OUT
       CLR   B_PRI
       CLR   B_PAGE_LED
       CLR   B_PAGE
       LCALL COMMSENDPRI
       RET
;PAGE_CHICK:
;       JB    B_KK,PAGE_CHICK_OUT
;       JB    B_COMM_PAGEA,PAGE_CHICK_OUT
;       CLR   B_PRI
;       CLR   B_PAGE_LED
;       CLR   B_PAGE
;       LCALL COMMSENDPAGE
;       RET
;;;;;;;;;;
KDENG: INC  KJS
       MOV  A,KJS
       CJNE A,#1,KD1
       RET
KD1:   CLR  C
       SUBB A,#KJS_1
       JC   KD1O
       MOV  A,KJS
       CJNE A,#39H,KD1O
       MOV  KJS,#KJS_1
       MOV  A,#1
KD1O:  RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMMAND:
       CJNE  A,#11H,NOK11
       CLR   B_COMM_XP
       JB    P_ON,CHOOSEMUTE
       JB    B_KK,TB1
       CALL  POW_ON_COM
       LJMP  com_out_m
CHOOSEMUTE:
       LCALL MUTE3S
       LJMP  com_out_m
NOK11: JNB   P_ON,TB1
       CJNE  A,#12H,NOK12
       JB    B_KK,TB1
       LCALL MUTE_COM
       LCALL COMMSENDMUTE
       LJMP  com_out_m
NOK12:
;clr b_mu
        setb mute
        CJNE A,#13H,NOK13   ;;;;;;;;;VOL U
        CALL KCOM12
        LJMP com_out_m
NOK13:  CJNE A,#14H,NOK14  ;;;;;;;;;VOL2 D
        CALL KCOM22
        LJMP com_out_m
NOK14:
        CJNE A,#15H,NOK15
        JB   B_KK,TB1
        CALL KCOM14
        CALL LINE_SET
        LCALL COMMSENDSOURCE
        Ljmp com_out
TB1:    LJMP COM_OUT_NM        ;BU KAI MUTE
NOK15:
        CJNE A,#16H,NOK16
        JB   B_KK,TB1
        CALL KCOM24
        CALL LINE_SET
        LCALL COMMSENDSOURCE
        LJMP COM_OUT
NOK16:
        CJNE A,#21H,NOK21
        JB   B_KK,TB1
        CALL KCOM31
        CALL LINE_SET
        MOV   LINE_DA,#01H
        LCALL COMMSENDSOURCE
        JMP COM_OUT
NOK21:
        CJNE A,#22H,NOK22
        JB B_KK,TB1
        CALL KCOM32
        CALL LINE_SET
        MOV   LINE_DA,#02H
        LCALL COMMSENDSOURCE
        JMP   COM_OUT
NOK22:
        CJNE  A,#23H,NOK23
        JB    B_KK,TB1
        CALL  KCOM33
        CALL  LINE_SET
        MOV   LINE_DA,#03H
        LCALL COMMSENDSOURCE
        JMP   COM_OUT
NOK23:  CJNE A,#24H,NOK24
        JB   B_KK,TB1
        CALL KCOM34
        CALL LINE_SET
        MOV   LINE_DA,#04H
        LCALL COMMSENDSOURCE
        JMP  COM_OUT
TB2:    LJMP COM_OUT_NM        ;BU KAI MUTE
NOK24:  CJNE A,#25H,NOK25
        JB   B_KK,TB2
        CALL KCOM35
        CALL LINE_SET
        MOV   LINE_DA,#05H
        LCALL COMMSENDSOURCE
        JMP COM_OUT
NOK25:  CJNE A,#26H,NOK26
        JB B_KK,TB2
        CALL KCOM36
        CALL LINE_SET
        MOV   LINE_DA,#06H
        LCALL COMMSENDSOURCE
        JMP COM_OUT
NOK26:  CJNE A,#31H,NOK31
        JB B_KK,TB2
        CALL  KCOM37
        CALL  LINE_SET
        MOV   LINE_DA,#07H
        LCALL COMMSENDSOURCE
        LJMP  COM_OUT
NOK31:  CJNE  A,#32H,NOK32
        JB    B_KK,TB2
        CALL  KCOM38
        CALL  LINE_SET
        MOV   LINE_DA,#08H
        LCALL COMMSENDSOURCE
        LJMP  COM_OUT
NOK32:  CJNE  A,#33H,NOK33
        JB    B_KK,TB2
        CPL   B_SW1
        LCALL COMMSENDSW1
        LJMP  COM_OUT
NOK33:  CJNE  A,#34H,NOK34
        JB    B_KK,TB3
        CPL   B_SW2
        LCALL COMMSENDSW2
        LJMP  COM_OUT
TB3:    LJMP  COM_OUT_NM        ;BU KAI MUTE
NOK34:  CJNE  A,#35H,NOK35
        JB    B_KK,TB3
        CPL   B_SW3
        LCALL COMMSENDSW3
        LJMP  COM_OUT
NOK35:  CJNE  A,#36H,NOK17
NOK35XD:CLR   B_COMM_PAGE
        JB    B_MU,PAGE1
        
        JB    B_PAGE_LED,NOK35XDCD
        MOV   R0,#0E0H
        MOV   @R0,LINE_DA
        MOV   LINE_DA,#08H
        LCALL LINE_SET
        LCALL KEY_DISPLAYSOURCE
        
NOK35XDCD:
        SETB  B_PAGE_LED
        SETB  B_PAGE
        
        JB    B_KK,COM_OUT_NM
        LCALL COMMSENDPAGE
        LJMP  COM_OUT
NOK17:  CJNE  A,#17H,COM_OUT_NM
        JB    B_KK,COM_OUT_NM
        CLR   B_COMM_PRI
NOK17_COMM:
        JB    B_MU,PAGE2
        SETB  B_PRI
        LCALL COMMSENDPRI
        LJMP  COM_OUT
PAGE2:  SETB  B_PRI
        LCALL COMMSENDPRI
        SETB  MANA
        LJMP  GOOD1XD
COM_OUT:
        LCALL MUTEOFF
com_out_m: NOP;call send_cpu_id
COM_OUT_NM:  ; OUT AND NO MUTE off
         SETB B_KK   ;; dai biao an jian wei song
         CLR  B_K_TRU
         POP  A
         POP  PSW
         RET
PAGE1:
      SETB  B_PAGE_LED
      SETB  B_PAGE
      SETB  MANA
GOOD:
      CALL  MUTEOFF
      LCALL COMMSENDPAGE
      SETB  B_KK
      CLR   B_K_TRU
      POP   A
      POP   PSW
      RET
;;;;;;;;;;;;;;;;;;;;;;;;;;
GOOD1XD:
      CALL MUTEOFF
      SETB B_KK
      CLR  B_K_TRU
      POP  A
      POP  PSW
      RET
;;;;;;;;;;;;;;;;;;;;;;;;;;
KCOM12:
        LCALL KDENG
CC11:   CJNE  A,#1,KCOM12_O
        MOV   R0,#V1DA
        MOV   A,@R0
        CJNE  A,#99H,V1JIA
        LJMP  KCOM12_O
V1JIA:
        LCALL JIA
        LCALL MUTEOFF
        LCALL JISUAN
        LCALL COMMSENDVOL
KCOM12_O:
        NOP
     GOON:
        LCALL P24_SAVE_VOL
        LCALL pt2257_2ch_vl
        RET
KCOM22:; MOV DIS3,#063H
        LCALL KDENG
        CJNE  A,#1,KCOM22_O
        MOV   R0,#V1DA
        MOV   A,@R0
        CJNE  A,#0H,V1JIAN
        LJMP  KCOM22_O
V1JIAN:
        LCALL JIAN
        LCALL MUTEOFF
        LCALL JISUAN
        LCALL COMMSENDVOL
KCOM22_O:
        nop
  GOON2:LCALL P24_SAVE_VOL
        Lcall pt2257_2ch_vl
        RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
KEY_DISPLAYSOURCE:
        MOV   A,LINE_DA
        CJNE  A,#01H,KEY_DISPLAYSOURCE_1
        MOV   DIS1,#06H    ;;1
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
KEY_DISPLAYSOURCE_8:
        MOV LINE_DA,#1
        RET
KEY_DISPLAYSOURCE_1:
        CJNE  A,#02H,KEY_DISPLAYSOURCE_2
        MOV   DIS1,#5BH    ;;2
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
        RET
KEY_DISPLAYSOURCE_2:
        CJNE  A,#03H,KEY_DISPLAYSOURCE_3
        MOV   DIS1,#4FH    ;;3
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
        RET
KEY_DISPLAYSOURCE_3:
        CJNE  A,#04H,KEY_DISPLAYSOURCE_4
        MOV   DIS1,#66H    ;;4
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
        RET
KEY_DISPLAYSOURCE_4:
        CJNE  A,#05H,KEY_DISPLAYSOURCE_5
        MOV   DIS1,#6DH    ;;5
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
        RET
KEY_DISPLAYSOURCE_5:
        CJNE  A,#06H,KEY_DISPLAYSOURCE_6
        MOV   DIS1,#7DH    ;;6
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
        RET
KEY_DISPLAYSOURCE_6:
        CJNE  A,#07H,KEY_DISPLAYSOURCE_7
        MOV   DIS1,#07H    ;;7
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
        RET
KEY_DISPLAYSOURCE_7:
        CJNE  A,#08H,KEY_DISPLAYSOURCE_8
        MOV   DIS1,#7FH    ;;8
        MOV   DIS2,#08H  ;L  ;;n
        SETB  B_V_L
        RET

KCOM31:
MOV DIS1,#06H    ;;1
MOV DIS2,#08H  ;L  ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#1
JMP SA_LINE
KCOM32:
MOV DIS1,#5BH    ;;2
MOV DIS2,#08H    ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#2
JMP SA_LINE
KCOM33:
MOV DIS1,#4FH    ;;3
MOV DIS2,#08H    ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#3
JMP SA_LINE
KCOM34:
MOV DIS1,#66H    ;;4
MOV DIS2,#08H    ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#4
JMP SA_LINE
KCOM35:
MOV DIS1,#6DH    ;;5
MOV DIS2,#08H    ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#5
JMP SA_LINE
KCOM36:
MOV DIS1,#7DH    ;;6
MOV DIS2,#08H    ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#6
JMP SA_LINE
KCOM37:
MOV DIS1,#07H    ;;7
MOV DIS2,#08H    ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#7
JMP SA_LINE
KCOM38:
MOV DIS1,#7FH    ;;8
MOV DIS2,#08H    ;;n
SETB B_V_L
;MOV DIS3,#38H    ;;L
MOV LINE_DA,#8
SA_LINE:
MOV SA_ADD,#SA_LI_ADD
MOV SA_DATA,LINE_DA
CALL B_W
RET
KCOM14:                  ;; ----------fun up
;INC LINE_DA
XSLINE:
MOV A,LINE_DA
LLN1:CJNE a,#1,LLN2
     JMP KCOM32
LLN2: CJNE A,#2,LLN3
     JMP KCOM33
LLN3: CJNE A,#3,LLN4
     JMP KCOM34
LLN4: CJNE A,#4,LLN5
      JMP KCOM35
LLN5: CJNE A,#5,LLN6
      JMP KCOM36
LLN6: CJNE A,#6,LLN7
      JMP KCOM37
LLN7: CJNE A,#7,LLN8
      JMP KCOM38
LLN8:; CJNE A,#8,LLN9
      JMP KCOM31



KCOM24:                 ;; ------fun down
;DEC LINE_DA
MOV A,LINE_DA
LLNN1: CJNE a,#8,LLNN2
       JMP KCOM37
LLNN2: CJNE A,#7,LLNN3
       JMP KCOM36
LLNN3: CJNE A,#6,LLNN4
       JMP KCOM35
LLNN4: CJNE A,#5,LLNN5
       JMP KCOM34
LLNN5: CJNE A,#4,LLNN6
       JMP KCOM33
LLNN6: CJNE A,#3,LLNN7
       JMP KCOM32
LLNN7: CJNE A,#2,LLNN8
       JMP KCOM31
LLNN8:; CJNE A,#0,LLNN9
       ;MOV LINE_DA,#8
       JMP KCOM38
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
POWER_COM:
    JB    P_ON,MUTE3S
    LCALL COMMSENDPOWER
POW_ON_COM:
    nop
    nop
    LCALL RRR
    NOP
    LCALL RRR
    MOV   SP,#SPXX
    JB    B_COMM_P1,RRR1
    SETB  B_COMM_P2
RRR1:
    JNB   B_COMM_P2,RRR2
    SETB  B_COMM_P1
RRR2:
    LJMP  SETF
RRR:RETI
    RET
POWER_COM2:
JB  P_ON,POW_OFF_COM
JMP POW_ON_COM

POW_OFF_COM:
  MOV   TMOD,#21H
  CLR   P_ON
  CLR   B_MU
  clr   mute
  SETB  B_P
  CLR   B_PAGE_LED ;;;;;;;;XXXXXXXXXXX
  MOV   DIS1,#00H
  MOV   DIS2,#00H
  mov   pt2257_MUTE_DZ,#01111001b
  call  pt2257_mute
  anl   21h,#11110000b
  RET
MUTE_COM:
        JNB   B_MU,MUTEON
MUTEOFF:
        CLR   B_MU
        SETB  MUTE
        mov   pt2257_MUTE_DZ,#01111000b
        call  pt2257_mute
        RET
MUTEON:
        SETB  B_MU
        CLR   MUTE
        mov   pt2257_MUTE_DZ,#01111001b
        Lcall pt2257_mute
        RET
MUTE3S:
       MOV   NUM,#00H
       SETB  B_MU
       CLR   MUTE
       LCALL COMMSENDMUTE
TIME:  LCALL MUTEON
       LCALL DISPLAY
       LCALL DISPLAY
       LCALL KEY_JUDGE
       LCALL DISPLAY
       JNB   SW1_FLG,MUTEON
       LCALL DISPLAY
       MOV   TMOD,#20H
       mov   th1,#0FDh      ;;²¨ÌØÂÊÎª9600
       setb  tr1
       LCALL DISPLAY
       SETB  TR1
       CLR   TF1
       JNB   TF1,$
       LCALL DISPLAY
       INC   NUM
       MOV   A,NUM
       CJNE  A,#0ffH,TIME
       CLR   P_ON
       SETB  B_P
       LCALL COMMSENDPOWER
       LJMP  POW_OFF_COM
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
KEY_JUDGE:
       CLR   SW1_FLG
       ANL   P0,#11100001B
       ORL   P0,#11100000B
       MOV   P2,#0FFH
       ANL   P0,#11011111B
       MOV   P2,#0FFH
       MOV   A,P2
       CJNE  A,#11111110B,YAODE
       SETB  SW1_FLG
       RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
YAODE: MOV   TMOD,#21H
       LJMP  MUTEON
