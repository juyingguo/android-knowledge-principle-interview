//#include<iostream.h>  
#include<stdio.h>  
  
typedef int (*FP_CALC)(int, int);  
//ע�����ﲻ�Ǻ����������Ǻ������壬����һ����ַ�������ֱ�����add����  
int add(int a, int b)  
{  
     return a + b;  
}  
int sub(int a, int b)  
{  
     return a - b;  
}  
int mul(int a, int b)  
{  
     return a * b;  
}  
int div(int a, int b)  
{  
     return b? a/b : -1;  
}  

int getName(int type){
	return type;
}
  
void main()  
{     
    int a = 100, b = 20; 
    
    FP_CALC fp = add;
	int ret = fp(a,b); 
	
	printf("ret =%d \n",ret);
	printf("add (address) =%p \n",add);
	
	/***********************
	FP_CALC fp2 = getName;
	int ret_for_getName = fp2(2); 
	
	printf("ret_for_getName =%d \n",ret_for_getName);
	**********************/
}  
