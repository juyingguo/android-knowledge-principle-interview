#include <iostream>
using namespace std;
int main()
{ const int n=7;
  int i,number,top,bott,mid,loca,a[n];
  bool flag=true,sign;
  char c;
  cout<<"enter data:"<<endl;;
  cin>>a[0];
  i=1;
  while(i<n)
   {cin>>a[i];
    if (a[i]>=a[i-1])
      i++;
    else
      cout<<"enter this data again:";
   }
  cout<<endl;
  for (i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  while(flag)
    {cout<<"input number to look for:";
     cin>>number;
     sign=false;
     top=0;            //top�ǲ����������ʼλ��
     bott=n-1;         //bott�ǲ����������ĩλ��
     if ((number<a[0])||(number>a[n-1]))  //Ҫ��������ڲ���������
       loca=-1;        // ��ʾ�Ҳ���
     while ((!sign) && (top<=bott))
       {mid=(bott+top)/2;
        if (number==a[mid])
         {loca=mid;
          cout<<"Find "<<number<<", its position is "<<loca+1<<endl;
		  sign=true;
         }
        else if (number<a[mid])
         bott=mid-1;
        else
        top=mid+1;
       }
     if(!sign||loca==-1)
       cout<<number<<" has not found."<<endl;;
     cout<<"continu or not(Y/N)?";
     cin>>c;
     if (c=='N'||c=='n')
	   flag=false;
    }
   return 0;
 } 
