#include "tybhmainframe.h"
#include "ui_tybhmainframe.h"

TybhMainFrame::TybhMainFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TybhMainFrame)
{
    ui->setupUi(this);
    Widget::uiInit(this,"项目图/文编号管理");
    //打开数据库
    Widget::openMySql();
    //初始化本ui
    uiInit();
    //显示初始table
    flushTableSlot();
}

TybhMainFrame::~TybhMainFrame()
{
    delete ui;
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void TybhMainFrame::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void TybhMainFrame::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void TybhMainFrame::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void TybhMainFrame::proTypeComboxInit(QComboBox *combox,QString type)
{
    if(type == "all")
    {
        combox->addItem("所有类型");
    }
    combox->addItem("遥测遥控类");
    combox->addItem("数据链传输类");
    combox->addItem("泛通信类");
    combox->addItem("卫星导航类");
    combox->addItem("微波产品类");
    combox->addItem("测控类");
    combox->addItem("软件类");
    combox->addItem("航空电子类");
}
void TybhMainFrame::uiInit()
{
    //初始化table
    ui->tableWidget->setColumnCount(7);
    QStringList header;
    header << "项目代号" << "项目名称" << "产品代号" << "产品名称" << "项目分类" << "项目负责任人" << "点击查看";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnWidth(1,230);
    ui->tableWidget->setColumnWidth(3,230);
    ui->tableWidget->setColumnWidth(2,130);
    ui->tableWidget->setColumnWidth(0,120);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能编辑
    connect(ui->tableWidget,SIGNAL(cellPressed(int,int)),SLOT(dealCellEnteredSlot(int,int)));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),SLOT(dealCellClickedSlot(int,int)));
    //初始化项目类型combobox
    proTypeComboxInit(ui->comboBox_proType,"all");
    //右键菜单
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    //菜单信号槽
    connect(ui->tableWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(dealMenu(QPoint)));
}

void TybhMainFrame::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void TybhMainFrame::on_pushButton_close_clicked()
{
    this->close();
}

void TybhMainFrame::on_pushButton_new_clicked()
{
    Tybh_sub * addPro = new Tybh_sub;
    connect(addPro,SIGNAL(sendFlushFatherTableSig()),this,SLOT(flushTableSlot()));
    addPro->show();
}

void TybhMainFrame::flushTableSlot()
{
    Widget::openMySql();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QString proType;
    if(ui->comboBox_proType->currentText() != "所有类型")
    {
        proType = ui->comboBox_proType->currentText();
    }
    QSqlQuery query;

    if(query.exec(tr("select projNum,projName,prodNum,prodName,protype,proLeaderName,dealState from tybhmsg where protype like '%%1%' order by dealtime desc").arg(proType)))
    {
        if(query.size())
        {
            ui->tableWidget->setRowCount(query.size());
            for(int i = 0; i != query.size();++i)
            {
                query.next();
                for(int j = 0; j != 7;++j)
                {
                    QTableWidgetItem * tempItem = new QTableWidgetItem(query.value(j).toString());
                    tempItem->setTextAlignment(Qt::AlignCenter);
                    tempItem->setToolTip(query.value(j).toString());
                    if(j == 6)
                    {
                        tempItem->setBackgroundColor(QColor(235,235,235));                       
                        if(query.value(j).toString() == "进行中···")
                        {
                            tempItem->setTextColor(Qt::red);
                            tempItem->setToolTip("点击进入流程");
                        }else{
                            tempItem->setTextColor(Qt::blue);
                            tempItem->setToolTip("点击查看");
                        }

                    }
                    ui->tableWidget->setItem(i,j,tempItem);
                }
            }
        }
    }
}

void TybhMainFrame::on_comboBox_proType_currentTextChanged(const QString &)
{
    flushTableSlot();
}

void TybhMainFrame::dealCellEnteredSlot(int row,int col)
{
    if(col == 6)
    {
        if(ui->tableWidget->item(row,col)->text() == "进行中···")
        {
            ui->tableWidget->item(row,col)->setTextColor(Qt::darkRed);
        }
        else{
            ui->tableWidget->item(row,col)->setTextColor(Qt::darkBlue);
        }
    }
}
//
void TybhMainFrame::dealCellClickedSlot(int row,int col)
{
    if(col == 6)
    {
        if(ui->tableWidget->item(row,6)->text() == "已结项")
        {
            TYBH * tybh = new TYBH("Look",ui->tableWidget->item(row,0)->text());
            connect(tybh,SIGNAL(sendFlushFatherTableSig()),this,SLOT(flushTableSlot()));
            tybh->show();
        }
        else
        {
            TYBH * tybh = new TYBH("Edit",ui->tableWidget->item(row,0)->text());
            connect(tybh,SIGNAL(sendFlushFatherTableSig()),this,SLOT(flushTableSlot()));
            tybh->show();
        }
    }
}
//定义菜单槽函数
void TybhMainFrame::dealMenu(QPoint pos)
{
    QModelIndex index = ui->tableWidget->indexAt(pos);
    if(index.isValid())
    {
        if(LoginWindow::userLevel == 5)
        {
            QMenu * menu = new QMenu(ui->tableWidget);
            QAction * editAction = new QAction("修改",ui->tableWidget);
            QAction * delAction = new QAction("删除",ui->tableWidget);
            connect(editAction,SIGNAL(triggered(bool)),this,SLOT(dealEditSlot()));
            connect(delAction,SIGNAL(triggered(bool)),this,SLOT(dealDeleteSlot()));
            menu->addAction(editAction);
            menu->addAction(delAction);
            menu->exec(QCursor::pos());
        }
    }
}

void TybhMainFrame::dealEditSlot()
{
    Tybh_sub * editSub = new Tybh_sub(ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text());
    connect(editSub,SIGNAL(sendFlushFatherTableSig()),this,SLOT(flushTableSlot()));
    editSub->show();
}

void TybhMainFrame::dealDeleteSlot()
{
    QMessageBox msgBox;
    msgBox.setDefaultButton(QMessageBox::No);
    int ret =  msgBox.warning(this,"删除提示","确定删除吗?   ",QMessageBox::Yes | QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        QString projNum = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();
        Widget::openMySql();
        QSqlQuery query;
        if(query.exec(tr("delete from tybhprodmsg where projNum = '%1'").arg(projNum)))
        {
            QSqlDatabase::database().commit();
            if(query.exec(tr("delete from tybhmsg where projNum = '%1'").arg(projNum)))
            {
                QSqlDatabase::database().commit();
                showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除成功！");
                dontUpdate->show();
                ui->comboBox_proType->setCurrentText(0);
                flushTableSlot();
            }else{
                QSqlDatabase::database().rollback();
            }
        }else
        {
            QSqlDatabase::database().rollback();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除失败，请重试！");
            dontUpdate->show();
        }
    }
}
