
/* 应用程序抽象类 */
#include <QApplication>

/*窗口类*/
#include <QWidget>
#include <QCompleter>
#include <QLineEdit>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    /* 构造一个窗口*/
    QWidget w;

    QLineEdit edit;
    edit.show();
    edit.setParent(&w);

    /* 输入密码 */
  //  edit.setEchoMode(QLineEdit::PasswordEchoOnEdit);
   // edit.text();
  //  edit.setPlaceholderText("Please input text:");

    QCompleter completer(QStringList() << "aab" << "123" << "998");
    completer.setFilterMode(Qt::MatchContains);
    edit.setCompleter(&completer);

    /*显示窗口*/
    w.show();

    /* QT对C++的拓展 */
    // std::bind std::function
  //  QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));

    w.setWindowTitle("Hello World");

    /*在exec中有一个消息循环*/
    return app.exec();
}
