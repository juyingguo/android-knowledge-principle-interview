#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{int s=1;
 double n=1,t=1,pi=0;
 while((fabs(t)) > 1e-7)
   {pi=pi+t;
    n=n+2;
    s=-s;
    t=s/n;
	}
 pi=pi*4;
 cout<<"pi="<<setiosflags(ios::fixed)<<setprecision(6)<<pi<<endl;
 return 0;
}

