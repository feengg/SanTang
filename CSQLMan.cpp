//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CSQLMan.cpp
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-05
// Description		: 数据库管理类
// History			:
//******************************************************************************

#include "CSQLMan.h"
#include <QSqlDataBase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

CSQLMan::CSQLMan()
{

}

CSQLMan::~CSQLMan()
{

}

void CSQLMan::mvCreateDB(QString sql, QString sHostName, QString sDatabaseName, QString sUserName, QString sPassword)
{
    *msqlDB = QSqlDatabase::addDatabase("QSQLITE");
    msqlDB->setHostName(sHostName);
    msqlDB->setDatabaseName(sDatabaseName);
    msqlDB->setUserName(sUserName);
    msqlDB->setPassword(sPassword);

}

bool CSQLMan::mbConnectDB()
{
    return true;
}

void CSQLMan::mvCreateTable(QString sTableName)
{
    bool ok = msqlDB->open();
    if (ok) {
        QSqlQuery query;
        query.exec("create table Bill (create_data datatime, "
            "id varchar(20) primary key, name varchar(20), "
            "sex varchar(20))");
    }
}

void CSQLMan::mvInitDB()
{

}

QList<QStringList> CSQLMan::mlstSelectDataFromDB()
{
    QSqlQuery query("SELECT * FROM bill");
    QList<QStringList> lst_str;
    while (query.next()) {
        QStringList srow_data;
        srow_data << query.value(1).toString();
        srow_data << query.value(2).toString();
        lst_str.append(srow_data);
    }
    return lst_str;
}

