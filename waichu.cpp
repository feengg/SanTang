#include "waichu.h"
#include "ui_waichu.h"

WaiChu::WaiChu(QString showType,QString name,QString dealTime,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaiChu)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("外出电子流");
    ui->calendarWidget->hide();
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    //界面初始化
    uiInit();
    //打开界面
    showUI(showType,name,dealTime);
}

WaiChu::~WaiChu()
{
    delete ui;
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void WaiChu::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void WaiChu::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void WaiChu::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void WaiChu::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void WaiChu::on_pushButton_close_clicked()
{
    this->close();
}
void WaiChu::uiInit()
{
    ui->lineEdit_name->setText(LoginWindow::userName);
    ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
    QSqlQuery query;
    if(query.exec(tr("select department,position from staffmsg where name = '%1'").arg(LoginWindow::userName)))
    {
        query.next();
        ui->comboBox_department->setCurrentText(query.value(0).toString());
        ui->comboBox_position->setCurrentText(query.value(1).toString());
    }
#if 0
    ui->lineEdit_realDay->setEnabled(false);
    ui->toolButton_realDay->setEnabled(false);
    ui->timeEdit_realTime->setEnabled(false);
    ui->checkBox_workOff->setEnabled(false);
    ui->checkBox_workOn->setEnabled(false);
    ui->groupBox_clerk->setEnabled(false);
    ui->groupBox_leader->setEnabled(false);
    ui->lineEdit_startDay->setEnabled(false);
    ui->lineEdit_endDay->setEnabled(false);

#endif
    QMap<int,QString> dealMap = {{0,"待处理"},{1,"同意"},{2,"驳回"},{3,"不同意"}};
    for(int i = 0;i != 4;++i)
    {
        ui->comboBox_leaderDeal->addItem(dealMap[i]);
        ui->comboBox_clerkDeal->addItem(dealMap[i]);
    }
    if(query.exec("select name from staffmsg"))
    {
        for(int i = 0;i != query.size();++i)
        {
            query.next();
            ui->comboBox_leader->addItem(query.value(0).toString());
            ui->comboBox_clerk->addItem(query.value(0).toString());
        }
    }
    ui->comboBox_leader->setItemText(0,"吴明胜");
    ui->comboBox_leader->setCurrentText("胡军火");
    ui->comboBox_clerk->setCurrentText("陈美琪");
    ui->calendarWidget->hide();
    ui->lineEdit_dealTime->setEnabled(false);
    ui->lineEdit_name->setEnabled(false);
}

void WaiChu::on_toolButton_startDay_clicked()
{
    dayType = "startDay";
    ui->calendarWidget->show();
}

void WaiChu::on_toolButton_endDay_clicked()
{
    dayType = "endDay";
    ui->calendarWidget->show();
}

void WaiChu::on_toolButton_realDay_clicked()
{
    dayType = "realDay";
    ui->calendarWidget->show();
}

void WaiChu::on_calendarWidget_selectionChanged()
{
    if(dayType == "startDay")
    {
        ui->lineEdit_startDay->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    }
    else if(dayType == "endDay")
    {
        ui->lineEdit_endDay->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    }
    else
    {
        ui->lineEdit_realDay->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    }
    ui->calendarWidget->hide();
}

void WaiChu::on_pButtonCancel_clicked()
{
    this->close();
}

void WaiChu::on_pButtonOk_clicked()
{
    if(ui->pButtonOk->text() == "确定")
    {
        this->close();
        return;
    }
    if(ui->pButtonOk->text() == "提交申请" || ui->pButtonOk->text() == "再次提交")
    {
        QString name = ui->lineEdit_name->text();
        QString department = ui->comboBox_department->currentText();
        QString position = ui->comboBox_position->currentText();
        QString dealTime = ui->lineEdit_dealTime->text();
        if(ui->pButtonOk->text() == "再次提交")
        {
            dealTime = QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss");
            ui->comboBox_clerkDeal->setCurrentIndex(0);
            ui->comboBox_leaderDeal->setCurrentIndex(0);
            ui->textEdit_clerkAdvice->clear();
            ui->textEdit_leaderAdvice->clear();
        }
        QString startTime = ui->lineEdit_startDay->text()+"/"+ui->timeEdit_startTime->text();
        QString endTime = ui->lineEdit_endDay->text()+"/"+ui->timeEdit_endTime->text();
        QString realTime = ui->lineEdit_realDay->text()+"/"+ui->timeEdit_realTime->text();
        QString toWhere = ui->lineEdit_toWhere->text();
        QString punchIn = "";
        QString withPeople = ui->lineEdit_with->text();
        QString reason = ui->lineEdit_reason->text();
        QString leader = ui->comboBox_leader->currentText();
        QString leaderResult = ui->comboBox_leaderDeal->currentText();
        QString leadAdvice = ui->textEdit_leaderAdvice->toPlainText();
        QString clerk = ui->comboBox_clerk->currentText();
        QString clerkResult = ui->comboBox_clerkDeal->currentText();
        QString clerkAdvice = ui->textEdit_clerkAdvice->toPlainText();
        if(startTime.isEmpty()||endTime.isEmpty()||toWhere.trimmed().isEmpty())
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("必填信息不能为空！");
            dontUpdate->show();
            return;
        }
        if(ui->lineEdit_startDay->text() > ui->lineEdit_endDay->text())
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("外出时间填写有误！");
            dontUpdate->show();
            return;
        }
        QSqlQuery query;
        if(query.exec(tr("insert into waichu values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10',"
                         "'%11','%12','%13','%14','%15','%16','%17','外出','%18')").arg(name).arg(department).arg(position)
                      .arg(dealTime).arg(startTime).arg(endTime).arg(realTime).arg(toWhere).arg(punchIn).arg(withPeople)
                      .arg(reason).arg(leader).arg(leaderResult).arg(leadAdvice).arg(clerk).arg(clerkResult).arg(clerkAdvice)
                      .arg(LoginWindow::staffID)))
        {
            QSqlDatabase::database().commit();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请成功！\n实际返回时间和打卡情况\n外出返回后向考勤员反馈！");
            dontUpdate->show();
            emit emitFlushShowStreamSig("外出");
            //提交成功后发送给领导处理提示信息
            QUdpSocket * udpSocket = new QUdpSocket(this);
            QByteArray sendMsg;
            sendMsg = "您有新的外出电子流待处理！";
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
            if(query.exec(tr("update waichu set leaderResult = '%1',leaderAdvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_leaderDeal->currentText()).arg(ui->textEdit_leaderAdvice->toPlainText())
                          .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
            {
                QSqlDatabase::database().commit();
                //QMessageBox::about(this,"提示","提交处理成功！ ");
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
                dontUpdate->show();
                this->close();
                emit sendFlushDclSig();
                emit emitFlushShowStreamSig("点击处理");
                //提交成功后发送给领导处理提示信息
                QUdpSocket * udpSocket = new QUdpSocket(this);
                QByteArray sendMsg;
                sendMsg = "您有新的外出电子流待处理！";
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
            }
            else
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
            if(ui->lineEdit_realDay->text().isEmpty())
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请填写实际返回时间！");
                dontUpdate->show();
                return;
            }
            if((ui->lineEdit_realDay->text()+"/"+ui->timeEdit_realTime->text()) < (ui->lineEdit_startDay->text()+"/"+ui->timeEdit_realTime->text()))
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("填写实际返回时间有误！");
                dontUpdate->show();
                return;
            }
            QString puchInResult;
            if(ui->checkBox_workOff->isChecked())
            {
                puchInResult = "下班";
            }
            if(ui->checkBox_workOn->isChecked())
            {
                puchInResult = "上班";
            }
            if(ui->checkBox_workOff->isChecked() && ui->checkBox_workOn->isChecked())
            {
                puchInResult = "上下班";
            }
            QSqlQuery query;
            if(query.exec(tr("update waichu set clerkResult = '%1',clerkAdvice = '%2',realTime = '%5',punchIn='%6' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_clerkDeal->currentText()).arg(ui->textEdit_clerkAdvice->toPlainText())
                          .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text()).arg(ui->lineEdit_realDay->text()+"/"+ui->timeEdit_realTime->text()).arg(puchInResult)))
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
                sendMsg = "您的外出电子流已通过审核！";
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
    //
}
//
void WaiChu::showUI(QString showType, QString name, QString dealTime)
{
    if(showType == "新增")
    {
        ui->pButtonOk->setText("提交申请");
        ui->lineEdit_realDay->setEnabled(false);
        ui->toolButton_realDay->setEnabled(false);
        ui->timeEdit_realTime->setEnabled(false);
        ui->checkBox_workOff->setEnabled(false);
        ui->checkBox_workOn->setEnabled(false);
        ui->groupBox_clerk->setEnabled(false);
        ui->groupBox_leader->setEnabled(false);
        ui->lineEdit_startDay->setEnabled(false);
        ui->lineEdit_endDay->setEnabled(false);
        return;
    }
    QSqlQuery query;
    if(query.exec(tr("select * from waichu where name = '%1' and dealTime = '%2'").arg(name).arg(dealTime)))
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

            QString realDayTime = query.value(6).toString();
            QString realDay = realDayTime.mid(0,realDayTime.indexOf("/"));
            QString realTime = realDayTime.mid(realDayTime.indexOf("/")+1,5);
            ui->lineEdit_realDay->setText(realDay);
            ui->timeEdit_realTime->setTime(QTime(realTime.mid(0,realTime.indexOf(":")).toInt(),realTime.mid(realTime.indexOf(":")+1,2).toInt()));

            ui->lineEdit_toWhere->setText(query.value(7).toString());
            QString punchIn = query.value(8).toString();
            if(punchIn.size() > 1)
            {
                if(punchIn == "上班")
                {
                    ui->checkBox_workOn->click();
                }else if(punchIn == "下班"){
                    ui->checkBox_workOff->click();
                }else{
                    ui->checkBox_workOff->click();
                    ui->checkBox_workOn->click();
                }
            }
            ui->lineEdit_with->setText(query.value(9).toString());
            ui->lineEdit_reason->setText(query.value(10).toString());
            ui->comboBox_leader->setCurrentText(query.value(11).toString());
            ui->comboBox_leaderDeal->setCurrentText(query.value(12).toString());
            ui->textEdit_leaderAdvice->setText(query.value(13).toString());
            ui->comboBox_clerk->setCurrentText(query.value(14).toString());
            ui->comboBox_clerkDeal->setCurrentText(query.value(15).toString());
            ui->textEdit_clerkAdvice->setText(query.value(16).toString());
        }
    }
    if(showType == "查看")
    {
        ui->pButtonOk->setText("确定");
        ui->groupBox->setEnabled(false);
        ui->groupBox_allLeader->setEnabled(false);
        ui->groupBox_clerk->setEnabled(false);
        ui->groupBox_leader->setEnabled(false);
    }
    if(showType == "驳回")
    {
        ui->pButtonOk->setText("再次提交");
        ui->lineEdit_realDay->setEnabled(false);
        ui->toolButton_realDay->setEnabled(false);
        ui->timeEdit_realTime->setEnabled(false);
        ui->checkBox_workOff->setEnabled(false);
        ui->checkBox_workOn->setEnabled(false);
        ui->groupBox_clerk->setEnabled(false);
        ui->groupBox_leader->setEnabled(false);
    }
    if(showType == "点击处理")
    {
        ui->groupBox->setEnabled(false);
        ui->groupBox_allLeader->setEnabled(false);
        ui->groupBox_clerk->setEnabled(false);
        ui->groupBox_leader->setEnabled(false);
        if(LoginWindow::userName == ui->comboBox_leader->currentText())
        {
            ChuChai::setComboxStyle(ui->comboBox_leader,ui->groupBox_leader,ui->comboBox_leaderDeal,ui->textEdit_leaderAdvice);
        }
        if(LoginWindow::userName == ui->comboBox_clerk->currentText())
        {
            ui->groupBox->setEnabled(true);
            ui->lineEdit_dealTime->setEnabled(false);
            ui->lineEdit_realDay->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->checkBox_workOff->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->checkBox_workOn->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ChuChai::setComboxStyle(ui->comboBox_clerk,ui->groupBox_clerk,ui->comboBox_clerkDeal,ui->textEdit_clerkAdvice);
        }
        ui->pButtonOk->setText("提交处理");
    }
}
