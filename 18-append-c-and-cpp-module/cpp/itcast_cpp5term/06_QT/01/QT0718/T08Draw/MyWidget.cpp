#include "MyWidget.h"
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    button = new MyButton("MyButton", this);
    connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));

    button->setGeometry(30, 30, 400, 300);
}

void MyWidget::slotButtonClicked()
{
    qDebug() << "button is clicked";
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    for(int i=0; i<_lines.size(); ++i)
    {
        const QVector<QPoint>& line = _lines.at(i);
        for(int j=0; j<line.size()-1; ++j)
        {
            p.drawLine(line.at(j), line.at(j+1));
        }
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(_lines.size() == 0)
    {
        QVector<QPoint> line;
        _lines.append(line);
    }

    QVector<QPoint>& lastLine = _lines.last();
    lastLine.append(ev->pos());

    update();
}
void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"mousePressEvent";
    QVector<QPoint> line;
    _lines.append(line);

    QVector<QPoint>& lastLine = _lines.last();
    lastLine.append(ev->pos());
}
void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    QVector<QPoint>& lastLine = _lines.last();
    lastLine.append(ev->pos());
}

#include <QApplication>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
