#include <iostream>
using namespace std;
int main()
  {int i,t,n=20;
   double a=2,b=1,s=0;
   for (i=1;i<=n;i++)
   {s=s+a/b;
    t=a; 
    a=a+b;           // 将前一项分子与分母之和作为下一项的分子 
    b=t;             // 将前一项的分子作为下一项的分母 
   }
   cout<<"sum="<<s<<endl;
   return 0;
   } 
  
