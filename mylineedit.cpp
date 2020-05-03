#include "mylineedit.h"
#include <QMouseEvent>
#include <QLabel>

void MyLineEdit::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
        labelRecv->setStyleSheet("color: rgb(42, 117, 255);");
        labelUnder->setStyleSheet("background-color: rgb(0, 0, 0);");
    }
}

void MyLineEdit::mouseMoveEvent(QMouseEvent *event)
{
    if(1)
    {
        labelRecv->setStyleSheet("color: rgb(0, 0, 0);");
        labelUnder->setStyleSheet("background-color: rgb(159, 159, 159);");
    }
}
