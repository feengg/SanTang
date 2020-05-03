
//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CSQLDatabase.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: CSQLDatabase��
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

// �ͻ�
#define CUSMER_TABLE        "customers"     // �ͻ���
#define CUSMER_ORDER_TABLE  "cusmer_orders" // �ͻ�������
#define CUSMER_ITEM_TABLE   "cusmer_items"  // �ͻ�������ϸ��

// ��Э
#define SUPPLY_TABLE        "supplier"      // ��Ӧ�̱�
#define SUPORDER_TABLE      "suporders"     // ��Ӧ������
#define SUPITEM_TABLE       "supitems"      // ��Ӧ������ϸ��

// ��Ա����
#define DEPARTMENT_TABLE    "departments"   // ���ű�
#define EMPOLYEE_TABLE      "empolyee"      // Ա����

// ��Ʒ����
#define MATERIAL_TABLE      "material"      // �Ĳı�
#define PRODUCT_TABLE       "products"      // ��Ʒ��
#define PROJECT_TABLE       "projects"      // ��Ŀ��
#define UNIT_TABLE          "unit"          // ������λ��

class CSQLDatabase
{
public:
    // ���캯��
    explicit CSQLDatabase();
    ~CSQLDatabase();
    
    // �������ݿ�
    bool mbCreateDatabase(const QString& sConnectName, const QString& sDatabaseName, \
        const QString& sHostName, const QString& sUserName, const QString& sPassWord);

    // �����ݿ�
    bool mbOpenDatabase(const QString& sConnectName, const QString& sDatabaseName, \
        const QString& sHostName, const QString& sUserName, const QString& sPassword);

    // ����TABLE
    void mvInitialTab();

    // �����ͻ���
    void mvCreateCusmerTab();
    // �����ͻ�������
    void mvCrateCusmerOrdTab();
    // �����ͻ�������ϸ��
    void mvCreateCusmerOrdItemTab();
    // �жϿͻ���Ϣ�Ƿ����
    bool mbCusmerInfoIsEx(const QString& sKey, const QString& sType);
     // ����ͻ���Ϣ
    bool mbInstCusmerInfo(const SCustomer& customerInfo);
    // ���¿ͻ���Ϣ
    bool mbUpdataCumerInfo(const SCustomer& customerInfo);
     // ��ȡ�ͻ���Ϣ
    bool mbGetLstCusmerInfo(const QString& sType, const QString& sKey, QList<SCustomer>& customerInfoList);
    // ��ȡ�ͻ���Ϣ
    bool mbGetLstCusmerInfo(QList<SCustomer>& LstCusmerInfo);
    // ɾ���ͻ���Ϣ
    bool mbDelCusmerInfo(const QString& name);
    
    // ������Ӧ�̱�
    void mvCreateSupplierTable();
    // ������Ӧ������
    void mvbCreateSupOrderTable();
    // ������Ӧ������ϸ��
    void mvCreateSupItemTable();

    // �������ű�
    void mvCreateDepartTable();
    // ����Ա����
    void mvCreateEmpolyeeTable();

    // �Ĳı�
    void mvCreateMaterialTable();
    // ��Ʒ��
    void mvCreateProductTable();
    // ��Ŀ��
    void mvCreateProjectTable();
    // ����������λ�б�
    void mvCreateUnitTable();

    // ��ȡ������Ϣ
    QString msGetError();

private:
    CSQLDatabase(const CSQLDatabase&);

    // �ͻ�����
    void mvGetLstCusmerInfo(QSqlQuery* query, QList<SCustomer>& customerInfoList);

private:
    QString msConnectName;              // ������
    QString msHostName;                 // ������
    QString msDatabaseName;             // ���ݿ���
    QString msUserName;                 // ���ݿ��û���
    QString msPassWord;                 // ���ݿ�����

    // �ͻ�����
    bool mbCusmerQeryIsOk;              // �ͻ���ѯ�����Ƿ�OK
    bool mbOrderQueryIsOk;              // �ͻ�������ѯ�����Ƿ�OK
    bool mbItemQueryIsOk;               // �ͻ�������ϸ��ѯ�Ƿ�OK

    // ��Э
    bool mbSupplierQueryIsOk;           // ��Ӧ�̲�ѯ�����Ƿ�OK
    bool mbSupOrdersQueryIsOk;          // ��Ӧ�̶�����ѯ�����Ƿ�OK
    bool mbSupItemsQueryIsOk;           // ��Ӧ�̶�����ϸ�����Ƿ�OK

    // ��Ա����
    bool mbEmpolyeeQueryIsOk;           // Ա����ѯ�����Ƿ�OK
    bool mbDepartmentQueryIsOk;         // ���Ų�ѯ�����Ƿ�OK

    // ��Ʒ����
    bool mbMaterialQueryIsOk;           // �ĲĲ�ѯ�����Ƿ�OK
    bool mbProductQuerysIsOk;           // ��Ʒ��ѯ�����Ƿ�OK
    bool mbProjectQueryIsOk;            // ��Ŀ��ѯ�����Ƿ�OK
    bool mbUnitQueryIsOk;               // ������λ��ѯ�����Ƿ�OK

    // ���ݿ�
    QSqlDatabase    mSqlDB;             // ���ݿ�

    // �ͻ�
    QSqlQuery       *mCustomerQuery;    // �ͻ���Ϣ�����б�
    QSqlQuery       *mOrderQuery;       // �ͻ�������ѯ�б�
    QSqlQuery       *mItemQuery;        // �ͻ�������ϸ��

    // ��Э
    QSqlQuery       *mSupplierQuery;    // ��Ӧ���б�
    QSqlQuery       *mSupOrdersQuery;   // ��Ӧ�̶����б�
    QSqlQuery       *mSupItemsQuery;    // ��Ӧ�̶�����ϸ�б�

    // ��Ա����
    QSqlQuery       *mEmpolyeeQuery;    // Ա����ѯ�б�
    QSqlQuery       *mDepartmentQuery;  // ���Ų�ѯ�б�

    // ��Ʒ����
    QSqlQuery       *mMaterialQuery;    // �ĲĲ�ѯ�б�
    QSqlQuery       *mProductQuery;     // ��Ʒ��ѯ�б�
    QSqlQuery       *mProjectQuery;     // ��Ŀ��ѯ�б�
    QSqlQuery       *mUnitQuery;        // ������λ�б�

    QString         msError;            // ������Ϣ
};

static CSQLDatabase* mSqlDB = new CSQLDatabase;


#endif // __CSQLDATABASE_H__


