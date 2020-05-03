#include "mytoolbtn.h"


void MyToolBtn::enterEvent(QEvent *)
{
    this->move(this->pos().x(),this->pos().y()-10);
}

void MyToolBtn::leaveEvent(QEvent *)
{
    this->move(this->pos().x(),this->pos().y()+10);
}


