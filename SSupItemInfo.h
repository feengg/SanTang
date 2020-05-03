//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SSupItemInfo.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-10
// Description		: 供货明细
// History			:
//******************************************************************************
#pragma once
#ifndef __SSUPITEMINFO_H__
#define __SSUPITEMINFO_H__
#include <QString>

struct SSupItemInfo
{
    int miOrderID;          // 供货订单编号
    int miMaterialType;     // 耗材类型
    int miNumber;           // 数量
    double mdWidth;         // 宽度
    double mdHeight;        // 高度
    double mdThickNess;     // 宽度
    double mdArea;          // 面积
    double miUnitPrice;     // 单价
    double mdPrice;         // 金额
    QString msProjectName;  // 项目名称
    QString msContents;     // 制作内容
    QString msRemarks;      // 备注
};

#endif // __SSUPITEMINFO_H__

