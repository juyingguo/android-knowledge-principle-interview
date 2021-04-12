#include <iostream>
#include <cmath>
using namespace std;
int main()
 {double e(double);               
  double x,sinh;
  cout<<"enter x:";
  cin>>x;
  sinh=(e(x)+e(-x))/2;
  cout<<"sinh("<<x<<")="<<sinh<<endl;  
  return 0;
 }

 double e(double x)
  {return exp(x);}
 


