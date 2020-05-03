//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SItemInfo.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: 订单明细
// History			:
//******************************************************************************
#pragma once
#ifndef __SITEMINFO_H__
#define __SITEMINFO_H__
#include <QString>
struct SItemInfo
{
    int miItemID;           // 订单明细ID
    int miOrderID;          // 订单ID
    int miMaterialID;       // 耗材ID
    int miProjectID;        // 项目ID
    int miNumber;           // 数量
    double mdWidth;         // 宽度
    double mdHeight;        // 高度
    double mdArea;          // 面积
    double miUnitPrice;     // 单价
    double mdPrice;         // 金额
    QString msContents;     // 制作内容
    QString msRemarks;      // 备注
};



#endif // __SITEMINFO_H__

