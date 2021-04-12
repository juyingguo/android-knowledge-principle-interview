//14.2.2 C语言结构体中定义函数指针详解
//			【优质博客】【linux,嵌入式，驱动】
//			https://blog.csdn.net/qq_21792169/article/details/50436089

#include <stdio.h> /* 标准输入输出头文件 */
#include <stdlib.h> /* strtoul用到的头文件*/


struct test_pfun { /* 定义一个结构体，里面有三个成员，是三个函数指针 ,前面千万不要加static,这里并没有分配内存*/
	int (*add) (int a,int b); 
	int (*sub) (int a,int b);
	int (*mult) (int a,int b);
};

static int test_add(int a,int b)  /* 定义求和函数 */
{
 	return (a+b);
}

static int test_sub(int a,int b)  /* 定义相减函数 */
{
 	return (a-b);
}

static int  test_mult(int a,int b)  /* 定义乘法函数 */
{
 	return (a*b);
}


struct test_pfun pfun={  /* 关键的地方时在这里，看怎么函数指针赋值 */
.add  =test_add,
.sub  =test_sub,
.mult =test_mult,
};

int main(void)
{
	 int a = 10 ,b = 20; 

	/* 不懂strtoul命令的请点击这里：点击这里！ */

	printf("a+b=%d\n",pfun.add(a,b));
	printf("a-b=%d\n",pfun.sub(a,b));
	printf("a*b=%d\n",pfun.mult(a,b));
 	return 0;
}
