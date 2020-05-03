#pragma once

#include <QWidget>
#include "ui_CDlgAddCusmerInfo.h"

class CDlgAddCusmerInfo : public QWidget
{
    Q_OBJECT

public:
    CDlgAddCusmerInfo(QWidget *parent = Q_NULLPTR);
    ~CDlgAddCusmerInfo();

private:
    Ui::CDlgAddCusmerInfo ui;
};
