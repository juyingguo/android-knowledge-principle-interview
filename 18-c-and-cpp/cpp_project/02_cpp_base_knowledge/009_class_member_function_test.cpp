#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      double length;         // ����
      double breadth;        // ���
      double height;         // �߶�
 
      // ��Ա��������
      double getVolume(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
};
 
// ��Ա��������
double Box::getVolume(void)
{
    return length * breadth * height;
}
 
void Box::setLength( double len )
{
    length = len;
}
 
void Box::setBreadth( double bre )
{
    breadth = bre;
}
 
void Box::setHeight( double hei )
{
    height = hei;
}
 
// �����������
int main( )
{
   Box Box1;                // ���� Box1������Ϊ Box
   Box Box2;                // ���� Box2������Ϊ Box
   double volume = 0.0;     // ���ڴ洢���
 
   // box 1 ����
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 ����
   Box2.setLength(10.0); 
   Box2.setBreadth(30.0); 
   Box2.setHeight(20.0);
 
   // box 1 �����
   volume = Box1.getVolume();
   cout << "Box1 �������" << volume <<endl;
 
   // box 2 �����
   volume = Box2.getVolume();
   cout << "Box2 �������" << volume <<endl;
   return 0;
}
