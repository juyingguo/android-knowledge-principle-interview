#include <iostream>
#include <cmath>
using namespace std;
#define S(a,b,c)  (a+b+c)/2
#define AREA(a,b,c) sqrt(S(a,b,c)*(S(a,b,c)-a)*(S(a,b,c)-b)*(S(a,b,c)-c))
int main()
 {float a,b,c;
  cout<<"input a,b,c:";
  cin>>a>>b>>c;
  if (a+b>c && a+c>b && b+c>a)
    cout<<"area="<<AREA(a,b,c)<<endl;
  else
    cout<<"It is not a triangle!"<<endl;
  return 0;
 } 
 


 
