#ifndef MYTOOLBTN_H
#define MYTOOLBTN_H
#include <QToolButton>

class MyToolBtn : public QToolButton
{
public:
    MyToolBtn(QWidget *parent = Q_NULLPTR) : QToolButton(parent){}
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif // MYTOOLBTN_H
