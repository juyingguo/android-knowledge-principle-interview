#include <iostream>
using namespace std;
 
int main ()
{
   float *pvalue  = NULL; // ��ʼ��Ϊ null ��ָ��
   pvalue  = new float;   // Ϊ���������ڴ�
 
   *pvalue = 29494.99f;     // �ڷ���ĵ�ַ�洢ֵ
   cout << "Value of pvalue : " << *pvalue << endl;
 
   delete pvalue;         // �ͷ��ڴ�
 
   return 0;
}
