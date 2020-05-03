#pragma once
//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CItem.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-06
// Description		: CItem类
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

    int miMaterialType;     // 耗材类型
    int miNumber;           // 数量
    double mdWidth;         // 宽度
    double mdHeight;        // 高度
    double mdArea;          // 面积
    double miUnitPrice;     // 单价
    double mdTotalPrice;    // 总价
    QString msProjectName;  // 项目名称
    QString msContents;     // 制作内容
    QString msRemarks;      // 备注

};

#endif // __CITEM_H__



