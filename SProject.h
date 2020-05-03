//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SProject.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-10
// Description		: 项目设置
// History			:
//******************************************************************************
#pragma once
#ifndef __SPROJECT_H__
#define __SPROJECT_H__

#include <QString>

class SProject
{
    int miProjectId;            // 编码
    int miUnitType;             // 计量单位
    QString msProjectName;      // 项目名
    QString msPinYinMa;         // 拼音码
};

#endif // __SPROJECT_H__
