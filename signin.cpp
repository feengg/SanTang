#include "signin.h"
#include "ui_signin.h"

QString SignIn::userName = NULL;
int SignIn::userLevel = 0;
QString SignIn::staffID = NULL;
QString SignIn::myIP = NULL;

SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
    this->setWindowFlags( Qt::FramelessWindowHint);
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/log.jpg").scaled(this->size())));
    this->setPalette(palette);
    ui->label_3->setStyleSheet("color:rgb(50,50,255)");
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("登录");
}

SignIn::~SignIn()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void SignIn::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void SignIn::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void SignIn::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void SignIn::on_pushButton_2_clicked()
{
    this->close();
}

void SignIn::on_pushButton_clicked()
{
    QSqlDatabase db =  QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.1.44");
    db.setDatabaseName("mySql5.6");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open())
    {
        QMessageBox::warning(this,"警告",tr("连接数据库失败:%1").arg(db.lastError().text()),QMessageBox::Ok);
    }else
    {
        QSqlQuery query;
        query.exec(tr("select count(staffID) from staffmsg where staffid = '%1'").arg(ui->lineEdit_name->text()));
        query.next();
        if(query.value(0) == 0)
        {
            QMessageBox::warning(this,"警告","工号错误",QMessageBox::Ok);
            db.close();

        }
        else{
            query.exec(tr("select staffpassword,name,level,staffid,ip from staffmsg where staffid = '%1'").arg(ui->lineEdit_name->text()));
            query.next();
            if(query.value(0) != ui->lineEdit_password->text())
            {
                QMessageBox::warning(this,"警告","密码错误！",QMessageBox::Ok);
                db.close();


            }else{
                //主窗体显示
                //QMessageBox::warning(this,"警告","登录成功！",QMessageBox::Ok);
                userName = query.value(1).toString();
                userLevel = query.value(2).toInt();
                staffID = query.value(3).toString();
                myIP = query.value(4).toString();
                Widget * widget = new Widget;
                widget->show();
                SignIn::close();
                db.close();
            }
        }
    }
}
