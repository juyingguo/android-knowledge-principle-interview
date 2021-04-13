#include <iostream>
using namespace std;
//����������Shape
class Shape
{public:
 virtual double area() const =0;                                //���麯��
};

//����Circle(Բ��)��
class Circle:public Shape
{public:
Circle(double r):radius(r){}                                     //�ṹ����
  virtual double area() const {return 3.14159*radius*radius;};   //�����麯��
 protected:
  double radius;                                                 //�뾶
};

//����Square(������)��
class Square:public Shape
{public:
  Square(double s):side(s){}                                     //�ṹ����     
  virtual double area() const {return side*side;}                //�����麯��
 protected:
  double side;
};

//����Rectangle(����)��
class Rectangle:public Shape
{public:
 Rectangle(double w,double h):width(w),height(h){}               //�ṹ����
 virtual double area() const {return width*height;}              //�����麯��
 protected:
  double width,height;                                           //�����
};

//����Trapezoid(����)��
class Trapezoid:public Shape
{public:
  Trapezoid(double t,double b,double h):top(t),bottom(t),height(h){} //�ṹ����
  virtual double area() const {return 0.5*(top+bottom)*height;}      //�����麯��
 protected:
  double top,bottom,height;                                          //�ϵס��µ����
};

//����Triangle(������)��
class Triangle:public Shape
{public:
  Triangle(double w,double h):width(w),height(h){}                //�ṹ����
  virtual double area() const {return 0.5*width*height;}          //�����麯��
 protected:
  double width,height;                                            //�����
};

int main()
{
 Circle circle(12.6);                                             //����Circle�����circle
 Square square(3.5);                                              //����Square�����square
 Rectangle rectangle(4.5,8.4);                                    //����Rectangle�����rectangle
 Trapezoid trapezoid(2.0,4.5,3.2);                                //����Trapezoid�����trapezoid
 Triangle triangle(4.5,8.4);                                      //����Triangle�����
 Shape *pt[5]={&circle,&square,&rectangle,&trapezoid,&triangle};  
                                              //�������ָ������pt��ʹ��ÿһ��Ԫ��ָ��һ�����������
 double areas=0.0;                                                //areasΪ�����
 for(int i=0;i<5;i++)
  {areas=areas+pt[i]->area();}
 cout<<"totol of all areas="<<areas<<endl;   //��������
 return 0;
} 

