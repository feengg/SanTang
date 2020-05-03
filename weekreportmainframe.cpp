#include "weekreportmainframe.h"
#include "ui_weekreportmainframe.h"

WeekReportMainFrame::WeekReportMainFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeekReportMainFrame)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("个人周报");
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    //初始化
    initNameCombox();
    initYearCombox();
    initPeriodCombox();
    initTableWidget();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    //信号和槽
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(dealCellClickedSlot(int,int)));
    //菜单信号槽
    connect(ui->tableWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(dealMenu(QPoint)));
    ui->pushButton_dontSubmit->setStyle(QStyleFactory::create("fusion"));
    ui->pushButton_sendTipMsg->setStyle(QStyleFactory::create("fusion"));
    saveAllNameVec();
}

WeekReportMainFrame::~WeekReportMainFrame()
{
    delete ui;
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void WeekReportMainFrame::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void WeekReportMainFrame::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void WeekReportMainFrame::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void WeekReportMainFrame::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void WeekReportMainFrame::on_pushButton_close_clicked()
{
    this->close();
}

void WeekReportMainFrame::initNameCombox()
{
    QSqlQuery query;
    if(query.exec("select name from staffmsg"))
    {
        int nameNum = query.size();
        for(int i = 0;i != nameNum;++i)
        {
            query.next();
            ui->comboBox_name->addItem(query.value(0).toString());
        }
    }
    ui->comboBox_name->setItemText(0,"所有员工");
    ui->comboBox_name->setCurrentText(LoginWindow::userName);
}
//
void WeekReportMainFrame::initYearCombox()
{
    for(int i = 2018;i < 2050;i++)
    {
        ui->comboBox_year->addItem(QString::number(i));
    }
    ui->comboBox_year->setCurrentText(QDateTime::currentDateTime().toString("yyyy"));
}

void WeekReportMainFrame::initPeriodCombox()
{
    ui->comboBox_period->clear();
    QSqlQuery query;
    if(query.exec(tr("select distinct time from weekreport where name like '%1' and time like '%2%' order by time desc").arg(ui->comboBox_name->currentText()=="所有员工"?"%":ui->comboBox_name->currentText())
                 .arg(ui->comboBox_year->currentText())))
    {
        if(query.size())
        {
            ui->comboBox_period->addItem("所有时段");
            for(int i = 0;i != query.size();++i)
            {
                query.next();
                ui->comboBox_period->addItem(query.value(0).toString());
            }
            if(ui->comboBox_name->currentText() == "所有员工")
            {
                ui->comboBox_period->setCurrentIndex(1);
            }
        }
        else
        {
            ui->comboBox_period->addItem("无");
        }
    }

}
//
void WeekReportMainFrame::showReportToTable()
{
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    initTableWidget();
    QString sqlMsg;
    if(ui->comboBox_name->currentText() == "所有员工")
    {
        if(ui->comboBox_period->currentText() == "所有时段")
        {
            sqlMsg = tr("select name,time from weekreport where time like '%1%' order by time desc").arg(ui->comboBox_year->currentText());
        }
        else
        {
            sqlMsg = tr("select name,time from weekreport where time = '%1' order by time desc").arg(ui->comboBox_period->currentText());
        }
    }
    else
    {
        if(ui->comboBox_period->currentText() == "所有时段")
        {
            sqlMsg = tr("select name,time from weekreport where name = '%1' and time like '%2%' order by time desc").arg(ui->comboBox_name->currentText()).arg(ui->comboBox_year->currentText());
        }
        else
        {
            sqlMsg = tr("select name,time from weekreport where name = '%1' and time = '%2' order by time desc").arg(ui->comboBox_name->currentText()).arg(ui->comboBox_period->currentText());
        }
    }
    //qDebug() << "sql = " << sqlMsg;
    QSqlQuery query;
    if(query.exec(sqlMsg))
    {
        if(query.size())
        {
            ui->tableWidget->setRowCount(query.size());
            for(int i = 0;i != query.size();++i)
            {
                query.next();
                QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                QTableWidgetItem * item2 = new QTableWidgetItem("点击查看");

                item0->setTextAlignment(Qt::AlignCenter);
                item1->setTextAlignment(Qt::AlignCenter);
                item2->setTextAlignment(Qt::AlignCenter);

                item2->setTextColor(Qt::blue);
                item2->setBackgroundColor(QColor(235,235,235));

                ui->tableWidget->setItem(i,0,item0);
                ui->tableWidget->setItem(i,1,item1);
                ui->tableWidget->setItem(i,2,item2);
            }
        }
    }
}
//
void WeekReportMainFrame::initTableWidget()
{
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header << "姓名" <<"报告时段" << "点击查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);


}

void WeekReportMainFrame::on_comboBox_name_currentTextChanged(const QString &)
{
    initPeriodCombox();
    showReportToTable();
}

void WeekReportMainFrame::on_comboBox_year_currentTextChanged(const QString &)
{
    initPeriodCombox();
    showReportToTable();
}

void WeekReportMainFrame::on_comboBox_period_currentTextChanged(const QString &)
{
    showReportToTable();
}

void WeekReportMainFrame::on_pushButton_newReport_clicked()
{
    WeekReport * report = new WeekReport("新建",LoginWindow::userName,"");
    connect(report,SIGNAL(sendFatherFlushTableSig()),this,SLOT(showReportToTable()));
    report->show();
}

void WeekReportMainFrame::dealDeleteSlot()
{
    int clickRow = ui->tableWidget->currentRow();
    QString name =  ui->tableWidget->item(clickRow,0)->text();
    QString time = ui->tableWidget->item(clickRow,1)->text();
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec(tr("delete from weekreport where name = '%1' and time = '%2'").arg(name).arg(time)))
    {
        QSqlDatabase::database().commit();
        showDontUpdateDialog * msgBox = new showDontUpdateDialog("删除成功！");
        msgBox->show();
    }
    showReportToTable();
}
//定义菜单槽函数
void WeekReportMainFrame::dealMenu(QPoint pos)
{
    QModelIndex index = ui->tableWidget->indexAt(pos);
    if(index.isValid())
    {
        if(ui->comboBox_name->currentText() == LoginWindow::userName)
        {
            QMenu * menu = new QMenu(ui->tableWidget);
            QAction * delAction = new QAction("删除",ui->tableWidget);
            connect(delAction,SIGNAL(triggered(bool)),this,SLOT(dealDeleteSlot()));
            menu->addAction(delAction);
            menu->exec(QCursor::pos());
        }
    }
}
//
void WeekReportMainFrame::dealCellClickedSlot(int row, int col)
{

    if(ui->tableWidget->item(row,col)->text() == "点击查看")
    {
        WeekReport * report = new WeekReport("查看",ui->tableWidget->item(row,0)->text(),ui->tableWidget->item(row,1)->text());
        report->show();
    }
}

void WeekReportMainFrame::on_pushButton_dontSubmit_clicked(bool flag)
{
    if(ui->comboBox_period->currentText() != "无" && ui->comboBox_period->currentText() != "所有时段")
    {
        qDebug() << "have";
        Widget::openMySql();
        QSqlQuery query;
        //qDebug() << "sql = " << tr("select name from weekreport where time = '%1' and department='研发部'").arg(ui->comboBox_period->currentText());
        if(query.exec(tr("select name from weekreport where time = '%1' and department='研发部'").arg(ui->comboBox_period->currentText())))
        {
            if(query.size())
            {
                QSet<QString>sentNameSet;
                //把交过了的名字全放在set里
                for(int i = 0;i != query.size();++i)
                {
                    query.next();
                    qDebug() << query.value(0).toString();
                    sentNameSet.insert(query.value(0).toString());
                }
                //
                QString dontSentNameStr;
                for(int i = 0;i != allNameVec.size();++i)
                {
                    if(sentNameSet.find(allNameVec[i]) == sentNameSet.end())//没有找到，即没有交
                    {
                        dontSentNameStr += allNameVec[i] +";";
                        dontSentNameVec.push_back(allNameVec[i]);
                    }
                }
                if(!dontSentNameStr.isEmpty() && flag == false)
                {
                    QMessageBox::about(this,"没有交周报人员名单",dontSentNameStr);
                }
            }
        }
    }
    else
    {
        showDontUpdateDialog * msgBox = new showDontUpdateDialog("请选择时间段！");
        msgBox->show();
    }
}
//
void WeekReportMainFrame::saveAllNameVec()
{
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec("select name,ip from staffmsg where department='研发部'"))
    {
        if(query.size())
        {
            for(int i = 0;i != query.size();++i)
            {
                query.next();
                allNameVec.push_back(query.value(0).toString());
                allNameAndIpMap.insert(query.value(0).toString(),query.value(1).toString());
            }
        }
    }
}

void WeekReportMainFrame::on_pushButton_sendTipMsg_clicked()
{
    if(ui->comboBox_period->currentText() == "无" || ui->comboBox_period->currentText() == "所有时段")
    {
        showDontUpdateDialog * msgBox = new showDontUpdateDialog("请选择时间段！");
        msgBox->show();
        return;
    }
    dontSentNameVec.clear();
    on_pushButton_dontSubmit_clicked(true);
    //发送提醒通知
    QUdpSocket * sendTipUdp = new QUdpSocket(this);
    QByteArray sendMsg = "您的周报未交,请及时提交！";
    for(int i = 0;i != dontSentNameVec.size();++i)
    {
        sendTipUdp->writeDatagram(sendMsg,QHostAddress(allNameAndIpMap[dontSentNameVec[i]]),4512);
    }
    showDontUpdateDialog * msgBox = new showDontUpdateDialog("已发送提醒通知！");
    msgBox->show();
}
