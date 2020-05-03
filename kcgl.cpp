#include "kcgl.h"
#include "ui_kcgl.h"
#include "widget.h"
#include "kcgl_subitem.h"
#include "wlbh.h"
#include "bom.h"
#include <QFileDialog>
#include "chukuform.h"

KCGL::KCGL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KCGL)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("库存管理");
    //显示tableView内容
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    //设置tableview一次只能可选一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->verticalHeader()->hide();
//    ui->calendarWidget->raise();
//    ui->calendarWidget->hide();

    action_menu1 = new QAction(this);
    action_chuku = new QAction(this);
    action_menu2 = new QAction(this);
    action_menu3 = new QAction(this);
    popMenu = new QMenu(ui->tableView);
    //添加菜单
    action_menu1->setText(QStringLiteral("查看"));
    popMenu->addAction(action_menu1);
    action_chuku->setText(QStringLiteral("出库"));
    popMenu->addAction(action_chuku);
    action_menu2->setText(QStringLiteral("修改"));
    popMenu->addAction(action_menu2);
    //信号槽处理编辑菜单
    action_menu3->setText(QStringLiteral("删除"));
    popMenu->addAction(action_menu3);
    //添加点击菜单信号槽
    connect(action_menu1,SIGNAL(triggered(bool)),this,SLOT(dealLook()));
    connect(action_chuku,SIGNAL(triggered(bool)),this,SLOT(dealChuku()));
    connect(action_menu2,SIGNAL(triggered(bool)),this,SLOT(dealEdit()));
    connect(action_menu3,SIGNAL(triggered(bool)),this,SLOT(dealDelete()));
    //菜单信号槽
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(dealMenu(QPoint)));
    model = new QSqlQueryModel(ui->tableView);

    flushStockShow();
    //初始化仓位combobox

    ui->comboBox->addItem("所有仓位");

    {
        QSqlQuery query;
        query.exec("select distinct 仓位 from storebill");
        for(int i = 0 ;i < query.size();i++)
        {
            query.next();
            ui->comboBox->addItem(query.value(0).toString());
        }

    }
    ui->comboBox->setCurrentText("所有仓位");
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->toolButton_time->hide();
}

KCGL::~KCGL()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void KCGL::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void KCGL::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void KCGL::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void KCGL::on_toolButton_clicked()
{
    this->showMinimized();
}

void KCGL::on_toolButton_2_clicked()
{
    this->close();
}

//显示库存信息
void KCGL::flushStockShow()
{
    if(Widget::openMySql())
    {
        model->setQuery(QString("select * from storebill"));
        ui->tableView->setModel(model);
    }
}

//定义菜单槽函数
void KCGL::dealMenu(QPoint pos)
{
    QModelIndex index = ui->tableView->indexAt(pos);
    if(index.isValid())
    {
        popMenu->exec(QCursor::pos());
    }
}

void KCGL::searchFlush()
{

    if(ui->lineEdit_inTime->text().isEmpty())
    {

        if(ui->comboBox->currentText() == "所有仓位")
        {

            model->setQuery(QString("select * from storebill where 物料编号 like '%%1%' and 检验报告编号 like "
                                    "'%%2%' and 物料名称 like '%%3%' and 规格型号 like '%%4%' and 供应商 like '%%5%' and 项目号 like '%%6%'")
                            .arg(ui->lineEdit_Num->text().trimmed()).arg(ui->lineEdit_serialID->text().trimmed())
                            .arg(ui->lineEdit_name->text().trimmed()).arg(ui->lineEdit_ID->text().trimmed()).arg(ui->lineEdit_privoder->text().trimmed()).arg(ui->lineEdit_proID->text().trimmed()));


        }else{


            model->setQuery(QString("select * from storebill  where 仓位='%1' and 物料编号 like '%%2%' and 检验报告编号 like "
                                    "'%%3%' and 物料名称 like '%%4%' and 规格型号 like '%%5%' and 供应商 like '%%6%' and 项目号 like '%%7%' and 检验日期 like ''")
                            .arg(ui->comboBox->currentText()).arg(ui->lineEdit_Num->text()).arg(ui->lineEdit_serialID->text())
                            .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_ID->text()).arg(ui->lineEdit_privoder->text()).arg(ui->lineEdit_proID->text()));

        }


    }else
    {
        if(ui->comboBox->currentText() == "所有仓位")
        {
            model->setQuery(QString("select * from storebill where 物料编号 like '%%1%' and 检验报告编号 like "
                                    "'%%2%' and 物料名称 like '%%3%' and 规格型号 like '%%4%' and 供应商 like '%%5%' and 项目号 like '%%6%' and 检验日期 like '%%7%'")
                            .arg(ui->lineEdit_Num->text().trimmed()).arg(ui->lineEdit_serialID->text().trimmed())
                            .arg(ui->lineEdit_name->text().trimmed()).arg(ui->lineEdit_ID->text().trimmed()).arg(ui->lineEdit_privoder->text().trimmed()).arg(ui->lineEdit_proID->text().trimmed()).arg(ui->lineEdit_inTime->text().trimmed()));

        }else
        {

            model->setQuery(QString("select * from storebill where 仓位='%1' and 物料编号 like '%%2%' and 检验报告编号 like "
                                    "'%%3%' and 物料名称 like '%%4%' and 规格型号 like '%%5%' and 供应商 like '%%6%' and 项目号 like '%%7%' and 检验日期 like '%%8%'")
                            .arg(ui->comboBox->currentText().trimmed()).arg(ui->lineEdit_Num->text().trimmed()).arg(ui->lineEdit_serialID->text().trimmed())
                            .arg(ui->lineEdit_name->text().trimmed()).arg(ui->lineEdit_ID->text().trimmed()).arg(ui->lineEdit_privoder->text().trimmed()).arg(ui->lineEdit_proID->text().trimmed()).arg(ui->lineEdit_inTime->text().trimmed()));
        }


    }
    ui->tableView->setModel(model);
}

void KCGL::on_comboBox_currentTextChanged(const QString &)
{
    searchFlush();
}


void KCGL::on_lineEdit_Num_textChanged(const QString &)
{
    searchFlush();
}

void KCGL::on_lineEdit_serialID_textChanged(const QString &)
{
    searchFlush();
}

void KCGL::on_lineEdit_name_textChanged(const QString &)
{
    searchFlush();
}

void KCGL::on_lineEdit_ID_textChanged(const QString &)
{
    searchFlush();
}

void KCGL::on_lineEdit_privoder_textChanged(const QString &)
{
    searchFlush();
}

void KCGL::on_lineEdit_proID_textChanged(const QString &)
{
    searchFlush();
}

void KCGL::on_pushButton_clicked()
{
    KCGL_subItem * kcgl_sub1 = new KCGL_subItem("新增");
    connect(kcgl_sub1,SIGNAL(emitFlushKCGLModelSig()),this,SLOT(flushStockShow()));
    kcgl_sub1->show();
}

//查看信号函数
void KCGL::dealLook()
{
    int row= ui->tableView->currentIndex().row();
    QModelIndex index1 = model->index(row,1);//选中行第一列的内容
    QVariant stockID = model->data(index1);   
    qDebug() << "stocidlook = " << stockID.toString();
    KCGL_subItem * kcgl_look = new KCGL_subItem("查看",stockID.toString());
    kcgl_look->show();
}

void KCGL::dealChuku()
{
    int row= ui->tableView->currentIndex().row();
    QModelIndex index1 = model->index(row,1);//选中行第一列的内容
    QVariant stockID = model->data(index1);
    QModelIndex index2 = model->index(row,9);//选中行第9列的内容出库数
    QVariant outNum = model->data(index2);
    QModelIndex index3 = model->index(row,10);//选中行第10列的内容库存数
    QVariant allNum = model->data(index3);
    ChuKuForm * chuku = new ChuKuForm(stockID.toString(),outNum.toInt(),allNum.toInt());
    connect(chuku,SIGNAL(sendFlushTableSig()),this,SLOT(flushStockShow()));
    chuku->show();
}

void KCGL::dealEdit()
{

    int row= ui->tableView->currentIndex().row();
    QModelIndex index1 = model->index(row,1);//选中行第一列的内容
    QVariant stockID = model->data(index1);
    KCGL_subItem * kcgl_edit = new KCGL_subItem("修改",stockID.toString());
    connect(kcgl_edit,SIGNAL(emitFlushKCGLModelSig()),this,SLOT(flushStockShow()));
    kcgl_edit->show();
}

//处理删除
void KCGL::dealDelete()
{
    //权限
    if(LoginWindow::userLevel != 3)
    {
        //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
    QMessageBox msgBox;
    msgBox.setDefaultButton(QMessageBox::No);
    int ret =  msgBox.warning(this,"删除提示","确定删除吗?   ",QMessageBox::Yes | QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        int row= ui->tableView->currentIndex().row();
        QModelIndex index1 = model->index(row,1);//选中行第一列的内容
        QVariant stockID = model->data(index1);

        if(Widget::openMySql())
        {
            QSqlQuery query;
            if(query.exec(QString("delete from storebill where 物料编号='%1'").arg(stockID.toString())))
            {
                QSqlDatabase::database().commit();
                QMessageBox::about(this,"提示","删除成功！  ");
                flushStockShow();
            }else
            {
                QSqlDatabase::database().rollback();
                QMessageBox::about(this,"提示","删除失败，请重试！  ");
            }

        }
        QSqlDatabase::database().close();
    }
}

void KCGL::on_lineEdit_inTime_textChanged(const QString &arg1)
{
    searchFlush();
}

void KCGL::on_toolButton_time_clicked()
{
    //ui->calendarWidget->show();
}

void KCGL::on_calendarWidget_selectionChanged()
{
//    ui->lineEdit_inTime->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
//    ui->calendarWidget->hide();
}




void KCGL::on_pushButton_wlbh_clicked()
{
    Wlbh * wlbh = new Wlbh;
    wlbh->show();
}

void KCGL::on_pushButton_daoru_clicked()
{
    //权限
    if(LoginWindow::userLevel != 3)
    {
        //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
    QString storeFilePath = QFileDialog::getOpenFileName(this,tr("选择库存表格"),"./",tr("库存表格(*.xlsx *.xls);"));

    if(storeFilePath.isEmpty())
    {
        QMessageBox::warning(this,"OA提示","请选择库存表！    ",QMessageBox::Ok);
        return;
    }
    QAxObject excel("Excel.Application");
    excel.dynamicCall("SetVisible(bool Visible)","false");
    excel.setProperty("DisplayAlerts",false);//不显示任何警告信息，如关闭“文件已修改，是否保存”
    //打开工作薄
    QAxObject * workbooks = excel.querySubObject("WorkBooks");
    //打开Excel
    QAxObject * storeWorkbook = workbooks->querySubObject("Open (const QString&)",storeFilePath);
    QAxObject * storeWorksheet = storeWorkbook->querySubObject("WorkSheets(int)",1);
    QAxObject * usedRange = storeWorksheet->querySubObject("UsedRange");
    QAxObject * rows = usedRange->querySubObject("Rows");
    QAxObject * columns = usedRange->querySubObject("Columns");
    int rowNum = rows->property("Count").toInt();
    int colNum = columns->property("Count").toInt();
    qDebug() << "rowNum = " << rowNum;
    qDebug() << "colNum = " << colNum;
    //判断列数
    qDebug () << "v(2,1)" << getCellValue(storeWorksheet,2,1);
    qDebug () << "v(2,12)" << getCellValue(storeWorksheet,2,15);

    if(getCellValue(storeWorksheet,2,1) == "序号" && getCellValue(storeWorksheet,2,15) == "项目号")
    {

        //QMessageBox::about(this,"OA提示","导入过程需要几分钟，请耐心等待，点击开始导入!   ");
        showDontUpdateDialog * msgBox = new showDontUpdateDialog("导入过程需要几分钟，请耐心等待！");
        msgBox->show();
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec("truncate table storebill;"))
        {
            qDebug() << "truncate success";
            for(int i = 3;i <= rowNum ; i++)
            {
                if(!query.exec(tr("insert into storebill values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15')")
                              .arg(getCellValue(storeWorksheet,i,1)).arg(getCellValue(storeWorksheet,i,2)).arg(getCellValue(storeWorksheet,i,3))
                              .arg(getCellValue(storeWorksheet,i,4)).arg(getCellValue(storeWorksheet,i,5)).arg(getCellValue(storeWorksheet,i,6))
                              .arg(getCellValue(storeWorksheet,i,7)).arg(getCellValue(storeWorksheet,i,8))
                              .arg(getCellValue(storeWorksheet,i,9)).arg(getCellValue(storeWorksheet,i,10)).arg(getCellValue(storeWorksheet,i,11))
                              .arg(getCellValue(storeWorksheet,i,12)).arg(getCellValue(storeWorksheet,i,13)).arg(getCellValue(storeWorksheet,i,14))
                               .arg(getCellValue(storeWorksheet,i,15))))
                {
                    QSqlDatabase::database().rollback();
                    QMessageBox::warning(this,"OA提示",tr("导入库存失败！\n错误信息：%1").arg(QSqlDatabase::database().lastError().text()),QMessageBox::Ok);
                    excel.dynamicCall("Quit()");
                    return;
                }
            }
            QSqlDatabase::database().commit();          
            flushStockShow();
            showDontUpdateDialog * msgBox = new showDontUpdateDialog("导入库存Excel成功！");
            msgBox->show();
        }

    }
    else
    {
        QMessageBox::warning(this,"OA提示","库存表格式不对！    ",QMessageBox::Ok);
    }
    excel.dynamicCall("Quit()");
}

void KCGL::on_pushButton_daochu_clicked()
{
    //权限
    if(LoginWindow::userLevel != 3)
    {
        //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
    QString savePath = QFileDialog::getSaveFileName(this,tr("导出库存"),tr("【%1】库存表.xlsx").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd")),tr("导出库存表(*.xlsx *.xls)"));
    qDebug() << "path = "  << savePath;
    if(savePath.isEmpty())
    {
        //QMessageBox::warning(this,"OA提示","请选择库存表导出位置！    ",QMessageBox::Ok);
        showDontUpdateDialog * msgBox1 = new showDontUpdateDialog("请选择库存表导出位置！");
        msgBox1->show();
        return;
    }
    //复制模板到临时文件
    if(!QFile::exists(qApp->applicationDirPath()+"/excelSource/storeBill-tempt.xlsx"))
    {
        if(!QFile::copy(qApp->applicationDirPath()+"/excelSource/storeBill.xlsx",qApp->applicationDirPath()+"/excelSource/storeBill-tempt.xlsx"))
        {
            qDebug() << "copy tempt.xlsx error";
            return;
        }
    }
    //打开temptExcel
    QAxObject excel("Excel.Application");
    excel.dynamicCall("SetVisible(bool Visible)","false");
    excel.setProperty("DisplayAlerts",false);//不显示任何警告信息，如关闭“文件已修改，是否保存”

    //QMessageBox::about(this,"OA提示","导出库存需要几分钟，请耐心等待，点击开始导出！     ");
    showDontUpdateDialog * msgBox1 = new showDontUpdateDialog("导出库存需要几分钟，请耐心等待！");
    msgBox1->show();
    //打开工作薄
    QAxObject * workbooks = excel.querySubObject("WorkBooks");

    //打开bomExcel
    QAxObject * storeWorkbook = workbooks->querySubObject("Open (const QString&)",qApp->applicationDirPath()+"/excelSource/storeBill-tempt.xlsx");
    QAxObject * storeWorksheet = storeWorkbook->querySubObject("WorkSheets(int)",1);


    //把storeBill数据表数据复制到tempt里
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec("select * from storeBill"))
    {
        for(int i = 0; i < query.size();i++)
        {
            query.next();
            for(int j = 1 ; j <= 15 ;j ++)
            {
                setCellString(storeWorksheet,i+3,j,query.value(j-1).toString());
            }

        }
    }
    //保存tempt表格
    storeWorkbook->dynamicCall("Save()");
    excel.dynamicCall("Quit()");

    if(!QFile::copy(qApp->applicationDirPath()+"/excelSource/storeBill-tempt.xlsx",savePath))
    {
        qDebug() << "copy-tempt.xlsx to user error";
        QFile::remove(savePath);
        QFile::copy(qApp->applicationDirPath()+"/excelSource/storeBill-tempt.xlsx",savePath);
    }
    QFile::remove(qApp->applicationDirPath()+"/excelSource/storeBill-tempt.xlsx");
    showDontUpdateDialog * msgBox = new showDontUpdateDialog("导出库存Excel成功！");
    msgBox->show();
}

void KCGL::setCellFontBold(QAxObject * storeWorksheet,int row, int column)
{
    QString cell;
    cell.append(QChar(column - 1 + 'A'));
    cell.append(QString::number(row));

    QAxObject *range = storeWorksheet->querySubObject("Range(const QString&)", cell);
    range = range->querySubObject("Font");
    range->setProperty("Bold", true);
}

QString KCGL::getCellValue(QAxObject *axSheet, int row, int col)
{
    QAxObject * Cell = axSheet->querySubObject("Cells(int,int)",row,col);
    return Cell->property("Value").toString();
}

void KCGL::setCellString(QAxObject * workSheet,int row, int column, const QString& value)
{
    QAxObject * range = workSheet->querySubObject("Cells(int,int)", row, column);
    range->dynamicCall("SetValue(const QString&)", value);
}

void KCGL::on_pushButton_2_clicked()
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
    }
    else
    {
        this->resize(1375,779);
        this->move((desktop->screenGeometry().width() - this->width())/2,(desktop->screenGeometry().height() - this->height())/2);
        //设置背景图片
        this->autoFillBackground();
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
        this->setPalette(palette);
    }
}
