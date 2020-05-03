#pragma once

#include "Global.h"
#include <QWidget>
#include <QList>

class COrderInfo;
class CCustomer;

namespace Ui { class CDlgNewBill; };

class CDlgNewBill : public QWidget
{
    Q_OBJECT

public:
    CDlgNewBill(QWidget *parent = Q_NULLPTR);
    ~CDlgNewBill();

private:
    // ��ʼ������
    void mvInitGUI();

    // ��ʼ��table����
    void mvInitTableWidget();

    // ��ʼ��ʱ��
    void mvInitTimeEdit();

    // ��ʼ���źŲ�����
    void mvInitConnection();

private slots:
    void mslotOnAddItemBtnClicked();            // �����ϸ
    void mslotOnDeleteItemBtnClicked();         // ɾ����ϸ                                        
    void mslotOnSaveBillBtnClicked();           // ���涩��
    void mslotOnEditBillBtnClicked();           // �༭����
    void mslotOnVerifyBillBtnClicked();         // ��˶���
    void mslotOnPrintBillBtnClicked();          // ��ӡ����
    void mslotOnCancelBillBtnClicked();         // ȡ������

private:
    // �����ݿ⽻���ĺ���
    void mvGetTempCusmoterInfo();               // ��ȡ��ǰ�ͻ���Ϣ
    void mvGetMaterialPrice();                  // ��ȡ���ϵ���λ�۸��ӳ��
    void mvGetUnitInfo();                       // ��ȡ���еı�׼��λ��Ϣ

    bool mbWriteItemToSQL();                    // д����ϸ��sql

private:
    sptr<CCustomer>         msptrTempCustomer;    // ��ǰ�ͻ���Ϣ
    QMap<QString, double>   mmapMaterialPrie;     // ����������λ�۸��ӳ��
    QList<QString>          msltUnitInfo;         // ��λ��Ϣ
    QList<sptr<COrderInfo>>      msltItems;            // ��ϸ
private:
    Ui::CDlgNewBill *ui;                          // ����
};
