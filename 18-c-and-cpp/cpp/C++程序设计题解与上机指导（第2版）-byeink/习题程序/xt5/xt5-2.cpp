#include <iostream>
using namespace std;
//#include <math.h>
int main()
  {int i,j,min,temp,a[11];
   cout<<"enter data:"<<endl;
   for (i=1;i<=10;i++)
   {cout<<"a["<<i<<"]=";
    cin>>a[i];                   //����10���� 
   }
   cout<<endl<<"The original numbers:"<<endl;;
   for (i=1;i<=10;i++)
     cout<<a[i]<<" ";           // �����10���� 
   cout<<endl;;
   for (i=1;i<=9;i++)           //����8���Ƕ�10�������� 
     {min=i;
      for (j=i+1;j<=10;j++)
        if (a[min]>a[j]) min=j;
         temp=a[i];             //����3�н�a[i+1]��a[10]����С����a[i] �Ի�
         a[i]=a[min];
         a[min]=temp;
      }
   cout<<endl<<"The sorted numbers:"<<endl;
   for (i=1;i<=10;i++)          // ������ź����10���� 
     cout<<a[i]<<" ";
   cout<<endl;
   return 0;  
}  
    

 
 
