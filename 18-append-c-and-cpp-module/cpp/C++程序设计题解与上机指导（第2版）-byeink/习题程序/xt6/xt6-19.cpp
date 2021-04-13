#include <iostream>
using namespace std;
            
int main()
{void sort(char **p);
 const int m=20;        //定义字符串的最大长度
 int i;
 char **p,*pstr[5],str[5][m];
 for (i=0;i<5;i++)
   pstr[i]=str[i];   /*将第i个字符串的首地址赋予指针数组 pstr 的第i个元素*/
 cout<<"input 5 strings:"<<endl;
 for (i=0;i<5;i++)
    cin>>pstr[i];
 p=pstr;
 sort(p);
 cout<<"strings sorted:"<<endl;
 for (i=0;i<5;i++)
    cout<<pstr[i]<<endl;
 return 0;
}

void sort(char **p)            //冒泡法对5个字符串排序函数
{int i,j;
 char *temp;
 for (i=0;i<5;i++)
  {for (j=i+1;j<5;j++)
    {if (strcmp(*(p+i),*(p+j))>0)      //比较后交换字符串地址
      {temp=*(p+i);
       *(p+i)=*(p+j);
       *(p+j)=temp;
      }
     }
  }
} 
