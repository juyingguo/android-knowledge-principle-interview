#include <iostream>
using namespace std;
int main()
{ void output(int (*p)[4]);
  int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
  output(a);
  return 0;
}

void output(int (*p)[4])  
{ int i,j;
  for(i=0;i<3;i++)
	for(j=0;j<4;j++)  
      cout<<*(*(p+i)+j)<<" ";
  cout<<endl;
}