#include <iostream>
#include <cstring>
using namespace std;

/**
1. C++��const�ؼ��ֵ�ʹ���ܽ�
    https://www.cnblogs.com/gklovexixi/p/5619647.html
2. C++ const���κ�����������������������ֵ
    https://blog.csdn.net/my_mao/article/details/22872149

*/

class Shape {
   private:
      int width, height;
      char * name;
   public:
       void setWidth(int w);
       int getWidth() const;

        //const ���κ�����
//       int getWidth() const{
////         width = width + width;
//        return width;
//       }

       //const ���κ������û�ָ�����͵ķ���ֵ
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
const ���κ�����
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

