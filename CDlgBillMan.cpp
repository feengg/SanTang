#pragma execution_character_set("utf-8")
#include "CDlgBillMan.h"
#include "CDlgAddItem.h"
#include <memory>

CDlgBillMan::CDlgBillMan(QWidget *parent)
    : QWidget(parent)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << tr("ID") << tr("Material"));
    int iRow = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(iRow + 10);
    for (int i = 0; i < 10; i++) {
        QTableWidgetItem *item = new QTableWidgetItem("type");
        ui->tableWidget->setItem(i, 0, item);
        ui->tableWidget->setItem(i, 1, item);
    }


    mvInit();


}

CDlgBillMan::~CDlgBillMan()
{
    delete ui;
    delete mopAddItemDlg;
}

void CDlgBillMan::mslotOnBtnAdd()
{
    mopAddItemDlg->show();
    QString sid = mopAddItemDlg->msGetID();
    QString sma = mopAddItemDlg->msGetMaterial();

}

void CDlgBillMan::mslotOnBtnDelete()
{

}

void CDlgBillMan::mslotOnBtnAddDlgOkClicked()
{

}

void CDlgBillMan::mslotOnBtnAddDlgCancelClicked()
{

}

void CDlgBillMan::mslotGetID(QString str)
{
    msTempID = str;
}

void CDlgBillMan::mslotGetMaterial()
{

}

void CDlgBillMan::mvInit()
{
    mopAddItemDlg = new CDlgAddItem;
    connect(ui->mopBtnAdd, SIGNAL(clicked()), this, SLOT(mslotOnBtnAdd()));
    connect(mopAddItemDlg, SIGNAL(msigGetID(QString)), this, SLOT(mslotGetID(QString)));
    //connect(mopAddItemDlg->ui.moBtnOk, SIGNAL(clicked()), this, SLOT(mslotOnBtnAddDlgOkClicked()));
}
