#include <iostream>

using namespace std;

class Line
{
   public:
      void setLength(double len);
      double getLength(void);
      Line();  // ���ǹ��캯��

   private:
      double length;
};

// ��Ա�������壬�������캯��
Line::Line(void)
{
    cout << "Object is being created" << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}
// �����������
int main()
{
   Line line;

   // ���ó���
   line.setLength(5.0);
   cout << "Length of line : " << line.getLength() <<endl;

   return 0;
}
