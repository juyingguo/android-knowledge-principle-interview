#include<stdio.h>
#include<stdlib.h>

void main()
{

	void *p1 = malloc(10); //p1,p2栈上
	void *p2 = malloc(20);
	printf("%p,%p", &p1, &p2);//地址在栈上
	printf("\n%p,%p", p1, p2);//堆区

	getchar();



}