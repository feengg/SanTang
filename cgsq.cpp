#include "cgsq.h"
#include "ui_cgsq.h"
#include "widget.h"
#include "loginwindow.h"

CGSQ::CGSQ(QString showModel,QString bomPath1,QString name,QString projectName,
           QString department,QString dealTime,QString expectTime,
                 QString recordMsg,QString groupLeader,QString groupResult,
                 QString groupAdvice,QString dptLeader,QString dptResult,
                 QString dptAdvice,QString manager,QString managerResult,
                 QString managerAdvice,QString num,QString leader,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CGSQ)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

    this->setWindowTitle("采购申请");
    bomPath = bomPath1;
    ui->calendarWidget_expectTime->hide();
    ui->calendarWidget_expectTime->raise();

    ui->comboBox_department->addItem("研发部");
    ui->comboBox_department->addItem("财务部");
    ui->comboBox_department->addItem("市场部");
    ui->comboBox_department->addItem("总工办");
    ui->comboBox_department->addItem("总经办");
    ui->comboBox_department->addItem("质管部");

    for(int i = 1;i < 50;i++)
    {
        ui->comboBox_num->addItem(QString::number(i));
    }

    show_model = showModel;
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setColumnWidth(0,102);
    ui->tableWidget->setColumnWidth(1,258);
    ui->tableWidget->setColumnWidth(2,79);
    ui->tableWidget->setColumnWidth(3,48);
    ui->tableWidget->setColumnWidth(4,62);
    ui->tableWidget->setColumnWidth(5,65);
    ui->tableWidget->setColumnWidth(6,55);
    ui->tableWidget->setColumnWidth(7,85);
    QStringList header;
    header << "产品名称" << "规格/型号" << "建议厂家"<<"数量"<<"单价(元)"<<"库存"<<"应购"<<"技术要求";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //设置combox
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }else
    {
        QSqlQuery query;
        if(query.exec("select count(*) from staffmsg"))
        {
            query.next();
            int rowNum = query.value(0).toInt();
            if(query.value(0).toInt())
            {
                query.exec("select name from staffmsg");
                for(int i =0;i < rowNum;i++)
                {
                    query.next();
                    ui->comboBox_leader1->addItem(query.value(0).toString());
                    //ui->comboBox_leader4->addItem(query.value(0).toString());
                }
            }
        }
        if(query.exec("select count(*) from staffmsg where level >=1 and level <=2"))
        {
            query.next();
            int rowNum = query.value(0).toInt();
            if(rowNum)
            {
                query.exec("select name from staffmsg where level >=1 and level <=2");
                for(int i =0 ; i < rowNum; i++)
                {
                    query.next();
                    ui->comboBox_leader2->addItem(query.value(0).toString());
                    ui->comboBox_leader3->addItem(query.value(0).toString());
                }
            }
        }
    }


    ui->comboBox_leader3->setCurrentText("吴伟");
    ui->comboBox_dealResult1->addItem("待处理");
    ui->comboBox_dealResult1->addItem("同意");
    ui->comboBox_dealResult1->addItem("驳回");
    ui->comboBox_dealResult1->addItem("不同意");

    ui->comboBox_dealResult2->addItem("待处理");
    ui->comboBox_dealResult2->addItem("同意");
    ui->comboBox_dealResult2->addItem("驳回");
    ui->comboBox_dealResult2->addItem("不同意");

    ui->comboBox_dealResult3->addItem("待处理");
    ui->comboBox_dealResult3->addItem("同意");
    ui->comboBox_dealResult3->addItem("驳回");
    ui->comboBox_dealResult3->addItem("不同意");

    //新增情况
    if(showModel == "新增")
    {

        ui->lineEdit_name->setText(LoginWindow::userName);
        ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));

        ui->pushButton_ok->setText("提交申请");
        ui->groupBox_leader1->setEnabled(false);
        ui->groupBox_leader2->setEnabled(false);
        ui->groupBox_leader3->setEnabled(false);
        flushCGSQTableWidgetSlot();
    }
    if(showModel == "查看" || showModel == "驳回")
    {

        ui->lineEdit_name->setText(name);
        ui->lineEdit_proName->setText(projectName);
        ui->lineEdit_dealTime->setText(dealTime);
        ui->lineEdit_expectTime->setText(expectTime);
        ui->textEdit_recordMsg->setText(recordMsg);
        ui->comboBox_leader1->setCurrentText(groupLeader);
        ui->comboBox_dealResult1->setCurrentText(groupResult);
        ui->textEdit_leaderAdvice1->setText(groupAdvice);
        ui->comboBox_leader2->setCurrentText(dptLeader);
        ui->comboBox_dealResult2->setCurrentText(dptResult);
        ui->textEdit_leaderAdvice2->setText(dptAdvice);
        ui->comboBox_leader3->setCurrentText(manager);
        ui->comboBox_dealResult3->setCurrentText(managerResult);
        ui->textEdit_leaderAdvice3->setText(managerAdvice);
        ui->comboBox_department->setCurrentText(department);
        ui->comboBox_num->setCurrentText(num);


        if(showModel == "查看")
        {
            ui->groupBox->setEnabled(false);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑
            ui->groupBox_allLeader->setEnabled(false);
        }else
        {
            ui->pushButton_ok->setText("再次提交");
            ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
        }
        ui->groupBox_leader1->setEnabled(false);
        ui->groupBox_leader2->setEnabled(false);
        ui->groupBox_leader3->setEnabled(false);
        //调用数据库
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(8);
        QStringList header;
        header << "产品名称" << "规格/型号" << "建议厂家"<<"数量"<<"单价(元)"<<"库存"<<"应购"<<"技术要求";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        QSqlQuery query;
        if(query.exec(tr("select * from caigoupromsg where projectName = '%1'").arg(projectName)))
        {
            ui->tableWidget->setRowCount(query.size());
            for(int i = 0;i < query.size();i++)
            {
                query.next();
                QTableWidgetItem * item0 = new QTableWidgetItem(query.value(1).toString());
                QTableWidgetItem * item1 = new QTableWidgetItem(query.value(2).toString());
                QTableWidgetItem * item2 = new QTableWidgetItem(query.value(3).toString());
                QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                QTableWidgetItem * item4 = new QTableWidgetItem(query.value(5).toString());
                QTableWidgetItem * item5 = new QTableWidgetItem(query.value(6).toString());
                QTableWidgetItem * item6 = new QTableWidgetItem(query.value(7).toString());
                QTableWidgetItem * item7 = new QTableWidgetItem(query.value(8).toString());

                item0->setTextAlignment(Qt::AlignCenter);
                item1->setTextAlignment(Qt::AlignCenter);
                item2->setTextAlignment(Qt::AlignCenter);
                item3->setTextAlignment(Qt::AlignCenter);
                item4->setTextAlignment(Qt::AlignCenter);
                item5->setTextAlignment(Qt::AlignCenter);
                item6->setTextAlignment(Qt::AlignCenter);
                item7->setTextAlignment(Qt::AlignCenter);


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

    if(showModel == "点击处理")
    {


        dealLeader = leader;
        ui->pushButton_ok->setText("提交处理");
        ui->groupBox->setEnabled(false);

        ui->groupBox_allLeader->setEnabled(false);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑

        if(leader == "组长")
        {
            ui->groupBox_leader1->setEnabled(true);
            ui->comboBox_leader1->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->comboBox_dealResult1->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->textEdit_leaderAdvice1->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
        }
        if(leader == "部门领导")
        {
            ui->groupBox_leader2->setEnabled(true);
            ui->comboBox_leader2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->comboBox_dealResult2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->textEdit_leaderAdvice2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
        }
        if(leader == "总经理")
        {
            ui->groupBox_leader3->setEnabled(true);
            ui->comboBox_leader3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->comboBox_dealResult3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->textEdit_leaderAdvice3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
        }
        ui->lineEdit_name->setText(name);
        ui->lineEdit_proName->setText(projectName);
        ui->comboBox_department->setCurrentText(department);
        ui->lineEdit_dealTime->setText(dealTime);
        ui->lineEdit_expectTime->setText(expectTime);

        ui->comboBox_num->setCurrentText(num);
        ui->textEdit_recordMsg->setText(recordMsg);
        ui->comboBox_leader1->setCurrentText(groupLeader);
        ui->comboBox_leader2->setCurrentText(dptLeader);
        ui->comboBox_leader3->setCurrentText(manager);
        ui->comboBox_dealResult1->setCurrentText(groupResult);
        ui->textEdit_leaderAdvice1->setText(groupAdvice);
        ui->comboBox_dealResult2->setCurrentText(dptResult);
        ui->textEdit_leaderAdvice2->setText(dptAdvice);
        ui->comboBox_dealResult3->setCurrentText(managerResult);
        ui->textEdit_leaderAdvice3->setText(managerAdvice);

        //调用申购产品描述数据库
        //调用数据库
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(8);
        QStringList header;
        header << "产品名称" << "规格/型号" << "建议厂家"<<"数量"<<"单价(元)"<<"库存"<<"应购"<<"技术要求";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        QSqlQuery query;
        qDebug() << "proName=" << projectName << ":sql = " << tr("select * from caigoupromsg where projectName = '%1'").arg(projectName) ;

        if(query.exec(tr("select * from caigoupromsg where projectName = '%1'").arg(projectName)))
        {
            ui->tableWidget->setRowCount(query.size());
            for(int i = 0;i < query.size();i++)
            {
                query.next();
                QTableWidgetItem * item0 = new QTableWidgetItem(query.value(1).toString());
                QTableWidgetItem * item1 = new QTableWidgetItem(query.value(2).toString());
                QTableWidgetItem * item2 = new QTableWidgetItem(query.value(3).toString());
                QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                QTableWidgetItem * item4 = new QTableWidgetItem(query.value(5).toString());
                QTableWidgetItem * item5 = new QTableWidgetItem(query.value(6).toString());
                QTableWidgetItem * item6 = new QTableWidgetItem(query.value(7).toString());
                QTableWidgetItem * item7 = new QTableWidgetItem(query.value(8).toString());

                item0->setTextAlignment(Qt::AlignCenter);
                item1->setTextAlignment(Qt::AlignCenter);
                item2->setTextAlignment(Qt::AlignCenter);
                item3->setTextAlignment(Qt::AlignCenter);
                item4->setTextAlignment(Qt::AlignCenter);
                item5->setTextAlignment(Qt::AlignCenter);
                item6->setTextAlignment(Qt::AlignCenter);
                item7->setTextAlignment(Qt::AlignCenter);


                ui->tableWidget->setItem(i,0,item0);
                ui->tableWidget->setItem(i,1,item1);
                ui->tableWidget->setItem(i,2,item2);
                ui->tableWidget->setItem(i,3,item3);
                ui->tableWidget->setItem(i,4,item4);
                ui->tableWidget->setItem(i,5,item5);
                ui->tableWidget->setItem(i,6,item6);
                ui->tableWidget->setItem(i,7,item7);
            }
        }//
    }

}

CGSQ::~CGSQ()
{
    delete ui;
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void CGSQ::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void CGSQ::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void CGSQ::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void CGSQ::on_toolButton_clicked()
{
    this->close();
}

void CGSQ::on_pushButton_cancel_clicked()
{
    this->close();
}

void CGSQ::on_toolButton_expectTime_clicked()
{

    ui->calendarWidget_expectTime->show();

}

void CGSQ::on_calendarWidget_expectTime_selectionChanged()
{
    ui->lineEdit_expectTime->setText(ui->calendarWidget_expectTime->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget_expectTime->hide();
}

QVariant CGSQ::getCellValue(QAxObject *axObject, int row, int col)
{
    QAxObject * Cell = axObject->querySubObject("Cells(int,int)",row,col);
    return Cell->property("Value");
}
//
int CGSQ::getUsedRowsCount(QAxObject * workSheet)
{
    QAxObject *usedRange = workSheet->querySubObject("UsedRange");
    int topRow = usedRange->property("Row").toInt();
    QAxObject *rows = usedRange->querySubObject("Rows");
    int bottomRow = topRow + rows->property("Count").toInt() - 1;
    return bottomRow;
}

void CGSQ::on_pushButton_ok_clicked()
{

    if(ui->pushButton_ok->text() == "确定")
    {
        this->close();
        return;
    }
    if(ui->pushButton_ok->text() == "提交申请" || ui->pushButton_ok->text() == "再次提交")
    {
        if(ui->lineEdit_name->text().trimmed().isEmpty() || ui->lineEdit_proName->text().trimmed().isEmpty())
        {
            //QMessageBox::warning(this,"提示","请填写申请人和项目名称！   ",QMessageBox::Ok);
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请填写申请人和项目名称！");
            dontUpdate->show();
            return;
        }
        //添加一条采购申请信息
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("insert into caigouapmsg values('%1','%2','%3','%4','%5','%6','%7','待处理',NULL,'%8','待处理',NULL,'%9','待处理',NULL,'%10','采购申请','%11')")
                      .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_proName->text()).arg(ui->comboBox_department->currentText())
                      .arg(ui->lineEdit_dealTime->text()).arg(ui->lineEdit_expectTime->text()).arg(ui->textEdit_recordMsg->toPlainText())
                      .arg(ui->comboBox_leader1->currentText()).arg(ui->comboBox_leader2->currentText()).arg(ui->comboBox_leader3->currentText())
                      .arg(LoginWindow::staffID).arg(ui->comboBox_num->currentText().trimmed())))
        {
            QSqlDatabase::database().commit();
        }else
        {
            QSqlDatabase::database().rollback();
            return;
        }
        //把采购产品描述保存在caigoupromsg表里
        bool ret = true;
        for(int i = 0; i < ui->tableWidget->rowCount();i++)
        {
            if(!query.exec(tr("insert into caigoupromsg values('%1','%2','%3','%4','%5','%6','%7','%8','%9')")
                       .arg(ui->lineEdit_proName->text()).arg(ui->tableWidget->item(i,0)->text()).arg(ui->tableWidget->item(i,1)->text())
                       .arg(ui->tableWidget->item(i,2)->text()).arg(ui->tableWidget->item(i,3)->text()).arg(ui->tableWidget->item(i,4)->text())
                       .arg(ui->tableWidget->item(i,5)->text()).arg(ui->tableWidget->item(i,6)->text()).arg(ui->tableWidget->item(i,7)->text())))
            {
                ret = false;
            }
        }
        if(ret == true)
        {
            QSqlDatabase::database().commit();
        }else{
            QSqlDatabase::database().rollback();
            return;
        }
        //想处理人发送消息
        //QMessageBox::about(this,"提示","提交申请成功！  ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请成功！");
        dontUpdate->show();
        emit emitFlushShowStreamSig("采购申请");
        //提交成功后发送给领导处理提示信息
        QUdpSocket * udpSocket = new QUdpSocket(this);
        QByteArray sendMsg;
        sendMsg = "新采购";
        QString recvMsgUserIP;
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }

        if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->comboBox_leader1->currentText())))
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
        this->close();
        //
    }
    if(ui->pushButton_ok->text() == "提交处理")
    {
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("update caigouapmsg set groupResult='%1',groupAdvice='%2',dptresult='%3',dptAdvice='%4',managerresult='%5',managerAdvice='%6' where dealtime='%7' and name='%8'")
                      .arg(ui->comboBox_dealResult1->currentText()).arg(ui->textEdit_leaderAdvice1->toPlainText())
                      .arg(ui->comboBox_dealResult2->currentText()).arg(ui->textEdit_leaderAdvice2->toPlainText())
                      .arg(ui->comboBox_dealResult3->currentText()).arg(ui->textEdit_leaderAdvice3->toPlainText())
                      .arg(ui->lineEdit_dealTime->text()).arg(ui->lineEdit_name->text())))
        {
            QSqlDatabase::database().commit();
        }else
        {
            QSqlDatabase::database().rollback();
            return;
        }
        if(dealLeader == "组长")
        {
            //QMessageBox::about(this,"提示","提交处理成功！ ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
            dontUpdate->show();
            emit emitFlushShowStreamSig("点击处理");
            //提交成功后发送给领导处理提示信息
            QUdpSocket * udpSocket = new QUdpSocket(this);
            QByteArray sendMsg;
            sendMsg = "已处理采购申请";
            QString recvMsgUserIP;
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            //发给申请人
            if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->lineEdit_name->text())))
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
            //发给下一个审核领导人
            if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->comboBox_leader2->currentText())))
            {
                query.next();
                recvMsgUserIP = query.value(0).toString();
                qDebug() << "recvMsgUserIP = " << recvMsgUserIP;
                sendMsg = "新采购";
                if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
                {
                    udpSocket->close();
                }else
                {
                    qDebug() << "udp error:" << udpSocket->errorString();
                }
            }
        }
        //部门领导
        if(dealLeader == "部门领导")
        {
            //QMessageBox::about(this,"提示","提交处理成功！ ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
            dontUpdate->show();
            emit emitFlushShowStreamSig("点击处理");
            //提交成功后发送给领导处理提示信息
            QUdpSocket * udpSocket = new QUdpSocket(this);
            QByteArray sendMsg;
            sendMsg = "已处理采购申请";
            QString recvMsgUserIP;
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            //发给申请人
            if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->lineEdit_name->text())))
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
            //发给下一个审核领导人
            if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->comboBox_leader3->currentText())))
            {
                query.next();
                recvMsgUserIP = query.value(0).toString();
                qDebug() << "recvMsgUserIP = " << recvMsgUserIP;
                sendMsg = "新采购";
                if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
                {
                    udpSocket->close();
                }else
                {
                    qDebug() << "udp error:" << udpSocket->errorString();
                }
            }
        }
        //总经理
        //部门领导
        if(dealLeader == "总经理")
        {
            //QMessageBox::about(this,"提示","提交处理成功！ ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
            dontUpdate->show();
            emit emitFlushShowStreamSig("点击处理");
            //提交成功后发送给领导处理提示信息
            QUdpSocket * udpSocket = new QUdpSocket(this);
            QByteArray sendMsg;
            sendMsg = "已处理采购申请";
            QString recvMsgUserIP;
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            //发给申请人
            if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->lineEdit_name->text())))
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
            //发给采购
            if(query.exec(tr("select ip from staffmsg where level = '4'")))
            {
                query.next();
                recvMsgUserIP = query.value(0).toString();
                qDebug() << "recvMsgUserIP = " << recvMsgUserIP;
                sendMsg = "新采购申请";
                if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
                {
                    udpSocket->close();
                }else
                {
                    qDebug() << "udp error:" << udpSocket->errorString();
                }
            }
        }
        this->close();
    }
}


void CGSQ::flushCGSQTableWidgetSlot()
{
    //添加采购产品描述
    //设置excel属性
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setColumnWidth(0,102);
    ui->tableWidget->setColumnWidth(1,258);
    ui->tableWidget->setColumnWidth(2,79);
    ui->tableWidget->setColumnWidth(3,48);
    ui->tableWidget->setColumnWidth(4,62);
    ui->tableWidget->setColumnWidth(5,65);
    ui->tableWidget->setColumnWidth(6,55);
    ui->tableWidget->setColumnWidth(7,85);
    QStringList header;
    header << "产品名称" << "规格/型号" << "建议厂家"<<"数量"<<"单价(元)"<<"库存"<<"应购"<<"技术要求";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    QAxObject excel("Excel.Application");
    excel.dynamicCall("SetVisible(bool Visible)","false");
    excel.setProperty("DisplayAlerts",false);//不显示任何警告信息，如关闭“文件已修改，是否保存”
     //打开bomExcel

    QAxObject * workbooks = excel.querySubObject("WorkBooks");
    QAxObject * bomWorkbook = workbooks->querySubObject("Open (const QString&)",bomPath);
    QAxObject * bomWorksheet = bomWorkbook->querySubObject("WorkSheets(int)",1);
    //判断bom格式是否正确
    for(int i = 1; i <= 7;i++)
    {
        if(getCellValue(bomWorksheet,1,i).toString() != "Designator" && getCellValue(bomWorksheet,1,i).toString() != "Description"
                && getCellValue(bomWorksheet,1,i).toString() != "Comment" && getCellValue(bomWorksheet,1,i).toString() != "Quantity"
                && getCellValue(bomWorksheet,1,i).toString() != "Footprint" && getCellValue(bomWorksheet,1,i).toString() != "LibRef"
                && getCellValue(bomWorksheet,1,i).toString() != "Class")
        {
            QMessageBox::warning(this,"提示","Bom单格式不对！表格不能有表头信息！\n"
                                           "且需字段:Designator,Description,Comment,Quantity,Footprint,LibRef,Class.  ");
            return;
        }
    }
    QString sheet1Name = bomWorksheet->property("Name").toString();
    ui->lineEdit_proName->setText(sheet1Name);

    int rowNum = getUsedRowsCount(bomWorksheet);
    ui->tableWidget->setRowCount(rowNum-1); //设置table行数

    //获取bom单各个字段所在的列号
    int nameNum=0,ggxhNum=0,fzNum=0,slNum=0,designNum=0;
    for(int i= 1;i <=7;i++)
    {
        if(getCellValue(bomWorksheet,1,i).toString()== "Class")
        {
            nameNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Description")
        {
            ggxhNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Footprint")
        {
            fzNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Quantity")
        {
            slNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Designator")
        {
            designNum = i;
        }
    }
    //把bom单里相应的采购数据导入tablewidget里面
    for(int i = 0; i < rowNum-1;i++)
    {
        QTableWidgetItem * item0 = new QTableWidgetItem(getCellValue(bomWorksheet,i+2,nameNum).toString());
        QTableWidgetItem * item1 = new QTableWidgetItem(getCellValue(bomWorksheet,i+2,ggxhNum).toString());
        QTableWidgetItem * item2 = new QTableWidgetItem();
        QTableWidgetItem * item3 = new QTableWidgetItem(getCellValue(bomWorksheet,i+2,slNum).toString()+tr("(x%1)").arg(ui->comboBox_num->currentText().trimmed()));
        QTableWidgetItem * item4 = new QTableWidgetItem();
        QTableWidgetItem * item5 = new QTableWidgetItem();
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        query.exec(tr("select count(*) from storebill where 规格型号='%1'").arg(getCellValue(bomWorksheet,i+2,ggxhNum).toString().trimmed()));
        query.next();
        if(query.value(0) > 0)
        {
            query.exec(tr("select 库存数 from storebill where 规格型号='%1'").arg(getCellValue(bomWorksheet,i+2,ggxhNum).toString().trimmed()));
            query.next();
            item5->setText(query.value(0).toString());
        }else{
            item5->setText("0");
        }
        QTableWidgetItem * item6 = new QTableWidgetItem();
        int shouldBuyNum = (item3->text().mid(0,item3->text().indexOf("(")).toInt())*(ui->comboBox_num->currentText().toInt()) - item5->text().toInt();
        if(shouldBuyNum <= 0)
        {
            shouldBuyNum = 0;
        }

        item6->setText(QString::number(shouldBuyNum));
        QTableWidgetItem * item7 = new QTableWidgetItem();
        //设置居中显示
        item0->setTextAlignment(Qt::AlignCenter);
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        item5->setTextAlignment(Qt::AlignCenter);
        item6->setTextAlignment(Qt::AlignCenter);
        item7->setTextAlignment(Qt::AlignCenter);


        ui->tableWidget->setItem(i,0,item0);
        ui->tableWidget->setItem(i,1,item1);
        ui->tableWidget->setItem(i,2,item2);
        ui->tableWidget->setItem(i,3,item3);
        ui->tableWidget->setItem(i,4,item4);
        ui->tableWidget->setItem(i,5,item5);
        ui->tableWidget->setItem(i,6,item6);
        ui->tableWidget->setItem(i,7,item7);


    }

    excel.dynamicCall("Quit()");
}


void CGSQ::on_comboBox_num_currentTextChanged(const QString &arg1)
{

    if(show_model == "新增")
    {
        flushCGSQTableWidgetSlot();
    }

}
