;;;;;;;;;;;;;;;;;;;;;;;;
COM_ASCII:
  PUSH   A
  PUSH   PSW
  JB     ti,commnot
  JNB    COMM_b,commra
  LJMP   commrd
;;;;;;;;;;;;;;;;;;;;;;;;
commra:  ;read addrss
  MOV    a,sbuf
  MOV    sbuf_id,a
  CJNE   A,#0EFH,commnot1
  LJMP   COMMYES
commnot1:
;  ANL    a,#10000000b
;  CJNE   a,#80h,commnot
;  MOV    A,sbuf_id
;  ANL    A,#01111111B
;  cjne   a,ADDRESS_ID,commnot
  JNB    ACC.7,commnot
  ANL    A,#01111111B
  nop
  cjne   a,ADDRESS_ID,commnot
COMMYES:
  MOV    SBUF_P,#4FH
  SETB   COMM_b
commnot:
  CLR    ti
  CLR    ri
  POP    PSW
  POP    A
  RETI
;;;;;;;;;;;;;;;;;;;;;;;;
;=======================
commrd:                 ;read data
  MOV    a,sbuf
  INC    SBUF_P
  MOV    r0,sbuf_p
  MOV    @r0,a
  nop
  MOV    a,r0
  CJNE   A,#FX_SBUF4,commnot
  nop
  JB     B_COMM1,commrd1_1
  MOV    55H,FX_SBUF2
  MOV    56H,FX_SBUF3
  MOV    57H,FX_SBUF4
  SETB   B_COMM1
  CLR    COMM_b
  MOV    IR_DATA,#0FFH
  LJMP   commnot
;========================
;========================
commrd1_1:
  JB     B_COMM2,commrd1_2
  MOV    59H,FX_SBUF2
  MOV    5AH,FX_SBUF3
  MOV    5BH,FX_SBUF4
  SETB   B_COMM2
  CLR    COMM_b
  MOV    IR_DATA,#0FFH
  LJMP   commnot
commrd1_2:
  JB     B_COMM3,commrd1_3
  MOV    5DH,FX_SBUF2
  MOV    5EH,FX_SBUF3
  MOV    5FH,FX_SBUF4
  SETB   B_COMM3
commrd1_3:
  CLR    COMM_b
  MOV    IR_DATA,#0FFH
  LJMP   commnot
;========================
