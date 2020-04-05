#include <iostream>
using namespace std;
int main()
{
 int a,b,c;
 int add(int x,int y);
 cin>>a>>b;
 c=add(a,b);
 cout<<"a+b="<<c<<endl;
 return 0;
}

int add(int x,int y)
{int z;
 z=x+y;
 return(z);
}
