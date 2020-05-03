#include "CDlgOrderMan.h"
#include "Global.h"

CDlgOrderMan::CDlgOrderMan(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    this->setParent(parent);

    mvInitConnection();
}

CDlgOrderMan::~CDlgOrderMan()
{
}

//******************************************************************************
// Function			: CDlgOrderMan::mvSetTableWidget
// Description		: 设置table界面
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-19
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgOrderMan::mvSetTableWidget(TTabType eDlgType)
{
    switch (eDlgType)
    {
    case eCusmerOrdTab: {
        return mvInitCusmerOrdTabTitle();
    }
    case eSupOrdTab: {
        return mvInitSupOrdTabTitle();
    }
    default:
        break;
    }
    return;
}

//******************************************************************************
// Function			: CDlgOrderMan::mslotSetTableWidget
// Description		:  设计table界面槽
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-18
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgOrderMan::mslotSetTableWidget(TTabType eDlgType)
{
    switch (eDlgType)
    {
    case eCusmerOrdTab: {
        return mvInitCusmerOrdTabTitle();
    }
    case eSupOrdTab: {
        return mvInitCusmerOrdTabTitle();
    }
    default:
        break;
    }
    return;
}

void CDlgOrderMan::mvInitGUI()
{
    mvInitOrderToolBar();
    mvInitCusmerOrdTabTitle();
}

void CDlgOrderMan::mvInitOrderToolBar()
{
    //mopOrderToolBar = new CDlgOrderToolBar(this->ui.mopFormToolBar);
    //mopOrderToolBar->show();
}

void CDlgOrderMan::mvInitCusmerOrdTabTitle()
{
    // 配置table显示
    ui.mopTableOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.mopTableOrders->setColumnCount(11);
    ui.mopTableOrders->setHorizontalHeaderLabels(QStringList()
        << tr("订单编号")
        << tr("客户名称")
        << tr("联系人")
        << tr("开单人")
        << tr("总价")
        << tr("定金")
        << tr("运费")
        << tr("优惠金额")
        << tr("交货时期")
        << tr("订单状态")
        << tr("备注"));
    ui.mopTableOrders->setColumnWidth(0, 80);
    ui.mopTableOrders->setColumnWidth(1, 100);
    ui.mopTableOrders->setColumnWidth(2, 100);
    ui.mopTableOrders->setColumnWidth(3, 100);
    ui.mopTableOrders->setColumnWidth(4, 100);
    ui.mopTableOrders->setColumnWidth(5, 100);
    ui.mopTableOrders->setColumnWidth(6, 100);
    ui.mopTableOrders->setColumnWidth(7, 100);
    ui.mopTableOrders->setColumnWidth(8, 100);
    ui.mopTableOrders->setColumnWidth(9, 100);
    ui.mopTableOrders->setColumnWidth(10, 100);
}

//******************************************************************************
// Function			: CDlgOrderMan::mvInitSupplierOrderTable
// Description		: 初始化外协订单列表
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-19
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgOrderMan::mvInitSupOrdTabTitle()
{
    // 配置table显示
    ui.mopTableOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.mopTableOrders->setColumnCount(11);
    ui.mopTableOrders->setHorizontalHeaderLabels(QStringList()
        << tr("订单编号")
        << tr("客户名称")
        << tr("联系人")
        << tr("开单人")
        << tr("总价")
        << tr("定金")
        << tr("运费")
        << tr("优惠金额")
        << tr("交货时期")
        << tr("订单状态")
        << tr("备注"));
    ui.mopTableOrders->setColumnWidth(0, 80);
    ui.mopTableOrders->setColumnWidth(1, 100);
    ui.mopTableOrders->setColumnWidth(2, 100);
    ui.mopTableOrders->setColumnWidth(3, 100);
    ui.mopTableOrders->setColumnWidth(4, 100);
    ui.mopTableOrders->setColumnWidth(5, 100);
    ui.mopTableOrders->setColumnWidth(6, 100);
    ui.mopTableOrders->setColumnWidth(7, 100);
    ui.mopTableOrders->setColumnWidth(8, 100);
    ui.mopTableOrders->setColumnWidth(9, 100);
    ui.mopTableOrders->setColumnWidth(10, 100);
}

void CDlgOrderMan::mvOnOrderManCheckBtnClicked()
{
    mopNewBill = new CDlgNewBill;
    mopNewBill->show();
}


void CDlgOrderMan::mvInitConnection()
{
    //connect(&parent, SIGNAL(msigSentCustomerOrderManClicked(TDlgType)), this, SLOT(mslotSetTableWidget(TDlgType)));
    //connect(mopOrderToolBar->ui.mopBtnCheck, SIGNAL(triggered()), this, SLOT(mvOnOrderManCheckBtnClicked));
    //connect(mopOrderToolBar->ui.mopBtnCheck, SIGNAL(triggered()),
    //    this, SLOT(mvOnCheckBtnClicked()));
}
             