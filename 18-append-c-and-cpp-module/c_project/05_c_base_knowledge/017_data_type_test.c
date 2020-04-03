#include <stdio.h>
#include <stdlib.h>

int main()
{
   
   //接收到数据为：0XF1 0XF2 0X01 0X69 0XF3 0XF4 0X44
   
   int n01 = 0xF1;
   
	printf("int type storage size = %d:\n",sizeof(int));
	printf("float type storage size = %d:\n",sizeof(float));
	printf("double type storage size = %d:\n",sizeof(double));
   printf("n01 = %d:\n",n01);

   return(0);
}
