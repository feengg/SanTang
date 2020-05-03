#include "ygsz.h"
#include "ui_ygsz.h"


YGSZ::YGSZ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YGSZ)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无边框
    this->setWindowTitle("员工管理");
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    //显示tableView内容
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    //设置tableview一次只能可选一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能编辑

    action_menu1 = new QAction(this);
    action_menu2 = new QAction(this);
    action_menu3 = new QAction(this);
    action_menu_offWork = new QAction(this);
    popMenu = new QMenu(ui->tableView);
    //添加菜单
    action_menu1->setText(QStringLiteral("查看"));
    popMenu->addAction(action_menu1);
    action_menu2->setText(QStringLiteral("修改"));
    popMenu->addAction(action_menu2);
    //离职
    action_menu_offWork->setText(QStringLiteral("移除到离职"));
    popMenu->addAction(action_menu_offWork);
    //信号槽处理编辑菜单
    action_menu3->setText(QStringLiteral("删除"));
    popMenu->addAction(action_menu3);

    //添加点击菜单信号槽
    connect(action_menu1,SIGNAL(triggered(bool)),this,SLOT(dealLook()));
    connect(action_menu2,SIGNAL(triggered(bool)),this,SLOT(dealEdit()));
    connect(action_menu3,SIGNAL(triggered(bool)),this,SLOT(dealDelete()));
    connect(action_menu_offWork,SIGNAL(triggered(bool)),this,SLOT(dealOffWork()));
    //菜单信号槽
    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(dealMenu(QPoint)));
    //初始化tableView
    //model = new QSqlQueryModel(ui->tableView);
    /*
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("工号"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("性别"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("部门"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("职位"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("婚姻状况"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("联系方式"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("IP地址"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("居住地址"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("工龄"));
    */
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    ui->tableView->setColumnCount(12);
    flushStaffShow();
    departmentComboBoxInit(ui->comboBox_department);
}

YGSZ::~YGSZ()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void YGSZ::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void YGSZ::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void YGSZ::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void YGSZ::on_toolButton_Close_clicked()
{
    this->close();
}

//定义菜单槽函数
void YGSZ::dealMenu(QPoint pos)
{
    QModelIndex index = ui->tableView->indexAt(pos);
    if(index.isValid())
    {
        popMenu->exec(QCursor::pos());
    }
}

void YGSZ::dealLook()
{
    int row= ui->tableView->currentIndex().row();
    QString staffID = ui->tableView->item(row,0)->text();
    if(Widget::openMySql())
    {
        QSqlQuery query;
        if(query.exec(tr("select * from staffmsg where staffid = '%1'").arg(staffID)))
        {
            query.next();
            YGSZ_New * ygsz_new = new YGSZ_New(2,0,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),
                                               query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),
                                               query.value(9).toString(),
                                               query.value(8).toString(),query.value(12).toString(),query.value(13).toString());
            ygsz_new->show();
        }

    }

}
void YGSZ::dealEdit()
{
    int row= ui->tableView->currentIndex().row();
    QString staffID = ui->tableView->item(row,0)->text();
    if(Widget::openMySql())
    {
        QSqlQuery query;
        if(query.exec(tr("select * from staffmsg where staffid = '%1'").arg(staffID)))
        {
            query.next();
            YGSZ_New * ygsz_new = new YGSZ_New(1,0,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),
                                               query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),
                                               query.value(9).toString(),
                                               query.value(8).toString(),query.value(12).toString(),query.value(13).toString());
            connect(ygsz_new,SIGNAL(emitFlushYgszSig()),this,SLOT(flushTableForSearch()));
            ygsz_new->show();
        }

    }
}

void YGSZ::dealDelete()
{
    //权限
    if(LoginWindow::userLevel != 2)
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
        QString staffID = ui->tableView->item(row,0)->text();

        if(Widget::openMySql())
        {
            QSqlQuery query;
            if(query.exec(QString("delete from staffmsg where staffid='%1'").arg(staffID)))
            {
                QSqlDatabase::database().commit();
                QMessageBox::about(this,"提示","删除成功！  ");
                flushTableForSearch();
            }else
            {
                QSqlDatabase::database().rollback();
                QMessageBox::about(this,"提示","删除失败，请重试！  ");
                flushTableForSearch();
            }

        }
    }
}

void YGSZ::on_toolButton_New_clicked()
{
    YGSZ_New * ygsz_new = new YGSZ_New(0);
    connect(ygsz_new,SIGNAL(emitFlushYgszSig()),this,SLOT(flushShowSlot()));
    ygsz_new->show();
}

void YGSZ::flushStaffShow()
{
    //设置各个按钮外观
    ui->tableView->clear();
    QStringList header;
    header << "工号" << "姓名" << "性别" << "部门" << "职位"<<"婚姻状况"<< "联系方式" << "IP地址" << "居住地址"<<"入职时间"<<"学历"<<"身份证号码";
    ui->tableView->setHorizontalHeaderLabels(header);

    if(0)
    {
        QMessageBox::warning(this,"警告","连接数据库失败！",QMessageBox::Ok);
        return;
    }else
    {
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }
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
        ui->tableView->setRowCount(rowNum);
        query.exec("select staffid,name,sex,department,position,marriage,phone,IP,address,worktime,学历,身份证 from staffmsg where onWork = '在职' order by staffid asc");

        for(int i = 0; i < rowNum; i++)
        {
            query.next();

            ui->tableView->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableView->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableView->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableView->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableView->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableView->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableView->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tableView->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
            ui->tableView->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
            ui->tableView->setItem(i,9,new QTableWidgetItem(query.value(9).toString()));
            ui->tableView->setItem(i,10,new QTableWidgetItem(query.value(10).toString()));
            ui->tableView->setItem(i,11,new QTableWidgetItem(query.value(11).toString()));

        }

        //update();
    }
}

void YGSZ::flushShowSlot()
{
    flushStaffShow();
    //QMessageBox::about(this,"提示","刷新成功！  ");
}

void YGSZ::on_pushButton_clicked()
{

}

void YGSZ::on_lineEdit_textChanged(const QString &)
{
    flushTableForSearch();
}

void YGSZ::on_lineEdit_2_textChanged(const QString &)
{
    flushTableForSearch();
}

void YGSZ::on_toolButton_Change_clicked()
{
    YGSZ_Authority * auth = new YGSZ_Authority;
    auth->show();
}

void YGSZ::on_toolButton_Mini_clicked()
{
    this->showMinimized();
}

void YGSZ::departmentComboBoxInit(QComboBox *combox)
{
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    combox->addItem("所有部门");
    if(query.exec("select  distinct department from staffmsg"))
    {
        if(query.size())
        {
            for(int i = 0;i != query.size();++i)
            {
                query.next();
                combox->addItem(query.value(0).toString());
            }
        }
    }
}
//
void YGSZ::flushTableForSearch()
{
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    //设置各个按钮外观
    ui->tableView->clear();
    QStringList header;
    header << "工号" << "姓名" << "性别" << "部门" << "职位"<<"婚姻状况"<< "联系方式" << "IP地址" << "居住地址"<<"入职时间"<<"学历" << "身份证号码";
    ui->tableView->setHorizontalHeaderLabels(header);
    QSqlQuery query;
    QString department,sex;
    if(ui->comboBox_department->currentText() != "所有部门")
    {
       department = ui->comboBox_department->currentText();
    }
    if(ui->comboBox_sex->currentText() != "所有")
    {
        sex = sex = ui->comboBox_sex->currentText();;
    }
    if(query.exec(tr("select staffid,name,sex,department,position,marriage,phone,IP,address,worktime,学历,身份证 from staffmsg where ip like '%%1%' and name like '%%2%' and department like '%%3%' "
                     "and sex like '%%4%' and onWork = '%5'").arg(ui->lineEdit_2->text()).arg(ui->lineEdit->text()).arg(department).arg(sex).arg(ui->comboBox_workState->currentText())))
    {
        ui->tableView->setRowCount(query.size());
        for(int i = 0; i < query.size(); i++)
        {
            query.next();

            ui->tableView->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableView->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableView->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableView->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableView->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableView->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableView->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tableView->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
            ui->tableView->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
            ui->tableView->setItem(i,9,new QTableWidgetItem(query.value(9).toString()));
            ui->tableView->setItem(i,10,new QTableWidgetItem(query.value(10).toString()));
            ui->tableView->setItem(i,11,new QTableWidgetItem(query.value(11).toString()));
        }
    }

}

void YGSZ::on_comboBox_department_currentTextChanged(const QString &)
{
    flushTableForSearch();
}

void YGSZ::on_comboBox_sex_currentTextChanged(const QString &)
{
    flushTableForSearch();
}

void YGSZ::dealOffWork()
{
    //权限
    if(LoginWindow::userLevel != 2)
    {
        //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
    QMessageBox msgBox;
    msgBox.setDefaultButton(QMessageBox::No);
    int ret =  msgBox.warning(this,"移除提示","确定要移除到离职状态吗?   ",QMessageBox::Yes | QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        int row= ui->tableView->currentIndex().row();
        QString staffID = ui->tableView->item(row,0)->text();

        if(Widget::openMySql())
        {
            QSqlQuery query;
            if(query.exec(tr("update staffmsg set onWork ='离职' where staffid='%1';").arg(staffID)))
            {
                QSqlDatabase::database().commit();
                QMessageBox::about(this,"提示","移除成功！  ");
                flushTableForSearch();
            }else
            {
                QSqlDatabase::database().rollback();
                QMessageBox::about(this,"提示","移除失败，请重试！  ");
            }
        }
    }
}

void YGSZ::on_comboBox_workState_currentTextChanged(const QString &)
{
    flushTableForSearch();
}
