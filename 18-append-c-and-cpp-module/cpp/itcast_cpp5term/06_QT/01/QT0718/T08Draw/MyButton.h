#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
    MyButton(const QString& text, QWidget* parent = 0);

    QRect _rect;
    QString _text;
    bool _pressed;
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void paintEvent(QPaintEvent *);

signals:
    void clicked();

public slots:

};

#endif // MYBUTTON_H
