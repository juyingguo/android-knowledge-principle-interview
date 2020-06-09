#include <iostream>
using namespace std;
int max(int,int);
int main()
 {extern int a,b;
  cout<<max(a,b)<<endl;
  return 0;
 }

int a=15,b=-7;
int max(int x,int y)
 {int z;
  z=x>y?x:y;
  return z;
 }
