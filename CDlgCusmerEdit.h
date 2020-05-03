//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgCusmerEdit.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-19
// Description		: 客户和供货商窗口
// History			:
//******************************************************************************
#pragma once

#include <QWidget>
#include "ui_CDlgCusmerEdit.h"
#include "Global.h"
#include "CSQLDatabase.h"

class CDlgCusmerEdit : public QWidget
{
    Q_OBJECT

public:
    CDlgCusmerEdit(QWidget *parent = Q_NULLPTR);
    ~CDlgCusmerEdit();

    // 设置table类型
    void mvSetTabType(TTabType eTabType);

private:
    // 初始化客户信息标题
    void mvInitCusmerTabTitle();
private slots:
    // 初始化增加
    void mslotAddCusmerInfo();

private:
    Ui::CDlgCusmerEdit ui;
    TTabType meTabType;          // table类型
};
