#include "chuchai.h"
#include "ui_chuchai.h"
#include <QButtonGroup>

ChuChai::ChuChai(QString showType,QString name,QString dealTime,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChuChai)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("出差电子流");
    ui->calendarWidget->hide();
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    allComboxInit();
    trafficCheckBoxInit();
    //显示
    showByLookOrRefuse(showType,name,dealTime);
}

ChuChai::~ChuChai()
{
    delete ui;
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void ChuChai::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void ChuChai::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void ChuChai::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void ChuChai::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void ChuChai::on_pushButton_close_clicked()
{
    this->close();
}
//
void ChuChai::allComboxInit()
{
    ui->lineEdit_name->setText(LoginWindow::userName);
    QSqlQuery query;
    if(query.exec(tr("select department,position from staffmsg where name = '%1'").arg(LoginWindow::userName)))
    {
        query.next();
        ui->comboBox_department->setCurrentText(query.value(0).toString());
        ui->comboBox_position->setCurrentText(query.value(1).toString());
    }
    ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
    if(query.exec("select name from staffmsg"))
    {
        for(int i = 0;i != query.size();++i)
        {
            query.next();
            ui->comboBox_leader->addItem(query.value(0).toString());
            ui->comboBox_manager->addItem(query.value(0).toString());
            ui->comboBox_clerk->addItem(query.value(0).toString());
        }
    }
    ui->comboBox_leader->setItemText(0,"吴明胜");
    ui->comboBox_leader->setCurrentText("胡军火");
    ui->comboBox_manager->setCurrentText("吴伟");
    ui->comboBox_clerk->setCurrentText("陈美琪");
    QMap<int,QString> dealMap = {{0,"待处理"},{1,"同意"},{2,"驳回"},{3,"不同意"}};
    for(int i = 0;i != 4;++i)
    {
        ui->comboBox_leaderDeal->addItem(dealMap[i]);
        ui->comboBox_managerDeal->addItem(dealMap[i]);
        ui->comboBox_clerkDeal->addItem(dealMap[i]);
    }
#if 1
    ui->groupBox_clerk->setEnabled(false);
    ui->groupBox_leader->setEnabled(false);
    ui->groupBox_manager->setEnabled(false);
    ui->lineEdit_startDay->setEnabled(false);
    ui->lineEdit_endDay->setEnabled(false);
    ui->lineEdit_dealTime->setEnabled(false);
    ui->lineEdit_name->setEnabled(false);
#endif
    ui->calendarWidget->hide();
}

void ChuChai::on_calendarWidget_selectionChanged()
{
    if(selectDayType == "startDay")
    {
        ui->lineEdit_startDay->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
        ui->calendarWidget->hide();
    }
    if(selectDayType == "endDay")
    {
        ui->lineEdit_endDay->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
        ui->calendarWidget->hide();
    }
}



void ChuChai::on_toolButton_startDay_clicked()
{
    selectDayType = "startDay";
    ui->calendarWidget->show();
}

void ChuChai::on_toolButton_endDay_clicked()
{
    selectDayType = "endDay";
    ui->calendarWidget->show();
}

void ChuChai::on_pButtonCancel_clicked()
{
    this->close();
}

void ChuChai::on_pButtonOk_clicked()
{
    if(ui->pButtonOk->text() == "确定")
    {
        this->close();
        return;
    }
    if(ui->pButtonOk->text() == "提交申请" || ui->pButtonOk->text() == "再次提交")
    {
        QString startTime = ui->lineEdit_startDay->text()+"/"+ui->timeEdit_startTime->text();
        QString endTime = ui->lineEdit_endDay->text()+"/"+ui->timeEdit_endTime->text();
#if 1
        if(ui->lineEdit_startDay->text().isEmpty() || ui->lineEdit_endDay->text().isEmpty()||
                ui->lineEdit_toWhere->text().trimmed().isEmpty()||ui->lineEdit_reason->text().trimmed().isEmpty())
        {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("必填信息不能为空！");
                dontUpdate->show();
                return;
        }
        if(startTime >= endTime)
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("出差时间填写有误！");
            dontUpdate->show();
            return;
        }
        if(trafficWay == "NO")
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择交通工具！");
            dontUpdate->show();
            return;
        }
#endif
        QSqlQuery query;
        QString name = ui->lineEdit_name->text();
        QString department = ui->comboBox_department->currentText();
        QString position = ui->comboBox_position->currentText();
        QString dealTime = ui->lineEdit_dealTime->text();
        if(ui->pButtonOk->text() == "再次提交")
        {
            dealTime = QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss");
            ui->comboBox_clerkDeal->setCurrentText(0);
            ui->comboBox_leaderDeal->setCurrentIndex(0);
            ui->comboBox_managerDeal->setCurrentIndex(0);
            ui->textEdit_clerkAdvice->clear();
            ui->textEdit_leaderAdvice->clear();
            ui->textEdit_managerAdvice->clear();
        }
        QString agent = ui->lineEdit_agent->text();
        QString toWhere = ui->lineEdit_toWhere->text();
        QString reason = ui->lineEdit_reason->text();
        QString leader = ui->comboBox_leader->currentText();
        QString leaderResult = ui->comboBox_leaderDeal->currentText();
        QString leaderAdvice = ui->textEdit_leaderAdvice->toPlainText();
        QString manager = ui->comboBox_manager->currentText();
        QString managerResult = ui->comboBox_managerDeal->currentText();
        QString managerAdvice = ui->textEdit_managerAdvice->toPlainText();
        QString clerk = ui->comboBox_clerk->currentText();
        QString clerkResult = ui->comboBox_clerkDeal->currentText();
        QString clerkAdvice = ui->textEdit_clerkAdvice->toPlainText();
        if(query.exec(tr("insert into chuchai values('%1','%2','%3','%4','%5','%6','%7','%8',"
                         "'%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21')")
                      .arg(name).arg(department).arg(position).arg(dealTime).arg(startTime)
                      .arg(endTime).arg(agent).arg(toWhere).arg(trafficWay).arg(reason).arg(leader)
                      .arg(leaderResult).arg(leaderAdvice).arg(manager).arg(managerResult)
                      .arg(managerAdvice).arg(clerk).arg(clerkResult).arg(clerkAdvice).arg("出差").arg(LoginWindow::staffID)))
        {
            QSqlDatabase::database().commit();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请成功！");
            dontUpdate->show();
            emit emitFlushShowStreamSig("出差");
            //提交成功后发送给领导处理提示信息
            QUdpSocket * udpSocket = new QUdpSocket(this);
            QByteArray sendMsg;
            sendMsg = "您有新的出差电子流待处理！";
            QString recvMsgUserIP;
            QSqlQuery query;
            if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->comboBox_leader->currentText())))
            {
                query.next();
                recvMsgUserIP = query.value(0).toString();
                if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
                {
                    udpSocket->close();
                }else
                {
                    qDebug() << "udp error:" << udpSocket->errorString();
                }
            }
            this->close();
            return;
        }else{
            QSqlDatabase::database().rollback();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请失败！");
            dontUpdate->show();
        }
    }
    //提交处理
    if(ui->pButtonOk->text() == "提交处理")
    {
        //部门领导
        if(LoginWindow::userName == ui->comboBox_leader->currentText())
        {
            if(ui->comboBox_leaderDeal->currentText() == "待处理")
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
                dontUpdate->show();
                return;
            }
            QSqlQuery query;
            if(query.exec(tr("update chuchai set leaderResult = '%1',leaderAdvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_leaderDeal->currentText()).arg(ui->textEdit_leaderAdvice->toPlainText())
                          .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
            {
                QSqlDatabase::database().commit();
                //QMessageBox::about(this,"提示","提交处理成功！ ");
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
                dontUpdate->show();
                emit sendFlushDclSig();
                emit emitFlushShowStreamSig("点击处理");
                //提交成功后发送给领导处理提示信息
                QUdpSocket * udpSocket = new QUdpSocket(this);
                QByteArray sendMsg;
                sendMsg = "您有新的出差电子流待处理！";
                QString recvMsgUserIP;

                //发给下一个审核领导人
                if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->comboBox_manager->currentText())))
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
            }
            else
            {
                QSqlDatabase::database().rollback();
                QMessageBox::about(this,"提示",tr("提交申请失败:%1  ").arg(query.lastError().text()));
                this->close();
                return;
            }
        }
        //总经理
        if(LoginWindow::userName == ui->comboBox_manager->currentText())
        {
            if(ui->comboBox_managerDeal->currentText() == "待处理")
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
                dontUpdate->show();
                return;
            }
            QSqlQuery query;
            if(query.exec(tr("update chuchai set managerResult = '%1',managerAdvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_managerDeal->currentText()).arg(ui->textEdit_managerAdvice->toPlainText())
                          .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
            {
                QSqlDatabase::database().commit();
                //QMessageBox::about(this,"提示","提交处理成功！ ");
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
                dontUpdate->show();
                emit sendFlushDclSig();
                emit emitFlushShowStreamSig("点击处理");
                //提交成功后发送给领导处理提示信息
                QUdpSocket * udpSocket = new QUdpSocket(this);
                QByteArray sendMsg;
                sendMsg = "您有新的出差电子流待处理！";
                QString recvMsgUserIP;
                //发给下一个审核领导人
                if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->comboBox_clerk->currentText())))
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
            }else
            {
                QSqlDatabase::database().rollback();
                QMessageBox::about(this,"提示",tr("提交申请失败:%1  ").arg(query.lastError().text()));
                this->close();
                return;
            }
        }
        //考勤员
        if(LoginWindow::userName == ui->comboBox_clerk->currentText())
        {
            if(ui->comboBox_clerkDeal->currentText() == "待处理")
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
                dontUpdate->show();
                return;
            }
            QSqlQuery query;
            if(query.exec(tr("update chuchai set clerkResult = '%1',clerkAdvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_clerkDeal->currentText()).arg(ui->textEdit_clerkAdvice->toPlainText())
                          .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
            {
                QSqlDatabase::database().commit();
                //QMessageBox::about(this,"提示","提交处理成功！ ");
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
                dontUpdate->show();
                emit sendFlushDclSig();
                emit emitFlushShowStreamSig("点击处理");
                //提交成功后发送给领导处理提示信息
                QUdpSocket * udpSocket = new QUdpSocket(this);
                QByteArray sendMsg;
                sendMsg = "您的出差电子流已审核完毕！";
                QString recvMsgUserIP;
                //发给下一个审核领导人
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
                this->close();
            }
            else
            {
                QSqlDatabase::database().rollback();
                QMessageBox::about(this,"提示",tr("提交申请失败:%1  ").arg(query.lastError().text()));
                this->close();
                return;
            }
        }
    }
}
//
void ChuChai::trafficCheckBoxInit()
{
    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->checkBox_air,0);
    btnGroup->addButton(ui->checkBox_train,1);
    btnGroup->addButton(ui->checkBox_car,2);
    btnGroup->addButton(ui->checkBox_selfDrive,3);
    connect(ui->checkBox_air,SIGNAL(clicked()),this,SLOT(trafficCheckBoxClickedSlot()));
    connect(ui->checkBox_train,SIGNAL(clicked()),this,SLOT(trafficCheckBoxClickedSlot()));
    connect(ui->checkBox_car,SIGNAL(clicked()),this,SLOT(trafficCheckBoxClickedSlot()));
    connect(ui->checkBox_selfDrive,SIGNAL(clicked()),this,SLOT(trafficCheckBoxClickedSlot()));
}
void ChuChai::trafficCheckBoxClickedSlot()
{
    switch (btnGroup->checkedId()) {
    case 0:
        trafficWay = "飞机";
        break;
    case 1:
        trafficWay = "火车";
        break;
    case 2:
        trafficWay = "汽车";
        break;
    case 3:
        trafficWay = "自驾";
        break;
    default:
        break;
    }
}
//
void ChuChai::showByLookOrRefuse(QString showType,QString name,QString dealTime)
{
    if(showType == "新增")
    {
        ui->pButtonOk->setText("提交申请");
        return;
    }
    QSqlQuery query;
    if(query.exec(tr("select * from chuchai where name = '%1' and dealTime = '%2'").arg(name).arg(dealTime)))
    {
        if(query.size())
        {
            query.next();
            ui->lineEdit_name->setText(query.value(0).toString());
            ui->comboBox_department->setCurrentText(query.value(1).toString());
            ui->comboBox_position->setCurrentText(query.value(2).toString());
            ui->lineEdit_dealTime->setText(query.value(3).toString());
            QString startDayTime = query.value(4).toString();
            QString startDay = startDayTime.mid(0,startDayTime.indexOf("/"));
            QString startTime = startDayTime.mid(startDayTime.indexOf("/")+1,5);
            ui->lineEdit_startDay->setText(startDay);
            ui->timeEdit_startTime->setTime(QTime(startTime.mid(0,startTime.indexOf(":")).toInt(),startTime.mid(startTime.indexOf(":")+1,2).toInt()));

            QString endDayTime = query.value(5).toString();
            QString endDay = endDayTime.mid(0,endDayTime.indexOf("/"));
            QString endTime = endDayTime.mid(endDayTime.indexOf("/")+1,5);
            ui->lineEdit_endDay->setText(endDay);
            ui->timeEdit_endTime->setTime(QTime(endTime.mid(0,endTime.indexOf(":")).toInt(),endTime.mid(endTime.indexOf(":")+1,2).toInt()));

            ui->lineEdit_agent->setText(query.value(6).toString());
            ui->lineEdit_toWhere->setText(query.value(7).toString());
            QString traffic = query.value(8).toString();
            if(traffic == "飞机")
            {
                ui->checkBox_air->click();
            }else if(traffic == "火车"){
                ui->checkBox_train->click();
            }else if(traffic == "汽车"){
                ui->checkBox_car->click();
            }else{
                ui->checkBox_selfDrive->click();
            }
            ui->lineEdit_reason->setText(query.value(9).toString());
            ui->comboBox_leader->setCurrentText(query.value(10).toString());
            ui->comboBox_leaderDeal->setCurrentText(query.value(11).toString());
            ui->textEdit_clerkAdvice->setText(query.value(12).toString());
            ui->comboBox_manager->setCurrentText(query.value(13).toString());
            ui->comboBox_managerDeal->setCurrentText(query.value(14).toString());
            ui->textEdit_managerAdvice->setText(query.value(15).toString());
            ui->comboBox_clerk->setCurrentText(query.value(16).toString());
            ui->comboBox_clerkDeal->setCurrentText(query.value(17).toString());
            ui->textEdit_clerkAdvice->setText(query.value(18).toString());
        }
    }
    if(showType == "查看")
    {
        ui->groupBox->setEnabled(false);
        ui->groupBox_allLeader->setEnabled(false);
        ui->groupBox_clerk->setEnabled(false);
        ui->groupBox_leader->setEnabled(false);
        ui->groupBox_manager->setEnabled(false);
        ui->pButtonOk->setText("确定");
    }
    if(showType == "驳回")
    {
        ui->pButtonOk->setText("再次提交");
    }
    if(showType == "点击处理")
    {
        ui->groupBox->setEnabled(false);
        ui->groupBox_allLeader->setEnabled(false);
        ui->groupBox_clerk->setEnabled(false);
        ui->groupBox_leader->setEnabled(false);
        ui->groupBox_manager->setEnabled(false);
        if(LoginWindow::userName == ui->comboBox_leader->currentText())
        {
            setComboxStyle(ui->comboBox_leader,ui->groupBox_leader,ui->comboBox_leaderDeal,ui->textEdit_leaderAdvice);
        }
        if(LoginWindow::userName == ui->comboBox_manager->currentText())
        {
            setComboxStyle(ui->comboBox_manager,ui->groupBox_manager,ui->comboBox_managerDeal,ui->textEdit_managerAdvice);
        }
        if(LoginWindow::userName == ui->comboBox_clerk->currentText())
        {
            setComboxStyle(ui->comboBox_clerk,ui->groupBox_clerk,ui->comboBox_clerkDeal,ui->textEdit_clerkAdvice);
        }
        ui->pButtonOk->setText("提交处理");
    }
}
//
void ChuChai::setComboxStyle(QComboBox *comBoxLeader,QGroupBox *groupBox, QComboBox *comBoxResult, QTextEdit *textEdit)
{
    groupBox->setEnabled(true);
    comBoxLeader->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
    comBoxResult->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
    textEdit->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
}
