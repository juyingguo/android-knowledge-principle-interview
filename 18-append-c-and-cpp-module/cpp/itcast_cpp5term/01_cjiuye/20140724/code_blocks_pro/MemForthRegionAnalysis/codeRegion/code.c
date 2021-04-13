#include<stdio.h>
#include<stdlib.h>


void gogogo()
{

	printf("AAAAA\n\n\n\n");
}

void main()
{
	printf("%p", gogogo);//函数名存放函数的地址
	//gogogo = gogogo;代码区只能读不可写
	//void gogogo()；
	//void ()();
//	gogogo();//直接调用

//	void(*p)()=gogogo;
//	p();//间接调用


	getchar();

}


void    main2()
{
	char *p = "ABCDEFG";//p存储常量字符串的地址
	printf("%d,%d\n", sizeof(p), sizeof("ABCDEFG"));
	printf("\n%p", &p);//查看指针变量的地址
	printf("\n%p", p);//查看字符串的地址
	*p = 'a';//代码区只能读，常量字符串在代码区


	getchar();






}
