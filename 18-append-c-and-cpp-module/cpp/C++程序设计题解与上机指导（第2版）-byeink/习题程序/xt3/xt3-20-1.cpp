#include <iostream>
using namespace std;
 int main()
 {const int m=1000;       // ����Ѱ�ҷ�Χ 
  int k1,k2,k3,k4,k5,k6,k7,k8,k9,k10;
  int i,a,n,s;
  for (a=2;a<=m;a++)      // a��2~1000֮���������������Ƿ�Ϊ���� 
   {n=0;                  // n�����ۼ�a�����ӵĸ��� 
    s=a;                  // s���������δ���������֮�ͣ���ʼʱ����a 
     for (i=1;i<a;i++)    // ���i�Ƿ�Ϊa������ 
       if (a%i==0)        // ���i��a������ 
	{n++;                 // n��1����ʾ���ҵ�һ������ 
	 s=s-i;               // s��ȥ���ҵ������ӣ�s����ֵ����δ���������֮�� 
	 switch(n)            // ���ҵ������Ӹ���k1,...,k10 
	  {case 1:
	      k1=i;  break;   // �ҳ�����1�����Ӹ���k1 
	   case 2:
	      k2=i;  break;   // �ҳ�����2�����Ӹ���k2 
	   case 3:
	      k3=i;  break;   // �ҳ�����3�����Ӹ���k3 
	   case 4:
	      k4=i;  break;   // �ҳ�����4�����Ӹ���k4 
	   case 5:
	      k5=i;  break;   // �ҳ�����5�����Ӹ���k5 
	   case 6:
	      k6=i;  break;    // �ҳ�����6�����Ӹ���k6 
	   case 7:
	      k7=i;  break;   // �ҳ�����7�����Ӹ���k7 
	   case 8:
	      k8=i;  break;    // �ҳ�����8�����Ӹ���k8 
	   case 9:
	      k9=i;  break;   // �ҳ�����9�����Ӹ���k9 
	   case 10:
	      k10=i;  break;   // �ҳ�����10�����Ӹ���k10 
	  }
	}
    if (s==0)              // s=0��ʾȫ�����Ӷ����ҵ��� 
     {cout<<a<<" is a ����"<<endl;
	  cout<<"its factors are:";
      if (n>1)  cout<<k1<<","<<k2;    // n>1��ʾa������2������ 
      if (n>2)  cout<<","<<k3; // n>2��ʾ������3�����ӣ���Ӧ�����һ������ 
      if (n>3)  cout<<","<<k4; // n>3��ʾ������4�����ӣ���Ӧ�����һ������ 
      if (n>4)  cout<<","<<k5;        //  �������� 
      if (n>5)  cout<<","<<k6;         
      if (n>6)  cout<<","<<k7;         
      if (n>7)	cout<<","<<k8;         
      if (n>8)	cout<<","<<k9;         
      if (n>9)	cout<<","<<k10;         
      cout<<endl<<endl;
    }
   }
  return 0;
 } 

