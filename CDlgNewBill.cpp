
#include "CDlgNewBill.h"
#include "ui_CDlgNewBill.h"
#include "COrderInfo.h"
#include <QStringList>


CDlgNewBill::CDlgNewBill(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::CDlgNewBill();
    ui->setupUi(this);
    mvInitGUI();

    mvInitConnection();
}

CDlgNewBill::~CDlgNewBill()
{
    delete ui;
}

void CDlgNewBill::mvInitGUI()
{
    mvInitTimeEdit();
    mvInitTableWidget();


}

void CDlgNewBill::mvInitTableWidget()
{
    // ����table��ʾ
    ui->mopTabItems->setColumnCount(11);
    ui->mopTabItems->setHorizontalHeaderLabels(QStringList()
        << tr("��Ŀ����")
        << tr("�Ĳ�")
        << tr("��������")
        << tr("���")
        << tr("�߶�")
        << tr("���")
        << tr("����")
        << tr("���")
        << tr("����")
        << tr("��λ")
        << tr("���"));
}

void CDlgNewBill::mvInitTimeEdit()
{
    // ����ʱ����ʾ
    QDate data = QDate::currentDate();
    ui->mopDateOrderBuild->setDate(data);
    ui->mopTimeDeliveryData->setDate(data);
    
}

void CDlgNewBill::mvInitConnection()
{
    connect(ui->mopBtnAddItem, SIGNAL(clicked()), this, SLOT(mslotOnAddItemBtnClicked()));
    connect(ui->mopBtnDeleteItem, SIGNAL(clicked()), this, SLOT(mslotOnDeleteItemBtnClicked()));
    connect(ui->mopBtnCancel, SIGNAL(clicked()), this, SLOT(mslotOnCancelBillBtnClicked()));
}

void CDlgNewBill::mslotOnAddItemBtnClicked()
{
    int i_row = ui->mopTabItems->rowCount();

    ui->mopTabItems->insertRow(i_row);

    QComboBox *box = new QComboBox;

    ui->mopTabItems->setCellWidget(i_row, 1, box);

    QComboBox *com_unit = new QComboBox;
    com_unit->addItem(tr("��"));
    com_unit->addItem(tr("ƽ����"));
    com_unit->addItem(tr("����"));
    com_unit->addItem(tr("ƽ������"));
    com_unit->addItem(tr("��"));
    ui->mopTabItems->setCellWidget(i_row, 9, com_unit);


}

void CDlgNewBill::mslotOnDeleteItemBtnClicked()
{
    int i_row = ui->mopTabItems->currentRow();
    ui->mopTabItems->removeRow(i_row);
}



void CDlgNewBill::mslotOnSaveBillBtnClicked()
{

}

void CDlgNewBill::mslotOnEditBillBtnClicked()
{

}

void CDlgNewBill::mslotOnVerifyBillBtnClicked()
{

}

void CDlgNewBill::mslotOnPrintBillBtnClicked()
{

}

void CDlgNewBill::mslotOnCancelBillBtnClicked()
{
    this->destroy();
}
