#include "MyApplication.h"
#include <QEvent>

#include <QDebug>
bool MyApplication::notify(QObject *o, QEvent *e)
{
    if(this->topLevelWidgets().count()>0)
    {
        QWidget* mainWnd = this->topLevelWidgets().at(0);
        if(o==(QObject*)mainWnd && e->type() == QEvent::MouseButtonPress)
        {
            // do ...
            qDebug() << "mainwnd is clicked";
        }
    }

    return QApplication::notify(o, e);
}
