#include <iostream>
using namespace std;
//����������Shape
class Shape
{public:
 virtual double area() const =0;            //���麯��
};

//����Circle��
class Circle:public Shape
{public:
Circle(double r):radius(r){}                                     //�ṹ����
  virtual double area() const {return 3.14159*radius*radius;};   //�����麯��
 protected:
  double radius;                                                 //�뾶
};

//����Rectangle��
class Rectangle:public Shape
{public:
 Rectangle(double w,double h):width(w),height(h){}               //�ṹ����
 virtual double area() const {return width*height;}              //�����麯��
 protected:
  double width,height;                                           //�����
};

class Triangle:public Shape
{public:
  Triangle(double w,double h):width(w),height(h){}                //�ṹ����
  virtual double area() const {return 0.5*width*height;}          //�����麯��
 protected:
  double width,height;                                            //�����
};

//�������ĺ���
void printArea(const Shape &s)
{cout<<s.area()<<endl;}                                            //���s�����

int main()
{
 Circle circle(12.6);                                             //����Circle�����circle
 cout<<"area of circle    =";          
 printArea(circle);                                               //���circle�����
 Rectangle rectangle(4.5,8.4);                                    //����Rectangle�����rectangle
 cout<<"area of rectangle =";                                     
 printArea(rectangle);                                            //���rectangle�����
 Triangle triangle(4.5,8.4);                                      //����Triangle����� 
 cout<<"area of triangle  =";
 printArea(triangle);           //���triangle�����
 return 0;
}

