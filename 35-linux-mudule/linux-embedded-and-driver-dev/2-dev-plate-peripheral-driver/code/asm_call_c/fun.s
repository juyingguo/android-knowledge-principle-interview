	AREA FUN ,CODE, READONLY
	IMPORT add
	EXPORT fun
fun
	add r0, r0, #1
	add r1, r1, #1
	
	mov r8, r14
	bl add
	mov r5, r0
	mov r14, r8
	mov pc, r14
	
	end
	