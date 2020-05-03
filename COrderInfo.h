#pragma once
//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CItem.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-06
// Description		: CItem��
// History			:
//******************************************************************************

#ifndef __CITEM_H__
#define __CITEM_H__

#include <QString>


class COrderInfo
{
public:
    COrderInfo();
    ~COrderInfo();

private:

    int miMaterialType;     // �Ĳ�����
    int miNumber;           // ����
    double mdWidth;         // ���
    double mdHeight;        // �߶�
    double mdArea;          // ���
    double miUnitPrice;     // ����
    double mdTotalPrice;    // �ܼ�
    QString msProjectName;  // ��Ŀ����
    QString msContents;     // ��������
    QString msRemarks;      // ��ע

};

#endif // __CITEM_H__



