#include "tybh_sub.h"
#include "ui_tybh_sub.h"
#include "widget.h"
#include <QDateTime>

Tybh_sub::Tybh_sub(QString proNum,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tybh_sub)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("新增项目图样编号");
//    ui->lineEdit_dealTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"));
//    ui->lineEdit_name->setText(LoginWindow::userName);
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec("select name from staffmsg where onWork = '在职'"))
    {
        int nameNum = query.size();
        for(int i = 0;i != nameNum;++i)
        {
            query.next();
            ui->comboBox_proLeader->addItem(query.value(0).toString());
        }
    }
    TybhMainFrame::proTypeComboxInit(ui->comboBox_proType);
    //修改模式
    if(proNum.trimmed().size() > 0)
    {
        if(query.exec(tr("select * from tybhmsg where projNum = '%1'").arg(proNum)))
        {
            if(query.size())
            {
                query.next();
                ui->lineEdit_proNum->setText(proNum);
                ui->lineEdit_proNum->setEnabled(false);
                ui->lineEdit_proName->setText(query.value(1).toString());
                ui->lineEdit_productNum->setText(query.value(2).toString());
                ui->lineEdit_productName->setText(query.value(3).toString());
                ui->comboBox_proLeader->setCurrentText(query.value(4).toString());
                ui->comboBox_proType->setCurrentText(query.value(5).toString());
                ui->pushButton->setText("提交修改");
            }
        }
    }
}

Tybh_sub::~Tybh_sub()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void Tybh_sub::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void Tybh_sub::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void Tybh_sub::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}


void Tybh_sub::on_toolButton_clicked()
{
    this->close();
}

void Tybh_sub::on_pushButton_clicked()
{
    if(LoginWindow::userLevel != 5)
    {
        showDontUpdateDialog * dontUpdate4 = new showDontUpdateDialog("您没有权限操作！ ");
        dontUpdate4->show();
        return;
    }
    if(ui->lineEdit_productName->text().trimmed().isEmpty()
            ||ui->lineEdit_productNum->text().trimmed().isEmpty()||ui->lineEdit_proName->text().trimmed().isEmpty()
            ||ui->lineEdit_proNum->text().trimmed().isEmpty()||ui->comboBox_proLeader->currentText().isEmpty())
    {
        showDontUpdateDialog * dontUpdate4 = new showDontUpdateDialog("输入项不能为空！ ");
        dontUpdate4->show();
        return;
    }
    //打开数据库
    Widget::openMySql();
    QSqlQuery query;
    //修改情况
    if(ui->pushButton->text() == "提交修改")
    {
        if(query.exec(tr("update tybhmsg set projName = '%1',prodNum = '%2',prodName = '%3',proLeaderName = '%4',proType = '%5' where projNum = '%6'")
                      .arg(ui->lineEdit_proName->text()).arg(ui->lineEdit_productNum->text()).arg(ui->lineEdit_productName->text()).arg(ui->comboBox_proLeader->currentText())
                      .arg(ui->comboBox_proType->currentText()).arg(ui->lineEdit_proNum->text())))
        {
            QSqlDatabase::database().commit();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("修改成功！");
            dontUpdate->show();
            ui->comboBox_proType->setCurrentText(0);
            emit sendFlushFatherTableSig();
            this->close();
        }else{
            QSqlDatabase::database().rollback();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交修改失败,请重试！");
            dontUpdate->show();
        }
        return;
    }
    //新增保存情况

    if(query.exec(tr("select count(*) from tybhMsg where projNum = '%1'").arg(ui->lineEdit_proNum->text().trimmed())))
    {
        query.next();
        if(query.value(0).toInt() > 0)
        {
            showDontUpdateDialog * dontUpdate4 = new showDontUpdateDialog("项目代号已存在,请查正！");
            dontUpdate4->show();
            return;
        }
    }
    if(query.exec(tr("insert into tybhmsg values('%1','%2','%3','%4','%5','%6','%7','进行中···')").arg(ui->lineEdit_proNum->text().trimmed())
                  .arg(ui->lineEdit_proName->text().trimmed()).arg(ui->lineEdit_productNum->text().trimmed()).arg(ui->lineEdit_productName->text().trimmed())
                  .arg(ui->comboBox_proLeader->currentText()).arg(ui->comboBox_proType->currentText()).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd/hh:mm:ss"))))
    {
        QSqlDatabase::database().commit();
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("保存成功！");
        dontUpdate->show();
        ui->comboBox_proType->setCurrentText(0);
        emit sendFlushFatherTableSig();
        this->close();
    }else{
        QSqlDatabase::database().rollback();
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交申请失败,请重试！");
        dontUpdate->show();
    }
}
