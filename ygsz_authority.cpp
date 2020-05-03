#include "ygsz_authority.h"
#include "ui_ygsz_authority.h"
#include "widget.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include "ygsz_auth_change.h"

YGSZ_Authority::YGSZ_Authority(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YGSZ_Authority)
{
    ui->setupUi(this);
    //设置背景图片
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle("权限管理");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    flushShowAuthSlot();

}

YGSZ_Authority::~YGSZ_Authority()
{
    delete ui;
}

void YGSZ_Authority::on_toolButton_clicked()
{
    this->close();
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void YGSZ_Authority::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void YGSZ_Authority::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void YGSZ_Authority::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void YGSZ_Authority::flushShowAuth(int level)
{
    if(!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }else{
        QSqlQuery query;
        if(query.exec(tr("select count(name) from staffmsg where level = '%1';").arg(level)))
        {
            query.next();
            int count = query.value(0).toInt();
            if(count > 0)
            {
                query.exec(tr("select name from staffmsg where level = '%1';").arg(level));
                QString Name = NULL;
                for(int i = 0;i < count;i++)
                {
                    query.next();
                    if(i < count-1)//最后一个去除逗号
                    {
                        Name += query.value(0).toString()+",";
                    }else
                    {
                        Name += query.value(0).toString();
                    }

                }
                if(level == 0)
                {
                    ui->lineEdit_super->setText(Name);
                }
                if(level == 1)
                {
                    ui->lineEdit_kcgl->setText(Name);
                }
                if(level == 2)
                {
                    ui->lineEdit_kccw->setText(Name);
                }
                if(level == 3)
                {
                    ui->lineEdit_store->setText(Name);
                }
                if(level == 4)
                {
                    ui->lineEdit_caigou->setText(Name);
                }
                if(level == 5)
                {
                    ui->lineEdit_tybh->setText(Name);
                }
                if(level == 6)
                {
                    ui->lineEdit_wlbh->setText(Name);
                }
            }

        }
    }
}

void YGSZ_Authority::flushShowAuthSlot()
{
    flushShowAuth(0);
    flushShowAuth(1);
    flushShowAuth(2);
    flushShowAuth(3);
    flushShowAuth(4);
    flushShowAuth(5);
    flushShowAuth(6);
}

void YGSZ_Authority::on_pushButton_super_clicked()
{
    YGSZ_Auth_Change * authCh1 = new YGSZ_Auth_Change(0,0);
    connect(authCh1,SIGNAL(emitFlushAuthLineEditSig()),this,SLOT(flushShowAuthSlot()));//点击完确定后想上级窗口发送刷新信号
    authCh1->show();
}

void YGSZ_Authority::on_pushButton_kcgl_2_clicked()
{
    this->close();
}

void YGSZ_Authority::on_pushButton_kcgl_clicked()
{
    YGSZ_Auth_Change * authCh2 = new YGSZ_Auth_Change(0,1);
    connect(authCh2,SIGNAL(emitFlushAuthLineEditSig()),this,SLOT(flushShowAuthSlot()));//点击完确定后想上级窗口发送刷新信号
    authCh2->show();
}

void YGSZ_Authority::on_pushButton__kccw_clicked()
{
    YGSZ_Auth_Change * authCh3 = new YGSZ_Auth_Change(0,2);
    connect(authCh3,SIGNAL(emitFlushAuthLineEditSig()),this,SLOT(flushShowAuthSlot()));//点击完确定后想上级窗口发送刷新信号
    authCh3->show();
}

void YGSZ_Authority::on_pushButton__store_clicked()
{
    YGSZ_Auth_Change * authCh4 = new YGSZ_Auth_Change(0,3);
    connect(authCh4,SIGNAL(emitFlushAuthLineEditSig()),this,SLOT(flushShowAuthSlot()));//点击完确定后想上级窗口发送刷新信号
    authCh4->show();
}

void YGSZ_Authority::on_pushButton__caigou_clicked()
{
    YGSZ_Auth_Change * authCh5 = new YGSZ_Auth_Change(0,4);
    connect(authCh5,SIGNAL(emitFlushAuthLineEditSig()),this,SLOT(flushShowAuthSlot()));//点击完确定后想上级窗口发送刷新信号
    authCh5->show();
}

void YGSZ_Authority::on_pushButton__tybh_clicked()
{
    YGSZ_Auth_Change * authCh6 = new YGSZ_Auth_Change(0,5);
    connect(authCh6,SIGNAL(emitFlushAuthLineEditSig()),this,SLOT(flushShowAuthSlot()));//点击完确定后想上级窗口发送刷新信号
    authCh6->show();
}

void YGSZ_Authority::on_pushButton__wlbh_clicked()
{
    YGSZ_Auth_Change * authCh7 = new YGSZ_Auth_Change(0,6);
    connect(authCh7,SIGNAL(emitFlushAuthLineEditSig()),this,SLOT(flushShowAuthSlot()));//点击完确定后想上级窗口发送刷新信号
    authCh7->show();
}
