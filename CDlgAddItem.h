#pragma once

#include <QWidget>
#include "ui_CDlgAddItem.h"

class CDlgBillMan;

class CDlgAddItem : public QWidget
{
    Q_OBJECT
public:

public:
    CDlgAddItem(QWidget *parent = Q_NULLPTR);
    ~CDlgAddItem();

    QString msGetID() const { return msID; }
    QString msGetMaterial() const { return msMaterial; }

private slots:
    void mslotOnOkClicked();
    void mslotOnCancelClicked();

signals:
    void msigGetID(QString);

private:
    void mvInitConnection();

private:
    Ui::CDlgAddItem ui;

private:
    QString msID;
    QString msMaterial;
};
