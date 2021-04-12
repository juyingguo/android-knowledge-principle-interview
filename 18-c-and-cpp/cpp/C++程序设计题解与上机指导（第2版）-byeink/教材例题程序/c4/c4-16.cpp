#include <iostream>
using namespace std;
#define RUN
int main()
{int x=1,y=2,z=3;
 #ifndef RUN
  cout<<"x="<<x<<",y="<<y<<",z="<<z<<endl;
 #endif
 cout<<x*y*z<<endl;
 return 0;
}
