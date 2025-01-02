pt2257_2ch_vl:
    PUSH PSW
    PUSH A
    CLR  RS0
    CLR  RS1
    CALL pt2257_vl_str
    MOV  A,#10001000B   ;;;
    CALL pt2257_vl_send
    CALL pt2257_vl_ack
    MOV  A,pt2257_2ch_vl_dz
    MOV  DPTR,#VOL_DB
    nop
    MOVC A,@A+DPTR
    nop
    SWAP A
    ;;-----------------------------------
    ANL A,#00001111B
    ORL A,#11100000B            ;shi wei
    CALL pt2257_vl_send
    CALL pt2257_vl_ack
    ;;-----------------------jian fa   79-xian shi yin liang
    MOV  A,pt2257_2ch_vl_dz
    MOV  DPTR,#VOL_DB
    nop
    MOVC A,@A+DPTR
    nop
    ;;-----------------------------------
    ANL A,#00001111B
    ORL A,#11010000B          ; ge wei
    CALL pt2257_vl_send
    CALL pt2257_vl_ack
    CALL pt2257_vl_stop
VLBBOUT:
    POP  A
    POP  PSW
    ret
;--------------------------------------------
pt2257_vl_str:
       SETB pt2257_scl
       SETB pt2257_sda
       nop
       CLR  pt2257_sda
       ret
;--------------------------------------------
pt2257_vl_send:
       CLR  pt2257_scl
       MOV  R1,#08H
VLSD1: JB   ACC.7,VLSD2
       CLR  pt2257_sda
       JMP  VLSD3
VLSD2: SETB pt2257_sda
VLSD3: SETB pt2257_scl
       RL   A
       CLR  pt2257_scl
       DJNZ R1,VLSD1
       ret
;----------------------------------------------
pt2257_vl_ack:
        CLR pt2257_scl   ;;;Ack
        CLR pt2257_sda
        SETB pt2257_scl
        CLR pt2257_scl
        retI
;----------------------------------------------
pt2257_vl_stop:   ;;stop
     CLR pt2257_scl
     CLR pt2257_sda
     SETB pt2257_scl
     nop
     SETB pt2257_sda
     CLR pt2257_scl
     retI
;;;;;;;;;
pt2257_mute:
    PUSH PSW
    PUSH A
    CLR RS0
    CLR RS1
    CALL pt2257_vl_str
    MOV A,#10001000B   ;;;
    CALL pt2257_vl_send
    CALL pt2257_vl_ack
    MOV A,pt2257_MUTE_DZ   ; 01111000b=mute off <>01111001b=mute on;;;;;+00;;;;;;;;;
    CALL pt2257_vl_send
    CALL pt2257_vl_ack
    CALL pt2257_vl_stop
    POP A
    POP PSW
    retI
;;;;;;;;
