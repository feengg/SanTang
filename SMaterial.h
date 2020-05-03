//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SMaterial.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-10
// Description		: 耗材类型
// History			:
//******************************************************************************
#pragma once
#ifndef __SMATERIAL_H__
#define __SMATERIAL_H__

#include <QString>

struct SMaterial
{
    int miMaterialId;           // 材料编码ID
    int miUniteID;              // 计量单位ID
    double mdPrice;             // 材料报价
    QString msMaterialName;     // 材料名
    QString msPinYinMa;         // 拼音码
};
#endif // __SMATERIAL_H__
