#include "SanTang.h"


ERP::ERP(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    mvInitlizeGUI();

    mvInitConnection();
}

void ERP::mslotOnBtnCustomerOrderManClicked()
{
    meDlgType = eCusmerOrdTab;
    return mvInitOrderManDlg();
    
}

void ERP::mslotOnBtnSupOrderManClicked()
{
    meDlgType = eSupOrdTab;
    return mvInitOrderManDlg();
}

void ERP::mslotOnBtnNewOrderClicked()
{

}

void ERP::mslotprint(QString data)
{
    QString m = data;
    int mm = 0;
}

void ERP::mslotOnBtnOrderToolCheck(bool bShow)
{
    mopNewBill = new CDlgNewBill;
    mopNewBill->show();
}

//******************************************************************************
// Function			: ERP::mvInitOrderManDlg
// Description		: 创建订单管理界面
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-19
// Author			: SanTang  Jiaofeng
//******************************************************************************
void ERP::mvInitOrderManDlg()
{
    mopOrderManBar->show();
    mopDlgOrderMan->mvSetTableWidget(meDlgType);
    this->ui.mopTableWidget->setCurrentWidget(mopDlgOrderMan);
}

void ERP::mvInitlizeGUI()
{
    mopDlgOrderMan = new CDlgOrderMan(this);
    this->ui.mopTableWidget->addWidget(mopDlgOrderMan);

    mopSanTangLogo = new QLabel;
    mopSanTangLogo->setText(tr("三棠广告"));
    this->ui.mopTableWidget->addWidget(mopSanTangLogo);
    this->ui.mopTableWidget->setCurrentWidget(mopSanTangLogo);

    mopOrderManBar = new CDlgOrderManToolBar(this->ui.mopFormToolBar);
    mopOrderManBar->hide();

}

void ERP::mvHideAllGUI()
{

}

void ERP::mvInitConnection()
{
    // 业务订单管理槽
    connect(this->ui.mopActCustomerOrderMan, SIGNAL(triggered()), this,SLOT(mslotOnBtnCustomerOrderManClicked()));

    connect(ui.mopActSupplierOrderMan, SIGNAL(triggered()), this, SLOT(mslotOnBtnSupOrderManClicked()));
    connect(ui.mopActNewCustomerOrder, SIGNAL(triggered()), this, SLOT(mslotOnBtnNewOrderClicked()));

    // 业务订单查看
    connect(mopOrderManBar, SIGNAL(msigSentOnBtnCheckClicked(bool)), this, SLOT(mslotOnBtnOrderToolCheck(bool)));
    
}
