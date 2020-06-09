#include <iostream>
using namespace std;
//定义抽象基类Shape
class Shape
{public:
 virtual double area() const =0;            //纯虚函数
};

//定义Circle类
class Circle:public Shape
{public:
Circle(double r):radius(r){}                                     //结构函数
  virtual double area() const {return 3.14159*radius*radius;};   //定义虚函数
 protected:
  double radius;                                                 //半径
};

//定义Rectangle类
class Rectangle:public Shape
{public:
 Rectangle(double w,double h):width(w),height(h){}               //结构函数
 virtual double area() const {return width*height;}              //定义虚函数
 protected:
  double width,height;                                           //宽与高
};

class Triangle:public Shape
{public:
  Triangle(double w,double h):width(w),height(h){}                //结构函数
  virtual double area() const {return 0.5*width*height;}          //定义虚函数
 protected:
  double width,height;                                            //宽与高
};

//输出面积的函数
void printArea(const Shape &s)
{cout<<s.area()<<endl;}                                            //输出s的面积

int main()
{
 Circle circle(12.6);                                             //建立Circle类对象circle
 cout<<"area of circle    =";          
 printArea(circle);                                               //输出circle的面积
 Rectangle rectangle(4.5,8.4);                                    //建立Rectangle类对象rectangle
 cout<<"area of rectangle =";                                     
 printArea(rectangle);                                            //输出rectangle的面积
 Triangle triangle(4.5,8.4);                                      //建立Triangle类对象 
 cout<<"area of triangle  =";
 printArea(triangle);           //输出triangle的面积
 return 0;
}

