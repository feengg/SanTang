#include "wlbh_sub.h"
#include "ui_wlbh_sub.h"
#include <QDateTime>
#include "widget.h"

Wlbh_sub::Wlbh_sub(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wlbh_sub)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("新增物料编号");
    ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
    ui->lineEdit_dealName->setText(LoginWindow::userName);
}

Wlbh_sub::~Wlbh_sub()
{
    delete ui;
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void Wlbh_sub::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void Wlbh_sub::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void Wlbh_sub::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void Wlbh_sub::on_toolButton_clicked()
{
    this->close();
}

void Wlbh_sub::on_pushButton_newNum_clicked()
{
    ui->lineEdit_wlNum->clear();
    if(ui->lineEdit_wlClass->text().trimmed().isEmpty()||ui->lineEdit_wlFormat->text().trimmed().isEmpty()
            ||ui->lineEdit_wlName->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"OA提示","必填信息不能为空！   ",QMessageBox::Ok);
        return;
    }
    if(ui->lineEdit_wlClass->text().trimmed().toInt() < 1000 || ui->lineEdit_wlClass->text().trimmed().toInt() > 9999)
    {
        QMessageBox::warning(this,"OA提示","物料分类填写有误！   ",QMessageBox::Ok);
        return;
    }
    if(!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }
    QSqlQuery query;

    qint64 storeWlMaxNum = 0;
    qint64 wlbhDataBaseMaxNum = 0;
    //获取库存里的最大值
    if(query.exec(tr("select count(*) from storebill where 规格型号 = '%1'").arg(ui->lineEdit_wlFormat->text().trimmed())))
    {
        query.next();
        if(query.value(0).toInt() > 0)
        {
            QMessageBox::warning(this,"OA提示","库存中已存在该规格型号！   ",QMessageBox::Ok);
            return;
        }
    }
    //查找该分类
    if(query.exec(tr("select max(物料编号) from storebill where 物料编号 like '%1%'").arg(ui->lineEdit_wlClass->text().trimmed())))
    {
         query.next();
         qDebug() << "v0=" << query.value(0).toInt();
         if(query.value(0).toInt() == 0)
         {
             QMessageBox::warning(this,"OA提示","库存中不存在该分类！   ",QMessageBox::Ok);
             return;
         }else{
             storeWlMaxNum = query.value(0).toInt();
         }
    }
    //获取新数据库的最大值

    //查找该分类
    if(query.exec(tr("select max(wlNum) from wlbhmsg where wlNum like '%1%'").arg(ui->lineEdit_wlClass->text().trimmed())))
    {
         query.next();
         wlbhDataBaseMaxNum = query.value(0).toInt();
    }
    //显示出来
    if(storeWlMaxNum > wlbhDataBaseMaxNum)
    {
        ui->lineEdit_wlNum->setText(QString::number(storeWlMaxNum+1));
    }else{
        ui->lineEdit_wlNum->setText(QString::number(wlbhDataBaseMaxNum+1));
    }

}

void Wlbh_sub::on_pushButton_save_clicked()
{
    //权限
    if(LoginWindow::userLevel != 6)
    {
        //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
    if(ui->lineEdit_wlNum->text().isEmpty())
    {
        //QMessageBox::warning(this,"OA提示","请先生成新的物料编号！   ",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请先生成新的物料编号！");
        dontUpdate->show();
        return;
    }
    if(!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec(tr("insert into wlbhMsg values('%1','%2','%3','%4','%5','%6','%7')").arg(ui->lineEdit_dealTime->text())
                  .arg(ui->lineEdit_dealName->text().trimmed()).arg(ui->lineEdit_wlClass->text().trimmed())
                  .arg(ui->lineEdit_wlNum->text()).arg(ui->lineEdit_wlName->text().trimmed()).arg(ui->lineEdit_wlFormat->text().trimmed())
                  .arg(ui->lineEdit_provider->text().trimmed())))
    {
        //QMessageBox::about(this,"OA提示","保存成功！  ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("保存成功！");
        dontUpdate->show();
        emit emitFlushWlbhTableSig();
        this->close();
    }else{
        QMessageBox::warning(this,"OA提示","保存失败,请重试！  ",QMessageBox::Ok);
    }
}
