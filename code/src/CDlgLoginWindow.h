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

class CDlgLoginWindow : public CDlgBaseWindow
{
    Q_OBJECT

public:
    CDlgLoginWindow(QWidget *parent = 0);
    ~CDlgLoginWindow();

    // �ƶ�ʵ�ֺ���
    void mvMousePressEvent(QMouseEvent * event);
    void mvMouseMoveEvent(QMouseEvent * event);
    void mvMouseReleaseEvent(QMouseEvent *event);

public:
    static QString msUserName;                  // �û���
    static QString msStaffID;                   // Ա��ID
    static QString msIpAddr;                    // IP��ַ
    static QString msVersion;                   // �汾
    static QString msPassWord;                  // ����
    static int miUserLevel;                     // �ȼ�
private slots:

    // ��ʾС����
    void mslotShowMinKeyBoard();

    // ��ʾ��������
    void mslotDisplayInputContent(QString text);

    // ������ʾ
    void mslotOnBtnFlickerClicked();

    // �����¼
    void mslotOnBtnLoginClicked();

    // ��������
    void mslotOnBtnForgetPasswordClicked();

    // �յ��رմ��ڲ�
    void mslotGetCloseSlot();

    // ���ð�ť
    void mslotOnBtnSettingClicked();

private:
    void mvInitTitle();
    void mvInitWindow();
    bool mbCloseFlag = false;


private:
    Ui::LoginWindow *ui;
    // �����С���̰�ť;
    QPushButton* mopBtnKeyboard;
    bool dragWindow;
    QPoint moPosition;

    // QByteArray msStaffID = NULL;

};



#endif // __CDLGLOGINWINDOW_H__
