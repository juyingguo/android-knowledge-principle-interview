#include <iostream>

namespace runrunrunrun
{

	int a(10);
	char *str("gogogo");
	namespace run   //�����ռ��Ƕ��
	{
		int a(9);
	}
}
namespace runrunrunrun  //�����ռ����չ
{
	int  y(5);
	//int  a(15);�ض������
}
namespace r = runrunrunrun;//�������ռ���һ������


void main132()
{
	std::cout << r::run::a << std::endl;//�����ռ����Ƕ��
	std::cout << r::y << std::endl;
	std::cout << r::a << std::endl;
}

//using namespace r;
void main11()
{
	//std::cout << r::a <<r::str<< std::endl;
	//std::cout << a << str << std::endl;

}