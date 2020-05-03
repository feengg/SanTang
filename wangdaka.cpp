#include "wangdaka.h"
#include "ui_wangdaka.h"

WangDaKa::WangDaKa(QString showModel,QString name,QString department,QString dealTime,QString position ,
                   QString wdkDay,QString wdkType,QString wdkReason,
                   QString witName,QString witResult,QString witAdvice,
                   QString dptLeader,QString dptResult,QString dptAdvice,QString viceManager,
                   QString viceResult,QString viceAdvice,QString manager,QString managerResult
          ,QString managerAdvice,QString leader,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WangDaKa)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("新增电子流");

    ui->calendarWidget_wdkEndTime->hide();
    ui->calendarWidget_wdkStartTime->hide();

    ui->comboBox_department->addItem("研发部");
    ui->comboBox_department->addItem("财务部");
    ui->comboBox_department->addItem("市场部");
    ui->comboBox_department->addItem("总工办");
    ui->comboBox_department->addItem("总经办");
    ui->comboBox_department->addItem("质管部");
    ui->comboBox_department->addItem("生产部");

    ui->comboBox_position->addItem("软件工程师");
    ui->comboBox_position->addItem("硬件工程师");
    ui->comboBox_position->addItem("软件实习生");
    ui->comboBox_position->addItem("硬件实习生");
    ui->comboBox_position->addItem("射频工程师");
    ui->comboBox_position->addItem("信号处理工程师");
    ui->comboBox_position->addItem("信号处理实习生");
    ui->comboBox_position->addItem("项目管理专员");
    ui->comboBox_position->addItem("项目经理");
    ui->comboBox_position->addItem("硬件组组长");
    ui->comboBox_position->addItem("测试检验工程师");
    ui->comboBox_position->addItem("市场助理");
    ui->comboBox_position->addItem("会计");
    ui->comboBox_position->addItem("射频实习生");
    ui->comboBox_position->addItem("体系工程师");
    ui->comboBox_position->addItem("信号处理实习工程师");
    ui->comboBox_position->addItem("射频组组长");
    ui->comboBox_position->addItem("采购工程师");
    ui->comboBox_position->addItem("生产工艺员");
    ui->comboBox_position->addItem("结构工程师");
    ui->comboBox_position->addItem("生产部经理");
    ui->comboBox_position->addItem("保密专员");
    ui->comboBox_position->addItem("检验工程师");
    ui->comboBox_position->addItem("行政专员");
    ui->comboBox_position->addItem("标准化工程师");
    ui->comboBox_position->addItem("副总经理");
    ui->comboBox_position->addItem("总经理");

    ui->comboBox_dealResult1->addItem("待处理");
    ui->comboBox_dealResult1->addItem("属实");
    ui->comboBox_dealResult1->addItem("驳回");
    ui->comboBox_dealResult1->addItem("不属实");
    ui->comboBox_dealResult2->addItem("待处理");
    ui->comboBox_dealResult2->addItem("同意");
    ui->comboBox_dealResult2->addItem("驳回");
    ui->comboBox_dealResult2->addItem("不同意");
    ui->comboBox_dealResult3->addItem("待处理");
    ui->comboBox_dealResult3->addItem("同意");
    ui->comboBox_dealResult3->addItem("驳回");
    ui->comboBox_dealResult3->addItem("不同意");
    ui->comboBox_dealResult4->addItem("待处理");
    ui->comboBox_dealResult4->addItem("同意");
    ui->comboBox_dealResult4->addItem("驳回");
    ui->comboBox_dealResult4->addItem("不同意");
    QButtonGroup * btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->checkBox_sb,1);
    btnGroup->addButton(ui->checkBox_xb,2);

    dealLeader = leader;
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
                    ui->comboBox_leader4->addItem(query.value(0).toString());
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
    //新增
    if(showModel == "新增")
    {
        ui->lineEdit_name->setText(LoginWindow::userName);
        ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
        ui->comboBox_leader4->setCurrentText("陈美琪");
        ui->groupBox_leader1->setEnabled(false);
        ui->groupBox_leader2->setEnabled(false);
        ui->groupBox_leader3->setEnabled(false);
        ui->groupBox_leader4->setEnabled(false);
        ui->pushButton_OK->setText("提交申请");
        ui->checkBox_xb->setChecked(true);
    }else
    {
        ui->lineEdit_name->setText(name);
        ui->comboBox_department->setCurrentText(department);
        if(showModel == "驳回")
        {
            ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
        }else
        {
            ui->lineEdit_dealTime->setText(dealTime);
        }
        ui->comboBox_position->setCurrentText(position);
        ui->lineEdit_wdkStartTime->setText(wdkDay);
        if(wdkType == "上班忘打卡")
        {
            ui->checkBox_sb->setChecked(true);
        }else
        {
            ui->checkBox_xb->setChecked(true);
        }
        ui->textEdit_wdkReason->setText(wdkReason);
        ui->comboBox_leader1->setCurrentText(witName);
        ui->comboBox_dealResult1->setCurrentText(witResult);
        ui->textEdit_leaderAdvice1->setText(witAdvice);
        ui->comboBox_leader2->setCurrentText(dptLeader);
        ui->comboBox_dealResult2->setCurrentText(dptResult);
        ui->textEdit_leaderAdvice2->setText(dptAdvice);
        ui->comboBox_leader3->setCurrentText(viceManager);
        ui->comboBox_dealResult3->setCurrentText(viceResult);
        ui->textEdit_leaderAdvice3->setText(viceAdvice);
        ui->comboBox_leader4->setCurrentText(manager);
        ui->comboBox_dealResult4->setCurrentText(managerResult);
        ui->textEdit_leaderAdvice4->setText(managerAdvice);

        ui->groupBox_leader1->setEnabled(false);
        ui->groupBox_leader2->setEnabled(false);
        ui->groupBox_leader3->setEnabled(false);
        ui->groupBox_leader4->setEnabled(false);
        if(showModel == "查看"||showModel == "点击处理")
        {
            if(showModel == "查看")
            {

                if(witResult == "待处理" && dptResult == "待处理" && viceResult == "待处理" && managerResult == "待处理")
                {
                    ui->pushButton_OK->setText("删除申请");
                }else{
                    ui->pushButton_OK->setText("确定");
                }
            }else
            {
                ui->pushButton_OK->setText("提交处理");
            }

            ui->groupBox_allLeader->setEnabled(false);
            ui->groupBox_wdk->setEnabled(false);
            ui->groupBox_wdkType->setEnabled(false);
            if(leader == "证明人")
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
            if(leader == "副总经理")
            {
                ui->groupBox_leader3->setEnabled(true);
                ui->comboBox_leader3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
                ui->comboBox_dealResult3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
                ui->textEdit_leaderAdvice3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            }
            if(leader == "考勤员")
            {
                ui->groupBox_leader4->setEnabled(true);
                ui->comboBox_leader4->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
                ui->comboBox_dealResult4->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
                ui->textEdit_leaderAdvice4->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            }
        }else
        {
            ui->pushButton_OK->setText("再次提交");
        }
    }
}

WangDaKa::~WangDaKa()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void WangDaKa::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void WangDaKa::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void WangDaKa::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void WangDaKa::on_toolButton_clicked()
{
    this->close();
}

void WangDaKa::on_pushButton_Cancel_clicked()
{
    this->close();
}

void WangDaKa::on_toolButton_wdkStart_clicked()
{
    ui->calendarWidget_wdkStartTime->raise();
    ui->calendarWidget_wdkStartTime->show();
}



void WangDaKa::on_calendarWidget_wdkStartTime_selectionChanged()
{

    ui->lineEdit_wdkStartTime->setText(ui->calendarWidget_wdkStartTime->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget_wdkStartTime->hide();
}




void WangDaKa::on_pushButton_OK_clicked()
{
    if(ui->pushButton_OK->text() == "确定")
    {
        this->close();
        return;
    }
    if(ui->pushButton_OK->text() == "删除申请")
    {
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("delete from wangdakamsg where name = '%1' and dealtime = '%2'").arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除成功！");
            dontUpdate->show();
            QSqlDatabase::database().commit();
            emit emitFlushShowStreamSig("忘打卡");
            this->close();

        }else{
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除失败！请重试！");
            dontUpdate->show();
            QSqlDatabase::database().rollback();
        }
        return;
    }
    if(ui->pushButton_OK->text() == "提交处理")
    {
        if(ui->comboBox_dealResult1->currentText() == "待处理")
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
            dontUpdate->show();
            return;
        }
        qDebug () << "dealleader = " << dealLeader;
        if(dealLeader == "证明人")
        {
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            if(query.exec(tr("update wangdakamsg set witresult = '%1',witadvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_dealResult1->currentText()).arg(ui->textEdit_leaderAdvice1->toPlainText())
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
                sendMsg = "已处理忘打卡";
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
                    sendMsg = "下一个忘打卡";
                    if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
                    {
                        udpSocket->close();
                    }else
                    {
                        qDebug() << "udp error:" << udpSocket->errorString();
                    }
                }
            }else
            {
                qDebug() << "sql Error: " << query.lastError().text();
            }
        }
        //部门领导
        if(dealLeader == "部门领导")
        {
            if(ui->comboBox_dealResult2->currentText() == "待处理")
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
                dontUpdate->show();
                return;
            }
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            if(query.exec(tr("update wangdakamsg set dptresult = '%1',dptadvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_dealResult2->currentText()).arg(ui->textEdit_leaderAdvice2->toPlainText())
                          .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
            {
                QSqlDatabase::database().commit();
                //QMessageBox::about(this,"提示","提交处理成功！ ");
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
                dontUpdate->show();
                emit emitFlushShowStreamSig("点击处理");
                emit sendFlushDclSig();
                //提交成功后发送给领导处理提示信息
                QUdpSocket * udpSocket = new QUdpSocket(this);
                QByteArray sendMsg;
                sendMsg = "已处理忘打卡";
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
                    sendMsg = "下一个忘打卡";
                    if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
                    {
                        udpSocket->close();
                    }else
                    {
                        qDebug() << "udp error:" << udpSocket->errorString();
                    }
                }
            }
        }
        //
        if(dealLeader == "副总经理")
        {
            if(ui->comboBox_dealResult3->currentText() == "待处理")
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
                dontUpdate->show();
                return;
            }
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            if(query.exec(tr("update wangdakamsg set viceresult = '%1',viceadvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_dealResult3->currentText()).arg(ui->textEdit_leaderAdvice3->toPlainText())
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
                sendMsg = "已处理忘打卡";
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
                if(query.exec(tr("select ip from staffmsg where name = '%1'").arg(ui->comboBox_leader4->currentText())))
                {
                    query.next();
                    recvMsgUserIP = query.value(0).toString();
                    qDebug() << "recvMsgUserIP = " << recvMsgUserIP;
                    sendMsg = "下一个忘打卡";
                    if(udpSocket->writeDatagram(sendMsg,QHostAddress(recvMsgUserIP),4512))
                    {
                        udpSocket->close();
                    }else
                    {
                        qDebug() << "udp error:" << udpSocket->errorString();
                    }
                }
            }
        }
        //考勤员
        if(dealLeader == "考勤员")
        {
            if(ui->comboBox_dealResult4->currentText() == "待处理")
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
                dontUpdate->show();
                return;
            }
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            if(query.exec(tr("update wangdakamsg set clerkresult = '%1',clerkadvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_dealResult4->currentText()).arg(ui->textEdit_leaderAdvice4->toPlainText())
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
                sendMsg = "已处理忘打卡";
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
            }
        }
        this->close();
        return;
    }
    if(ui->lineEdit_name->text().trimmed().isEmpty()||ui->lineEdit_wdkStartTime->text().trimmed().isEmpty()||
            ui->textEdit_wdkReason->toPlainText().trimmed().isEmpty()||ui->comboBox_leader1->currentText().trimmed().isEmpty()
            ||ui->comboBox_leader2->currentText().trimmed().isEmpty()||ui->comboBox_leader3->currentText().trimmed().isEmpty()
            ||ui->comboBox_leader4->currentText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"提示","必填信息不能为空！   ");
        return;
    }
    if(ui->comboBox_leader2->currentText() == ui->comboBox_leader3->currentText())
    {
        QMessageBox::warning(this,"提示","部门领导和总经办选择有误！  ");
        return;
    }
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    QString wdkType =NULL;
    if(ui->checkBox_sb->isChecked())
    {
        wdkType = "上班忘打卡";
    }else
    {
        wdkType = "下班忘打卡";
    }
    if(query.exec(tr("insert into wangdakamsg values('%1','%2','%3','%4','%5','%6','%7','%8','待处理',NULL"
                     ",'%11','待处理',NULL,'%12','待处理',NULL,'%13','待处理',NULL,'%14','0','忘打卡')").arg(ui->lineEdit_name->text()).arg(ui->comboBox_department->currentText()).arg(ui->lineEdit_dealTime->text())
                  .arg(ui->comboBox_position->currentText()).arg(ui->lineEdit_wdkStartTime->text()).arg(wdkType).arg(ui->textEdit_wdkReason->toPlainText())
                  .arg(ui->comboBox_leader1->currentText()).arg(ui->comboBox_leader2->currentText()).arg(ui->comboBox_leader3->currentText())
                  .arg(ui->comboBox_leader4->currentText()).arg(LoginWindow::staffID)))
    {
        //QMessageBox::about(this,"提示","提交申请成功！  ");
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请成功！");
        dontUpdate->show();
        emit emitFlushShowStreamSig("忘打卡");
        //提交成功后发送给领导处理提示信息
        QUdpSocket * udpSocket = new QUdpSocket(this);
        QByteArray sendMsg;
        sendMsg = "新忘打卡";
        QString recvMsgUserIP;
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
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
    }

}
