#include <iostream> 
using namespace std;
int main()
{
 int a[2][3]={{1,2,3},{4,5,6}};
 int b[3][2],i,j;
 cout<<"array a:"<<endl;
 for (i=0;i<=1;i++)
 {
   for (j=0;j<=2;j++)
   {  cout<<a[i][j]<<" ";
      b[j][i]=a[i][j];
   }
   cout<<endl;
  }
  cout<<"array b:"<<endl;
  for (i=0;i<=2;i++)
  {
    for(j=0;j<=1;j++)
      cout<<b[i][j]<<" ";
    cout<<endl;             
   } 
  return 0;
}