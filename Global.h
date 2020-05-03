//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: Global.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-07
// Description		: Global
// History			:
//******************************************************************************
#pragma once
#include <QString>
#include <memory>
template<class T> using sptr = std::shared_ptr<T>;
template<class T> using wptr = std::weak_ptr<T>;
template<class T> using uptr = std::unique_ptr<T>;
using std::enable_shared_from_this;

// ���������ַ�
#pragma execution_character_set("utf-8")

// SQL�༭�ؼ���
const QString create    = "create ";
const QString table     = "table";
const QString varchar   = "varchar";
const QString primary   = "primary";
const QString select    = "select";
const QString count     = "count";
const QString from      = "from";
const QString sqlite_master = "sqlite_master";
const QString where     = "where";
const QString type      = "type";
const QString and       = "and";
const QString name      = "name";

// �����ֶ�
const QString id            = "id";
const QString companyname   = "companyname";
const QString contact       = "contact";
const QString tel           = "tel";
const QString wechat        = "wechat";
const QString qq            = "qq";
const QString address       = "address";
const QString remarks       = "remarks";


// �ͻ���Ϣ
enum TCustomer
{
    eId = 1,        // ID���
    eCompanyName,   // ��˾��
    eName,          // �ͻ���ϵ��
    eTel,           // �ͻ��绰
    eWechat,        // ΢��
    eQQ,            // QQ
    eAddress,       // ��ַ
    eRemark         // ��ע
};


// ��Э��Ϣ
enum TSupplier
{

};

// ������ʽ
enum TDeliveryWay
{
    eSelfPickup = 0,    // �û�����
    eCourier,           // ����
};

// ����״̬
enum TOrderStatus
{
    eMaking = 0,        // ������
    eWaitingMake,       // ������
    eMaked,             // ������
    eDeliveried         // �ѷ���
};

// ������Ϣ
enum TOrderInfo
{
    eOrderId = 1,           // �������
    eCustomerID,            // �ͻ�ID
    eDesignerID,            // ���ԱID
    eClerkID,               // ҵ��ԱID
    eDelivery,              // �ͻ���ʽ
    eOrderStatus,           // ����״̬
    ePrePay,                // ����
    eTotalPrice,            // �ܼ�
    eDeliveryPrice,         // �˷�
    eOrderDate,             // �µ�ʱ��
    eDeliveryDate,          // ��������
    eRemarks                // ��ע
};

// ������λ��Ϣ
enum TUnit
{
    eUnitId = 1,            // ������λ���
    eUnitName,              // ������λ����
};

// ����
enum TTabType
{
    eCusmerOrdTab,      // �ͻ�����table
    eSupOrdTab,         // ��Ӧ�̶���table
    eCusmerInfoTab,     // �ͻ���Ϣtable
    eSupOrdInfoTab,     // ��Э�ͻ���Ϣtable
};
