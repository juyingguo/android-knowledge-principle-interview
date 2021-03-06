#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<Windows.h>

int  flag = 0;//意味着没有找到
int  * addrfind = NULL;//地址
struct MyStruct
{
	int *pfindstart;//要查找的首地址
	int  length;//限定长度，从地址开始
	int  num;//要查找的数据
	int  bh;//编号
	int  *pflag;//传递flag的地址，修改flag,访问
	int **addr;//传递一个指针的地址，
};



void find(void *p)
{
	struct MyStruct *pstruct = (struct MyStruct *)p;//指针类型转换
	//内存的遍历，从地址开始累加100个元素的大小，遍历所有元素
	for (int *px = pstruct->pfindstart; px < pstruct->pfindstart + 100; px++)
	{
		Sleep(100);
		if (*(pstruct->pflag) != 0)
		{
			printf("属下%d无能，其他线程已经找到 \n", pstruct->bh);
			return;
		}

		if (*px == pstruct->num)//判断是否相等
		{
			printf("\n第%d个线程找到%p,%d \n",pstruct->bh, px,*px);//查找
			*(pstruct->pflag) = 1;//改变标识，代表找到
			*(pstruct->addr) = px;
			return;
		}

	}
	printf("\n没有找到第%d个线程\n", pstruct->bh);

	return;


}

void main()
{
	int a[1000];//783;数组
	for (int i = 0; i < 1000; i++)
	{
		a[i] = i;//数组初始化
	}
	struct MyStruct threaddata[10];//创建结构体,处理不同的线程，
	for (int i = 0; i < 10; i++)//创建10个线程并行查找
	{
		//a , a+100 a+200               a+900


		threaddata[i].pfindstart  = a + i * 100;//计算数组的地址
		threaddata[i].length = 100;//长度
		threaddata[i].bh = i;//编号
		threaddata[i].num = 783;//要查找的数据
		threaddata[i].pflag = &flag;//标识
		threaddata[i].addr = &addrfind;//存储了变量的地址


		printf("\n%d\n", threaddata[i].bh);
		_beginthread(find, 0, &threaddata[i]);//

		//Sleep(30);///
	}



	Sleep(30000);


	system("pause");
	printf("\n\n%d,%p\n\n", *addrfind, addrfind);//打印地址，还有数据
	system("pause");
}
