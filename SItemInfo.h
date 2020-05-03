//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SItemInfo.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: ������ϸ
// History			:
//******************************************************************************
#pragma once
#ifndef __SITEMINFO_H__
#define __SITEMINFO_H__
#include <QString>
struct SItemInfo
{
    int miItemID;           // ������ϸID
    int miOrderID;          // ����ID
    int miMaterialID;       // �Ĳ�ID
    int miProjectID;        // ��ĿID
    int miNumber;           // ����
    double mdWidth;         // ���
    double mdHeight;        // �߶�
    double mdArea;          // ���
    double miUnitPrice;     // ����
    double mdPrice;         // ���
    QString msContents;     // ��������
    QString msRemarks;      // ��ע
};



#endif // __SITEMINFO_H__

