//////////
//1.不再使用导演类
//////////

#include <string>
#include <iostream>
using namespace std;
//car属性类
class Car
{
public:
    void setEngine(string engine){ m_Engine = engine;}
    void setWheel(string wheel){ m_Wheel = wheel;}
    void setBody(string body){ m_Body = body;}
    void disPlay()
    {
        cout<<m_Engine<<" "<<m_Wheel<< " " <<m_Body<<endl;
    }
private:
    string  m_Engine;
    string  m_Wheel;
    string  m_Body;
};
//建造者模式抽象类，组装流程
class Assemble{
public:
    virtual void assembleEngine(){};
    virtual void assembleWheel(){};
    virtual void assembleBody(){};
    virtual Car* buildCar(){ return nullptr;};
};
//a型车组装流程
class AssembleCarA : public Assemble
{
public:
    AssembleCarA(){ _carA = new Car();}
    virtual void assembleEngine( ){ _carA->setEngine("engineA");};
    virtual void assembleWheel( ){ _carA->setWheel("whellA");}
    virtual void assembleBody( ){ _carA->setBody("bodyA");};
    virtual Car* buildCar()
    {
        assembleEngine();
        assembleWheel();
        assembleBody();
        return _carA;
    }
private:
    Car *_carA;
};
//b型车组装流程
class AssembleCarB : public Assemble
{
public:
    AssembleCarB(){ _carB = new Car();}
    virtual void assembleEngine( ){ _carB->setEngine("engineB");};
    virtual void assembleWheel( ){ _carB->setWheel("wheelB");}
    virtual void assembleBody( ){ _carB->setBody("bodyB");};
    virtual Car* buildCar()
    {
        assembleEngine();
        assembleWheel();
        assembleBody();
        return _carB;
    }
private:
    Car *_carB;
};
////工厂类可视为导演类 //不再使用导演类
//class Factory{
//public:
//    Factory(Assemble* assemble){ m_assemble = assemble;}
//    void assembleCar(){
//        m_assemble->assembleEngine();
//        m_assemble->assembleWheel();
//        m_assemble->assembleBody();
//    }
//    Car* buildCar(){return m_assemble->buildCar();}
//private:
//    Assemble* m_assemble;
//};
int main()
{
    Assemble *m_assemble = new AssembleCarA();
//    Factory *m_factory = new Factory(m_assemble);
//    m_factory->assembleCar();
//    m_factory->buildCar()->disPlay();

    Car *car = m_assemble->buildCar();
    car->disPlay();
    return 0;
}
