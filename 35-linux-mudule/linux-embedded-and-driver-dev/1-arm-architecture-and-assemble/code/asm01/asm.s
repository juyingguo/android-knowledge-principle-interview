	AREA asm1test,CODE,READONLY
	;ENTRY
	
AAA
	MOV R0, #0X3
	BIC R0,R0,#0X1
	MOV R1, R0
	MOV R2, #0X2
	
	ADD R3,R1,R2	;R1+R2=>R3
	CMP R3,R1		;R3-R1,修改CPSR标志位
	SUB R4,R3,R1  	;R3-R1=>R4
	SUBS R0,R0,R0
	
	
	MVN R5,#0X0
	MOV R6,#0X9000
	STR R5,[R6]
	LDR R7,[R6]
	
	STR R5,[R6,#0X4]
	LDR R7,[R6]
	
	MRS R0,CPSR
	BIC R0,R0,#0XF	;把R0里最低4位清0，结果给R0
	MSR CPSR_cxsf, R0
	
BBB	
	ORR R6,R1,R2	;R1&R2=>R6
	AND R3,R1,R2	;R1&R2=>R3
	
	BL 	BBB			;.表示当前指令地址
	
	
	MVN R5,#0X0
	MOV R6,#0X9000
	
	END
	
	