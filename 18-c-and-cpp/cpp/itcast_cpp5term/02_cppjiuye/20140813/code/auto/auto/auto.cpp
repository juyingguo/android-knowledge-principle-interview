#include<iostream>
#include<stdlib.h>
//�Զ��������Զ���ȡ���ͣ����������
//�Զ�����������ʵ���Զ�ѭ��һά����
//�Զ�ѭ����ʱ�򣬶�Ӧ�ı����ǳ���



void main1()
{
	auto num = 10.9;//�Զ��������Զ�ƥ������
	auto numA = 10/3.0;
	std::cout << num <<"     " << numA << std::endl;
	system("pause");


}

void main()
{
	//int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double num[2][5] = { 1.0, 2.0, 3.0, 4.5, 5, 6, 7, 8, 9, 10 };
	//num��������һ��ָ�볣��
	//auto �Զ�ѭ�� begin  endl;��������һ������ĳ���
	//
	for (auto data : num)//����C++�﷨,ѭ��һά����,����
	{
		std::cout << data<<std::endl;
		
		for (int i = 0; i < 5; i++)
		{
			std::cout << *(data + i) << std::endl;
		}
	}
	system("pause");


}