#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include "ui_CDlgBillMan.h"
#include "Global.h"
#include "SanTang.h"

class CDlgAddItem;

class CDlgBillMan : public QWidget
{
    Q_OBJECT
public:

public:
    CDlgBillMan(QWidget *parent = Q_NULLPTR);
    ~CDlgBillMan();

private slots:
    void mslotOnBtnAdd();
    void mslotOnBtnDelete();

    void mslotOnBtnAddDlgOkClicked();
    void mslotOnBtnAddDlgCancelClicked();

    void mslotGetID(QString);
    void mslotGetMaterial();

private:
    void mvInit();
private:

    QString msTempID;
    QString msTempMaterial;

private:
    Ui::CDlgBillMan  *ui;
    CDlgAddItem*     mopAddItemDlg;

};
