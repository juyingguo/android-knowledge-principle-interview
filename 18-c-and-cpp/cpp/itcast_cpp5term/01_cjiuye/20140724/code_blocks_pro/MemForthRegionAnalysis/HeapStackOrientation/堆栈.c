#include<stdio.h>
#include<stdlib.h>

void main()
{

	void *p1 = malloc(10); //p1,p2ջ��
	void *p2 = malloc(20);
	printf("%p,%p", &p1, &p2);//��ַ��ջ��
	printf("\n%p,%p", p1, p2);//����

	getchar();



}