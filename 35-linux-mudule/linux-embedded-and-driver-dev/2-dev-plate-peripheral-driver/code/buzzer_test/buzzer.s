	AREA START,CODE,READONLY
	ENTRY
	CODE32
	
BUZZER_TEST
BUZZER_INIT
	;����GPIO�ܽ�Ϊ���ģʽ��GPD0CON[0]
	LDR R0,=0XE02000A0			
	LDR R1,=0X1					;ʮ������0x1��Ӧ������0001				 	
	STR R1,[R0]
	
BUZZER_ON	
	;����GPD0DAT[0]Ϊ�ߵ�ƽ��buzzer����
	LDR R0,=0XE02000A4		
	LDR R1,=0X1
	STR R1,[R0]
	
	;ģ��sleep����ʱ
delay1
	MOV R4,#0XFFFFFFF
LOOP1
	SUBS R4, R4, #1
	BNE LOOP1
	
BUZZER_OFF	
	;����GPD0DAT[0]Ϊ�͵�ƽ��buzzerֹͣ����
	LDR R0,=0XE02000A4
	LDR R1,=0X0
	STR R1,[R0]
	

delay2
	MOV R4,#0XFFFFFFF
LOOP2
	SUBS R4, R4, #1
	BNE LOOP2
	
	B BUZZER_ON
	
	END