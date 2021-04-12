#include <iostream>
using namespace std;
//#include <math.h>
int main()
  {int i,j,min,temp,a[11];
   cout<<"enter data:"<<endl;
   for (i=1;i<=10;i++)
   {cout<<"a["<<i<<"]=";
    cin>>a[i];                   //输入10个数 
   }
   cout<<endl<<"The original numbers:"<<endl;;
   for (i=1;i<=10;i++)
     cout<<a[i]<<" ";           // 输出这10个数 
   cout<<endl;;
   for (i=1;i<=9;i++)           //以下8行是对10个数排序 
     {min=i;
      for (j=i+1;j<=10;j++)
        if (a[min]>a[j]) min=j;
         temp=a[i];             //以下3行将a[i+1]～a[10]中最小者与a[i] 对换
         a[i]=a[min];
         a[min]=temp;
      }
   cout<<endl<<"The sorted numbers:"<<endl;
   for (i=1;i<=10;i++)          // 输出已排好序的10个数 
     cout<<a[i]<<" ";
   cout<<endl;
   return 0;  
}  
    

 
 
