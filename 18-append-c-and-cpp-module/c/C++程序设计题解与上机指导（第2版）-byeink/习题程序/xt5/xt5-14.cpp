#include <iostream>
#include <string>
using namespace std;
int main()
{ const int n=5;
  int i,j;
  string str[n],temp;
  cout<<"please input strings:"<<endl;
  for(i=0;i<n;i++)
	  cin>>str[i];
  for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
      if(str[j]>str[j+1])
	  {temp=str[j];str[j]=str[j+1];str[j+1]=temp;}
  cout<<endl<<"sorted strings:"<<endl;
  for(i=0;i<n;i++)
	  cout<<str[i]<<endl;
  return 0;
}
  
  
  