#include "tybh.h"
#include "ui_tybh.h"
#include "tybh_sub.h"
#include <QIcon>
#include <QDebug>

TYBH::TYBH(QString showType,QString proNum,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TYBH)
{
    ui->setupUi(this);
    Widget::uiInit(this,"图号/文件编号清单");
    //打开数据库
    Widget::openMySql();
    //初始化table
    tableInit(showType);
    //显示table
    showTable(showType,proNum);
}

TYBH::~TYBH()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void TYBH::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void TYBH::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void TYBH::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}
//根据权限设置某些列不可编辑
void TYBH::dealTableDoubleClickedSlot(QTableWidgetItem * item)
{
    if(item->row() == ui->tableWidget->rowCount()-1)
    {
        item->setFlags(Qt::NoItemFlags);
    }
    if(LoginWindow::userLevel != 5)
    {
        if(item->column() >= 1 && item->column() <= 3)
        {
            item->setFlags(Qt::NoItemFlags);
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("该项由标准工程师填写！");
            dontUpdate->show();
            return;
        }
    }
}

void TYBH::on_toolButton_clicked()
{
    this->close();
}

void TYBH::on_pushButton_ok_clicked()
{
    this->close();
}

void TYBH::on_pushButton_new_clicked()
{
    Tybh_sub * tybh_sub = new Tybh_sub;
    connect(tybh_sub,SIGNAL(emitFlushTybhProjComboSig()),this,SLOT(on_flushProjNumComboSlot()));
    tybh_sub->show();
}

void TYBH::on_flushProjNumComboSlot()
{

    if(!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec("select projNum from tybhMsg order by dealTime desc"))
    {
        for(int i = 0 ; i < query.size() ; i ++)
        {
            query.next();
            //ui->comboBox_proNum->addItem(query.value(0).toString());
        }
    }
}

void TYBH::on_comboBox_proNum_currentTextChanged(const QString &arg1)
{
    if(!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    //显示图样信息
    if(query.exec(tr("select * from tybhMsg where projNum = '%1'").arg(1)))
    {
        query.next();
        ui->lineEdit_proNum->setText(query.value(0).toString());
        ui->lineEdit_proName->setText(query.value(1).toString());
        ui->lineEdit_productNum->setText(query.value(2).toString());
        ui->lineEdit_productName->setText(query.value(3).toString());
        //ui->lineEdit_name->setText(query.value(4).toString());
        //ui->lineEdit_dealTime->setText(query.value(5).toString());
    }
    //显示图纸编号table
    ui->tableWidget->clear();
    QStringList header;
    header << "名称" << "整/部件编号" << "图纸编号" << "结构件编号"<<"备注"<<"上移" << "下移" << "删除";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    if(query.exec(tr("select * from tybhProdMsg where projNum = '%1'").arg(1)))
    {
        ui->tableWidget->setRowCount(query.size()+1);

        //*****************设置末行新增保存
        QTableWidgetItem * item_newRow = newSaveAndNewItem("新增一行");
        QTableWidgetItem * item_save = newSaveAndNewItem("保存");
        //ui->tableWidget->setSpan(query.size(),4,1,4);
        ui->tableWidget->setItem(query.size(),1,item_newRow);
        ui->tableWidget->setItem(query.size(),3,item_save);
        //*******************

        //数据库图样显示table上
        for(int i = 0; i < ui->tableWidget->rowCount()-1 ; i++)
        {
            query.next();
            QTableWidgetItem * item0 = new QTableWidgetItem(query.value(2).toString());
            QTableWidgetItem * item1 = new QTableWidgetItem(query.value(3).toString());
            QTableWidgetItem * item2 = new QTableWidgetItem(query.value(4).toString());
            QTableWidgetItem * item3 = new QTableWidgetItem(query.value(5).toString());
            QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
            QTableWidgetItem * item_up = newSaveAndNewItem("上移");
            QTableWidgetItem * item_down = newSaveAndNewItem("下移");
            QTableWidgetItem * item_remove = newSaveAndNewItem("删除");
            item0->setTextAlignment(Qt::AlignCenter);
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setItem(i,0,item0);
            ui->tableWidget->setItem(i,1,item1);
            ui->tableWidget->setItem(i,2,item2);
            ui->tableWidget->setItem(i,3,item3);
            ui->tableWidget->setItem(i,4,item4);
            ui->tableWidget->setItem(i,5,item_up);
            ui->tableWidget->setItem(i,6,item_down);
            ui->tableWidget->setItem(i,7,item_remove);
        }

    }
}

void TYBH::dealCellClickedSlot(int x,int y)
{
    //新增一行
    if(ui->tableWidget->rowCount()-1 == x && y ==2)
    {
#if 0
        if(ui->tableWidget->item(x-1,0)->text().trimmed().isEmpty())
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("仍有可用单元格！");
            dontUpdate->show();
            return;
        }
#endif
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        for(int i = 0;i != 7;++i)
        {
            QTableWidgetItem * item_NULL = new QTableWidgetItem("");
            item_NULL->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,i,item_NULL);
            if(i == 5 || i == 6)
            {
                item_NULL->setFlags(item_NULL->flags() & ~Qt::ItemIsEditable);//双击不被改变、编辑
            }
        }
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,newSaveAndNewItem("新增一行"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,newSaveAndNewItem("保存"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,7,newSaveAndNewItem("上传附件"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,8,newSaveAndNewItem("待处理"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,9,newSaveAndNewItem("上移"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,10,newSaveAndNewItem("下移"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-2,11,newSaveAndNewItem("删除"));
    }
    //保存
    if(ui->tableWidget->rowCount()-1 == x && y == 5)
    {
        if(saveFlag == true)
        {
            if(ui->tableWidget->rowCount() == 1)
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("没有数据可保存！");
                dontUpdate->show();
                return;
            }
            //判断负责人有没有处理
            for(auto i = dealComboMap.begin(); i != dealComboMap.end();++i)
            {
                  qDebug() << "key = " << i.key();
                if(i.value()->currentText() == "待处理")
                {
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("有未处理项！");
                    dontUpdate->show();
                    return;
                }
            }
            Widget::openMySql();
            QSqlQuery query;
            nameSet.clear();
            if(query.exec(tr("delete from tybhprodmsg where projnum = '%1'").arg(ui->lineEdit_proNum->text())))
            {
                for(int i = 0 ; i < ui->tableWidget->rowCount()-1;i++)
                {
                    //判断是否为空,为空跳过
                    if(ui->tableWidget->item(i,0)->text().trimmed().isEmpty())
                    {
                        continue;
                    }
                    nameSet.insert(ui->tableWidget->item(i,6)->text());//保存所以设计人到set里
                    QString saveDealStr;
                    //负责人
                    if(ui->lineEdit_leaderName->text() == LoginWindow::userName)
                    {
                        if(dealComboMap.find(i) != dealComboMap.end())
                        {
                            saveDealStr = dealComboMap[i]->currentText();
                        }else{ //该行不是combox
                            saveDealStr = ui->tableWidget->item(i,8)->text();
                        }

                    }else if(ui->tableWidget->item(i,8)->text() == "驳回" && LoginWindow::userName == ui->tableWidget->item(i,6)->text())
                    {
                        saveDealStr = "待处理";
                    }else{
                        saveDealStr = ui->tableWidget->item(i,8)->text();
                    }

                    if(!query.exec(tr("insert into tybhprodMsg values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')").arg(ui->lineEdit_proNum->text())
                                   .arg(ui->tableWidget->item(i,0)->text()).arg(ui->tableWidget->item(i,1)->text()).arg(ui->tableWidget->item(i,2)->text())
                                   .arg(ui->tableWidget->item(i,3)->text()).arg(ui->tableWidget->item(i,4)->text()).arg(ui->tableWidget->item(i,5)->text())
                                   .arg(ui->tableWidget->item(i,6)->text()).arg(ui->tableWidget->item(i,7)->toolTip()).arg(saveDealStr)))
                    {
                        QMessageBox::warning(this,"OA提示","保存失败,请重试！  ",QMessageBox::Ok);
                        QSqlDatabase::database().rollback();
                        return;
                    }

                }
                QSqlDatabase::database().commit();
                bool sendFailFlag = false;
                //如果是设计人员
                if(LoginWindow::userName != ui->lineEdit_leaderName->text() && LoginWindow::userLevel != 5)
                {
                    if(!sendNotice(ui->lineEdit_leaderName->text(),"您有一份文件及图号申请待审核!"))
                    {
                        sendFailFlag = true;
                    }
                }
                //如果是项目负责人

                if(LoginWindow::userName == ui->lineEdit_leaderName->text())
                {
                    //发给设计人
                    nameSet.clear();
                    for(auto i = dealComboMap.begin();i != dealComboMap.end();++i)
                    {
                        nameSet.insert(ui->tableWidget->item(i.key(),6)->text());
                    }
                    foreach (const QString &name, nameSet)
                    {
                        qDebug() << "send name = " << name;
                        if(!sendNotice(name,"您的文件及图号负责人已审核!"))
                        {
                            sendFailFlag = true;
                            break;
                        }
                    }
                    //发个标准化
                    QString standName = "杨会英";
                    if(query.exec(tr("select name from staffmsg where level = '5'")))
                    {
                        if(query.size())
                        {
                            query.next();
                            standName = query.value(0).toString();
                        }
                    }
                    if(!sendNotice(standName,"负责人已审核文件及图号申请!"))
                    {
                        sendFailFlag = true;
                    }
                }
                //标准工程师
                if(LoginWindow::userLevel == 5)
                {
                    foreach (const QString &name, nameSet)
                    {
                        if(!sendNotice(name,"您的文件及图号标准工程师已编号!"))
                        {
                            sendFailFlag = true;
                            break;
                        }
                    }
                    if(!sendNotice(ui->lineEdit_leaderName->text(),"您审核的文件及图号标准工程师已编号!"))
                    {
                        sendFailFlag = true;
                    }

                }
                if(sendFailFlag == false)
                {
                    saveFlag = false;
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("通知成功！");
                    dontUpdate->show();
                }else{
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("通知失败！请检查网络后请重试");
                    dontUpdate->show();
                }
            }
        }
        else
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("数据内容未改变！");
            dontUpdate->show();
            return;
        }

    }
    //上传下载附件
    if(y == 7)
    {
        //上传
        if(ui->tableWidget->item(x,y)->text() == "上传附件")
        {
            UpOrLoadFileDialog * upDialog = new UpOrLoadFileDialog("Up",x);
            connect(upDialog,SIGNAL(sendFileNameAndRowNumToFatherSig(QString,int)),this,SLOT(getFileNameFromUpDialogSlot(QString,int)));
            upDialog->show();
        }
        //下载
        if(ui->tableWidget->item(x,y)->text() == "下载附件")
        {
            UpOrLoadFileDialog * upDialog = new UpOrLoadFileDialog("Load",x,ui->tableWidget->item(x,y)->toolTip());
            upDialog->show();
        }
    }
    //*********************
    if(LoginWindow::userLevel != 5 && (y == 9 || y == 10 || y ==11))
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作");
        dontUpdate->show();
        return;
    }
    //上移
    if(y == 9 && x != ui->tableWidget->rowCount()-1)
    {
        if(x == 0)
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("已经为最顶行！");
            dontUpdate->show();
            return;
        }
        QList < QTableWidgetItem * > CurRowItemsList;
        QList < QTableWidgetItem * > PreRowItemsList;
        for(int i = 0 ; i < 8;i ++)
        {
            CurRowItemsList.append(ui->tableWidget->takeItem(x,i));
            PreRowItemsList.append(ui->tableWidget->takeItem(x-1,i));
        }
        for(int i = 0; i < 8 ; i ++)
        {
            ui->tableWidget->setItem(x,i,PreRowItemsList.at(i));
            ui->tableWidget->setItem(x-1,i,CurRowItemsList.at(i));
        }
    }

    //下移
    if(y == 10 && x != ui->tableWidget->rowCount()-1)
    {
        if(x == ui->tableWidget->rowCount()-2)
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("已经为最底行！");
            dontUpdate->show();
            return;
        }
        QList < QTableWidgetItem * > CurRowItemsList;
        QList < QTableWidgetItem * > NextRowItemsList;
        for(int i = 0 ; i < 8;i ++)
        {
            CurRowItemsList.append(ui->tableWidget->takeItem(x,i));
            NextRowItemsList.append(ui->tableWidget->takeItem(x+1,i));
        }
        for(int i = 0; i < 8 ; i ++)
        {
            ui->tableWidget->setItem(x,i,NextRowItemsList.at(i));
            ui->tableWidget->setItem(x+1,i,CurRowItemsList.at(i));
        }
    }
    //删除
    if(y == 11 && x != ui->tableWidget->rowCount()-1)
    {
        QMessageBox msgBox;
        msgBox.setDefaultButton(QMessageBox::No);
        int ret =  msgBox.warning(this,"删除提示","确定删除吗?   ",QMessageBox::Yes | QMessageBox::No);
        if(ret == QMessageBox::Yes)
        {
            ui->tableWidget->removeRow(x);
        }
    }
}

QTableWidgetItem * TYBH::newSaveAndNewItem(QString type)
{
    if(type == "保存")
    {
        QTableWidgetItem * item_save = new QTableWidgetItem("保存并通知");
        item_save->setIcon(QIcon(":./images/保存.png"));
        item_save->setTextColor(Qt::blue);
        item_save->setBackgroundColor(QColor(235,235,235));
        if(LoginWindow::userName != ui->lineEdit_leaderName->text() && LoginWindow::userLevel != 5)
        {
            item_save->setToolTip("向项目负责人发送审核通知");
        }
        if(LoginWindow::userName == ui->lineEdit_leaderName->text())
        {
            item_save->setToolTip("向设计人员或标准工程师发送通知");
        }
        if(LoginWindow::userLevel == 5)
        {
            item_save->setToolTip("向设计人员和负责人发送通知");
        }
        item_save->setFlags(item_save->flags() & ~Qt::ItemIsEditable);
        return item_save;
    }
    if(type == "新增一行")
    {
        QTableWidgetItem * item_newRow = new QTableWidgetItem("新增一行");
        item_newRow->setIcon(QIcon(":./images/新增一行.png"));
        item_newRow->setTextColor(Qt::blue);
        item_newRow->setBackgroundColor(QColor(235,235,235));
        item_newRow->setFlags(item_newRow->flags() & ~Qt::ItemIsEditable);
        return item_newRow;
    }
    if(type == "上移")
    {
        QTableWidgetItem * item_up = new QTableWidgetItem("上移");
        item_up->setIcon(QIcon(":./images/上移.png"));
        item_up->setTextColor(Qt::blue);
        item_up->setBackgroundColor(QColor(235,235,235));
        item_up->setToolTip("点击上移");
        item_up->setFlags(item_up->flags() & ~Qt::ItemIsEditable);
        return item_up;
    }
    if(type == "下移")
    {
        QTableWidgetItem * item_down = new QTableWidgetItem("下移");
        item_down->setIcon(QIcon(":./images/下移.png"));
        item_down->setTextColor(Qt::blue);
        item_down->setBackgroundColor(QColor(235,235,235));
        item_down->setToolTip("点击下移");
        item_down->setFlags(item_down->flags() & ~Qt::ItemIsEditable);
        return item_down;
    }
    if(type == "删除")
    {
        QTableWidgetItem * item_remove = new QTableWidgetItem("删除");
        item_remove->setIcon(QIcon(":./images/删除.png"));
        item_remove->setTextColor(Qt::blue);
        item_remove->setBackgroundColor(QColor(235,235,235));
        item_remove->setToolTip("点击删除");
        item_remove->setFlags(item_remove->flags() & ~Qt::ItemIsEditable);
        return item_remove;
    }
    if(type == "待处理")
    {
        QTableWidgetItem * item_dcl= new QTableWidgetItem("待处理");
        item_dcl->setTextColor(Qt::blue);
        item_dcl->setTextAlignment(Qt::AlignCenter);
        item_dcl->setBackgroundColor(QColor(234,241,188));
        item_dcl->setFlags(item_dcl->flags() & ~Qt::ItemIsEditable);
        return item_dcl;
    }
    if(type == "上传附件")
    {
        QTableWidgetItem * item_fj= new QTableWidgetItem(type);
        item_fj->setTextColor(Qt::blue);
        item_fj->setTextAlignment(Qt::AlignCenter);
        item_fj->setBackgroundColor(QColor(210,210,188));
        item_fj->setToolTip("点击上传附件");
        item_fj->setFlags(item_fj->flags() & ~Qt::ItemIsEditable);
        return item_fj;
    }
}

void TYBH::on_pushButton_sendMsg_clicked()
{
    if(LoginWindow::userLevel != 5)
    {
        //QMessageBox::warning(this,"OA提示","您没有权限操作！   ",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
        dontUpdate->show();
        return;
    }
    //发送给项目负责人提示信息
    QUdpSocket * udpSocket = new QUdpSocket(this);
    QByteArray sendMsg;
    sendMsg = "请查看图样编号";
    QString recvMsgUserIP;
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    //发给申请人
    //if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->lineEdit_name->text())))
    {
        query.next();
        recvMsgUserIP = query.value(0).toString();
        qDebug() << "recvMsgUserIP = " << recvMsgUserIP;
        if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
        {
            udpSocket->close();
        }else
        {
            qDebug() << "udp error:" << udpSocket->errorString();
        }
    }
}
//
void TYBH::tableInit(QString showType)
{
    QStringList header;
    if(showType == "Look")
    {
        ui->tableWidget->setColumnCount(7);
        header << "名称" << "整/部/组件图号" << "图样/文件编号" << "零件(结构件/印制板)图号"<<"备注"<<"编辑时间"<<"设计人员";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->groupBox_tyMsg->setEnabled(false);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->pushButton_getOver->setText("已结项");
        ui->pushButton_getOver->setEnabled(false);
    }
    else
    {
        ui->tableWidget->setColumnCount(12);
        header << "名称" << "整/部/组件图号" << "图样/文件编号" << "零件(结构件/印制板)图号"<<"备注"<<"编辑时间"<<"设计人员"<<"资料附件"<<"负责人意见"<<"上移" << "下移" << "删除";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->groupBox_tyMsg->setEnabled(false);

        //connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),ui->tableWidget,SLOT(resizeRowsToContents()));//一行显示不完，多行显示

        ui->tableWidget->setIconSize(QSize(40,32));
        for(int i = 0; i != 12; ++i)
        {
            ui->tableWidget->setColumnWidth(i,141);
            if(i >8)
            {
                ui->tableWidget->setColumnWidth(i,40);
            }
        }
        ui->tableWidget->setColumnWidth(0,180);
        ui->tableWidget->setColumnWidth(6,80);
        ui->tableWidget->setColumnWidth(7,80);
        ui->tableWidget->setColumnWidth(8,90);
        connect(ui->tableWidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(dealTableDoubleClickedSlot(QTableWidgetItem*)));
        connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(dealCellClickedSlot(int,int)));
        connect(ui->tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(dealItemTextChangedSlot(QTableWidgetItem*)));
    }

    //for test
#if 0
    ui->tableWidget->setRowCount(1);
    for(int i = 0;i != 12;++i)
    {
        QTableWidgetItem * item = new QTableWidgetItem();
        if(i == 8)
        {
            item->setToolTip("给负责人发送通知");
            leaderDealCombox = new QComboBox(this);
            leaderDealCombox->addItem("待处理");
            leaderDealCombox->addItem("同意");
            leaderDealCombox->addItem("驳回");
            QLineEdit * lineEdit = new QLineEdit;
            lineEdit->setReadOnly(true);
            lineEdit->setFont(QFont("Timers",9,QFont::Normal));
            lineEdit->setAlignment(Qt::AlignCenter);
            leaderDealCombox->setLineEdit(lineEdit);
            leaderDealCombox->setStyleSheet("color: rgb(255, 0, 0);");
            ui->tableWidget->setCellWidget(0,8,leaderDealCombox);

        }else
        {
            ui->tableWidget->setItem(0,i,item);
        }

    }
#endif

}
//
void TYBH::dealItemTextChangedSlot(QTableWidgetItem* item)
{
    if(ui->tableWidget->item(item->row(),6)) //判断是否有效单元格
    {
        if(item->column() == 0) //当一列名称修改时
        {
            //if(LoginWindow::userLevel != 5) //如果不是总经办权限的人修改
            {
                if(LoginWindow::userName == ui->tableWidget->item(item->row(),6)->text() || ui->tableWidget->item(item->row(),6)->text().trimmed().size() == 0)
                {
                    //其他人不能再次修改，只能是上次编辑的人或者为空时可编辑
                    ui->tableWidget->item(item->row(),6)->setText(LoginWindow::userName);
                    ui->tableWidget->item(item->row(),5)->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
                    saveFlag = true;//内容改变后保存开关打开
                }
            }
        }
        if(item->column() == 1 || item->column() == 2 || item->column() == 3)
        {
            saveFlag = true;
        }
    }

}
void TYBH::showTable(QString showType,QString proNum)
{
    QSqlQuery query;
    if(query.exec(tr("select projNum,prodNum,proType,projName,prodName,proLeaderName from tybhmsg where projNum = '%1'").arg(proNum)))
    {
        if(query.size())
        {
            query.next();
            ui->lineEdit_proNum->setText(query.value(0).toString());
            ui->lineEdit_productNum->setText(query.value(1).toString());
            ui->lineEdit_proType->setText(query.value(2).toString());
            ui->lineEdit_proName->setText(query.value(3).toString());
            ui->lineEdit_productName->setText(query.value(4).toString());
            ui->lineEdit_leaderName->setText(query.value(5).toString());
        }
    }
    if(showType == "Look")
    {
        ui->tableWidget->setEnabled(false);
    }
    if(query.exec(tr("select * from tybhprodmsg where projNum = '%1'").arg(proNum)))
    {
        if(query.size()) //当prodMsg有记录时
        {
            if(showType == "Look")
            {
                ui->tableWidget->setRowCount(query.size());//设置行数
                for(int i = 0;i != query.size();++i)
                {
                    query.next();
                    for(int j = 0;j != ui->tableWidget->columnCount();++j)
                    {
                        QTableWidgetItem * item = new QTableWidgetItem(query.value(j+1).toString());
                        item->setTextAlignment(Qt::AlignCenter);
                        item->setToolTip(query.value(j+1).toString());
                        ui->tableWidget->setItem(i,j,item);
                    }
                }
            }
            else //编辑模式
            {
                ui->tableWidget->setRowCount(query.size()+1);//设置行数
                QTableWidgetItem * newRowItem = newSaveAndNewItem("新增一行");
                QTableWidgetItem * saveItem = newSaveAndNewItem("保存");
                ui->tableWidget->setItem(query.size(),2,newRowItem);
                ui->tableWidget->setItem(query.size(),5,saveItem);
                dealComboMap.clear();//情空
                for(int i = 0 ; i != query.size();++i)
                {
                    query.next();
                    for(int j = 0;j != 9;++j)
                    {
                        QTableWidgetItem * item = new QTableWidgetItem(query.value(j+1).toString());
                        item->setTextAlignment(Qt::AlignCenter);
                        item->setToolTip(query.value(j+1).toString());
                        if(j == 0 && query.value(9).toString() == "同意")
                        {
                            item->setFlags(item->flags() & ~Qt::ItemIsEditable);//双击不可编辑
                        }
                        if(j == 5 || j == 6)
                        {
                            item->setFlags(item->flags() & ~Qt::ItemIsEditable);//双击不可编辑
                        }
                        if(j == 7)
                        {
                            item->setBackgroundColor(QColor(210,210,188));
                            if(query.value(8).toString() == "点击上传附件")
                            {
                                item->setToolTip("点击上传附件");
                                item->setText("上传附件");
                                item->setTextColor(Qt::blue);
                            }else{
                                item->setToolTip(query.value(8).toString());
                                item->setText("下载附件");
                                item->setTextColor(QColor(255,0,0));
                            }

                            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        }
                        if(j == 8)//处理项
                        {

                            if(LoginWindow::userName == ui->lineEdit_leaderName->text())
                            {
                                //项目负责人显示处理combox
                                if(query.value(j+1).toString() == "待处理")
                                {
                                    QComboBox * combox = new QComboBox(this);
                                    connect(combox,SIGNAL(currentTextChanged(QString)),SLOT(comboChangeSlot(QString)));
                                    combox->addItem("待处理");
                                    combox->addItem("同意");
                                    combox->addItem("驳回");
                                    QLineEdit * lineEdit = new QLineEdit;
                                    lineEdit->setReadOnly(true);
                                    lineEdit->setFont(QFont("Timers",9,QFont::Normal));
                                    lineEdit->setAlignment(Qt::AlignCenter);
                                    combox->setLineEdit(lineEdit);
                                    combox->setStyleSheet("color: rgb(0, 0, 255);");
                                    item->setText("combox");
                                    ui->tableWidget->setItem(i,8,item);
                                    ui->tableWidget->setCellWidget(i,8,combox);
                                    dealComboMap.insert(i,combox);//把所以combox放在map容器里，方便保存时读取处理结果
                                }
                                else //处理过的正常显示
                                {
                                    if(query.value(j+1).toString() == "同意")
                                    {
                                        item->setTextColor(Qt::green);
                                    }else{
                                        item->setTextColor(Qt::red);
                                    }
                                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                                    item->setBackgroundColor(QColor(234,241,188));
                                    ui->tableWidget->setItem(i,j,item);
                                }
                            }
                            else
                            {
                                //不是负责人
                                if(query.value(j+1).toString() == "待处理")
                                {
                                    item->setTextColor(Qt::blue);
                                }else if(query.value(j+1).toString() == "同意")
                                {
                                    item->setTextColor(Qt::green);
                                }else{
                                    item->setTextColor(Qt::red);
                                }
                                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                                item->setBackgroundColor(QColor(234,241,188));
                                ui->tableWidget->setItem(i,j,item);
                            }
                        }
                        else
                        {
                            ui->tableWidget->setItem(i,j,item);
                        }

                    }
                    ui->tableWidget->setItem(i,9,newSaveAndNewItem("上移"));
                    ui->tableWidget->setItem(i,10,newSaveAndNewItem("下移"));
                    ui->tableWidget->setItem(i,11,newSaveAndNewItem("删除"));
                }
            }
        }
        else //当没有记录时
        {
            if(showType == "Edit")
            {
                ui->tableWidget->setRowCount(1);//设置行数
                ui->tableWidget->setItem(0,2,newSaveAndNewItem("新增一行"));
                ui->tableWidget->setItem(0,5,newSaveAndNewItem("保存"));
            }
        }
    }
}

void TYBH::on_pushButton_min_clicked()
{
    this->showMinimized();
}
//
bool TYBH::sendNotice(QString name,QByteArray sendMsg)
{
    Widget::openMySql();
    QSqlQuery query;
    QUdpSocket * udpSocket = new QUdpSocket(this);
    if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(name)))
    {
        query.next();
        QString recvMsgUserIP = query.value(0).toString();
        if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
        {
            udpSocket->close();
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
//
void TYBH::comboChangeSlot(QString text)
{

    if(text != "待处理")
    {

        saveFlag = true;
        qDebug() << "saveFlag = " << saveFlag;
    }
    else
    {
        saveFlag = false;
        qDebug() << "saveFlag = " << saveFlag;
    }
}

void TYBH::on_pushButton_getOver_clicked()
{
    if(LoginWindow::userLevel != 5)
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作");
        dontUpdate->show();
        return;
    }
    QMessageBox msgBox;
    msgBox.setDefaultButton(QMessageBox::No);
    int ret =  msgBox.warning(this,"结项提示","确定结项吗?   ",QMessageBox::Yes | QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        Widget::openMySql();
        QSqlQuery query;
        if(query.exec(tr("update tybhmsg set dealState = '已结项' where projNum = '%1'").arg(ui->lineEdit_proNum->text())))
        {
            QSqlDatabase::database().commit();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("结项成功！");
            dontUpdate->show();
            emit sendFlushFatherTableSig();
            this->close();
        }
    }
}
//
void TYBH::getFileNameFromUpDialogSlot(QString fileName, int rowNum)
{
    ui->tableWidget->item(rowNum,7)->setToolTip(fileName);
    ui->tableWidget->item(rowNum,7)->setText("下载附件");
    ui->tableWidget->item(rowNum,7)->setTextColor(QColor(255,0,0));
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec(tr("update tybhprodmsg set fileName = '%1' where projNum = '%2' and dealTime = '%3' and dealPerson = '%4'")
                  .arg(fileName).arg(ui->tableWidget->item(rowNum,0)->text()).arg(ui->tableWidget->item(rowNum,5)->text())
                  .arg(ui->tableWidget->item(rowNum,6)->text())))
    {
        QSqlDatabase::database().commit();
    }
}
