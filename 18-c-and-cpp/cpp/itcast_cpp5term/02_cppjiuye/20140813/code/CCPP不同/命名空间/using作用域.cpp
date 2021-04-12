#include<iostream>
#include<stdlib.h>
namespace mydata
{
	int a(6);
}
namespace yourdata
{
	int a(10);
}
using namespace mydata;//using必须在命名空间的后面，作用域
using namespace yourdata;
//using如果变量重名，会出现不明确错误，加上命名空间修饰符
void go()
{

	//命名空间如果在块语句内容，作用域是定义开始到块语句结束
	//std::cout << mydata::a << std::endl;

}


//using namespace mydata;//作用域为从代码开始到结束
void main02()
{
	//std::cout << mydata::a << std::endl;
	std::cout <<yourdata::a << std::endl;



	system("pause");
}