#include <stdio.h>
int main(void)
{

	__asm 
	{
		mrs r5, CPSR
		bic r5, r5, #0xf
		orr r5, r5, #0x2
		msr CPSR_cxsf, r5
	}
	printf("hello\n");
	return 0;
}
