#include "CDlgOrderManToolBar.h"
#include "ui_CDlgOrderManToolBar.h"

CDlgOrderManToolBar::CDlgOrderManToolBar(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::CDlgOrderManToolBar();
    ui->setupUi(this);
    connect(ui->mopBtnCheck, SIGNAL(clicked()), this, SLOT(mslotOnBtnCheckClicked()));
}

CDlgOrderManToolBar::~CDlgOrderManToolBar()
{
    delete ui;
}

void CDlgOrderManToolBar::mslotOnBtnCheckClicked()
{
    emit msigSentOnBtnCheckClicked(true);
}
