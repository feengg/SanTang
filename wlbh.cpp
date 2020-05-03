#include "wlbh.h"
#include "ui_wlbh.h"
#include "wlbh_sub.h"
#include "widget.h"

Wlbh::Wlbh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wlbh)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("物料编号");
    flushTableSlot();
}

Wlbh::~Wlbh()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void Wlbh::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void Wlbh::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void Wlbh::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void Wlbh::on_pushButton_new_clicked()
{
    Wlbh_sub * wlbh_sub = new Wlbh_sub;
    connect(wlbh_sub,SIGNAL(emitFlushWlbhTableSig()),this,SLOT(flushTableSlot()));
    wlbh_sub->show();
}

void Wlbh::on_pushButton_ok_clicked()
{
    this->close();
}

void Wlbh::on_toolButton_clicked()
{
    this->close();
}

void Wlbh::flushTableSlot()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    QStringList header;
    header << "物料编码" << "物料名称" << "规格型号/封装" << "厂家"<<"申请人"<<"申请日期";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    if(!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec(tr("select * from wlbhMsg order by dealTime desc")))
    {
        ui->tableWidget->setRowCount(query.size());
        for(int i = 0; i < query.size();i ++)
        {
            query.next();
            QTableWidgetItem * item0 = new QTableWidgetItem(query.value(3).toString());
            QTableWidgetItem * item1 = new QTableWidgetItem(query.value(4).toString());
            QTableWidgetItem * item2 = new QTableWidgetItem(query.value(5).toString());
            QTableWidgetItem * item3 = new QTableWidgetItem(query.value(6).toString());
            QTableWidgetItem * item4 = new QTableWidgetItem(query.value(1).toString());
            QTableWidgetItem * item5 = new QTableWidgetItem(query.value(0).toString());
            item0->setTextAlignment(Qt::AlignCenter);
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);
            item4->setTextAlignment(Qt::AlignCenter);
            item5->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setItem(i,0,item0);
            ui->tableWidget->setItem(i,1,item1);
            ui->tableWidget->setItem(i,2,item2);
            ui->tableWidget->setItem(i,3,item3);
            ui->tableWidget->setItem(i,4,item4);
            ui->tableWidget->setItem(i,5,item5);
        }
    }
}

//显示搜索结果到table
void Wlbh::showSearchResultToTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    QStringList header;
    header << "物料编码" << "物料名称" << "规格型号/封装" << "厂家"<<"申请人"<<"申请日期";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    if(!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec(tr("select * from wlbhMsg where wlNum like '%%1%' and wlName like '%%2%' and wlFormat like '%%3%' order by dealTime desc")
                  .arg(ui->lineEdit_wlNum->text().trimmed()).arg(ui->lineEdit_wlName->text().trimmed()).arg(ui->lineEdit_format->text().trimmed())))
    {
        ui->tableWidget->setRowCount(query.size());
        for(int i = 0; i < query.size();i ++)
        {
            query.next();
            QTableWidgetItem * item0 = new QTableWidgetItem(query.value(3).toString());
            QTableWidgetItem * item1 = new QTableWidgetItem(query.value(4).toString());
            QTableWidgetItem * item2 = new QTableWidgetItem(query.value(5).toString());
            QTableWidgetItem * item3 = new QTableWidgetItem(query.value(6).toString());
            QTableWidgetItem * item4 = new QTableWidgetItem(query.value(1).toString());
            QTableWidgetItem * item5 = new QTableWidgetItem(query.value(0).toString());
            item0->setTextAlignment(Qt::AlignCenter);
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);
            item4->setTextAlignment(Qt::AlignCenter);
            item5->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setItem(i,0,item0);
            ui->tableWidget->setItem(i,1,item1);
            ui->tableWidget->setItem(i,2,item2);
            ui->tableWidget->setItem(i,3,item3);
            ui->tableWidget->setItem(i,4,item4);
            ui->tableWidget->setItem(i,5,item5);
        }
    }
}

void Wlbh::on_lineEdit_wlNum_textChanged(const QString &arg1)
{
    showSearchResultToTable();
}

void Wlbh::on_lineEdit_wlName_textChanged(const QString &arg1)
{
    showSearchResultToTable();
}

void Wlbh::on_lineEdit_format_textChanged(const QString &arg1)
{
    showSearchResultToTable();
}
