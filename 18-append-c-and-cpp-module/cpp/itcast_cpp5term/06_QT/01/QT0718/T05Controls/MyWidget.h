#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTextEdit>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    QTextEdit* _edit;

signals:

public slots:
    void slotComboBoxIndexChanged(const QString&);
};

#endif // MYWIDGET_H
