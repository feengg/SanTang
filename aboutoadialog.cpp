#include "aboutoadialog.h"
#include "ui_aboutoadialog.h"

AboutOADialog::AboutOADialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutOADialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/aboutZYOA.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("关于正博OA");
}

AboutOADialog::~AboutOADialog()
{
    delete ui;
}

void AboutOADialog::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
        this->hide();
    }
}

void AboutOADialog::on_toolButton_clicked()
{
    this->close();
}
