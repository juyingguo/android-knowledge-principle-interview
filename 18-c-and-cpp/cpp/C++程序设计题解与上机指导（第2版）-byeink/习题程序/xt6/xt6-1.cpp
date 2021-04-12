#include <iostream>
using namespace std;
int main()
 {void swap(int *p1,int *p2);
  int n1,n2,n3;
  int *p1,*p2,*p3;
  cout<<"input three integers n1,n2,n3:";
  cin>>n1>>n2>>n3;
  p1=&n1;
  p2=&n2;
  p3=&n3;
  if(n1>n2) swap(p1,p2);
  if(n1>n3) swap(p1,p3);
  if(n2>n3) swap(p2,p3);
  cout<<"Now,the order is:"<<n1<<" "<<n2<<" "<<n3<<endl;
  return 0;
 }

 void swap(int *p1,int *p2)
  {int p;
   p=*p1; *p1=*p2; *p2=p;
  }
