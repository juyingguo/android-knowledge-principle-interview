#include <iostream>
using namespace std;
int main()
{ const n=10;
  int i;
  char a[n],temp;
  cout<<"please input a string:";
  for(i=0;i<n;i++)
	  cin>>a[i];
  for(i=0;i<n/2;i++)
  {temp=a[i];a[i]=a[n-i-1];a[n-i-1]=temp;}
  for(i=0;i<n;i++)
	  cout<<a[i];
  cout<<endl;
  return 0;
}
  
  
  
  