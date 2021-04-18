#include "MyWidget.h"
#include <QApplication>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QPainter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
//    QVBoxLayout* lay = new QVBoxLayout(this);
    QVBoxLayout*lay =new QVBoxLayout();
  //  this->setLayout(lay);
#if 0
    QPushButton* button2;
    lay->addWidget(button = new QPushButton("OK", this));
    lay->addWidget(button2 = new QPushButton("Button2"));

    button->setDefault(true);

    //不需要按下，mouseMove就能得到调用
    this->setMouseTracking(true);

    connect(button2, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
    connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
#endif
//    lay->addWidget(edit = new QLineEdit());
//    connect(edit, SIGNAL(returnPressed()), this, SLOT(slotButtonClicked()));
}

void MyWidget::slotButtonClicked()
{
    QLineEdit* button = (QLineEdit*)sender();
    qDebug() << button->text();
}
/* QApplication先得到->具体应该处理的窗口::event()->event()据消息类型来调用具体的虚函数 */
/* 1）可以重载具体的虚函数，来实现对消息的响应
   2）可以重载event函数，用来处理或者截取消息 */

/* 截取消息 */
bool MyWidget::event(QEvent *ev)
{
    //消息被截断
//    if(ev->type() == QEvent::MouseButtonPress)
//        return true;
    ev->accept();
//    if(1) return true;

    return QWidget::event(ev);
}
void MyWidget::closeEvent(QCloseEvent *)
{
    qDebug() << "closeEvent";
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawLine(QPoint(0, 0), QPoint(100, 100));

}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
#if 0
    QPoint pt = ev->pos();
    qDebug() << pt;
    if(ev->button() == Qt::LeftButton)
    {

    }
    if(ev->modifiers() == Qt::ShiftModifier)
    {
        qDebug() << "shift press";
    }
#endif
    if(ev->button() == Qt::LeftButton)
    {
        if(ev->modifiers() == Qt::ControlModifier)
        {
            // handle with Control;
            qDebug() << "mousePressEvent() LeftButton and ctrl.";
            return;
        }

        // handle2 without control;
    }
    else
    {

    }
}
void MyWidget::mouseReleaseEvent(QMouseEvent *)
{}
void MyWidget::mouseMoveEvent(QMouseEvent *)
{
    static int i=0;
    qDebug() << "mouse move"<< i++;
}

void MyWidget::keyPressEvent(QKeyEvent *ev)
{
    ev->modifiers();
    int key = ev->key();
    qDebug() << key;
    char a = key;
    qDebug() << (char)a;
}

void MyWidget::keyReleaseEvent(QKeyEvent *)
{}


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
