#include <iostream>
using namespace std;
int main()
{ char a[5]={'*','*','*','*','*'};
  int i,j,k;
  char space=' ';
  for (i=0;i<5;i++)              // ���5�� 
   { cout<<endl;                 // ���ÿ��ǰ�Ȼ��� 
     cout<<"    ";               // ÿ��ǰ����4���ո� 
     for (j=1;j<=i;j++)
       cout<<space;              // ÿ������һ���ո� 
     for (k=0;k<5;k++)
       cout<<a[k];               // ÿ�����5��*��
	}   
  cout<<endl;
   return 0;
} 
