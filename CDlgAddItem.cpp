#include "CDlgAddItem.h"
#include "CDlgBillMan.h"

CDlgAddItem::CDlgAddItem(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    mvInitConnection();
}

CDlgAddItem::~CDlgAddItem()
{
 
}

void CDlgAddItem::mslotOnOkClicked()
{
    msID = ui.moLineEditID->text();
    msMaterial = ui.moLineEditMaterial->text();
    emit msigGetID(msID);
    this->hide();

}

void CDlgAddItem::mslotOnCancelClicked()
{
    this->close();
}
//
//void CDlgAddItem::msigGetID(QString str)
//{
//    str = msID;
//}
//
void CDlgAddItem::mvInitConnection()
{
    connect(ui.moBtnOk, SIGNAL(clicked()), this, SLOT(mslotOnOkClicked()));
    connect(ui.moBtnCancel, SIGNAL(clicked()), this, SLOT(mslotOnCancelClicked()));
}
