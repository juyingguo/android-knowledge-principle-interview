#include <iostream>
#include <math.h>
using namespace std;
float x1,x2,disc,p,q;
int main()
{void greater_than_zero(float,float);
 void equal_to_zero(float,float); 
 void smaller_than_zero(float,float); 
 float a,b,c;
 cout<<"input a,b,c:";
 cin>>a>>b>>c;
 disc=b*b-4*a*c;
 cout<<"root:"<<endl;
 if (disc>0)
  {
   greater_than_zero(a,b);
   cout<<"x1="<<x1<<",x2="<<x2<<endl;
  }
 else if (disc==0)
  {equal_to_zero(a,b);
   cout<<"x1="<<x1<<",x2="<<x2<<endl;
  }
 else
  {smaller_than_zero(a,b);
   cout<<"x1="<<p<<"+"<<q<<"i"<<endl;
   cout<<"x2="<<p<<"-"<<q<<"i"<<endl;
  }
 return 0;
}

void greater_than_zero(float a,float b)   /* 定义一个函数，用来求disc>0时方程的根 */
 {x1=(-b+sqrt(disc))/(2*a);
  x2=(-b-sqrt(disc))/(2*a);
 }

void equal_to_zero(float a,float b)     /* 定义一个函数，用来求disc=0时方程的根 */
 {
  x1=x2=(-b)/(2*a);
 }

void smaller_than_zero(float a,float b)  /* 定义一个函数，用来求disc<0时方程的根 */
 {
  p=-b/(2*a);
  q=sqrt(-disc)/(2*a);
 }

