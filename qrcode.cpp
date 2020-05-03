#include "qrcode.h"
#include "ui_qrcode.h"
#include "qrcode/qrencode.h"
#include <QPainter>
#include <QDebug>

Qrcode::Qrcode(QString showString,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qrcode)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("二维码");

    QString tempstr = showString;
    QRcode *qrcode;
    qrcode=QRcode_encodeString(tempstr.toStdString().c_str(),2,QR_ECLEVEL_Q,QR_MODE_8,1);
    qint32 temp_width=ui->label->width();
    qint32 temp_height=ui->label->height();
    qDebug()<<"temp_width="<<temp_width<<";temp_height="<<temp_height;
    qint32 qrcode_width=qrcode->width>0?qrcode->width:1;
    double scale_x=(double)temp_width/(double)qrcode_width;
    double scale_y=(double)temp_height/(double)qrcode_width;
    QImage mainimg=QImage(temp_width,temp_height,QImage::Format_ARGB32);
    QPainter painter(&mainimg);
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,0,temp_width,temp_height);
    QColor foreground(Qt::black);
    painter.setBrush(foreground);
    for(qint32 y=0;y<qrcode_width;y++)
    {
        for(qint32 x=0;x<qrcode_width;x++)
        {
            unsigned char b=qrcode->data[y*qrcode_width+x];
            if(b &0x01)
            {
                QRectF r(x*scale_x,y*scale_y,scale_x,scale_y);
                painter.drawRects(&r,1);
            }
        }
    }
    QPixmap mainmap=QPixmap::fromImage(mainimg);
    ui->label->setPixmap(mainmap);
    ui->label->show();
    ui->label->setVisible(true);
}

Qrcode::~Qrcode()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void Qrcode::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void Qrcode::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void Qrcode::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void Qrcode::on_pushButton_clicked()
{
    this->close();
}

void Qrcode::on_toolButton_clicked()
{
    this->close();
}
