#include<stdio.h>
#include<stdlib.h>//要使用malloc是要包含此头文件
#include <memory.h>//要使用memset是要包含此头文件
int main()
{
    int m;
    scanf("%d", &m);//scanf只是遇到回车符的时候结束，并没有把回车符输入，因此输入流中还有一个回车符
    getchar();//把输入流中的回车符读走
    int *p;
    p = (int*)malloc(m*(sizeof(int)));//动态申请内存
    int *ret = memset(p, 0, m);//初始化，每个元素都为零
    int i;
    for (i=0;i<m; i++)//数组赋值
    {
        p[i] = i;
    }
    for (i = 0; i <m; i++)//打印数组
    {
        printf("%p   %d\n",&p[i], p[i]);
    }
    printf("%p\n",p);
     printf("ret = %p\n",ret);
    free(p);//释放内存，malloc和free一定要记得成组使用，不然会导致程序吃内存

//    printf("%p   %d\n",&p[0], p[0]);
//    printf("%p   %d\n",&p[1], p[1]);
    getchar();//让程序停顿，观察输出
    return 0;
}
