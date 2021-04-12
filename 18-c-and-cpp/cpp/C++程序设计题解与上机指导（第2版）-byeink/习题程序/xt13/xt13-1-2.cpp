#include <iostream>
#include <cmath>
using namespace std;

void input(double a,double b,double c)
{cout<<"please input a,b,c:";
 cin>>a>>b>>c;
}
void area(double a,double b,double c)
{double s,area;
 if (a+b<=c)
  cerr<<"a+b<=c,error!"<<endl;
 else if(b+c<=a)
  cerr<<"b+c<=a,error!"<<endl;
 else if (c+a<=b)
  cerr<<"c+a<=b,error!"<<endl;
 else
  {s=(a+b+c)/2;
   area=sqrt(s*(s-a)*(s-b)*(s-c));
   cout<<"area="<<area<<endl;}
}
int main()
{double a=2,b=3,c=5;
 input(a,b,c);
 area(a,b,c);
 return 0;
}
 
