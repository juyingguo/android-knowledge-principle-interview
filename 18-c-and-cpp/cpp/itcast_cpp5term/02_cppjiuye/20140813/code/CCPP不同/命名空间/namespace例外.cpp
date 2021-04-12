#include"iostream"

//没有命名的命名空间可以直接调用
namespace
{
	int a(3);
	void print()
	{
		std::cout << "gogogo";
	}
}

void main()
{

	std::cout << a;
	print();
	getchar();
}