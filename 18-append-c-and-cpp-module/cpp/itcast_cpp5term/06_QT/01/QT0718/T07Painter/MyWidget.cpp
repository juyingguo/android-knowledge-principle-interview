#include "MyWidget.h"
#include <QPainter>
#include <QPixmap>
#include <QBrush>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPixmap pixmap(size());

    QPainter p(&pixmap);
    pixmap.fill(Qt::green);

    //QPainter使用带有QPixmap的构造函数时，设置背景无效
//    QBrush qbrush(Qt::GlobalColor::green);
//    p.setBackground(qbrush)//修改背景颜色

    #if 0
     //   p.translate(100, 100);
        //p.scale();
        p.setRenderHint(QPainter::Antialiasing);
        QTransform transform;
        transform.translate(50,50);
        transform.rotate(30);
       // transform.scale(.5, .5);
        p.setTransform(transform);

        QTransform transform2;
        transform2.scale(.5, .5);
        p.setTransform(transform2, true);
    #endif

    p.drawLine(QPoint(0, 0), QPoint(100, 100));

 //   p.translate(-100, -100);
    p.setPen(QPen(Qt::red, 2, Qt::DashLine));
    p.setBrush(Qt::yellow);
    p.setBrush(QBrush(Qt::GlobalColor::yellow));
    p.setFont(QFont("aaa", 40, 700, true));

    p.drawEllipse(QPoint(95, 333), 50, 100);
    p.drawText(QPoint(300, 50), "Hello world");
 //   p.drawPixmap(QPoint(40, 40), QPixmap("../aaa.png"));
  //  p.drawRect(QRect(40, 60, 100, 50));
    p.drawRoundRect(QRect(40, 60, 100, 50));

    p.end();

    p.begin(this);
    p.drawPixmap(50, 0, pixmap);

}

#include <QApplication>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
