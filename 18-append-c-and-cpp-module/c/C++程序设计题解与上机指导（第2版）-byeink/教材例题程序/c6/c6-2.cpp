#include  <iostream>
using namespace std;
int main()
{
  int *p1,*p2,*p,a,b;
  cin>>a>>b;
  p1=&a;
  p2=&b;
  if(a<b)
  {p=p1;p1=p2;p2=p;}
  cout<<"a="<<a<<" b="<<b<<endl;
  cout<<"max="<<*p1<<" min="<<*p2<<endl;
  return 0;
}
