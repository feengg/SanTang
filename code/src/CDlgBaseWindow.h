//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgBaseWindow.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CDlgBaseWindow¿‡
// History			:
//******************************************************************************

#ifndef __CDLGBASEWINDOW_H__
#define __CDLGBASEWINDOW_H__

#include "CDlgTitleBar.h"
#include <QDialog>

class CDlgBaseWindow : public QDialog
{
    Q_OBJECT

public:
    CDlgBaseWindow(QWidget *parent = 0);
    ~CDlgBaseWindow();

protected:
    void mvInitTitleBar();
    void mvPaintEvent(QPaintEvent *event);
    void mvLoadStyleSheet(const QString &sheetName);

private slots:
    void msotOnBtnMinClicked();
    void mslotOnBtnRestoreClicked();
    void mslotOnBtnMaxClicked();
    void mslotOnBtnCloseClicked();

protected:
    CDlgTitleBar* mopTitleBar;

};

#endif // __CDLGBASEWINDOW_H__