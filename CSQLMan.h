//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CSQLMan.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-05
// Description		: 数据库管理类
// History			:
//******************************************************************************

#pragma once
#ifndef __CSQLMAN_H__
#define __CSQLMAN_H__

#include <QList>
#include <QStringList>
#include <QSqlDataBase>

class CSQLMan
{
public:
    CSQLMan();
    ~CSQLMan();

    void mvCreateDB(QString sql, QString sHostName, QString sDatabaseName, QString sUserName, QString sPassword);

    bool mbConnectDB();

    void mvCreateTable(QString sTableName);

    void mvInitDB();

    QList<QStringList> mlstSelectDataFromDB();

private:

    QSqlDatabase *msqlDB;

};

#endif // __CSQLMAN_H__



