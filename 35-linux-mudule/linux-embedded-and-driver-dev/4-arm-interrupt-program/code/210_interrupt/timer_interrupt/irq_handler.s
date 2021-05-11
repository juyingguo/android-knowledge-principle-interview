.globl irq_handler
.globl cpsr_I_clear
cpsr_I_clear:
	STMFD R13!,{R0}
	MRS R0,CPSR
	BIC R0,R0,#0X80;
	MSR CPSR_c,R0
	LDMFD R13!,{R0}
	MOV PC,LR
	
irq_handler:
	SUB R14,R14,#0X4  	@调整IRQ返回地址
	LDR R13,=0X28000000
	STMFD R13!,{R0-R12,R14}

	BL do_irq

	LDMFD R13!,{R0-R12,R15}^
