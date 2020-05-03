#include "choosetype.h"
#include "ui_choosetype.h"
#include <QDebug>
#include "jiaban.h"
#include "qingjia.h"
#include "wangdaka.h"
#include "chuchai.h"
#include "waichu.h"

chooseType::chooseType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseType)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("选择类型");

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->radioButton_jb,1);
    btnGroup->addButton(ui->radioButton_qj,2);
    btnGroup->addButton(ui->radioButton_wdk,3);
    btnGroup->addButton(ui->radioButton_chuchai,4);
    btnGroup->addButton(ui->radioButton_waichu,5);

    ui->radioButton_jb->setChecked(true);
    connect(ui->radioButton_jb,SIGNAL(clicked()),this,SLOT(onRadioClickedSlot()));
    connect(ui->radioButton_qj,SIGNAL(clicked()),this,SLOT(onRadioClickedSlot()));
    connect(ui->radioButton_wdk,SIGNAL(clicked()),this,SLOT(onRadioClickedSlot()));
    connect(ui->radioButton_chuchai,SIGNAL(clicked()),this,SLOT(onRadioClickedSlot()));
    connect(ui->radioButton_waichu,SIGNAL(clicked()),this,SLOT(onRadioClickedSlot()));

}

chooseType::~chooseType()
{
    delete ui;
}

void chooseType::on_pushButton_2_clicked()
{
    this->close();
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void chooseType::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void chooseType::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void chooseType::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void chooseType::onRadioClickedSlot()
{

    switch (btnGroup->checkedId()) {
    case 1:
        choose_type = "加班";
        break;
    case 2:
        choose_type = "请假";
        break;
    case 3:
        choose_type = "忘打卡";
        break;
    case 4:
        choose_type = "出差";
        break;
    case 5:
        choose_type = "外出";
        break;
    default:
        break;
    }
}

void chooseType::on_pushButton_clicked()
{

    if(choose_type == "加班")
    {

        Jiaban * jiaban = new Jiaban("新增");
        connect(jiaban,SIGNAL(emitFlushShowStreamSig(QString)),this,SLOT(getJbSigSlot(QString)));
        jiaban->show();
        this->close();

    }
    if(choose_type == "请假")
    {
        QingJia * qingjia = new QingJia("新增",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
                                        NULL,NULL,NULL,NULL,NULL,NULL,NULL,0);
        connect(qingjia,SIGNAL(emitFlushShowStreamSig(QString)),this,SLOT(getJbSigSlot(QString)));
        qingjia->show();
        this->hide();
    }
    if(choose_type == "忘打卡")
    {
        WangDaKa * wangdaka = new WangDaKa("新增",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
                                           NULL,NULL,NULL,NULL,NULL,NULL,NULL,0);
        connect(wangdaka,SIGNAL(emitFlushShowStreamSig(QString)),this,SLOT(getJbSigSlot(QString)));
        wangdaka->show();
        this->hide();
    }
    if(choose_type == "出差")
    {
        ChuChai * chuchai = new ChuChai("新增");
        connect(chuchai,SIGNAL(emitFlushShowStreamSig(QString)),this,SLOT(getJbSigSlot(QString)));
        chuchai->show();
        this->hide();
    }
    if(choose_type == "外出")
    {
        WaiChu * waichu = new WaiChu ("新增");
        connect(waichu,SIGNAL(emitFlushShowStreamSig(QString)),this,SLOT(getJbSigSlot(QString)));
        waichu->show();
        this->hide();
    }
}

void chooseType::getJbSigSlot(QString type)
{
    emit emitToJiabanToFlushStreamListSig(type);
}
