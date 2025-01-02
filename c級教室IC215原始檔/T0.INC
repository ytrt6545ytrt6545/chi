TR0ZD: PUSH PSW
       PUSH A
       PUSH P2
       MOV P2,#00
       CLR TR0
       MOV A,YKTR1
       DEC A
       CLR CY
       SUBB A,#YKTR11
       JC YKBF
       JMP CA_DIS

YKBF:   DEC YKTR1
        XCH A,YKTR1  ;YAO KONG YOU XIAO
        CJNE A,#0,YK_YX
        XCH A,YKTR1
        CALL YK_CLR
        CLR RS0
        CLR RS1
        MOV YKTR1,#10H
CA_DIS: ;CALL DISPLAY
        SETB TR0
        POP P2
        POP A
        POP PSW
       RETI
YK_YX: XCH A,YKTR1
       JMP CA_DIS
;;;\\\\\\\\\\\\\\\\\\\\\\\\\\\
;;;\\\S_V_D:    ;SETUP VOICE LED
;;;\\\PUSH A
;;;\\\JB P_ON,S_V_D_SS
;;;\\\CLR LED_VOICE       ;GUAN BI LED_VOICE
;;;\\\JMP S_V_D_O
;;;\\\S_V_D_SS:
;;;\\\MOV A,VIC
;;;\\\CJNE A,#0,S_V_D_OFF
;;;\\\S_V_D_ON:
;;;\\\SETB LED_VOICE
;;;\\\JMP S_V_D_O
;;;\\\S_V_D_OFF:
;;;\\\MOV A,VIC
;;;\\\CJNE A,#1,S_V_D_AUTO
;;;\\\CLR LED_VOICE
;;;\\\JMP S_V_D_O
;;;\\\S_V_D_AUTO:
;;;\\\MOV C,V_IN
;;;\\\;MOV V_OUT,C
;;;\\\JNB V_IN,MANSHAN
;;;\\\MOV A,V_D_JS
;;;\\\CLR C
;;;\\\SUBB A,#V_D_JS_K
;;;\\\JC BUBIAN
;;;\\\MOV V_D_JS,#0
;;;\\\CPL B_V_D
;;;\\\BUBIAN: MOV C,B_V_D
;;;\\\        MOV LED_VOICE,C
;;;\\\        JMP S_V_D_O
;;;\\\MANSHAN:
;;;\\\MOV A,V_D_JS
;;;\\\CLR C
;;;\\\SUBB A,#V_D_JS_M
;;;\\\JC BUBIAN
;;;\\\MOV V_D_JS,#0
;;;\\\CPL B_V_D
;;;\\\JMP BUBIAN
;;;\\\S_V_D_O:
;;;\\\POP A
;;;\\\RET
DISPLAY:
         MOV   P2,#00
         ORL   P0,#11100000B
         ANL   P0,#11100001B
         JNB   P_ON,NOSC4
         NOP
         LCALL SET_LI_LED
         SETB  SC1
NOSC4:   LCALL DLA04MSXD
         CLR   SC1
         MOV   P2,21H
         SETB  SC2
         LCALL DLA04MSXD
         CLR   SC2
         JNB   B_MU,DIS_NO_MU
         MOV   P2,#40H
         ORL   P0,#00011000B
         LCALL DLA04MSXD
         RET
DIS_NO_MU:
         MOV   P2,DIS1
         SETB  SC4
         LCALL DLA04MSXD
         CLR   SC4
         mov   p2,dis2
         SETB  SC3
         LCALL DLA04MSXD
         CLR SC3
         RET
SET_LI_LED:
           PUSH  A
           MOV   A,LINE_DA
           CJNE  A,#1,SET_LI_LED_1
           SETB  LED_YD1
           LJMP  SET_LIRR
SET_LI_LED_1:
           CJNE  A,#2,SET_LI_LED_2
           SETB  LED_YD2
           LJMP  SET_LIRR
SET_LI_LED_2:
           CJNE  A,#3,SET_LI_LED_3
           SETB  LED_YD3
           LJMP  SET_LIRR
SET_LI_LED_3:
           CJNE  A,#4,SET_LI_LED_4
           SETB  LED_YD4
           LJMP  SET_LIRR
SET_LI_LED_4:
           CJNE  A,#5,SET_LI_LED_5
           SETB  LED_YD5
           LJMP  SET_LIRR
SET_LI_LED_5:
           CJNE  A,#6,SET_LI_LED_6
           SETB  LED_YD6
           LJMP  SET_LIRR
SET_LI_LED_6:
           CJNE  A,#7,SET_LI_LED_7
           SETB  LED_YD7
           LJMP  SET_LIRR
SET_LI_LED_7:
           CJNE  A,#8,SET_LIRR
           SETB  LED_YD8
SET_LIRR:
           POP   A
           RET

;======================================================

SET_YD_LED:
           PUSH A
;           MOV A,YD_DA
           CJNE A,#0,SET_YD_LED_1
;           SETB LED_YDF
           SETB LED_YD5
           JMP SET_YDRR
SET_YD_LED_1:
             CJNE A,#1,SET_YD_LED_2
;             SETB LED_YDF
             SETB LED_YD4
             JMP SET_YDRR
SET_YD_LED_2:
             CJNE A,#2,SET_YD_LED_3
;             SETB LED_YDF
             SETB LED_YD3
             JMP SET_YDRR
SET_YD_LED_3:
             CJNE A,#3,SET_YD_LED_4
;;             SETB LED_YDF
             SETB LED_YD2
             JMP SET_YDRR
SET_YD_LED_4:
             CJNE A,#4,SET_YD_LED_5
;             SETB LED_YDF
             SETB LED_YD1
             JMP SET_YDRR
SET_YD_LED_5:
             CJNE A,#5,SET_YD_LED_6
             JMP SET_YDRR

SET_YD_LED_6:
             CJNE A,#6,SET_YD_LED_7
             ;SETB LED_YDF
             SETB LED_YD1
             JMP SET_YDRR
SET_YD_LED_7:
             CJNE A,#7,SET_YD_LED_8
             ;SETB LED_YDF
             SETB LED_YD2
             JMP SET_YDRR
SET_YD_LED_8:
             CJNE A,#8,SET_YD_LED_9
             ;SETB LED_YDF
             SETB LED_YD3
             JMP SET_YDRR
SET_YD_LED_9:
             CJNE A,#9,SET_YD_LED_10
             ;SETB LED_YDF
             SETB LED_YD4
             JMP SET_YDRR
SET_YD_LED_10:
             ;CJNE A,#9,SET_YD_LED_2
             ;SETB LED_YDF
             SETB LED_YD5
             ;JMP SET_YDRR
SET_YDRR:
           POP A
RET
