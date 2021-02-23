//Builder.cpp
#include "Builder.h"
#include "Product.h"
#include <iostream>
using namespace std;
Builder::Builder()
{
}
Builder::~Builder()
{
}
ConcreteBuilder::ConcreteBuilder()
{
}
ConcreteBuilder::~ConcreteBuilder()
{
}
void ConcreteBuilder::BuildPartA(const string& buildPara)
{
    cout<<"Step1:BuildPartA..."<<buildPara<<endl;
}
void ConcreteBuilder::BuildPartB(const string& buildPara)
{
    cout<<"Step1:BuildPartB..."<<buildPara<<endl;
}
void ConcreteBuilder::BuildPartC(const string& buildPara)
{
    cout<<"Step1:BuildPartC..."<<buildPara<<endl;
}
Product* ConcreteBuilder::GetProduct()
{
    BuildPartA("pre-defined");
    BuildPartB("pre-defined");
    BuildPartC("pre-defined");
    return new Product();
}
