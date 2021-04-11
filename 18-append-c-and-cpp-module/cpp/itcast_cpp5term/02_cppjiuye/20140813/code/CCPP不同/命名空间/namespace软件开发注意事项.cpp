#include <iostream>

namespace runmove
{
	int  y(5);
	int(*padd)(int, int);//函数指针接口
//private: 命名空间是透明的
	int  y1(5);
	class myclass
	{
	public://类默认是私有，实现封装
		int a;
	};
}

int add(int a, int b)
{

	return a + b;
}
int addp(int a, int b)
{
	std::cout << a << b;
	return a + b;
}
struct MyStruct
{
	int b;//结构体默认是透明的
private:
	int a;//是私有
};

void main1123()
{
	//namespace所有数据，函数，类，对象都是共有
	MyStruct struct1;//结构体内部默认公有
	struct1.b;


}