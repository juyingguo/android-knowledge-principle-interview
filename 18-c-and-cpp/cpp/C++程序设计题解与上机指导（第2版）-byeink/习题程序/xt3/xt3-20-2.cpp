#include <iostream>
using namespace std;
 int main()
  {int m,s,i;
   for (m=2;m<1000;m++)
    {s=0;
     for (i=1;i<m;i++)
       if ((m%i)==0) s=s+i;
     if(s==m)
      {cout<<m<<" is aÍêÊý"<<endl;
	   cout<<"its factors are:";
       for (i=1;i<m;i++)
        if (m%i==0)  cout<<i<<" ";
       cout<<endl;
      }
    }
   return 0;
 } 
