#include <iostream>
using namespace std;
int main()
{void change(int *p);
 int a[5][5],*p,i,j;
 cout<<"input matrix:"<<endl;
 for (i=0;i<5;i++)                       //�������
   for (j=0;j<5;j++)
     cin>>a[i][j];
 p=&a[0][0];                             //ʹpָ��0��0��Ԫ�� 
 change(p);                              //���ú�����ʵ�ֽ���
 cout<<"Now,matrix:"<<endl;
 for (i=0;i<5;i++)                      //����ѽ����ľ���
  {for (j=0;j<5;j++)
     cout<<a[i][j]<<" ";
   cout<<endl;
  }
 return 0;
}

void change(int *p)                    //��������
 {int i,j,temp;
  int *pmax,*pmin;
  pmax=p;
  pmin=p;
  for (i=0;i<5;i++)      //�����ֵ����Сֵ�ĵ�ַ,������ pmax,pmin
    for (j=i;j<5;j++)
     {if (*pmax<*(p+5*i+j)) pmax=p+5*i+j;
      if (*pmin>*(p+5*i+j)) pmin=p+5*i+j;
     }
  temp=*(p+12);              //�����ֵ������Ԫ�ػ���
  *(p+12)=*pmax;
  *pmax=temp;

  temp=*p;                  //����Сֵ�����Ͻ�Ԫ�ػ���
  *p=*pmin;
  *pmin=temp;

  pmin=p+1;            
    //��a[0][1]�ĵ�ַ����pmin���Ӹ�λ�ÿ�ʼ����С��Ԫ��
  for (i=0;i<5;i++)         //�ҵڶ���Сֵ�ĵ�ַ���� pmin 
    for (j=0;j<5;j++)
      if  (((p+5*i+j)!=p) && (*pmin > *(p+5*i+j))) pmin=p+5*i+j;
  temp=*pmin;              //���ڶ���Сֵ�����Ͻ�Ԫ�ػ��� 
  *pmin=*(p+4);
  *(p+4)=temp;

  pmin=p+1;
  for (i=0;i<5;i++)       //�ҵ�����Сֵ�ĵ�ַ����pmin 
    for (j=0;j<5;j++)
      if(((p+5*i+j)!=(p+4)) && ((p+5*i+j)!=p) &&(*pmin>*(p+5*i+j))) pmin=p+5*i+j;
  temp=*pmin;            // ��������Сֵ�����½�Ԫ�ػ���
  *pmin=*(p+20);
  *(p+20)=temp;

  pmin=p+1;
  for (i=0;i<5;i++)       // �ҵ�����Сֵ�ĵ�ַ����pmin */
     for (j=0;j<5;j++)
       if (((p+5*i+j)!=p) &&((p+5*i+j)!=(p+4)) && ((p+5*i+j)!=(p+20)) && (*pmin>*(p+5*i+j)))
        	 pmin=p+5*i+j;
  temp=*pmin;             //��������Сֵ�����½�Ԫ�ػ���
  *pmin=*(p+24);
  *(p+24)=temp;
  } 

	
	
 

	