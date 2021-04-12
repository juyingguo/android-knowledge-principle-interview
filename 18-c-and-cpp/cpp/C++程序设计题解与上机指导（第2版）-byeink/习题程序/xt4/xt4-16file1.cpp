#include <iostream>
using namespace std;
int a;
int main()
 {extern int power(int);
  int b=3,c,d,m;
  cout<<"enter an integer a and its power m:"<<endl;
  cin>>a>>m;
  c=a*b;
  cout<<a<<"*"<<b<<"="<<c<<endl;
  d=power(m);
  cout<<a<<"**"<<m<<"="<<d<<endl;
  return 0;
 }