#include <iostream>
using namespace std;
int main()
  {int i,k;
    for (i=0;i<=3;i++)         // �������4��*�� 
      {for (k=0;k<=2*i;k++)
        cout<<"*";           // ���*�� 
       cout<<endl;           //�����һ��*�ź��� 
      }
    for (i=0;i<=2;i++)        // �������3��*�� 
      {for (k=0;k<=4-2*i;k++)
         cout<<"*";          // ���*�� 
       cout<<endl;           // �����һ��*�ź���
      }
	return 0;
    } 

