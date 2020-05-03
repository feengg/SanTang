#include "CDlgCusmerEdit.h"

CDlgCusmerEdit::CDlgCusmerEdit(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

CDlgCusmerEdit::~CDlgCusmerEdit()
{
}

//******************************************************************************
// Function			: CDlgCusmerEdit::mvSetTabType
// Description		: 设置table类型
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-19
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgCusmerEdit::mvSetTabType(TTabType eTabType)
{
    meTabType = eTabType;
    return mvInitCusmerTabTitle();
}

//******************************************************************************
// Function			: CDlgCusmerEdit::mvInitCusmerTabTitle
// Description		: 初始化客户信息标题
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-19
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgCusmerEdit::mvInitCusmerTabTitle()
{
    // 配置table显示
    ui.mopTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.mopTableWidget->setColumnCount(8);
    ui.mopTableWidget->setHorizontalHeaderLabels(QStringList()
        << tr("编号")
        << tr("公司名称")
        << tr("联系人")
        << tr("联系电话")
        << tr("微信")
        << tr("QQ")
        << tr("地址")
        << tr("备注"));
    ui.mopTableWidget->setColumnWidth(0, 80);
    ui.mopTableWidget->setColumnWidth(1, 100);
    ui.mopTableWidget->setColumnWidth(2, 100);
    ui.mopTableWidget->setColumnWidth(3, 100);
    ui.mopTableWidget->setColumnWidth(4, 100);
    ui.mopTableWidget->setColumnWidth(5, 100);
    ui.mopTableWidget->setColumnWidth(6, 100);
    ui.mopTableWidget->setColumnWidth(7, 100);
}

//******************************************************************************
// Function			: CDlgCusmerEdit::mslotAddCusmerInfo
// Description		: 初始化增加
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-04-19
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgCusmerEdit::mslotAddCusmerInfo()
{

}
