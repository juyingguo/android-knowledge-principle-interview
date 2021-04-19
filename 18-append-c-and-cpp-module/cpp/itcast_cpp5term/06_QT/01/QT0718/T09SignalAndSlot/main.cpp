

#include <QCoreApplication>
#include "mysignal.h"
#include "myslot.h"

/*
1) 信号的定义必须在signals:保留字下，并且不需要实现
2）槽的定义必须在slots:保留字下，需要实现
3）信号和槽通过QObject::connect函数连接
4）当信号被触发时，槽函数被调用

需要注意的是：
1）信号和槽，是QT的拓展，所以实现信号和槽的类，必须是QObject的子类
2）实现信号和槽的类，必须以宏Q_OBJECT开始
3）连接信号和槽，要用到SIGNAL和SLOT宏，转换函数为字符串
4）一个信号可以和多个槽连接，槽函数调用的顺序是不确定的
5）多个信号可以同时连接一个槽
6）信号可以连接信号，形成信号传导
7）信号和槽的参数应该一样多，而且类型必须相同
8）信号和槽都可以重载
9）信号和槽都可以有默认参数
10）槽函数可以像普通函数一样被调用
11）在槽函数中，调用sender可以获得信号调用者

总结下：
一个类：QObject
三个宏：Q_OBJECT SIGNAL SLOT
三个保留字：signals, slots, emit
*/

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    MySignal sig;
    MySlot slot;

    QObject::connect(&sig, SIGNAL(sig()), &slot, SLOT(slot()));

    emit sig.sig();

    return app.exec();
}
