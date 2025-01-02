;;;;;;;;;;;;;;;;;;;;;;;;;
COMMSENDPOWER:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#31H
      MOV   C,B_P
      NOP
      JNC    COMM_SENDALL1
      MOV   COMMDATA3,#32H
COMM_SENDALL1:
      LCALL send_ZT     ;僕POWER
      RET
;;;;;;;;;
COMMSENDMUTE:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#33H
      mov   C,B_MU
      NOP
      JC    COMM_SENDALL2
      MOV   COMMDATA3,#34H
COMM_SENDALL2:
      LCALL send_ZT     ;僕MUTE
      RET
;;;;;;;;;
COMMSENDSW1:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#35H
      MOV   C,B_SW1
      JC    COMM_SENDALL3
      MOV   COMMDATA3,#36H
COMM_SENDALL3:
      LCALL send_ALLZT  ;僕sw1
      RET
;;;;;;;;;
COMMSENDSW2:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#37H
      MOV   C,B_SW2
      JC    COMM_SENDALL4
      MOV   COMMDATA3,#38H
COMM_SENDALL4:
      LCALL send_ALLZT   ;僕sw2
      RET
;;;;;;;;;
COMMSENDSW3:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#39H
      MOV   C,B_SW3
      JC    COMM_SENDALL5
      MOV   COMMDATA3,#41H
COMM_SENDALL5:
      LCALL send_ALLZT    ;僕sw3
      RET
;;;;;;;;;
;;;;;;;;;
COMMSENDBVL:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#42H
      MOV   C,B_V_L
      JC    COMM_SENDALL6
      MOV   COMMDATA3,#43H
COMM_SENDALL6:
      LCALL send_ZT    ;僕B！！V！！L
      RET
;;;;;;;;;
;;;;;;;;;
COMMSENDPRI:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#44H
      MOV   C,B_PRI
      JC    COMM_SENDALL7
      MOV   COMMDATA3,#45H
COMM_SENDALL7:
      LCALL send_ZT    ;僕PRI
      RET
;;;;;;;;;
;;;;;;;;;
COMMSENDPAGE:
      MOV   COMMDATA1,#57H
      MOV   COMMDATA2,#30H
      MOV   COMMDATA3,#46H
      MOV   C,B_PAGE
      JC    COMM_SENDALL8
      MOV   COMMDATA2,#31H
      MOV   COMMDATA3,#30H
COMM_SENDALL8:
      LCALL send_ZT    ;僕PAGE
      RET
;;;;;;;;;
COMMSENDVOL:
      MOV   COMMDATA1,#56H
      MOV   A,pt2257_2ch_vl_dz
      anl   a,#11110000B
      swap  a
      NOP
      orl   a,#30h
      MOV   COMMDATA2,A
      MOV   A,pt2257_2ch_vl_dz
      anl   a,#00001111B
      orl   a,#30h
      NOP
      MOV   COMMDATA3,A
      LCALL send_ZT       ;僕VOL
      lcall DLA2MS
      RET
COMMSENDSOURCE:
      MOV   COMMDATA1,#53H
      MOV   COMMDATA2,#30H
      MOV   A,LINE_DA
      ORL   A,#30H
      MOV   COMMDATA3,A
      LCALL send_ZT       ;僕SOURCE
      lcall DLA2MS
      RET
;;;;;;;;;
send_cpu_id:
    lcall DLA1MS
    LCALL COMMSENDSOURCE
    lcall DLA1MS
    lcall DLA1MS
    LCALL COMMSENDVOL
    lcall DLA1MS
    lcall DLA1MS
    lcall DLA1MS
    CLR   B_V_L
    LCALL COMMSENDBVL
    lcall DLA1MS
    LCALL COMMSENDSW1
    lcall DLA1MS
    lcall DLA1MS
    LCALL COMMSENDSW2
    lcall DLA1MS
    LCALL COMMSENDSW3
    ;lcall DLA1MS
    ;LCALL COMMSENDPRI
    lcall DLA1MS
    LCALL COMMSENDPAGE
    lcall DLA1MS
    LCALL COMMSENDMUTE
    lcall DLA1MS
    lcall DLA1MS
    lcall DLA1MS
    lcall DLA1MS
    lcall DLA1MS
    lcall DLA1MS
    LCALL COMMSENDPOWER
    lcall DLA1MS
    RET
;;;;;;;;;
send_cpu_idDF:
    LCALL COMMSENDSOURCE
    lcall DLA1MS
    lcall DLA1MS
    LCALL COMMSENDVOL
    lcall DLA1MS
    lcall DLA1MS
    CLR   B_V_L
    LCALL COMMSENDBVL
    lcall DLA1MS
    LCALL COMMSENDMUTE
    lcall DLA1MS
    lcall DLA1MS
    LCALL COMMSENDPOWER
    lcall DLA1MS
    RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
