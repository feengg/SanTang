//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgLoginWindow.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: 登录窗口
// History			:
//******************************************************************************
#ifndef __CDLGLOGINWINDOW_H__
#define __CDLGLOGINWINDOW_H__


#include "CDlgBaseWindow.h"
#include <QWidget>
#include <QMouseEvent>

namespace Ui {
    class LoginWindow;
}

// 登录状态;
typedef enum
{
    ONLINE = 1,     //在线;
    ACTIVE,			//活跃;
    AWAY,           //离开;
    BUSY,           //忙碌;
    NOT_DISTURB,	//请勿打扰;
    HIDE,           //隐身;
    OFFLINE			//离线;
}LoginState;

class CDlgLoginWindow : public CDlgBaseWindow
{
    Q_OBJECT

public:
    CDlgLoginWindow(QWidget *parent = 0);
    ~CDlgLoginWindow();

    // 移动实现函数
    void mvMousePressEvent(QMouseEvent * event);
    void mvMouseMoveEvent(QMouseEvent * event);
    void mvMouseReleaseEvent(QMouseEvent *event);

public:
    static QString msUserName;                  // 用户名
    static QString msStaffID;                   // 员工ID
    static QString msIpAddr;                    // IP地址
    static QString msVersion;                   // 版本
    static QString msPassWord;                  // 密码
    static int miUserLevel;                     // 等级
private slots:

    // 显示小键盘
    void mslotShowMinKeyBoard();

    // 显示输入内容
    void mslotDisplayInputContent(QString text);

    // 设置提示
    void mslotOnBtnFlickerClicked();

    // 点击登录
    void mslotOnBtnLoginClicked();

    // 忘记密码
    void mslotOnBtnForgetPasswordClicked();

    // 收到关闭窗口槽
    void mslotGetCloseSlot();

    // 设置按钮
    void mslotOnBtnSettingClicked();

private:
    void mvInitTitle();
    void mvInitWindow();
    bool mbCloseFlag = false;


private:
    Ui::LoginWindow *ui;
    // 密码框小键盘按钮;
    QPushButton* mopBtnKeyboard;
    bool dragWindow;
    QPoint moPosition;

    // QByteArray msStaffID = NULL;

};



#endif // __CDLGLOGINWINDOW_H__
