#include <iostream>
#include <cmath>
using namespace std;
int main()
 {float a,x0,x1;
  cout<<"enter a positive number:";
  cin>>a;            // ÊäÈëaµÄÖµ 
  x0=a/2;
  x1=(x0+a/x0)/2;
  do
    {x0=x1;
     x1=(x0+a/x0)/2;
     }
  while(fabs(x0-x1)>=1e-5);
  cout<<"The square root of "<<a<<" is "<<x1<<endl;
  return 0;
 } 
  

