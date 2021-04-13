#include <iostream>
using namespace std;
int main()
{ int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
  int (*p)[4],i,j;
  cin>>i>>j;
  p=a;
  cout<<*(*(p+i)+j)<<endl;
  return 0;
}