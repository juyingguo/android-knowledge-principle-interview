#include <iostream>
#include <cmath>
using namespace std;
int main()
{double a,b,c,s,area;
 cout<<"please input a,b,c:";
 cin>>a>>b>>c;
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
 return 0;
}
