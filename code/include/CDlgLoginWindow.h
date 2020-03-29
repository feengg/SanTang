//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgLoginWindow.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: ��¼����
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

// ��¼״̬;
typedef enum
{
    ONLINE = 1,     //����;
    ACTIVE,			//��Ծ;
    AWAY,           //�뿪;
    BUSY,           //æµ;
    NOT_DISTURB,	//�������;
    HIDE,           //����;
    OFFLINE			//����;
}LoginState;

class LoginWindow : public CDlgBaseWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    static QString userName;
    static QString staffID;
    static QString myIP;
    static QString version;
    static QString myPassWord;
    static int userLevel;
private slots:
    void showMinKeyBoardSlot();

    void displayInputContent(QString text);

    void on_pButtongFlicker_clicked();

    void on_loginButton_clicked();

    void on_pButtonForgetPassword_clicked();

    void getCloseThisSlot();
    void on_pushButton_setting_clicked();

private:
    void initMyTitle();
    void initWindow();
    bool closeFlag = false;


private:
    Ui::LoginWindow *ui;
    // �����С���̰�ť;
    QPushButton* m_keyboardButton;
    bool dragWindow;
    QPoint position;

    QByteArray staffId = NULL;

};



#endif // __CDLGLOGINWINDOW_H__
