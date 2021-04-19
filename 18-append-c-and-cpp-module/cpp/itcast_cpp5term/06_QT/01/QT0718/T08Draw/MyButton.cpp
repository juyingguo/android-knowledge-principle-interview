#include "MyButton.h"
#include <QPainter>
#include <QMouseEvent>
MyButton::MyButton(QWidget *parent) :
    QWidget(parent), _rect(0, 0, 100, 30), _text(QString())
{
    _pressed = false;
    this->setGeometry(_rect);
}

MyButton::MyButton(const QString &text, QWidget *parent):
    QWidget(parent), _text(text), _rect(0, 0, 100, 30)
{
    _pressed = false;
    this->setGeometry(_rect);
}

void MyButton::mousePressEvent(QMouseEvent *)
{
    _pressed = true;
    update();
}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    _pressed = false;
    update();

    if(_rect.contains(ev->pos()))
        emit clicked();
    // callback handler
}
void MyButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if(_pressed)
        p.setBrush(Qt::yellow);
    else
        p.setBrush(Qt::darkGray);
    p.drawRect(_rect);
    p.drawText(_rect, _text, QTextOption(Qt::AlignCenter));
}
