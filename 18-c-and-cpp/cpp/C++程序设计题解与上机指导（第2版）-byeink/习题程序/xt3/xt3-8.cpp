#include <iostream>
using namespace std;
int main ( )
{ int a=3,b=4,c=5,x,y;
  cout<<(a+b>c && b==c)<<endl;
  cout<<(a||b+c && b-c)<<endl;
  cout<<(!(a>b) && !c||1)<<endl;
  cout<<(!(x=a) && (y=b) && 0)<<endl;
  cout<<(!(a+b)+c-1 && b+c/2)<<endl;
  return 0;
}  

