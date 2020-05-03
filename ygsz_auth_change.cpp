#include "ygsz_auth_change.h"
#include "ui_ygsz_auth_change.h"
#include "widget.h"

YGSZ_Auth_Change::YGSZ_Auth_Change(QWidget *parent,int level) :
    ui(new Ui::YGSZ_Auth_Change)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle("权限修改");
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    userLevel = level;
    ui->tableWidget_Owner->setColumnCount(2);
    ui->tableWidget_Owner->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_Owner->setSelectionMode(QAbstractItemView::SingleSelection);
    showAllName();
    flushAuthorityName(userLevel);
    if(level == 0)
    {
        ui->groupBox->setTitle("修改超级管理权限");
    }
    if(level == 1)
    {
        ui->groupBox->setTitle("修改部门主任权限");
    }
    if(level == 2)
    {
        ui->groupBox->setTitle("修改总经办权限");
    }
    if(level == 3)
    {
        ui->groupBox->setTitle("修改库存管理权限");
    }
    if(level == 4)
    {
        ui->groupBox->setTitle("修改采购权限");
    }
    if(level == 5)
    {
        ui->groupBox->setTitle("修改图样编号权限");
    }
    if(level == 6)
    {
        ui->groupBox->setTitle("修改物料编号权限");
    }
}

YGSZ_Auth_Change::~YGSZ_Auth_Change()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void YGSZ_Auth_Change::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void YGSZ_Auth_Change::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void YGSZ_Auth_Change::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void YGSZ_Auth_Change::showAllName()
{
    //设置tableview一次只能可选一行
    ui->tableWidget_All->setColumnCount(2);
    ui->tableWidget_All->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_All->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList header;
    header << "工号" << "姓名";
    ui->tableWidget_All->setHorizontalHeaderLabels(header);
    if(!Widget::openMySql())
    {
        QMessageBox::warning(this,"警告",tr("连接数据库失败:%1！").arg(QSqlDatabase::database().lastError().text()),QMessageBox::Ok);
        return;
    }else
    {
        QSqlQuery query;
        if(!query.exec("select count(*) from staffmsg;"))
        {
            QMessageBox::warning(this,"警告","加载数据失败，请重试！",QMessageBox::Ok);
            return;
        }
        query.next();
        int rowNum = 0;//数据库中数据行数决定table的row
        rowNum = query.value(0).toInt();

        if(rowNum == 0)
        {
            return;
        }
        ui->tableWidget_All->setRowCount(rowNum);
        query.exec("select staffid,name from staffmsg order by staffid asc");

        for(int i = 0; i < rowNum; i++)
        {
            query.next();
            ui->tableWidget_All->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_All->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));

        }
        QSqlDatabase::database().close();
        //update();
    }
}



void YGSZ_Auth_Change::flushAuthorityName(int level)
{
    ui->tableWidget_Owner->clear();
    ui->tableWidget_Owner->setColumnCount(2);
    ui->tableWidget_Owner->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_Owner->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList header;
    header << "工号" << "姓名";
    ui->tableWidget_Owner->setHorizontalHeaderLabels(header);
    if(!Widget::openMySql())
    {
        QMessageBox::warning(this,"警告","连接数据库失败！",QMessageBox::Ok);
        return;
    }else
    {
        QSqlQuery query;
        if(!query.exec(tr("select count(*) from staffmsg where level = '%1';").arg(level)))
        {
            QMessageBox::warning(this,"警告","加载数据失败，请重试！",QMessageBox::Ok);
            return;
        }
        query.next();
        int rowNum = 0;//数据库中数据行数决定table的row
        rowNum = query.value(0).toInt();

        if(rowNum == 0)
        {
            return;
        }
        ui->tableWidget_Owner->setRowCount(rowNum);
        query.exec(tr("select staffid,name from staffmsg where level = '%1'").arg(level));

        for(int i = 0; i < rowNum; i++)
        {
            query.next();
            ui->tableWidget_Owner->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_Owner->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        }
        QSqlDatabase::database().close();
        //update();
    }

}

void YGSZ_Auth_Change::on_pushButton_clicked()
{
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec(tr("select level from staffmsg where name = '%1'").arg(LoginWindow::userName)))
    {
        query.next();
        LoginWindow::userLevel = query.value(0).toInt();
    }
    emit emitFlushAuthLineEditSig();
    this->close();
}

void YGSZ_Auth_Change::on_toolButton_clicked()
{
    this->close();
}

void YGSZ_Auth_Change::on_pushButton_Push_clicked()
{
    if(isClickedLeftTabelWidgetFlag == false)
    {
        QMessageBox::warning(this,"提示","请先在左栏选择员工！  ");
        return;
    }
    //权限
    qDebug () << "level = " << LoginWindow::userLevel << ":" << LoginWindow::userName;
    if(LoginWindow::userLevel == 0 || LoginWindow::userName == "吴胜兵")
    {
        int row= ui->tableWidget_All->currentIndex().row();
        QString staffID = ui->tableWidget_All->item(row,0)->text();

        if(Widget::openMySql())
        {
            QSqlQuery query;
            if(query.exec(tr("select count(*) from staffmsg where staffid = '%1'").arg(staffID)))
            {
                query.next();
                if(query.value(0) == 0)
                {
                    QMessageBox::warning(this,"提示","请先在左栏选择员工！  ");
                    return;
                }else
                {
                    if(query.exec(tr("update staffmsg set level = '%1' where staffid = '%2'").arg(userLevel).arg(staffID)))
                    {
                        QSqlDatabase::database().commit();
                        flushAuthorityName(userLevel);
                    }
                }

            }
        }
    }else{
        //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
}


void YGSZ_Auth_Change::on_tableWidget_All_cellClicked(int row, int column)
{
    isClickedLeftTabelWidgetFlag = true;
}

void YGSZ_Auth_Change::on_lineEdit_Name_textChanged(const QString &arg1)
{
    if(Widget::openMySql())
    {

        //设置各个按钮外观
        ui->tableWidget_All->clear();
        QStringList header;
        header << "工号" << "姓名";
        ui->tableWidget_All->setHorizontalHeaderLabels(header);
        QSqlQuery query;
        if(!query.exec(tr("select count(*) from staffmsg where name like '%%1%'").arg(ui->lineEdit_Name->text())))
        {
            //QMessageBox::warning(this,"警告","加载数据失败，请重试！",QMessageBox::Ok);
            return;
        }
        query.next();
        int rowNum = 0;//数据库中数据行数决定table的row

        rowNum = query.value(0).toInt();
        if(rowNum == 0)
        {
            return;
        }
        ui->tableWidget_All->setRowCount(rowNum);
        query.exec(tr("select staffid,name from staffmsg where name like '%%1%'").arg(ui->lineEdit_Name->text()));

        for(int i = 0; i < rowNum; i++)
        {
            query.next();

            ui->tableWidget_All->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_All->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        }
    }
}

void YGSZ_Auth_Change::on_pushButton_Pop_clicked()
{
    if(isClickedRightTabelWidgetFlag == false)
    {
        QMessageBox::warning(this,"提示","请先在右栏选择员工！  ");
        return;
    }
    //权限
    if(LoginWindow::userName != "吴胜兵" && LoginWindow::userLevel != 0)
    {
        //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
    int row= ui->tableWidget_Owner->currentIndex().row();
    QString staffID = ui->tableWidget_Owner->item(row,0)->text();

    if(Widget::openMySql())
    {
        QSqlQuery query;
        if(query.exec(tr("select count(*) from staffmsg where staffid = '%1'").arg(staffID)))
        {
            query.next();
            if(query.value(0) == 0)
            {
                QMessageBox::warning(this,"提示","请先在左栏选择员工！  ");
                return;
            }else
            {
                if(query.exec(tr("update staffmsg set level = '9' where staffid = '%1'").arg(staffID)))
                {
                    QSqlDatabase::database().commit();
                    flushAuthorityName(userLevel);
                }
            }

        }
    }
}

void YGSZ_Auth_Change::on_tableWidget_Owner_cellClicked(int row, int column)
{
    isClickedRightTabelWidgetFlag = true;
}
