#include <iostream>

namespace runrunrunrun
{

	int a(10);
	char *str("gogogo");
	namespace run   //命名空间的嵌套
	{
		int a(9);
	}
}
namespace runrunrunrun  //命名空间的拓展
{
	int  y(5);
	//int  a(15);重定义错误
}
namespace r = runrunrunrun;//给命名空间起一个别名


void main132()
{
	std::cout << r::run::a << std::endl;//命名空间可以嵌套
	std::cout << r::y << std::endl;
	std::cout << r::a << std::endl;
}

//using namespace r;
void main11()
{
	//std::cout << r::a <<r::str<< std::endl;
	//std::cout << a << str << std::endl;

}