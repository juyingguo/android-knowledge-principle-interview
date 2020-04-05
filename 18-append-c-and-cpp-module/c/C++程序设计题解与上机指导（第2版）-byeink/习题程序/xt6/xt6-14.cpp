#include <iostream>
using namespace std;
int main()
{ void sort (char *p,int m);
  int i,n;
  char *p,num[20];
  cout<<"input n:";
  cin>>n;
  cout<<"please input these numbers:"<<endl;
  for (i=0;i<n;i++)
   cin>>num[i];
  p=&num[0];
  sort(p,n);
  cout<<"Now,the sequence is:"<<endl;
  for (i=0;i<n;i++)
    cout<<num[i]<<" ";
  cout<<endl;
  return 0;
 }

 void sort (char *p,int m)              // 将n个数逆序排列函数 
 {int i;
  char temp, *p1,*p2;
  for (i=0;i<m/2;i++)
  {p1=p+i;
   p2=p+(m-1-i);
   temp=*p1;
   *p1=*p2;
   *p2=temp;
  }
 }