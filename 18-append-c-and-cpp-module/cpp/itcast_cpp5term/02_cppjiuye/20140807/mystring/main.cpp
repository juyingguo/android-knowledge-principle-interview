#include <iostream>
#include <string.h>
#include "mystring.h"

using namespace std;

int main()
{
//    mystring str1("hello world");
//    mystring str2 = str1;
//    str3.set_s("SDFSD");
//    cout << str1.get_s() << endl;
    //mystring *str1 = mystring::makestring();//默认调用的是NULL

    mystring *str1 = mystring::makestring("hello world");//默认调用的是NULL

    cout << str1->get_s() << endl;

    mystring::deletestring();

    mystring *str3 = mystring::makestring("abcdefg");

    cout << str3->get_s() << endl;
    cout << strlen(str3->get_s()) << endl;
    cout << str3->get_s()[0] << endl;
    cout << str3->get_s()[1] << endl;

    const mystring str4("hello baby");
    cout << "str4 = " << str4.get_s() << endl;
    return 0;
}

