#include <iostream>

using namespace std;

class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // ���ǹ��캯��

   private:
      double length;
};

// ��Ա�������壬�������캯��
Line::Line( double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

void Line::setLength( double len )
{
    length = len;
}

double Line::getLength( void )
{
    return length;
}
// �����������
int main( )
{
   Line line(10.0);

   // ��ȡĬ�����õĳ���
   cout << "Length of line : " << line.getLength() <<endl;
   // �ٴ����ó���
   line.setLength(6.0);
   cout << "Length of line : " << line.getLength() <<endl;

   return 0;
}
