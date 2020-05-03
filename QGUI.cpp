#include "QGUI.h"
#include "ui_QGUI.h"

QGUI::QGUI(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::QGUI();
    ui->setupUi(this);
}

QGUI::~QGUI()
{
    delete ui;
}
