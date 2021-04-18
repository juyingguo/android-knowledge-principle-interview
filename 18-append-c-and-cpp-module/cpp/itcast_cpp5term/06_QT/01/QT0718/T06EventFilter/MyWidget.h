#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    QPushButton* _button;
    bool eventFilter(QObject *, QEvent *);
    bool event(QEvent *);

signals:

public slots:

};

#endif // MYWIDGET_H
