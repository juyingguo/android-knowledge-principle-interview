#include "mystring.h"
#include <iostream>
#include <string.h>

mystring *mystring::self = NULL;

mystring *mystring::makestring(const char *s)
{
    if (self == NULL)
    {
        if (s == NULL)
            self = new mystring;
        else
            self = new mystring(s);
    }

    return self;
}

void mystring::deletestring()
{
    if (self != NULL)
    {
        delete self;
        self = NULL;//释放指针之后，赋值NULL，这样就可以再次建立类的实例
    }
}

mystring::mystring(): s(NULL)
{

}

mystring::mystring(const char *s)
{
    int len = strlen(s);
    this->s = new char[len + 1];
    strcpy(this->s, s);
    this->s[len] = 0;
}

mystring::mystring(const mystring &it)//通过拷贝构造实现深拷贝，避免成员变量指针赋值导致的错误
{
    int len = strlen(it.get_s());
    this->s = new char[len + 1];
    strcpy(this->s, it.s);
    this->s[len] = 0;
}

mystring::~mystring()
{
    delete []s;//将构造函数分配的内存释放
}

const char *mystring::get_s() const
{
    return s;
}

void mystring::set_s(const char *s)
{
    if (this->s == NULL)
    {
        int len = strlen(s);
        this->s = new char[len + 1];
        strcpy(this->s, s);
        this->s[len] = 0;
    }else
    {
        int len1 = strlen(this->s);
        int len2 = strlen(s);

        if (len1 > len2)
        {
            strcpy(this->s, s);
            this->s[strlen(s)] = 0;
        }else
        {
            delete []this->s;//由于成员变量s的空间不够了，所以不要了
            this->s = new char[len2 + 1];//重新给成员变量s分配新空间
            strcpy(this->s, s);//给新空间赋值
            this->s[len2] = 0;//新空间最后一个字节为字符串结束标示符0
        }
    }
}
