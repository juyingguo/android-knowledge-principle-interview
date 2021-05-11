	AREA HADNLER,CODE,READONLY
	IMPORT do_swi
	EXPORT swi_handler
swi_handler
	;1.保存处理器现场,把寄存器保存到栈上
	; STR R0,[R1];把R0寄存器的值保存在R1寄存器的地址上。
	STMFD R13!,{R0-R12, R14};将R0到R12，及R14一并保存到R13所代表的的地址上，R13代表栈指针寄存器。!代表更新，R13！指向更新后的栈指针首地址。
	
	SUB R14,R14,#4			;R14里保存的是swi 0x123指令，4个字节，中断号在低24位
	LDR R0,[R14]
	BIC R0,R0,#0XFF000000
	;2.调用中断处理程序
	BL do_swi
	
	;3.恢复处理器现场,^把当前模式下的SPSR恢复给CPSR
	;恢复的时候，将R14直接给R15，即直接跳转到该返回地址上。
	LDMFD R13!,{R0-R12, R15}^
	
	END
	