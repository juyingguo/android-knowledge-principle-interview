
#include<iostream>//C++û��.h��������C/C++
//C/C++ͷ�ļ�  ��û�������ռ�
#include<stdlib.h>
//int a = 1;
extern  int a;//C++Ҫ���ϸ�
void main()
{
	int a = 3;
	std::cout << ::a;

	system("pause");
}