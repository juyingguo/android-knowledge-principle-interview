#include <iostream>
using namespace std;
 
// ��������
//�����Կ������ͺ������ԣ�����ĳ������޹ؽ�Ҫ�ģ���Ϊ C++ �������ʽ����ִ�б߽��顣
double getAverage(int arr[], int size);
 
int main ()
{
   // ���� 5 ��Ԫ�ص���������
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   // ����һ��ָ�������ָ����Ϊ����
   avg = getAverage( balance, 5 ) ;
 
   // �������ֵ
   cout << "ƽ��ֵ�ǣ�" << avg << endl; 
    
   return 0;
}

double getAverage(int arr[], int size)
{
  int    i, sum = 0;       
  double avg;          
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
   }
 
  avg = double(sum) / size;
 
  return avg;
}
