#include <stdio.h>
#include <stdlib.h>

int main()
{

   //接收到数据为：0XF1 0XF2 0X01 0X69 0XF3 0XF4 0X44

   int n01 = 0xF1;

	printf("int type storage sizeof(char) = %d:\n",sizeof(char));
	printf("int type storage sizeof(char(*)) = %d:\n",sizeof(char(*)));
	printf("int type storage sizeof(short) = %d:\n",sizeof(short));
	printf("int type storage sizeof(short(*) = %d:\n",sizeof(short(*)));
	printf("int type storage sizeof(int) = %d:\n",sizeof(int));
	printf("int type storage sizeof(int(*) = %d:\n",sizeof(int(*)));
	printf("float type storage sizeof(float) = %d:\n",sizeof(float));
	printf("float type storage sizeof(float(*) = %d:\n",sizeof(float(*)));
	printf("double type storage sizeof(double) = %d:\n",sizeof(double));
	printf("double type storage sizeof(double(*) = %d:\n",sizeof(double(*)));
   printf("n01 = %d:\n",n01);

   return(0);
}
