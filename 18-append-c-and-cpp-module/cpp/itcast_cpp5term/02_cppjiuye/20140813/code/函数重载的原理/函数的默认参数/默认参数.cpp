#include<stdio.h>
#include<stdlib.h>
#include<iostream>


//Ĭ�ϲ�����������ұ�
//Ĭ�ϲ����м䲻������ֲ�Ĭ�ϵ�

void print(int c,int a = 1, int d=2, int b = 3)
{
	std::cout << a<<b<<c << std::endl;

}

void print(double c)
{

}



void main()
{
	//print(1,2,3);
	//����ָ��û��Ĭ�ϲ���������ȫ����������
	//���������뺯��Ĭ�ϲ�����ͻ,��Ҫ������Ĳ������Ͳ�һ����������һ����˳��һ������������⣬����һ������
	void(*pt1)(int c, int a , int d , int b ) = print;
	pt1(100,1,2,3);//����ָ����ã�û����Ĭ�ϵ�

	print(100);


	system("pause");
}