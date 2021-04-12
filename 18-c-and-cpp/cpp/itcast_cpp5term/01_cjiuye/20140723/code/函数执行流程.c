#include<stdio.h>
#include<stdlib.h>
void print2()
{
	printf("\nshang2");

	printf("\nxia2");
}

void print1()
{
	printf("\nshang1");
	print2();
	printf("\nxia1");
}

/**
函数调用过程，从下至上一次压入栈中，然后执行从栈中取出依次执行
*/
void main()
{
	print1();
	printf("\n1");
	printf("\n2");

	getchar();


}
