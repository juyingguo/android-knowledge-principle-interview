#include <iostream>
using namespace std;
long fac(int);
int main()
 {int n;
  long y;
  cout<<"please input an integer:";
  cin>>n;
  y=fac(n);
  cout<<n<<"!="<<y<<endl;
  return 0;
 }

long fac(int n)
{
 long f;
 if(n<0)
  {cout<<"n<0,data error!"<<endl;
   f=-1;
  }
 else if (n==0||n==1) f=1;
 else f=fac(n-1)*n;
 return f;
}


