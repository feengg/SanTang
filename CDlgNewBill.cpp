
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
    // 配置table显示
    ui->mopTabItems->setColumnCount(11);
    ui->mopTabItems->setHorizontalHeaderLabels(QStringList()
        << tr("项目名称")
        << tr("耗材")
        << tr("制作内容")
        << tr("宽度")
        << tr("高度")
        << tr("厚度")
        << tr("数量")
        << tr("面积")
        << tr("单价")
        << tr("单位")
        << tr("金额"));
}

void CDlgNewBill::mvInitTimeEdit()
{
    // 配置时间显示
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
    com_unit->addItem(tr("米"));
    com_unit->addItem(tr("平方米"));
    com_unit->addItem(tr("厘米"));
    com_unit->addItem(tr("平方厘米"));
    com_unit->addItem(tr("个"));
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
