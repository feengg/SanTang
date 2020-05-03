#include "maxbutton.h"

maxButton::maxButton(QWidget * parent):QPushButton(parent)
{
    setStyleSheet("border-image: url(:/images/max-min_first.png)");

}

void maxButton::enterEvent(QEvent *)
{
    setStyleSheet("border-image: url(:/images/max-min_after.png)");
    /*
    if(Widget::Width == Widget::maxWidth)
    {
        setStyleSheet("border-image: url(:/images/max_after.png)");
    }
    */
}

void maxButton::leaveEvent(QEvent *)
{
    setStyleSheet("border-image: url(:/images/max-min_first.png)");
    /*
    if(Widget::Width == Widget::maxWidth)
    {
        setStyleSheet("border-image: url(:/images/max_after_first.png)");
    }
    */
}
