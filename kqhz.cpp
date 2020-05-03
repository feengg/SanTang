#include "kqhz.h"
#include "ui_kqhz.h"
#include "widget.h"
#include <QDateTime>
#include <QTableWidgetItem>
#include "kqhz_sub.h"

KQHZ::KQHZ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KQHZ)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("考勤汇总");
    for(int i = 2018;i < 2050;i++)
    {
        ui->comboBox_year->addItem(QString::number(i));
    }
    for(int i = 1;i < 13;i++)
    {
        if(i < 10)
        {
            ui->comboBox_mouth->addItem("0"+QString::number(i));
        }else{
            ui->comboBox_mouth->addItem(QString::number(i));
        }
    }
    QString year = QDateTime::currentDateTime().toString("yyyy");
    QString mouth = QDateTime::currentDateTime().toString("MM");
    ui->comboBox_year->setCurrentText(year);
    ui->comboBox_mouth->setCurrentText(mouth);
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(clickedToShowSlot(int,int)));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑
    addALLTableItem();
    ui->label_name->hide();
    ui->lineEdit_name->hide();
}

KQHZ::~KQHZ()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void KQHZ::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void KQHZ::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void KQHZ::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void KQHZ::on_pushButton_search_clicked()
{
    if(!ui->lineEdit_name->text().trimmed().isEmpty())
    {
        addNewTableItem(ui->lineEdit_name->text().trimmed());
    }else
    {
        addALLTableItem();
    }
}

void KQHZ::on_toolButton_clicked()
{
    this->close();
}

void KQHZ::on_pushButton_Ok_clicked()
{
    this->close();
}

void KQHZ::addNewTableItem(QString name)
{
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec(tr("select count(*) from staffmsg where name = '%1'").arg(name)))
    {
//        query.next();
//        if(query.value(0) == 0)
//        {
//            QMessageBox::warning(this,"OA提示","姓名有误，没有该员工！  ",QMessageBox::Ok);
//            return;
//        }

        //初始化tableWidget
        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(10);
        ui->tableWidget->setRowCount(0);
        //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QStringList header;
        header << "工号" << "姓名" << "请假(天)" << "换休(小时)" << "加班(小时)"<<"忘打卡(次)"<<"加班餐费"<<"出差次数"<<"外出次数"<<"查看详情";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        //显示该员工考勤汇总
        //请假
        query.exec(tr("select count(*) from qingjiamsg where name like '%%1%' and qjStartTime like '%%2%' and (manager = '无' or (manager != '无' and managerResult='同意')) and dptResult='同意' and viceResult='同意'")
                   .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        query.next();
        int qjDay = query.value(0).toInt();

        //加班
        query.exec(tr("select count(*) from jiabanmsg where name like '%%1%' and jbStartTime like '%%2%' and dealResult='同意'")
                   .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        query.next();
        int jbDay = query.value(0).toInt();

        //忘打卡
        query.exec(tr("select count(*) from wangdakamsg where name like '%%1%' and wdkDay like '%%2%' and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意'")
                   .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        query.next();
        int wdkDay = query.value(0).toInt();
        //出差次数
        query.exec(tr("select * from chuchai where name like '%%1%' and startTime like '%%2%' and leaderResult='同意' and  managerResult='同意' and clerkResult='同意'")
                   .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        int chuChaiTimes = query.size();
        //外出次数
        query.exec(tr("select * from waichu where name like '%%1%' and startTime like '%%2%' and leaderResult='同意'  and clerkResult='同意'")
                   .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        int waiChuTimes = query.size();
        if(qjDay == 0 && jbDay == 0 && wdkDay == 0 && chuChaiTimes == 0 && waiChuTimes == 0)
        {
            return;

        }else{ //有考勤记录
            ui->tableWidget->setRowCount(1);
            int qjNum = 0,hxNum = 0,jbNum = 0,wdkNum = 0,jbDineMoney = 0;
            QString staffName = NULL,staffid = NULL;
            if(qjDay) //qingjia
            {


                query.exec(tr("select staffid,name,qjType,qjday from qingjiamsg where name like '%%1%' and qjStartTime like '%%2%'")
                           .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                for(int i = 0;i < query.size();i++)
                {
                    query.next();
                    if(query.value(2).toString() == "换休")
                    {
                        hxNum += query.value(3).toInt();
                    }else{
                        qjNum += query.value(3).toInt();
                    }

                }
                staffName = query.value(1).toString();
                staffid = query.value(0).toString();
            }
            if(jbDay)
            {

                query.exec(tr("select staffid,name,jbTimeArea,jbStartTime,jbEndTime,jbFoodMoney from jiabanmsg where name like '%%1%' and jbStartTime like '%%2%'  and dealResult='同意'")
                           .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                for(int i = 0 ; i < query.size(); i++)
                {
                    query.next();
                    if(query.value(2).toString() == "工作日加班")
                    {
                        //加班日期为同一天
                        if(query.value(3).toString().mid(0,10) == query.value(4).toString().mid(0,10))
                        {
                            QString qValue4 = query.value(4).toString();
                            int hours = qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt()-18;

                            if(qValue4.mid(qValue4.indexOf(":")+1,2).toInt() >= 30)
                            {
                                hours += 1;
                            }
                            jbNum += hours;
                        }else
                        {
                            jbNum += 6;
                            QString qValue4 = query.value(4).toString();

                            jbNum += qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt();
                            if(qValue4.mid(qValue4.indexOf(":")+1,2).toInt() >= 30)
                            {
                                jbNum += 1;
                            }
                        }
                    }else{
                        QString qValue3 = query.value(3).toString();
                        QString qValue4 = query.value(4).toString();
                        int day = qValue4.mid(8,2).toInt() - qValue3.mid(8,2).toInt();
                        if(day == 0)
                        {
                            jbNum += qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt() - qValue3.mid(qValue3.indexOf("/")+1,qValue3.indexOf(":")-qValue3.indexOf("/")-1).toInt();

                        }else{
                            jbNum += (24 - qValue3.mid(qValue3.indexOf("/")+1,qValue3.indexOf(":")-qValue3.indexOf("/")-1).toInt() + qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt()
                                      + 24 * ((qValue4.mid(8,2).toInt() - qValue3.mid(8,2).toInt() - 1)));
                        }
                    }
                    jbDineMoney += query.value(5).toFloat();
                }
                staffName = query.value(1).toString();
                staffid = query.value(0).toString();
            }
            if(wdkDay)
            {
                wdkNum = wdkDay;

                query.exec(tr("select staffid,name from wangdakamsg where name like '%%1%' and wdkDay like '%%2%'  and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意'")
                           .arg(name).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                query.next();
                staffName = query.value(1).toString();
                staffid = query.value(0).toString();

            }
            if(chuChaiTimes)
            {
                query.exec(tr("select staffid,name from chuchai where name like '%%1%' and startTime like '%%2%' and leaderResult='同意' and managerResult='同意' and clerkResult='同意'")
                           .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                query.next();
                staffName = query.value(1).toString();
                staffid = query.value(0).toString();
            }
            if(waiChuTimes)
            {
                query.exec(tr("select staffid,name from waichu where name like '%%1%' and startTime like '%%2%' and leaderResult='同意' and clerkResult='同意'")
                           .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                query.next();
                staffName = query.value(1).toString();
                staffid = query.value(0).toString();
            }

            QTableWidgetItem * item0 = new QTableWidgetItem(staffid);
            QTableWidgetItem * item1 = new QTableWidgetItem(staffName);
            QTableWidgetItem * item2 = new QTableWidgetItem(QString::number(qjNum));
            QTableWidgetItem * item3 = new QTableWidgetItem(QString::number(hxNum));
            QTableWidgetItem * item4 = new QTableWidgetItem(QString::number(jbNum));
            QTableWidgetItem * item5 = new QTableWidgetItem(QString::number(wdkNum));
            QTableWidgetItem * item6 = new QTableWidgetItem(QString::number(jbDineMoney));
            QTableWidgetItem * item7 = new QTableWidgetItem(QString::number(chuChaiTimes));
            QTableWidgetItem * item8 = new QTableWidgetItem(QString::number(waiChuTimes));
            QTableWidgetItem * item9 = new QTableWidgetItem("点击查看");

            item0->setTextAlignment(Qt::AlignCenter);
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);
            item4->setTextAlignment(Qt::AlignCenter);
            item5->setTextAlignment(Qt::AlignCenter);
            item6->setTextAlignment(Qt::AlignCenter);
            item7->setTextAlignment(Qt::AlignCenter);
            item8->setTextAlignment(Qt::AlignCenter);
            item9->setTextAlignment(Qt::AlignCenter);

            item9->setTextColor(Qt::blue);
            item9->setBackgroundColor(QColor(235,235,235));

            ui->tableWidget->setRowCount(1);
            ui->tableWidget->setItem(0,0,item0);
            ui->tableWidget->setItem(0,1,item1);
            ui->tableWidget->setItem(0,2,item2);
            ui->tableWidget->setItem(0,3,item3);
            ui->tableWidget->setItem(0,4,item4);
            ui->tableWidget->setItem(0,5,item5);
            ui->tableWidget->setItem(0,6,item6);
            ui->tableWidget->setItem(0,7,item7);
            ui->tableWidget->setItem(0,8,item8);
            ui->tableWidget->setItem(0,9,item9);
        }

    }else{
        QMessageBox::warning(this,"错误提示","数据库执行失败！  ",QMessageBox::Ok);
        return;
    }
}


void KQHZ::addALLTableItem()
{
    //初始化tableWidget
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(10);
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList header;
    header << "工号" << "姓名" << "请假(天)" << "换休(小时)" << "加班(小时)"<<"忘打卡(次)"<<"加班餐费"<<"出差次数"<<"外出次数"<<"查看详情";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    query.exec("select name from staffmsg");

    int rowNum = 0;
    for(int i = 0 ; i < query.size(); i ++ )
    {
        query.next();

        //显示该员工考勤汇总
        //请假
        QSqlQuery query1;

        query1.exec(tr("select count(*) from qingjiamsg where name='%1' and qjStartTime like '%%2%' and (manager = '无' or (manager != '无' and managerResult='同意')) and dptResult='同意' and viceResult='同意'")
                   .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        query1.next();
        int qjDay = query1.value(0).toInt();

        //加班
        query1.exec(tr("select count(*) from jiabanmsg where name='%1' and jbStartTime like '%%2%'  and dealResult='同意'")
                   .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        query1.next();
        int jbDay = query1.value(0).toInt();

        //忘打卡
        query1.exec(tr("select count(*) from wangdakamsg where name='%1' and wdkDay like '%%2%' and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意'")
                   .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        query1.next();
        int wdkDay = query1.value(0).toInt();
        //出差次数
        query1.exec(tr("select * from chuchai where name='%1' and startTime like '%%2%' and leaderResult='同意' and  managerResult='同意' and clerkResult='同意'")
                   .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        int chuChaiTimes = query1.size();
        //外出次数
        query1.exec(tr("select * from waichu where name='%1' and startTime like '%%2%' and leaderResult='同意'  and clerkResult='同意'")
                   .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
        int waiChuTimes = query1.size();
        if(qjDay == 0 && jbDay == 0 && wdkDay == 0 && chuChaiTimes == 0 && waiChuTimes == 0)
        {
            continue;
        }else{ //有考勤记录

            int qjNum = 0,hxNum = 0,jbNum = 0,wdkNum = 0,jbDineMoney = 0;
            QString staffName = NULL,staffid = NULL;
            if(qjDay) //qingjia
            {
                query1.exec(tr("select staffid,name,qjType,qjday from qingjiamsg where name='%1' and qjStartTime like '%%2%' and (manager = '无' or (manager != '无' and managerResult='同意')) and dptResult='同意' and viceResult='同意'")
                           .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                for(int i = 0;i < query1.size();i++)
                {
                    query1.next();
                    if(query1.value(2).toString() == "换休")
                    {
                        hxNum += query1.value(3).toInt();
                    }else{
                        qjNum += query1.value(3).toInt();
                    }

                }
                staffName = query1.value(1).toString();
                staffid = query1.value(0).toString();
            }
            if(jbDay)
            {

                query1.exec(tr("select staffid,name,jbTimeArea,jbStartTime,jbEndTime,jbFoodMoney from jiabanmsg where name='%1' and jbStartTime like '%%2%'  and dealResult='同意'")
                           .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                for(int i = 0 ; i < query1.size(); i++)
                {
                    query1.next();
                    if(query1.value(2).toString() == "工作日加班")
                    {
                        //加班日期为同一天
                        if(query1.value(3).toString().mid(0,10) == query1.value(4).toString().mid(0,10))
                        {
                            QString qValue4 = query1.value(4).toString();
                            int hours = qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt()-18;

                            if(qValue4.mid(qValue4.indexOf(":")+1,2).toInt() >= 30)
                            {
                                hours += 1;
                            }
                            jbNum += hours;
                        }else
                        {
                            jbNum += 6;
                            QString qValue4 = query1.value(4).toString();

                            jbNum += qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt();
                            if(qValue4.mid(qValue4.indexOf(":")+1,2).toInt() >= 30)
                            {
                                jbNum += 1;
                            }
                        }
                    }else{
                        QString qValue3 = query1.value(3).toString();
                        QString qValue4 = query1.value(4).toString();
                        int day = qValue4.mid(8,2).toInt() - qValue3.mid(8,2).toInt();
                        if(day == 0)
                        {
                            jbNum += qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt() - qValue3.mid(qValue3.indexOf("/")+1,qValue3.indexOf(":")-qValue3.indexOf("/")-1).toInt();

                        }else{
                            jbNum += (24 - qValue3.mid(qValue3.indexOf("/")+1,qValue3.indexOf(":")-qValue3.indexOf("/")-1).toInt() + qValue4.mid(qValue4.indexOf("/")+1,qValue4.indexOf(":")-qValue4.indexOf("/")-1).toInt()
                                      + 24 * ((qValue4.mid(8,2).toInt() - qValue3.mid(8,2).toInt() - 1)));
                        }
                    }
                    //计算加班费
                    jbDineMoney += query1.value(5).toFloat();
                }
                staffName = query1.value(1).toString();
                staffid = query1.value(0).toString();
            }
            if(wdkDay)
            {
                wdkNum = wdkDay;

                query1.exec(tr("select staffid,name from wangdakamsg where name='%1' and wdkDay like '%%2%' and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意'")
                           .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                query1.next();
                staffName = query1.value(1).toString();
                staffid = query1.value(0).toString();

            }
            if(chuChaiTimes)
            {
                query1.exec(tr("select staffid,name from chuchai where name='%1' and startTime like '%%2%' and leaderResult='同意' and managerResult='同意' and clerkResult='同意'")
                           .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                query1.next();
                staffName = query1.value(1).toString();
                staffid = query1.value(0).toString();
            }
            if(waiChuTimes)
            {
                query1.exec(tr("select staffid,name from waichu where name='%1' and startTime like '%%2%' and leaderResult='同意' and clerkResult='同意'")
                           .arg(query.value(0).toString()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText()));
                query1.next();
                staffName = query1.value(1).toString();
                staffid = query1.value(0).toString();
            }
            rowNum++;
            ui->tableWidget->setRowCount(rowNum);
            QTableWidgetItem * item0 = new QTableWidgetItem(staffid);
            QTableWidgetItem * item1 = new QTableWidgetItem(staffName);
            QTableWidgetItem * item2 = new QTableWidgetItem(QString::number(qjNum));
            QTableWidgetItem * item3 = new QTableWidgetItem(QString::number(hxNum));
            QTableWidgetItem * item4 = new QTableWidgetItem(QString::number(jbNum));
            QTableWidgetItem * item5 = new QTableWidgetItem(QString::number(wdkNum));
            QTableWidgetItem * item6 = new QTableWidgetItem(QString::number(jbDineMoney));
            QTableWidgetItem * item7 = new QTableWidgetItem(QString::number(chuChaiTimes));
            QTableWidgetItem * item8 = new QTableWidgetItem(QString::number(waiChuTimes));
            QTableWidgetItem * item9 = new QTableWidgetItem("点击查看");

            item0->setTextAlignment(Qt::AlignCenter);
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);
            item4->setTextAlignment(Qt::AlignCenter);
            item5->setTextAlignment(Qt::AlignCenter);
            item6->setTextAlignment(Qt::AlignCenter);
            item7->setTextAlignment(Qt::AlignCenter);
            item8->setTextAlignment(Qt::AlignCenter);
            item9->setTextAlignment(Qt::AlignCenter);

            item9->setTextColor(Qt::blue);
            item9->setBackgroundColor(QColor(235,235,235));


            ui->tableWidget->setItem(rowNum-1,0,item0);
            ui->tableWidget->setItem(rowNum-1,1,item1);
            ui->tableWidget->setItem(rowNum-1,2,item2);
            ui->tableWidget->setItem(rowNum-1,3,item3);
            ui->tableWidget->setItem(rowNum-1,4,item4);
            ui->tableWidget->setItem(rowNum-1,5,item5);
            ui->tableWidget->setItem(rowNum-1,6,item6);
            ui->tableWidget->setItem(rowNum-1,7,item7);
            ui->tableWidget->setItem(rowNum-1,8,item8);
            ui->tableWidget->setItem(rowNum-1,9,item9);
        }
    }

}

void KQHZ::clickedToShowSlot(int x,int y)
{
    if( y == 9)
    {
        QString time = ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText();
        QString staffId  = ui->tableWidget->item(x,0)->text();
        KQHZ_Sub * kqhz_sub = new KQHZ_Sub(time,staffId);
        kqhz_sub->show();
    }
}

void KQHZ::on_lineEdit_name_textChanged(const QString &arg1)
{
    addNewTableItem(arg1);
}
