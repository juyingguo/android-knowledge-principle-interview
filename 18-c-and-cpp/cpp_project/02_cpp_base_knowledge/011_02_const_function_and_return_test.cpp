#include <iostream>
#include <cstring>
using namespace std;

/**
1. C++中const关键字的使用总结
    https://www.cnblogs.com/gklovexixi/p/5619647.html
2. C++ const修饰函数、函数参数、函数返回值
    https://blog.csdn.net/my_mao/article/details/22872149

*/

class Shape {
   private:
      int width, height;
      char * name;
   public:
       void setWidth(int w);
       int getWidth() const;

        //const 修饰函数。
//       int getWidth() const{
////         width = width + width;
//        return width;
//       }

       //const 修饰函数引用或指针类型的返回值
       int const & getWidth2() {
        return width;
       }

       /**
        const decorate printer parameter
       */
       void printName(/*const*/ char  * /*const*/ pName){

           cout<< "pName str length:" <<  strlen(pName)<<endl;
//           *pName = 'p';

            //pName = "test 123";

           cout<<pName<<endl;
       }

       char* getName(char *pName){

           return pName;
       }

};
void Shape::setWidth(int w){

    width = w;
}
/**
const 修饰函数。
*/
int Shape::getWidth() const{

    return width;
}
int main()
{
   Shape shape;
   shape.setWidth(4);
   cout<<shape.getWidth()<<endl;

//   shape.getWidth2() = 5;

   cout<<shape.getWidth()<<endl;

//   char  /*const*/ * /*const*/ test = "test";
   char *test = "test";


//   test = "test abc";

   shape.printName(test);


   char /*const*/ greeting[] = "Hello";// const decorate content ,can not modify content.
    cout<<greeting<<endl;
   greeting[0] = 'h';
    cout<<greeting<<endl;

//    char *p = greeting; //
//    char const *p = greeting;
//    char  * const p = greeting;
    char const * const p = greeting;

    *(p) = 'E';// verify test can't modify content ,for const or not const printer;

    cout<<greeting<<endl;


   return 0;
}

