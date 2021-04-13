#include <iostream>
#include <iomanip>
using namespace std;

int main()
{float a[5];
 cout<<"input data:";
 for(int i=0;i<5;i++)
  cin>>a[i];
 cout<<setiosflags(ios::fixed)<<setprecision(2);
 for(i=0;i<5;i++)
  cout<<setw(10)<<a[i]<<endl;
 return 0;
}

