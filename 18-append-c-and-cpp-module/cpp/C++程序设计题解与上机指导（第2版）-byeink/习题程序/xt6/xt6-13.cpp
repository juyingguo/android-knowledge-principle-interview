#include <iostream>
#include <cmath>
using namespace std;
int main()
{float integral(float (*p)(float),float a,float b,int n);
 float a1,b1,a2,b2,a3,b3,c,(*p)(float);
 float fsin(float);               // ��fsin���������� 
 float fcos(float);               // ��fcos���������� 
 float fexp(float);               // ��fexp���������� 
 int n=20;
 cout<<"input a1,b1:";           //������sin(x) �����ֵ����޺����� 
 cin>>a1>>b1;          
 cout<<"input a2,b2:";         // ������cos(x) �����ֵ����޺����� 
 cin>>a2>>b2;
 cout<<"input a3,b3:";         // ������#include <iostream>
 cin>>a3>>b3;
 p=fsin;
 c=integral(p,a1,b1,n);           // ���sin(x)�Ķ����� 
 cout<<"The integral of sin(x) is :"<<c<<endl;
 p=fcos;
 c=integral(p,a2,b2,n);           // ���cos(x)�� ������ 
 cout<<"The integral of cos(x) is :"<<c<<endl;;
 p=fexp;
 c=integral(p,a3,b3,n);           // ��� �Ķ����� 
 cout<<"The integral of exp(x) is :"<<c<<endl;
 return 0;
}

float integral(float (*p)(float),float a,float b,int n)   
           //�þ��η��󶨻��ֵ�ͨ�ú���
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

float fsin(float x)                    // ����sin(x) �ĺ��� 
{return sin(x);}

float fcos(float x)                    // ����cos(x) �ĺ��� 
{return cos(x);}

float fexp(float x)                    // ����exp(x)�ĺ��� 
{return exp(x);} 
