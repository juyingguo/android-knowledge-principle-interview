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
�������ù��̣���������һ��ѹ��ջ�У�Ȼ��ִ�д�ջ��ȡ������ִ��
*/
void main()
{
	print1();
	printf("\n1");
	printf("\n2");

	getchar();


}
