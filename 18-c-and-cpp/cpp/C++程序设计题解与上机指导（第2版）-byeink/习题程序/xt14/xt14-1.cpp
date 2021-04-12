#include <iostream>
#include <cmath>
using namespace std;
double q(double,double,double);
void main()
{double a,b,c,p,x1,x2;
 cout<<"please enter a,b,c:";
 cin>>a>>b>>c;
 p=-b/(2*a);
 try
  {x1=p+q(a,b,c);
   x2=p-q(a,b,c);
   cout<<"x1="<<x1<<endl<<"x2="<<x2<<endl;
  }
 catch(double d)
   {cout<<"a="<<a<<",b="<<b<<",c="<<c<<",disc="<<d<<",error!"<<endl;}
 cout<<"end"<<endl;
}

double q(double a,double b,double c)
 {double disc;
  disc=b*b-4*a*c;
  if (disc<0) throw disc;
  return sqrt(disc)/(2*a);
 }
  
