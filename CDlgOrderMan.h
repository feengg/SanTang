#pragma once

#include <QWidget>
#include "ui_CDlgOrderMan.h"
#include "CDlgOrderToolBar.h"
#include "CDlgNewBill.h"
#include "Global.h"

class CDlgOrderMan : public QWidget
{
    Q_OBJECT

public:
    CDlgOrderMan(QWidget *parent = Q_NULLPTR);
    ~CDlgOrderMan();
    // 设置table界面
    void mvSetTableWidget(TTabType eDlgType);

signals:
    // 发送订单ID
    void msigSendOrderId(QString msOrderId);
public slots:
    // 设计table界面槽
    void mslotSetTableWidget(TTabType);

private:
    // 初始化界面
    void mvInitGUI();

    // 初始化Tool
    void mvInitOrderToolBar();

    // 初始化客户订单列表
    void mvInitCusmerOrdTabTitle();

    // 初始化外协订单列表
    void mvInitSupOrdTabTitle();

private slots:
    // 查看槽
    void mvOnOrderManCheckBtnClicked();

private:

    // 初始化连接
    void mvInitConnection();

private:
    Ui::CDlgOrderMan ui;                    // 管理界面

    CDlgOrderToolBar *mopOrderToolBar;      // 工具框

    CDlgNewBill      *mopNewBill;           // 新建业务订单界面


};
