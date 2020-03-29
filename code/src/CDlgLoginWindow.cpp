//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgLoginWindow.cpp
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CDlgLoginWindow��
// History			:
//******************************************************************************

#include "../include/CDlgLoginWindow.h"
#include "ui_qDlgLoginWindow.h"
#include "KeyBoard.h"
#include <QPainter>
#include <QMovie>
#include <QHBoxLayout>
#include <QCursor>
#include <QDebug>
#include "qrcode.h"
#include "widget.h"
#include <QDateTime>
#include <QFile>
#include <QDataStream>
#include "changepassword.h"
#include <QThread>
#include "oasettingform.h"

QString LoginWindow::userName = NULL;
int LoginWindow::userLevel = 0;
QString LoginWindow::staffID = NULL;
QString LoginWindow::myIP = NULL;
QString LoginWindow::version = NULL;
QString LoginWindow::myPassWord = NULL;

LoginWindow::LoginWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    initWindow();
    initMyTitle();
    this->loadStyleSheet(":/Resources/LoginWindow/LoginWindow.css");
    this->setWindowTitle("��¼����");
    Widget::initOASetting();
    ui->rememberPsd->setChecked(true);
    if (!QFile::exists("C:/Users/Administrator/Desktop/����OA.lnk"))
    {
        QFile::copy(qApp->QCoreApplication::applicationDirPath() + "/����OA.lnk", "C:/Users/Administrator/Desktop/����OA.lnk");
    }
    ui->autoLogin->setChecked(true);
    qDebug() << "exiet:" << QFile::exists("account.dat");
    if (QFile::exists(qApp->applicationDirPath() + "/account.dat"))
    {
        QFile file(qApp->applicationDirPath() + "/account.dat");
        file.open(QIODevice::ReadOnly);

        QByteArray rememberPswFlag = NULL;
        QByteArray autoLoginFlag = NULL;
        QByteArray passWord = NULL;
        rememberPswFlag = file.readLine();
        autoLoginFlag = file.readLine();
        staffId = file.readLine();
        passWord = file.readLine();

        version = file.readLine();
        rememberPswFlag.replace("\n", "");
        autoLoginFlag.replace("\n", "");
        staffId.replace("\n", "");
        passWord.replace("\n", "");
        version.replace("\n", "");
        version = "v3.2";
        qDebug() << "version=" << version;
        qDebug() << "all param=" << QString(rememberPswFlag) << QString(staffId) << QString(passWord);
        ui->accountComboBox->setCurrentText(staffId);
        if (rememberPswFlag == "true")
        {
            ui->rememberPsd->setChecked(true);
            ui->passwordEdit->setText(passWord);

        }
        else
        {
            ui->rememberPsd->setChecked(false);
        }
        //����������Զ���¼
        if (autoLoginFlag == "true")
        {
            qDebug() << "2222";
            if (!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            qDebug() << "2223";
            QSqlQuery query;

            qDebug() << "sql=" << tr("select name,ip,level,staffPassword from staffmsg where staffid = '%1'").arg(QString(staffId));

            if (query.exec(tr("select name,ip,level,staffPassword from staffmsg where staffid = '%1'").arg(QString(staffId))))
            {
                qDebug() << "2224";
                if (query.size() == 1)
                {
                    qDebug() << "2225";
                    query.next();
                    if (passWord == query.value(3).toString())
                    {
                        userName = query.value(0).toString();
                        myIP = query.value(1).toString();
                        userLevel = query.value(2).toInt();
                        staffID = QString(staffId);
                        myPassWord = passWord;
                        qDebug() << "2226";
                        Widget * widget = new Widget;
                        qDebug() << "2227";
                        connect(widget, SIGNAL(emitCloseLogWidgetSig()), this, SLOT(getCloseThisSlot()));
                        widget->show();
                        qDebug() << "2228";
                    }

                }
            }
        }
    }

}

//�յ��رմ��ڲ�
void LoginWindow::getCloseThisSlot()
{
    qDebug() << "get close signal;";
    this->close();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

//������������ʵ��û�б߿�Ĵ�������ƶ�����
void LoginWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void LoginWindow::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void LoginWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void LoginWindow::initMyTitle()
{
    // ��Ϊ�����пؼ�����ˣ�����Ҫע��ؼ�raise()�����ĵ���˳��;
    m_titleBar->move(0, 0);
    m_titleBar->raise();
    m_titleBar->setBackgroundColor(0, 0, 0, true);
    m_titleBar->setButtonType(MIN_BUTTON);
    m_titleBar->setTitleWidth(this->width());

    //ui->pButtonArrow->raise();
}

void LoginWindow::initWindow()
{
    //����GIGͼ;
    QLabel* pBack = new QLabel(this);
    QMovie *movie = new QMovie();
    movie->setFileName(":/Resources/LoginWindow/back.gif");
    //movie->start();
   // movie->stop();
    pBack->setMovie(movie);
    movie->start();
    //pBack->move(0, 0);

    //��ע��;
    ui->accountComboBox->setEditable(true);
    QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
    lineEdit->setPlaceholderText(QStringLiteral("����(�����ִ�Сд)"));

    ui->passwordEdit->setPlaceholderText(QStringLiteral("����"));

    // ������е�С���̰�ť;

    m_keyboardButton = new QPushButton();
    m_keyboardButton->setObjectName("pButtonKeyboard");
    m_keyboardButton->setFixedSize(QSize(16, 16));
    m_keyboardButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(m_keyboardButton, SIGNAL(clicked()), this, SLOT(showMinKeyBoardSlot()));
    QHBoxLayout* passwordEditLayout = new QHBoxLayout();
    passwordEditLayout->addStretch();
    passwordEditLayout->addWidget(m_keyboardButton);
    passwordEditLayout->setSpacing(0);
    passwordEditLayout->setContentsMargins(0, 0, 8, 0);

    ui->passwordEdit->setLayout(passwordEditLayout);
    ui->passwordEdit->setTextMargins(0, 0, m_keyboardButton->width() + 12, 0);

    //ui->userHead->setPixmap(QPixmap(":/Resources/LoginWindow/HeadImage.png"));


}

void LoginWindow::showMinKeyBoardSlot()
{
    qDebug() << "intokeybutton";
    KeyBoard * keyBoardDlg = new KeyBoard;
    keyBoardDlg->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    connect(keyBoardDlg, SIGNAL(setvalue(QString)), this, SLOT(displayInputContent(QString)));
    keyBoardDlg->move(this->pos().x() - 40, this->y() + this->frameGeometry().height() - 50);
    keyBoardDlg->show();
}

void LoginWindow::displayInputContent(QString text)
{
    ui->passwordEdit->setText(text);
}

void LoginWindow::on_pButtongFlicker_clicked()
{
    if (ui->accountComboBox->currentText().trimmed().isEmpty() || ui->passwordEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "OA��ʾ", "����д���ź����룡  ", QMessageBox::Ok);
        return;
    }
    if (!QSqlDatabase::database().isValid())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    query.exec(tr("select count(staffID) from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed()));
    query.next();
    if (query.value(0).toInt() == 0)
    {
        QMessageBox::warning(this, "OA��ʾ", "���Ŵ���  ", QMessageBox::Ok);
    }
    else {
        query.exec(tr("select staffpassword,name,level,staffid,ip from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed()));
        query.next();
        QString password = query.value(0).toString();
        QString userName = query.value(1).toString();
        QString userID = query.value(3).toString();
        if (query.value(0).toString() != ui->passwordEdit->text())
        {
            QMessageBox::warning(this, "����", "�������  ", QMessageBox::Ok);
        }
        else {
            //��������ʾ
            //QMessageBox::warning(this,"����","��¼�ɹ���",QMessageBox::Ok);
            //��ʾ��Ա�����ڻ���
            //���
            QString name = ui->accountComboBox->currentText().trimmed();
            QString time = QDateTime::currentDateTime().toString("yyyy-MM");
            query.exec(tr("select count(*) from qingjiamsg where staffid='%1' and qjStartTime like '%%2%' and (manager = '��' or (manager != '��' and managerResult='ͬ��')) and dptResult='ͬ��' and viceResult='ͬ��'")
                .arg(name).arg(time));
            query.next();
            int qjDay = query.value(0).toInt();

            //�Ӱ�
            query.exec(tr("select count(*) from jiabanmsg where staffid='%1' and jbStartTime like '%%2%' and dealResult='ͬ��'")
                .arg(name).arg(time));
            query.next();
            int jbDay = query.value(0).toInt();

            //����
            query.exec(tr("select count(*) from wangdakamsg where staffid='%1' and wdkDay like '%%2%' and witResult='��ʵ' and dptResult='ͬ��' and viceResult='ͬ��' and clerkResult='ͬ��'")
                .arg(name).arg(time));
            query.next();
            int wdkDay = query.value(0).toInt();

            int qjNum = 0, hxNum = 0, jbNum = 0, wdkNum = 0;
            QString staffName = NULL, staffid = NULL;

            if (qjDay == 0 && jbDay == 0 && wdkDay == 0)
            {
                QString showStr = time + "�·�Ŀǰ�������£�\n" + "���ţ�" + userID + "\n" + "������" + userName + "\n" + "���룺" + password + "\n" + "��٣�" + QString::number(qjNum) + "��\n"
                    + "���ݣ�" + QString::number(hxNum) + "Сʱ\n" + "�Ӱࣺ" + QString::number(jbNum) + "Сʱ\n" + "���򿨣�" + QString::number(wdkNum) + "��\n";
                qDebug() << "showStr = " << showStr;
                Qrcode * qrcode = new Qrcode(showStr);
                qrcode->show();
                return;
            }
            else { //�п��ڼ�¼


                if (qjDay) //qingjia
                {


                    query.exec(tr("select staffid,name,qjType,qjday from qingjiamsg where staffid='%1' and qjStartTime like '%%2%'")
                        .arg(name).arg(time));
                    for (int i = 0; i < query.size(); i++)
                    {
                        query.next();
                        if (query.value(2).toString() == "����")
                        {
                            hxNum += query.value(3).toInt();
                        }
                        else {
                            qjNum += query.value(3).toInt();
                        }

                    }
                    staffName = query.value(1).toString();
                    staffid = query.value(0).toString();
                }
                if (jbDay)
                {

                    query.exec(tr("select staffid,name,jbTimeArea,jbStartTime,jbEndTime from jiabanmsg where staffid='%1' and jbStartTime like '%%2%'  and dealResult='ͬ��'")
                        .arg(name).arg(time));
                    for (int i = 0; i < query.size(); i++)
                    {
                        query.next();
                        if (query.value(2).toString() == "�����ռӰ�")
                        {
                            //�Ӱ�����Ϊͬһ��
                            if (query.value(3).toString().mid(0, 10) == query.value(4).toString().mid(0, 10))
                            {
                                QString qValue4 = query.value(4).toString();
                                int hours = qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt() - 18;

                                if (qValue4.mid(qValue4.indexOf(":") + 1, 2).toInt() >= 30)
                                {
                                    hours += 1;
                                }
                                jbNum += hours;
                            }
                            else
                            {
                                jbNum += 6;
                                QString qValue4 = query.value(4).toString();

                                jbNum += qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt();
                                if (qValue4.mid(qValue4.indexOf(":") + 1, 2).toInt() >= 30)
                                {
                                    jbNum += 1;
                                }
                            }
                        }
                        else {
                            QString qValue3 = query.value(3).toString();
                            QString qValue4 = query.value(4).toString();
                            int day = qValue4.mid(8, 2).toInt() - qValue3.mid(8, 2).toInt();
                            if (day == 0)
                            {
                                jbNum += qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt() - qValue3.mid(qValue3.indexOf("/") + 1, qValue3.indexOf(":") - qValue3.indexOf("/") - 1).toInt();

                            }
                            else {
                                jbNum += (24 - qValue3.mid(qValue3.indexOf("/") + 1, qValue3.indexOf(":") - qValue3.indexOf("/") - 1).toInt() + qValue4.mid(qValue4.indexOf("/") + 1, qValue4.indexOf(":") - qValue4.indexOf("/") - 1).toInt()
                                    + 24 * ((qValue4.mid(8, 2).toInt() - qValue3.mid(8, 2).toInt() - 1)));
                            }
                        }
                    }
                    staffName = query.value(1).toString();
                    staffid = query.value(0).toString();
                }
                if (wdkDay)
                {
                    wdkNum = wdkDay;

                    query.exec(tr("select staffid,name from wangdakamsg where staffid='%1' and wdkDay like '%%2%'  and witResult='��ʵ' and dptResult='ͬ��' and viceResult='ͬ��' and clerkResult='ͬ��'")
                        .arg(name).arg(time));
                    query.next();
                    staffName = query.value(1).toString();
                    staffid = query.value(0).toString();

                }

                QString showStr = time + "�·�Ŀǰ�������£�\n" + "���ţ�" + userID + "\n" + "������" + userName + "\n" + "���룺" + password + "\n" + "��٣�" + QString::number(qjNum) + "��\n"
                    + "���ݣ�" + QString::number(hxNum) + "Сʱ\n" + "�Ӱࣺ" + QString::number(jbNum) + "Сʱ\n" + "���򿨣�" + QString::number(wdkNum) + "��\n";
                qDebug() << "showStr = " << showStr;
                Qrcode * qrcode = new Qrcode(showStr);
                qrcode->show();

                //***
            }
        }
    }

}

void LoginWindow::on_loginButton_clicked()
{
    if (!QSqlDatabase::database().isOpen())
    {
        if (!Widget::openMySql())
        {
            QMessageBox::warning(this, "����", tr("��ȷ�ϱ����������ӻ�������Ƿ���!\n�������ݿ�ʧ��:%1").arg(QSqlDatabase::database().lastError().text()), QMessageBox::Ok);
            return;
        }
    }
    qDebug() << "here";
    //
    QSqlQuery query;
    if (query.exec(tr("select staffID from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed())))
    {
        if (query.size() == 0)
        {
            QMessageBox::warning(this, "����", "���Ŵ���", QMessageBox::Ok);
            return;
        }
    }
    qDebug() << "here1";
    if (query.exec(tr("select staffpassword,name,level,staffid,ip from staffmsg where staffid = '%1'").arg(ui->accountComboBox->currentText().trimmed())))
    {
        qDebug() << "here2";
        if (query.size())
        {
            query.next();
            if (query.value(0) != ui->passwordEdit->text())
            {
                QMessageBox::warning(this, "����", "�������", QMessageBox::Ok);

            }
            else {
                //��������ʾ
                //QMessageBox::warning(this,"����","��¼�ɹ���",QMessageBox::Ok);
                userName = query.value(1).toString();
                userLevel = query.value(2).toInt();
                staffID = query.value(3).toString();
                myIP = query.value(4).toString();
                myPassWord = ui->passwordEdit->text();
                //�ж��Ƿ����˱���������Զ���¼
                QFile file(qApp->applicationDirPath() + "/account.dat");
                file.open(QIODevice::WriteOnly | QIODevice::Append);
                file.reset();

                if (ui->rememberPsd->isChecked())
                {
                    file.write("true\n");

                }
                else {

                    file.write("false\n");
                }
                if (ui->autoLogin->isChecked())
                {
                    file.write("true\n");

                }
                else {

                    file.write("false\n");
                }
                QByteArray id = QString(ui->accountComboBox->currentText().trimmed() + "\n").toLatin1();
                QByteArray passw = QString(ui->passwordEdit->text() + "\n").toLatin1();
                file.write(id);
                file.write(passw);
                file.write("v3.2\n");
                file.close();
                Widget * widget = new Widget;
                widget->show();
                this->close();
            }
        }
    }
}

void LoginWindow::on_pButtonForgetPassword_clicked()
{
    ChangePassword * changpassword = new ChangePassword(staffId);
    changpassword->show();
}

void LoginWindow::on_pushButton_setting_clicked()
{
    OASettingForm * setting = new OASettingForm;
    setting->show();
}
