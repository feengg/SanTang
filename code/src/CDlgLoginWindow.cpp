//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgLoginWindow.cpp
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CDlgLoginWindow类
// History			:
//******************************************************************************

#include "CDlgLoginWindow.h"
#include "ui_qDlgLoginWindow.h"
#include <QPainter>
#include <QMovie>
#include <QHBoxLayout>
#include <QCursor>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QDataStream>
#include <QThread>

QString CDlgLoginWindow::msUserName = NULL;
int CDlgLoginWindow::miUserLevel = 0;
QString CDlgLoginWindow::msStaffID = NULL;
QString CDlgLoginWindow::msIpAddr = NULL;
QString CDlgLoginWindow::msVersion = NULL;
QString CDlgLoginWindow::msPassWord = NULL;

CDlgLoginWindow::CDlgLoginWindow(QWidget *parent)
    : CDlgBaseWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    mvInitWindow();
    mvInitTitle();
    this->mvLoadStyleSheet("../code/css/LoginWindow/LoginWindow.css");
    this->setWindowTitle(tr("login"));

    ui->rememberPsd->setChecked(true);
    if (!QFile::exists("C:/Users/Administrator/Desktop/三棠OA.lnk"))
    {
        QFile::copy(qApp->QCoreApplication::applicationDirPath() + "/三棠OA.lnk", "C:/Users/Administrator/Desktop/三棠OA.lnk");
    }
    ui->autoLogin->setChecked(true);
    qDebug() << "exiet:" << QFile::exists("account.dat");
    //if (QFile::exists(qApp->applicationDirPath() + "/account.dat"))
    //{
    //    QFile file(qApp->applicationDirPath() + "/account.dat");
    //    file.open(QIODevice::ReadOnly);

    //    QByteArray rememberPswFlag = NULL;
    //    QByteArray autoLoginFlag = NULL;
    //    QByteArray passWord = NULL;
    //    rememberPswFlag = file.readLine();
    //    autoLoginFlag = file.readLine();
    //    staffId = file.readLine();
    //    passWord = file.readLine();

    //    msVersion = file.readLine();
    //    rememberPswFlag.replace("\n", "");
    //    autoLoginFlag.replace("\n", "");
    //    staffId.replace("\n", "");
    //    passWord.replace("\n", "");
    //    msVersion.replace("\n", "");
    //    msVersion = "v3.2";
    //    qDebug() << "version=" << msVersion;
    //    qDebug() << "all param=" << QString(rememberPswFlag) << QString(staffId) << QString(passWord);
    //    ui->accountComboBox->setCurrentText(staffId);
    //    if (rememberPswFlag == "true")
    //    {
    //        ui->rememberPsd->setChecked(true);
    //        ui->passwordEdit->setText(passWord);

    //    }
    //    else
    //    {
    //        ui->rememberPsd->setChecked(false);
    //    }
    //    //如果设置了自动登录
    //    if (autoLoginFlag == "true")
    //    {
    //        qDebug() << "2222";
    //        if (!QSqlDatabase::database().isOpen())
    //        {
    //            Widget::openMySql();
    //        }
    //        //qDebug() << "2223";
    //        //QSqlQuery query;

    //        qDebug() << "sql=" << tr("select name,ip,level,staffPassword from staffmsg where staffid = '%1'").arg(QString(staffId));

    //        if (query.exec(tr("select name,ip,level,staffPassword from staffmsg where staffid = '%1'").arg(QString(staffId))))
    //        {
    //            qDebug() << "2224";
    //            if (query.size() == 1)
    //            {
    //                qDebug() << "2225";
    //                query.next();
    //                if (passWord == query.value(3).toString())
    //                {
    //                    msUserName = query.value(0).toString();
    //                    msIpAddr = query.value(1).toString();
    //                    miUserLevel = query.value(2).toInt();
    //                    msStaffID = QString(staffId);
    //                    msPassWord = passWord;
    //                    qDebug() << "2226";
    //                    //Widget * widget = new Widget;
    //                    qDebug() << "2227";
    //                    connect(widget, SIGNAL(emitCloseLogWidgetSig()), this, SLOT(mslotGetCloseSlot()));
    //                    widget->show();
    //                    qDebug() << "2228";
    //                }

    //            }
    //        }
    //    }
    //}

}

//收到关闭窗口槽
void CDlgLoginWindow::mslotGetCloseSlot()
{
    qDebug() << "get close signal;";
    this->close();
}

CDlgLoginWindow::~CDlgLoginWindow()
{
    delete ui;
}


//******************************************************************************
// Function			: CDlgLoginWindow::mvMousePressEvent
// Description		: 实现没有边框的窗体鼠标移动功能
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-30
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgLoginWindow::mvMousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        moPosition = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

//******************************************************************************
// Function			: CDlgLoginWindow::mvMouseReleaseEvent
// Description		: 实现没有边框的窗体鼠标移动功能
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-30
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgLoginWindow::mvMouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


//******************************************************************************
// Function			: CDlgLoginWindow::mvMouseMoveEvent
// Description		: 实现没有边框的窗体鼠标移动功能
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-30
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgLoginWindow::mvMouseMoveEvent(QMouseEvent *event)
{
    if (dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - moPosition);
        event->accept();
    }
}

void CDlgLoginWindow::mvInitTitle()
{
    // 因为这里有控件层叠了，所以要注意控件raise()方法的调用顺序;
    mopTitleBar->move(0, 0);
    mopTitleBar->raise();
    mopTitleBar->mvSetBackGrdColr(0, 0, 0, true);
    mopTitleBar->mvSetButtonType(eMin_Button);
    mopTitleBar->mvSetTitleWidth(this->width());

    //ui->pButtonArrow->raise();
}

void CDlgLoginWindow::mvInitWindow()
{
    //背景GIG图;
    QLabel* pBack = new QLabel(this);
    QMovie *movie = new QMovie();
    movie->setFileName("../code/css/LoginWindow/back.gif");
    //movie->start();
   // movie->stop();
    pBack->setMovie(movie);
    movie->start();
    //pBack->move(0, 0);

    //暗注释;
    ui->accountComboBox->setEditable(true);
    QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
    lineEdit->setPlaceholderText(tr("number"));

    ui->passwordEdit->setPlaceholderText(tr("password"));

    // 密码框中的小键盘按钮;

    mopBtnKeyboard = new QPushButton();
    mopBtnKeyboard->setObjectName("pButtonKeyboard");
    mopBtnKeyboard->setFixedSize(QSize(16, 16));
    mopBtnKeyboard->setCursor(QCursor(Qt::PointingHandCursor));
    connect(mopBtnKeyboard, SIGNAL(clicked()), this, SLOT(mslotShowMinKeyBoard()));
    QHBoxLayout* passwordEditLayout = new QHBoxLayout();
    passwordEditLayout->addStretch();
    passwordEditLayout->addWidget(mopBtnKeyboard);
    passwordEditLayout->setSpacing(0);
    passwordEditLayout->setContentsMargins(0, 0, 8, 0);

    ui->passwordEdit->setLayout(passwordEditLayout);
    ui->passwordEdit->setTextMargins(0, 0, mopBtnKeyboard->width() + 12, 0);

    //ui->userHead->setPixmap(QPixmap(":/Resources/LoginWindow/HeadImage.png"));


}

void CDlgLoginWindow::mslotShowMinKeyBoard()
{
    //qDebug() << "intokeybutton";
    //KeyBoard * keyBoardDlg = new KeyBoard;
    //keyBoardDlg->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    //connect(keyBoardDlg, SIGNAL(setvalue(QString)), this, SLOT(mslotDisplayInputContent(QString)));
    //keyBoardDlg->move(this->pos().x() - 40, this->y() + this->frameGeometry().height() - 50);
    //keyBoardDlg->show();
}

void CDlgLoginWindow::mslotDisplayInputContent(QString text)
{
    ui->passwordEdit->setText(text);
}

void CDlgLoginWindow::mslotOnBtnFlickerClicked()
{
    //if (ui->accountComboBox->currentText().trimmed().isEmpty() || ui->passwordEdit->text().isEmpty())
    //{
    //    QMessageBox::warning(this, tr("提示"), tr("请填写工号和密码！  "), QMessageBox::Ok);
    //    return;
    //}
    //if (!QSqlDatabase::database().isValid())
    //{
    //    Widget::openMySql();
    //}
    //QSqlQuery query;
    //query.exec(tr("select count(staffID) from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed()));
    //query.next();
    //if (query.value(0).toInt() == 0)
    //{
    //    QMessageBox::warning(this, "OA提示", "工号错误！  ", QMessageBox::Ok);
    //}
    //else {
    //    query.exec(tr("select staffpassword,name,level,staffid,ip from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed()));
    //    query.next();
    //    QString password = query.value(0).toString();
    //    QString userName = query.value(1).toString();
    //    QString userID = query.value(3).toString();
    //    if (query.value(0).toString() != ui->passwordEdit->text())
    //    {
    //        QMessageBox::warning(this, "警告", "密码错误！  ", QMessageBox::Ok);
    //    }
    //    else {
    //        //主窗体显示
    //        //QMessageBox::warning(this,"警告","登录成功！",QMessageBox::Ok);
    //        //显示该员工考勤汇总
    //        //请假
    //        QString name = ui->accountComboBox->currentText().trimmed();
    //        QString time = QDateTime::currentDateTime().toString("yyyy-MM");
    //        query.exec(tr("select count(*) from qingjiamsg where staffid='%1' and qjStartTime like '%%2%' and (manager = '无' or (manager != '无' and managerResult='同意')) and dptResult='同意' and viceResult='同意'")
    //            .arg(name).arg(time));
    //        query.next();
    //        int qjDay = query.value(0).toInt();

    //        //加班
    //        query.exec(tr("select count(*) from jiabanmsg where staffid='%1' and jbStartTime like '%%2%' and dealResult='同意'")
    //            .arg(name).arg(time));
    //        query.next();
    //        int jbDay = query.value(0).toInt();

    //        //忘打卡
    //        query.exec(tr("select count(*) from wangdakamsg where staffid='%1' and wdkDay like '%%2%' and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意'")
    //            .arg(name).arg(time));
    //        query.next();
    //        int wdkDay = query.value(0).toInt();

    //        int qjNum = 0, hxNum = 0, jbNum = 0, wdkNum = 0;
    //        QString staffName = NULL, staffid = NULL;

    //        if (qjDay == 0 && jbDay == 0 && wdkDay == 0)
    //        {
    //            QString showStr = time + "月份目前考勤如下：\n" + "工号：" + userID + "\n" + "姓名：" + userName + "\n" + "密码：" + password + "\n" + "请假：" + QString::number(qjNum) + "天\n"
    //                + "换休：" + QString::number(hxNum) + "小时\n" + "加班：" + QString::number(jbNum) + "小时\n" + "忘打卡：" + QString::number(wdkNum) + "次\n";
    //            qDebug() << "showStr = " << showStr;
    //            Qrcode * qrcode = new Qrcode(showStr);
    //            qrcode->show();
    //            return;
    //        }
    //        else { //有考勤记录


    //            if (qjDay) //qingjia
    //            {


    //                query.exec(tr("select staffid,name,qjType,qjday from qingjiamsg where staffid='%1' and qjStartTime like '%%2%'")
    //                    .arg(name).arg(time));
    //                for (int i = 0; i < query.size(); i++)
    //                {
    //                    query.next();
    //                    if (query.value(2).toString() == "换休")
    //                    {
    //                        hxNum += query.value(3).toInt();
    //                    }
    //                    else {
    //                        qjNum += query.value(3).toInt();
    //                    }

    //                }
    //                staffName = query.value(1).toString();
    //                staffid = query.value(0).toString();
    //            }
    //            if (jbDay)
    //            {

    //                query.exec(tr("select staffid,name,jbTimeArea,jbStartTime,jbEndTime from jiabanmsg where staffid='%1' and jbStartTime like '%%2%'  and dealResult='同意'")
    //                    .arg(name).arg(time));
    //                for (int i = 0; i < query.size(); i++)
    //                {
    //                    query.next();
    //                    if (query.value(2).toString() == "工作日加班")
    //                    {
    //                        //加班日期为同一天
    //                        if (query.value(3).toString().mid(0, 10) == query.value(4).toString().mid(0, 10))
    //                        {
    //                            QString qValue4 = query.value(4).toString();
    //                            int hours = qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt() - 18;

    //                            if (qValue4.mid(qValue4.indexOf(":") + 1, 2).toInt() >= 30)
    //                            {
    //                                hours += 1;
    //                            }
    //                            jbNum += hours;
    //                        }
    //                        else
    //                        {
    //                            jbNum += 6;
    //                            QString qValue4 = query.value(4).toString();

    //                            jbNum += qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt();
    //                            if (qValue4.mid(qValue4.indexOf(":") + 1, 2).toInt() >= 30)
    //                            {
    //                                jbNum += 1;
    //                            }
    //                        }
    //                    }
    //                    else {
    //                        QString qValue3 = query.value(3).toString();
    //                        QString qValue4 = query.value(4).toString();
    //                        int day = qValue4.mid(8, 2).toInt() - qValue3.mid(8, 2).toInt();
    //                        if (day == 0)
    //                        {
    //                            jbNum += qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt() - qValue3.mid(qValue3.indexOf("/") + 1, qValue3.indexOf(":") - qValue3.indexOf("/") - 1).toInt();

    //                        }
    //                        else {
    //                            jbNum += (24 - qValue3.mid(qValue3.indexOf("/") + 1, qValue3.indexOf(":") - qValue3.indexOf("/") - 1).toInt() + qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt()
    //                                + 24 * ((qValue4.mid(8, 2).toInt() - qValue3.mid(8, 2).toInt() - 1)));
    //                        }
    //                    }
    //                }
    //                staffName = query.value(1).toString();
    //                staffid = query.value(0).toString();
    //            }
    //            if (wdkDay)
    //            {
    //                wdkNum = wdkDay;

    //                query.exec(tr("select staffid,name from wangdakamsg where staffid='%1' and wdkDay like '%%2%'  and witResult='属实' and dptResult='同意' and viceResult='同意' and clerkResult='同意'")
    //                    .arg(name).arg(time));
    //                query.next();
    //                staffName = query.value(1).toString();
    //                staffid = query.value(0).toString();

    //            }

    //            QString showStr = time + "月份目前考勤如下：\n" + "工号：" + userID + "\n" + "姓名：" + userName + "\n" + "密码：" + password + "\n" + "请假：" + QString::number(qjNum) + "天\n"
    //                + "换休：" + QString::number(hxNum) + "小时\n" + "加班：" + QString::number(jbNum) + "小时\n" + "忘打卡：" + QString::number(wdkNum) + "次\n";
    //            qDebug() << "showStr = " << showStr;
    //            Qrcode * qrcode = new Qrcode(showStr);
    //            qrcode->show();

    //            //***
    //        }
    //    }
    //}

}

void CDlgLoginWindow::mslotOnBtnLoginClicked()
{
    //if (!QSqlDatabase::database().isOpen())
    //{
    //    if (!Widget::openMySql())
    //    {
    //        QMessageBox::warning(this, "警告", tr("请确认本地网络连接或服务器是否开启!\n连接数据库失败:%1").arg(QSqlDatabase::database().lastError().text()), QMessageBox::Ok);
    //        return;
    //    }
    //}
    //qDebug() << "here";
    ////
    //QSqlQuery query;
    //if (query.exec(tr("select staffID from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed())))
    //{
    //    if (query.size() == 0)
    //    {
    //        QMessageBox::warning(this, "警告", "工号错误！", QMessageBox::Ok);
    //        return;
    //    }
    //}
    //qDebug() << "here1";
    //if (query.exec(tr("select staffpassword,name,level,staffid,ip from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed())))
    //{
    //    qDebug() << "here2";
    //    if (query.size())
    //    {
    //        query.next();
    //        if (query.value(0) != ui->passwordEdit->text())
    //        {
    //            QMessageBox::warning(this, "警告", "密码错误！", QMessageBox::Ok);

    //        }
    //        else {
    //            //主窗体显示
    //            //QMessageBox::warning(this,"警告","登录成功！",QMessageBox::Ok);
    //            msUserName = query.value(1).toString();
    //            miUserLevel = query.value(2).toInt();
    //            msStaffID = query.value(3).toString();
    //            msIpAddr = query.value(4).toString();
    //            msPassWord = ui->passwordEdit->text();
    //            //判断是否点击了保存密码和自动登录
    //            QFile file(qApp->applicationDirPath() + "/account.dat");
    //            file.open(QIODevice::WriteOnly | QIODevice::Append);
    //            file.reset();

    //            if (ui->rememberPsd->isChecked())
    //            {
    //                file.write("true\n");

    //            }
    //            else {

    //                file.write("false\n");
    //            }
    //            if (ui->autoLogin->isChecked())
    //            {
    //                file.write("true\n");

    //            }
    //            else {

    //                file.write("false\n");
    //            }
    //            QByteArray id = QString(ui->accountComboBox->currentText().trimmed() + "\n").toLatin1();
    //            QByteArray passw = QString(ui->passwordEdit->text() + "\n").toLatin1();
    //            file.write(id);
    //            file.write(passw);
    //            file.write("v3.2\n");
    //            file.close();
    //            Widget * widget = new Widget;
    //            widget->show();
    //            this->close();
    //        }
    //    }
    //}
}

void CDlgLoginWindow::mslotOnBtnForgetPasswordClicked()
{
    //ChangePassword * changpassword = new ChangePassword(staffId);
    //changpassword->show();
}

void CDlgLoginWindow::mslotOnBtnSettingClicked()
{
    //OASettingForm * setting = new OASettingForm;
    //setting->show();
}
