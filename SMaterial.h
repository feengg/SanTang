//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SMaterial.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-10
// Description		: �Ĳ�����
// History			:
//******************************************************************************
#pragma once
#ifndef __SMATERIAL_H__
#define __SMATERIAL_H__

#include <QString>

struct SMaterial
{
    int miMaterialId;           // ���ϱ���ID
    int miUniteID;              // ������λID
    double mdPrice;             // ���ϱ���
    QString msMaterialName;     // ������
    QString msPinYinMa;         // ƴ����
};
#endif // __SMATERIAL_H__
