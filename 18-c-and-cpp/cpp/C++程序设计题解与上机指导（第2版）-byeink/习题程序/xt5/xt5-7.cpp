#include <iostream>
using namespace std;
int main()
{ const int n=4,m=5;        //��������Ϊ4��5��     
  int i,j,a[n][m],max,maxj;
  bool flag;
  for (i=0;i<n;i++)         //��������
     for (j=0;j<m;j++)
      cin>>a[i][j];
  for (i=0;i<n;i++)         
   {max=a[i][0]; maxj=0;    
    for (j=0;j<m;j++)      //�ҳ���i���е������
	  if (a[i][j]>max)
	    {max=a[i][j];      //�����е�����������max��
	     maxj=j;           //����������ڵ��кŴ����maxj��
	    }
    flag=true;            //�ȼ����ǰ��㣬��flagΪ�����
    for (int k=0;k<n;k++)
	  if (max>a[k][maxj])  //�����������ͬ��Ԫ�����
	     {flag=false;     //���max����ͬ����С����ʾ���ǰ�����flag1Ϊ��
	      continue;}
    if(flag)             //���flag1Ϊ���ʾ�ǰ���
	{cout<<"a["<<i<<"]["<<"["<<maxj<<"]="<<max<<endl;
	                     //��������ֵ���������к�
	 break;
	}
  } 
  if(!flag)	            //���flagΪ�ٱ�ʾ���㲻����
    cout<<"It does not exist!"<<endl;
   return 0;
  } 


