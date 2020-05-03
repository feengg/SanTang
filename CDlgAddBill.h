#pragma once

#include <QWidget>
#include "ui_CDlgAddBill.h"

class CDlgAddBill : public QWidget
{
    Q_OBJECT

public:
    CDlgAddBill(QWidget *parent = Q_NULLPTR);
    ~CDlgAddBill();

    QString msGetID() const;
    QString msGetMaterial() const;

private slots:
    void mslotOnClickOkBtn();
    void mslotOnClickCancelBtn();

private:
    
    void mvInitConnection();

private:
    Ui::CDlgAddBill *ui;

    QString msID;
    QString msMaterial;
};
