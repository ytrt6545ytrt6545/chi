;=======CPU PIN =========
Q1 EQU P2.0
Q2 EQU P2.1
Q3 EQU P2.2
Q4 EQU P2.3
Q5 EQU P2.4
Q6 EQU P2.5
Q7 EQU P2.6
Q8 EQU P2.7          ; D28=XIAOSHUDIAN = DAI TI VOICE LED
LED_YD1 EQU P2.0
LED_YD2 EQU P2.1
LED_YD3 EQU P2.2
LED_YD4 EQU P2.3
LED_YD5 EQU P2.4
LED_YD6 EQU P2.5
LED_YD7 EQU P2.6
LED_YD8 EQU P2.7

P_ON EQU P0.0        ;B=1=ON
;YS2 EQU P0.1
SC2 EQU P0.1         ;
SC1 EQU P0.2         ; SHU MA GUAN
SC3 EQU P0.3         ;
SC4 EQU P0.4         ;//LED KONGZHI, SC4=1 LED KE YI LIANG
KEY1 EQU P0.5        ;key hang
KEY2 EQU P0.6        ;key hang
KEY3 EQU P0.7        ;key hang

AA EQU P1.0          ;; 4051-A ;;
BB EQU P1.1              ;
CC EQU P1.2          ;;;;;;;;;;;;
pt2257_sda equ p1.3
pt2257_scl equ p1.4
;V_OUT EQU P1.4      ;;;;;;;;;;;;;;;;;;;;;
V_IN   EQU P1.5
;KNBO_D1 EQU P1.6    ;;vole1 zhi shi deng
RT_485 EQU P1.7      ;;vole2 zhi shi deng
SA_SDA EQU P1.6
SA_SCL EQU P1.5

INT_D EQU P3.2
MUTE  EQU P3.3
;VOL1_U EQU P3.4     ;;vole1 up kong zhi
;VOL1_D EQU P3.5     ;;vole1 d  kong zhi
;VOL2_U EQU P3.6     ;;vole2 up kong zhi
;VOL2_D EQU P3.7     ;;vole2 d  kong zhi
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMMDATA1      EQU  18H      ; 69H
COMMDATA2      EQU  19H      ; 6AH
COMMDATA3      EQU  1AH      ; 6BH
COMMLOAD2      EQU  1BH      ; 6CH
COMMLOAD3      EQU  1CH      ; 6CH
COMMLOAD4      EQU  1DH      ; 6CH
         ;      EQU  1EH     ; USED   ASCII TO HEX
TIMER1         EQU  1FH     ; USED
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;======BIT =20H============
B_YK_DA EQU 00H
B_YK_TRU EQU 01H
B_K_TRU EQU 02H      ;;YOU KEY AN XIA  ==1  PAN DUAN SHI FOU ZHI XING KCOM
B_KK  EQU 03H        ;; KEY SHI FOU SONG KAI  B=1,MEI SONG
B_V_D EQU 04H        ;;VOICE LED ZHUANG TAI
MANA  EQU 05H
B_YD_2  EQU 06H      ;;YIN DIAO BIAN HUA LIANG CI
B_YKLX EQU 07H       ;;YAO KONG LIAN XU MA
;=========BIT=21H===========
B_SW1 EQU 08H
B_SW2 EQU 09H
B_SW3 EQU 0AH
B_MU EQU 0BH         ; 21.3  ;;B=1=MUTE
B_RT_LED EQU 0CH
B_IR_LED EQU 0DH
B_PAGE_LED EQU 0EH
B_POWER_LED EQU 0FH
;========BIT=22H==========
B_V_L   EQU 22H.0      ; =1 => LINE  TONG BU
B_P     EQU 22H.1      ; =1 =>POWER  TONG BU
B_PAGE  EQU 22H.2
MANA2   EQU 22H.3
SW1_FLG EQU 22H.4
B_POWER EQU 22H.5
B_PRI   EQU 22H.6
;========BIT=23H========== ;COM 用
   B_COMM1      BIT  18H
   B_COMM2      BIT  19H
   B_COMM3      BIT  1AH
   B_COMM4      BIT  1BH
   B_COMM5      BIT  1CH
   B_COMM6      BIT  1DH
   B_COMM7      BIT  1EH
   B_COMM8      BIT  1FH
;==========BIT=24H======
POWER_DATA  EQU 24H
B_POWER_CPL EQU 24H.4
;========== BIT=25H=====
RT_DATA   EQU 25H
B_RT_CPL  EQU 25H.4
;===========BIT=26H=====
IR_DATA   EQU 26H
B_IR_CPL  EQU 26H.4
;=======bit=27H=========
YS2MXSJS  EQU 027H    ; KAI JI YAN SHI LIANG MIAO XIAN SHI CI CHU
;========BIT 28H========
COMM_b      BIT 40H
COMM_b1     BIT 41H
B_COM       BIT 42H
B_COM_PRI   BIT 43H
B_COM_PAGE  BIT 44H
B_COMM_P1   BIT 45H
B_COMM_P2   BIT 46H
B_COMM_XP   BIT 47H
;========BIT 29H========
COMMSADA     EQU 29H
;========BIT 2AH========
ADDRESS_ID   EQU 2AH
;========BIT 2BH========
COM_ID       EQU 2BH
;========BIT 2DH========
sbuf_id      EQU 2DH
;========BIT 2EH========
B_COMM_PAGE  EQU 70H
B_COMM_PRI   EQU 71H
B_COMM_PAGEA EQU 72H
B_ALL_DF     EQU 73H
;========BIT 2FH========

;;=========BYT==========
DLA1  EQU 30H
DLA2  EQU 31H
DLA12 EQU 32H
YKDA1 EQU 33H
YKDA2 EQU 34H
YKDA3 EQU 35H
YKDA4 EQU 36H
;YKLXJS EQU 14H
YKTR1 EQU 15H     ;;  YAO KONG SHI XIAO SHI JIAN DIZHI
YKDAD EQU 16H     ;; YAO KONG SHU JU GE SHU, GONG 4 GE
KEYDA EQU 37H     ;;KEY DATA DI ZHI
NUM EQU 38H       ;
DIS2 EQU 39H
DIS1 EQU 3AH      ;^^^^^^^^
V1DA EQU 3BH      ; CHU SHI 40
DIS3 EQU 3CH      ;-----------
KJS  EQU 3DH      ;;;;key lian an ji shu
LINE_DA EQU 3EH   ;LINE DA  CHU SHI WEI 1
SA_ADD EQU 3FH    ;
SA_DATA EQU 40H   ;
pt2257_MUTE_DZ   equ  41h
pt2257_2ch_vl_dz equ 42h
SBUF_P  EQU 43H    ;ZHI XIANG SHU JU DI ZHI
;SBUF_ID EQU 44H    ;
SBUF1   EQU 45H
SBUF2   EQU 46H
SBUF3   EQU 47H
TMP_A   EQU 48H
TMP_PSW EQU 49H
;;======################################
;;;;;;;;;;;;;;;;;;;;
;YKLXJS11   EQU  5     ;;# YAO KONG LIAN XU 8 CI HOU YOU XIAO SHI JIAN
YKTR11     EQU  03H    ;;# YAO KONG SHI XIAO SHI JIAN  ##
KJS_1      EQU  030H   ;;KEY LIAN XU ZHI QIAN
KJS_2      EQU  045H   ;;KEY LIAN XU SU DU
;;;;;
;SA_LO_ADD  EQU  00H   ;;
SA_V1_ADD  EQU  10H    ;;
SA_sw_ADD  EQU  12H    ;;
SA_LI_ADD  EQU  14H    ;;
;V_D_JS_K   EQU  0DH    ;;VOICE KUAI SHAN SU DU
;V_D_JS_M   EQU  030H   ;VOICE MAN SHAN SU DU
;YD_DACS    EQU  09H    ;yin DIAO CHU SHI +-5=5  +-9=9
;;;;;;;;;;;;;;;COM KOU DATA;;;;;;;;;;;;;;;;;;;;;;
;;=#########################
   FX_SBUF1       EQU  50H
   FX_SBUF2       EQU  51H
   FX_SBUF3       EQU  52H
   FX_SBUF4       EQU  53H

   ;50H~6FH 以用于串口接收码
;;=#########################
SPXX       EQU  72H      ; 60h
