#include "dakarecord.h"
#include "ui_dakarecord.h"

DaKaRecord::DaKaRecord(QString name,QWidget *parent) :
    userName(name),QWidget(parent),
    ui(new Ui::DaKaRecord)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("打卡记录查询");
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
    //table初始化
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    QStringList header;
    header << "姓名" <<"日期" << "星期" << "打卡记录";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    //初始化bombox
    initNameCombox();
    //初始table显示
    showMonthRecordToTableWidget();
}

DaKaRecord::~DaKaRecord()
{
    delete ui;
}


//下面三个函数实现没有边框的窗体鼠标移动功能
void DaKaRecord::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void DaKaRecord::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void DaKaRecord::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void DaKaRecord::on_pushButton_close_clicked()
{
    this->close();
}

void DaKaRecord::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void DaKaRecord::on_pushButton_inputExcel_clicked()
{
    saveDaKaRecordToSql();
}

void DaKaRecord::saveDaKaRecordToSql()
{
    if(!QSqlDatabase::database().isOpen())
    {
        if(Widget::openMySql() == false)
        {
            return;
        }
    }
    QString excelPath = NULL;
    excelPath = QFileDialog::getOpenFileName(this,tr("请选择考勤Excel表格"),"./",tr("考勤Excel表格(*.xlsx *.xls);"));
    if(excelPath.isNull())
    {
        showDontUpdateDialog * dontUpdate1 = new showDontUpdateDialog("请先选择Excel表格路径！");
        dontUpdate1->show();
        return;
    }
    //
    //设置excel属性
    QAxObject excel("Excel.Application");
    excel.dynamicCall("SetVisible(bool Visible)","false");
    excel.setProperty("DisplayAlerts",false);//不显示任何警告信息，如关闭“文件已修改，是否保存”
     //打开考勤Excel
    QAxObject * workbooks = excel.querySubObject("WorkBooks");
    QAxObject * bomWorkbook = workbooks->querySubObject("Open (const QString&)",excelPath);
    QAxObject * bomWorksheet = bomWorkbook->querySubObject("WorkSheets(int)",1);
    //判断bom格式是否正确

    if(!(Bom::getCellValue(bomWorksheet,1,1).toString() == "考勤号码" && Bom::getCellValue(bomWorksheet,1,2).toString() == "姓名"
         && Bom::getCellValue(bomWorksheet,1,3).toString() == "部门" && Bom::getCellValue(bomWorksheet,1,4).toString() == "日期"
         && Bom::getCellValue(bomWorksheet,1,5).toString() == "时间"))
    {
        excel.dynamicCall("Quit()");
        showDontUpdateDialog * dontUpdate2 = new showDontUpdateDialog("考勤Excel格式不对！\n表头应为:\n考勤号码,姓名,部门,日期,时间.");
        dontUpdate2->show();
        return;
    }
    qDebug() << "rowNum = " << Bom::getUsedRowsCount(bomWorksheet);

    showDontUpdateDialog * dontUpdate3 = new showDontUpdateDialog("正在导入数据库，请稍后...");
    dontUpdate3->show();

    int rowNum = Bom::getUsedRowsCount(bomWorksheet);
    int startRowNum = 0;
    for(int i = 2;i <= rowNum;++i)
    {
        if(Bom::getCellValue(bomWorksheet,i,2).toInt() == 0)
        {
            startRowNum = i;
            break;
        }
    }

    //QThread::sleep(1);
    //getStartTime(getStartTime(Bom::getCellValue(bomWorksheet,578,5).toString()));
    //qDebug() << "startRowNum" << startRowNum;
    QString maxDayTime;
    QSqlQuery query1;
    if(query1.exec(tr("select max(daytime) from dakarecord)")))
    {
        query1.next();
        maxDayTime = query1.value(0).toString();
        if(query1.exec(tr("delete from dakarecord where daytime = '%1'").arg(maxDayTime)))
        {
            QSqlDatabase::database().commit();
        }
        else
        {
            QSqlDatabase::database().rollback();
            QMessageBox::warning(this,"OA提示",tr("导入库存失败！\n错误信息：%1").arg(QSqlDatabase::database().lastError().text()),QMessageBox::Ok);
            return;
        }
    }
    else
    {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this,"OA提示",tr("导入库存失败！\n错误信息：%1").arg(QSqlDatabase::database().lastError().text()),QMessageBox::Ok);
        return;
    }
    for(int i = startRowNum;i <= rowNum;++i)
    {
        QSqlQuery query;
        //判断是否已经添加过
        if(query.exec(tr("select * from dakarecord where name = '%1' and daytime = '%2'").arg(Bom::getCellValue(bomWorksheet,i,2).toString()).arg(Bom::getCellValue(bomWorksheet,i,4).toString())))
        {
            if(query.size())
            {
                continue;
            }
        }
        if(!query.exec(tr("insert into dakarecord values('%1','%2','%3','%4 ','%5')")
                      .arg(Bom::getCellValue(bomWorksheet,i,2).toString()).arg(Bom::getCellValue(bomWorksheet,i,3).toString()).arg(Bom::getCellValue(bomWorksheet,i,4).toString())
                      .arg(Bom::getCellValue(bomWorksheet,i,5).toString()).arg(getDayOfWeek(Bom::getCellValue(bomWorksheet,i,4).toString()))))
        {
            QSqlDatabase::database().rollback();
            QMessageBox::warning(this,"OA提示",tr("导入库存失败！\n错误信息：%1").arg(QSqlDatabase::database().lastError().text()),QMessageBox::Ok);
            break;
        }
    }
    QSqlDatabase::database().commit();
    excel.dynamicCall("Quit()");
    dontUpdate3->close();
    showDontUpdateDialog * dontUpdate4 = new showDontUpdateDialog("考勤Excel成功导入数据库！");
    dontUpdate4->show();
}



int DaKaRecord::getDayOfWeek(QString dayTime)
{
    int year,mouth,day;
    year = dayTime.mid(0,4).toInt();
    mouth = dayTime.mid(5,2).toInt();
    day = dayTime.mid(8,2).toInt();
    QDate date(year,mouth,day);
    return date.dayOfWeek();
}

void DaKaRecord::showMonthRecordToTableWidget()
{
    QSqlQuery query;
    //qDebug() << tr("select name,daytime,week,record from dakarecord where name = '%1' and daytime like '%2%'").arg(ui->comboBox_name->currentText()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText());
    if(query.exec(tr("select name,daytime,week,record from dakarecord where name like '%%1%' and daytime like '%2%'").arg(ui->comboBox_name->currentText()=="所有员工"?"":ui->comboBox_name->currentText()).arg(ui->comboBox_year->currentText()+"-"+ui->comboBox_mouth->currentText())))
    {
        int rowNum = query.size();
        ui->tableWidget->setRowCount(rowNum);
        for(int i = 0;i != rowNum;++i)
        {
            query.next();
            QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
            QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
            QTableWidgetItem * item2 = new QTableWidgetItem(getWeekString(query.value(2).toInt()));
            QTableWidgetItem * item3 = new QTableWidgetItem(query.value(3).toString());


            item0->setTextAlignment(Qt::AlignCenter);
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);

            item3->setTextColor(Qt::blue);

            ui->tableWidget->setItem(i,0,item0);
            ui->tableWidget->setItem(i,1,item1);
            ui->tableWidget->setItem(i,2,item2);
            ui->tableWidget->setItem(i,3,item3);
        }
    }
}

QString DaKaRecord::getWeekString(int dayNum)
{
    switch (dayNum) {
    case 1:
        return "星期一";
        break;
    case 2:
        return "星期二";
        break;
    case 3:
        return "星期三";
        break;
    case 4:
        return "星期四";
        break;
    case 5:
        return "星期五";
        break;
    case 6:
        return "星期六";
        break;
    case 7:
        return "星期日";
        break;
    default:
        break;
    }
}

void DaKaRecord::on_pushButton_search_clicked()
{
    showMonthRecordToTableWidget();
}

void DaKaRecord::initNameCombox(const QString type)
{

    QSqlQuery query;
    if(query.exec("select name from staffmsg where onWork = '在职'"))
    {
        int nameNum = query.size();
        for(int i = 0;i != nameNum;++i)
        {
            query.next();
            ui->comboBox_name->addItem(query.value(0).toString());
        }
    }
    if(type != "tybh_sub")
    {
        ui->comboBox_name->setItemText(0,"所有员工");
        ui->comboBox_name->setCurrentText(userName);
    }

}

void DaKaRecord::on_comboBox_name_currentTextChanged(const QString &)
{
    showMonthRecordToTableWidget();
}

void DaKaRecord::on_comboBox_year_currentTextChanged(const QString &)
{
    showMonthRecordToTableWidget();
}

void DaKaRecord::on_comboBox_mouth_currentTextChanged(const QString &)
{
    showMonthRecordToTableWidget();
}
