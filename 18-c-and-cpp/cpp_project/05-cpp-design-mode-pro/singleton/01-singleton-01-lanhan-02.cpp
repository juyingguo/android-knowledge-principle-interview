#include <iostream>
// version1:
// with problems below:
// 1. thread is not safe
// 2. memory leak

class Singleton{
private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton* m_instance_ptr;
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
//        m_instance_ptr = nullptr;
    }
    static Singleton* get_instance(){
        if(m_instance_ptr==nullptr){
              m_instance_ptr = new Singleton();
        }
        return m_instance_ptr;
    }
    void use() const { std::cout << "in use current object address:"<< this << std::endl; }
};
Singleton* Singleton::m_instance_ptr = nullptr;

int main(){
    Singleton* instance = Singleton::get_instance();
    Singleton* instance_2 = Singleton::get_instance();

    instance->use();
    instance_2->use();
//    delete instance;
//    instance = nullptr;

//    Singleton Singleton3(instance);
    std::cout<<"&instance_2 = "<<instance_2<<std::endl;
//    if(instance_2 != nullptr)
//        delete instance_2;

//    Singleton s1;//实际调用Singleton::Singleton()，如果还私有类型，会提示错误的。
    return 0;
}
