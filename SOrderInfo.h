//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: SOrder.h
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-04-09
// Description		: �����ṹ��
// History			:
//******************************************************************************
#pragma once
#ifndef __SORDER_H__
#define __SORDER_H__

#include <QString>

struct SOrderInfo
{
    int miOrderID;              // �������
    int miCustomerID;           // �ͻ�ID
    int miDesignerID;           // ���ԱID
    int miClerkID;              // ҵ��ԱID
    int meDelivery;             // �ͻ���ʽ
    int meOrderStatus;          // ����״̬

    double msPrePay;            // ����
    double msTotalPrice;        // �ܼ�
    double msDeliveryPrice;     // �˷�

    QString msOrderData;        // �µ�ʱ��
    QString msDeliveryDate;     // ��������
    QString msRemarks;          // ��ע
};

#endif // __SORDER_H__
