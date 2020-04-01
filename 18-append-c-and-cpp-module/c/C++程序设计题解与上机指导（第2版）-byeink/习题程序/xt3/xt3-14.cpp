#include <iostream>
using namespace std;
int main ()
{int t,a,b,c,d;
 cout<<"enter four numbers:";
 cin>>a>>b>>c>>d;
 cout<<"a="<<a<<", b="<<b<<", c="<<c<<",d="<<d<<endl;
 if (a>b)
 {t=a;a=b;b=t;} 
 if (a>c)
  {t=a; a=c; c=t;}
 if (a>d)
  {t=a; a=d; d=t;}
 if (b>c)
  {t=b; b=c; c=t;}
 if (b>d)
  {t=b; b=d; d=t;}
 if (c>d)
   {t=c; c=d; d=t;}
 cout<<"the sorted sequence:"<<endl;
 cout<<a<<", "<<b<<", "<<c<<", "<<d<<endl;
 return 0;
 }

	
	