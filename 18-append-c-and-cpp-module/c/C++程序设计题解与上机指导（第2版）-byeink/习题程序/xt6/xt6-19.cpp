#include <iostream>
using namespace std;
            
int main()
{void sort(char **p);
 const int m=20;        //�����ַ�������󳤶�
 int i;
 char **p,*pstr[5],str[5][m];
 for (i=0;i<5;i++)
   pstr[i]=str[i];   /*����i���ַ������׵�ַ����ָ������ pstr �ĵ�i��Ԫ��*/
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

void sort(char **p)            //ð�ݷ���5���ַ���������
{int i,j;
 char *temp;
 for (i=0;i<5;i++)
  {for (j=i+1;j<5;j++)
    {if (strcmp(*(p+i),*(p+j))>0)      //�ȽϺ󽻻��ַ�����ַ
      {temp=*(p+i);
       *(p+i)=*(p+j);
       *(p+j)=temp;
      }
     }
  }
} 
