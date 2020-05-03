#include "kcgl_subitem.h"
#include "ui_kcgl_subitem.h"
#include "widget.h"

KCGL_subItem::KCGL_subItem(QString showType,QString itemNum,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KCGL_subItem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/采购申请背景图.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("库存操作");
    //打开数据库
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    query.exec("select distinct 仓位 from storebill");
    for(int i = 0 ;i < query.size();i++)
    {
        query.next();
        ui->comboBox_12->addItem(query.value(0).toString());
    }
    if(showType == "查看")
    {
//        ui->lineEdit_1->setEnabled(false);
//        ui->lineEdit_2->setEnabled(false);
//        ui->lineEdit_3->setEnabled(false);
//        ui->lineEdit_4->setEnabled(false);
//        ui->lineEdit_5->setEnabled(false);
//        ui->lineEdit_6->setEnabled(false);
//        ui->lineEdit_7->setEnabled(false);
//        ui->lineEdit_8->setEnabled(false);
//        ui->comboBox_12->setEnabled(false);
//        ui->lineEdit_9->setEnabled(false);
//        ui->lineEdit_10->setEnabled(false);
//        ui->lineEdit_11->setEnabled(false);
//        ui->lineEdit_13->setEnabled(false);
//        ui->lineEdit_14->setEnabled(false);
//        ui->lineEdit_15->setEnabled(false);
        //初始值
        qDebug() << "sql = " << tr("select * from storebill where 物料编号 = '%1'").arg(itemNum);
        if(query.exec(tr("select * from storebill where 物料编号 = '%1'").arg(itemNum)))
        {
            query.next();
            ui->lineEdit_1->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
            ui->lineEdit_5->setText(query.value(4).toString());
            ui->lineEdit_6->setText(query.value(5).toString());
            ui->lineEdit_7->setText(query.value(6).toString());
            ui->lineEdit_8->setText(query.value(7).toString());
            ui->lineEdit_9->setText(query.value(8).toString());
            ui->lineEdit_10->setText(query.value(9).toString());
            ui->lineEdit_11->setText(query.value(10).toString());
            ui->comboBox_12->setCurrentText(query.value(11).toString());
            ui->lineEdit_13->setText(query.value(12).toString());
            ui->lineEdit_14->setText(query.value(13).toString());
            ui->lineEdit_15->setText(query.value(14).toString());
        }
        ui->groupBox->setTitle("查看库存");
    }
    if(showType == "修改")
    {
        //初始值
        //qDebug() << "sql = " << tr("select * from storebill where 物料编号 = '%1'").arg(itemNum);
        if(query.exec(tr("select * from storebill where 物料编号 = '%1'").arg(itemNum)))
        {
            query.next();
            ui->lineEdit_1->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
            ui->lineEdit_5->setText(query.value(4).toString());
            ui->lineEdit_6->setText(query.value(5).toString());
            ui->lineEdit_7->setText(query.value(6).toString());
            ui->lineEdit_8->setText(query.value(7).toString());
            ui->lineEdit_9->setText(query.value(8).toString());
            ui->lineEdit_10->setText(query.value(9).toString());
            ui->lineEdit_11->setText(query.value(10).toString());
            ui->comboBox_12->setCurrentText(query.value(11).toString());
            ui->lineEdit_13->setText(query.value(12).toString());
            ui->lineEdit_14->setText(query.value(13).toString());
            ui->lineEdit_15->setText(query.value(14).toString());
        }
        ui->lineEdit_2->setEnabled(false);
        ui->groupBox->setTitle("修改库存");
        ui->pushButton->setText("提交修改");

    }
    if(showType == "新增")
    {
        ui->groupBox->setTitle("新增库存");
        ui->pushButton->setText("提交新增");
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec("select max(序号) from storebill"))
        {
            query.next();
            qDebug() <<"num = " <<query.value(0).toString();
            ui->lineEdit_1->setText(QString::number(query.value(0).toInt()+1));
            //ui->lineEdit_1->setEnabled(false);
        }
    }
}

KCGL_subItem::~KCGL_subItem()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void KCGL_subItem::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void KCGL_subItem::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void KCGL_subItem::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void KCGL_subItem::on_toolButton_clicked()
{
    this->close();
}

void KCGL_subItem::on_pushButton_clicked()
{

    if(ui->pushButton->text() == "确 定")
    {
        this->close();
    }

    if(ui->pushButton->text() == "提交修改")
    {
        //权限
        if(LoginWindow::userLevel != 3)
        {
            //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
            dontUpdate->show();
            return;
        }
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
//        qDebug() << "updateSql = " << tr("update storebill set 序号='%1',物料编号='%2',物料名称='%3',规格型号='%4',入库数='%5',送检人='%6',检验日期='%7',检验结果='%8',检验报告编号='%9',"
//                                         "出库数='%10',库存='%11',仓位='%12',有/领完='%13',供应商='%14',项目号='%15' where 物料编号='%16'").arg(ui->lineEdit_1->text().toInt()).arg(ui->lineEdit_2->text())
//                                      .arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->lineEdit_6->text())
//                                      .arg(ui->lineEdit_7->text()).arg(ui->lineEdit_8->text()).arg(ui->lineEdit_9->text()).arg(ui->lineEdit_10->text())
//                                      .arg(ui->lineEdit_11->text()).arg(ui->comboBox_12->currentText()).arg(ui->lineEdit_13->text()).arg(ui->lineEdit_14->text()).arg(ui->lineEdit_15->text()).arg(ui->lineEdit_2->text());

        if(query.exec(tr("update storebill set 序号='%1',物料编号='%2',物料名称='%3',规格型号='%4',入库数='%5',送检人='%6',检验日期='%7',检验结果='%8',检验报告编号='%9',"
                         "出库数='%10',库存='%11',仓位='%12',有领完='%13',供应商='%14',项目号='%15' where 物料编号='%16'").arg(ui->lineEdit_1->text().toInt()).arg(ui->lineEdit_2->text())
                      .arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->lineEdit_6->text())
                      .arg(ui->lineEdit_7->text()).arg(ui->lineEdit_8->text()).arg(ui->lineEdit_9->text()).arg(ui->lineEdit_10->text())
                      .arg(ui->lineEdit_11->text()).arg(ui->comboBox_12->currentText()).arg(ui->lineEdit_13->text()).arg(ui->lineEdit_14->text()).arg(ui->lineEdit_15->text()).arg(ui->lineEdit_2->text())))
        {
            QSqlDatabase::database().commit();
            emit emitFlushKCGLModelSig();
            //QMessageBox::about(this,"提示","修改库存成功！    ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("修改库存成功！");
            dontUpdate->show();
            this->close();
        }else
        {
            QSqlDatabase::database().rollback();

            QMessageBox::about(this,"提示","操作失败！    ");

        }
    }
    if(ui->pushButton->text() == "提交新增")
    {
        //权限
        if(LoginWindow::userLevel != 3)
        {
            //QMessageBox::about(this,"OA提示","您没有权限操作！   ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("您没有权限操作！");
            dontUpdate->show();
            return;
        }
        if(!QSqlDatabase::database().isValid())
        {
            Widget::openMySql();
        }
        QSqlQuery query;
        if(query.exec(tr("select * from storebill where 物料编号 = '%1'").arg(ui->lineEdit_2->text().trimmed())))
        {
            if(query.size())
            {
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("库存中已存在此物料编号！");
                dontUpdate->show();
                return;
            }
        }
        if(query.exec(tr("insert into storebill values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10'"
                         ",'%11','%12','%13','%14','%15')").arg(ui->lineEdit_1->text().toInt()).arg(ui->lineEdit_2->text())
                      .arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(ui->lineEdit_6->text())
                      .arg(ui->lineEdit_7->text()).arg(ui->lineEdit_8->text()).arg(ui->lineEdit_9->text()).arg(ui->lineEdit_10->text())
                      .arg(ui->lineEdit_11->text()).arg(ui->comboBox_12->currentText()).arg(ui->lineEdit_13->text()).arg(ui->lineEdit_14->text()).arg(ui->lineEdit_15->text())))
        {
            QSqlDatabase::database().commit();
            emit emitFlushKCGLModelSig();
            //QMessageBox::about(this,"提示","修改库存成功！    ");
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("提交成功！");
            dontUpdate->show();
            this->close();
        }else
        {
            QSqlDatabase::database().rollback();

            QMessageBox::about(this,"提示","操作失败！    ");

        }
    }
}




void KCGL_subItem::on_toolButton_inTime_clicked()
{
    //ui->calendarWidget->show();
}

void KCGL_subItem::on_calendarWidget_selectionChanged()
{
//    ui->lineEdit_inTime->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
//    ui->calendarWidget->hide();
}
