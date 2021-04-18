#include "myslot.h"
#include <QDebug>

MySlot::MySlot(QObject *parent) :
    QObject(parent)
{
}

void MySlot::slot()
{
    qDebug() << "MySlot::slot is called";
}
