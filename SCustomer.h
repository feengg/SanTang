//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SCustomer.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: �ͻ��ṹ��
// History			:
//******************************************************************************
#pragma once
#ifndef __SCUSTOMER_H__
#define __SCUSTOMER_H__
#include <QString>
struct SCustomer
{
    QString id;                 // �ͻ�ID
    QString companyname;        // �ͻ���˾��
    QString contact;            // �ͻ�����
    QString tel;                // �ͻ��绰
    QString wechat;             // ΢���ʺ�
    QString qq;                 // QQ�ʺ�
    QString address;            // �ͻ���ַ
    QString remarks;            // ��ע
};

#endif // __SCUSTOMER_H__
