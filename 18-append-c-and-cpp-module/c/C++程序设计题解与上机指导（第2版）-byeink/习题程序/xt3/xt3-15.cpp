#include <iostream>
using namespace std;
int main ()
{int p,r,n,m,temp;
 cout<<"please enter two positive integer numbers n,m:"; 
 cin>>n>>m; 
 if (n<m)              
     {temp=n;
      n=m;
      m=temp;                //�Ѵ�������n��, С������m��
     }
 p=n*m;                     //�Ƚ�n��m�ĳ˻�������p��, �Ա�����С������ʱ��
 while (m!=0)               //��n��m�����Լ��
    {r=n%m;
     n=m;
     m=r;
 }
 cout<<"HCF="<<n<<endl;
 cout<<"LCD="<<p/n<<endl;        // p��ԭ�����������ĳ˻�
 return 0;
 }
   



	
	