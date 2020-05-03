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

// 配置中文字符
#pragma execution_character_set("utf-8")

// SQL编辑关键字
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

// 共用字段
const QString id            = "id";
const QString companyname   = "companyname";
const QString contact       = "contact";
const QString tel           = "tel";
const QString wechat        = "wechat";
const QString qq            = "qq";
const QString address       = "address";
const QString remarks       = "remarks";


// 客户信息
enum TCustomer
{
    eId = 1,        // ID编号
    eCompanyName,   // 公司名
    eName,          // 客户联系名
    eTel,           // 客户电话
    eWechat,        // 微信
    eQQ,            // QQ
    eAddress,       // 地址
    eRemark         // 备注
};


// 外协信息
enum TSupplier
{

};

// 发货方式
enum TDeliveryWay
{
    eSelfPickup = 0,    // 用户自提
    eCourier,           // 物流
};

// 订单状态
enum TOrderStatus
{
    eMaking = 0,        // 制作中
    eWaitingMake,       // 待制作
    eMaked,             // 已制作
    eDeliveried         // 已发货
};

// 订单信息
enum TOrderInfo
{
    eOrderId = 1,           // 订单编号
    eCustomerID,            // 客户ID
    eDesignerID,            // 设计员ID
    eClerkID,               // 业务员ID
    eDelivery,              // 送货方式
    eOrderStatus,           // 订单状态
    ePrePay,                // 定金
    eTotalPrice,            // 总价
    eDeliveryPrice,         // 运费
    eOrderDate,             // 下单时间
    eDeliveryDate,          // 交货日期
    eRemarks                // 备注
};

// 计量单位信息
enum TUnit
{
    eUnitId = 1,            // 计量单位编号
    eUnitName,              // 计量单位名称
};

// 界面
enum TTabType
{
    eCusmerOrdTab,      // 客户订单table
    eSupOrdTab,         // 供应商订单table
    eCusmerInfoTab,     // 客户信息table
    eSupOrdInfoTab,     // 外协客户信息table
};
