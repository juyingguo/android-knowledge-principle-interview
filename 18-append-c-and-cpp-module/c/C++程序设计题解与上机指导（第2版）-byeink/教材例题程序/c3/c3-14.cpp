#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{int m,k,i,n=0;
 bool prime;
 for(m=101;m<=200;m=m+2)
   {prime=true;
	k=int(sqrt(m));
    for(i=2;i<=k;i++)
		if(m%i==0) {prime=false;break;}
    if (prime)
      {cout<<setw(5)<<m;
       n=n+1;
      }
    if(n%10==0) cout<<endl;
   }
 cout<<endl;
 return 0;
}

