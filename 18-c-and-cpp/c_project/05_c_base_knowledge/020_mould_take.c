#include <stdio.h>

int main ()
{
	int n = 1;

    int const num = 8;
    int i = 0;
    for(i;i<10;i++){
        printf("%d %% %d= %d\n",i,num,i%num);
    }

    printf("3%4\n",3%4);
    printf("8%8\n",8%8);//常量直接打印，与通过变量打印不同得到的值不同。
    printf("9%8\n",9%8);
   return 0;
}

