#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      double length;
      void setLength( double len );
      double getLength( void );
};
 
// ��Ա��������
double Line::getLength(void)
{
    return length ;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
// �����������
int main( )
{
   Line line;
 
   // ���ó���
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   // ��ʹ�ó�Ա�������ó���
   line.length = 10.0; // OK: ��Ϊ length �ǹ��е�
   cout << "Length of line : " << line.length <<endl;
   return 0;
}
