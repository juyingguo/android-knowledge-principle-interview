#include <iostream>
#include <string.h>

using namespace std;

// Ahthor:    ��������
// E-mail:    wyphao.2007@163.com
// Blog:    http://www.iteblog.com
// ת����ע������

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

size_t TestClass::length() const{ //���������const
    if(!lengthIsValid){
        contentLength= strlen(pContent);     //C   ���һ��Ҫ���ʱ�������Ҫ�ӹؼ���mutable
        lengthIsValid = true;               //D     ���һ��Ҫ���ʱ�������Ҫ�ӹؼ���mutable
    }

    return contentLength;
}

const char* TestClass::getPContent(){//������ǰ��const
    return pContent;
}

void TestClass::setPContent(const char *s){//������ǰ��const

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
