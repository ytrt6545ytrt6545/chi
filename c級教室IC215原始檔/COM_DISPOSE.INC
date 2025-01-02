;;;;;;;;;;;;;;;;;;;;;;;;
ID_DATA:
    MOV  a,60H
    CJNE A,#57H,COMM_R
    LJMP COMM_W1
COMM_R:
    CJNE A,#52H,COMM_K
    LJMP COMM_R1
;COMM_P:
;    CJNE A,#50H,COMM_M
;    LJMP COMM_P1
;COMM_M:
;    CJNE A,#4DH,COMM_K
;    LJMP COMM_M1
COMM_K:
    CJNE A,#4BH,COMM_V
    LJMP COMM_K1
COMM_V:
    CJNE A,#56H,COMM_S
    LJMP COMM_V1
COMM_S:
    CJNE A,#53H,commout
    LJMP COMM_S1
;========================
COMM_W1:
    MOV   a,61H
    cjne  a,#2Eh,COMM_W1_20H
    LJMP  COMM_W1_2EH
COMM_W1_20H:
    cjne  a,#20h,commout
;;;;
    lcall benji_id
    XRL   A,62H
    JNZ   commout
;;;;
COMM_W1_2EH:
    mov   A,63H
    cjne  a,#20h,commout
    mov   A,65H
    cjne  a,#20h,commout
    MOV   A,64H
    CJNE  A,#30h,COMM_W2
    MOV   A,66H
    CJNE  A,#31H,COMM_W2_1
    LCALL POW_ON_COM
    RET
COMM_W2_1:
    CJNE  A,#32H,COMM_W2_2
    LCALL POW_OFF_COM
    RET
COMM_W2_2:
    CJNE  A,#33H,COMM_W2_3
    LCALL MUTEOFF
    RET
COMM_W2_3:
    CJNE  A,#34H,COMM_W2_4
    LCALL MUTEON
COMM_W2_4:
    RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMM_W2:
    cjne  a,#31h,COMM_W3
    MOV   A,66H
    cjne  a,#31h,COMM_W3_31H
    SETB  B_SW1
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_W3_31H:
    cjne  a,#32h,COMM_W3_32H
    CLR   B_SW1
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_W3_32H:
    cjne  a,#33h,COMM_W3_33H
    SETB  B_SW2
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_W3_33H:
    cjne  a,#34h,COMM_W3_34H
    CLR   B_SW2
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_W3_34H:
    cjne  a,#35h,COMM_W3_35H
    SETB  B_SW3
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_W3_35H:
    cjne  a,#36h,COMM_W3_36H
    CLR   B_SW3
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_W3_36H:
    cjne  a,#37h,COMM_W3_37H
    setb  B_V_L
    ret
COMM_W3_37H:
    cjne  a,#38h,COMM_W3_38H
    CLR   B_V_L
    ret
COMM_W3_38H:
    cjne  a,#39h,COMM_W3_39H
    setb  B_PRI
    ret
COMM_W3_39H:
    cjne  a,#41h,COMM_W3_41H
    CLR   B_PRI
    ret
COMM_W3_41H:
    cjne  a,#42h,COMM_W3_42H
    SETB  B_PAGE

    RET
COMM_W3_42H:
    cjne  a,#43h,COMM_W3_43H
    CLR   B_PAGE

COMM_W3_43H:
    RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMM_W3:
    cjne  a,#32h,COMM_W4
    MOV   A,66H
    cjne  a,#31h,COMM_W4_31H
    CALL  KCOM12
COMM_W4_31H:
    cjne  a,#32h,COMM_W4_32H
    CALL  KCOM22
COMM_W4_32H:
    RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMM_W4:
    cjne  a,#33h,COMM_W5
    MOV   A,66H
    cjne  a,#31h,COMM_W5_31H
    LCALL KCOM14
COMM_W5_31H:
    cjne  a,#32h,COMM_W5
    LCALL KCOM24
COMM_W5:
    RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMM_R1:
    MOV   a,61H
    cjne  a,#2Eh,COMM_R1_20H
    LJMP  COMM_R1_2EH_1
commout2:
    LJMP  commout
COMM_R1_20H:
    cjne  a,#20h,commout2
;;;;
    lcall benji_id
    XRL   A,62H
    JNZ   commout2
COMM_R1_2EH_1:
;;;;
    mov   A,63H
    cjne  a,#20h,commout2
    mov   A,65H
    cjne  a,#20h,commout2
    mov   A,64H
    cjne  a,66H,commout2
    MOV   a,66H
    cjne  a,#31h,MUTE_STATUS1
    MOV   COMMSADA,#1H
    SETB  B_COM
    RET
MUTE_STATUS1:
    cjne  a,#32h,SW1_STATUS1
    MOV   COMMSADA,#2H
    SETB  B_COM
    RET
SW1_STATUS1:
    cjne  a,#33h,SW2_STATUS1
    MOV   COMMSADA,#3H
    SETB  B_COM
    RET
SW2_STATUS1:
    cjne  a,#34h,SW3_STATUS1
    MOV   COMMSADA,#4H
    SETB  B_COM
    RET
SW3_STATUS1:
    cjne  a,#35h,BLV_STATUS1
    MOV   COMMSADA,#5H
    SETB  B_COM
    RET
BLV_STATUS1:
    cjne  a,#36h,B_PRI_STATUS1
    MOV   COMMSADA,#6H
    SETB  B_COM
    RET
B_PRI_STATUS1:
    cjne  a,#37h,B_PAGE_STATUS1
    MOV   COMMSADA,#7H
    SETB  B_COM
    RET
B_PAGE_STATUS1:
    cjne  a,#38h,VOL_STATUS1
    MOV   COMMSADA,#8H
    SETB  B_COM
    RET
VOL_STATUS1:
    cjne  a,#39h,SOURCE_STATUS1
    MOV   COMMSADA,#9H
    SETB  B_COM
    RET
SOURCE_STATUS1:
    cjne  a,#41h,ALL_STATUS1
    MOV   COMMSADA,#0AH
    SETB  B_COM
    RET
ALL_STATUS1:
    cjne  a,#42h,ALL_STATUS2
    MOV   COMMSADA,#0BH
    SETB  B_COM
ALL_STATUS2:
    RET
;;;;;;;;;;;;;;;;;;;;;;;;;
commout3:
    LJMP  commout
;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;
COMM_K1:
    MOV   a,61H
    cjne  a,#20h,commout4
;;;;
    ORL   P3,#11110000B
    mov   a,p3
    nop
    anl   a,#11110000b
    SWAP  a
    clr   c
    cjne  a,#0ah,COMM_K1_addr
COMM_K1_addr:
    JC    COMM_K1_add
    add   a,#30h
    ljmp  COMM_K1_ad
;;;;;;;;;;;;;;;;;;
commout4:
    LJMP  commout
;;;;;;;;;;;;;;;;;;
COMM_K1_add:
    add   a,#31h
COMM_K1_ad:
    da    a
    xrl   a,62h
    jnz   commout4
;;;;
    mov   A,63H
    cjne  a,#20h,commout4
    mov   A,65H
    cjne  a,#20h,commout4
    mov   A,64H
    cjne  a,#31H,commout4
    MOV   a,66H
    cjne  a,#31h,COMM_K1_32h
    SETB  B_SW1
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    ret
COMM_K1_32h:
    cjne  a,#32h,COMM_K1_33h
    CLR   B_SW1
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_K1_33h:
    cjne  a,#33h,COMM_K1_34h
    SETB  B_SW2
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_K1_34h:
    cjne  a,#34h,COMM_K1_35h
    CLR   B_SW2
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_K1_35h:
    cjne  a,#35h,COMM_K1_36h
    SETB  B_SW3
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_K1_36h:
    cjne  a,#36h,COMM_K1_37h
    CLR   B_SW3
    LCALL MUTEOFF
    SETB  B_KK
    CLR   B_K_TRU
    RET
COMM_K1_37h:
    cjne  a,#37h,COMM_K1_38h
    setb  B_V_L
    ret
COMM_K1_38h:
    cjne  a,#38h,COMM_K1_39h
    CLR   B_V_L
    ret
COMM_K1_39h:
    cjne  a,#39h,COMM_K1_41h
    setb  B_PRI
    ret
COMM_K1_41h:
    cjne  a,#41h,COMM_K1_42h
    CLR   B_PRI
    ret
COMM_K1_42h:
    cjne  a,#42h,COMM_K1_43h
    SETB  B_PAGE
    ret
COMM_K1_43h:
    cjne  a,#43h,COMM_K1_44h
    CLR   B_PAGE
COMM_K1_44h:
    ret
;;;;;;;;;;;;;
COMM_V1:
    MOV   a,61H
    cjne  a,#20h,commout5
;;;;
    ORL   P3,#11110000B
    mov   a,p3
    nop
    anl   a,#11110000b
    SWAP  a
    clr   c
    cjne  a,#0ah,COMM_V1_addr
COMM_V1_addr:
    JC    COMM_V1_add
    add   a,#30h
    ljmp  COMM_V1_ad
COMM_V1_add:
    add   a,#31h
COMM_V1_ad:
    da    a
    xrl   a,62h
    jnz   commout5
;;;;
    mov   A,63H
    cjne  a,#20h,commout5
    mov   A,65H
    cjne  a,#20h,commout5

    mov   A,64H
    anl   a,#00001111b
    swap  a
    mov   64h,a
    MOV   a,66H
    anl   a,#00001111b
    ORL   a,64h
    mov   66h,a
    MOV   v1da,A
    LCALL JISUAN
    Lcall pt2257_2ch_vl
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
commout5:
    LJMP  commout
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMM_S1:
    MOV   a,61H
    cjne  a,#20h,commout5
;;;;
    ORL   P3,#11110000B
    mov   a,p3
    nop
    anl   a,#11110000b
    SWAP  a
    clr   c
    cjne  a,#0ah,COMM_S1_addr
COMM_S1_addr:
    JC    COMM_S1_add
    add   a,#30h
    ljmp  COMM_S1_ad
COMM_S1_add:
    add   a,#31h
COMM_S1_ad:
    da    a
    xrl   a,62h
    jnz   commout5
;;;;
    mov   A,63H
    cjne  a,#20h,commout5
    mov   A,65H
    cjne  a,#20h,commout5

    mov   A,64H
    anl   a,#00001111b
    swap  a
    mov   64h,a
    MOV   a,66H
    anl   a,#00001111b
    anl   a,64h
    mov   66h,a
    cjne  a,#01h,COMM_S1_2H
    lcall KCOM31
    LCALL LINE_SET
    ret
COMM_S1_2H:
    cjne  a,#02h,COMM_S1_3H
    CALL  KCOM32
    CALL  LINE_SET
    RET
COMM_S1_3H:
    cjne  a,#03h,COMM_S1_4H
    CALL  KCOM33
    CALL  LINE_SET
    RET
COMM_S1_4H:
    cjne  a,#04h,COMM_S1_5H
    CALL  KCOM34
    CALL  LINE_SET
    RET
COMM_S1_5H:
    cjne  a,#05h,COMM_S1_6H
    CALL KCOM35
    CALL LINE_SET
    RET
COMM_S1_6H:
    cjne  a,#06h,COMM_S1_7H
    CALL KCOM36
    CALL LINE_SET
    RET
COMM_S1_7H:
    cjne  a,#07h,COMM_S1_8H
    CALL KCOM37
    CALL LINE_SET
    RET
COMM_S1_8H:
    cjne  a,#08h,COMM_S1_9H
    CALL KCOM38
    CALL LINE_SET
COMM_S1_9H:
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;
