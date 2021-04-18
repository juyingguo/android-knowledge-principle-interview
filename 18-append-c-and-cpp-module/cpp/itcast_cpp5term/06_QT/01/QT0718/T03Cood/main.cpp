
/* 应用程序抽象类 */
#include <QApplication>

/*窗口类*/
#include <QWidget>

/* 按钮 */
#include <QPushButton>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    /* 构造一个窗口*/
    QWidget w;

    /*显示窗口*/
    w.show();

    /* 按钮也是个窗口 */
    QPushButton button;
    button.setText("Button");
    /* 窗口对象的父子关系，影响显示位置 */
    /* 没有父窗口的窗口，我们称之为主窗口 */
    button.setParent(&w);
    button.show();

    button.setGeometry(30, 30, 100, 30);

    /* QT对C++的拓展 */
    // std::bind std::function
    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));

    w.setWindowTitle("Hello World");

    /*在exec中有一个消息循环*/
    return app.exec();
}

