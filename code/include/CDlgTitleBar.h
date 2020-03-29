//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CTitleBar.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CTitleBar��
// History			:
//******************************************************************************
#ifndef __CTITLEBAR_H__
#define __CTITLEBAR_H__

#include "Global.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

enum eBtnType
{
    eMin_Button,        // ��С���͹رհ�ť��
    eMin_Max_Button,    // ��С������󻯺͹رհ�ť��
    eOnly_Close_Button  // ֻ�йرհ�ť

};

class CDlgTitleBar : public QWidget
{
    Q_OBJECT

public:
    CDlgTitleBar(QWidget *parent = NULL);
    ~CDlgTitleBar();

    // ���ñ���������ɫ;
    void mvSetBackGrdColr(int iR, int iG, int iB, bool isTransparent = false);

    // ���ñ�����ͼ��;
    void mvSetTitleIcon(QString filePath);

    // ���ñ�������;
    void mvSetTitleContent(QString titleContent, int titleFontSize = 9);

    // ���ñ���������;
    void mvSetTitleWidth(int width);

    // ���ñ������ϰ�ť����;
    void mvSetButtonType(eBtnType buttonType);

    // ���ñ������еı����Ƿ�����;������Կ�Ч��;
    void mvSetTitleRoll();

    // ���ô��ڱ߿���;
    void mvSetWindowBorderWidth(int borderWidth);

    // ����/��ȡ ���ǰ���ڵ�λ�ü���С;
    void mvSaveRestoreInfo(const QPoint point, const QSize size);
    void mvGetRestoreInfo(QPoint& point, QSize& size);

private:

    // �¼�
    void mvPaintEvent(QPaintEvent *event);

    // ˫���¼�
    void mvDoubleClickEvent(QMouseEvent *event);

    // ��ѹ�¼�
    void mvPressEvent(QMouseEvent *event);

    // �ƶ��¼�
    void mvMoveEvent(QMouseEvent *event);

    // �ͷ�
    void mvReleaseEvent(QMouseEvent *event);

    // ��ʼ���ؼ�;
    void mvInitControl();

    // �źŲ۵İ�;
    void mvInitConn();

    // ������ʽ�ļ�;
    void mvLoadStyleSheet(const QString &sheetName);

signals:
    // ��ť�������ź�;
    void msigBtnMinClicked();
    void msigBtnRestorClicked();
    void msigBtnMaxClicked();
    void msigBtnCloseClicked();

private slots:
    // ��ť�����Ĳ�;
    void mslotOnBtnMinClicked();
    void mslotOnBtnRestoreClicked();
    void mslotOnBtnMaxClicked();
    void mslotOnBtnCloseClicked();
    void mslotOnRollTitle();

private:
    QLabel* mopLabIcon;             // ������ͼ��;
    QLabel* mopLabTitleCont;        // ����������;
    QPushButton* mopBtnMin;         // ��С����ť;
    QPushButton* mopBtnRestore;     // ��󻯻�ԭ��ť;
    QPushButton* mopBtnMax;         // ��󻯰�ť;
    QPushButton* mopBtnClose;       // �رհ�ť;

    // ����������ɫ;
    int miR;
    int miG;
    int miB;


    // ��󻯣���С������;
    QPoint moRestorePos;
    QSize moRestoreSize;
    
    // �ƶ����ڵı���;
    bool mbIsPressed;
    QPoint moStartMovePos;

    // �����������Ч��ʱ��;
    QTimer moTitleRollTimer;

    // ����������;
    QString msTitleContent;

    // ��ť����;
    eBtnType meBtnType;

    // ���ڱ߿���;
    int miWindowBorderWidth;

    // �������Ƿ�͸��;
    bool mbIsTransparent;
};

#endif // __CTITLEBAR_H__
