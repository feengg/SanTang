#pragma once

#include <QtWidgets/QMainWindow>
#include "SanTang.h"
#include "ui_SanTang.h"
#include "Global.h"
#include "CSQLDatabase.h"
#include "CDlgCustomerEdit.h"
#include "CDlgOrderToolBar.h"
#include "CDlgOrderMan.h"
#include "CDlgNewBill.h"
#include "CDlgOrderManToolBar.h"

//class CSQLDatabase;
//class CDlgCustomerEdit;
//class CDlgOrderToolBar;
//class CDlgOrderMan;
//class CDlgNewBill;
//class CDlgOrderManToolBar;

class ERP : public QMainWindow
{
    Q_OBJECT

public:
    ERP(QWidget *parent = Q_NULLPTR);

    // 初始化db
    bool mbInitDB();
signals:
    void msigSentCustomerOrderManClicked(TTabType);
private:


private slots:
    // 业务管理
    // 客户订单管理按钮
    void mslotOnBtnCustomerOrderManClicked();

    // 外协订单管理按钮
    void mslotOnBtnSupOrderManClicked();

    // 添加客户订单
    void mslotOnBtnNewOrderClicked();
    void mslotprint(QString);

    // 业务订单查看
    void mslotOnBtnOrderToolCheck(bool);

private:
    // 创建订单管理界面
    void mvInitOrderManDlg();

    // 初始所有的界面
    void mvInitlizeGUI();

    // 隐藏所有的界面
    void mvHideAllGUI();

    // 初始化连接
    void mvInitConnection();
    
private:
    TTabType    meDlgType;      // 订单界面类型

public:
    static sptr<CSQLDatabase>   mSqlDatabase;
    static CSQLDatabase* mSql;

private:
    Ui::CDlgMainWindow      ui;
    CDlgCustomerEdit        *mopDlgCustomerEdit;    // 编辑客户信息
    CDlgOrderToolBar        *mopDlgOrderToolBar;    // 订单编辑工具栏
    CDlgOrderMan            *mopDlgOrderMan;        // 订单管理界面
    CDlgNewBill             *mopNewBill;            // 业务新单
    CDlgOrderManToolBar     *mopOrderManBar;        // 订单管理工具
    QLabel                  *mopSanTangLogo;        // logo
private:

 };
