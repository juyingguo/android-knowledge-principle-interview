#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "MyButton.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    MyButton* button;

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    QVector< QVector<QPoint> > _lines;

signals:

public slots:
    void slotButtonClicked();
};

#endif // MYWIDGET_H
