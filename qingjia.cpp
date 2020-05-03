#include <QButtonGroup>
#include "qingjia.h"
#include "ui_qingjia.h"

QingJia::QingJia(QString showModel,QString name,QString department,QString dealTime,QString position,
                 QString qjStartTime,QString qjEndTime,QString qjType,QString qjDay,QString qjReason,
                 QString tipMsg,QString dptLeader,QString dptResult,QString dptAdvice,QString viceManager,
                 QString viceResult,QString viceAdvice,QString manager,QString managerResult,QString managerAdvice,
                 QString leader,QWidget *parent) :
    QWidget(parent),

    ui(new Ui::QingJia)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("新增请假");
    qDebug() << "qjDay = " << qjDay;


    ui->calendarWidget_qjEndTime->raise();
    ui->calendarWidget_qjStartTime->raise();
    ui->calendarWidget_qjEndTime->hide();
    ui->calendarWidget_qjStartTime->hide();

    ui->comboBox_department->addItem("研发部");
    ui->comboBox_department->addItem("财务部");
    ui->comboBox_department->addItem("市场部");
    ui->comboBox_department->addItem("总工办");
    ui->comboBox_department->addItem("总经办");
    ui->comboBox_department->addItem("质管部");
    ui->comboBox_department->addItem("生产部");

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

    ui->comboBox_dw->addItem("天");
    ui->comboBox_dw->addItem("小时");
    showType = showModel;
    dealLeader = leader;

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->checkBox_sj,1);
    btnGroup->addButton(ui->checkBox_bj,2);
    btnGroup->addButton(ui->checkBox_shijia,3);
    btnGroup->addButton(ui->checkBox_hx,4);
    btnGroup->addButton(ui->checkBox_other,5);
    //初始化审核人combox
    ui->comboBox_leader3->addItem("无");
    ui->comboBox_leader3->addItem("吴伟");
    QSqlQuery query;
    int num;
    if(!QSqlDatabase::database().isOpen())
    {

        Widget::openMySql();
    }
    else
    {

        if(query.exec("select count(*) from staffmsg where level <=2 and level >0"))
        {
            query.next();
            num = query.value(0).toInt();

            if(num ==0)
            {
                return;
            }
        }
        if(query.exec("select name from staffmsg where level <= 2 and level >0"))
        {
            for(int i = 0;i < num;i ++)
            {
                query.next();
                ui->comboBox_leader1->addItem(query.value(0).toString());
                ui->comboBox_leader2->addItem(query.value(0).toString());
            }

        }
    }
    //不同打开模式初始
    if(showModel == "新增")
    {
        ui->pButtonOk->setText("提交申请");
        ui->groupBox_qj->setTitle("新增请假申请");
        ui->groupBox_leader1->setEnabled(false);
        ui->groupBox_leader2->setEnabled(false);
        ui->groupBox_leader3->setEnabled(false);
        ui->checkBox_shijia->setChecked(true);
        ui->lineEdit_name->setText(LoginWindow::userName);
        ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
    }
    if(showModel == "不同意"||showModel == "驳回")
    {
        ui->pButtonOk->setText("再次提交");
        ui->groupBox_qj->setTitle("查看请假申请");
        ui->groupBox_leader1->setEnabled(false);
        ui->groupBox_leader2->setEnabled(false);
        ui->groupBox_leader3->setEnabled(false);

        ui->lineEdit_name->setText(name);
        ui->comboBox_department->setCurrentText(department);
        ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
        ui->comboBox_position->setCurrentText(position);
        ui->lineEdit_qjDayNum->setText(qjDay);
        if(qjType == "伤假")
        {
            ui->checkBox_sj->setChecked(true);
        }
        if(qjType == "病假")
        {
            ui->checkBox_bj->setChecked(true);
        }
        if(qjType == "事假")
        {
            ui->checkBox_shijia->setChecked(true);
        }
        if(qjType == "换休")
        {
            ui->checkBox_hx->setChecked(true);
            ui->comboBox_dw->setCurrentText("小时");
        }
        if(qjType == "其他")
        {
            ui->checkBox_other->setChecked(true);
        }
        ui->textEdit_qjReason->setPlainText(qjReason);
        ui->textEdit_qjRecord->setPlainText(tipMsg);
        ui->comboBox_leader1->setCurrentText(dptLeader);
        ui->comboBox_dealResult1->setCurrentText(dptResult);
        ui->textEdit_leaderAdvice1->setPlainText(dptAdvice);
        ui->comboBox_leader2->setCurrentText(viceManager);
        ui->comboBox_dealResult2->setCurrentText(viceResult);
        ui->textEdit_leaderAdvice2->setPlainText(viceAdvice);
        ui->comboBox_leader3->setCurrentText(manager);
        ui->comboBox_dealResult3->setCurrentText(managerResult);
        ui->textEdit_leaderAdvice3->setPlainText(managerAdvice);

        ui->lineEdit_qjStartTime->setText(qjStartTime.mid(0,10));

        ui->timeEdit->setTime(QTime(qjStartTime.mid(11,qjStartTime.indexOf(":",0)-11).toInt(),qjStartTime.mid(qjStartTime.indexOf(":",0)+1,5).toInt()));
        ui->lineEdit_qjEndTime->setText(qjEndTime.mid(0,10));
        ui->timeEdit_2->setTime(QTime(qjEndTime.mid(11,qjEndTime.indexOf(":",0)-11).toInt(),qjEndTime.mid(qjEndTime.indexOf(":",0)+1,5).toInt()));
    }
    if(showModel == "查看"||showModel == "点击处理")
    {
        if(showModel == "查看")
        {
            if(dptResult == "待处理" && viceResult == "待处理" && managerResult == "待处理")
            {
                ui->pButtonOk->setText("删除申请");
            }else{
                ui->pButtonOk->setText("确定");
            }

            ui->groupBox_qj->setTitle("查看请假申请");
        }else
        {
            ui->pButtonOk->setText("提交处理");
            ui->groupBox_qj->setTitle("处理请假申请");
        }
        ui->groupBox_leader1->setEnabled(false);
        ui->groupBox_leader2->setEnabled(false);
        ui->groupBox_leader3->setEnabled(false);
        if(leader == "部门领导")
        {
            ui->groupBox_leader1->setEnabled(true);
            ui->comboBox_leader1->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->comboBox_dealResult1->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->textEdit_leaderAdvice1->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
        }
        if(leader == "副总经理")
        {
            ui->groupBox_leader2->setEnabled(true);
            ui->comboBox_leader2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->comboBox_dealResult2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->textEdit_leaderAdvice2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
        }
        if(leader == "总经理")
        {
            ui->groupBox_leader3->setEnabled(true);
            ui->comboBox_leader2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->comboBox_dealResult3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->textEdit_leaderAdvice3->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
        }
        ui->groupBox_allLeader->setEnabled(false);
        ui->groupBox_qj->setEnabled(false);
        ui->groupBox_qjType->setEnabled(false);

        ui->lineEdit_name->setText(name);
        ui->comboBox_department->setCurrentText(department);
        ui->lineEdit_dealTime->setText(dealTime);
        ui->comboBox_position->setCurrentText(position);
        if(qjDay.indexOf("h") != -1)
        {
            ui->lineEdit_qjDayNum->setText(qjDay.mid(0,qjDay.indexOf("h")));
            ui->comboBox_dw->setCurrentText("小时");
        }
        else
        {
            ui->lineEdit_qjDayNum->setText(qjDay);
            ui->comboBox_dw->setCurrentText("天");
        }
        if(qjType == "伤假")
        {
            ui->checkBox_sj->setChecked(true);

        }
        if(qjType == "病假")
        {
            ui->checkBox_bj->setChecked(true);
        }
        if(qjType == "事假")
        {
            ui->checkBox_shijia->setChecked(true);
        }
        if(qjType == "换休")
        {
            ui->checkBox_hx->setChecked(true);
            ui->comboBox_dw->setCurrentText("小时");
        }
        if(qjType == "其他")
        {
            ui->checkBox_other->setChecked(true);
        }
        ui->textEdit_qjReason->setPlainText(qjReason);
        ui->textEdit_qjRecord->setPlainText(tipMsg);
        ui->comboBox_leader1->setCurrentText(dptLeader);
        ui->comboBox_dealResult1->setCurrentText(dptResult);
        ui->textEdit_leaderAdvice1->setPlainText(dptAdvice);
        ui->comboBox_leader2->setCurrentText(viceManager);
        ui->comboBox_dealResult2->setCurrentText(viceResult);
        ui->textEdit_leaderAdvice2->setPlainText(viceAdvice);
        ui->comboBox_leader3->setCurrentText(manager);
        ui->comboBox_dealResult3->setCurrentText(managerResult);
        ui->textEdit_leaderAdvice3->setPlainText(managerAdvice);
        ui->lineEdit_qjStartTime->setText(qjStartTime.mid(0,10));

        ui->timeEdit->setTime(QTime(qjStartTime.mid(11,qjStartTime.indexOf(":",0)-11).toInt(),qjStartTime.mid(qjStartTime.indexOf(":",0)+1,5).toInt()));
        ui->lineEdit_qjEndTime->setText(qjEndTime.mid(0,10));
        ui->timeEdit_2->setTime(QTime(qjEndTime.mid(11,qjEndTime.indexOf(":",0)-11).toInt(),qjEndTime.mid(qjEndTime.indexOf(":",0)+1,5).toInt()));
    }
    if(qjDay.indexOf("h") != -1)
    {
        ui->lineEdit_qjDayNum->setText(qjDay.mid(0,qjDay.indexOf("h")));
        ui->comboBox_dw->setCurrentText("小时");
    }
    else
    {
        ui->lineEdit_qjDayNum->setText(qjDay);
        ui->comboBox_dw->setCurrentText("天");
    }
}

QingJia::~QingJia()
{
    delete ui;
}

void QingJia::on_toolButton_close_clicked()
{
    this->close();
}

void QingJia::on_pButtonCancel_clicked()
{
    this->close();
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void QingJia::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void QingJia::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void QingJia::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void QingJia::on_toolButton_qjStart_clicked()
{
    ui->calendarWidget_qjStartTime->show();
}

void QingJia::on_toolButton_qjEnd_clicked()
{
    ui->calendarWidget_qjEndTime->show();
}

void QingJia::on_calendarWidget_qjStartTime_selectionChanged()
{
    ui->lineEdit_qjStartTime->setText(ui->calendarWidget_qjStartTime->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget_qjStartTime->hide();
}

void QingJia::on_calendarWidget_qjEndTime_selectionChanged()
{
    ui->lineEdit_qjEndTime->setText(ui->calendarWidget_qjEndTime->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget_qjEndTime->hide();
}

void QingJia::on_pButtonOk_clicked()
{
    if(ui->pButtonOk->text() == "确定")
    {
        this->close();
        return;
    }
    if(ui->pButtonOk->text() == "删除申请")
    {
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("delete from qingjiamsg where name = '%1' and dealtime = '%2'").arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除成功！");
            dontUpdate->show();
            QSqlDatabase::database().commit();
            emit emitFlushShowStreamSig("请假");
            this->close();

        }else{
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除失败！请重试！");
            dontUpdate->show();
            QSqlDatabase::database().rollback();
        }
    }
    if(ui->pButtonOk->text() == "提交处理")
    {
        if(dealLeader == "部门领导")
        {
            if(ui->comboBox_dealResult1->currentText() == "待处理")
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
            if(query.exec(tr("update qingjiamsg set dptresult = '%1',dptadvice = '%2' where name = '%3' and dealtime='%4'")
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
                sendMsg = "已处理请假";
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
                    sendMsg = "下一个请假";
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
        if(dealLeader == "副总经理")
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
            if(query.exec(tr("update qingjiamsg set viceresult = '%1',viceadvice = '%2' where name = '%3' and dealtime='%4'")
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
                sendMsg = "已处理请假";
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
                    sendMsg = "下一个请假";
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
        if(dealLeader == "总经理")
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
            if(query.exec(tr("update qingjiamsg set managerresult = '%1',manageradvice = '%2' where name = '%3' and dealtime='%4'")
                          .arg(ui->comboBox_dealResult3->currentText()).arg(ui->textEdit_leaderAdvice3->toPlainText())
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
                sendMsg = "已处理请假";
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

    if(ui->lineEdit_name->text().trimmed().isEmpty()||ui->lineEdit_qjStartTime->text().isEmpty()||ui->lineEdit_qjEndTime->text().isEmpty()||
            ui->lineEdit_qjDayNum->text().trimmed().isEmpty()||ui->textEdit_qjReason->toPlainText().isEmpty())
    {
        QMessageBox::warning(this,"提示","必填信息不能为空！  ");
        return;
    }
    if(ui->lineEdit_qjDayNum->text().toFloat())
    {
        if(ui->comboBox_dw->currentText() == "小时")
        {
            if(ui->lineEdit_qjDayNum->text().toInt() >= 48)
            {
                QMessageBox::warning(this,"提示","请假超过两天需要总经理批准！  ");
                return;
            }
        }
        else{
            if(!ui->checkBox_hx->isChecked() && ui->lineEdit_qjDayNum->text().toFloat() >= 2 && ui->comboBox_leader3->currentText() == "无")
            {
                QMessageBox::warning(this,"提示","请假超过两天需要总经理批准！  ");
                return;
            }
        }

        if(ui->lineEdit_qjDayNum->text().toFloat() < 2 && ui->comboBox_leader3->currentText() == "吴伟")
        {
            QMessageBox::warning(this,"提示","请假两天内不需要总经理批准！  ");
            return;
        }
        if(ui->checkBox_hx->isChecked()&&ui->comboBox_leader3->currentText() == "吴伟")
        {
            QMessageBox::warning(this,"提示","换休不需要总经理批准！  ");
            return;
        }
    }else
    {
        QMessageBox::warning(this,"提示","请假天数填写有误！  ");
        return;
    }
    if(ui->lineEdit_qjStartTime->text() > ui->lineEdit_qjEndTime->text())
    {
        QMessageBox::about(this,"提示","请假时间填写有误！  ");
        return;
    }
    if(ui->comboBox_leader1->currentText() == ui->comboBox_leader2->currentText())
    {
        QMessageBox::warning(this,"提示","部门领导和总经办选择有误！  ");
        return;
    }
    if(ui->pButtonOk->text() == "提交申请" || ui->pButtonOk->text() == "再次提交")
    {
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }else
        {
            QString qjType = NULL;
            switch (btnGroup->checkedId()) {
            case 1:
                qjType = "伤假";
                break;
            case 2:
                qjType = "病假";
                break;
            case 3:
                qjType = "事假";
                break;
            case 4:
                qjType = "换休";
                break;
            case 5:
                qjType = "其他";
                break;
            default:
                break;
            }
            QString qjTipMsg = NULL;
            if(ui->textEdit_qjRecord->toPlainText().trimmed().isEmpty())
            {
                qjTipMsg = "无";
            }else
            {
                qjTipMsg = ui->textEdit_qjRecord->toPlainText();
            }
            QSqlQuery query;
            QString qjDayStr;
            if(ui->comboBox_dw->currentText() == "小时")
            {
                qjDayStr = QString::number(ui->lineEdit_qjDayNum->text().toFloat()) + "h";
            }else{
                qjDayStr = QString::number(ui->lineEdit_qjDayNum->text().toFloat());
            }
            int ret = query.exec(tr("insert into qingjiamsg values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10'"
                                     ",'%11','待处理',NULL,'%12','待处理',NULL,'%13','待处理',NULL,'%14','0','请假')").arg(ui->lineEdit_name->text()).arg(ui->comboBox_department->currentText())
                                  .arg(ui->lineEdit_dealTime->text()).arg(ui->comboBox_position->currentText())
                                  .arg(ui->lineEdit_qjStartTime->text()+"/"+ui->timeEdit->text()).arg(ui->lineEdit_qjEndTime->text()+"/"+ui->timeEdit_2->text())
                                  .arg(qjType).arg(qjDayStr).arg(ui->textEdit_qjReason->toPlainText()).arg(qjTipMsg)
                                  .arg(ui->comboBox_leader1->currentText()).arg(ui->comboBox_leader2->currentText()).arg(ui->comboBox_leader3->currentText())
                                  .arg(LoginWindow::staffID));
            if(ret)
            {
                //QMessageBox::about(this,"提示","提交申请成功！  ");
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请成功！");
                dontUpdate->show();
                emit emitFlushShowStreamSig("请假");
                //提交成功后发送给领导处理提示信息
                QUdpSocket * udpSocket = new QUdpSocket(this);
                QByteArray sendMsg;
                sendMsg = "新请假";
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
                return;
            }
        }
    }
}

void QingJia::on_checkBox_hx_stateChanged(int arg1)
{
    if(ui->checkBox_hx->isChecked())
    {
        ui->comboBox_dw->setCurrentText("小时");
    }else
    {
        ui->comboBox_dw->setCurrentText("天");
    }
}
