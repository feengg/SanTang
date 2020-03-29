//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CTitleBar.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CTitleBar类
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
    eMin_Button,        // 最小化和关闭按钮；
    eMin_Max_Button,    // 最小华、最大化和关闭按钮；
    eOnly_Close_Button  // 只有关闭按钮

};

class CDlgTitleBar : public QWidget
{
    Q_OBJECT

public:
    CDlgTitleBar(QWidget *parent = NULL);
    ~CDlgTitleBar();

    // 设置标题栏背景色;
    void mvSetBackGrdColr(int iR, int iG, int iB, bool isTransparent = false);

    // 设置标题栏图标;
    void mvSetTitleIcon(QString filePath);

    // 设置标题内容;
    void mvSetTitleContent(QString titleContent, int titleFontSize = 9);

    // 设置标题栏长度;
    void mvSetTitleWidth(int width);

    // 设置标题栏上按钮类型;
    void mvSetButtonType(eBtnType buttonType);

    // 设置标题栏中的标题是否会滚动;具体可以看效果;
    void mvSetTitleRoll();

    // 设置窗口边框宽度;
    void mvSetWindowBorderWidth(int borderWidth);

    // 保存/获取 最大化前窗口的位置及大小;
    void mvSaveRestoreInfo(const QPoint point, const QSize size);
    void mvGetRestoreInfo(QPoint& point, QSize& size);

private:

    // 事件
    void mvPaintEvent(QPaintEvent *event);

    // 双击事件
    void mvDoubleClickEvent(QMouseEvent *event);

    // 按压事件
    void mvPressEvent(QMouseEvent *event);

    // 移动事件
    void mvMoveEvent(QMouseEvent *event);

    // 释放
    void mvReleaseEvent(QMouseEvent *event);

    // 初始化控件;
    void mvInitControl();

    // 信号槽的绑定;
    void mvInitConn();

    // 加载样式文件;
    void mvLoadStyleSheet(const QString &sheetName);

signals:
    // 按钮触发的信号;
    void msigBtnMinClicked();
    void msigBtnRestorClicked();
    void msigBtnMaxClicked();
    void msigBtnCloseClicked();

private slots:
    // 按钮触发的槽;
    void mslotOnBtnMinClicked();
    void mslotOnBtnRestoreClicked();
    void mslotOnBtnMaxClicked();
    void mslotOnBtnCloseClicked();
    void mslotOnRollTitle();

private:
    QLabel* mopLabIcon;             // 标题栏图标;
    QLabel* mopLabTitleCont;        // 标题栏内容;
    QPushButton* mopBtnMin;         // 最小化按钮;
    QPushButton* mopBtnRestore;     // 最大化还原按钮;
    QPushButton* mopBtnMax;         // 最大化按钮;
    QPushButton* mopBtnClose;       // 关闭按钮;

    // 标题栏背景色;
    int miR;
    int miG;
    int miB;


    // 最大化，最小化变量;
    QPoint moRestorePos;
    QSize moRestoreSize;
    
    // 移动窗口的变量;
    bool mbIsPressed;
    QPoint moStartMovePos;

    // 标题栏跑马灯效果时钟;
    QTimer moTitleRollTimer;

    // 标题栏内容;
    QString msTitleContent;

    // 按钮类型;
    eBtnType meBtnType;

    // 窗口边框宽度;
    int miWindowBorderWidth;

    // 标题栏是否透明;
    bool mbIsTransparent;
};

#endif // __CTITLEBAR_H__
