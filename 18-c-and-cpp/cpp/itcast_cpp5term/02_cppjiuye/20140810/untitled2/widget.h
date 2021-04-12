#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *btn1;
    QHBoxLayout *layout1, *layout2;
    QVBoxLayout *layout3;
    QGridLayout *layout4;
    QLineEdit *edit1, *edit2, *edit3;
    QLabel *label1;
    QLabel *label2;

private slots:
    void on_clicked();
};

#endif // WIDGET_H
