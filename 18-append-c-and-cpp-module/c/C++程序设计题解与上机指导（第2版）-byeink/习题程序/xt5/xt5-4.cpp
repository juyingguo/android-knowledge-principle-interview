#include <iostream>
using namespace std;
int main()
 {int a[11]={1,4,6,9,13,16,19,28,40,100};
   int num,i,j;
   cout<<"array a:"<<endl;
   for (i=0;i<10;i++)
     cout<<a[i]<<" ";
   cout<<endl;;
   cout<<"insert data:";
   cin>>num;
   if (num>a[9])
     a[10]=num;
   else
    {for (i=0;i<10;i++)
     {if (a[i]>num)
       {for (j=9;j>=i;j--)
         a[j+1]=a[j];
        a[i]=num;
		break;
       }
      }
     }
  cout<<"Now, array a:"<<endl;
  for (i=0;i<11;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
 }
