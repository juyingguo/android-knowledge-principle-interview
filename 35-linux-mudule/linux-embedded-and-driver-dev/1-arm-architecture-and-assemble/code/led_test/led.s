	AREA START,CODE,READONLY
	ENTRY
	CODE32
	
LED_TEST
	LDR R0,=0XE0200280			; r0=0xe0200280   ���ƼĴ���
	LDR R1,=0X1111				 	;4���������ģʽ
	STR R1,[R0]
	
	LDR R0,=0XE0200284			;�������ݼĴ��������õ͵�ƽ�ѵƵ���
	LDR R1,=0X0
	STR R1,[R0]
	
delay1
	MOV R4,#0XFFFFFFF
LOOP1
	SUBS R4, R4, #1
	BNE LOOP1
	
	LDR R0,=0XE0200284
	LDR R1,=0XF
	STR R1,[R0]
	

delay2
	MOV R4,#0XFFFFFFF
LOOP2
	SUBS R4, R4, #1
	BNE LOOP2
	
	B LED_TEST
	
	END