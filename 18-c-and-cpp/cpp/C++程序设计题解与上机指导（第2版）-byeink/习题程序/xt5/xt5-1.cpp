#include <iostream>
#include <iomanip>
using namespace std;
#include <math.h>
int main()
 {int i,j,n,a[101];
  for (i=1;i<=100;i++)
    a[i]=i;
  a[1]=0;
  for (i=2;i<sqrt(100);i++)
    for (j=i+1;j<=100;j++)
       {if(a[i]!=0 && a[j]!=0)
	      if (a[j]%a[i]==0)
	       a[j]=0;  }
    cout<<endl;
    for (i=1,n=0;i<=100;i++)
     {if (a[i]!=0)
       {cout<<setw(5)<<a[i]<<" ";
        n++;}
      if(n==10)
        {cout<<endl;
   	     n=0;}
     }
	cout<<endl;
	return 0;
   } 


 
