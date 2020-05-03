#include "CDlgOrderToolBar.h"

CDlgOrderToolBar::CDlgOrderToolBar(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.mopBtnCheck, SIGNAL(clicked()), this, SLOT(mslotOnBtnCheckClicked()));
}

CDlgOrderToolBar::~CDlgOrderToolBar()
{
}

void CDlgOrderToolBar::mslotOnBtnCheckClicked(bool)
{
    emit mbsigSentBtnCheckClicked(true);
}

void CDlgOrderToolBar::mslotOnBtnEditClicked(bool)
{
    emit mbsigSentBtnEditClicked(true);
}

void CDlgOrderToolBar::mvInitConection()
{
    connect(ui.mopBtnCheck, SIGNAL(clicked()), this, SLOT(mslotOnBtnCheckClicked()));
    connect(ui.mopBtnEdit, SIGNAL(ui.mopBtnEdit.clicked()), this, SLOT(mslotOnBtnEditClicked()));
}

