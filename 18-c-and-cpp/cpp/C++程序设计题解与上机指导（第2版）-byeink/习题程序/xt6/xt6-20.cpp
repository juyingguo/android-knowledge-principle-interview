#include <iostream>
using namespace std;
int main()
{void sort(int **p,int n);
 int i,n,data[10],**p,*pstr[10];
 cout<<"input n:";
 cin>>n;
 for (i=0;i<n;i++)
   pstr[i]=&data[i];   /*将第i个整数的地址赋予指针数组 pstr 的第i个元素*/
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
     {if (**(p+i)>**(p+j))      //比较后交换整数地址
       {temp=*(p+i);
        *(p+i)=*(p+j);
        *(p+j)=temp; 
       }
     }
  }
} 

