// Director.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Builder

{

public:
    virtual void BuildHead() {}
    virtual void BuildBody() {}
    virtual void BuildLeftArm(){}
    virtual void BuildRightArm() {}
    virtual void BuildLeftLeg() {}
    virtual void BuildRightLeg() {}
};

//构造瘦人

class ThinBuilder : public Builder
{
public:
    void BuildHead() { cout<<"build thin body"<<endl; }
    void BuildBody() { cout<<"build thin head"<<endl; }
    void BuildLeftArm() { cout<<"build thin leftarm"<<endl; }
    void BuildRightArm() { cout<<"build thin rightarm"<<endl; }
    void BuildLeftLeg() { cout<<"build thin leftleg"<<endl; }
    void BuildRightLeg() { cout<<"build thin rightleg"<<endl; }

};

//构造胖人
class FatBuilder : public Builder
{
public:
    void BuildHead() { cout<<"build fat body"<<endl; }
    void BuildBody() { cout<<"build fat head"<<endl; }
    void BuildLeftArm() { cout<<"build fat leftarm"<<endl; }
    void BuildRightArm() { cout<<"build fat rightarm"<<endl; }
    void BuildLeftLeg() { cout<<"build fat leftleg"<<endl; }
    void BuildRightLeg() { cout<<"build fat rightleg"<<endl; }
};

//构造的指挥官
class Director
{
private:
    Builder *m_pBuilder;
public:
    Director(Builder *builder) { m_pBuilder = builder; }
    void Create(){
        m_pBuilder->BuildHead();
        m_pBuilder->BuildBody();
        m_pBuilder->BuildLeftArm();
        m_pBuilder->BuildRightArm();
        m_pBuilder->BuildLeftLeg();
        m_pBuilder->BuildRightLeg();
    }
};
int main(int argc)
{
    FatBuilder *fat = new FatBuilder();
    Director *director = new Director(fat);
    director->Create();
    system("pause");
    return 0;
}
