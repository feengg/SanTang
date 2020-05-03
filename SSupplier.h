//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SSupplier.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-10
// Description		: ��������Ϣ
// History			:
//******************************************************************************
#pragma once
#ifndef __SSUPPLIER_H__
#define __SSUPPLIER_H__

#include <QString>
struct SSupplier
{
    QString id;             // ��Ӧ��ID
    QString companyname;    // ��Ӧ�̹�˾����
    QString contact;        // ��ϵ��
    QString tel;            // �����̵绰
    QString wechat;         // ΢���ʺ�
    QString qq;             // QQ�ʺ�
    QString address;        // �����̵�ַ
    QString remarks;        // ��ע
};

#endif // __SSUPPLIER_H__