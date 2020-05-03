//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgCusmerEdit.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-19
// Description		: �ͻ��͹����̴���
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

    // ����table����
    void mvSetTabType(TTabType eTabType);

private:
    // ��ʼ���ͻ���Ϣ����
    void mvInitCusmerTabTitle();
private slots:
    // ��ʼ������
    void mslotAddCusmerInfo();

private:
    Ui::CDlgCusmerEdit ui;
    TTabType meTabType;          // table����
};
