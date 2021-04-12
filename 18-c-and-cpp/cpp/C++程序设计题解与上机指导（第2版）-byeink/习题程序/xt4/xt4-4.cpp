#include <iostream>
using namespace std;
int main()
 {int fac(int);               
  int a,b,c,sum=0;
  cout<<"enter a,b,c:";
  cin>>a>>b>>c;
  sum=sum+fac(a)+fac(b)+fac(c);
  cout<<a<<"!+"<<b<<"!+"<<c<<"!="<<sum<<endl;  
  return 0;
 }

 int fac(int n)
  {int f=1;
   for (int i=1;i<=n;i++)
     f=f*i;
   return f;
  }
 


