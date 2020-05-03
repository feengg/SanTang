//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SEmpolyee.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: 员工结构体
// History			:
//******************************************************************************
#pragma once
#ifndef __SEMPOLYEE_H__
#define __SEMPOLYEE_H__
#include <QString>

struct SEmpolyee
{
    int miEmpolyeeId;           // 员工编号
    int miDepartMent;           // 员工所在部门
    QString msName;             // 员工姓名
    QString msTelNumber;        // 员工电话
    QString msAddress;          // 员工地址
};

#endif // __SEMPOLYEE_H__
