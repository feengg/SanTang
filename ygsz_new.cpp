#include "ygsz_new.h"
#include "ui_ygsz_new.h"

YGSZ_New::YGSZ_New(int show_model,QWidget *parent,QString staffID,QString name,QString sex,QString department,QString position,QString marriage
        ,QString phone,QString ip,QString workTime,QString address,QString edu,QString idCard) :
    QWidget(parent),
    ui(new Ui::YGSZ_New)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle("员工信息");
    ui->calendarWidget->hide();
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);

    ui->comboBox_marriage->addItem("已婚");
    ui->comboBox_marriage->addItem("未婚");
    ui->comboBox_marriage->setCurrentText("未婚");
    ui->comboBox_sex->addItem("男");
    ui->comboBox_sex->addItem("女");
    ui->comboBox_department->setCurrentText("研发部");
    ui->comboBox_department->addItem("研发部");
    ui->comboBox_department->addItem("财务部");
    ui->comboBox_department->addItem("市场部");
    ui->comboBox_department->addItem("总工办");
    ui->comboBox_department->addItem("总经办");
    ui->comboBox_department->addItem("质管部");
    ui->comboBox_department->addItem("生产部");
    ui->comboBox_edu->addItem("专科");
    ui->comboBox_edu->addItem("本科");
    ui->comboBox_edu->addItem("硕士");
    ui->comboBox_edu->addItem("博士");
    ui->comboBox_edu->setCurrentText("本科");
    showModel = show_model;
    if(showModel == 0)
    {
        ui->label_title->setText("新增员工信息");
    }
    //修改模式
    if(showModel == 1)
    {
        ui->lineEdit_staffID->setText(staffID);
        ui->lineEdit_name->setText(name);
        ui->comboBox_sex->setCurrentText(sex);
        ui->comboBox_department->setCurrentText(department);
        ui->lineEdit_position->setText(position);
        ui->comboBox_marriage->setCurrentText(marriage);
        ui->lineEdit_phone->setText(phone);
        ui->lineEdit_ip->setText(ip);
        ui->lineEdit_workTime->setText(workTime);
        ui->lineEdit_address->setText(address);
        ui->lineEdit_idCard->setText(idCard);
        ui->comboBox_edu->setCurrentText(edu);
        ui->label_title->setText("修改员工信息");
    }
    //查看模式
    if(showModel == 2)
    {
        ui->lineEdit_staffID->setEnabled(false);
        ui->lineEdit_name->setEnabled(false);
        ui->comboBox_sex->setEnabled(false);
        ui->comboBox_department->setEnabled(false);
        ui->lineEdit_position->setEnabled(false);
        ui->comboBox_marriage->setEnabled(false);
        ui->lineEdit_phone->setEnabled(false);
        ui->lineEdit_ip->setEnabled(false);
        ui->lineEdit_workTime->setEnabled(false);
        ui->lineEdit_address->setEnabled(false);
        ui->comboBox_edu->setEnabled(false);
        ui->lineEdit_idCard->setEnabled(false);
        ui->toolButton_time->setEnabled(false);
        //初始化值
        ui->lineEdit_staffID->setText(staffID);
        ui->lineEdit_name->setText(name);
        ui->comboBox_sex->setCurrentText(sex);
        ui->comboBox_department->setCurrentText(department);
        ui->lineEdit_position->setText(position);
        ui->comboBox_marriage->setCurrentText(marriage);
        ui->lineEdit_phone->setText(phone);
        ui->lineEdit_ip->setText(ip);
        ui->lineEdit_workTime->setText(workTime);
        ui->lineEdit_address->setText(address);
        ui->lineEdit_idCard->setText(idCard);
        ui->comboBox_edu->setCurrentText(edu);
        ui->label_title->setText("查看员工信息");
    }
}

YGSZ_New::~YGSZ_New()
{
    delete ui;
}

void YGSZ_New::on_toolButton_2_clicked()
{
    this->close();
}

void YGSZ_New::on_pushButton_clicked()
{
    //查看
    if(showModel == 2)
    {
        this->close();
        return;
    }
    //修改
    if(1)
    {
        //权限
        if(LoginWindow::userLevel != 2)
        {
            //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
            dontUpdate->show();
            return;
        }
#if 0
        if(ui->lineEdit_staffID->text().trimmed().isEmpty() || ui->lineEdit_name->text().trimmed().isEmpty()
                ||ui->lineEdit_ip->text().trimmed().isEmpty()||ui->lineEdit_workTime->text().trimmed().isEmpty()
                ||ui->lineEdit_idCard->text().trimmed().isEmpty())
        {
            QMessageBox::about(this,"提示","必填信息不能为空！  ");
            return;
        }
        if(ui->lineEdit_ip->text().mid(0,10) != "192.168.1." || ui->lineEdit_ip->text().size()<11 || ui->lineEdit_ip->text().size() > 13)
        {
            QMessageBox::about(this,"提示","输入IP地址有误！  ");
            return;
        }
#endif
        //打开成功
        if(Widget::openMySql())
        {
            QSqlQuery query;
            if(showModel == 0)
            {
                bool ret = query.exec(tr("insert into staffmsg values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','0','123456','%11','%12','在职');").arg(ui->lineEdit_staffID->text()).arg(ui->lineEdit_name->text())
                           .arg(ui->comboBox_sex->currentText()).arg(ui->comboBox_department->currentText()).arg(ui->lineEdit_position->text()).arg(ui->comboBox_marriage->currentText())
                           .arg(ui->lineEdit_phone->text()).arg(ui->lineEdit_ip->text()).arg(ui->lineEdit_address->text())
                           .arg(ui->lineEdit_workTime->text()).arg(ui->comboBox_edu->currentText()).arg(ui->lineEdit_idCard->text()));
                if(ret == false)
                {
                    QSqlDatabase::database().rollback();
                    QMessageBox::warning(this,"提示",tr("保存失败:%1 ").arg(query.lastError().text()));
                    return;

                }else
                {
                    QSqlDatabase::database().commit();
                    QMessageBox::about(this,"提示","添加成功！  ");
                    emit emitFlushYgszSig();
                    this->close();
                }
            }
            if(showModel == 1)
            {
                bool ret = query.exec(tr("update staffmsg set name='%2',sex='%3',department='%4',position='%5',marriage='%6',phone='%7',ip='%8',address='%9',worktime='%10',学历='%11',身份证='%12' where staffid='%13';").arg(ui->lineEdit_name->text())
                           .arg(ui->comboBox_sex->currentText()).arg(ui->comboBox_department->currentText()).arg(ui->lineEdit_position->text()).arg(ui->comboBox_marriage->currentText())
                           .arg(ui->lineEdit_phone->text()).arg(ui->lineEdit_ip->text()).arg(ui->lineEdit_address->text())
                           .arg(ui->lineEdit_workTime->text()).arg(ui->comboBox_edu->currentText()).arg(ui->lineEdit_idCard->text()).arg(ui->lineEdit_staffID->text()));
                if(ret == false)
                {

                    QSqlDatabase::database().rollback();
                    qDebug() << "sql:" << tr("update staffmsg set name='%2',sex='%3',department='%4',position='%5',marriage='%6',phone='%7',ip='%8',address='%9',worktime='%10' where staffid='%11';").arg(ui->lineEdit_name->text())
                                .arg(ui->comboBox_sex->currentText()).arg(ui->comboBox_department->currentText()).arg(ui->lineEdit_position->text()).arg(ui->comboBox_marriage->currentText())
                                .arg(ui->lineEdit_phone->text()).arg(ui->lineEdit_ip->text()).arg(ui->lineEdit_address->text())
                                .arg(ui->lineEdit_workTime->text()).arg(ui->lineEdit_staffID->text());
                    QMessageBox::warning(this,"提示",tr("保存失败:%1 ").arg(query.lastError().text()));
                    return;

                }else
                {
                    QSqlDatabase::database().commit();
                    QMessageBox::about(this,"提示","修改成功！  ");
                    this->close();
                }
            }
            QSqlDatabase::database().close();
            emit emitFlushYgszSig();
        }
    }
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void YGSZ_New::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void YGSZ_New::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void YGSZ_New::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void YGSZ_New::on_toolButton_time_clicked()
{
    ui->calendarWidget->show();

}

void YGSZ_New::on_calendarWidget_selectionChanged()
{
    ui->lineEdit_workTime->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    ui->calendarWidget->hide();
}


