#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
   // ����һ�������洢 int
   vector<int> vec; 
   int i;
 
   // ��ʾ vec ��ԭʼ��С
   cout << "vector size = " << vec.size() << endl;
 
   // ���� 5 ��ֵ��������
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
 
   // ��ʾ vec ��չ��Ĵ�С
   cout << "extended vector size = " << vec.size() << endl;
 
   // ���������е� 5 ��ֵ
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
 
   // ʹ�õ����� iterator ����ֵ
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }
 
   return 0;
}
