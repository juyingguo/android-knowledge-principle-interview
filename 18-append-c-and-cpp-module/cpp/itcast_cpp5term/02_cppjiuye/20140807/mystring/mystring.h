#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

//一个单例的能够动态分配内存的字符串
class mystring
{
private:
    static mystring *self;
    char *s;
public:
    static mystring *makestring(const char *s = NULL);
    static void deletestring();

    ~mystring();
    const char *get_s() const;
    void set_s(const char *s);

    mystring();
    mystring(const char *s);
    mystring(const mystring &it);

protected:


};

#endif // MYSTRING_H
