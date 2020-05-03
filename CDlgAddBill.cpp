#include "CDlgAddBill.h"
#include <QMessageBox>

CDlgAddBill::CDlgAddBill(QWidget *parent)
    : QWidget(parent)
{
    ui->setupUi(this);
    mvInitConnection();
}

CDlgAddBill::~CDlgAddBill()
{
}

QString CDlgAddBill::msGetID() const
{
    return msID;
}

QString CDlgAddBill::msGetMaterial() const
{
    return msMaterial;
}

void CDlgAddBill::mslotOnClickOkBtn()
{
    msID = ui->opTxtID->toPlainText();
    msMaterial = ui->opTxtMaterial->toPlainText();
    this->destroy();
}

void CDlgAddBill::mslotOnClickCancelBtn()
{
    this->destroy();
}

void CDlgAddBill::mvInitConnection()
{
    connect(ui->mopBtnOk, SIGNAL(clicked()), this, SLOT(mslotOnClickOkBtn()));
    connect(ui->mopBtnCancel, SIGNAL(clicked()), this, SLOT(mslotOnClickCancelBtn()));
}

