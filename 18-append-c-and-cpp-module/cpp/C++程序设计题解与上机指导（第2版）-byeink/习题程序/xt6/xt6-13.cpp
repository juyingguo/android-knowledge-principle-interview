#include <iostream>
#include <cmath>
using namespace std;
int main()
{float integral(float (*p)(float),float a,float b,int n);
 float a1,b1,a2,b2,a3,b3,c,(*p)(float);
 float fsin(float);               // 对fsin函数作声明 
 float fcos(float);               // 对fcos函数作声明 
 float fexp(float);               // 对fexp函数作声明 
 int n=20;
 cout<<"input a1,b1:";           //输入求sin(x) 定积分的下限和上限 
 cin>>a1>>b1;          
 cout<<"input a2,b2:";         // 输入求cos(x) 定积分的下限和上限 
 cin>>a2>>b2;
 cout<<"input a3,b3:";         // 输入求#include <iostream>
 cin>>a3>>b3;
 p=fsin;
 c=integral(p,a1,b1,n);           // 求出sin(x)的定积分 
 cout<<"The integral of sin(x) is :"<<c<<endl;
 p=fcos;
 c=integral(p,a2,b2,n);           // 求出cos(x)的 定积分 
 cout<<"The integral of cos(x) is :"<<c<<endl;;
 p=fexp;
 c=integral(p,a3,b3,n);           // 求出 的定积分 
 cout<<"The integral of exp(x) is :"<<c<<endl;
 return 0;
}

float integral(float (*p)(float),float a,float b,int n)   
           //用矩形法求定积分的通用函数
{int i;
 float x,h,s;
 h=(b-a)/n;
 x=a;
 s=0;
 for (i=1;i<=n;i++)
  {x=x+h;
   s=s+(*p)(x)*h;
  }
return(s);
}

float fsin(float x)                    // 计算sin(x) 的函数 
{return sin(x);}

float fcos(float x)                    // 计算cos(x) 的函数 
{return cos(x);}

float fexp(float x)                    // 计算exp(x)的函数 
{return exp(x);} 
