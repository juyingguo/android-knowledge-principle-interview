#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      virtual int area() = 0;
};
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      { 
         cout << "Rectangle class area :" << (width * height) <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      //Triangle( int a, int b):Shape(a, b) { }
      Triangle( int a, int b) {
      	width = a;
      	height = b;
		}
      int area ()
      { 
         cout << "Triangle class area :" << (width * height / 2 ) <<endl;
         return (width * height / 2); 
      }
};
// �����������
int main( )
{
   Shape *shape;
   //Shape selfShape(20,30);
   
   //selfShape.area();
   
   Rectangle rec(10,7);
   Triangle  tri(10,5);
 
   // �洢���εĵ�ַ
   shape = &rec;
   // ���þ��ε���������� area
   shape->area();
 
   // �洢�����εĵ�ַ
   shape = &tri;
   // ���������ε���������� area
   shape->area();
   
   
   
   return 0;
}
