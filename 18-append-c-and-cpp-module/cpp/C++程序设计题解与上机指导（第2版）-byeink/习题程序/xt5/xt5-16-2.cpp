#include <iostream>
#include <string>
using namespace std;
int main()
{ string a;
  int i,n;
  char temp;
  cout<<"please input a string:";
  cin>>a;
  n=a.size();
  for(i=0;i<n/2;i++)
  {temp=a[i];a[i]=a[n-i-1];a[n-i-1]=temp;}
  cout<<a<<endl;
  return 0;
}
  
  
  
  