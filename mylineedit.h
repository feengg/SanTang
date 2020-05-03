#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H
#include <QLineEdit>
#include <QLabel>

class MyLineEdit : public QLineEdit
{
public:
    MyLineEdit(QLabel * label1,QLabel * label2,QWidget * parent = Q_NULLPTR) : QLineEdit(parent),labelRecv(label1)
    ,labelUnder(label2){}
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
private:
    QLabel * labelRecv;
    QLabel * labelUnder;
};

#endif // MYLINEEDIT_H
