#include <strstream>
#include <iostream>
using namespace std;
int main()
{char c[50]="12 34 65 -23 -32 33 61 99 321 32";
 int a[10],i,j,t;
 cout<<"array c:"<<c<<endl;
 istrstream strin(c,sizeof(c));
 for(i=0;i<10;i++)
  strin>>a[i];
 cout<<"array a:";
 for(i=0;i<10;i++)
   cout<<a[i]<<" ";
 cout<<endl;
 for(i=0;i<9;i++)
   for(j=0;j<9-i;j++)
      if(a[j]>a[j+1])
        {t=a[j];a[j]=a[j+1];a[j+1]=t;}
 ostrstream strout(c,sizeof(c));
 for(i=0;i<10;i++)
   strout<<a[i]<<" ";
 strout<<ends;
 cout<<"array c:"<<c<<endl;
 return 0;
}

