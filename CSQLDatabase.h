
//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CSQLDatabase.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: CSQLDatabase类
// History			:
//******************************************************************************
#pragma once
#ifndef __CSQLDATABASE_H__
#define __CSQLDATABASE_H__

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QString>
#include "Global.h"
#include "CCustomer.h"
#include "COrderInfo.h"
#include "SCustomer.h"
#include "SOrderInfo.h"
#include "SProduct.h"

// 客户
#define CUSMER_TABLE        "customers"     // 客户表
#define CUSMER_ORDER_TABLE  "cusmer_orders" // 客户订单表
#define CUSMER_ITEM_TABLE   "cusmer_items"  // 客户订单明细表

// 外协
#define SUPPLY_TABLE        "supplier"      // 供应商表
#define SUPORDER_TABLE      "suporders"     // 供应订单表
#define SUPITEM_TABLE       "supitems"      // 供应订单明细表

// 人员管理
#define DEPARTMENT_TABLE    "departments"   // 部门表
#define EMPOLYEE_TABLE      "empolyee"      // 员工表

// 产品管理
#define MATERIAL_TABLE      "material"      // 耗材表
#define PRODUCT_TABLE       "products"      // 产品表
#define PROJECT_TABLE       "projects"      // 项目表
#define UNIT_TABLE          "unit"          // 计量单位表

class CSQLDatabase
{
public:
    // 构造函数
    explicit CSQLDatabase();
    ~CSQLDatabase();
    
    // 创建数据库
    bool mbCreateDatabase(const QString& sConnectName, const QString& sDatabaseName, \
        const QString& sHostName, const QString& sUserName, const QString& sPassWord);

    // 打开数据库
    bool mbOpenDatabase(const QString& sConnectName, const QString& sDatabaseName, \
        const QString& sHostName, const QString& sUserName, const QString& sPassword);

    // 创建TABLE
    void mvInitialTab();

    // 创建客户表
    void mvCreateCusmerTab();
    // 创建客户订单表
    void mvCrateCusmerOrdTab();
    // 创建客户订单明细表
    void mvCreateCusmerOrdItemTab();
    // 判断客户信息是否存在
    bool mbCusmerInfoIsEx(const QString& sKey, const QString& sType);
     // 插入客户信息
    bool mbInstCusmerInfo(const SCustomer& customerInfo);
    // 更新客户信息
    bool mbUpdataCumerInfo(const SCustomer& customerInfo);
     // 获取客户信息
    bool mbGetLstCusmerInfo(const QString& sType, const QString& sKey, QList<SCustomer>& customerInfoList);
    // 获取客户信息
    bool mbGetLstCusmerInfo(QList<SCustomer>& LstCusmerInfo);
    // 删除客户信息
    bool mbDelCusmerInfo(const QString& name);
    
    // 创建供应商表
    void mvCreateSupplierTable();
    // 创建供应订单表
    void mvbCreateSupOrderTable();
    // 创建供应订单明细表
    void mvCreateSupItemTable();

    // 创建部门表
    void mvCreateDepartTable();
    // 创建员工表
    void mvCreateEmpolyeeTable();

    // 耗材表
    void mvCreateMaterialTable();
    // 产品表
    void mvCreateProductTable();
    // 项目表
    void mvCreateProjectTable();
    // 创建计量单位列表
    void mvCreateUnitTable();

    // 获取错误信息
    QString msGetError();

private:
    CSQLDatabase(const CSQLDatabase&);

    // 客户操作
    void mvGetLstCusmerInfo(QSqlQuery* query, QList<SCustomer>& customerInfoList);

private:
    QString msConnectName;              // 联接名
    QString msHostName;                 // 主机名
    QString msDatabaseName;             // 数据库名
    QString msUserName;                 // 数据库用户名
    QString msPassWord;                 // 数据库密码

    // 客户操作
    bool mbCusmerQeryIsOk;              // 客户查询操作是否OK
    bool mbOrderQueryIsOk;              // 客户订单查询操作是否OK
    bool mbItemQueryIsOk;               // 客户订单明细查询是否OK

    // 外协
    bool mbSupplierQueryIsOk;           // 供应商查询操作是否OK
    bool mbSupOrdersQueryIsOk;          // 供应商订单查询操作是否OK
    bool mbSupItemsQueryIsOk;           // 供应商订单明细操作是否OK

    // 人员管理
    bool mbEmpolyeeQueryIsOk;           // 员工查询操作是否OK
    bool mbDepartmentQueryIsOk;         // 部门查询操作是否OK

    // 产品管理
    bool mbMaterialQueryIsOk;           // 耗材查询操作是否OK
    bool mbProductQuerysIsOk;           // 产品查询操作是否OK
    bool mbProjectQueryIsOk;            // 项目查询操作是否OK
    bool mbUnitQueryIsOk;               // 计量单位查询操作是否OK

    // 数据库
    QSqlDatabase    mSqlDB;             // 数据库

    // 客户
    QSqlQuery       *mCustomerQuery;    // 客户信息数据列表
    QSqlQuery       *mOrderQuery;       // 客户订单查询列表
    QSqlQuery       *mItemQuery;        // 客户订单明细表

    // 外协
    QSqlQuery       *mSupplierQuery;    // 供应商列表
    QSqlQuery       *mSupOrdersQuery;   // 供应商订单列表
    QSqlQuery       *mSupItemsQuery;    // 供应商订单明细列表

    // 人员管理
    QSqlQuery       *mEmpolyeeQuery;    // 员工查询列表
    QSqlQuery       *mDepartmentQuery;  // 部门查询列表

    // 产品管理
    QSqlQuery       *mMaterialQuery;    // 耗材查询列表
    QSqlQuery       *mProductQuery;     // 产品查询列表
    QSqlQuery       *mProjectQuery;     // 项目查询列表
    QSqlQuery       *mUnitQuery;        // 计量单位列表

    QString         msError;            // 错误信息
};

static CSQLDatabase* mSqlDB = new CSQLDatabase;


#endif // __CSQLDATABASE_H__


