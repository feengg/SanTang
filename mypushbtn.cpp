#include "mypushbtn.h"

MyPushBtn::MyPushBtn(QGroupBox * groupbox,QString text,QString tip,int maxWidth,int minWidth,int minHeight,QString color,QWidget * parent) : QPushButton(parent)
{
    groupBox = groupbox;
    setBtnStyleSheet(btnStyle);
    this->setToolTip(tip);
    this->setMaximumWidth(maxWidth);
    this->setMinimumWidth(minWidth);
    this->setMaximumHeight(minHeight);
    this->setText(text);
    if(color == "red")
    {
        btnStyle += "color:red;";
        setBtnStyleSheet(btnStyle);
    }
    if(color == "blue")
    {
        btnStyle += "color:blue;";
        setBtnStyleSheet(btnStyle);
    }
}

void MyPushBtn::enterEvent(QEvent *)
{
    groupBox->setStyleSheet(groupBoxEnterStyle);
}
void MyPushBtn::leaveEvent(QEvent *)
{
    groupBox->setStyleSheet(groupBoxLeaveStyle);
}

void MyPushBtn::setBtnStyleSheet(QString style)
{
    this->setStyleSheet(style);
}

void MyPushBtn::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        emit sendDoubleClickedToolTipSig(this->toolTip());
    }
}
