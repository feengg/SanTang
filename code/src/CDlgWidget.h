//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgWidget.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-30
// Description		: CDlgWidget类
// History			:
//******************************************************************************
#ifndef __CDLGWIDGET_H__
#define __CDLGWIDGET_H__

#include <QWidget>
#include <QDesktopWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QToolButton>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QDebug>
#include <QSystemTrayIcon>
#include "CDlgLoginWindow.h"
#include <QMessageBox>
#include <QDate>
#include <QThread>
#include <QStandardItemModel>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    //void paintEvent(QPaintEvent * event);
    static bool openMySql();
    //  考勤记录
    bool saveDaKaRecordToSql();
    int getDayOfWeek(QString);
    static void uiInit(QWidget *, const QString);
    //服务器监听
    void serverListenInit();
    //文件上传下载服务器IP地址
    static QString serverIP;
    static int serverPort;

    static void initOASetting();
    //设置参数
    static QString sqlIP;
    static int sqlPort;
    static QString sqlUserName;
    static QString sqlPassword;
    static QString sqlBaseName;

private:
    Ui::Widget *ui;
    int maxWidth;
    int maxHeight;
    bool dragWindow;
    QPoint position;
    QLabel * labelMyStream;
    QLabel * labelNewMyStream;
    //    //左
    //    QToolButton * toolBtn_jb;
    //    QToolButton * toolBtn_qj;
    //    QToolButton * toolBtn_wdk;
    //    QToolButton * toolBtn_cg;

    //    //右
    //    QToolButton * toolBtn_dcl;
    //    QToolButton * toolBtn_kqhz;
    //    QToolButton * toolBtn_cgjh;
    //    QToolButton * toolBtn_spkc;
    //    QToolButton * toolBtn_ygsz;
    //    QToolButton * toolBtn_tybh;

    bool leftBtn1ClickFlag = false;
    bool leftBtn2ClickFlag = false;
    bool leftBtn3ClickFlag = false;
    bool leftBtn4ClickFlag = false;
    bool leftBtn5ClickFlag = false;

    //程序托盘
    QSystemTrayIcon * myTray;
    QMenu *myMenu;
    QAction * showMainAction;
    QAction * exitAppAction;
    QAction * startSelfAction;
    QAction * autoUpdateAction;
    QAction * aboutOAAction;

    //判断有没有设置自启动flag
    bool isStartBySelfFlag = true;

    QUdpSocket * udpSocket;
    QTimer * closeTimer;
    //服务器
    QTcpServer * tcpServer;



signals:
    void emitCloseLogWidgetSig();

private slots:
    void on_minBtn_clicked();

    void on_maxBtn_clicked();

    void on_closeBtn_clicked();

    void on_toolBtn_jb_clicked();

    void on_toolBtn_qj_clicked();

    void on_toolBtn_wdk_clicked();

    void on_toolBtn_cg_clicked();



    void on_toolBtn_dcl_clicked();

    void toolBtn_kqhz_clicked();

    void toolBtn_cgjh_clicked();

    void toolBtn_spkc_clicked();

    void toolBtn_ygsz_clicked();

    void toolBtn_tybh_clicked();

    void on_toolButton_myStream_clicked();

    void toolButton_newStream_clicked();

    void showStreamListSlot(QString type);//刷新TabelWidget槽
    //托盘相关槽
    void on_activatedSystemTrayIcon(QSystemTrayIcon::ActivationReason reason);

    void on_showMainAction();

    void on_exitAppAction();

    void on_startSelfAction();

    void on_aboutOAAction();

    void on_autoUpdateAction(bool startCheckFlag = false);
    //

    void recvTipUdpMsgSlot();

    void showWidgetSlot(QString tipMsg = NULL);//点击右下角提示消息后收到显示主窗体的槽

    //当移动到点击查看，字体变色槽
    void clickedToShowSlot(int x, int y);

    void emitCloseSigToLogW();
    void on_pushButton_quitAutoRun_clicked();
    void on_pushButton_help_clicked();



    void on_toolButton_daka_clicked();
    void on_toolButton_weekReport_clicked();

    void on_pushButton_chuChai_clicked();
    void on_pushButton_waiChu_clicked();
    //监听连接slot
    void acceptConnection();

    void on_pushButton_email_clicked();
    void on_pushButton_leaveMsg_clicked();
    //check if have emails that dont read
    void checkIfHaveNotReadEmails();
    void on_pushButton_haveFun_clicked();
    void on_pushButton_setting_clicked();
};


//自定义ToolButton
//class MyToolButton : public QToolButton
//{

//public:
//    MyToolButton(QWidget *parent = Q_NULLPTR) : QToolButton(parent){}
//    void enterEvent(QEvent *);
//    void leaveEvent(QEvent *);
//};

#endif // __CDLGWIDGET_H__
