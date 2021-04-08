#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int a = ui->lineEdit->text().toInt();//
    QString str2 = ui->lineEdit_2->text();

    int b = ui->lineEdit_3->text().toInt();
    const char *s = str2.toStdString().data();//将QString内部的char *挖出来
    printf("s = %s\n.",s);
    char c1 = s[0];


    int c = 0;
    if (str2 == "+")
        c = a + b;

    if (str2 == "-")
        c = a - b;

    if (str2 == "*")
        c = a * b;

    if (str2 == "/")
    {
        if (b != 0)
            c = a / b;
    }

    ui->label->setText(QString::number(c));
}
