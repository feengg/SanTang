//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SCustomer.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: 客户结构体
// History			:
//******************************************************************************
#pragma once
#ifndef __SCUSTOMER_H__
#define __SCUSTOMER_H__
#include <QString>
struct SCustomer
{
    QString id;                 // 客户ID
    QString companyname;        // 客户公司名
    QString contact;            // 客户姓名
    QString tel;                // 客户电话
    QString wechat;             // 微信帐号
    QString qq;                 // QQ帐号
    QString address;            // 客户地址
    QString remarks;            // 备注
};

#endif // __SCUSTOMER_H__
