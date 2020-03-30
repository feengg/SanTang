#include "CDlgWidget.h"
#include "ui_qDlgWidget.h"

#include <QSettings>
#include <windows.h>

#include <QProcess>

#include "CDlgLoginWindow.h"
#include <QSettings>


using namespace  std;

QString Widget::serverIP = "192.168.1.44";
int Widget::serverPort = 4513;
//设置参数
QString Widget::sqlIP = "192.168.1.44";
int Widget::sqlPort = 3306;
QString Widget::sqlUserName = "root";
QString Widget::sqlPassword = "123456";
QString Widget::sqlBaseName = "mySql5.6";

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无边框
    this->setWindowTitle("正博OA系统");
    QDesktopWidget * desktop = QApplication::desktop();
    maxWidth = desktop->screenGeometry().width()*57/100;
    maxHeight = desktop->screenGeometry().height()*78/100;
    qDebug() << "width=" << maxWidth << ";" << maxHeight;
    this->resize(1094,842);
    //设置背景图片
    this->autoFillBackground();
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/mainboard.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    //
    //设置title
//    QLabel * labelTitle = new QLabel(this);
//    labelTitle->setText("正博OA系统");
//    labelTitle->move(45,7);
//    labelTitle->show();
    //设置右上角三个按钮（最小化，最大化，关闭）
//    minButton * minBtn = new minButton(this);
//    minBtn->move(maxWidth-50,1);
//    minBtn->resize(18,18);
//    minBtn->show();
//    maxButton * maxBtn = new maxButton(this);
//    maxBtn->move(maxWidth-40,0);
//    maxBtn->resize(20,20);
//    maxBtn->show();
//    closeButton * closeBtn = new closeButton(this);
//    closeBtn->move(maxWidth-25,1);
//    closeBtn->resize(18,18);
//    closeBtn->show();
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(on_minBtn_clicked()));
    connect(ui->pushButton_max,SIGNAL(clicked()),this,SLOT(on_maxBtn_clicked()));
    connect(ui->pushButton_close,SIGNAL(clicked()),this,SLOT(on_closeBtn_clicked()));
    //添加工具栏
    //1
//    QToolButton * toolButton_myStream = new QToolButton(this);
//    toolButton_myStream->move(60,30);
//    toolButton_myStream->resize(51,41);
//    toolButton_myStream->setStyleSheet("border-image: url(:/images/myStream.png);");
//    toolButton_myStream->setCursor(Qt::PointingHandCursor);
//    toolButton_myStream->show();
    //2
    //QToolButton * toolButton_newStream = new QToolButton(this);
    ui->toolButton_newStream->resize(30,34);
    //ui->toolButton_newStream->move(155,32);
    //ui->toolButton_newStream->setStyleSheet("border-image: url(:/images/新增电子流.png);");
    ui->toolButton_newStream->setCursor(Qt::PointingHandCursor);
    ui->toolButton_newStream->show();
    //左1 加班
    //toolBtn_jb = new QToolButton(this);
    ui->toolBtn_jb->resize(170,35);
    //toolBtn_jb->move(13,150);
    //toolBtn_jb->setStyleSheet("border-image: url(:/images/加班1.jpg);");
    ui->toolBtn_jb->setCursor(Qt::PointingHandCursor);
    //ui->toolBtn_jb->show();
    //左2 请假
    //toolBtn_qj = new QToolButton(this);
    ui->toolBtn_qj->resize(170,35);
    //toolBtn_qj->move(13,208);
    //toolBtn_qj->setStyleSheet("border-image: url(:/images/请假1.jpg);");
    ui->toolBtn_qj->setCursor(Qt::PointingHandCursor);
    //toolBtn_qj->show();
    //左3 忘打卡
    //toolBtn_wdk = new QToolButton(this);
    ui->toolBtn_wdk->resize(170,35);
    //toolBtn_wdk->move(13,266);
    //toolBtn_wdk->setStyleSheet("border-image: url(:/images/忘打卡1.jpg);");
    ui->toolBtn_wdk->setCursor(Qt::PointingHandCursor);
    //toolBtn_wdk->show();
    //左4 采购
    //toolBtn_cg = new QToolButton(this);
    ui->toolBtn_cg->resize(170,35);
    //toolBtn_cg->move(13,324);
    //toolBtn_cg->setStyleSheet("border-image: url(:/images/采购1.png);");
    ui->toolBtn_cg->setCursor(Qt::PointingHandCursor);
    //toolBtn_cg->show();


    //右1，待处理
    //toolBtn_dcl = new QToolButton(this);
    ui->toolBtn_dcl->resize(65,75);
    //toolBtn_dcl->move(950,140);
    //toolBtn_dcl->setStyleSheet("border-image: url(:/images/待处理.jpg);");
    ui->toolBtn_dcl->setCursor(Qt::PointingHandCursor);
    //toolBtn_dcl->show();
    //右2
    //toolBtn_kqhz = new QToolButton(this);
    ui->toolBtn_kqhz->resize(65,75);
    //toolBtn_kqhz->move(950,225);
    //toolBtn_kqhz->setStyleSheet("border-image: url(:/images/考勤汇总.png);");
    ui->toolBtn_kqhz->setCursor(Qt::PointingHandCursor);
    //toolBtn_kqhz->show();
    //右3
    //toolBtn_cgjh = new QToolButton(this);
    ui->toolBtn_cgjh->resize(65,75);
    //toolBtn_cgjh->move(950,310);
    //toolBtn_cgjh->setStyleSheet("border-image: url(:/images/BOM.png);");
    ui->toolBtn_cgjh->setCursor(Qt::PointingHandCursor);
    //toolBtn_cgjh->show();
    //右4
    //toolBtn_spkc = new QToolButton(this);
    ui->toolBtn_spkc->resize(65,75);
    //toolBtn_spkc->move(950,395);
    //toolBtn_spkc->setStyleSheet("border-image: url(:/images/商品库存.png);");
    ui->toolBtn_spkc->setCursor(Qt::PointingHandCursor);
    //toolBtn_spkc->show();
    //右5
    //toolBtn_ygsz = new QToolButton(this);
    ui->toolBtn_ygsz->resize(65,75);
    //toolBtn_ygsz->move(950,480);
    //toolBtn_ygsz->setStyleSheet("border-image: url(:/images/员工设置.png);");
    ui->toolBtn_ygsz->setCursor(Qt::PointingHandCursor);
    //toolBtn_ygsz->show();
    //右6
    //toolBtn_tybh = new QToolButton(this);
    ui->toolBtn_tybh->resize(65,75);
    //toolBtn_tybh->move(950,565);
    //toolBtn_tybh->setStyleSheet("border-image: url(:/images/图样编号.png);");
    ui->toolBtn_tybh->setCursor(Qt::PointingHandCursor);
    //toolBtn_tybh->show();

    connect(ui->toolButton_newStream,SIGNAL(clicked()),this,SLOT(toolButton_newStream_clicked()));
    connect(ui->toolBtn_jb,SIGNAL(clicked()),this,SLOT(on_toolBtn_jb_clicked()));
    connect(ui->toolBtn_qj,SIGNAL(clicked()),this,SLOT(on_toolBtn_qj_clicked()));
    connect(ui->toolBtn_wdk,SIGNAL(clicked()),this,SLOT(on_toolBtn_wdk_clicked()));
    connect(ui->toolBtn_cg,SIGNAL(clicked()),this,SLOT(on_toolBtn_cg_clicked()));


    connect(ui->toolBtn_dcl,SIGNAL(clicked()),this,SLOT(on_toolBtn_dcl_clicked()));
    connect(ui->toolBtn_kqhz,SIGNAL(clicked()),this,SLOT(toolBtn_kqhz_clicked()));
    connect(ui->toolBtn_cgjh,SIGNAL(clicked()),this,SLOT(toolBtn_cgjh_clicked()));
    connect(ui->toolBtn_spkc,SIGNAL(clicked()),this,SLOT(toolBtn_spkc_clicked()));
    connect(ui->toolBtn_ygsz,SIGNAL(clicked()),this,SLOT(toolBtn_ygsz_clicked()));
    connect(ui->toolBtn_tybh,SIGNAL(clicked()),this,SLOT(toolBtn_tybh_clicked()));




    //初始化显示tabelWidget
    showStreamListSlot("加班");
    //初始化托盘对象
    myTray = 0;
    myTray->deleteLater();
    //udp绑定自己IP
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress(LoginWindow::myIP),4512);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(recvTipUdpMsgSlot()));
    //tabelWidget点击信号
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(clickedToShowSlot(int,int)));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑

    //判断是否有待处理的电子流，并通知
    on_toolBtn_dcl_clicked();
    int rownum = ui->tableWidget->rowCount();
    qDebug() << "rownum=" << rownum;
    for(int i = 0; i < rownum ;i++)
    {
        if(ui->tableWidget->item(i,8))
        {
            if(ui->tableWidget->item(i,8)->text() == "点击处理")
            {
                showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("  您有新的电子流待处理!");
                connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
                tipDialog->show();
                break;
            }
        }

    }
    qDebug() << "here555";
    //验证ip地址
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    //获取本机本地ip地址

    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    QString localIP = NULL;
    qDebug() << "here556";
    foreach(QHostAddress address,info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {

            qDebug() << "address=" << address.toString();
            if(address.toString().mid(0,10) == "192.168.1.")
            {
                localIP = address.toString();
                break;
            }
        }
    }
    //如果ip不一致，则就修改数据库ip地址
    if(localIP != LoginWindow::myIP)
    {
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("update staffmsg set ip = '%1' where staffid = '%2'").arg(localIP).arg(LoginWindow::staffID)))
        {
           QSqlDatabase::database().commit();
        }else
        {
            QSqlDatabase::database().rollback();
        }
    }
    //设置定时器关闭logWindow
    closeTimer = new QTimer;
    closeTimer->setInterval(40);
    connect(closeTimer,SIGNAL(timeout()),this,SLOT(emitCloseSigToLogW()));
    closeTimer->start();

    //开机自启动
    /*
    HKEY hKey;
    LPCTSTR lpRun = (wchar_t *)QString("Software\\Microsoft\\Windows\\CurrentVersion\\Run").utf16();
    long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,lpRun,0,KEY_WRITE,&hKey);
    if(lRet == ERROR_SUCCESS)
    {
        qDebug() << "sucess into ";
        DWORD dwRet = QApplication::applicationFilePath().length()*2;
        //lRet = RegSetValueEx(hKey,(WCHAR*)QString("wsb").utf16(),0,REG_SZ,(BYTE*)QApplication::applicationFilePath().utf16(),dwRet);
        lRet = RegSetValueEx(hKey,(WCHAR*)QString("test").utf16(),0,REG_SZ,(BYTE*)"",dwRet);
        if(lRet == ERROR_SUCCESS)
        {
            qDebug() << "sucess";
        }

        RegCloseKey(hKey);
    }
    */
    //判断是否自启动
    qDebug() << "here555";
    startSelfAction = new QAction("开机自启动",this);
    if(QFile::exists(qApp->applicationDirPath() + "/autoRun.dat"))
    {
        QFile file(qApp->applicationDirPath() + "/autoRun.dat");
        file.open(QIODevice::ReadOnly);
        QByteArray autoRunFlag = NULL;
        autoRunFlag = file.readLine();
        autoRunFlag.replace("\n","");
        qDebug() << "autoFlag = "  << autoRunFlag;
        if(autoRunFlag == "true")
        {
            qDebug() << "enter here";
            startSelfAction->setIcon(QIcon(":/images/自启动.png"));
            QString appName = QApplication::applicationName();

            QString appPath = QApplication::applicationFilePath();

            appPath = appPath.replace("/","\\");
            QSettings * reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
            QString val = reg->value(appName).toString();
            qDebug() << val;
            if(val != appPath)
            {
                qDebug() << "1";
                reg->setValue(appName,appPath);
                //startSelfAction->setIcon(QIcon(":/images/自启动.png"));
                QFile file(qApp->applicationDirPath() + "/autoRun.dat");
                file.open(QIODevice::WriteOnly | QIODevice::Append);
                file.reset();
                file.write("true\n");
                file.close();
            }
        }
    }
    else
    {
        QString appName = QApplication::applicationName();

        QString appPath = QApplication::applicationFilePath();

        appPath = appPath.replace("/","\\");
        QSettings * reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
        QString val = reg->value(appName).toString();
        qDebug() << val;
        if(val != appPath)
        {
            qDebug() << "1";
            reg->setValue(appName,appPath);
            startSelfAction->setIcon(QIcon(":/images/自启动.png"));
            QFile file(qApp->applicationDirPath() + "/autoRun.dat");
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            file.reset();
            file.write("true\n");
            file.close();
        }
    }
    //初始退出自启动按钮
    if(QFile::exists(qApp->applicationDirPath() + "/account.dat"))
    {
        QFile file(qApp->applicationDirPath() + "/account.dat");
        file.open(QIODevice::ReadOnly);

        QByteArray rememberPswFlag = NULL;
        QByteArray autoLoginFlag = NULL;

        rememberPswFlag = file.readLine();
        autoLoginFlag = file.readLine();
        if(autoLoginFlag == "true\n")
        {
            ui->pushButton_quitAutoRun->show();
        }else{
            ui->pushButton_quitAutoRun->hide();
        }
    }
    //
    ui->label_userName->setText(LoginWindow::userName);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //
    if(!myTray)
    {

        myTray = new QSystemTrayIcon(this);
        QIcon icon = QIcon(":/images/OA_Logo.ico");
        myTray->setIcon(icon);
        myTray->setToolTip("正博OA");
        myTray->show();
        connect(myTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSystemTrayIcon(QSystemTrayIcon::ActivationReason)));
        //建立托盘操作的菜单
        showMainAction = new QAction("显示主界面",this);
        exitAppAction = new QAction("退出",this);
        autoUpdateAction = new QAction("一键自动更新",this);
        aboutOAAction = new QAction("关于正博OA",this);



        connect(showMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));
        connect(exitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));
        connect(startSelfAction,SIGNAL(triggered()),this,SLOT(on_startSelfAction()));
        connect(autoUpdateAction,SIGNAL(triggered()),this,SLOT(on_autoUpdateAction()));
        connect(aboutOAAction,SIGNAL(triggered()),this,SLOT(on_aboutOAAction()));

        myMenu = new QMenu(this);
        myMenu->addAction(showMainAction);
        myMenu->addSeparator();
        myMenu->addAction(startSelfAction);
        myMenu->addSeparator();
        myMenu->addAction(autoUpdateAction);
        myMenu->addSeparator();
        myMenu->addAction(aboutOAAction);
        myMenu->addSeparator();
        myMenu->addAction(exitAppAction);
        myTray->setContextMenu(myMenu);
    }
    //开启服务器监听，以便连接tcpSocket以便上下载文件
    serverListenInit();
    //
    QButtonGroup * btnGroup = new QButtonGroup();
    btnGroup->addButton(ui->toolBtn_jb);
    btnGroup->addButton(ui->toolBtn_qj);
    btnGroup->addButton(ui->toolBtn_wdk);
    btnGroup->addButton(ui->pushButton_chuChai);
    btnGroup->addButton(ui->pushButton_waiChu);
    btnGroup->addButton(ui->toolBtn_cg);
    //检查是否有未读邮件
    checkIfHaveNotReadEmails();
    //version 3.1 content
    //ui->pushButton_haveFun->hide();
    //on_autoUpdateAction(true);
    //qDebug() << "serverIP = " << serverIP;
}

void Widget::emitCloseSigToLogW()
{
    emit emitCloseLogWidgetSig();
    closeTimer->stop();
    delete closeTimer;
    closeTimer = NULL;
    //test
    //QMessageBox::about(this,"it","更新后的程序");
}

Widget::~Widget()
{
    myTray->deleteLater();
    udpSocket->close();
    delete ui;
}

void Widget::on_minBtn_clicked()
{
    on_closeBtn_clicked();
}

void Widget::on_closeBtn_clicked()
{

    this->hide();
    if(!myTray)
    {

        myTray = new QSystemTrayIcon(this);
        QIcon icon = QIcon(":/images/OA_Logo.ico");
        myTray->setIcon(icon);
        myTray->setToolTip("正博OA");
        myTray->show();
        connect(myTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSystemTrayIcon(QSystemTrayIcon::ActivationReason)));
        //建立托盘操作的菜单
        showMainAction = new QAction("显示主界面",this);
        exitAppAction = new QAction("退出",this);
        autoUpdateAction = new QAction("一键自动更新",this);
        aboutOAAction = new QAction("关于正博OA",this);



        connect(showMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));
        connect(exitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));
        connect(startSelfAction,SIGNAL(triggered()),this,SLOT(on_startSelfAction()));
        connect(autoUpdateAction,SIGNAL(triggered()),this,SLOT(on_autoUpdateAction()));
        connect(aboutOAAction,SIGNAL(triggered()),this,SLOT(on_aboutOAAction()));

        myMenu = new QMenu(this);
        myMenu->addAction(showMainAction);
        myMenu->addSeparator();
        myMenu->addAction(startSelfAction);
        myMenu->addSeparator();
        myMenu->addAction(autoUpdateAction);
        myMenu->addSeparator();
        myMenu->addAction(aboutOAAction);
        myMenu->addSeparator();
        myMenu->addAction(exitAppAction);
        myTray->setContextMenu(myMenu);
    }



}

//show aboutOA Dialog slot
void Widget::on_aboutOAAction()
{
    AboutOADialog * aboutOA = new AboutOADialog;
    aboutOA->show();
}

//自动更新
void Widget::on_autoUpdateAction(bool startCheckFlag)
{
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec("select * from zyoaversion"))
    {
        query.next();
        qDebug() << "logver =" << LoginWindow::version  << " " << "sqlver= " << query.value(0).toString() << endl;
        if(query.value(0).toString() == LoginWindow::version)
        {
            if(!startCheckFlag)
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您已是最新版本！");
                dontUpdate->show();
            }

        }else
        {
            QProcess * myProcess = new QProcess(this);
            QString dir;
            dir = qApp->applicationDirPath();

            dir += "/updateLoader.exe";

            myProcess->start(dir);
            if(myProcess->state() != QProcess::NotRunning)
            {
                qDebug() << "打开成功！";
                exit(0); //退出整个oa系统
            }
            else
            {
                QMessageBox::about(this,"OA提示","更新失败，打开下载器失败，请重试！  ");
            }

        }
    }else
    {
        QMessageBox::warning(this,"OA提示",tr("操作失败,连接数据库失败:%1").arg(query.lastError().text()),QMessageBox::Ok);
    }

}


void Widget::on_showMainAction()
{

    this->show();
    showStreamListSlot("加班");
}
void Widget::on_exitAppAction()
{
    myTray->deleteLater();
    exit(0);
}
void Widget::on_activatedSystemTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
        myTray->showMessage("提示","已打开",QSystemTrayIcon::Information,1000);
        this->show();
    default:
        break;
    }
}
void Widget::on_startSelfAction()
{
    //开机自启动
    if(1)
    {
//        HKEY hKey;
//        LPCTSTR lpRun = (wchar_t *)QString("Software\\Microsoft\\Windows\\CurrentVersion\\Run").utf16();
//        long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,lpRun,0,KEY_WRITE,&hKey);
//        if(lRet == ERROR_SUCCESS)
//        {
//            DWORD dwRet = QApplication::applicationFilePath().length()*2;
//            lRet = RegSetValueEx(hKey,(WCHAR*)QString("ZY-OA").utf16(),0,REG_SZ,(BYTE*)QApplication::applicationFilePath().utf16(),dwRet);
//            if(lRet == ERROR_SUCCESS)
//            {
//                startSelfAction->setIcon(QIcon(":/images/自启动.png"));
//                isStartBySelfFlag = false;
//                QFile file("autoRun.dat");
//                file.open(QIODevice::WriteOnly | QIODevice::Append);
//                file.reset();
//                file.write("true\n");
//                file.close();
//                qDebug() << "开启自启动已开启";
//            }else{
//                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("设置失败,关闭杀毒后重试！  ");
//                dontUpdate->show();
//            }

//        }else{
//            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("设置失败,关闭杀毒后重试！  ");
//            dontUpdate->show();
//        }
//        RegCloseKey(hKey);
        QString appName = QApplication::applicationName();

        QString appPath = QApplication::applicationFilePath();

        appPath = appPath.replace("/","\\");
        QSettings * reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
        QString val = reg->value(appName).toString();
        if(val != appPath)
        {
            qDebug() << "1";
            reg->setValue(appName,appPath);
            startSelfAction->setIcon(QIcon(":/images/自启动.png"));
            QFile file(qApp->applicationDirPath() + "/autoRun.dat");
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            file.reset();
            file.write("true\n");
            file.close();
            QString val = reg->value(appName).toString();
            qDebug() << val;
        }
        else
        {
            qDebug() << "2";
            reg->remove(appName);
            startSelfAction->setIcon(QIcon(""));
            QFile file(qApp->applicationDirPath() + "/autoRun.dat");
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            file.reset();
            file.write("false\n");
            file.close();
            QString val = reg->value(appName).toString();
            qDebug() << val;
        }
        reg->deleteLater();
    }
//    else
//    {
//        HKEY hKey;
//        LPCTSTR lpRun = (wchar_t *)QString("Software\\Microsoft\\Windows\\CurrentVersion\\Run").utf16();
//        long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,lpRun,0,KEY_WRITE,&hKey);
//        if(lRet == ERROR_SUCCESS)
//        {
//            DWORD dwRet = QApplication::applicationFilePath().length()*2;
//            lRet = RegSetValueEx(hKey,(WCHAR*)QString("ZY-OA").utf16(),0,REG_SZ,(BYTE*)"",dwRet);
//            if(lRet == ERROR_SUCCESS)
//            {
//                startSelfAction->setIcon(QIcon(""));
//                isStartBySelfFlag = true;
//                QFile file("autoRun.dat");
//                file.open(QIODevice::WriteOnly | QIODevice::Append);
//                file.reset();
//                file.write("false\n");
//                file.close();
//                qDebug() << "开启自启动已关闭";
//            }else{
//                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("设置失败,关闭杀毒后重试！  ");
//                dontUpdate->show();
//            }

//        }else{
//            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("设置失败,关闭杀毒后重试！  ");
//            dontUpdate->show();
//        }
//        RegCloseKey(hKey);
//    }

}



void Widget::on_maxBtn_clicked()
{

    QDesktopWidget * desktop = QApplication::desktop();
    if(this->width() != desktop->screenGeometry().width())
    {
        this->resize(desktop->screenGeometry().width(),desktop->screenGeometry().height());
        this->move(0,0);
        //设置背景图片
        this->autoFillBackground();
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/mainboard.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
        this->setPalette(palette);
    }
    else
    {
        this->resize(1094,842);
        this->move((desktop->screenGeometry().width() - this->width())/2,(desktop->screenGeometry().height() - this->height())/2);
        //设置背景图片
        this->autoFillBackground();
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/mainboard.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
        this->setPalette(palette);
    }
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void Widget::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}


void Widget::on_toolButton_myStream_clicked()
{
    //QMessageBox::about(this,"hell","ok");
}

void Widget::on_toolBtn_jb_clicked()
{
    leftBtn1ClickFlag = true;
    leftBtn2ClickFlag = false;
    leftBtn3ClickFlag = false;
    leftBtn4ClickFlag = false;
    leftBtn5ClickFlag = false;
    showStreamListSlot("加班");
}
//采购按钮槽
void Widget::on_toolBtn_cg_clicked()
{
    leftBtn1ClickFlag = false;
    leftBtn2ClickFlag = false;
    leftBtn3ClickFlag = false;
    leftBtn4ClickFlag = true;
    leftBtn5ClickFlag = false;

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    QStringList header;
    header << "电子流类型" << "提交时间" << "组长" << "部门领导"<<"总经理"<<"查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);
//    ui->tableWidget->setColumnWidth(0,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(1,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(2,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(3,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(4,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(5,ui->tableWidget->width()/6);
    if(!QSqlDatabase::database().isValid())
    {
        openMySql();
    }else
    {
        qDebug() << "level=" << LoginWindow::userLevel;
        if(LoginWindow::userLevel == 4)
        {
            QSqlQuery query;

            if(!query.exec(tr("select count(*) from caigouapmsg where groupResult='同意' and dptResult='同意' and managerResult='同意'")))
            {
                qDebug() << "Sql Error:" << query.lastError().text();
                return;
            }
            query.next();
            int rowNum = query.value(0).toInt();
            ui->tableWidget->setRowCount(rowNum);
            if(rowNum > 0)
            {
                if(!query.exec(tr("select dealTime,groupresult,dptresult,managerresult from caigouapmsg where groupResult='同意' and dptResult='同意' and managerResult='同意' order by dealtime desc")
                           .arg(LoginWindow::staffID)))
                {
                    qDebug() << "Sql Error:" << query.lastError().text();
                    return;
                }
                for(int i = 0; i < rowNum; i++)
                {
                    query.next();

                    QTableWidgetItem * item0 = new QTableWidgetItem("采购申请");
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(3).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem("点击查看");
                    item5->setToolTip("点击查看");
                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item5->setBackgroundColor(QColor(235,235,235));
                    item5->setTextColor(Qt::blue);
                    //manager

                    if(query.value(3).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(3).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(3).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(3).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    //department
                    if(query.value(1).toString() == "待处理")
                    {
                        item2->setTextColor(Qt::blue);
                    }
                    if(query.value(1).toString() == "同意")
                    {
                        item2->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(1).toString() == "驳回")
                    {
                        item2->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(1).toString() == "不同意")
                    {
                        item2->setTextColor(Qt::red);
                    }
                    //总经办
                    if(query.value(2).toString() == "待处理")
                    {
                        item3->setTextColor(Qt::blue);
                    }
                    if(query.value(2).toString() == "同意")
                    {
                        item3->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(2).toString() == "驳回")
                    {
                        item3->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(2).toString() == "不同意")
                    {
                        item3->setTextColor(Qt::red);
                    }

                    ui->tableWidget->setItem(i,0,item0);
                    ui->tableWidget->setItem(i,1,item1);
                    ui->tableWidget->setItem(i,2,item2);
                    ui->tableWidget->setItem(i,3,item3);
                    ui->tableWidget->setItem(i,4,item4);
                    ui->tableWidget->setItem(i,5,item5);
                    /*
                    delete item0;
                    delete item1;
                    delete item2;
                    delete item3;
                    delete item4;
                    delete item5;
                    */
                }
            }
        }else
        {
            QSqlQuery query;

            if(!query.exec(tr("select count(*) from caigouapmsg where staffid = '%1'").arg(LoginWindow::staffID)))
            {
                qDebug() << "Sql Error:" << query.lastError().text();
                return;
            }
            query.next();
            int rowNum = query.value(0).toInt();
            ui->tableWidget->setRowCount(rowNum);
            if(rowNum > 0)
            {
                if(!query.exec(tr("select dealTime,groupresult,dptresult,managerresult from caigouapmsg where staffid = '%1' order by dealtime desc")
                           .arg(LoginWindow::staffID)))
                {
                    qDebug() << "Sql Error:" << query.lastError().text();
                    return;
                }
                for(int i = 0; i < rowNum; i++)
                {
                    query.next();

                    QTableWidgetItem * item0 = new QTableWidgetItem("采购申请");
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(3).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem("点击查看");
                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item5->setBackgroundColor(QColor(235,235,235));
                    item5->setTextColor(Qt::blue);
                    //manager

                    if(query.value(3).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(3).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(3).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(3).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    //department
                    if(query.value(1).toString() == "待处理")
                    {
                        item2->setTextColor(Qt::blue);
                    }
                    if(query.value(1).toString() == "同意")
                    {
                        item2->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(1).toString() == "驳回")
                    {
                        item2->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(1).toString() == "不同意")
                    {
                        item2->setTextColor(Qt::red);
                    }
                    //总经办
                    if(query.value(2).toString() == "待处理")
                    {
                        item3->setTextColor(Qt::blue);
                    }
                    if(query.value(2).toString() == "同意")
                    {
                        item3->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(2).toString() == "驳回")
                    {
                        item3->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(2).toString() == "不同意")
                    {
                        item3->setTextColor(Qt::red);
                    }

                    ui->tableWidget->setItem(i,0,item0);
                    ui->tableWidget->setItem(i,1,item1);
                    ui->tableWidget->setItem(i,2,item2);
                    ui->tableWidget->setItem(i,3,item3);
                    ui->tableWidget->setItem(i,4,item4);
                    ui->tableWidget->setItem(i,5,item5);
                    /*
                    delete item0;
                    delete item1;
                    delete item2;
                    delete item3;
                    delete item4;
                    delete item5;
                    */
                }
            }

        }
    }
}


void Widget::on_toolBtn_qj_clicked()
{
    leftBtn1ClickFlag = false;
    leftBtn2ClickFlag = true;
    leftBtn3ClickFlag = false;
    leftBtn4ClickFlag = false;
    leftBtn5ClickFlag = false;
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);

    QStringList header;
    header << "电子流类型" << "提交时间" << "部门领导" << "总经办"<<"总经理"<<"查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    if(!QSqlDatabase::database().isOpen())
    {
        openMySql();
    }else
    {

        QSqlQuery query;
        if(!query.exec(tr("select count(*) from qingjiamsg where staffid = '%1'").arg(LoginWindow::staffID)))
        {
            qDebug() << "Sql Error:" << query.lastError().text();
            return;
        }
        query.next();
        int rowNum = query.value(0).toInt();
        ui->tableWidget->setRowCount(rowNum);
        if(rowNum > 0)
        {
            if(!query.exec(tr("select dealTime,dptresult,viceresult,manager,managerresult from qingjiamsg where staffid = '%1' order by dealtime desc")
                       .arg(LoginWindow::staffID)))
            {
                qDebug() << "Sql Error:" << query.lastError().text();
                return;
            }
            for(int i = 0; i < rowNum; i++)
            {
                query.next();

                QTableWidgetItem * item0 = new QTableWidgetItem("请假");
                QTableWidgetItem * item1 = new QTableWidgetItem(query.value(0).toString());
                QTableWidgetItem * item2 = new QTableWidgetItem(query.value(1).toString());
                QTableWidgetItem * item3 = new QTableWidgetItem(query.value(2).toString());
                QTableWidgetItem * item4 = new QTableWidgetItem();
                QTableWidgetItem * item5 = new QTableWidgetItem("点击查看");
                item5->setToolTip("点击查看");
                item0->setTextAlignment(Qt::AlignCenter);
                item1->setTextAlignment(Qt::AlignCenter);
                item2->setTextAlignment(Qt::AlignCenter);
                item3->setTextAlignment(Qt::AlignCenter);
                item4->setTextAlignment(Qt::AlignCenter);
                item5->setTextAlignment(Qt::AlignCenter);
                item5->setBackgroundColor(QColor(235,235,235));
                item5->setTextColor(Qt::blue);
                //manager
                if(query.value(3).toString() == "无")
                {
                    item4->setText("无");
                }else
                {
                    item4->setText(query.value(4).toString());
                    if(query.value(4).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(4).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(4).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(4).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                }
                //department
                if(query.value(1).toString() == "待处理")
                {
                    item2->setTextColor(Qt::blue);
                }
                if(query.value(1).toString() == "同意")
                {
                    item2->setTextColor(Qt::darkGreen);
                }
                if(query.value(1).toString() == "驳回")
                {
                    item2->setTextColor(Qt::darkYellow);
                }
                if(query.value(1).toString() == "不同意")
                {
                    item2->setTextColor(Qt::red);
                }
                //总经办
                if(query.value(2).toString() == "待处理")
                {
                    item3->setTextColor(Qt::blue);
                }
                if(query.value(2).toString() == "同意")
                {
                    item3->setTextColor(Qt::darkGreen);
                }
                if(query.value(2).toString() == "驳回")
                {
                    item3->setTextColor(Qt::darkYellow);
                }
                if(query.value(2).toString() == "不同意")
                {
                    item3->setTextColor(Qt::red);
                }

                ui->tableWidget->setItem(i,0,item0);
                ui->tableWidget->setItem(i,1,item1);
                ui->tableWidget->setItem(i,2,item2);
                ui->tableWidget->setItem(i,3,item3);
                ui->tableWidget->setItem(i,4,item4);
                ui->tableWidget->setItem(i,5,item5);
                /*
                delete item0;
                delete item1;
                delete item2;
                delete item3;
                delete item4;
                delete item5;
                */
            }
        }

    }

}

void Widget::on_toolBtn_wdk_clicked()
{
    leftBtn1ClickFlag = false;
    leftBtn2ClickFlag = false;
    leftBtn3ClickFlag = true;
    leftBtn4ClickFlag = false;
    leftBtn5ClickFlag = false;

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(7);
//    ui->tableWidget->setColumnWidth(0,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(1,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(2,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(3,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(4,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(5,ui->tableWidget->width()/6);
//    ui->tableWidget->setColumnWidth(6,ui->tableWidget->width()/6);
    QStringList header;
    header << "电子流类型" << "提交时间" << "证明人" << "部门领导" << "总经办"<<"考勤员"<<"查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    query.exec(tr("select count(*) from wangdakamsg where name = '%1'").arg(LoginWindow::userName));
    query.next();
    int rowNum = query.value(0).toInt();
    ui->tableWidget->setRowCount(rowNum);
    if(rowNum)
    {
        query.exec(tr("select dealtime,witresult,dptresult,viceresult,clerkresult from wangdakamsg where name ='%1' order by dealtime desc").arg(LoginWindow::userName));
        for(int i = 0;i < rowNum;i++)
        {
            query.next();
            QTableWidgetItem * item0 = new QTableWidgetItem("忘打卡");
            QTableWidgetItem * item1 = new QTableWidgetItem(query.value(0).toString());
            QTableWidgetItem * item2 = new QTableWidgetItem(query.value(1).toString());
            QTableWidgetItem * item3 = new QTableWidgetItem(query.value(2).toString());
            QTableWidgetItem * item4 = new QTableWidgetItem(query.value(3).toString());
            QTableWidgetItem * item5 = new QTableWidgetItem(query.value(4).toString());
            QTableWidgetItem * item6 = new QTableWidgetItem("点击查看");
            item6->setToolTip("点击查看");
            item0->setTextAlignment(Qt::AlignCenter);
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);
            item4->setTextAlignment(Qt::AlignCenter);
            item5->setTextAlignment(Qt::AlignCenter);
            item6->setTextAlignment(Qt::AlignCenter);
            item6->setBackgroundColor(QColor(235,235,235));
            item6->setTextColor(Qt::blue);

            //witness
            if(query.value(1).toString() == "待处理")
            {
                item2->setTextColor(Qt::blue);
            }
            if(query.value(1).toString() == "属实")
            {
                item2->setTextColor(Qt::darkGreen);
            }
            if(query.value(1).toString() == "驳回")
            {
                item2->setTextColor(Qt::darkYellow);
            }
            if(query.value(1).toString() == "不属实")
            {
                item2->setTextColor(Qt::red);
            }

            //dptleader
            if(query.value(2).toString() == "待处理")
            {
                item3->setTextColor(Qt::blue);
            }
            if(query.value(2).toString() == "同意")
            {
                item3->setTextColor(Qt::darkGreen);
            }
            if(query.value(2).toString() == "驳回")
            {
                item3->setTextColor(Qt::darkYellow);
            }
            if(query.value(2).toString() == "不同意")
            {
                item3->setTextColor(Qt::red);
            }
            //viceManager
            if(query.value(3).toString() == "待处理")
            {
                item4->setTextColor(Qt::blue);
            }
            if(query.value(3).toString() == "同意")
            {
                item4->setTextColor(Qt::darkGreen);
            }
            if(query.value(3).toString() == "驳回")
            {
                item4->setTextColor(Qt::darkYellow);
            }
            if(query.value(3).toString() == "不同意")
            {
                item4->setTextColor(Qt::red);
            }
            //clerk
            if(query.value(4).toString() == "待处理")
            {
                item5->setTextColor(Qt::blue);
            }
            if(query.value(4).toString() == "同意")
            {
                item5->setTextColor(Qt::darkGreen);
            }
            if(query.value(4).toString() == "驳回")
            {
                item5->setTextColor(Qt::darkYellow);
            }
            if(query.value(4).toString() == "不同意")
            {
                item5->setTextColor(Qt::red);
            }

            ui->tableWidget->setItem(i,0,item0);
            ui->tableWidget->setItem(i,1,item1);
            ui->tableWidget->setItem(i,2,item2);
            ui->tableWidget->setItem(i,3,item3);
            ui->tableWidget->setItem(i,4,item4);
            ui->tableWidget->setItem(i,5,item5);
            ui->tableWidget->setItem(i,6,item6);
        }
    }
}
//点击员工设置
void Widget::toolBtn_ygsz_clicked()
{
    //if(LoginWindow::userLevel <= 2 || LoginWindow::userName == "吴胜兵")
    {
        YGSZ * ygsz = new YGSZ;
        ygsz->show();
    }
//    else
//    {
//        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
//        dontUpdate->show();
//    }

}

void Widget::toolBtn_kqhz_clicked()
{
    /*
    if(LoginWindow::userName == "吴伟")
    {
        QMessageBox::about(this,"OA提示","您没有权限操作！   ");
        return;
    }
    */
    KQHZ * kqhz = new KQHZ();
    kqhz->show();
}

void Widget::toolBtn_cgjh_clicked()
{
    //QMessageBox::about(this,"提示","未开通此功能");
    Bom * bom = new Bom();
    connect(bom,SIGNAL(emitToCGSQToFlushStreamListSig(QString)),this,SLOT(showStreamListSlot(QString)));
    bom->show();
}

void Widget::toolBtn_spkc_clicked()
{
    KCGL * kcgl = new KCGL;
    kcgl->show();

}

void Widget::on_toolBtn_dcl_clicked()
{

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(0);
    QStringList header;
    header << "电子类型" << "申请人" << "提交时间"<<"证明人/组长"<<"部门领导"<<"副总经理"<<"总经理"<<"考勤员"<<"点击查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    int rowNum = 0;
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    if(query.exec("select tabletype as msgtype,name as name,dealtime as dtime,'-' as witname,'-' as witness,dptLeader as dptname,"
                  "dptresult as dptresult,viceManager as viceManager,viceresult as viceresult,manager as manager,managerresult as managerresult,"
                  "'-' as clerkname,'-' as clerkresult from qingjiamsg  "
                  "union select tabletype as msgtype,name as name,dealtime as dtime,'-' as witname,'-' as witness,"
                  "leaderName as dptname,dealresult as dptresult,'-' as viceManager,'-' as viceresult,'-' as manager,"
                 "'-' as managerresult,'-' as clerkname,'-' as clerkresult  from jiabanmsg "
                  "union select tabletype as msgtype,name as name,dealtime as dtime,witname as witname,witresult as witness,"
                  "dptLeader as dptname,dptresult as dptresult,viceManager as viceManager,viceresult as viceresult,'-' as manager,"
                  "'-' as managerresult,clerkname as clerkname,clerkresult as clerkresult from wangdakamsg "
                  "union select tabletype as msgtype,name as name,dealtime as dtime,groupleader as witname,groupresult as witness,"
                  "dptleader as dptname,dptresult as dptresult,'-' as vicemanager,'-' as viceresult,manager as manager,managerresult as managerresult,"
                  "'-' as clerkname,'-' as clerkresult from caigouapmsg  "
                  "union select tabletype as msgtype,name as name,dealtime as dtime, '-' as witname,'-' as witness,"
                  "leader as dptname,leaderResult as dptresult,'-' as vicemanager,'-' as viceresult,manager as manager,managerresult as managerresult,"
                  "clerk as clerkname,clerkresult as clerkresult from chuchai "
                  "union select tabletype as msgtype,name as name,dealtime as dtime, '-' as witname,'-' as witness,"
                  "leader as dptname,leaderResult as dptresult,'-' as vicemanager,'-' as viceresult,'-' as manager,'-' as managerresult,"
                  "clerk as clerkname,clerkresult as clerkresult from waichu "
                  "order by dtime desc;"))
    {
        rowNum = query.size();
        int realRowNum = 0;
        if(rowNum)
        {

            for(int i = 0 ;i < rowNum ; i++)
            {

                query.next();
                if(query.value(0).toString() == "加班" && query.value(5).toString() == LoginWindow::userName)
                {

                    realRowNum++;
                    ui->tableWidget->setRowCount(realRowNum);
                    QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                    QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                    QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                    QTableWidgetItem * item8 = new QTableWidgetItem();
                    if(query.value(6).toString() == "待处理")
                    {
                        item8->setText("点击处理");
                        item8->setTextColor(Qt::red);
                        item8->setBackgroundColor(QColor(235,235,235));

                    }else
                    {
                        item8->setText("已处理");
                        item8->setTextColor(Qt::blue);
                        item8->setBackgroundColor(QColor(235,235,235));

                    }
                    //dpt
                    if(query.value(6).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(6).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(6).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(6).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item6->setTextAlignment(Qt::AlignCenter);
                    item7->setTextAlignment(Qt::AlignCenter);
                    item8->setTextAlignment(Qt::AlignCenter);

                    ui->tableWidget->setItem(realRowNum-1,0,item0);
                    ui->tableWidget->setItem(realRowNum-1,1,item1);
                    ui->tableWidget->setItem(realRowNum-1,2,item2);
                    ui->tableWidget->setItem(realRowNum-1,3,item3);
                    ui->tableWidget->setItem(realRowNum-1,4,item4);
                    ui->tableWidget->setItem(realRowNum-1,5,item5);
                    ui->tableWidget->setItem(realRowNum-1,6,item6);
                    ui->tableWidget->setItem(realRowNum-1,7,item7);
                    ui->tableWidget->setItem(realRowNum-1,8,item8);

                }
                if(query.value(0).toString() == "请假" && query.value(5).toString() == LoginWindow::userName)
                {


                    realRowNum++;
                    ui->tableWidget->setRowCount(realRowNum);
                    QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                    QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                    QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                    QTableWidgetItem * item8 = new QTableWidgetItem();

                    if(query.value(6).toString() == "待处理")
                    {

                        item8->setText("点击处理");
                        item8->setTextColor(Qt::red);
                        item8->setBackgroundColor(QColor(235,235,235));

                    }else
                    {

                        item8->setText("已处理");
                        item8->setTextColor(Qt::blue);
                        item8->setBackgroundColor(QColor(235,235,235));

                    }
                    //dpt
                    if(query.value(6).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(6).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(6).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(6).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    //vice
                    if(query.value(8).toString() == "待处理")
                    {
                        item5->setTextColor(Qt::blue);
                    }
                    if(query.value(8).toString() == "同意")
                    {
                        item5->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(8).toString() == "驳回")
                    {
                        item5->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(8).toString() == "不同意")
                    {
                        item5->setTextColor(Qt::red);
                    }
                    //manager
                    if(query.value(9).toString() != "-")
                    {
                        //manager

                        if(query.value(10).toString() == "待处理")
                        {
                            item6->setTextColor(Qt::blue);
                        }
                        if(query.value(10).toString() == "同意")
                        {
                            item6->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(10).toString() == "驳回")
                        {
                            item6->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(10).toString() == "不同意")
                        {
                            item6->setTextColor(Qt::red);
                        }
                    }else
                    {
                        item6->setText("-");
                    }
                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item6->setTextAlignment(Qt::AlignCenter);
                    item7->setTextAlignment(Qt::AlignCenter);
                    item8->setTextAlignment(Qt::AlignCenter);

                    ui->tableWidget->setItem(realRowNum-1,0,item0);
                    ui->tableWidget->setItem(realRowNum-1,1,item1);
                    ui->tableWidget->setItem(realRowNum-1,2,item2);
                    ui->tableWidget->setItem(realRowNum-1,3,item3);
                    ui->tableWidget->setItem(realRowNum-1,4,item4);
                    ui->tableWidget->setItem(realRowNum-1,5,item5);
                    ui->tableWidget->setItem(realRowNum-1,6,item6);
                    ui->tableWidget->setItem(realRowNum-1,7,item7);
                    ui->tableWidget->setItem(realRowNum-1,8,item8);

                }
                if(query.value(0).toString() == "请假" && query.value(7).toString() == LoginWindow::userName)
                {
                    if(query.value(6).toString() == "同意")
                    {
                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();

                        item4->setTextColor(Qt::darkGreen);
                        if(query.value(8).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setToolTip("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");
                        }

                        //vice
                        if(query.value(8).toString() == "待处理")
                        {
                            item5->setTextColor(Qt::blue);
                        }
                        if(query.value(8).toString() == "同意")
                        {
                            item5->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(8).toString() == "驳回")
                        {
                            item5->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(8).toString() == "不同意")
                        {
                            item5->setTextColor(Qt::red);
                        }
                        if(query.value(9).toString() != "-")
                        {
                            //manager

                            if(query.value(10).toString() == "待处理")
                            {
                                item6->setTextColor(Qt::blue);
                            }
                            if(query.value(10).toString() == "同意")
                            {
                                item6->setTextColor(Qt::darkGreen);
                            }
                            if(query.value(10).toString() == "驳回")
                            {
                                item6->setTextColor(Qt::darkYellow);
                            }
                            if(query.value(10).toString() == "不同意")
                            {
                                item6->setTextColor(Qt::red);
                            }
                        }else
                        {
                            item6->setText("-");
                        }

                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);
                    }

                }
                if(query.value(0).toString() == "请假" && query.value(9).toString() == LoginWindow::userName)
                {
                    if(query.value(6).toString() == "同意" && query.value(8).toString() == "同意")
                    {

                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();

                        item4->setTextColor(Qt::darkGreen);
                        item5->setTextColor(Qt::darkGreen);
                        if(query.value(10).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8->setToolTip("点击查看");
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));

                        }

                        //manager
                        if(query.value(9).toString() != "-")
                        {

                            if(query.value(10).toString() == "待处理")
                            {
                                item6->setTextColor(Qt::blue);
                            }
                            if(query.value(10).toString() == "同意")
                            {
                                item6->setTextColor(Qt::darkGreen);
                            }
                            if(query.value(10).toString() == "驳回")
                            {
                                item6->setTextColor(Qt::darkYellow);
                            }
                            if(query.value(10).toString() == "不同意")
                            {
                                item6->setTextColor(Qt::red);
                            }
                        }else
                        {
                            item6->setText("-");
                        }



                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);
                    }

                }
                //忘打卡
                if(query.value(0).toString() == "忘打卡" && query.value(3).toString() == LoginWindow::userName)
                {

                    realRowNum++;
                    ui->tableWidget->setRowCount(realRowNum);
                    QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                    QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                    QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                    QTableWidgetItem * item8 = new QTableWidgetItem();
                    if(query.value(4).toString() == "待处理")
                    {
                        item8 = new QTableWidgetItem("点击处理");
                        item8->setTextColor(Qt::red);
                        item8->setBackgroundColor(QColor(235,235,235));
                        item8->setToolTip("点击处理");

                    }else
                    {
                        item8 = new QTableWidgetItem("已处理");
                        item8->setTextColor(Qt::blue);
                        item8->setBackgroundColor(QColor(235,235,235));
                        item8->setToolTip("点击查看");

                    }

                    //witness
                    if(query.value(4).toString() == "待处理")
                    {
                        item3->setTextColor(Qt::blue);
                    }
                    if(query.value(4).toString() == "属实")
                    {
                        item3->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(4).toString() == "驳回")
                    {
                        item3->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(4).toString() == "不属实")
                    {
                        item3->setTextColor(Qt::red);
                    }
                    //dpt
                    if(query.value(6).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(6).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(6).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(6).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    //vice
                    if(query.value(8).toString() == "待处理")
                    {
                        item5->setTextColor(Qt::blue);
                    }
                    if(query.value(8).toString() == "同意")
                    {
                        item5->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(8).toString() == "驳回")
                    {
                        item5->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(8).toString() == "不同意")
                    {
                        item5->setTextColor(Qt::red);
                    }
                    //clerk
                    if(query.value(12).toString() == "待处理")
                    {
                        item7->setTextColor(Qt::blue);
                    }
                    if(query.value(12).toString() == "同意")
                    {
                        item7->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(12).toString() == "驳回")
                    {
                        item7->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(12).toString() == "不同意")
                    {
                        item7->setTextColor(Qt::red);
                    }
                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item6->setTextAlignment(Qt::AlignCenter);
                    item7->setTextAlignment(Qt::AlignCenter);
                    item8->setTextAlignment(Qt::AlignCenter);

                    ui->tableWidget->setItem(realRowNum-1,0,item0);
                    ui->tableWidget->setItem(realRowNum-1,1,item1);
                    ui->tableWidget->setItem(realRowNum-1,2,item2);
                    ui->tableWidget->setItem(realRowNum-1,3,item3);
                    ui->tableWidget->setItem(realRowNum-1,4,item4);
                    ui->tableWidget->setItem(realRowNum-1,5,item5);
                    ui->tableWidget->setItem(realRowNum-1,6,item6);
                    ui->tableWidget->setItem(realRowNum-1,7,item7);
                    ui->tableWidget->setItem(realRowNum-1,8,item8);

                }
                //忘打卡
                if(query.value(0).toString() == "忘打卡" && query.value(5).toString() == LoginWindow::userName)
                {
                    if(query.value(4).toString() == "属实")
                    {

                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();
                        item3->setTextColor(Qt::darkGreen);
                        if(query.value(6).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");

                        }

                        //dpt
                        if(query.value(6).toString() == "待处理")
                        {
                            item4->setTextColor(Qt::blue);
                        }
                        if(query.value(6).toString() == "同意")
                        {
                            item4->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(6).toString() == "驳回")
                        {
                            item4->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(6).toString() == "不同意")
                        {
                            item4->setTextColor(Qt::red);
                        }
                        //vice
                        if(query.value(8).toString() == "待处理")
                        {
                            item5->setTextColor(Qt::blue);
                        }
                        if(query.value(8).toString() == "同意")
                        {
                            item5->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(8).toString() == "驳回")
                        {
                            item5->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(8).toString() == "不同意")
                        {
                            item5->setTextColor(Qt::red);
                        }
                        //clerk
                        if(query.value(12).toString() == "待处理")
                        {
                            item7->setTextColor(Qt::blue);
                        }
                        if(query.value(12).toString() == "同意")
                        {
                            item7->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(12).toString() == "驳回")
                        {
                            item7->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(12).toString() == "不同意")
                        {
                            item7->setTextColor(Qt::red);
                        }
                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);

                    }

                }
                //
                if(query.value(0).toString() == "忘打卡" && query.value(7).toString() == LoginWindow::userName)
                {
                    if(query.value(4).toString() == "属实" && query.value(6).toString() == "同意")
                    {

                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();
                        item3->setTextColor(Qt::darkGreen);
                        item4->setTextColor(Qt::darkGreen);
                        if(query.value(8).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");
                        }
                        //vice
                        if(query.value(8).toString() == "待处理")
                        {
                            item5->setTextColor(Qt::blue);
                        }
                        if(query.value(8).toString() == "同意")
                        {
                            item5->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(8).toString() == "驳回")
                        {
                            item5->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(8).toString() == "不同意")
                        {
                            item5->setTextColor(Qt::red);
                        }
                        //clerk
                        if(query.value(12).toString() == "待处理")
                        {
                            item7->setTextColor(Qt::blue);
                        }
                        if(query.value(12).toString() == "同意")
                        {
                            item7->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(12).toString() == "驳回")
                        {
                            item7->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(12).toString() == "不同意")
                        {
                            item7->setTextColor(Qt::red);
                        }

                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);

                    }

                }
                //
                if(query.value(0).toString() == "忘打卡" && query.value(11).toString() == LoginWindow::userName)
                {
                    if(query.value(4).toString() == "属实" && query.value(6).toString() == "同意" && query.value(8).toString() == "同意")
                    {
                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();
                        item3->setTextColor(Qt::darkGreen);
                        item4->setTextColor(Qt::darkGreen);
                        item5->setTextColor(Qt::darkGreen);
                        if(query.value(12).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");

                        }
                        //clerk
                        if(query.value(12).toString() == "待处理")
                        {
                            item7->setTextColor(Qt::blue);
                        }
                        if(query.value(12).toString() == "同意")
                        {
                            item7->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(12).toString() == "驳回")
                        {
                            item7->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(12).toString() == "不同意")
                        {
                            item7->setTextColor(Qt::red);
                        }
                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);

                    }
                }
                if(query.value(0).toString() == "采购申请" && query.value(3).toString() == LoginWindow::userName)
                {
                    realRowNum++;
                    ui->tableWidget->setRowCount(realRowNum);
                    QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                    QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                    QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                    QTableWidgetItem * item8 = new QTableWidgetItem();
                    if(query.value(4).toString() == "待处理")
                    {
                        item8 = new QTableWidgetItem("点击处理");
                        item8->setTextColor(Qt::red);
                        item8->setBackgroundColor(QColor(235,235,235));
                        item8->setToolTip("点击处理");

                    }else
                    {
                        item8 = new QTableWidgetItem("已处理");
                        item8->setTextColor(Qt::blue);
                        item8->setBackgroundColor(QColor(235,235,235));
                        item8->setToolTip("点击查看");

                    }

                    //group
                    if(query.value(4).toString() == "待处理")
                    {
                        item3->setTextColor(Qt::blue);
                    }
                    if(query.value(4).toString() == "同意")
                    {
                        item3->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(4).toString() == "驳回")
                    {
                        item3->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(4).toString() == "不同意")
                    {
                        item3->setTextColor(Qt::red);
                    }
                    //dpt
                    if(query.value(6).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(6).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(6).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(6).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    //manager
                    if(query.value(10).toString() == "待处理")
                    {
                        item6->setTextColor(Qt::blue);
                    }
                    if(query.value(10).toString() == "同意")
                    {
                        item6->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(10).toString() == "驳回")
                    {
                        item6->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(10).toString() == "不同意")
                    {
                        item6->setTextColor(Qt::red);
                    }
                    //clerk
                    if(query.value(12).toString() == "待处理")
                    {
                        item7->setTextColor(Qt::blue);
                    }
                    if(query.value(12).toString() == "同意")
                    {
                        item7->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(12).toString() == "驳回")
                    {
                        item7->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(12).toString() == "不同意")
                    {
                        item7->setTextColor(Qt::red);
                    }
                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item6->setTextAlignment(Qt::AlignCenter);
                    item7->setTextAlignment(Qt::AlignCenter);
                    item8->setTextAlignment(Qt::AlignCenter);

                    ui->tableWidget->setItem(realRowNum-1,0,item0);
                    ui->tableWidget->setItem(realRowNum-1,1,item1);
                    ui->tableWidget->setItem(realRowNum-1,2,item2);
                    ui->tableWidget->setItem(realRowNum-1,3,item3);
                    ui->tableWidget->setItem(realRowNum-1,4,item4);
                    ui->tableWidget->setItem(realRowNum-1,5,item5);
                    ui->tableWidget->setItem(realRowNum-1,6,item6);
                    ui->tableWidget->setItem(realRowNum-1,7,item7);
                    ui->tableWidget->setItem(realRowNum-1,8,item8);
                }
                //采购
                if(query.value(0).toString() == "采购申请" && query.value(5).toString() == LoginWindow::userName)
                {
                    if(query.value(4).toString() == "同意")
                    {

                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();
                        item3->setTextColor(Qt::darkGreen);
                        if(query.value(6).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");

                        }

                        //dpt
                        if(query.value(6).toString() == "待处理")
                        {
                            item4->setTextColor(Qt::blue);
                        }
                        if(query.value(6).toString() == "同意")
                        {
                            item4->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(6).toString() == "驳回")
                        {
                            item4->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(6).toString() == "不同意")
                        {
                            item4->setTextColor(Qt::red);
                        }
                        //manager
                        if(query.value(10).toString() == "待处理")
                        {
                            item6->setTextColor(Qt::blue);
                        }
                        if(query.value(10).toString() == "同意")
                        {
                            item6->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(10).toString() == "驳回")
                        {
                            item6->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(10).toString() == "不同意")
                        {
                            item6->setTextColor(Qt::red);
                        }
                        //clerk
                        if(query.value(12).toString() == "待处理")
                        {
                            item7->setTextColor(Qt::blue);
                        }
                        if(query.value(12).toString() == "同意")
                        {
                            item7->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(12).toString() == "驳回")
                        {
                            item7->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(12).toString() == "不同意")
                        {
                            item7->setTextColor(Qt::red);
                        }
                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);

                    }

                }
                //采购申请
                if(query.value(0).toString() == "采购申请" && query.value(9).toString() == LoginWindow::userName)
                {
                    if(query.value(4).toString() == "同意" && query.value(6).toString() == "同意")
                    {

                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();

                        item3->setTextColor(Qt::darkGreen);
                        item4->setTextColor(Qt::darkGreen);
                        if(query.value(10).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");

                        }

                        //manager
                        if(query.value(9).toString() != "-")
                        {

                            if(query.value(10).toString() == "待处理")
                            {
                                item6->setTextColor(Qt::blue);
                            }
                            if(query.value(10).toString() == "同意")
                            {
                                item6->setTextColor(Qt::darkGreen);
                            }
                            if(query.value(10).toString() == "驳回")
                            {
                                item6->setTextColor(Qt::darkYellow);
                            }
                            if(query.value(10).toString() == "不同意")
                            {
                                item6->setTextColor(Qt::red);
                            }
                        }else
                        {
                            item6->setText("-");
                        }

                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);
                    }

                }
                //出差
                if(query.value(0).toString() == "出差" && query.value(5).toString() == LoginWindow::userName)
                {


                    realRowNum++;
                    ui->tableWidget->setRowCount(realRowNum);
                    QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());//leaderResult
                    QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());//viceManagerResult
                    QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());//managerResult
                    QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());//clerkResult
                    QTableWidgetItem * item8 = new QTableWidgetItem();

                    if(query.value(6).toString() == "待处理")
                    {

                        item8->setText("点击处理");
                        item8->setTextColor(Qt::red);
                        item8->setBackgroundColor(QColor(235,235,235));

                    }else
                    {

                        item8->setText("已处理");
                        item8->setTextColor(Qt::blue);
                        item8->setBackgroundColor(QColor(235,235,235));

                    }
                    //dpt
                    if(query.value(6).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(6).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(6).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(6).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    //manager
                    if(query.value(10).toString() == "待处理")
                    {
                        item6->setTextColor(Qt::blue);
                    }
                    if(query.value(10).toString() == "同意")
                    {
                        item6->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(10).toString() == "驳回")
                    {
                        item6->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(10).toString() == "不同意")
                    {
                        item6->setTextColor(Qt::red);
                    }
                    //clerk
                    if(query.value(12).toString() == "待处理")
                    {
                        item7->setTextColor(Qt::blue);
                    }
                    if(query.value(12).toString() == "同意")
                    {
                        item7->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(12).toString() == "驳回")
                    {
                        item7->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(12).toString() == "不同意")
                    {
                        item7->setTextColor(Qt::red);
                    }

                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item6->setTextAlignment(Qt::AlignCenter);
                    item7->setTextAlignment(Qt::AlignCenter);
                    item8->setTextAlignment(Qt::AlignCenter);

                    ui->tableWidget->setItem(realRowNum-1,0,item0);
                    ui->tableWidget->setItem(realRowNum-1,1,item1);
                    ui->tableWidget->setItem(realRowNum-1,2,item2);
                    ui->tableWidget->setItem(realRowNum-1,3,item3);
                    ui->tableWidget->setItem(realRowNum-1,4,item4);
                    ui->tableWidget->setItem(realRowNum-1,5,item5);
                    ui->tableWidget->setItem(realRowNum-1,6,item6);
                    ui->tableWidget->setItem(realRowNum-1,7,item7);
                    ui->tableWidget->setItem(realRowNum-1,8,item8);

                }
                //userName = clerk
                if(query.value(0).toString() == "出差" && query.value(11).toString() == LoginWindow::userName)
                {
                    if(query.value(6).toString() == "同意" && query.value(10).toString() == "同意")
                    {
                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();

                        item4->setTextColor(Qt::darkGreen);
                        item6->setTextColor(Qt::darkGreen);
                        if(query.value(12).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");

                        }

                        //dpt
                        if(query.value(6).toString() == "待处理")
                        {
                            item4->setTextColor(Qt::blue);
                        }
                        if(query.value(6).toString() == "同意")
                        {
                            item4->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(6).toString() == "驳回")
                        {
                            item4->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(6).toString() == "不同意")
                        {
                            item4->setTextColor(Qt::red);
                        }

                        //manager
                        if(query.value(10).toString() == "待处理")
                        {
                            item6->setTextColor(Qt::blue);
                        }
                        if(query.value(10).toString() == "同意")
                        {
                            item6->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(10).toString() == "驳回")
                        {
                            item6->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(10).toString() == "不同意")
                        {
                            item6->setTextColor(Qt::red);
                        }
                        //clerk
                        if(query.value(12).toString() == "待处理")
                        {
                            item7->setTextColor(Qt::blue);
                        }
                        if(query.value(12).toString() == "同意")
                        {
                            item7->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(12).toString() == "驳回")
                        {
                            item7->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(12).toString() == "不同意")
                        {
                            item7->setTextColor(Qt::red);
                        }
                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);
                    }

                }
                //username = manager
                if(query.value(0).toString() == "出差" && query.value(9).toString() == LoginWindow::userName)
                {
                    if(query.value(6).toString() == "同意")
                    {

                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();

                        item4->setTextColor(Qt::darkGreen);
                        if(query.value(10).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");

                        }
                        //manager
                        if(query.value(10).toString() == "待处理")
                        {
                            item6->setTextColor(Qt::blue);
                        }
                        if(query.value(10).toString() == "同意")
                        {
                            item6->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(10).toString() == "驳回")
                        {
                            item6->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(10).toString() == "不同意")
                        {
                            item6->setTextColor(Qt::red);
                        }
                        //clerk
                        if(query.value(12).toString() == "待处理")
                        {
                            item7->setTextColor(Qt::blue);
                        }
                        if(query.value(12).toString() == "同意")
                        {
                            item7->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(12).toString() == "驳回")
                        {
                            item7->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(12).toString() == "不同意")
                        {
                            item7->setTextColor(Qt::red);
                        }

                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);
                    }

                }
                //外出
                //userName = dptLeader
                if(query.value(0).toString() == "外出" && query.value(5).toString() == LoginWindow::userName)
                {
                    realRowNum++;
                    ui->tableWidget->setRowCount(realRowNum);
                    QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                    QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                    QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                    QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                    QTableWidgetItem * item8 = new QTableWidgetItem();

                    if(query.value(6).toString() == "待处理")
                    {
                        item8 = new QTableWidgetItem("点击处理");
                        item8->setTextColor(Qt::red);
                        item8->setBackgroundColor(QColor(235,235,235));
                        item8->setToolTip("点击处理");

                    }else
                    {
                        item8 = new QTableWidgetItem("已处理");
                        item8->setTextColor(Qt::blue);
                        item8->setBackgroundColor(QColor(235,235,235));
                        item8->setToolTip("点击查看");

                    }
                    //dpt
                    if(query.value(6).toString() == "待处理")
                    {
                        item4->setTextColor(Qt::blue);
                    }
                    if(query.value(6).toString() == "同意")
                    {
                        item4->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(6).toString() == "驳回")
                    {
                        item4->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(6).toString() == "不同意")
                    {
                        item4->setTextColor(Qt::red);
                    }
                    //clerk
                    if(query.value(12).toString() == "待处理")
                    {
                        item7->setTextColor(Qt::blue);
                    }
                    if(query.value(12).toString() == "同意")
                    {
                        item7->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(12).toString() == "驳回")
                    {
                        item7->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(12).toString() == "不同意")
                    {
                        item7->setTextColor(Qt::red);
                    }

                    item0->setTextAlignment(Qt::AlignCenter);
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    item4->setTextAlignment(Qt::AlignCenter);
                    item5->setTextAlignment(Qt::AlignCenter);
                    item6->setTextAlignment(Qt::AlignCenter);
                    item7->setTextAlignment(Qt::AlignCenter);
                    item8->setTextAlignment(Qt::AlignCenter);

                    ui->tableWidget->setItem(realRowNum-1,0,item0);
                    ui->tableWidget->setItem(realRowNum-1,1,item1);
                    ui->tableWidget->setItem(realRowNum-1,2,item2);
                    ui->tableWidget->setItem(realRowNum-1,3,item3);
                    ui->tableWidget->setItem(realRowNum-1,4,item4);
                    ui->tableWidget->setItem(realRowNum-1,5,item5);
                    ui->tableWidget->setItem(realRowNum-1,6,item6);
                    ui->tableWidget->setItem(realRowNum-1,7,item7);
                    ui->tableWidget->setItem(realRowNum-1,8,item8);
                }
                //username = clerk
                if(query.value(0).toString() == "外出" && query.value(11).toString() == LoginWindow::userName)
                {
                    if(query.value(6).toString() == "同意")
                    {

                        realRowNum++;
                        ui->tableWidget->setRowCount(realRowNum);
                        QTableWidgetItem * item0 = new QTableWidgetItem(query.value(0).toString());
                        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(1).toString());
                        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(2).toString());
                        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(4).toString());
                        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(6).toString());
                        QTableWidgetItem * item5 = new QTableWidgetItem(query.value(8).toString());
                        QTableWidgetItem * item6 = new QTableWidgetItem(query.value(10).toString());
                        QTableWidgetItem * item7 = new QTableWidgetItem(query.value(12).toString());
                        QTableWidgetItem * item8 = new QTableWidgetItem();

                        item4->setTextColor(Qt::darkGreen);
                        if(query.value(12).toString() == "待处理")
                        {
                            item8 = new QTableWidgetItem("点击处理");
                            item8->setTextColor(Qt::red);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击处理");

                        }else
                        {
                            item8 = new QTableWidgetItem("已处理");
                            item8->setTextColor(Qt::blue);
                            item8->setBackgroundColor(QColor(235,235,235));
                            item8->setToolTip("点击查看");

                        }
                        //clerk
                        if(query.value(12).toString() == "待处理")
                        {
                            item7->setTextColor(Qt::blue);
                        }
                        if(query.value(12).toString() == "同意")
                        {
                            item7->setTextColor(Qt::darkGreen);
                        }
                        if(query.value(12).toString() == "驳回")
                        {
                            item7->setTextColor(Qt::darkYellow);
                        }
                        if(query.value(12).toString() == "不同意")
                        {
                            item7->setTextColor(Qt::red);
                        }

                        item0->setTextAlignment(Qt::AlignCenter);
                        item1->setTextAlignment(Qt::AlignCenter);
                        item2->setTextAlignment(Qt::AlignCenter);
                        item3->setTextAlignment(Qt::AlignCenter);
                        item4->setTextAlignment(Qt::AlignCenter);
                        item5->setTextAlignment(Qt::AlignCenter);
                        item6->setTextAlignment(Qt::AlignCenter);
                        item7->setTextAlignment(Qt::AlignCenter);
                        item8->setTextAlignment(Qt::AlignCenter);

                        ui->tableWidget->setItem(realRowNum-1,0,item0);
                        ui->tableWidget->setItem(realRowNum-1,1,item1);
                        ui->tableWidget->setItem(realRowNum-1,2,item2);
                        ui->tableWidget->setItem(realRowNum-1,3,item3);
                        ui->tableWidget->setItem(realRowNum-1,4,item4);
                        ui->tableWidget->setItem(realRowNum-1,5,item5);
                        ui->tableWidget->setItem(realRowNum-1,6,item6);
                        ui->tableWidget->setItem(realRowNum-1,7,item7);
                        ui->tableWidget->setItem(realRowNum-1,8,item8);
                    }

                }
                //

            }
        }
        //排除空的
//        for(int i = 0;i != ui->tableWidget->rowCount();++i)
//        {
//            if(ui->tableWidget->item(i,0))
//            {
//                if(ui->tableWidget->item(i,0)->text().trimmed().isEmpty())
//                {
//                    ui->tableWidget->removeRow(i);
//                }
//            }
//        }
    }else
    {
        qDebug() << "sql err: " << query.lastError().text();
    }
}

//打开数据库
bool Widget::openMySql()
{
    if(!QSqlDatabase::database().isOpen())
    {
        QSqlDatabase db =  QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(sqlIP);
        db.setDatabaseName(sqlBaseName);
        db.setPort(sqlPort);
        db.setUserName(sqlUserName);
        db.setPassword(sqlPassword);
        if(!db.open())
        {
            QMessageBox::about(NULL,"",tr("数据库错误：%1").arg(QSqlDatabase::database().lastError().text()));
            return false;
        }else
        {
            return true;
        }
    }
    return true;
}

void Widget::toolButton_newStream_clicked()
{
    chooseType * type = new chooseType;
    connect(type,SIGNAL(emitToJiabanToFlushStreamListSig(QString)),this,SLOT(showStreamListSlot(QString)));
    type->show();
}
//定义刷新电子流申请列表
void Widget::showStreamListSlot(QString type)
{

    if(type == "加班")
    {
        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(6);

        QStringList header;
        header << "电子流类型" << "提交时间" << "加班时段" << "处理人"<<"处理结果"<<"查看";
        ui->tableWidget->setHorizontalHeaderLabels(header);
//        ui->tableWidget->setColumnWidth(0,ui->tableWidget->width()/6);
//        ui->tableWidget->setColumnWidth(1,ui->tableWidget->width()/6);
//        ui->tableWidget->setColumnWidth(2,ui->tableWidget->width()/6);
//        ui->tableWidget->setColumnWidth(3,ui->tableWidget->width()/6);
//        ui->tableWidget->setColumnWidth(4,ui->tableWidget->width()/6);
//        ui->tableWidget->setColumnWidth(5,ui->tableWidget->width()/6);
        if(!QSqlDatabase::database().isOpen())
        {
            openMySql();
        }else
        {

            QSqlQuery query;
            if(!query.exec(tr("select count(*) from jiabanmsg where staffid = '%1'").arg(LoginWindow::staffID)))
            {
                qDebug() << "Sql Error:" << query.lastError().text();
                return;
            }
            query.next();
            int rowNum = query.value(0).toInt();
            ui->tableWidget->setRowCount(rowNum);
            if(rowNum > 0)
            {
                if(!query.exec(tr("select dealTime,jbTimeArea,jbStartTime,jbEndTime,leaderName,dealResult from jiabanmsg where staffid = '%1' order by dealtime desc")
                           .arg(LoginWindow::staffID)))
                {
                    qDebug() << "Sql Error:" << query.lastError().text();
                    return;
                }
                for(int i = 0; i < rowNum; i++)
                {
                    query.next();

                    QTableWidgetItem * item1 = new QTableWidgetItem("加班");
                    QTableWidgetItem * item2 = new QTableWidgetItem(query.value(0).toString());
                    QTableWidgetItem * item3 = new QTableWidgetItem(query.value(1).toString());
                    //QTableWidgetItem * item4 = new QTableWidgetItem(query.value(2).toString()+"~"+query.value(3).toString());
                    QTableWidgetItem * item5 = new QTableWidgetItem(query.value(4).toString());
                    QTableWidgetItem * item6 = new QTableWidgetItem(query.value(5).toString());
                    QTableWidgetItem * item7 = new QTableWidgetItem("点击查看");
                    item7->setToolTip("点击查看");
                    item1->setTextAlignment(Qt::AlignCenter);
                    item2->setTextAlignment(Qt::AlignCenter);
                    item3->setTextAlignment(Qt::AlignCenter);
                    //item4->setTextAlignment(Qt::AlignCenter);

                    item5->setTextAlignment(Qt::AlignCenter);
                    item6->setTextAlignment(Qt::AlignCenter);
                    item7->setTextAlignment(Qt::AlignCenter);
                    item7->setBackgroundColor(QColor(235,235,235));
                    //connect(ui->tableWidget,SIGNAL(itemEntered(QTableWidgetItem*)),this,SLOT(changFontSlot(QTableWidgetItem*)));
                    if(query.value(5).toString() == "待处理")
                    {
                        item6->setTextColor(Qt::blue);
                    }
                    if(query.value(5).toString() == "同意")
                    {
                        item6->setTextColor(Qt::darkGreen);
                    }
                    if(query.value(5).toString() == "驳回")
                    {
                        item6->setTextColor(Qt::darkYellow);
                    }
                    if(query.value(5).toString() == "不同意")
                    {
                        item6->setTextColor(Qt::red);
                    }
                    item7->setTextColor(Qt::blue);
                    ui->tableWidget->setItem(i,0,item1);
                    ui->tableWidget->setItem(i,1,item2);
                    ui->tableWidget->setItem(i,2,item3);
                    ui->tableWidget->setItem(i,3,item5);
                    ui->tableWidget->setItem(i,4,item6);
                    ui->tableWidget->setItem(i,5,item7);
/*
                    delete item1;
                    delete item2;
                    delete item3;
                    delete item5;
                    delete item6;
                    delete item7;
                    */
                }
            }

        }
    }
    if(type == "点击处理")
    {
        on_toolBtn_dcl_clicked();
    }
    if(type == "请假")
    {

        on_toolBtn_qj_clicked();

    }
    if(type == "忘打卡")
    {
        on_toolBtn_wdk_clicked();
    }
    if(type == "采购申请")
    {
        on_toolBtn_cg_clicked();
    }
    if(type == "出差")
    {
        on_pushButton_chuChai_clicked();
    }
    if(type == "外出")
    {
        on_pushButton_waiChu_clicked();
    }
}

//接收udp提示消息
void Widget::recvTipUdpMsgSlot()
{
    QByteArray recvMsg;
    while(udpSocket->hasPendingDatagrams())
    {
        recvMsg.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(recvMsg.data(),recvMsg.size());
        //检查是否有未读邮件
        checkIfHaveNotReadEmails();

        if(recvMsg == "新加班")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有加班电子流待处理!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "新请假")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有请假电子流待处理!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "新忘打卡")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有忘打卡电子流待处理!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "已处理加班")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您的加班电子流已被处理！");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "已处理请假")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您的请假电子流已被处理！");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "已处理忘打卡")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您的忘打卡电子流已被处理！");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "下一个请假")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有请假电子流待处理!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "下一个忘打卡")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有忘打卡电子流待处理!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "新采购")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有采购申请电子流待处理!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "已处理采购申请")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您的采购申请电子流已被处理！");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "新采购申请")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有新的采购申请待处理!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "请查看图样编号")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您的图样编号已生成!");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else if(recvMsg == "已处理")
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您的电子流已被处理！");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else
        {
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog(recvMsg);
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
    }
}

void Widget::showWidgetSlot(QString tipMsg)
{
    if(tipMsg == "点击处理")
    {
        on_toolBtn_dcl_clicked();
        this->show();

    }
    if(tipMsg == "查看加班")
    {
        on_toolBtn_jb_clicked();
        this->show();
    }
    if(tipMsg == "查看请假")
    {
        on_toolBtn_qj_clicked();
        this->show();
    }
    if(tipMsg == "查看忘打卡")
    {
        on_toolBtn_wdk_clicked();
        this->show();
    }
    if(tipMsg == "查看采购")
    {
        on_toolBtn_cg_clicked();
        this->show();
    }
    if(tipMsg == "查看图样编号")
    {
        toolBtn_tybh_clicked();
        this->show();
    }
}

//点击单元格后查看电子流
void Widget::clickedToShowSlot(int x,int y)
{
    //加班
    if(ui->tableWidget->item(x,0)->text() == "加班" && y == 5 && ui->tableWidget->columnCount() != 9)
    {
        if(ui->tableWidget->item(x,4)->text() == "同意" || ui->tableWidget->item(x,4)->text() == "待处理" )
        {
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            if(query.exec(tr("select * from jiabanmsg where dealtime = '%1'").arg(ui->tableWidget->item(x,1)->text())))
            {
                query.next();
                Jiaban * jiabanShow = new Jiaban("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                 ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                 ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                 ,query.value(12).toString());

                jiabanShow->show();
            }
        }
        if(ui->tableWidget->item(x,4)->text() == "不同意" || ui->tableWidget->item(x,4)->text() == "驳回")
        {
            if(!QSqlDatabase::database().isOpen())
            {
                Widget::openMySql();
            }
            QSqlQuery query;
            if(query.exec(tr("select * from jiabanmsg where dealtime = '%1'").arg(ui->tableWidget->item(x,1)->text())))
            {
                query.next();
                Jiaban * jiabanShow = new Jiaban("驳回",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                 ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                 ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                 ,query.value(12).toString());
                jiabanShow->show();
            }
        }
    }
    //请假
    if(ui->tableWidget->item(x,0)->text() == "请假" && y == 5 && ui->tableWidget->columnCount() != 9)
    {
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("select * from qingjiamsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,1)->text()).arg(LoginWindow::userName)))
        {
            query.next();
            if((ui->tableWidget->item(x,2)->text()=="待处理"||ui->tableWidget->item(x,2)->text()=="同意")
                    &&(ui->tableWidget->item(x,3)->text()=="待处理"||ui->tableWidget->item(x,3)->text()=="同意")
                    &&(ui->tableWidget->item(x,4)->text()=="待处理"||ui->tableWidget->item(x,4)->text()=="同意"||ui->tableWidget->item(x,4)->text()=="-"))
            {
                QingJia * qingjia = new QingJia("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                qingjia->show();
            }else{
                QingJia * qingjia = new QingJia("驳回",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                qingjia->show();
            }

        }
    }
    //忘打卡
    if(ui->tableWidget->item(x,0)->text() == "忘打卡" && y == 6 && ui->tableWidget->columnCount() != 9)
    {
        if(!QSqlDatabase::database().isOpen())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("select * from wangdakamsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,1)->text()).arg(LoginWindow::userName)))
        {
            query.next();
            if((ui->tableWidget->item(x,2)->text()=="待处理"||ui->tableWidget->item(x,2)->text()=="属实")
                    &&(ui->tableWidget->item(x,3)->text()=="待处理"||ui->tableWidget->item(x,3)->text()=="同意")
                    &&(ui->tableWidget->item(x,4)->text()=="待处理"||ui->tableWidget->item(x,4)->text()=="同意")
                    &&(ui->tableWidget->item(x,5)->text()=="待处理"||ui->tableWidget->item(x,5)->text()=="同意"))
            {
                WangDaKa * wangdaka = new WangDaKa("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                wangdaka->show();
            }else{
                WangDaKa * wangdaka = new WangDaKa("驳回",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                wangdaka->show();
            }

        }
    }
    //采购申请
    if(ui->tableWidget->columnCount() == 6 && y == 5 && ui->tableWidget->item(x,0)->text() == "采购申请" && ui->tableWidget->columnCount() != 9)
    {
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("select * from caigouapmsg where dealtime = '%1'").arg(ui->tableWidget->item(x,1)->text())))
        {
            query.next();

            if((ui->tableWidget->item(x,2)->text()=="待处理"||ui->tableWidget->item(x,2)->text()=="同意")
                    &&(ui->tableWidget->item(x,3)->text()=="待处理"||ui->tableWidget->item(x,3)->text()=="同意")
                    &&(ui->tableWidget->item(x,4)->text()=="待处理"||ui->tableWidget->item(x,4)->text()=="同意"||ui->tableWidget->item(x,4)->text()=="-"))
            {
                CGSQ * cgsq = new CGSQ(tr("查看"),NULL,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(17).toString());

                cgsq->show();
                qDebug() << "return;";
                //return;
            }else{
                CGSQ * cgsq = new CGSQ(QString("驳回"),NULL,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(17).toString());
                cgsq->show();
            }

        }
    }
    //出差
    if(ui->tableWidget->item(x,0)->text() == "出差" && y == 5  && ui->tableWidget->columnCount() != 9)
    {

        if((ui->tableWidget->item(x,2)->text()=="待处理"||ui->tableWidget->item(x,2)->text()=="同意")
                &&(ui->tableWidget->item(x,3)->text()=="待处理"||ui->tableWidget->item(x,3)->text()=="同意")
                &&(ui->tableWidget->item(x,4)->text()=="待处理"||ui->tableWidget->item(x,4)->text()=="同意"))
        {
            ChuChai * chuchai = new ChuChai("查看",LoginWindow::userName,ui->tableWidget->item(x,1)->text());
            chuchai->show();
        }
        else
        {
            ChuChai * chuchai = new ChuChai("驳回",LoginWindow::userName,ui->tableWidget->item(x,1)->text());
            chuchai->show();
        }
    }
    //外出
    if(ui->tableWidget->item(x,0)->text() == "外出" && y == 4  && ui->tableWidget->columnCount() != 9)
    {

        if((ui->tableWidget->item(x,2)->text()=="待处理"||ui->tableWidget->item(x,2)->text()=="同意")
                &&(ui->tableWidget->item(x,3)->text()=="待处理"||ui->tableWidget->item(x,3)->text()=="同意"))
        {
            WaiChu * waichu = new WaiChu("查看",LoginWindow::userName,ui->tableWidget->item(x,1)->text());
            waichu->show();
        }
        else
        {
            WaiChu * waichu = new WaiChu("驳回",LoginWindow::userName,ui->tableWidget->item(x,1)->text());
            waichu->show();
        }
    }
    //点击处理情况
    if(ui->tableWidget->columnCount() == 9 && y == 8)
    {
        if(ui->tableWidget->item(x,0)->text() == "加班")
        {
            if(ui->tableWidget->item(x,8)->text() == "已处理")
            {
                if(!QSqlDatabase::database().isOpen())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from jiabanmsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    query.next();
                    Jiaban * jiabanShow = new Jiaban("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                     ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                        ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                     ,query.value(12).toString());
                    jiabanShow->show();
                }
            }else//点击处理情况
            {
                if(!QSqlDatabase::database().isOpen())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from jiabanmsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    query.next();
                    Jiaban * jiabanShow = new Jiaban("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                     ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                     ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                     ,query.value(12).toString());
                    connect(jiabanShow,SIGNAL(sendFlushDclSig()),this,SLOT(on_toolBtn_dcl_clicked()));
                    jiabanShow->show();
                }
            }
        }
        //请假情况
        if(ui->tableWidget->item(x,0)->text() == "请假")
        {
            if(ui->tableWidget->item(x,8)->text() == "已处理")
            {
                if(!QSqlDatabase::database().isOpen())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from qingjiamsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    query.next();
                    QingJia * qingjiaShow = new QingJia("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                     ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                        ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                     ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                        ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                    qingjiaShow->show();
                }
            }else//点击处理情况
            {
                if(!QSqlDatabase::database().isOpen())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from qingjiamsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    query.next();
                    QingJia * qingjiaShow;
                    if(ui->tableWidget->item(x,4)->text() == "待处理")
                    {
                        qingjiaShow = new QingJia("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                         ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                            ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                         ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                            ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),"部门领导");

                    }
                    if(ui->tableWidget->item(x,4)->text() == "同意"&&ui->tableWidget->item(x,5)->text()=="待处理")
                    {
                        qingjiaShow = new QingJia("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                         ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                            ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                         ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                            ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),"副总经理");
                    }
                    if(ui->tableWidget->item(x,4)->text() == "同意"&&ui->tableWidget->item(x,5)->text()=="同意"&&ui->tableWidget->item(x,6)->text()=="待处理")
                    {
                        qingjiaShow = new QingJia("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                         ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                            ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                         ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                            ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),"总经理");
                    }
                    connect(qingjiaShow,SIGNAL(sendFlushDclSig()),this,SLOT(on_toolBtn_dcl_clicked()));
                    qingjiaShow->show();
                }
            }
        }
        //忘打卡
        if(ui->tableWidget->item(x,0)->text() == "忘打卡")
        {
            if(ui->tableWidget->item(x,8)->text() == "已处理")
            {
                if(!QSqlDatabase::database().isValid())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from wangdakamsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    query.next();
                    WangDaKa * wangdakaShow = new WangDaKa("查看",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                     ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                        ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                     ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                        ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString());
                    wangdakaShow->show();
                }
            }else//点击处理情况
            {
                if(!QSqlDatabase::database().isOpen())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from wangdakamsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    query.next();
                    WangDaKa * wangdakaShow;
                    //证明人
                    if(ui->tableWidget->item(x,3)->text() == "待处理")
                    {
                        wangdakaShow = new WangDaKa("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                         ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                            ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                         ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                            ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),"证明人");
                    }
                    //部门领导
                    if(ui->tableWidget->item(x,3)->text() == "属实" && ui->tableWidget->item(x,4)->text() == "待处理")
                    {
                        wangdakaShow = new WangDaKa("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                         ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                            ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                         ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                            ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),"部门领导");
                    }
                    //副总经理
                    if(ui->tableWidget->item(x,3)->text() == "属实" && ui->tableWidget->item(x,4)->text() == "同意" && ui->tableWidget->item(x,5)->text() == "待处理")
                    {
                        wangdakaShow = new WangDaKa("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                         ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                            ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                         ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                            ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),"副总经理");
                    }
                    //考勤员
                    if(ui->tableWidget->item(x,3)->text() == "属实" && ui->tableWidget->item(x,4)->text() == "同意" && ui->tableWidget->item(x,5)->text() == "同意" && ui->tableWidget->item(x,7)->text() == "待处理")
                    {
                        wangdakaShow = new WangDaKa("点击处理",query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString()
                                                         ,query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                            ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                         ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(15).toString()
                                                            ,query.value(16).toString(),query.value(17).toString(),query.value(18).toString(),"考勤员");
                    }
                    connect(wangdakaShow,SIGNAL(sendFlushDclSig()),this,SLOT(on_toolBtn_dcl_clicked()));
                    wangdakaShow->show();
                }
            }
        }
        if(ui->tableWidget->item(x,0)->text() == "采购申请")
        {
            if(ui->tableWidget->item(x,8)->text() == "已处理")
            {
                if(!QSqlDatabase::database().isValid())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from caigouapmsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    query.next();
                    CGSQ * cgsq = new CGSQ(tr("查看"),NULL,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                    query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                    ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                    ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(17).toString());
                    cgsq->show();
                }
            }else{
                if(!QSqlDatabase::database().isValid())
                {
                    Widget::openMySql();
                }
                QSqlQuery query;
                if(query.exec(tr("select * from caigouapmsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(ui->tableWidget->item(x,1)->text())))
                {
                    qDebug() << "sql = " << tr("select * from caigouapmsg where dealtime = '%1' and name = '%2'").arg(ui->tableWidget->item(x,2)->text()).arg(LoginWindow::userName);
                    query.next();
                    //组长
                    if(ui->tableWidget->item(x,3)->text() == "待处理")
                    {
                        CGSQ * cgsq = new CGSQ(tr("点击处理"),NULL,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                        query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                        ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                        ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(17).toString(),"组长");
                        cgsq->show();
                    }
                    //部门领导
                    if(ui->tableWidget->item(x,3)->text() == "同意" && ui->tableWidget->item(x,4)->text() == "待处理")
                    {
                        CGSQ * cgsq = new CGSQ(tr("点击处理"),NULL,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                        query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                        ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                        ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(17).toString(),"部门领导");
                        cgsq->show();
                    }
                    //总经理
                    if(ui->tableWidget->item(x,3)->text() == "同意" && ui->tableWidget->item(x,4)->text() == "同意" && ui->tableWidget->item(x,6)->text() == "待处理")
                    {
                        CGSQ * cgsq = new CGSQ(tr("点击处理"),NULL,query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                                        query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString()
                                                        ,query.value(8).toString(),query.value(9).toString(),query.value(10).toString(),query.value(11).toString()
                                                        ,query.value(12).toString(),query.value(13).toString(),query.value(14).toString(),query.value(17).toString(),"总经理");
                        cgsq->show();
                    }
                }
            }
        }
        //出差
        if(ui->tableWidget->item(x,0)->text() == "出差")
        {
            if(ui->tableWidget->item(x,8)->text() == "已处理")
            {
                 ChuChai * chuchai = new ChuChai("查看",ui->tableWidget->item(x,1)->text(),ui->tableWidget->item(x,2)->text());
                 chuchai->show();
            }
            else//点击处理情况
            {
                ChuChai * chuchai = new ChuChai("点击处理",ui->tableWidget->item(x,1)->text(),ui->tableWidget->item(x,2)->text());
                connect(chuchai,SIGNAL(sendFlushDclSig()),this,SLOT(on_toolBtn_dcl_clicked()));
                chuchai->show();
            }
        }
        //外出
        if(ui->tableWidget->item(x,0)->text() == "外出")
        {
            if(ui->tableWidget->item(x,8)->text() == "已处理")
            {
                 WaiChu * waichu = new WaiChu("查看",ui->tableWidget->item(x,1)->text(),ui->tableWidget->item(x,2)->text());
                 waichu->show();
            }
            else//点击处理情况
            {
                WaiChu * waichu = new WaiChu("点击处理",ui->tableWidget->item(x,1)->text(),ui->tableWidget->item(x,2)->text());
                connect(waichu,SIGNAL(sendFlushDclSig()),this,SLOT(on_toolBtn_dcl_clicked()));
                waichu->show();
            }
        }
    }
}

//图样编号按钮slot
void Widget::toolBtn_tybh_clicked()
{
    TybhMainFrame * tybh = new TybhMainFrame;
    tybh->show();
}

void Widget::on_pushButton_quitAutoRun_clicked()
{
    if(QFile::exists(qApp->applicationDirPath() + "/account.dat"))
    {
        QFile file(qApp->applicationDirPath() + "/account.dat");
        file.open(QIODevice::ReadWrite);

        QByteArray rememberPswFlag = NULL;
        QByteArray autoLoginFlag = NULL;
        QByteArray staffId = NULL;
        QByteArray passWord = NULL;
        QByteArray version = NULL;

        rememberPswFlag = file.readLine();
        autoLoginFlag = file.readLine();
        staffId  = file.readLine();
        passWord    = file.readLine();
        version = file.readLine();

        file.reset();
        file.write(rememberPswFlag);
        file.write("false\n");
        file.write(staffId);
        file.write(passWord);
        file.write(version);
        file.close();
        ui->pushButton_quitAutoRun->setText("已退出自动登录");
    }
}

void Widget::on_pushButton_help_clicked()
{
    QAxObject * m_word = new QAxObject();
    bool bFlag = m_word->setControl("word.Application");
    if(!bFlag)
    {
        bFlag = m_word->setControl("kwps.Application");
    }
    if(!bFlag)
    {
        return;
    }
    m_word->setProperty("Visible",true);
    QAxObject* documents =m_word->querySubObject("Documents");
    if(!documents)
    {
        return;
    }
    documents->dynamicCall("Add(QString)",qApp->QCoreApplication::applicationDirPath()+"/正博OA使用手册.doc");
    this->showMinimized();
}

bool Widget::saveDaKaRecordToSql()
{
    if(!QSqlDatabase::database().isOpen())
    {
        if(Widget::openMySql() == false)
        {
            return false;
        }
    }
    QString excelPath = NULL;
    if(QFile::exists(qApp->applicationDirPath()+"/考勤记录/考勤记录.xlsx"))
    {
        excelPath = qApp->applicationDirPath()+"/考勤记录/考勤记录.xlsx";
    }
    if(QFile::exists(qApp->applicationDirPath()+"/考勤记录/考勤记录.xls"))
    {
        excelPath = qApp->applicationDirPath()+"/考勤记录/考勤记录.xls";
    }
    if(excelPath.isNull())
    {
        return false;
    }
    //
    //设置excel属性
    QAxObject excel("Excel.Application");
    excel.dynamicCall("SetVisible(bool Visible)","false");
    excel.setProperty("DisplayAlerts",false);//不显示任何警告信息，如关闭“文件已修改，是否保存”
     //打开考勤Excel
    QAxObject * workbooks = excel.querySubObject("WorkBooks");
    QAxObject * bomWorkbook = workbooks->querySubObject("Open (const QString&)",excelPath);
    QAxObject * bomWorksheet = bomWorkbook->querySubObject("WorkSheets(int)",1);
    //判断bom格式是否正确

    if(!(Bom::getCellValue(bomWorksheet,1,1).toString() == "考勤号码" && Bom::getCellValue(bomWorksheet,1,2).toString() == "姓名"
         && Bom::getCellValue(bomWorksheet,1,3).toString() == "部门" && Bom::getCellValue(bomWorksheet,1,4).toString() == "日期"
         && Bom::getCellValue(bomWorksheet,1,5).toString() == "时间"))
    {
        QMessageBox::warning(this,"提示","考勤Excel格式不对！\n"
                                       "表头为:考勤号码,姓名,部门,日期,时间.  ");
        excel.dynamicCall("Quit()");
        return false;
    }


    qDebug() << "rowNum = " << Bom::getUsedRowsCount(bomWorksheet);
    int rowNum = Bom::getUsedRowsCount(bomWorksheet);
    int startRowNum = 0;
    for(int i = 2;i <= rowNum;++i)
    {
        if(Bom::getCellValue(bomWorksheet,i,2).toInt() == 0)
        {
            startRowNum = i;
            break;
        }
    }


    //getStartTime(getStartTime(Bom::getCellValue(bomWorksheet,578,5).toString()));
    //qDebug() << "startRowNum" << startRowNum;
    for(int i = startRowNum;i <= rowNum;++i)
    {
        QSqlQuery query;
        //判断是否已经添加过
        if(query.exec(tr("select count(*) from dakarecord where name = '%1' and daytime = '%2'").arg(Bom::getCellValue(bomWorksheet,i,2).toString()).arg(Bom::getCellValue(bomWorksheet,i,4).toString())))
        {
            query.next();
            if(query.value(0).toInt() > 0)
            {
                continue;
            }
        }
        if(!query.exec(tr("insert into dakarecord values('%1','%2','%3','%4 ','%5')")
                      .arg(Bom::getCellValue(bomWorksheet,i,2).toString()).arg(Bom::getCellValue(bomWorksheet,i,3).toString()).arg(Bom::getCellValue(bomWorksheet,i,4).toString())
                      .arg(Bom::getCellValue(bomWorksheet,i,5).toString()).arg(getDayOfWeek(Bom::getCellValue(bomWorksheet,i,4).toString()))))
        {
            QSqlDatabase::database().rollback();
            QMessageBox::warning(this,"OA提示",tr("导入库存失败！\n错误信息：%1").arg(QSqlDatabase::database().lastError().text()),QMessageBox::Ok);
            break;
        }
    }
    QSqlDatabase::database().commit();
    excel.dynamicCall("Quit()");
    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("考勤Excel成功导入数据库！");
    dontUpdate->show();
    return true;

}

void Widget::on_toolButton_daka_clicked()
{
    //saveDaKaRecordToSql();
    DaKaRecord * daka = new DaKaRecord(ui->label_userName->text());
    daka->show();
}

int Widget::getDayOfWeek(QString dayTime)
{
    int year,mouth,day;
    year = dayTime.mid(0,4).toInt();
    mouth = dayTime.mid(5,2).toInt();
    day = dayTime.mid(8,2).toInt();
    QDate date(year,mouth,day);
    return date.dayOfWeek();
}

void Widget::on_toolButton_weekReport_clicked()
{
    WeekReportMainFrame * reportFrame = new WeekReportMainFrame;
    reportFrame->show();
}



void Widget::on_pushButton_chuChai_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    QStringList header;
    header << "电子流类型" << "提交时间" << "部门领导" << "总经理"<<"考勤员"<<"查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    QSqlQuery query;

    if(!query.exec(tr("select dealTime,leaderResult,managerResult,clerkResult from chuchai where staffid = '%1' order by dealtime desc")
                   .arg(LoginWindow::staffID)))
    {
        qDebug() << "Sql Error:" << query.lastError().text();
        return;
    }
    ui->tableWidget->setRowCount(query.size());

    for(int i = 0; i < query.size(); i++)
    {
        query.next();

        QTableWidgetItem * item0 = new QTableWidgetItem("出差");
        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(1).toString());//部门领导
        QTableWidgetItem * item3 = new QTableWidgetItem(query.value(2).toString());//总经理
        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(3).toString());//考勤员
        QTableWidgetItem * item5 = new QTableWidgetItem("点击查看");
        item5->setToolTip("点击查看");
        item0->setTextAlignment(Qt::AlignCenter);
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        item5->setTextAlignment(Qt::AlignCenter);
        item5->setBackgroundColor(QColor(235,235,235));
        item5->setTextColor(Qt::blue);

        //部门领导
        if(query.value(1).toString() == "待处理")
        {
            item2->setTextColor(Qt::blue);
        }
        if(query.value(1).toString() == "同意")
        {
            item2->setTextColor(Qt::darkGreen);
        }
        if(query.value(1).toString() == "驳回")
        {
            item2->setTextColor(Qt::darkYellow);
        }
        if(query.value(1).toString() == "不同意")
        {
            item2->setTextColor(Qt::red);
        }
        //总经理
        if(query.value(2).toString() == "待处理")
        {
            item3->setTextColor(Qt::blue);
        }
        if(query.value(2).toString() == "同意")
        {
            item3->setTextColor(Qt::darkGreen);
        }
        if(query.value(2).toString() == "驳回")
        {
            item3->setTextColor(Qt::darkYellow);
        }
        if(query.value(2).toString() == "不同意")
        {
            item3->setTextColor(Qt::red);
        }
        //考勤员
        item4->setText(query.value(3).toString());
        if(query.value(3).toString() == "待处理")
        {
            item4->setTextColor(Qt::blue);
        }
        if(query.value(3).toString() == "同意")
        {
            item4->setTextColor(Qt::darkGreen);
        }
        if(query.value(3).toString() == "驳回")
        {
            item4->setTextColor(Qt::darkYellow);
        }
        if(query.value(3).toString() == "不同意")
        {
            item4->setTextColor(Qt::red);
        }

        ui->tableWidget->setItem(i,0,item0);
        ui->tableWidget->setItem(i,1,item1);
        ui->tableWidget->setItem(i,2,item2);
        ui->tableWidget->setItem(i,3,item3);
        ui->tableWidget->setItem(i,4,item4);
        ui->tableWidget->setItem(i,5,item5);
    }
}

void Widget::on_pushButton_waiChu_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList header;
    header << "电子流类型" << "提交时间" << "部门领导" << "考勤员"<<"查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    QSqlQuery query;

    if(!query.exec(tr("select dealTime,leaderResult,clerkResult from waichu where staffid = '%1' order by dealtime desc")
                   .arg(LoginWindow::staffID)))
    {
        qDebug() << "Sql Error:" << query.lastError().text();
        return;
    }
    ui->tableWidget->setRowCount(query.size());
    for(int i = 0; i < query.size(); i++)
    {
        query.next();

        QTableWidgetItem * item0 = new QTableWidgetItem("外出");
        QTableWidgetItem * item1 = new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem * item2 = new QTableWidgetItem(query.value(1).toString());//部门领导
        QTableWidgetItem * item4 = new QTableWidgetItem(query.value(2).toString());//考勤员
        QTableWidgetItem * item5 = new QTableWidgetItem("点击查看");
        item5->setToolTip("点击查看");
        item0->setTextAlignment(Qt::AlignCenter);
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        item5->setTextAlignment(Qt::AlignCenter);
        item5->setBackgroundColor(QColor(235,235,235));
        item5->setTextColor(Qt::blue);

        //部门领导
        if(query.value(1).toString() == "待处理")
        {
            item2->setTextColor(Qt::blue);
        }
        if(query.value(1).toString() == "同意")
        {
            item2->setTextColor(Qt::darkGreen);
        }
        if(query.value(1).toString() == "驳回")
        {
            item2->setTextColor(Qt::darkYellow);
        }
        if(query.value(1).toString() == "不同意")
        {
            item2->setTextColor(Qt::red);
        }
        //考勤员
        item4->setText(query.value(2).toString());
        if(query.value(2).toString() == "待处理")
        {
            item4->setTextColor(Qt::blue);
        }
        if(query.value(2).toString() == "同意")
        {
            item4->setTextColor(Qt::darkGreen);
        }
        if(query.value(2).toString() == "驳回")
        {
            item4->setTextColor(Qt::darkYellow);
        }
        if(query.value(2).toString() == "不同意")
        {
            item4->setTextColor(Qt::red);
        }

        ui->tableWidget->setItem(i,0,item0);
        ui->tableWidget->setItem(i,1,item1);
        ui->tableWidget->setItem(i,2,item2);
        ui->tableWidget->setItem(i,3,item4);
        ui->tableWidget->setItem(i,4,item5);
    }
}
//
void Widget::uiInit(QWidget * ui,const QString titleName)
{
    ui->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(ui->size(),Qt::IgnoreAspectRatio)));
    ui->setPalette(palette);
    ui->setWindowTitle(titleName);
}
//
void Widget::serverListenInit()
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::AnyIPv4,serverPort);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}
//
void Widget::acceptConnection()
{
    QTcpSocket * tempSocket = tcpServer->nextPendingConnection();
    TcpDealThread * listen = new TcpDealThread(tempSocket);
    QThread * thread = new QThread(this);
    listen->moveToThread(thread);
    thread->start();
}


void Widget::on_pushButton_email_clicked()
{
    EmailFrame * email = new EmailFrame();
    connect(email,SIGNAL(sendToWidgetToCheckIfHaveEmailToRead()),this,SLOT(checkIfHaveNotReadEmails()));
    email->show();
}

void Widget::on_pushButton_leaveMsg_clicked()
{
    LeaveMsg * leaveMsg = new LeaveMsg;
    leaveMsg->show();
}
//
void Widget::checkIfHaveNotReadEmails()
{
    QSqlQuery query;
    if(query.exec(tr("select * from emailfiles where receiver like '%1%' and state ='未读' and deleteUsers not like '%%2%'").arg(LoginWindow::staffID)
                  .arg(LoginWindow::staffID)))
    {
        if(query.size())
        {
            ui->pushButton_email->setStyleSheet("QPushButton{border-image: url(:/images/EmailImage/Email_email.png);}"
                                                "QPushButton:hover{border-image: url(:/images/EmailImage/Email_hover_email.png);}");
            showUdpTipMsgDialog * tipDialog = new showUdpTipMsgDialog("您有新的邮件！");
            connect(tipDialog,SIGNAL(emitShowWidgetSig(QString)),this,SLOT(showWidgetSlot(QString)));
            tipDialog->show();
        }
        else
        {
            ui->pushButton_email->setStyleSheet("QPushButton{border-image: url(:/images/EmailImage/Email.png);}"
                                                "QPushButton:hover{border-image: url(:/images/EmailImage/Email_hover.png);}");
        }
    }
}

void Widget::on_pushButton_haveFun_clicked()
{
    MimeGame * mimegame = new MimeGame();
    mimegame->show();
}

void Widget::on_pushButton_setting_clicked()
{
    OASettingForm * setting = new OASettingForm;
    setting->show();
}

void Widget::initOASetting()
{
    if(QFile::exists(qApp->applicationDirPath()+"/OASetting.dat"))
    {
        QFile file(qApp->applicationDirPath()+"/OASetting.dat");
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray line;
            line = file.readLine();
            sqlIP = line.replace("\n","");

            line = file.readLine();
            sqlPort = line.replace("\n","").toInt();

            line = file.readLine();
            sqlUserName = line.replace("\n","");

            line = file.readLine();
            sqlPassword = line.replace("\n","");

            line = file.readLine();
            sqlBaseName = line.replace("\n","");

            line = file.readLine();
            serverIP = line.replace("\n","");

            line = file.readLine();
            serverPort= line.replace("\n","").toInt();
        }
    }
}
