#include "iostream"
#include"stdlib.h"


namespace myspace
{
	int a (15);

	void  print()
	{
		std::cout << "�����յ���"<<std::endl;
	}
}

namespace myspaceA
{
	int a(25);
	void  print()
	{
		std::cout << "AAAAAAAAAA" << std::endl;
	}
}

void main1()
{
	int a (5);
	//std::cout����� <<��������������ͷ���ת��Ϊ�ַ������
	//std::endl;//���У�����һ�������
	std::cout << "myspace a=" << myspace::a << std::endl;
	std::cout << "myspaceA a=" << myspaceA::a << std::endl;
	std::cout << "  main a=" << a << std::endl;
	std::cout << "hello world" << std::endl;
	system("pause");

}

void main2()
{
	myspace::print();
	myspaceA::print();

	system("pause");
}