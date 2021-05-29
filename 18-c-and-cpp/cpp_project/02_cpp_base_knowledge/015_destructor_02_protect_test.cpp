
#include <iostream>

using namespace std;

class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();   // ���ǹ��캯������

   protected :
    ~Line();  // ����������������

   private:
      double length;
};

// ��Ա�������壬�������캯��
Line::Line(void)
{
    cout << "Object Line is being created" << endl;
}
Line::~Line(void)
{
    cout << "Object Line is being deleted" << endl;
}

void Line::setLength( double len )
{
    length = len;
}

double Line::getLength( void )
{
    return length;
}
class Rectangle :public Line{

    public:
        Rectangle(){
            cout << "Object Rectangle is being created" << endl;
        }
        ~Rectangle();

//    Rectangle::~Line(){
//        cout << "Object Line is being deleted" << endl;
//    }
//    Rectangle::~Rectangle(){
//        cout << "Object Rectangle is being deleted" << endl;
//    }
};
//Rectangle::Rectangle(void)
//    {
//        cout << "Object Rectangle is being created" << endl;
//    }

Rectangle::~Rectangle()
{
    cout << "Object Rectangle is being deleted" << endl;
}

// �����������
int main( )
{
//   Line line;
//
//   // ���ó���
//   line.setLength(6.0);
//   cout << "Length of line : " << line.getLength() <<endl;
//
//   line.setLength(20.0);
//   cout << "Length of line : " << line.getLength() <<endl;

    Rectangle rect;
    rect.setLength(8.0);
    cout << "Length of rect : " << rect.getLength() <<endl;


   return 0;
}
