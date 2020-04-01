#include <iostream>
using namespace std;
int main()
{float a[5];
 int i;
 cout<<"input data:";
 for(i=0;i<5;i++)
  cin>>a[i];
 cout.setf(ios::fixed);
 cout.precision(2);
 for(i=0;i<5;i++)
  {cout.width(10);
   cout<<a[i]<<endl;}
 return 0;
}

