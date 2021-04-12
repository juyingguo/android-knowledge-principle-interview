#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>



//内存分配，malloc calloc,realloc
void  test()
{
	int *p = (int *)malloc(sizeof(int)* 10);//指针除了地址，类型，
	printf("%p\n", p);//打印地址

	int num = 0;
	for (int *px = p; px < p + 10; px++)
	{


		*px = num;//对内容赋值

		printf("%p,%d\n", px, *px);//打印地址还有数据
		num++;

	}



}

void mainA()
{

	test();
	test();


	system("pause");








}

void mainB()
{

	unsigned  long long ll = 1024 * 1024 * 1024;//ll   2^64-1  鲸吞
	ll *= 1;
	void *p = malloc(1024 * 1024);
	if (p == NULL)
	{
		printf("内存分配失败\n");
	}
	else
	{
		printf("成功\n");
	}


	system("pause");
}

void   main()
{
	while (1)
	{
		//内存一定要及时释放
		void *p = malloc(100*1024*1024);//p, 栈    *(p+3)地址指向的内容
		if (p == NULL)
        {
            printf("内存分配失败\n");
        }
        else
        {
            printf("成功\n");
        }
		Sleep(100);
//		free(p);//释放内存
//		Sleep(3000);

	}


}
