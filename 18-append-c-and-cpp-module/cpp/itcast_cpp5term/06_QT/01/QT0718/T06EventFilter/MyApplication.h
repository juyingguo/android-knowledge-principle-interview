#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>

class MyApplication : public QApplication
{
    Q_OBJECT
public:

    MyApplication(int argc, char*argv[]):QApplication(argc, argv)
    {}
    bool notify(QObject *, QEvent *);

signals:

public slots:

};

#endif // MYAPPLICATION_H
