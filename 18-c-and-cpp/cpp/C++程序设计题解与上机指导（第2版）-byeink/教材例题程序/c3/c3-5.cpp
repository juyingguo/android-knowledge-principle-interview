#include <iostream>
#include <cmath>
using namespace std;
int main()
{float  a,b,c,x1,x2;
 cin>>a>>b>>c;
 x1=(-b+sqrt(b*b-4*a*c))/(2*a);
 x2=(-b-sqrt(b*b-4*a*c))/(2*a);
 cout<<"x1="<<x1<<endl;
 cout<<"x2="<<x2<<endl;
 return 0;
}
