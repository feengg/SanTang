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
// Description		: ����table����
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
// Description		: ��ʼ���ͻ���Ϣ����
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
    // ����table��ʾ
    ui.mopTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.mopTableWidget->setColumnCount(8);
    ui.mopTableWidget->setHorizontalHeaderLabels(QStringList()
        << tr("���")
        << tr("��˾����")
        << tr("��ϵ��")
        << tr("��ϵ�绰")
        << tr("΢��")
        << tr("QQ")
        << tr("��ַ")
        << tr("��ע"));
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
// Description		: ��ʼ������
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
