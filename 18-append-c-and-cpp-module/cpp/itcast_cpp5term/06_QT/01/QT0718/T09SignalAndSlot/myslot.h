#ifndef MYSLOT_H
#define MYSLOT_H

#include <QObject>

class MySlot : public QObject
{
    Q_OBJECT
public:
    explicit MySlot(QObject *parent = 0);

signals:

public slots:
    void slot();

};

#endif // MYSLOT_H
