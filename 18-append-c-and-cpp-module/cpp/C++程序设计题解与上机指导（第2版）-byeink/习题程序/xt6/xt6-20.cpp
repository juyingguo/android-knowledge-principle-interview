#include <iostream>
using namespace std;
int main()
{void sort(int **p,int n);
 int i,n,data[10],**p,*pstr[10];
 cout<<"input n:";
 cin>>n;
 for (i=0;i<n;i++)
   pstr[i]=&data[i];   /*����i�������ĵ�ַ����ָ������ pstr �ĵ�i��Ԫ��*/
 cout<<"input "<<n<<" integer numbers:"<<endl;
 for (i=0;i<n;i++)
   cin>>*pstr[i];
 p=pstr;
 sort(p,n);
 cout<<"Now,the sequence is:"<<endl;
 for (i=0;i<n;i++)
   cout<<*pstr[i]<<"  ";
 cout<<endl;
 return 0;
}

void sort(int **p,int n)
{int i,j,*temp;
 for (i=0;i<n-1;i++)
  {for (j=i+1;j<n;j++)
     {if (**(p+i)>**(p+j))      //�ȽϺ󽻻�������ַ
       {temp=*(p+i);
        *(p+i)=*(p+j);
        *(p+j)=temp; 
       }
     }
  }
} 

