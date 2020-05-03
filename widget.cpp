#include "widget.h"
#include "ui_widget.h"
#include <QSettings>
#include <windows.h>
#include <QProcess>
#include "loginwindow.h"
#include <QSettings>


using namespace  std;

QString Widget::serverIP = "192.168.1.44";
int Widget::serverPort = 4513;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowFlags(Qt::FramelessWindowHint);  //设置无边框
    this->setWindowTitle("TITLE");
    QDesktopWidget * desktop = QApplication::desktop();
    maxWidth = desktop->screenGeometry().width() * 57 / 100;
    maxHeight = desktop->screenGeometry().height() * 78 / 100;
    qDebug() << "width=" << maxWidth << ";" << maxHeight;
    this->resize(1094, 842);
    //设置背景图片
    this->autoFillBackground();
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap("F:\\Temp\\ERP\\ERP\\images\\mainboard.png").scaled(this->size(), Qt::IgnoreAspectRatio)));
    this->setPalette(palette);                                      
    //
    //设置title

    connect(ui->pushButton_min, SIGNAL(clicked()), this, SLOT(on_minBtn_clicked()));
    connect(ui->pushButton_max, SIGNAL(clicked()), this, SLOT(on_maxBtn_clicked()));
    connect(ui->pushButton_close, SIGNAL(clicked()), this, SLOT(on_closeBtn_clicked()));
    //添加工具栏

    ui->toolButton_newStream->resize(30, 34);

    ui->toolButton_newStream->setCursor(Qt::PointingHandCursor);
    ui->toolButton_newStream->show();
    //左1 加班

    ui->toolBtn_jb->resize(170, 35);

    ui->toolBtn_jb->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_qj->resize(170, 35);

    ui->toolBtn_qj->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_wdk->resize(170, 35);

    ui->toolBtn_wdk->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_cg->resize(170, 35);

    ui->toolBtn_cg->setCursor(Qt::PointingHandCursor);


    //右1，待处理
    //toolBtn_dcl = new QToolButton(this);
    ui->toolBtn_dcl->resize(65, 75);

    ui->toolBtn_dcl->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_kqhz->resize(65, 75);

    ui->toolBtn_kqhz->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_cgjh->resize(65, 75);

    ui->toolBtn_cgjh->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_spkc->resize(65, 75);

    ui->toolBtn_spkc->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_ygsz->resize(65, 75);

    ui->toolBtn_ygsz->setCursor(Qt::PointingHandCursor);

    ui->toolBtn_tybh->resize(65, 75);

    ui->toolBtn_tybh->setCursor(Qt::PointingHandCursor);

    connect(ui->toolButton_newStream, SIGNAL(clicked()), this, SLOT(toolButton_newStream_clicked()));
    connect(ui->toolBtn_jb, SIGNAL(clicked()), this, SLOT(on_toolBtn_jb_clicked()));
    connect(ui->toolBtn_qj, SIGNAL(clicked()), this, SLOT(on_toolBtn_qj_clicked()));
    connect(ui->toolBtn_wdk, SIGNAL(clicked()), this, SLOT(on_toolBtn_wdk_clicked()));
    connect(ui->toolBtn_cg, SIGNAL(clicked()), this, SLOT(on_toolBtn_cg_clicked()));


    connect(ui->toolBtn_dcl, SIGNAL(clicked()), this, SLOT(on_toolBtn_dcl_clicked()));
    connect(ui->toolBtn_kqhz, SIGNAL(clicked()), this, SLOT(toolBtn_kqhz_clicked()));
    connect(ui->toolBtn_cgjh, SIGNAL(clicked()), this, SLOT(toolBtn_cgjh_clicked()));
    connect(ui->toolBtn_spkc, SIGNAL(clicked()), this, SLOT(toolBtn_spkc_clicked()));
    connect(ui->toolBtn_ygsz, SIGNAL(clicked()), this, SLOT(toolBtn_ygsz_clicked()));
    connect(ui->toolBtn_tybh, SIGNAL(clicked()), this, SLOT(toolBtn_tybh_clicked()));

    //初始化显示tabelWidget
    showStreamListSlot("加班");
    //初始化托盘对象
    myTray = 0;
    myTray->deleteLater();
    //udp绑定自己IP

    //tabelWidget点击信号
    connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(clickedToShowSlot(int, int)));

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止双击编辑

    //判断是否有待处理的电子流，并通知
    on_toolBtn_dcl_clicked();
    int rownum = ui->tableWidget->rowCount();
    qDebug() << "rownum=" << rownum;

    qDebug() << "here555";
    //验证ip地址
    if (!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    //获取本机本地ip地址

    //QHostInfo info = QHostInfo::fromName(localHostName);
    QString localIP = NULL;
    qDebug() << "here556";

    //设置定时器关闭logWindow
    closeTimer = new QTimer;
    closeTimer->setInterval(40);
    connect(closeTimer, SIGNAL(timeout()), this, SLOT(emitCloseSigToLogW()));
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
    //qDebug() << "here555";
    //startSelfAction = new QAction("开机自启动",this);
    //if(QFile::exists(qApp->applicationDirPath() + "/autoRun.dat"))
    //{
    //    QFile file(qApp->applicationDirPath() + "/autoRun.dat");
    //    file.open(QIODevice::ReadOnly);
    //    QByteArray autoRunFlag = NULL;
    //    autoRunFlag = file.readLine();
    //    autoRunFlag.replace("\n","");
    //    qDebug() << "autoFlag = "  << autoRunFlag;
    //    if(autoRunFlag == "true")
    //    {
    //        qDebug() << "enter here";
    //        //startSelfAction->setIcon(QIcon(":/images/自启动.png"));
    //        QString appName = QApplication::applicationName();
    //        QString appPath = QApplication::applicationFilePath();
    //        appPath = appPath.replace("/","\\");
    //        QSettings * reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
    //        QString val = reg->value(appName).toString();
    //        qDebug() << val;
    //        if(val != appPath)
    //        {
    //            qDebug() << "1";
    //            reg->setValue(appName,appPath);
    //            //startSelfAction->setIcon(QIcon(":/images/自启动.png"));
    //            QFile file(qApp->applicationDirPath() + "/autoRun.dat");
    //            file.open(QIODevice::WriteOnly | QIODevice::Append);
    //            file.reset();
    //            file.write("true\n");
    //            file.close();
    //        }
    //    }
    //}
    //else
    //{
    //    QString appName = QApplication::applicationName();
    //    QString appPath = QApplication::applicationFilePath();
    //    appPath = appPath.replace("/","\\");
    //    QSettings * reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
    //    QString val = reg->value(appName).toString();
    //    qDebug() << val;
    //    if(val != appPath)
    //    {
    //        qDebug() << "1";
    //        reg->setValue(appName,appPath);
    //        //startSelfAction->setIcon(QIcon(":/images/自启动.png"));
    //        QFile file(qApp->applicationDirPath() + "/autoRun.dat");
    //        file.open(QIODevice::WriteOnly | QIODevice::Append);
    //        file.reset();
    //        file.write("true\n");
    //        file.close();
    //    }
    //}
    ////初始退出自启动按钮
    //if(QFile::exists(qApp->applicationDirPath() + "/account.dat"))
    //{
    //    QFile file(qApp->applicationDirPath() + "/account.dat");
    //    file.open(QIODevice::ReadOnly);
    //    QByteArray rememberPswFlag = NULL;
    //    QByteArray autoLoginFlag = NULL;
    //    rememberPswFlag = file.readLine();
    //    autoLoginFlag = file.readLine();
    //    if(autoLoginFlag == "true\n")
    //    {
    //        ui->pushButton_quitAutoRun->show();
    //    }else{
    //        ui->pushButton_quitAutoRun->hide();
    //    }
    //}
    //
    ui->label_userName->setText(LoginWindow::userName);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //
    if (!myTray)
    {

        myTray = new QSystemTrayIcon(this);
        QIcon icon = QIcon(":/images/OA_Logo.ico");
        myTray->setIcon(icon);
        myTray->setToolTip("正博OA");
        myTray->show();
        connect(myTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_activatedSystemTrayIcon(QSystemTrayIcon::ActivationReason)));
        //建立托盘操作的菜单
        //showMainAction = new QAction("显示主界面",this);
        //exitAppAction = new QAction("退出",this);
        //autoUpdateAction = new QAction("一键自动更新",this);
        //aboutOAAction = new QAction("关于正博OA",this);



        //connect(showMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));
        //connect(exitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));
        //connect(startSelfAction,SIGNAL(triggered()),this,SLOT(on_startSelfAction()));
        //connect(autoUpdateAction,SIGNAL(triggered()),this,SLOT(on_autoUpdateAction()));
        //connect(aboutOAAction,SIGNAL(triggered()),this,SLOT(on_aboutOAAction()));

        //myMenu = new QMenu(this);
        //myMenu->addAction(showMainAction);
        //myMenu->addSeparator();
        //myMenu->addAction(startSelfAction);
        //myMenu->addSeparator();
        //myMenu->addAction(autoUpdateAction);
        //myMenu->addSeparator();
        //myMenu->addAction(aboutOAAction);
        //myMenu->addSeparator();
        //myMenu->addAction(exitAppAction);
        //myTray->setContextMenu(myMenu);
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

Widget::~Widget()
{
    myTray->deleteLater();
    //udpSocket->close();
    delete ui;
}

void Widget::initOASetting()
{

}

//设置参数
QString Widget::sqlIP = "192.168.1.44";
int Widget::sqlPort = 3306;
QString Widget::sqlUserName = "root";
QString Widget::sqlPassword = "123456";
QString Widget::sqlBaseName = "mySql5.6";

void Widget::on_minBtn_clicked()
{

}

void Widget::on_maxBtn_clicked()
{

}

void Widget::on_closeBtn_clicked()
{

}

void Widget::on_toolBtn_jb_clicked()
{

}

void Widget::on_toolBtn_qj_clicked()
{

}

void Widget::on_toolBtn_wdk_clicked()
{

}

void Widget::on_toolBtn_cg_clicked()
{

}

void Widget::on_toolBtn_dcl_clicked()
{

}

void Widget::toolBtn_kqhz_clicked()
{

}

void Widget::toolBtn_cgjh_clicked()
{

}

void Widget::toolBtn_spkc_clicked()
{

}

void Widget::toolBtn_ygsz_clicked()
{

}

void Widget::toolBtn_tybh_clicked()
{

}

void Widget::on_toolButton_myStream_clicked()
{

}

void Widget::toolButton_newStream_clicked()
{

}

void Widget::showStreamListSlot(QString type)
{

}

void Widget::on_activatedSystemTrayIcon(QSystemTrayIcon::ActivationReason reason)
{

}

void Widget::on_showMainAction()
{

}

void Widget::on_exitAppAction()
{

}

void Widget::on_startSelfAction()
{

}

void Widget::on_aboutOAAction()
{

}

void Widget::on_autoUpdateAction(bool startCheckFlag /*= false*/)
{

}

void Widget::recvTipUdpMsgSlot()
{

}

void Widget::showWidgetSlot(QString tipMsg /*= NULL*/)
{

}

void Widget::clickedToShowSlot(int x, int y)
{

}

void Widget::emitCloseSigToLogW()
{

}

void Widget::on_pushButton_quitAutoRun_clicked()
{

}

void Widget::on_pushButton_help_clicked()
{

}

void Widget::on_toolButton_daka_clicked()
{

}

void Widget::on_toolButton_weekReport_clicked()
{

}

void Widget::on_pushButton_chuChai_clicked()
{

}

void Widget::on_pushButton_waiChu_clicked()
{

}

void Widget::acceptConnection()
{

}

void Widget::on_pushButton_email_clicked()
{

}

void Widget::on_pushButton_leaveMsg_clicked()
{

}

void Widget::checkIfHaveNotReadEmails()
{

}

void Widget::on_pushButton_haveFun_clicked()
{

}

void Widget::on_pushButton_setting_clicked()
{

}



void Widget::mousePressEvent(QMouseEvent * event)
{

}

void Widget::mouseMoveEvent(QMouseEvent * event)
{

}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{

}

bool Widget::openMySql()
{
    return true;
}

bool Widget::saveDaKaRecordToSql()
{
    return true;
}

int Widget::getDayOfWeek(QString)
{
    return 0;
}

void Widget::uiInit(QWidget *, const QString)
{

}

void Widget::serverListenInit()
{

}

