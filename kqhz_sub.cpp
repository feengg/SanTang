#include "kqhz_sub.h"
#include "ui_kqhz_sub.h"
#include "widget.h"
#include "jiaban.h"
#include "qingjia.h"
#include "wangdaka.h"

KQHZ_Sub::KQHZ_Sub(QString time,QString staffId,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KQHZ_Sub)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("查看考勤");
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(clickedToShowSlot(int,int)));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->hideColumn(3);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    QStringList header;
    header << "工号" << "姓名" << "类型" << "电子流提交时间" << "申请时间段" << "打卡记录" << "该项事由" << "查看详情";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),ui->tableWidget,SLOT(resizeRowsToContents()));
    ui->tableWidget->setColumnWidth(0,80);
    ui->tableWidget->setColumnWidth(1,80);
    ui->tableWidget->setColumnWidth(2,80);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,240);
    ui->tableWidget->setColumnWidth(5,250);
    ui->tableWidget->setColumnWidth(6,310);
    ui->tableWidget->setColumnWidth(7,30);
    //显示条目
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;

//    qDebug() << "sub_sql= " << tr("select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,jbStartTime as startTime,jbEndTime as endTime from jiabanmsg where staffid = '%1' and jbStartTime like '%%2%' and dealresult='同意'"
//                                  "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,qjStartTime as startTime,qjEndTime as endTime  from qingjiamsg where staffid = '%1' and qjStartTime like '%%2%' and (manager = '无' or (manager != '无' and managerResult='同意')) and dptResult='同意' and viceResult='同意'"
//                                  "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,wdkDay as startTime,'-' as endTime  from wangdakamsg where staffid = '%1' and wdkDay like '%%2%'  and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意' "
//                                  "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,startTime as startTime,endTime as endTime  from chuchai where staffid = '%1' and startTime like '%%2%'  and leaderResult='同意' and managerResult='同意' and clerkResult='同意'"
//                                  "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,startTime as startTime,realTime as endTime  from waichu where staffid = '%1' and startTime like '%%2%' and leaderResult='同意' and clerkResult='同意'"
//                                  "order by starttime asc").arg(staffId).arg(time);

    if(query.exec(tr("select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,jbStartTime as startTime,jbEndTime as endTime,jbReason as reason from jiabanmsg where staffid = '%1' and jbStartTime like '%%2%' and dealresult='同意'"
                     "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,qjStartTime as startTime,qjEndTime as endTime,qjReason as reason  from qingjiamsg where staffid = '%1' and qjStartTime like '%%2%' and (manager = '无' or (manager != '无' and managerResult='同意')) and dptResult='同意' and viceResult='同意'"
                     "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,wdkDay as startTime,'-' as endTime,wdkReason as reason  from wangdakamsg where staffid = '%1' and wdkDay like '%%2%'  and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意' "
                     "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,startTime as startTime,endTime as endTime,reason as reason  from chuchai where staffid = '%1' and startTime like '%%2%'  and leaderResult='同意' and managerResult='同意' and clerkResult='同意'"
                     "union select staffid as staffid,name as name,tabletype as tabletype,dealtime as dealtime,startTime as startTime,realTime as endTime,reason as reason  from waichu where staffid = '%1' and startTime like '%%2%' and leaderResult='同意' and clerkResult='同意'"
                     "order by starttime asc")
               .arg(staffId).arg(time)))
    {
            ui->tableWidget->setRowCount(query.size());
            for(int i = 0; i < query.size();i++)
            {
                query.next();
                QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                QTableWidgetItem * item3 = new QTableWidgetItem(query.value(3).toString());
                QTableWidgetItem * item4 = new QTableWidgetItem(query.value(4).toString()+"—"+(query.value(5).toString()=="-"?"":query.value(5).toString()));

                QSqlQuery puchInQuery;
                QString recordStr;
                if(puchInQuery.exec(tr("select record,daytime from dakarecord where name = '%1' and daytime >= '%2' and daytime <= '%3'").arg(query.value(1).toString()).arg(query.value(4).toString().mid(0,10)).arg((query.value(5).toString()=="-"?query.value(4).toString().mid(0,10):query.value(5).toString().mid(0,10)))))
                {
                    if(puchInQuery.size())
                    {
                        for(int j = 0;j != puchInQuery.size();++j)
                        {
                            puchInQuery.next();
                            if(j == puchInQuery.size() - 1)
                            {
                                recordStr += puchInQuery.value(1).toString().mid(5,5) + ":  " + puchInQuery.value(0).toString();
                            }else{
                                recordStr += puchInQuery.value(1).toString().mid(5,5) + ":  " + puchInQuery.value(0).toString()+"\n";
                            }
                        }
                    }
                }
                QTableWidgetItem * item5 = new QTableWidgetItem(recordStr);
                QTableWidgetItem * item6 = new QTableWidgetItem(query.value(6).toString());
                QTableWidgetItem * item7 = new QTableWidgetItem("点击查看");

                item0->setTextAlignment(Qt::AlignCenter);
                item1->setTextAlignment(Qt::AlignCenter);
                item2->setTextAlignment(Qt::AlignCenter);
                item3->setTextAlignment(Qt::AlignCenter);
                item4->setTextAlignment(Qt::AlignCenter);
                item6->setTextAlignment(Qt::AlignCenter);
                item7->setTextAlignment(Qt::AlignCenter);

                item7->setTextColor(Qt::blue);
                item7->setBackgroundColor(QColor(235,235,235));

                ui->tableWidget->setItem(i,0,item0);
                ui->tableWidget->setItem(i,1,item1);
                ui->tableWidget->setItem(i,2,item2);
                ui->tableWidget->setItem(i,3,item3);
                ui->tableWidget->setItem(i,4,item4);
                ui->tableWidget->setItem(i,5,item5);
                ui->tableWidget->setItem(i,6,item6);
                ui->tableWidget->setItem(i,7,item7);
            }

    }



}

KQHZ_Sub::~KQHZ_Sub()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void KQHZ_Sub::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void KQHZ_Sub::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void KQHZ_Sub::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void KQHZ_Sub::on_toolButton_clicked()
{
    this->close();
}

void KQHZ_Sub::on_pButtonOk_clicked()
{
    this->close();
}

void KQHZ_Sub::clickedToShowSlot(int x,int y)
{
    if(y == 7)
    {
        QString staffId = ui->tableWidget->item(x,0)->text();
        QString name = ui->tableWidget->item(x,1)->text();
        QString tableType = ui->tableWidget->item(x,2)->text();
        QString dealtime = ui->tableWidget->item(x,3)->text();
        if(tableType == "加班")
        {
            if(!QSqlDatabase::database().isValid())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            qDebug() << "jiabansql = " << tr("select * from jiabanmsg where dealtime = '%1' and staffid = '%2'").arg(dealtime).arg(staffId);
            if(query.exec(tr("select * from jiabanmsg where dealtime = '%1' and staffid = '%2'").arg(dealtime).arg(staffId)))
            {
                query.next();
                Jiaban * jiabanShow = new Jiaban("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                 ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                 ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                 ,query.value(12).toString());
                jiabanShow->show();
            }
        }
        //请假
        if(tableType == "请假")
        {
            if(!QSqlDatabase::database().isValid())
            {
                Widget::openMySql();
            }
            QSqlQuery query;

            qDebug() << "qingjiasql=" << tr("select * from qingjiamsg where qjStartTime = '%1' and staffid = '%2'").arg(dealtime).arg(staffId);

            if(query.exec(tr("select * from qingjiamsg where dealtime = '%1' and staffid = '%2'").arg(dealtime).arg(staffId)))
            {
                query.next();
                QingJia * qingjia = new QingJia("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                qingjia->show();
            }
        }
        //忘打卡
        if(tableType == "忘打卡")
        {
            if(!QSqlDatabase::database().isValid())
            {
                Widget::openMySql();
            }
            QSqlQuery query;

            qDebug() << "wangdakasql=" << tr("select * from wangdakamsg where dealtime = '%1' and staffid = '%2'").arg(dealtime).arg(staffId);

            if(query.exec(tr("select * from wangdakamsg where dealtime = '%1' and staffid = '%2'").arg(dealtime).arg(staffId)))
            {
                query.next();
                WangDaKa * wangdaka = new WangDaKa("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                wangdaka->show();
            }
        }
        //出差
        if(tableType == "出差")
        {
            ChuChai * chuchai = new ChuChai("查看",name,dealtime);
            chuchai->show();
        }
        //外出
        if(tableType == "外出")
        {
            qDebug() << "name = " << name << "startTime = " << dealtime;
            WaiChu * waichu = new WaiChu("查看",name,dealtime);
            waichu->show();
        }
    }
}
