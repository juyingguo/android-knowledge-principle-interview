#include <iostream>
#include <string>
using namespace std;
int main()
{ string stars="*****";
  int i,j;
  for (i=0;i<5;i++)              // ���5�� 
   { cout<<"    ";               // ÿ��ǰ����4���ո�
     for (j=1;j<=i;j++)
       cout<<" ";               // ÿ���ٲ���i���ո�    
     cout<<stars<<endl;         // ���5��*��
  }   
  return 0;
} 
