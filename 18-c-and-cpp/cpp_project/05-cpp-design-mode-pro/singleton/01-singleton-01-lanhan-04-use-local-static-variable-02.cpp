#include <iostream>

class Singleton
{
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;

//    static Singleton& get_instance(){//good
//        static Singleton instance;
//        return instance;
//
//    }
     static Singleton* get_instance(){ // 这样做并不好，理由主要是无法避免用户使用delete instance导致对象被提前销毁。还是建议大家使用返回引用的方式。
        static Singleton instance;
        return &instance;

    }
private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
};

int main(int argc, char *argv[])
{
    Singleton *instance_1 = Singleton::get_instance();
    std::cout<<"instance_1="<< instance_1<<std::endl;
    delete instance_1;
    Singleton * instance_2 = Singleton::get_instance();
    std::cout<<"instance_1="<< instance_1<<std::endl;
    return 0;
}
