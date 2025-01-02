;=============================
DLA04MS:
          PUSH  DLA1
          PUSH  DLA2
          PUSH  DLA12
          MOV   DLA2,#012H    ;12h
          MOV   DLA12,#0aH    ;0ah
DLA_ON_1: MOV   DLA1,DLA12
          DJNZ  DLA1,$
          DJNZ  DLA2,DLA_ON_1
          POP   DLA12
          POP   DLA2
          POP   DLA1
          RET
;======================
DLA1MS:                    ;1ah,  1595uS
PUSH DLA1
PUSH DLA2
PUSH DLA12
          MOV   DLA2,#07fH
          MOV   DLA12,#07fH
DLA_ON_1ms: MOV   DLA1,DLA12
          DJNZ  DLA1,$

          DJNZ  DLA2,DLA_ON_1ms
POP DLA12
POP DLA2
POP DLA1
RET
;================================
DLA2MS:                    ;1ah,  1595uS
PUSH DLA1
PUSH DLA2
PUSH DLA12
          MOV   DLA2,#01AH
          MOV   DLA12,#01AH
DLA_ON_2: MOV   DLA1,DLA12
          DJNZ  DLA1,$
          ;LCALL DISPLAY
          DJNZ  DLA2,DLA_ON_2
POP DLA12
POP DLA2
POP DLA1
RET
;===============================
DLAXMS:
MOV DLA2,DLA12
DXLOOP2:
MOV DLA1,DLA12
DXLOOP:
DJNZ DLA1,DXLOOP
DJNZ DLA2,DXLOOP2
;DJNZ DLA12,DLAXMS
RET
DLA2S:
PUSH DLA1
PUSH DLA2
PUSH DLA12
MOV  DLA12,#088H
MOV  DLA2,#068H
CALL DLAXMS
POP  DLA12
POP  DLA2
POP  DLA1
RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DELAY_40MS:
     MOV    R2,#68H
DELAY_40MS_1:
     MOV    R5,#48H
     DJNZ   R5,$
     LCALL  DISPLAY
     DJNZ   R2,DELAY_40MS_1
     NOP
     RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;=============================
DLA04MSXD:
          PUSH  DLA1
          PUSH  DLA2
          PUSH  DLA12
          MOV   DLA2,#02H    ;12h
          MOV   DLA12,#0aH    ;0ah
DLA_ON_1XD:
          MOV   DLA1,DLA12
          DJNZ  DLA1,$
          DJNZ  DLA2,DLA_ON_1XD
          POP   DLA12
          POP   DLA2
          POP   DLA1
          RET
;=============================
;=============================
DLA2MSXD:                    ;1ah,  9997uS
          MOV   R2,#01AH
DLA_ON_2XD:
          MOV   R5,#01AH
          DJNZ  R5,$
          LCALL DISPLAY
          DJNZ  R2,DLA_ON_2XD
          ANL   P0,#11100001B
          ORL   P0,#11100000B
          MOV   P2,#0FFH
          ANL   P0,#00011111B
          RET
;=============================
