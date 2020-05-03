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
    // 初始化界面
    void mvInitGUI();

    // 初始化table界面
    void mvInitTableWidget();

    // 初始化时间
    void mvInitTimeEdit();

    // 初始化信号槽连接
    void mvInitConnection();

private slots:
    void mslotOnAddItemBtnClicked();            // 添加明细
    void mslotOnDeleteItemBtnClicked();         // 删除明细                                        
    void mslotOnSaveBillBtnClicked();           // 保存订单
    void mslotOnEditBillBtnClicked();           // 编辑订单
    void mslotOnVerifyBillBtnClicked();         // 审核订单
    void mslotOnPrintBillBtnClicked();          // 打印订单
    void mslotOnCancelBillBtnClicked();         // 取消订单

private:
    // 与数据库交互的函数
    void mvGetTempCusmoterInfo();               // 获取当前客户信息
    void mvGetMaterialPrice();                  // 获取材料到单位价格的映射
    void mvGetUnitInfo();                       // 获取所有的标准单位信息

    bool mbWriteItemToSQL();                    // 写出明细到sql

private:
    sptr<CCustomer>         msptrTempCustomer;    // 当前客户信息
    QMap<QString, double>   mmapMaterialPrie;     // 材料名到单位价格的映射
    QList<QString>          msltUnitInfo;         // 单位信息
    QList<sptr<COrderInfo>>      msltItems;            // 明细
private:
    Ui::CDlgNewBill *ui;                          // 界面
};
