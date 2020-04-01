#include <iostream>
using namespace std;
int main()
{ const int n=5;
  int a[n],i,temp;
  cout<<"enter array a:"<<endl; 
  for (i=0;i<n;i++)
    cin>>a[i];
  cout<<"array a:"<<endl;
  for (i=0;i<n;i++)
   cout<<a[i]<<" ";
  for (i=0;i<n/2;i++)            //循环的作用是将对称的元素的值互换
    { temp=a[i];
      a[i]=a[n-i-1];
      a[n-i-1]=temp;
     }
  cout<<endl<<"Now,array a:"<<endl;
  for (i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}   



