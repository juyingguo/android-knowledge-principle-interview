#include<stdio.h>

typedef int *P;
  
void main()  
{     
	int a = 16;
    P b;
    b = &a; 
	printf("b value =%d \n",*b);
	return 0;
}  
