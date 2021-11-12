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
     static Singleton* get_instance(){ // �����������ã�������Ҫ���޷������û�ʹ��delete instance���¶�����ǰ���١����ǽ�����ʹ�÷������õķ�ʽ��
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
