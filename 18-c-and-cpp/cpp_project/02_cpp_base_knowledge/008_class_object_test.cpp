#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      double length;   // ����
      double breadth;  // ���
      double height;   // �߶�
};
 
int main( )
{
   Box Box1;        // ���� Box1������Ϊ Box
   Box Box2;        // ���� Box2������Ϊ Box
   double volume = 0.0;     // ���ڴ洢���
 
   // box 1 ����
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;
 
   // box 2 ����
   Box2.height = 10.0;
   Box2.length = 20.0;
   Box2.breadth = 30.0;
 
   // box 1 �����
   volume = Box1.height * Box1.length * Box1.breadth;
   cout << "Box1 �������" << volume <<endl;
 
   // box 2 �����
   volume = Box2.height * Box2.length * Box2.breadth;
   cout << "Box2 �������" << volume <<endl;
   return 0;
}
