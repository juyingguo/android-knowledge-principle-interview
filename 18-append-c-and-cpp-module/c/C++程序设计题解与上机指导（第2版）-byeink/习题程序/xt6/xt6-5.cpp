#include <iostream>
using namespace std;
int main()
 {int i,k,m,n,num[50],*p;
  cout<<"input number of person: n=";
  cin>>n;
  p=num;
  for (i=0;i<n;i++)
    *(p+i)=i+1;          // ��1��nΪ���ÿ���˱�� 
  i=0;                   // iΪÿ��ѭ��ʱ�������� 
  k=0;                   // kΪ��1,2,3����ʱ�ļ������� 
  m=0;                   // mΪ�˳����� 
  while (m<n-1)          // ���˳�������n-1��ʱ(��δ�˳���������1ʱ)ִ��ѭ����
  {if (*(p+i)!=0)  k++;
   if (k==3)             // ���˳����˵ı����Ϊ0 
     {*(p+i)=0;
      k=0;
      m++;
     }
   i++;
   if (i==n) i=0;        // ������β��i�ָ�Ϊ0 
   }
  while(*p==0) p++;
  cout<<"The last one is NO."<<*p<<endl;
  return 0;
}
 

	
 
