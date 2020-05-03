#pragma once

#include <QWidget>
#include "ui_CDlgOrderToolBar.h"
class CDlgOrderMan;
class ERP;

class CDlgOrderToolBar : public QWidget
{
    Q_OBJECT
        friend class CDlgOrderMan;
        friend class ERP;

public:
    CDlgOrderToolBar(QWidget *parent = Q_NULLPTR);
    ~CDlgOrderToolBar();
signals:
    void mbsigSentBtnCheckClicked(bool);
    void mbsigSentBtnEditClicked(bool);
    void senddata(QString data);

public slots :
    // CHECK²Û
    void mslotOnBtnCheckClicked(bool);

    // ±à¼­²Û
    void mslotOnBtnEditClicked(bool);

private:
    void mvInitConection();
private:
    Ui::CDlgOrderToolBar ui;
};
