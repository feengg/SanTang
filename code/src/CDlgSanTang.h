#pragma once

#include <QtWidgets/QWidget>
#include "ui_qDlgSanTang.h"

class CDlgSanTang : public QWidget
{
    Q_OBJECT

public:
    CDlgSanTang(QWidget *parent = Q_NULLPTR);

private:
    Ui::SanTangClass ui;
};
