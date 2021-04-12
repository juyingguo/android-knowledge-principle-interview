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
//����һ������������Ϊop������һ��ָ�롣��ָ������Ϊ ӵ������int������  
//��������Ϊint �ĺ���ָ�롣���������Ǹ��ݲ�����������Ӧ�����ĵ�ַ  
FP_CALC calc_func(char op)  
{  
     switch (op)  
     {  
     case '+': return add;//���غ����ĵ�ַ  
     case '-': return sub;  
     case '*': return mul;  
     case '/': return div;  
     default:  
         return NULL;  
     }  
     return NULL;  
}  
//s_calc_funcΪ���������Ĳ����� op��  
//����ֵΪһ��ӵ�� ����int��������������Ϊint �ĺ���ָ��  
int (*s_calc_func(char op)) (int, int)  
{  
     return calc_func(op);  
}   
//�����û�ֱ�ӵ��õĺ������ú�����������int��������һ�����������������������������  
int calc(int a, int b, char op)  
{  
     FP_CALC fp = calc_func(op); //����Ԥ����õ���������ĺ����ĵ�ַ  
         int (*s_fp)(int, int) = s_calc_func(op);//���ڲ���  
         // ASSERT(fp == s_fp);   // ���Զ�����������ȵ�  
     if (fp) return fp(a, b);//������һ���õ��ĺ����ĵ�ַ������Ӧ�����������ؽ��  
     else return -1;  
}  
  
void main()  
{     
    int a = 100, b = 20;  
  
     printf("calc(%d, %d, %c) = %d\n", a, b, '+', calc(a, b, '+'));  
     printf("calc(%d, %d, %c) = %d\n", a, b, '-', calc(a, b, '-'));  
     printf("calc(%d, %d, %c) = %d\n", a, b, '*', calc(a, b, '*'));  
     printf("calc(%d, %d, %c) = %d\n", a, b, '/', calc(a, b, '/'));  
}  
