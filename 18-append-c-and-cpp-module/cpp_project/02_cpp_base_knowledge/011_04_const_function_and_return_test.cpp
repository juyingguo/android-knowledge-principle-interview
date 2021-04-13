#include <iostream>
#include <string.h>

using namespace std;

// Ahthor:    过往记忆
// E-mail:    wyphao.2007@163.com
// Blog:    http://www.iteblog.com
// 转载请注明出处

class TestClass {
public:
    size_t length() const;
    const char* getPContent();
    void setPContent(const char *);
    void setLengthValid(bool isLengthValid);
private:
    char *pContent;
    mutable size_t contentLength;          //A
    mutable  bool lengthIsValid;          //B
     size_t precontentLength;
};

size_t TestClass::length() const{ //函数名后加const
    if(!lengthIsValid){
        contentLength= strlen(pContent);     //C   如果一定要访问变量，需要加关键字mutable
        lengthIsValid = true;               //D     如果一定要访问变量，需要加关键字mutable
    }

    return contentLength;
}

const char* TestClass::getPContent(){//函数名前加const
    return pContent;
}

void TestClass::setPContent(const char *s){//函数名前加const

    int len = strlen(s);
    this->pContent = new char[len + 1];
    strcpy(this->pContent, s);
    this->pContent[len] = 0;
}
void TestClass::setLengthValid(bool isLengthValid){
    lengthIsValid = isLengthValid;
}

int main(void){
    TestClass *tc =new TestClass;
    tc->setLengthValid(false);
    tc->length();
    tc->setPContent("haha");
    const char * content = tc->getPContent();          //E
    cout << "content= " <<content <<endl;
    return 0;
}
