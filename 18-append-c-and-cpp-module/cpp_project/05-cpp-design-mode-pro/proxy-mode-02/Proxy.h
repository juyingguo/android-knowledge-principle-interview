//Proxy.h
#ifndef _PROXY_H_
#define _PROXY_H_
class Subject
{
    public:
        virtual ~Subject();
        virtual void Request() = 0;
    protected:
        virtual Subject();
    private:
};
class ConcreteSubject:public Subject
{
    public:
        ConcreteSubject();
        ~ConcreteSubject();
        void Request();
    protected:
    private:
};
class Proxy :public Subject
{
    public:
        Proxy();
        Proxy(Subject* sub);
        ~Proxy();
        void Request();
    protected:
    private:
        Subject* _sub;
};
#endif //~_PROXY_H_
