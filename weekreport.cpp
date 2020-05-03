#include "weekreport.h"
#include "ui_weekreport.h"

WeekReport::WeekReport(const QString showType,QString name,const QString time,QWidget *parent) :showType(showType),
    name(name),time(time),QWidget(parent),
    ui(new Ui::WeekReport)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

    //init all the same property
    initAllTable();

    //init table
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    if(showType == "新建")
    {
        initTableForNew();
        ui->pushButton->setText("提交");
        this->setWindowTitle("新增个人周报");
    }else
    {
        //查看
        //初始化combox
        QLineEdit * lineEdit = new QLineEdit;
        lineEdit->setReadOnly(true);
        lineEdit->setFont(QFont("Timers",12,QFont::Normal));
        lineEdit->setAlignment(Qt::AlignCenter);
        ui->comboBox_time->setLineEdit(lineEdit);
        ui->pushButton->setText("确定");
        this->setWindowTitle("查看周报");
    }
    showReportToTable(showType);
    ui->scrollArea->setStyle(QStyleFactory::create("fusion"));
}

WeekReport::~WeekReport()
{
    delete ui;
}


//下面三个函数实现没有边框的窗体鼠标移动功能
void WeekReport::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void WeekReport::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void WeekReport::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void WeekReport::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void WeekReport::on_pushButton_close_clicked()
{
    this->close();
}

void WeekReport::on_pushButton_max_clicked()
{
    QDesktopWidget * desktop = QApplication::desktop();
    if(this->width() != desktop->screenGeometry().width())
    {
        this->resize(desktop->screenGeometry().width(),desktop->screenGeometry().height());
        this->move(0,0);
        //设置背景图片
        this->autoFillBackground();
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
        this->setPalette(palette);
        ui->scrollAreaWidgetContents->resize(desktop->screenGeometry().width()-20,1500);
    }
    else
    {
        this->resize(1086,770);
        this->move((desktop->screenGeometry().width() - this->width())/2,(desktop->screenGeometry().height() - this->height())/2);
        //设置背景图片
        this->autoFillBackground();
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
        this->setPalette(palette);
        ui->scrollAreaWidgetContents->resize(1069,1500);
    }
}
//
void WeekReport::initTableForNew()
{
#if 0
    //1
    ui->tableWidget_nowWork->setRowCount(2);
    QTableWidgetItem * item0 = new QTableWidgetItem("");
    QTableWidgetItem * item1 = new QTableWidgetItem("");
    item0->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget_nowWork->setItem(0,0,item0);
    ui->tableWidget_nowWork->setItem(0,1,item1);
    ui->tableWidget_nowWork->setItem(1,0,getNewLineIconItem());

    //2
    ui->tableWidget_thisWeekWork->setRowCount(2);
    QTableWidgetItem * item2 = new QTableWidgetItem("");
    QTableWidgetItem * item3 = new QTableWidgetItem("");
    QTableWidgetItem * item4 = new QTableWidgetItem("");
    QTableWidgetItem * item5 = new QTableWidgetItem("");
    QTableWidgetItem * item6 = new QTableWidgetItem("");
    QTableWidgetItem * item7 = new QTableWidgetItem("");

    ui->tableWidget_thisWeekWork->setItem(0,0,item2);
    ui->tableWidget_thisWeekWork->setItem(0,1,item3);
    ui->tableWidget_thisWeekWork->setItem(0,2,item4);
    ui->tableWidget_thisWeekWork->setItem(0,3,item5);
    ui->tableWidget_thisWeekWork->setItem(0,4,item6);
    ui->tableWidget_thisWeekWork->setItem(0,5,item7);
    ui->tableWidget_thisWeekWork->setItem(1,0,getNewLineIconItem());

    //3
    ui->tableWidget_nextWeekWork->setRowCount(2);
    QTableWidgetItem * item8 = new QTableWidgetItem("");
    QTableWidgetItem * item9 = new QTableWidgetItem("");
    QTableWidgetItem * item10 = new QTableWidgetItem("");

    ui->tableWidget_nextWeekWork->setItem(0,0,item8);
    ui->tableWidget_nextWeekWork->setItem(0,1,item9);
    ui->tableWidget_nextWeekWork->setItem(0,2,item10);
    ui->tableWidget_nextWeekWork->setItem(1,0,getNewLineIconItem());
#endif
    //初始化个人信息
    ui->lineEdit_name->setText(name);
    QSqlQuery query;
    if(query.exec(tr("select position,department from staffmsg where name = '%1'").arg(name)))
    {
        query.next();
        ui->lineEdit_position->setText(query.value(0).toString());
        ui->lineEdit_department->setText(query.value(1).toString());
    }
    //初始化combox
    QLineEdit * lineEdit = new QLineEdit;
    lineEdit->setReadOnly(true);
    lineEdit->setFont(QFont("Timers",12,QFont::Normal));
    lineEdit->setAlignment(Qt::AlignCenter);
    ui->comboBox_time->setLineEdit(lineEdit);
    //设置下拉居中显示
    //static_cast<QStandardItemModel*>(ui->comboBox_time->view()->model())->item(0)->setTextAlignment(Qt::AlignCenter);

    //初始化时间段
    int year = QDate::currentDate().toString("yyyy").toInt();
    int mouth = QDate::currentDate().toString("MM").toInt();
    int day = QDate::currentDate().toString("dd").toInt();
    QDate date(year,mouth,day);
    int dayOfWeek = date.dayOfWeek();
    if(dayOfWeek == 1)
    {
        QDateTime time = QDateTime::currentDateTime();
        //QDateTime time(date);
        QString lastFriday = time.addDays(-3).toString("yyyy/MM/dd");
        QString lastMonday = time.addDays(-7).toString("yyyy/MM/dd");
        QString showTime0 =  lastMonday+"-"+lastFriday;
        ui->comboBox_time->addItem(showTime0);

        QString thisMonday = time.toString("yyyy/MM/dd");
        QString thisFriday = time.addDays(dayOfWeek+4).toString("yyyy/MM/dd");
        QString showTime =  thisMonday+"-"+thisFriday;
        ui->comboBox_time->addItem(showTime);
    }else
    {
        QDateTime time = QDateTime::currentDateTime();
        QString thisFriday = time.addDays(5-dayOfWeek).toString("yyyy/MM/dd");
        QString thisMonday = time.addDays(-(dayOfWeek-1)).toString("yyyy/MM/dd");
        QString showTime =  thisMonday+"-"+thisFriday;
        ui->comboBox_time->addItem(showTime);
    }
}
//
void WeekReport::initAllTable()
{
    //1
    ui->tableWidget_nowWork->setColumnCount(2);
    ui->tableWidget_nowWork->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_nowWork->setIconSize(QSize(35,28));
    QStringList header;
    header << "参与项目" <<"任务安排";
    ui->tableWidget_nowWork->setHorizontalHeaderLabels(header);

    ui->tableWidget_nowWork->setColumnWidth(0,250);
    connect(ui->tableWidget_nowWork,SIGNAL(itemChanged(QTableWidgetItem*)),ui->tableWidget_nowWork,SLOT(resizeRowsToContents()));

    //2
    ui->tableWidget_thisWeekWork->setColumnCount(6);
    ui->tableWidget_thisWeekWork->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_thisWeekWork->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_thisWeekWork->setIconSize(QSize(35,28));
    header.clear();
    header << "工作内容" <<"完成情况(%)" << "未完成原因" << "应对措施" << "预完成时间" << "备注";
    ui->tableWidget_thisWeekWork->setHorizontalHeaderLabels(header);
    connect(ui->tableWidget_thisWeekWork,SIGNAL(itemChanged(QTableWidgetItem*)),ui->tableWidget_thisWeekWork,SLOT(resizeRowsToContents()));

    //3
    ui->tableWidget_nextWeekWork->setColumnCount(3);
    ui->tableWidget_nextWeekWork->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_nextWeekWork->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_nextWeekWork->setIconSize(QSize(35,28));
    header.clear();
    header << "计划或安排工作内容" <<"预计完成时间" << "备注";
    ui->tableWidget_nextWeekWork->setHorizontalHeaderLabels(header);
    connect(ui->tableWidget_nextWeekWork,SIGNAL(itemChanged(QTableWidgetItem*)),ui->tableWidget_nextWeekWork,SLOT(resizeRowsToContents()));

    //
    connect(ui->tableWidget_nowWork,SIGNAL(cellClicked(int,int)),this,SLOT(dealNowWorkCellClickedSlot(int,int)));
    connect(ui->tableWidget_thisWeekWork,SIGNAL(cellClicked(int,int)),this,SLOT(dealThisWeekWorkCellClickedSlot(int,int)));
    connect(ui->tableWidget_nextWeekWork,SIGNAL(cellClicked(int,int)),this,SLOT(dealNextWeekWorkCellClickedSlot(int,int)));
}
//
QTableWidgetItem * WeekReport::getNewLineIconItem()
{
    QTableWidgetItem * item_newRow = new QTableWidgetItem("新增一行");
    item_newRow->setIcon(QIcon(":./images/新增一行.png"));
    item_newRow->setTextColor(Qt::blue);
    item_newRow->setBackgroundColor(QColor(235,235,235));
    return item_newRow;
}
//
void WeekReport::dealNowWorkCellClickedSlot(int row, int col)
{
    if(row == ui->tableWidget_nowWork->rowCount() -1 && col > 0)
    {
        return;
    }
    if(ui->tableWidget_nowWork->item(row,col)->text() == "新增一行")
    {
        //判断是否任由可用单元格可用，如果有则不可新增
        if(ui->tableWidget_nowWork->item(row-1,col)->text().trimmed().isEmpty())
        {
            showDontUpdateDialog * msgBox = new showDontUpdateDialog("仍有单元格可用！");
            msgBox->show();
            return;
        }
        ui->tableWidget_nowWork->setRowCount(row+2);
        QTableWidgetItem * item0 = new QTableWidgetItem("");
        QTableWidgetItem * item1 = new QTableWidgetItem("");
        item0->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_nowWork->setItem(row,0,item0);
        ui->tableWidget_nowWork->setItem(row,1,item1);
        ui->tableWidget_nowWork->setItem(row+1,0,getNewLineIconItem());
    }
}
//
void WeekReport::dealThisWeekWorkCellClickedSlot(int row, int col)
{
    if(row == ui->tableWidget_thisWeekWork->rowCount() -1 && col > 0)
    {
        return;
    }
    if(ui->tableWidget_thisWeekWork->item(row,col)->text() == "新增一行")
    {
        //判断是否任由可用单元格可用，如果有则不可新增
        if(ui->tableWidget_thisWeekWork->item(row-1,col)->text().trimmed().isEmpty())
        {
            showDontUpdateDialog * msgBox = new showDontUpdateDialog("仍有单元格可用！");
            msgBox->show();
            return;
        }
        ui->tableWidget_thisWeekWork->setRowCount(row+2);
        QTableWidgetItem * item2 = new QTableWidgetItem("");
        QTableWidgetItem * item3 = new QTableWidgetItem("");
        QTableWidgetItem * item4 = new QTableWidgetItem("");
        QTableWidgetItem * item5 = new QTableWidgetItem("");
        QTableWidgetItem * item6 = new QTableWidgetItem("");
        QTableWidgetItem * item7 = new QTableWidgetItem("");

        ui->tableWidget_thisWeekWork->setItem(row,0,item2);
        ui->tableWidget_thisWeekWork->setItem(row,1,item3);
        ui->tableWidget_thisWeekWork->setItem(row,2,item4);
        ui->tableWidget_thisWeekWork->setItem(row,3,item5);
        ui->tableWidget_thisWeekWork->setItem(row,4,item6);
        ui->tableWidget_thisWeekWork->setItem(row,5,item7);
        ui->tableWidget_thisWeekWork->setItem(row+1,0,getNewLineIconItem());
    }
}
//
void WeekReport::dealNextWeekWorkCellClickedSlot(int row, int col)
{
    if(row == ui->tableWidget_nextWeekWork->rowCount() -1 && col > 0)
    {
        return;
    }
    if(ui->tableWidget_nextWeekWork->item(row,col)->text() == "新增一行")
    {
        //判断是否任由可用单元格可用，如果有则不可新增
        if(ui->tableWidget_nextWeekWork->item(row-1,col)->text().trimmed().isEmpty())
        {
            showDontUpdateDialog * msgBox = new showDontUpdateDialog("仍有单元格可用！");
            msgBox->show();
            return;
        }
        ui->tableWidget_nextWeekWork->setRowCount(row+2);
        QTableWidgetItem * item8 = new QTableWidgetItem("");
        QTableWidgetItem * item9 = new QTableWidgetItem("");
        QTableWidgetItem * item10 = new QTableWidgetItem("");

        ui->tableWidget_nextWeekWork->setItem(row,0,item8);
        ui->tableWidget_nextWeekWork->setItem(row,1,item9);
        ui->tableWidget_nextWeekWork->setItem(row,2,item10);
        ui->tableWidget_nextWeekWork->setItem(row+1,0,getNewLineIconItem());
    }
}
//保存数据库
void WeekReport::on_pushButton_clicked()
{

    if(ui->pushButton->text() == "确定")
    {
        this->close();
        return;
    }
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    if(ui->tableWidget_nowWork->item(0,0)->text().trimmed().isEmpty() &&
            ui->tableWidget_thisWeekWork->item(0,0)->text().trimmed().isEmpty() &&
            ui->tableWidget_nextWeekWork->item(0,0)->text().trimmed().isEmpty())
    {
        showDontUpdateDialog * msgBox = new showDontUpdateDialog("未填写周报内容！");
        msgBox->show();
        return;
    }
    QString name = ui->lineEdit_name->text();
    QString position = ui->lineEdit_position->text();
    QString department = ui->lineEdit_department->text();
    QString time = ui->comboBox_time->currentText();
    QString needs = ui->textEdit_need->toPlainText();
    QString advices = ui->textEdit_advices->toPlainText();

    QString nowWork,thisWeekWork,nextWeekWork;
    //nowWork
    for(int i = 0;i != ui->tableWidget_nowWork->rowCount()-1;++i) //#:表示行分割，^:表示列分割
    {
        if(!ui->tableWidget_nowWork->item(i,0)->text().trimmed().isEmpty())
        {

            nowWork += "#";
            for(int j = 0; j != 2;++j)
            {
                //判断是否是特殊字符
                if(ui->tableWidget_nowWork->item(i,j)->text().indexOf("#") != -1 || ui->tableWidget_nowWork->item(i,j)->text().indexOf("^") != -1)
                {
                    QMessageBox::about(this,"",tr("不能包含#和^特殊字符：\n%1").arg(ui->tableWidget_nowWork->item(i,j)->text()));
                    return;
                }
                if(j == 1)
                {
                    nowWork += ui->tableWidget_nowWork->item(i,j)->text()+"  ";
                }
                else
                {
                    nowWork += ui->tableWidget_nowWork->item(i,j)->text() + "^";
                }

            }
        }
    }

    //thisWeekWork
    for(int i = 0;i != ui->tableWidget_thisWeekWork->rowCount()-1;++i) //#:表示行分割，^:表示列分割
    {
        if(!ui->tableWidget_thisWeekWork->item(i,0)->text().trimmed().isEmpty())
        {
            thisWeekWork += "#";
            for(int j = 0; j != 6;++j)
            {
                //判断是否是特殊字符
                if(ui->tableWidget_thisWeekWork->item(i,j)->text().indexOf("#") != -1 || ui->tableWidget_thisWeekWork->item(i,j)->text().indexOf("^") != -1)
                {
                    QMessageBox::about(this,"",tr("不能包含#和^特殊字符：\n%1").arg(ui->tableWidget_thisWeekWork->item(i,j)->text()));
                    return;
                }
                if(j == 5)
                {
                    thisWeekWork += ui->tableWidget_thisWeekWork->item(i,j)->text()+"  ";
                }
                else
                {
                    thisWeekWork += ui->tableWidget_thisWeekWork->item(i,j)->text() + "^";
                }

            }
        }

    }
    //nextWeekWork
    for(int i = 0;i != ui->tableWidget_nextWeekWork->rowCount()-1;++i) //#:表示行分割，^:表示列分割
    {
        if(!ui->tableWidget_nextWeekWork->item(i,0)->text().trimmed().isEmpty())
        {
            nextWeekWork += "#";
            for(int j = 0; j != 3;++j)
            {
                //判断是否是特殊字符
                if(ui->tableWidget_nextWeekWork->item(i,j)->text().indexOf("#") != -1 || ui->tableWidget_nextWeekWork->item(i,j)->text().indexOf("^") != -1)
                {
                    QMessageBox::about(this,"",tr("不能包含#和^特殊字符：\n%1").arg(ui->tableWidget_nextWeekWork->item(i,j)->text()));
                    return;
                }
                if(j == 2)
                {
                    nextWeekWork += ui->tableWidget_nextWeekWork->item(i,j)->text()+"  ";
                }
                else
                {
                    nextWeekWork += ui->tableWidget_nextWeekWork->item(i,j)->text() + "^";
                }

            }
        }
    }

//    qDebug() << "nowWork = " << nowWork;
//    qDebug() << "thisWeekWork = " << thisWeekWork;
//    qDebug() << "nextWeekWork = " << nextWeekWork;
    QSqlQuery query;
    //qDebug() << "count sql = " << tr("select count(*) from weekreport where name = '%1' and time = '%2'").arg(ui->lineEdit_name->text())
    //                                                                                                          .arg(ui->comboBox_time->currentText());
    if(query.exec(tr("select count(*) from weekreport where name = '%1' and time = '%2'").arg(ui->lineEdit_name->text())
                                                                                              .arg(ui->comboBox_time->currentText())))
    {
        query.next();
        qDebug() << "count(*) = " << query.value(0).toInt();
        if(query.value(0).toInt() > 0)
        {
            showDontUpdateDialog * msgBox = new showDontUpdateDialog("本周个人周报已提交！");
            msgBox->show();
            return;
        }
    }
    if(query.exec(tr("insert into weekreport values('%1','%2','%3','%4','%5 ','%6 ','%7 ','%8 ','%9 ')")
                  .arg(name).arg(department).arg(position).arg(time).arg(nowWork).arg(thisWeekWork).arg(nextWeekWork)
                  .arg(needs).arg(advices)))
    {
        QSqlDatabase::database().commit();
        emit sendFatherFlushTableSig(); //
        showDontUpdateDialog * msgBox = new showDontUpdateDialog("提交成功！");
        msgBox->show();
        this->close();//关闭串口
    }else
    {
        QSqlDatabase::database().rollback();
        showDontUpdateDialog * msgBox = new showDontUpdateDialog("提交失败！请重试！");
        msgBox->show();
    }
}
//
void WeekReport::showReportToTable(QString showType)
{
    QString sqlMsg;
    QSqlQuery query;
    if(showType == "查看")
    {
        ui->lineEdit_name->setText(name);
        ui->comboBox_time->setCurrentText(time);
        if(query.exec(tr("select position,department from staffmsg where name = '%1'").arg(name)))
        {
            query.next();
            ui->lineEdit_position->setText(query.value(0).toString());
            ui->lineEdit_department->setText(query.value(1).toString());
        }
        sqlMsg = tr("select nowWork,thisWeekWork,nextWeekWork,needs,advices from weekreport where name = '%1' and time='%2'").arg(name).arg(time);
    }
    else
    {
        sqlMsg = tr("select nowWork,thisWeekWork,nextWeekWork,needs,advices from weekreport where name = '%1' order by time desc limit 0,1").arg(name);
    }
    if(query.exec(sqlMsg))
    {
        if(query.size() == 0)
        {
            //1
            ui->tableWidget_nowWork->setRowCount(2);
            QTableWidgetItem * item0 = new QTableWidgetItem("");
            QTableWidgetItem * item1 = new QTableWidgetItem("");
            item0->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_nowWork->setItem(0,0,item0);
            ui->tableWidget_nowWork->setItem(0,1,item1);
            ui->tableWidget_nowWork->setItem(1,0,getNewLineIconItem());

            //2
            ui->tableWidget_thisWeekWork->setRowCount(2);
            QTableWidgetItem * item2 = new QTableWidgetItem("");
            QTableWidgetItem * item3 = new QTableWidgetItem("");
            QTableWidgetItem * item4 = new QTableWidgetItem("");
            QTableWidgetItem * item5 = new QTableWidgetItem("");
            QTableWidgetItem * item6 = new QTableWidgetItem("");
            QTableWidgetItem * item7 = new QTableWidgetItem("");

            ui->tableWidget_thisWeekWork->setItem(0,0,item2);
            ui->tableWidget_thisWeekWork->setItem(0,1,item3);
            ui->tableWidget_thisWeekWork->setItem(0,2,item4);
            ui->tableWidget_thisWeekWork->setItem(0,3,item5);
            ui->tableWidget_thisWeekWork->setItem(0,4,item6);
            ui->tableWidget_thisWeekWork->setItem(0,5,item7);
            ui->tableWidget_thisWeekWork->setItem(1,0,getNewLineIconItem());

            //3
            ui->tableWidget_nextWeekWork->setRowCount(2);
            QTableWidgetItem * item8 = new QTableWidgetItem("");
            QTableWidgetItem * item9 = new QTableWidgetItem("");
            QTableWidgetItem * item10 = new QTableWidgetItem("");

            ui->tableWidget_nextWeekWork->setItem(0,0,item8);
            ui->tableWidget_nextWeekWork->setItem(0,1,item9);
            ui->tableWidget_nextWeekWork->setItem(0,2,item10);
            ui->tableWidget_nextWeekWork->setItem(1,0,getNewLineIconItem());
            return;
        }
        query.next();
        QString nowWork= query.value(0).toString();
        QString thisWeekWork = query.value(1).toString();
        QString nextWeekWord = query.value(2).toString();
        QString needs = query.value(3).toString();
        QString advices = query.value(4).toString();
#if 1
        qDebug() << query.value(0).toString();
        qDebug() << query.value(1).toString();
        qDebug() << query.value(2).toString();
        qDebug() << query.value(3).toString();
        qDebug() << query.value(4).toString();
#endif
        //目前参与的项目和任务显示
        int rowNum = 0;
        while(nowWork.indexOf("#") != -1)
        {
            rowNum++;
            QString oneTaskStr;
            ui->tableWidget_nowWork->setRowCount(rowNum);
            if(nowWork.indexOf("#",2) != -1)
            {
                oneTaskStr = nowWork.mid(1,nowWork.indexOf("#",2)-1);
            }else
            {
                oneTaskStr = nowWork.mid(1,500);
            }
            QTableWidgetItem * item0 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));
            QTableWidgetItem * item1 = new QTableWidgetItem(oneTaskStr.mid(oneTaskStr.indexOf("^")+1,500));
            item0->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_nowWork->setItem(rowNum-1,0,item0);
            ui->tableWidget_nowWork->setItem(rowNum-1,1,item1);
            if(nowWork.indexOf("#",2) != -1)
            {
                nowWork = nowWork.mid(nowWork.indexOf("#",2),2000);
            }else{
                break;
            }
        }
        if(showType == "新建")
        {
            rowNum++;
            ui->tableWidget_nowWork->setRowCount(rowNum);
            ui->tableWidget_nowWork->setItem(rowNum-1,0,getNewLineIconItem());
        }
        //本周工作显示
        rowNum = 0;
        while(thisWeekWork.indexOf("#") != -1)
        {
            rowNum++;
            QString oneTaskStr;
            ui->tableWidget_thisWeekWork->setRowCount(rowNum);
            if(thisWeekWork.indexOf("#",2) != -1)
            {
                oneTaskStr = thisWeekWork.mid(1,thisWeekWork.indexOf("#",2)-1);
            }else
            {
                oneTaskStr = thisWeekWork.mid(1,500);
            }
            QTableWidgetItem * item0 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));

            oneTaskStr = oneTaskStr.mid(oneTaskStr.indexOf("^")+1,2000);
            QTableWidgetItem * item1 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));

            oneTaskStr = oneTaskStr.mid(oneTaskStr.indexOf("^")+1,2000);
            QTableWidgetItem * item2 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));

            oneTaskStr = oneTaskStr.mid(oneTaskStr.indexOf("^")+1,2000);
            QTableWidgetItem * item3 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));

            oneTaskStr = oneTaskStr.mid(oneTaskStr.indexOf("^")+1,2000);
            QTableWidgetItem * item4 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));

            oneTaskStr = oneTaskStr.mid(oneTaskStr.indexOf("^")+1,2000);
            QTableWidgetItem * item5 = new QTableWidgetItem(oneTaskStr);

            ui->tableWidget_thisWeekWork->setItem(rowNum-1,0,item0);
            ui->tableWidget_thisWeekWork->setItem(rowNum-1,1,item1);
            ui->tableWidget_thisWeekWork->setItem(rowNum-1,2,item2);
            ui->tableWidget_thisWeekWork->setItem(rowNum-1,3,item3);
            ui->tableWidget_thisWeekWork->setItem(rowNum-1,4,item4);
            ui->tableWidget_thisWeekWork->setItem(rowNum-1,5,item5);
            if(thisWeekWork.indexOf("#",2) != -1)
            {
                thisWeekWork = thisWeekWork.mid(thisWeekWork.indexOf("#",2),2000);
            }else{
                break;
            }
        }
        if(showType == "新建")
        {
            rowNum++;
            ui->tableWidget_thisWeekWork->setRowCount(rowNum);
            ui->tableWidget_thisWeekWork->setItem(rowNum-1,0,getNewLineIconItem());
        }
        //下周工作计划显示
        rowNum = 0;
        while(nextWeekWord.indexOf("#") != -1)
        {
            rowNum++;
            QString oneTaskStr;
            ui->tableWidget_nextWeekWork->setRowCount(rowNum);
            if(nextWeekWord.indexOf("#",2) != -1)
            {
                oneTaskStr = nextWeekWord.mid(1,nextWeekWord.indexOf("#",2)-1);
            }else
            {
                oneTaskStr = nextWeekWord.mid(1,500);
            }
            QTableWidgetItem * item0 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));

            oneTaskStr = oneTaskStr.mid(oneTaskStr.indexOf("^")+1,2000);
            QTableWidgetItem * item1 = new QTableWidgetItem(oneTaskStr.mid(0,oneTaskStr.indexOf("^")));

            oneTaskStr = oneTaskStr.mid(oneTaskStr.indexOf("^")+1,2000);
            QTableWidgetItem * item2 = new QTableWidgetItem(oneTaskStr);

            ui->tableWidget_nextWeekWork->setItem(rowNum-1,0,item0);
            ui->tableWidget_nextWeekWork->setItem(rowNum-1,1,item1);
            ui->tableWidget_nextWeekWork->setItem(rowNum-1,2,item2);

            if(nextWeekWord.indexOf("#",2) != -1)
            {
                nextWeekWord = nextWeekWord.mid(nextWeekWord.indexOf("#",2),2000);
            }else{
                break;
            }
        }
        if(showType == "新建")
        {
            rowNum++;
            ui->tableWidget_nextWeekWork->setRowCount(rowNum);
            ui->tableWidget_nextWeekWork->setItem(rowNum-1,0,getNewLineIconItem());
        }
        ui->textEdit_advices->setText(advices);
        ui->textEdit_need->setText(needs);

    }

}
