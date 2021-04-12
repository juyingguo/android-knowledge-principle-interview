#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class mystring
{
public:
    char *s;
public:
    mystring()
    {
        s = new char[1024];
        cout << "mystring" << endl;
    }
    /**
     * 深拷贝构造函数
     * @brief mystring
     * @param it
     */
    mystring(const mystring &it)//深拷贝
    {
        cout << "copy mystring" << endl;
        s = new char[1024];
        memset(s, 0, 1024);
        strcpy(s, it.s);
    }

    ~mystring()
    {
        cout << "~mystring" << endl;
        delete []s;
    }

    mystring operator =(const mystring &it)//重载了一个=号操作符
    {
        cout << "= operator,(mystring)" << endl;
        memset(s, 0, 1024);
        strcpy(s, it.s);
        return *this;
    }

    mystring operator =(const char *str)//重载了一个=号操作符
    {
        cout << "= operator,(char*)" << endl;
        memset(s, 0, 1024);
        strcpy(s, str);
        return *this;
    }

    mystring operator =(int i)//重载了一个=号操作符
    {
        memset(s, 0, 1024);
        sprintf(s, "%d", i);
        return *this;
    }

    mystring operator + (const mystring &it)//重载了一个+号操作符
    {
        strcat(s, it.s);
        return *this;
    }

    mystring operator + (const char *str)//重载了一个+号操作符
    {
        strcat(s, str);
        return *this;
    }

    void operator +=(const char *str)//
    {
        strcat(this->s, str);
    }

    mystring operator + (int i)//重载了一个+号操作符,一元操作符重载
    {
        char temp[100] = {0};
        sprintf(temp, "%d", i);
        strcat(s, temp);
        return *this;
    }
    void operator <<(const char *str)//把<<操作符定义为赋值
    {
        strcpy(s, str);
    }

    void operator >>(char *str)//把<<操作符定义为赋值
    {
        strcpy(str, s);
    }

    mystring operator ++(int)//重载++操作符的函数int参数是固定
    {
        int len = strlen(s);
        for(int i = 0;i < len; i++)
        {
            s[i]++;//让s的第一个成员char + 1,就是将s[0]对应字符的ASCII码 + 1
        }
        return *this;
    }

    void * operator new(size_t size)//如果重载的new，那么必须重载delete
    {
        //参数size就是sizeof(mystring)的大小.
        cout << "size = " << size << endl;
        mystring *p = (mystring *)malloc(size);
        return p;
    }

    void * operator new[](size_t size)//如果重载的new，那么必须重载delete
    {
        //参数size就是sizeof(mystring)的大小 * new[x] + 4个字节.
        cout << "size = " << size << endl;
        //mystring *p = (mystring *)malloc(size);
        return NULL;
    }

    void operator delete[](void *obj)
    {
        free((mystring *)obj);
        obj = NULL;
    }

    void operator delete(void *obj)
    {
        free((mystring *)obj);//不能直接free一个void *；
        obj = NULL;//防止野指针
    }

    bool operator ==(const mystring &it)
    {
        if (strcmp(s, it.s) == 0)//如果this->s和it的s相同,就返回true
        {
            return true;
        }else
            return false;
    }

    bool operator ==(const char *str)
    {
        if (strcmp(s, str) == 0)//如果this->s和it的s相同,就返回true
        {
            return true;
        }else
            return false;
    }

    //如果返回的是char，代表的是一个右值，右值是不能直接赋值的，
    //如果返回的是char的引用，那么[]就可以当左值使用了
    char &operator[](int index)
    {
        return s[index];
    }

    void operator ()(const char *str)//重载函数调用操作符
    {
        strcpy(s, str);
    }

    void operator ()(int i)
    {
        sprintf(s, "%d", i);
    }

    operator int()
    {
        return atoi(s);
    }

    //类的外部使用，加上有元才可以访问私有成员。
    friend mystring operator +(const char *str, const mystring &it);

};

bool operator ==(const char *str, const mystring &it)
{
    if (strcmp(str, it.s) == 0)
    {
        return true;
    }else
        return false;
}

/**
 * 操作符重载，有一个最基本条件，就是一定有一个一元是一个自定义的C++类
 * 如果两个都是基本数据类型操作符重载是非法的
 * @brief operator +
 * @param str
 * @param it
 * @return
 */
mystring operator +(const char *str, const mystring &it)
{
    cout << "out class operator +" << endl;
    mystring str1;
    char buf[1024] = {0};
    sprintf(buf, "%s%s", str, it.s);
    strcpy(str1.s, buf);
    return str1;
}

mystring operator ++(mystring &it)
{
    int len = strlen(it.s);
    for(int i = 0;i < len; i++)
    {
        it.s[i]++;//让s的第一个成员char + 1,就是将s[0]对应字符的ASCII码 + 1
    }
    return it;
}

mystring operator +(int i, const mystring &it)
{
    mystring str1;
    char buf[1024] = {0};
    sprintf(buf, "%d%s", i, it.s);
    strcpy(str1.s, buf);
    return str1;
}

class demo
{
public:
    demo()
    {

    }
};

void test(int i)
{
    cout << i << endl;
}

int main05()
{
//    mystring str;
//    str << "123";

//    test(str);//导致C++编译器自动的配备int（）操作符

    mystring *p = new mystring;
    delete p;

//    mystring *p = (mystring *)malloc(sizeof(mystring));
//    free(p);


    return 0;
}


int main04()
{
    mystring str1;
    str1 << "hello";
    mystring str2;
    str2 << "hello";

    if ("hello" == str1)
    {
        cout << "true" << endl;
    }else
    {
        cout << "fasle" << endl;
    }

    str1[2] = 'a';

    //str1("aaaaaaaa");
    str1(10);

    cout << str1.s << endl;




    return 0;

}

int main()
{
    cout << "mystring size =" << sizeof(mystring) << endl;
    mystring str1;
    str1 =  "hello";//也会执行拷贝构造函数
//    mystring str2;
//    str2 = " world";
//    mystring str3 = str1;
    //str3 = str1 + str2;//对C++编译器来讲，不能识别两个类+是什么含义
    //str3 = str1 + "aaaaaaaaaaaa";
    //str3 = str1 + 100;
//    str3 = "AAAAA" + str1;
//    str3 = 100 + str1;
//    str3 += "BBBBBB";
//    str3 << "CCCCC";
//    char buf[1024] = {0};
//    str3 >> buf;
//    str2 = str3++;
//    str2 = ++str3;

//    mystring *pstr = new mystring;
//    delete pstr;

//    cout << str3.s << endl;
    return 0;
}


int main01()
{
    mystring str1;
    strcpy(str1.s, "hello world");
    mystring str2;
//    mystring str2 = str1;//此时直接调用拷贝构造函数
    str2 = str1;//这个过程不是拷贝构造的过程，只是=号操作。会调用拷贝构造及重载=函数
    //str2.operator =(str1);//和直接写=号是一摸一样的

    cout << str2.s << endl;

//    str2 = "test";//C++编译器不能理解把一个字符串赋给一个类是什么含义

//    mystring str3;

//    str3 = str2 = 100;
//    //str3 = str2.operator =(100);//上一条语句的等效语法

//    cout << str2.s << endl;

    return 0;
}



