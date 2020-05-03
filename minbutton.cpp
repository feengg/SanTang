#include "minbutton.h"

minButton::minButton(QWidget * parent):QPushButton(parent)
{
    setStyleSheet("border-image: url(:/images/min_first.png)");
}

void minButton::enterEvent(QEvent *)
{
    setStyleSheet("border-image: url(:/images/min_after.png)");

}

void minButton::leaveEvent(QEvent *)
{
    setStyleSheet("border-image: url(:/images/min_first.png)");
}
