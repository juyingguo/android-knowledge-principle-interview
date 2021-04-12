#include "iostream"
#include"stdlib.h"


namespace myspace
{
	int a (15);

	void  print()
	{
		std::cout << "锄禾日当午"<<std::endl;
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
	//std::cout输出， <<输出符，根据类型泛型转换为字符串输出
	//std::endl;//换行，结束一个输出，
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