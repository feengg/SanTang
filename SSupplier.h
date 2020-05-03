//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SSupplier.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-10
// Description		: 供货商信息
// History			:
//******************************************************************************
#pragma once
#ifndef __SSUPPLIER_H__
#define __SSUPPLIER_H__

#include <QString>
struct SSupplier
{
    QString id;             // 供应商ID
    QString companyname;    // 供应商公司名称
    QString contact;        // 联系人
    QString tel;            // 供货商电话
    QString wechat;         // 微信帐号
    QString qq;             // QQ帐号
    QString address;        // 供货商地址
    QString remarks;        // 备注
};

#endif // __SSUPPLIER_H__