#include "chukuform.h"
#include "ui_chukuform.h"
#include "widget.h"

ChuKuForm::ChuKuForm(QString id,int num,int haveChuku,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChuKuForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("出库");
    termID = id;
    haveOutNum = num;
    kuChuNum = haveChuku;
    ui->label_have->setText(QString::number(haveChuku));
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void ChuKuForm::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void ChuKuForm::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void ChuKuForm::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}
ChuKuForm::~ChuKuForm()
{
    delete ui;
}

void ChuKuForm::on_pushButton_close_clicked()
{
    this->close();
}

void ChuKuForm::on_pushButton_clicked()
{
    if(ui->lineEdit->text().trimmed().isEmpty())
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("请输入出库数");
        tip->show();
        return;
    }
    if(ui->lineEdit->text().toInt() > ui->label_have->text().toInt())
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("出库数多出了剩余库存数！");
        tip->show();
        return;
    }
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec(tr("update storebill set 出库数 = '%1',库存='%3' where 物料编号 = '%2'").arg(haveOutNum+ui->lineEdit->text().toInt())
                  .arg(termID).arg(kuChuNum - ui->lineEdit->text().toInt())))
    {
        QSqlDatabase::database().commit();
        showDontUpdateDialog * tip = new showDontUpdateDialog("出库成功！");
        tip->show();
    }
    this->close();
    emit sendFlushTableSig();
}
