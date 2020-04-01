#include <iostream>
#include <cmath>
using namespace std;
int main()
{double solut(double ,double ,double ,double );
 double a,b,c,d;
 cout<<"input a,b,c,d:";
 cin>>a>>b>>c>>d;
 cout<<"x="<<solut(a,b,c,d)<<endl;
 return 0;
}
 
double solut(double a,double b,double c,double d)
 {double x=1,x0,f,f1;
  do
   {x0=x;
    f=((a*x0+b)*x0+c)*x0+d;
    f1=(3*a*x0+2*b)*x0+c;
    x=x0-f/f1;
   }
  while(fabs(x-x0)>=1e-5);
  return(x);
}
