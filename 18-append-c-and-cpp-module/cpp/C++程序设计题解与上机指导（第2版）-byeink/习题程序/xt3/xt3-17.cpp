#include <iostream>
using namespace std;
int main ()
{int  a,n,i=1,sn=0,tn=0;
 cout<<"a,n=:";
 cin>>a>>n;
 while (i<=n)
  {tn=tn+a;        //赋值后的tn为i个a组成数的值
   sn=sn+tn;       //赋值后的sn为多项式前i项之和
   a=a*10;
   ++i;
  }
  cout<<"a+aa+aaa+...="<<sn<<endl;
  return 0;
  } 
