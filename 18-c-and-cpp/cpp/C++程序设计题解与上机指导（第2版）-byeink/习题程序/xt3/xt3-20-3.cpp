#include <iostream>
using namespace std;
int main()
  {int k[11];
   int i,a,n,s;
   for (a=2;a<=1000;a++)
   {n=0;
    s=a;
    for (i=1;i<a;i++)
     if ((a%i)==0)
       {n++;
        s=s-i;
        k[n]=i;           // 将找到的因子赋给k[1]┅k[10] 
       }
   if (s==0)
    {cout<<a<<" is a 完数"<<endl;
     cout<<"its factors are:";
     for (i=1;i<n;i++)
       cout<<k[i]<<" ";
     cout<<k[n]<<endl;
     }
   }
   return 0;
} 
  
 
