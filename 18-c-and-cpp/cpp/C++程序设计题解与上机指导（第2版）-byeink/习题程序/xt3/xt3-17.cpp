#include <iostream>
using namespace std;
int main ()
{int  a,n,i=1,sn=0,tn=0;
 cout<<"a,n=:";
 cin>>a>>n;
 while (i<=n)
  {tn=tn+a;        //��ֵ���tnΪi��a�������ֵ
   sn=sn+tn;       //��ֵ���snΪ����ʽǰi��֮��
   a=a*10;
   ++i;
  }
  cout<<"a+aa+aaa+...="<<sn<<endl;
  return 0;
  } 
