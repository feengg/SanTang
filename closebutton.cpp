#include "closebutton.h"


closeButton::closeButton(QWidget * parent):QPushButton(parent)
{
    setStyleSheet("border-image: url(:/images/close_first.png)");
}

void closeButton::enterEvent(QEvent *)
{
    setStyleSheet("border-image: url(:/images/close_after.png)");

}

void closeButton::leaveEvent(QEvent *)
{
    setStyleSheet("border-image: url(:/images/close_first.png)");
}
