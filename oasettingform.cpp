#include "oasettingform.h"
#include "ui_oasettingform.h"
#include "emailframe.h"
#include "showdontupdatedialog.h"
#include <QProcess>

OASettingForm::OASettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OASettingForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/对话框.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("设置");
    //EmailFrame::setWidgetShadow(ui->groupBox);
    //EmailFrame::setWidgetShadow(ui->pushButton);
    if(QFile::exists(qApp->applicationDirPath()+"/OASetting.dat"))
    {
        Widget::initOASetting();
        ui->lineEdit_sqlIP->setText(Widget::sqlIP);
        ui->lineEdit_sqlPort->setText(QString::number(Widget::sqlPort));
        ui->lineEdit_serverIP->setText(Widget::serverIP);
        ui->lineEdit_serverPort->setText(QString::number(Widget::serverPort));
        ui->lineEdit_sqlBaseName->setText(Widget::sqlBaseName);
        ui->lineEdit_sqlPassword->setText(Widget::sqlPassword);
        ui->lineEdit_sqlUserName->setText(Widget::sqlUserName);
        ui->lineEdit_serverIP->setText(Widget::serverIP);
        ui->lineEdit_serverPort->setText(QString::number(Widget::serverPort));
    }
}

OASettingForm::~OASettingForm()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void OASettingForm::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void OASettingForm::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void OASettingForm::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void OASettingForm::on_pushButton_close_clicked()
{
    this->close();
}

void OASettingForm::on_pushButton_clicked()
{
    if(LoginWindow::userLevel != 0)
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("您没有权限操作！");
        tip->show();
        return;
    }
    if(ui->lineEdit_serverIP->text().trimmed().isEmpty() || ui->lineEdit_serverPort->text().trimmed().isEmpty()
            ||ui->lineEdit_sqlBaseName->text().trimmed().isEmpty()||ui->lineEdit_sqlIP->text().trimmed().isEmpty()
            ||ui->lineEdit_sqlPassword->text().trimmed().isEmpty()||ui->lineEdit_sqlPort->text().trimmed().isEmpty()
            ||ui->lineEdit_sqlUserName->text().trimmed().isEmpty())
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("设置项不能为空！");
        tip->show();
        return;
    }
    QProcess * cmd = new QProcess;
    QString sqlIP = "ping "+ui->lineEdit_sqlIP->text() + " -n 1 -w 100";
    QString serverIP = "ping "+ui->lineEdit_serverIP->text() + " -n 1 -w 100";
    cmd->start(sqlIP);
    cmd->waitForReadyRead();
    cmd->waitForFinished();
    QString results = cmd->readAll();

    if(results.indexOf("TTL") == -1)
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("设置的数据库IP是无效IP地址！");
        tip->show();
        return;
    }
    results.clear();
    cmd->start(serverIP);
    cmd->waitForReadyRead();
    cmd->waitForFinished();
    results = cmd->readAll();

    if(results.indexOf("TTL") == -1)
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("设置的服务器IP是无效IP地址！");
        tip->show();
        return;
    }
    //判断数据库是否能打开成功
    if(QSqlDatabase::database().isOpen())
    {
        QSqlDatabase::database().close();
    }
    Widget::sqlIP = ui->lineEdit_sqlIP->text().trimmed();
    Widget::sqlPort = ui->lineEdit_sqlPort->text().trimmed().toInt();
    Widget::sqlUserName = ui->lineEdit_sqlUserName->text().trimmed();
    Widget::sqlPassword = ui->lineEdit_sqlPassword->text().trimmed();
    Widget::sqlBaseName = ui->lineEdit_sqlBaseName->text().trimmed();
    if(!Widget::openMySql())
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("数据库设置不成功！");
        tip->show();
        return;
    }
    QFile file(qApp->applicationDirPath()+"/OASetting.dat");
    if(file.open(QIODevice::Truncate|QIODevice::WriteOnly))
    {
        file.write(ui->lineEdit_sqlIP->text().trimmed().toLatin1()+"\n");
        file.write(ui->lineEdit_sqlPort->text().trimmed().toLatin1()+"\n");
        file.write(ui->lineEdit_sqlUserName->text().trimmed().toLatin1()+"\n");
        file.write(ui->lineEdit_sqlPassword->text().trimmed().toLatin1()+"\n");
        file.write(ui->lineEdit_sqlBaseName->text().trimmed().toLatin1()+"\n");
        file.write(ui->lineEdit_serverIP->text().trimmed().toLatin1()+"\n");
        file.write(ui->lineEdit_serverPort->text().trimmed().toLatin1()+"\n");
        file.close();
        showDontUpdateDialog * tip = new showDontUpdateDialog("设置成功！");
        tip->show();
        this->close();
    }
}
