#include "showdontupdatedialog.h"
#include "ui_showdontupdatedialog.h"
#include <QDebug>

showDontUpdateDialog::showDontUpdateDialog(QString showMsg,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showDontUpdateDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("提示信息");
    ui->label_msg->setText(showMsg);

}

showDontUpdateDialog::~showDontUpdateDialog()
{
    delete ui;
}

void showDontUpdateDialog::on_pushButton_clicked()
{
    qDebug() << "close";
    this->deleteLater();
}
