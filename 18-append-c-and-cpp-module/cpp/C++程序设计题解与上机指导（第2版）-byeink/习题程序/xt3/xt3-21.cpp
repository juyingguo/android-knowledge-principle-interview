#include <iostream>
using namespace std;
int main()
  {int i,t,n=20;
   double a=2,b=1,s=0;
   for (i=1;i<=n;i++)
   {s=s+a/b;
    t=a; 
    a=a+b;           // ��ǰһ��������ĸ֮����Ϊ��һ��ķ��� 
    b=t;             // ��ǰһ��ķ�����Ϊ��һ��ķ�ĸ 
   }
   cout<<"sum="<<s<<endl;
   return 0;
   } 
  
