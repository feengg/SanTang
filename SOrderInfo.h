//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SOrder.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: 订单结构体
// History			:
//******************************************************************************
#pragma once
#ifndef __SORDER_H__
#define __SORDER_H__

#include <QString>

struct SOrderInfo
{
    int miOrderID;              // 订单编号
    int miCustomerID;           // 客户ID
    int miDesignerID;           // 设计员ID
    int miClerkID;              // 业务员ID
    int meDelivery;             // 送货方式
    int meOrderStatus;          // 订单状态

    double msPrePay;            // 定金
    double msTotalPrice;        // 总价
    double msDeliveryPrice;     // 运费

    QString msOrderData;        // 下单时间
    QString msDeliveryDate;     // 交货日期
    QString msRemarks;          // 备注
};

#endif // __SORDER_H__
