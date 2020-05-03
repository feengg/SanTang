#pragma once

#include <QWidget>
#include "ui_CDlgCustomerEdit.h"

class CDlgCustomerEdit : public QWidget
{
    Q_OBJECT

public:
    CDlgCustomerEdit(QWidget *parent = Q_NULLPTR);
    ~CDlgCustomerEdit();

private:
    Ui::CDlgCustomerEdit ui;
};
