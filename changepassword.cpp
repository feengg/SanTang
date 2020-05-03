#include "changepassword.h"
#include "ui_changepassword.h"
#include <QMessageBox>
#include "widget.h"

ChangePassword::ChangePassword(QString staffid,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("修改密码");
    ui->lineEdit_staffid->setText(staffid);
    ui->lineEdit_oldPassw->setEchoMode(QLineEdit::Password);
    ui->lineEdit_newPassw->setEchoMode(QLineEdit::Password);
    ui->lineEdit_recheckPassw->setEchoMode(QLineEdit::Password);

}

ChangePassword::~ChangePassword()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void ChangePassword::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void ChangePassword::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void ChangePassword::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void ChangePassword::on_pushButton_clicked()
{
    if(ui->lineEdit_staffid->text().trimmed().isEmpty()||ui->lineEdit_oldPassw->text().isEmpty()||ui->lineEdit_recheckPassw->text().isEmpty()
            ||ui->lineEdit_newPassw->text().isEmpty())
    {
        //QMessageBox::warning(this,"OA提示:","输入不能为空！  ",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("输入不能为空！");
        dontUpdate->show();
        return;
    }
    if(ui->lineEdit_newPassw->text() != ui->lineEdit_recheckPassw->text())
    {
        //QMessageBox::warning(this,"OA提示:","输入的两次新密码不一致！  ",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("输入的两次新密码不一致！！");
        dontUpdate->show();
        return;
    }
    if(!QSqlDatabase::database().isValid())
    {
        if(!Widget::openMySql())
        {
            QMessageBox::warning(this,"警告",tr("请确认服务器主机是否关闭!\n连接数据库失败:%1").arg(QSqlDatabase::database().lastError().text()),QMessageBox::Ok);
            return;
        }
    }
    //
    QSqlQuery query;
    query.exec(tr("select count(staffID) from staffmsg where staffid = '%1'").arg(ui->lineEdit_staffid->text().trimmed()));
    query.next();
    if(query.value(0) == 0)
    {
        //QMessageBox::warning(this,"警告","工号错误！",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("工号错误！");
        dontUpdate->show();
    }
    else{
        query.exec(tr("select staffpassword,name,level,staffid,ip from staffmsg where staffid = '%1'").arg(ui->lineEdit_staffid->text().trimmed()));
        query.next();
        if(query.value(0) != ui->lineEdit_oldPassw->text())
        {
            //QMessageBox::warning(this,"警告","密码错误！",QMessageBox::Ok);
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("密码错误！");
            dontUpdate->show();

        }else{

            //认证成功
            if(query.exec(tr("update staffmsg set staffPassword = '%1' where staffid = '%2'").arg(ui->lineEdit_newPassw->text()).arg(ui->lineEdit_staffid->text().trimmed())))
            {
                //QMessageBox::about(this,"OA提示:","修改密码成功！");
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("修改密码成功！");
                dontUpdate->show();
                QSqlDatabase::database().commit();
                this->close();
            }else
            {
                QSqlDatabase::database().rollback();
                 //QMessageBox::warning(this,"OA提示:","修改密码失败，请重试！  ",QMessageBox::Ok);
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("修改密码失败，请重试！");
                dontUpdate->show();
            }
        }
    }
}

void ChangePassword::on_toolButton_clicked()
{
    this->close();
}
