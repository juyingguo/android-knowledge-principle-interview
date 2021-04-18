#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    /* widget's event handler (all event) */
    bool event(QEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    /* 不要用 */
   // void mouseDoubleClickEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    void closeEvent(QCloseEvent *);

 //   void showEvent(QShowEvent *);
 //   void hideEvent(QHideEvent *);
    void paintEvent(QPaintEvent *);

    QPushButton* button;
    QLineEdit* edit;

signals:

public slots:
    void slotButtonClicked();

};

#endif // MYWIDGET_H
