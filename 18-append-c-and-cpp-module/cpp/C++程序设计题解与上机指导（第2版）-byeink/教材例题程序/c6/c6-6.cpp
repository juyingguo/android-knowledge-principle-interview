#include <iostream>
using namespace std;
int main()
{void select_sort(int *p,int n);             //��������
 int a[10],i;
 double c=3.6,*q=&c;
 cout<<"enter the originl array:"<<endl;
 for(i=0;i<10;i++)                                //����10����
   cin>>a[i];
 cout<<endl;
 select_sort(a,10);                              //�������ã���������ʵ��
 cout<<"the sorted array:"<<endl;
 for(i=0;i<10;i++)                               //���10���ź������
   cout<<a[i]<<"  ";
 cout<<endl;
 return 0;
}

void select_sort(int *p,int n)              
{int i,j,k,t;
 for(i=0;i<n-1;i++)
 {k=i;
     for(j=i+1;j<n;j++)                     
       if(*(p+j)<*(p+k)) k=j;
	   t=*(p+k);*(p+k)=*(p+i);*(p+i)=t;
 }
} 
