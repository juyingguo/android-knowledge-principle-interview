#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout1 = new QHBoxLayout;
    layout2 = new QHBoxLayout;
    //layout3 = new QVBoxLayout(this);
    layout4 = new QGridLayout(this);
    btn1 = new QPushButton;
    edit1 = new QLineEdit;
    edit2 = new QLineEdit;
    edit3 = new QLineEdit;
    label1 = new QLabel;
    label2 = new QLabel;//这个控件没有任何父控件

//    layout1->addWidget(btn1);
//    layout1->addWidget(edit1);
//    layout1->addWidget(edit2);
//    layout1->addWidget(edit3);
//    layout2->addWidget(label1);
//    layout3->addLayout(layout1);
//    layout3->addLayout(layout2);

    edit2->setMaximumWidth(20);

    layout4->addWidget(btn1, 0, 0);
    layout4->addWidget(edit1, 0, 1);
    layout4->addWidget(edit2, 0, 2);
    layout4->addWidget(edit3, 1, 0);
    layout4->addWidget(label1, 1, 2);
    btn1->setText("确定");

    //当点击了btn1的时候就调用on_clicked()这个函数
    connect(btn1, SIGNAL(clicked()), this, SLOT(on_clicked()));//实现控件与具体的槽函数关联
}

Widget::~Widget()
{
    //delete layout1;在QT内部，不需要单独delete一个控件的指针
    //QT的窗口在退出的时候会自动delete他相关的子控件
    delete label2;
}

void Widget::on_clicked()
{
    int a = edit1->text().toInt();
    int b = edit3->text().toInt();
    if (edit2->text() == "+")
        label1->setText(QString::number(a + b));
    if (edit2->text() == "-")
        label1->setText(QString::number(a - b));
    if (edit2->text() == "*")
        label1->setText(QString::number(a * b));
    if (edit2->text() == "/")
    {
        if (b != 0){
            label1->setText(QString::number(a / b));
        }else{
            label1->setText(QString::fromStdString("error divisor is 0."));
        }
    }
}
