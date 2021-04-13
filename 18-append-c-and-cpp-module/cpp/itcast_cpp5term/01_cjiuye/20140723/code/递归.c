//#define _CRT_SECURE_NO_WARNINGS  //关闭安全监察

#include<stdio.h>
#include<stdlib.h>


double go(int n)
{
	if (n == 1)
	{
		return 1.0;  //终止
	}
	else if (n==2)
	{
		return 2.0;
	}
	else
	{
		return go(n - 1) + go(n - 2);//找出关系
	}



}

void main3()
{
	//printf("%f", go(50));

	double a[50];
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < 50; i++) //数组加循环，实现递归
	{
		a[i] = a[i - 1] + a[i - 2];
		printf("%f\n", a[i]);
	}
	system("pause");
}



/**
判断一个数组的元素是否递增的。非递归实现。
*/
void main6()
{
	int a[10] = { 1, 4, 3, 4, 5, 6, 7, 8, 9, 10 };
	int flag = 1;//假定是递增
	for (int i = 0; i < 10 - 1; i++)//0-9
	{
		if (a[i] > a[i + 1])//非递增
		{
			flag = 0;//非递增
			break;
		}
	}
	if (flag)
	{
		printf("递增 \n");
	}
	else
	{
		printf("fei递增 \n");
	}


	system("pause");





}

/**
判断一个数组的元素是否递增的。递归实现。
*/
int  a[10] = { 1, 2, 3, 4, 5, 6, 7, 10, 15, 20 };
int  isadd(int n)   //递增返回1，否则返回0
{
	if (n==8)
	{
		return a[n] < a[n+1];//递归终止
	}
	else
	{
		return  (a[n] < a[n + 1]) && isadd(n + 1); //吧所有的判断串联一起来
	}



}

void  main5()
{
	printf("isadd(0) = %d \n", isadd(0));

	system("pause");

}
/**
将整数倒叙排列。采用非递归方式。12345,54321

*/
void  main()
{
	int num;
	scanf("%d", &num);//初始化数据
	printf("num=%d \n", num);
	//12345
	int lastres = 0;
	while (num)  // 12345  1234  123   12
	{
		lastres *= 10;     //  0    50     540     5430    54320
		int wei = num % 10; //5     4        3      2       1
		lastres   += wei ; //5     54     543      5432    54321
		num /= 10;  //1234       123      12        1      0

	}
    printf("lastres=%d \n", lastres);

    scanf("%d", &num);//初始化数据
    printf("daoxuFun(%d)=%d \n", num,daoxuFun(num));
	system("pause");
}
/**
将整数倒叙排列。采用递归方式。12345,54321

*/
int lastres = 0;
int daoxuFun(int num){

    if(num ==0){
        return lastres;
    }else{
        lastres = lastres *10 + num%10;
        return daoxuFun(num/10);
    }
}
