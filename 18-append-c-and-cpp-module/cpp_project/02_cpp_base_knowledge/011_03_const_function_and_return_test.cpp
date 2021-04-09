/*
 * FunctionConst.cpp
 */
#include <iostream>
#include <stdio.h>
//#include "FunctionConst.h"

using namespace std;
class FunctionConst {
public:
    int value;
    FunctionConst();
    virtual ~FunctionConst();
    const int getValue();
    int getValue2() const;
};

FunctionConst::FunctionConst():value(100) {
    // TODO Auto-generated constructor stub
    cout << "FunctionConst()" << endl ;
}

FunctionConst::~FunctionConst() {
    // TODO Auto-generated destructor stub
}

const int FunctionConst::getValue(){
    return value;//返回值是 const, 使用指针时很有用.
}

int FunctionConst::getValue2() const{
    //此函数不能修改class FunctionConst的成员函数 value
//    value = 15;//错误的, 因为函数后面加 const
    return value;
}
int main()
{
    FunctionConst *fc = new FunctionConst();
    const int v = fc->getValue();
    printf("fc->getValue = %d.\n",v);
    cout << "fc.getValue() = " << fc->getValue() << endl;
    return 0;
}
