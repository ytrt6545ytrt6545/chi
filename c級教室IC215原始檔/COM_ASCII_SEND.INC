;=========================
send_ZT:
   push  a
   clr   ren             ; jin zhi shou
   clr   es              ; jin zhi zhong duan
   SETB  RT_485
   MOV   A,COM_ID        ;;WRITE DATA
   mov   sbuf,a          ;;;;;; 1
ZTdeng:
   jbc   ti,ZT20_1       ;;send over , clr ti
   LJMP  ZTdeng
ZT20_1:                  ;;;;;; 2
   MOV   A,#20H
   mov   sbuf,A
ZTdeng0:
   jbc   ti,ZT20_2
   Ljmp  ZTdeng0
ZT20_2:
   MOV   A,COMMDATA1
   mov   sbuf,A          ;;;;;; 3
ZTdeng1:
   jbc   ti,ZT20_3
   Ljmp  ZTdeng1
ZT20_3:
   mov   a,COMMDATA2
   mov   sbuf,A          ;;;;;; 5
ZTdeng3:
   jbc   ti,ZT20_5
   Ljmp  ZTdeng3
ZT20_5:
   mov   a,COMMDATA3
   mov   sbuf,A          ;;;;;; 7
ZTdeng5:
   jbc   ti,SEND_ZTOUT
   ljmp  ZTdeng5
SEND_ZTOUT:
   CLR   RT_485
   setb  ren
   setb  es
   pop   a
   MOV   RT_DATA,#0FFH
   lcall DLA2MS
   JNB   B_ALL_DF,send_ZTDF
   SETB  B_COM
   CLR   B_ALL_DF
   MOV   COMMSADA,#0CH
send_ZTDF:
   retI
;=========================
;=========================
send_ALLZT:
   push  a
   clr   ren   ; jin zhi shou
   clr   es    ; jin zhi zhong duan
   SETB  RT_485
   mov   a,#0efh        ;;WRITE DATA
   mov   sbuf,a          ;;;;;; 1
ZTALLdeng:
   jbc   ti,ZTALL20_1    ;;send over , clr ti
   LJMP  ZTALLdeng
ZTALL20_1:
   MOV   A,#20H
   mov   sbuf,A
ZTALLdeng0:
   jbc   ti,ZTALL20_2
   Ljmp  ZTALLdeng0
ZTALL20_2:
   MOV   A,COMMDATA1
   mov   sbuf,A          ;;;;;; 3
ZTALLdeng1:
   jbc   ti,ZTALL20_3
   Ljmp  ZTALLdeng1
ZTALL20_3:
   mov   a,COMMDATA2
   mov   sbuf,A
ZTALLdeng3:
   jbc   ti,ZTALL20_5
   Ljmp  ZTALLdeng3
ZTALL20_5:
   mov   a,COMMDATA3
   mov   sbuf,A          ;;;;;; 7
ZTALLdeng5:
   jbc   ti,SEND_ZTALLOUT
   ljmp  ZTALLdeng5
SEND_ZTALLOUT:
   CLR   RT_485
   setb  ren
   setb  es
   pop   a
   MOV   RT_DATA,#0FFH
   lcall DLA2MS
   JNB   B_ALL_DF,send_ALLZTDF
   SETB  B_COM
   CLR   B_ALL_DF
   MOV   COMMSADA,#0CH
send_ALLZTDF:
   retI
;=========================
