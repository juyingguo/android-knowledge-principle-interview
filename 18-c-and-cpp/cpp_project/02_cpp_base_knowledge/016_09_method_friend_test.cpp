#include <iostream>
 
using namespace std;
 
class Box
{
   double width;
public:
   friend void printWidth( Box box );
   void setWidth( double wid );
};
 
// ��Ա��������
void Box::setWidth( double wid )
{
    width = wid;
}
 
// ��ע�⣺printWidth() �����κ���ĳ�Ա����
void printWidth( Box box )
{
   /* ��Ϊ printWidth() �� Box ����Ԫ��������ֱ�ӷ��ʸ�����κγ�Ա */
   cout << "Width of box : " << box.width <<endl;
}
 
// �����������
int main( )
{
   Box box;
 
   // ʹ�ó�Ա�������ÿ��
   box.setWidth(10.0);
   
   // ʹ����Ԫ����������
   printWidth( box );
 
   return 0;
}
