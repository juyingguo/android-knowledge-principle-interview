	AREA asmtest02,CODE,READONLY
	ENTRY
	
AAA
	MOV R0, #0X3
	BIC R0,R0,#0X1
	MOV R1, R0
	ORR R3,R0,#0X7
	
	B .
	
	END
	
	