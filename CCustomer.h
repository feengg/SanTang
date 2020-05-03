#pragma once
//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CCustomer.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-06
// Description		: �ͻ���
// History			:
//******************************************************************************

#ifndef __CCUSTOMER_H__
#define __CCUSTOMER_H__
#include <QString>

class CCustomer
{
public:
    CCustomer();
    CCustomer(const QString& sName, const QString& sTelNum, const QString& sAddress);
    ~CCustomer();

public:
    QString msGetName() { return msName; }
    QString msGetTelNum() { return msTelNum; }
    QString msGetAddress() { return msAddress; }

    void mvSetName(const QString& sName) { msName = sName; }
    void mvSetTelNum(const QString& sTelNum) { msTelNum = sTelNum; }
    void mvSetAddress(const QString& sAddress) { msAddress = sAddress; }

private:
    QString msName;             // �ͻ�����
    QString msTelNum;           // �ͻ��绰
    QString msAddress;          // �ͻ���ַ
};

#endif // __CCUSTOMER_H__


