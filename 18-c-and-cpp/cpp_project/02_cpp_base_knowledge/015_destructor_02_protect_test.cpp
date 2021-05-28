
#include <iostream>

using namespace std;

class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();   // 这是构造函数声明

   protected :
    ~Line();  // 这是析构函数声明

   private:
      double length;
};

// 成员函数定义，包括构造函数
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

// 程序的主函数
int main( )
{
//   Line line;
//
//   // 设置长度
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
