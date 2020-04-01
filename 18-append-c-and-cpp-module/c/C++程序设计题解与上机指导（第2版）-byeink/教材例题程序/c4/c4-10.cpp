#include <iostream>
using namespace std;
int age(int);
int main()
 {cout<<age(5)<<endl;
  return 0;
 }

int age(int n)
{
 int c;
 if(n==1) c=10;
 else c=age(n-1)+2;
 return c;
}


