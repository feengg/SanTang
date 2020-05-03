#include "showudptipmsgdialog.h"
#include "ui_showudptipmsgdialog.h"

showUdpTipMsgDialog::showUdpTipMsgDialog(QString tipMsg,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showUdpTipMsgDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/对话框.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

    this->move((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height());//初始化位置到右下角
    showAnimation(); //开始显示右下角弹出框
    this->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);
    ui->label->setText(tipMsg);


//    if(tipMsg.mid(0,2) == "您有")
//    {
//        ui->pushButton->setText("点击处理");
//    }else
//    {
//        ui->pushButton->setText("点击查看");
//    }
}

showUdpTipMsgDialog::~showUdpTipMsgDialog()
{
    delete ui;
}

//弹出动画
void showUdpTipMsgDialog::showAnimation(){
    //显示弹出框动画

    animation=new QPropertyAnimation(this,"pos");
    animation->setDuration(500);
    animation->setStartValue(QPoint(this->x(),this->y()));
    animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),(desktop.availableGeometry().height()-this->height())));
    animation->start();
}
//关闭动画
void showUdpTipMsgDialog::closeAnimation(){
    //弹出框回去动画
    animation->setStartValue(QPoint(this->x(),this->y()));
    animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height()));
    animation->start();
    //弹回动画完成后清理动画指针
    connect(animation,SIGNAL(finished()),this,SLOT(clearAll()));


}
//清理动画指针
void showUdpTipMsgDialog::clearAll(){
    disconnect(animation,SIGNAL(finished()),this,SLOT(clearAll()));
    delete animation;
    animation=NULL;
    this->close();
}

void showUdpTipMsgDialog::on_pushButton_clicked()
{

    if(ui->pushButton->text() == "点击处理")
    {
        emit emitShowWidgetSig("点击处理");
    }
    if(ui->label->text() == "您的加班电子流已被处理！")
    {
         emit emitShowWidgetSig("查看加班");
    }
    if(ui->label->text() == "您的请假电子流已被处理！")
    {
        emit emitShowWidgetSig("查看请假");
    }
    if(ui->label->text() == "您的忘打卡电子流已被处理！")
    {
        emit emitShowWidgetSig("查看忘打卡");
    }
    if(ui->label->text() == "您有新的采购申请待处理!" || ui->label->text() == "您的采购申请电子流已被处理！")
    {
        emit emitShowWidgetSig("查看采购");
    }
    if(ui->label->text() == "您的图样编号已生成!")
    {
        emit emitShowWidgetSig("查看图样编号");
    }
    if(ui->pushButton->text() == "点击查看")
    {
        emit emitShowWidgetSig("点击处理");
    }
    closeAnimation();
}

void showUdpTipMsgDialog::on_toolButton_clicked()
{
    closeAnimation();
}
