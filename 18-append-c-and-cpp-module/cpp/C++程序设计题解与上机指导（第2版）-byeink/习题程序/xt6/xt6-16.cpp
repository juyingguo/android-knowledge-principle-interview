#include <iostream>
using namespace std;
int main()
{char str[50],*pstr;
 int i,j,k,m,e10,digit,ndigit,a[10],*pa;
 cout<<"input a string:"<<endl;
gets(str);
cout<<endl;
pstr=&str[0];    //�ַ�ָ��pstrָ������str��Ԫ�� 
pa=&a[0];        //ָ��paָ��a������Ԫ��
ndigit=0;        //ndigit�����ж��ٸ����� 
i=0;             //i�����ַ����еĵڼ����ַ�/
j=0;             //j�����������ֵ�λ�� 
while(*(pstr+i)!='\0')
 {if((*(pstr+i)>='0') && (*(pstr+i)<='9'))
    j++;
  else
   {if (j>0)
     {digit=*(pstr+i-1)-48;          //������λ����digit
      k=1;
      while (k<j)     //��������λ������������λ����ֵ�ۼ���digit
       {e10=1;
        for (m=1;m<=k;m++)
        e10=e10*10;                  //e10�����λ����Ӧ�˵�����
        digit=digit+(*(pstr+i-1-k)-48)*e10;  //����λ������ֵ�ۼ���digit
        k++;                         //λ��k����
       }
      *pa=digit;                     //����ֵ��������a��
      ndigit++;
      pa++;                         //ָ��paָ��a������һԪ��
      j=0;
     }
   }
  i++;
 }
 if (j>0)                         //�����ֽ�β�ַ��������һ������
  {digit=*(pstr+i-1)-48;          //������λ����digit
   k=1;
   while (k<j)          // ��������λ������������λ����ֵ�ۼ���digit
    {e10=1;
     for (m=1;m<=k;m++)
       e10=e10*10;            //e10����λ����Ӧ�˵�����
     digit=digit+(*(pstr+i-1-k)-48)*e10;  //����λ������ֵ�ۼ���digit
     k++;  /*λ��K����*/
    }
   *pa=digit;                 //����ֵ�ŵ�����a��
   ndigit++;
   j=0;
  }
  printf("There are %d numbers in this line. They are:\n",ndigit);
  j=0;
  pa=&a[0];
  for (j=0;j<ndigit;j++)            //��ӡ����
    cout<<*(pa+j)<<endl;
  cout<<endl;
  return 0;
}
