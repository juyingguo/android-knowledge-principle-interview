#include <iostream>
#include <iomanip>
using namespace std;
int main()
{long f1,f2;
 int i;
 f1=f2=1;
 for(i=1;i<=20;i++)
   {cout<<setw(12)<<f1<<setw(12)<<f2;
    if(i%2==0) cout<<endl;
    f1=f1+f2;
    f2=f2+f1;
   }
  return 0;
 }

