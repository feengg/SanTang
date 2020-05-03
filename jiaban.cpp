#include "jiaban.h"
#include "ui_jiaban.h"
#include "widget.h"

Jiaban::Jiaban(QString showModel,QString name,QString department,QString dealTime,QString jbTimeArea,
               QString jbStartTime,QString jbEndTime,QString jbReason,QString jbContent,
               QString jbFoodValue,QString jbFoodMoney,QString leaderName,
               QString dealResult,QString leaderAdvice,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jiaban)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //
    ui->label_9->hide();
    ui->textEdit_jbContent->hide();
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("新增电子流");

    ui->groupBox_leader->setParent(this);
    ui->groupBox_leader->raise();
    ui->lineEdit_name->setText(LoginWindow::userName);

    ui->calendarWidget_jbStartTime->hide();

    ui->comboBox_timeArea->addItem("工作日加班");
    ui->comboBox_timeArea->addItem("周末假日加班");
    ui->comboBox_timeArea->addItem("法定节日加班");
    ui->comboBox_department->addItem("研发部");
    ui->comboBox_department->addItem("财务部");
    ui->comboBox_department->addItem("市场部");
    ui->comboBox_department->addItem("总工办");
    ui->comboBox_department->addItem("总经办");
    ui->comboBox_department->addItem("质管部");
    ui->comboBox_department->addItem("生产部");

    ui->comboBox_dealResult->addItem("待处理");
    ui->comboBox_dealResult->addItem("同意");
    ui->comboBox_dealResult->addItem("驳回");
    ui->comboBox_dealResult->addItem("不同意");


    ui->calendarWidget_jbEndTime->hide();
    ui->lineEdit_jbTime1->setEnabled(false);
    ui->lineEdit_jbTime2->setEnabled(false);
    //ui->groupBox_jb->setEnabled(false);

    showType = showModel;

    if(showModel == "新增")
    {
        ui->pushButton->setText("提交申请");
        ui->groupBox_jb->setTitle("新增加班申请");
        ui->timeEdit->setTime(QTime(18,0));
        ui->groupBox_leader->setEnabled(false);
        ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
        QSqlQuery query;
        int num;
        if(!QSqlDatabase::database().isValid())
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
                }

            }
        }
        ui->comboBox_leader1->setCurrentText("陈美琪");
    }
    if(showModel == "驳回" || showModel == "不同意")
    {
        ui->groupBox_leader->setEnabled(false);
        ui->lineEdit_name->setText(name);
        ui->comboBox_department->setCurrentText(department);
        //ui->lineEdit_dealTime->setText(dealTime);
        ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
        ui->comboBox_timeArea->setCurrentText(jbTimeArea);
        ui->lineEdit_jbTime1->setText(jbStartTime.mid(0,10));
        //qDebug() << "jbStartTime.mid(10,10)) = " << jbStartTime.mid(11,10);
        ui->timeEdit->setTime(QTime(jbStartTime.mid(11,jbStartTime.indexOf(":",0)-11).toInt(),jbStartTime.mid(jbStartTime.indexOf(":",0)+1,5).toInt()));
        ui->lineEdit_jbTime2->setText(jbEndTime.mid(0,10));
        ui->timeEdit_2->setTime(QTime(jbEndTime.mid(11,jbEndTime.indexOf(":",0)-11).toInt(),jbEndTime.mid(jbEndTime.indexOf(":",0)+1,5).toInt()));
        ui->textEdit_jbReason->setText(jbReason);
        ui->textEdit_jbContent->setText(jbContent);
        switch (jbFoodValue.toInt()) {
        case 1:
            ui->checkBox->setChecked(true);
            break;
        case 2:
            ui->checkBox_2->setChecked(true);
            break;
        case 4:
            ui->checkBox_3->setChecked(true);
            break;
        case 3:
            ui->checkBox->setChecked(true);
            ui->checkBox_2->setChecked(true);
            break;
        case 5:
            ui->checkBox_3->setChecked(true);
            ui->checkBox->setChecked(true);
            break;
        case 6:
            ui->checkBox_3->setChecked(true);
            ui->checkBox_2->setChecked(true);
            break;
        case 7:
            ui->checkBox_3->setChecked(true);
            ui->checkBox->setChecked(true);
            ui->checkBox_2->setChecked(true);
            break;
        default:
            break;
        }
        ui->lineEdit_jbFoodMoney->setText(jbFoodMoney);
        //ui->comboBox_leader1->setCurrentText(leaderName);
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
                }

            }
        }
        ui->comboBox_dealResult->setCurrentText(dealResult);
        ui->textEdit_leaderAdvice->setPlainText(leaderAdvice);
        ui->pushButton->setText("再次提交");
    }
    if(showModel == "查看" || showModel == "点击处理")
    {

        ui->groupBox_jb->setEnabled(false);
        if(showModel == "点击处理")
        {
            ui->groupBox_leader->setEnabled(true);
            ui->comboBox_leader1->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->comboBox_dealResult->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
            ui->textEdit_leaderAdvice->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(216, 235, 233);");
        }else{
            ui->groupBox_leader->setEnabled(false);
        }
        ui->lineEdit_name->setText(name);
        ui->comboBox_department->setCurrentText(department);
        ui->lineEdit_dealTime->setText(dealTime);
        ui->comboBox_timeArea->setCurrentText(jbTimeArea);
        ui->lineEdit_jbTime1->setText(jbStartTime.mid(0,10));
        //qDebug() << "jbStartTime.mid(10,10)) = " << jbStartTime.mid(11,10);
        ui->timeEdit->setTime(QTime(jbStartTime.mid(11,jbStartTime.indexOf(":",0)-11).toInt(),jbStartTime.mid(jbStartTime.indexOf(":",0)+1,5).toInt()));
        ui->lineEdit_jbTime2->setText(jbEndTime.mid(0,10));
        ui->timeEdit_2->setTime(QTime(jbEndTime.mid(11,jbEndTime.indexOf(":",0)-11).toInt(),jbEndTime.mid(jbEndTime.indexOf(":",0)+1,5).toInt()));
        ui->textEdit_jbReason->setText(jbReason);
        ui->textEdit_jbContent->setText(jbContent);
        switch (jbFoodValue.toInt()) {
        case 1:
            ui->checkBox->setChecked(true);
            break;
        case 2:
            ui->checkBox_2->setChecked(true);
            break;
        case 4:
            ui->checkBox_3->setChecked(true);
            break;
        case 3:
            ui->checkBox->setChecked(true);
            ui->checkBox_2->setChecked(true);
            break;
        case 5:
            ui->checkBox_3->setChecked(true);
            ui->checkBox->setChecked(true);
            break;
        case 6:
            ui->checkBox_3->setChecked(true);
            ui->checkBox_2->setChecked(true);
            break;
        case 7:
            ui->checkBox_3->setChecked(true);
            ui->checkBox->setChecked(true);
            ui->checkBox_2->setChecked(true);
            break;
        default:
            break;
        }
        ui->lineEdit_jbFoodMoney->setText(jbFoodMoney);
        ui->comboBox_leader1->setCurrentText(leaderName);
        ui->comboBox_dealResult->setCurrentText(dealResult);
        ui->textEdit_leaderAdvice->setText(leaderAdvice);
        if(showModel == "点击处理")
        {
           ui->pushButton->setText("提交处理");
        }else{
            if(dealResult == "待处理")
            {
                ui->pushButton->setText("删除申请");
            }else{
                ui->pushButton->setText("确定");
            }

        }

    }

}

Jiaban::~Jiaban()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void Jiaban::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void Jiaban::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void Jiaban::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}



void Jiaban::on_toolButton_clicked()
{
    this->close();
}

void Jiaban::on_toolButton_2_clicked()
{
    ui->calendarWidget_jbStartTime->show();
}

void Jiaban::on_toolButton_3_clicked()
{
    ui->calendarWidget_jbEndTime->show();
}

void Jiaban::on_calendarWidget_jbStartTime_selectionChanged()
{
    ui->lineEdit_jbTime1->setText(ui->calendarWidget_jbStartTime->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget_jbStartTime->hide();
}





void Jiaban::on_calendarWidget_jbEndTime_selectionChanged()
{
    ui->lineEdit_jbTime2->setText(ui->calendarWidget_jbEndTime->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget_jbEndTime->hide();
}


void Jiaban::on_pushButton_clicked()
{

    if(showType == "查看")
    {

        if(ui->pushButton->text() == "删除申请")
        {
            qDebug() << "into delte";
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            if(query.exec(tr("delete from jiabanmsg where name = '%1' and dealtime = '%2'").arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text())))
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除成功！");
                dontUpdate->show();
                QSqlDatabase::database().commit();
                emit emitFlushShowStreamSig("加班");
                this->close();

            }else{
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除失败！请重试！");
                dontUpdate->show();
                QSqlDatabase::database().rollback();
            }
        }else
        {
            this->close();
        }
        return;
    }

    if(showType == "点击处理" && ui->comboBox_dealResult->currentText() == "待处理")
    {
        QMessageBox::about(this,"提示","请选择处理结果项！  ");
        return;
    }
    if(ui->lineEdit_name->text().trimmed().isEmpty()||ui->lineEdit_dealTime->text().trimmed().isEmpty()
            ||ui->lineEdit_jbTime1->text().trimmed().isEmpty()||ui->lineEdit_jbTime2->text().trimmed().isEmpty()
            ||ui->textEdit_jbReason->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::about(this,"提示","必填信息不能为空！  ");
        return;
    }
    if((ui->checkBox->isChecked()||ui->checkBox_2->isChecked()||ui->checkBox_3->isChecked())&&ui->lineEdit_jbFoodMoney->text().trimmed().isEmpty())
    {
        QMessageBox::about(this,"提示","请填写加班餐费！  ");
        return;
    }
    if(!(ui->lineEdit_jbFoodMoney->text().trimmed().isEmpty())&&!(ui->checkBox->isChecked()||ui->checkBox_2->isChecked()||ui->checkBox_3->isChecked()))
    {
        QMessageBox::about(this,"提示","请选择餐费项！  ");
        return;
    }
    if(ui->lineEdit_jbTime1->text() > ui->lineEdit_jbTime2->text())
    {
        QMessageBox::about(this,"提示","加班时间填写有误！  ");
        return;
    }
    if(ui->comboBox_timeArea->currentText() == "工作日加班" && (ui->lineEdit_jbTime2->text().mid(8,2).toInt() - ui->lineEdit_jbTime1->text().mid(8,2).toInt() > 1))
    {
        QMessageBox::about(this,"提示","工作日加班时间填写有误！  ");
        return;
    }
    if(ui->lineEdit_jbTime1->text().mid(5,2) != ui->lineEdit_jbTime2->text().mid(5,2))
    {
        QMessageBox::about(this,"提示","加班日期必须在同一月份内！  ");
        return;
    }
    if(ui->lineEdit_jbFoodMoney->text().toFloat())
    {
        int time = 0;
        jbFoodValue = 0;
        if(ui->checkBox->isChecked())
        {
            jbFoodValue += 1;
            time++;
        }
        if(ui->checkBox_2->isChecked())
        {
            jbFoodValue += 2;
            time++;
        }
        if(ui->checkBox_3->isChecked())
        {
            jbFoodValue += 4;
            time++;
        }
        if(ui->lineEdit_jbFoodMoney->text().toInt() > 15*time)
        {
            QMessageBox::about(this,"提示","每顿餐补不能超过15元！  ");
            return;
        }
    }else
    {
        if(ui->lineEdit_jbFoodMoney->text().toInt() != 0)
        {
            QMessageBox::about(this,"提示","加班餐费填写有误！  ");
            return;
        }

    }
    if(showType == "新增"||showType == "驳回" || showType == "不同意"||showType == "点击处理")
    {
        //提交

        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }else
        {
            QSqlQuery query;
            bool ret;
            if(showType == "点击处理")
            {
                if(ui->comboBox_dealResult->currentText() == "待处理")
                {
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请选择处理结果！");
                    dontUpdate->show();
                    return;
                }
                ret = query.exec(tr("update jiabanmsg set dealresult = '%1',leaderadvice = '%2' where name = '%3' and dealtime ='%4'").arg(ui->comboBox_dealResult->currentText()).arg(ui->textEdit_leaderAdvice->toPlainText())
                                 .arg(ui->lineEdit_name->text()).arg(ui->lineEdit_dealTime->text()));
            }else{
                ret = query.exec(tr("insert into jiabanmsg values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10'"
                                         ",'%11','待处理','无','%12','0','加班')").arg(ui->lineEdit_name->text()).arg(ui->comboBox_department->currentText())
                                      .arg(ui->lineEdit_dealTime->text()).arg(ui->comboBox_timeArea->currentText())
                                      .arg(ui->lineEdit_jbTime1->text()+"/"+ui->timeEdit->text()).arg(ui->lineEdit_jbTime2->text()+"/"+ui->timeEdit_2->text())
                                      .arg(ui->textEdit_jbReason->toPlainText()).arg(ui->textEdit_jbContent->toPlainText())
                                      .arg(QString::number(jbFoodValue)).arg(ui->lineEdit_jbFoodMoney->text())
                                      .arg(ui->comboBox_leader1->currentText())
                                      .arg(LoginWindow::staffID));
            }

            if(ret == true)
            {
                QSqlDatabase::database().commit();
                if(showType == "点击处理")
                {
                    //QMessageBox::about(this,"提示","提交处理成功！  ");
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交处理成功！");
                    dontUpdate->show();
                    emit sendFlushDclSig();
                    emit emitFlushShowStreamSig("点击处理");
                    //提交成功后发送给领导处理提示信息
                    QUdpSocket * udpSocket = new QUdpSocket(this);
                    QByteArray sendMsg;
                    sendMsg = "已处理加班";
                    QString recvMsgUserIP;
                    if(!QSqlDatabase::database().isOpen())
                    {
                        Widget::openMySql();
                    }
                    QSqlQuery query;
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
                }else{
                    //QMessageBox::about(this,"提示","提交申请成功！  ");
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请成功！");
                    dontUpdate->show();
                    emit emitFlushShowStreamSig("加班");
                    //提交成功后发送给领导处理提示信息
                    QUdpSocket * udpSocket = new QUdpSocket(this);
                    QByteArray sendMsg;
                    sendMsg = "新加班";
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
                }
                this->close();
                return;
            }else
            {
                QSqlDatabase::database().rollback();
                QMessageBox::about(this,"提示",tr("提交申请失败:%1  ").arg(query.lastError().text()));
                this->close();
                return;
            }
        }
    }

}

void Jiaban::on_pushButton_cancel_clicked()
{
    this->close();
}
