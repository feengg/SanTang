//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SSupItemInfo.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-10
// Description		: ������ϸ
// History			:
//******************************************************************************
#pragma once
#ifndef __SSUPITEMINFO_H__
#define __SSUPITEMINFO_H__
#include <QString>

struct SSupItemInfo
{
    int miOrderID;          // �����������
    int miMaterialType;     // �Ĳ�����
    int miNumber;           // ����
    double mdWidth;         // ���
    double mdHeight;        // �߶�
    double mdThickNess;     // ���
    double mdArea;          // ���
    double miUnitPrice;     // ����
    double mdPrice;         // ���
    QString msProjectName;  // ��Ŀ����
    QString msContents;     // ��������
    QString msRemarks;      // ��ע
};

#endif // __SSUPITEMINFO_H__

