#include <iostream>
using namespace std;
int main()
{void select_sort(int array[],int n);             
 int a[10],i;
 cout<<"enter the originl array:"<<endl;
 for(i=0;i<10;i++)                                
   cin>>a[i];
 cout<<endl;
 select_sort(a,10);                              
 cout<<"the sorted array:"<<endl;
 for(i=0;i<10;i++)                             
   cout<<a[i]<<"  ";
 cout<<endl;
 return 0;
}

void select_sort(int array[],int n)              
{int i,j,k,t;
 for(i=0;i<n-1;i++)
 {k=i;
  for(j=i+1;j<n;j++)                    
    if(array[j]<array[k]) k=j;
 t=array[k];array[k]=array[i];array[i]=t;
}
} 
