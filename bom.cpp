#include "bom.h"
#include "ui_bom.h"


Bom::Bom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bom)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/对话框.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    this->setWindowTitle("BOM单处理");
    QFile file1(qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx");
    if(file1.exists())
    {
        QDir dir(qApp->applicationDirPath());
        dir.cd("excelSource");
        while(!dir.remove("采购清单-tempt.xlsx"))
        {
            continue;
        }
    }
    QFile file2(qApp->applicationDirPath()+"/excelSource/电装明细表-tempt.doc");
    if(file2.exists())
    {
        QDir dir(qApp->applicationDirPath());
        dir.cd("excelSource");
        while(!dir.remove("电装明细表-tempt.doc"))
        {
            continue;
        }
    }
    QFile file3(qApp->applicationDirPath()+"/excelSource/storeBill-tempt.xlsx");
    if(file3.exists())
    {
        QDir dir(qApp->applicationDirPath());
        dir.cd("excelSource");
        while(!dir.remove("storeBill-tempt.xlsx"))
        {
            continue;
        }
    }
    //ui->lineEdit->setText("D:/nwt/孙永健/ZY306_ADS-B_20180601.xls");
}

Bom::~Bom()
{
    delete ui;
    QFile::remove(qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx");
    QFile::remove(qApp->applicationDirPath()+"/excelSource/电装明细表-tempt.doc");
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void Bom::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void Bom::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void Bom::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void Bom::on_toolButton_clicked()
{
    this->close();
}

void Bom::on_pushButton_loadBom_clicked()
{
    ui->lineEdit->clear();
    bomFilePath = QFileDialog::getOpenFileName(this,tr("选择Bom单"),"./",tr("Bom单文件(*.xlsx *.xls);"));
    ui->lineEdit->setText(bomFilePath);
}

void Bom::on_pushButton_ok_clicked()
{
    this->close();
}

void Bom::on_pushButton_cgqd_clicked()
{
    if(ui->lineEdit->text().trimmed().isEmpty())
    {
        //QMessageBox::warning(this,"提示","请先导入Bom单！  ",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请先导入Bom单!");
        dontUpdate->show();
        return;
    }
    bomFilePath = ui->lineEdit->text();

    QAxObject excel("Excel.Application");
    excel.dynamicCall("SetVisible(bool Visible)","false");
    excel.setProperty("DisplayAlerts",false);//不显示任何警告信息，如关闭“文件已修改，是否保存”
    //打开工作薄
    QAxObject * workbooks = excel.querySubObject("WorkBooks");

    //打开bomExcel
    QAxObject * bomWorkbook = workbooks->querySubObject("Open (const QString&)",bomFilePath);
    QAxObject * bomWorksheet = bomWorkbook->querySubObject("WorkSheets(int)",1);

    //判断bom格式是否正确
    for(int i = 1; i <= 7;i++)
    {
        qDebug() << "1="<< getCellValue(bomWorksheet,1,i).toString();
        if(getCellValue(bomWorksheet,1,i).toString().trimmed() != "Designator" && getCellValue(bomWorksheet,1,i).toString().trimmed() != "Description"
                && getCellValue(bomWorksheet,1,i).toString().trimmed() != "Comment" && getCellValue(bomWorksheet,1,i).toString().trimmed() != "Quantity"
                && getCellValue(bomWorksheet,1,i).toString().trimmed() != "Footprint" && getCellValue(bomWorksheet,1,i).toString().trimmed() != "LibRef"
                && getCellValue(bomWorksheet,1,i).toString().trimmed() != "Class")
        {
            QMessageBox::warning(this,"提示","Bom单格式不对！表格不能有表头信息！\n"
                                           "且需:Designator,Description,Comment,Quantity,Footprint,LibRef,Class字段.  ");
            return;
        }
    }

    QString sheet1Name = bomWorksheet->property("Name").toString();
    QString savePath = QFileDialog::getSaveFileName(this,tr("保存采购清单"),tr("【%1】采购清单.xlsx").arg(sheet1Name),tr("采购清单(*.xlsx *.xls)"));
    if(savePath.isEmpty())
    {
        return;
    }
    //复制模板到临时文件
    if(!QFile::exists(qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx"))
    {
        if(!QFile::copy(qApp->applicationDirPath()+"/excelSource/采购清单.xlsx",qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx"))
        {
            qDebug() << "copy tempt.xlsx error";
            return;
        }
    }
    //打开temptExcel
    QAxObject * cgqdWorkbook = workbooks->querySubObject("Open (const QString&)",qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx");
    QAxObject * cgqdWorksheet = cgqdWorkbook->querySubObject("WorkSheets(int)",1);



    qDebug() << "rowNum = " << getUsedRowsCount(bomWorksheet);
    int rowNum = getUsedRowsCount(bomWorksheet);


    //获取bom单各个字段所在的列号
    int nameNum=0,ggxhNum=0,fzNum=0,slNum=0;
    for(int i= 1;i <=7;i++)
    {
        if(getCellValue(bomWorksheet,1,i).toString()== "Class")
        {
            nameNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Description")
        {
            ggxhNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Footprint")
        {
            fzNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Quantity")
        {
            slNum = i;
        }
    }
    //把bom表格数据复制到tempt里
    //打开数据库判断想要规格型号的器件编号
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    for(int i = 2;i <= rowNum ; i++)
    {
        setCellString(cgqdWorksheet,i+26,1,QVariant(i-1));//序号
        setCellString(cgqdWorksheet,i+26,2,getCellValue(bomWorksheet,i,nameNum));//产品/物料名称
        qDebug() << "规格型号：" << getCellValue(bomWorksheet,i,ggxhNum).toString();
        setCellString(cgqdWorksheet,i+26,5,getCellValue(bomWorksheet,i,ggxhNum));//规格型号/封装
        //查询物料编号
        QVariant  wlbhStr = " ";
        if(query.exec(tr("select 物料编号 from storebill where 规格型号 = '%1'").arg(getCellValue(bomWorksheet,i,ggxhNum).toString())))
        {
            if(query.size())
            {
                query.next();
                wlbhStr = query.value(0);
            }
        }
        setCellString(cgqdWorksheet,i+26,6,wlbhStr);
        setCellString(cgqdWorksheet,i+26,9,getCellValue(bomWorksheet,i,slNum));
        query.exec(tr("select count(*) from storebill where 规格型号='%1'").arg(getCellValue(bomWorksheet,i,ggxhNum).toString().trimmed()));
        query.next();
        if(query.value(0).toInt() > 0)
        {
            //qDebug() << tr("select 库存 from storebill where 规格型号='%1'").arg(getCellValue(bomWorksheet,i,ggxhNum).toString().trimmed());
            query.exec(tr("select 库存 from storebill where 规格型号='%1'").arg(getCellValue(bomWorksheet,i,ggxhNum).toString().trimmed()));
            query.next();
            setCellString(cgqdWorksheet,i+26,12,query.value(0));
        }else
        {
            setCellString(cgqdWorksheet,i+26,12,"0");
        }
    }
    //保存tempt表格
    cgqdWorkbook->dynamicCall("Save()");



    excel.dynamicCall("Quit()");

    if(!QFile::copy(qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx",savePath))
    {
        qDebug() << "copy-tempt.xlsx to user error";
        QFile::remove(savePath);
        QFile::copy(qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx",savePath);
    }
    if(!QFile::remove(qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx"))
    {
        QFile::remove(qApp->applicationDirPath()+"/excelSource/采购清单-tempt.xlsx");
    }
    //QMessageBox::about(this,"导出提示",tr("导出采购清单成功!    "));
    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("导出采购清单成功！");
    dontUpdate->show();

}

QVariant Bom::getCellValue(QAxObject *axObject, int row, int col)
{
    QAxObject * Cell = axObject->querySubObject("Cells(int,int)",row,col);
    return Cell->property("Value");
}

int Bom::getUsedRowsCount(QAxObject * workSheet)
{
    QAxObject *usedRange = workSheet->querySubObject("UsedRange");
    int topRow = usedRange->property("Row").toInt();
    QAxObject *rows = usedRange->querySubObject("Rows");
    int bottomRow = topRow + rows->property("Count").toInt() - 1;
    return bottomRow;
}

void Bom::setCellString(QAxObject * workSheet,int row, int column, const QVariant& value)
{
    QAxObject * range = workSheet->querySubObject("Cells(int,int)", row, column);
    range->setProperty("Value",value);
}

void Bom::on_pushButton_mxb_clicked()
{

    //打开bom清单
    if(ui->lineEdit->text().isEmpty())
    {
        //QMessageBox::warning(this,"提示","请先导入Bom单！  ",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请先导入Bom单！");
        dontUpdate->show();
        return;
    }
    //复制模板到临时文件
    if(!QFile::exists(qApp->applicationDirPath()+"/excelSource/电装明细表-tempt.doc"))
    {
        if(!QFile::copy(qApp->applicationDirPath()+"/excelSource/电装明细表.doc",qApp->applicationDirPath()+"/excelSource/电装明细表-tempt.doc"))
        {
            qDebug() << "copy tempt.xlsx error";
            return;
        }
    }
    //设置excel属性
    QAxObject excel("Excel.Application");
    excel.dynamicCall("SetVisible(bool Visible)","false");
    excel.setProperty("DisplayAlerts",false);//不显示任何警告信息，如关闭“文件已修改，是否保存”
     //打开bomExcel
    bomFilePath = ui->lineEdit->text();
    QAxObject * workbooks = excel.querySubObject("WorkBooks");
    QAxObject * bomWorkbook = workbooks->querySubObject("Open (const QString&)",bomFilePath);
    QAxObject * bomWorksheet = bomWorkbook->querySubObject("WorkSheets(int)",1);
    //判断bom格式是否正确
    for(int i = 1; i <= 7;i++)
    {
        if(getCellValue(bomWorksheet,1,i).toString() != "Designator" && getCellValue(bomWorksheet,1,i).toString() != "Description"
                && getCellValue(bomWorksheet,1,i).toString() != "Comment" && getCellValue(bomWorksheet,1,i).toString() != "Quantity"
                && getCellValue(bomWorksheet,1,i).toString() != "Footprint" && getCellValue(bomWorksheet,1,i).toString() != "LibRef"
                && getCellValue(bomWorksheet,1,i).toString() != "Class")
        {
            QMessageBox::warning(this,"提示","Bom单格式不对！表格不能有表头信息！\n"
                                           "且需:Designator,Description,Comment,Quantity,Footprint,LibRef,Class字段.  ");
            return;
        }
    }
    QString sheet1Name = bomWorksheet->property("Name").toString();
    QString savePath = QFileDialog::getSaveFileName(this,tr("保存电装明细表"),tr("【%1】电装明细表.doc").arg(sheet1Name),tr("电装明细表(*.doc *.docx)"));
    if(savePath.isEmpty())
    {
        return;
    }
    qDebug() << "rowNum = " << getUsedRowsCount(bomWorksheet);
    int rowNum = getUsedRowsCount(bomWorksheet);
    //获取bom单各个字段所在的列号
    int nameNum=0,ggxhNum=0,fzNum=0,slNum=0,designNum=0;
    for(int i= 1;i <=7;i++)
    {
        if(getCellValue(bomWorksheet,1,i).toString()== "Class")
        {
            nameNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Description")
        {
            ggxhNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Footprint")
        {
            fzNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Quantity")
        {
            slNum = i;
        }
        if(getCellValue(bomWorksheet,1,i).toString()== "Designator")
        {
            designNum = i;
        }
    }

    //获取bom单里的name放到list里
    QStringList  nameList;
    for(int i = 2; i <= rowNum;i++)
    {
        nameList.append(getCellValue(bomWorksheet,i,nameNum).toString());
    }
    removeListSame(&nameList);

    QAxObject * m_word = new QAxObject();
    bool bFlag = m_word->setControl("word.Application");
    if(!bFlag)
    {
        bFlag = m_word->setControl("kwps.Application");
    }
    if(!bFlag)
    {
        return;
    }
    m_word->setProperty("Visible",false);
    m_word->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
    QAxObject * documents =m_word->querySubObject("Documents");

    if(!documents)
    {
        return;
    }
    //打开word
    documents->dynamicCall("Add(QString)",qApp->applicationDirPath()+"/excelSource/电装明细表-tempt.doc").toString();
    QAxObject * m_document = m_word->querySubObject("ActiveDocument");//获取当前激活的文档
    QAxObject* selection = m_word->querySubObject("Selection");
    if(nullptr== selection)
    {
        return;
    }

    selection->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphCenter");
    //创建表格
    if(!insertTable(m_document,m_word,rowNum+nameList.size(),7))
    {
        return;
    }
    //setRowAlignment(m_document,1,0); //设置第一行居中对齐
    //设置列间距

    setColumnWidth(m_word,1,115);
    setColumnWidth(m_word,2,85);
    setColumnWidth(m_word,3,120);
    setColumnWidth(m_word,4,40);
    setColumnWidth(m_word,5,27);
    setColumnWidth(m_word,6,60);
    setColumnWidth(m_word,7,30);
    //设置表头
    setCellValue(m_word,1,1,"\n位    号");
    setCellValue(m_word,1,2,"\n编    号");
    setCellValue(m_word,1,3,"名 称 和 型 号\n(基 本 数 据)");
    setCellValue(m_word,1,4,"质量\n等级");
    setCellValue(m_word,1,5,"数\n量");
    setCellValue(m_word,1,6,"\n备  注");
    setCellValue(m_word,1,7,"更\n改");



    //把对应器件类型名字分类写入word中
    int wordRowNum = 2;
    //打开数据库判断想要规格型号的器件编号
    if(!QSqlDatabase::database().isOpen())
    {
        Widget::openMySql();
    }
    QSqlQuery query;
    for(int i = 0;i < nameList.size();i++)
    {
        setCellValue(m_word,wordRowNum,3,nameList.at(i));
        setCellFontBold(m_document,wordRowNum,3);
        wordRowNum++;
        for(int j = 2;j <= rowNum;j++)
        {
            if(getCellValue(bomWorksheet,j,nameNum).toString() == nameList.at(i))
            {
                setCellValue(m_word,wordRowNum,1,getCellValue(bomWorksheet,j,designNum).toString());
                setCellValue(m_word,wordRowNum,3,getCellValue(bomWorksheet,j,ggxhNum).toString());
                setCellValue(m_word,wordRowNum,5,getCellValue(bomWorksheet,j,slNum).toString());
                query.exec(tr("select count(*) from storebill where 规格型号='%1'").arg(getCellValue(bomWorksheet,j,ggxhNum).toString().trimmed()));
                query.next();
                if(query.value(0).toInt() > 0)
                {
                    query.exec(tr("select 物料编号 from storebill where 规格型号='%1'").arg(getCellValue(bomWorksheet,j,ggxhNum).toString().trimmed()));
                    query.next();
                    setCellValue(m_word,wordRowNum,2,query.value(0).toString());
                }
                wordRowNum++;
            }
        }
    }
    //关闭word
    m_document->dynamicCall("SaveAs(const QString&)",savePath);
    m_word->dynamicCall("Quit()");
    //QMessageBox::about(this,"导出提示",tr("导出电装明细表成功!    "));
    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("导出电装明细表成功！");
    dontUpdate->show();
    QFile::remove(qApp->applicationDirPath()+"/excelSource/电装明细表-tempt.doc");
}

/************************************************************************************/

//word插入表格
void Bom::setCellValue(QAxObject * m_word,int row,int col,QString value)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    if(nullptr== selection)
    {
        qDebug() << "selection errr";
        return;
    }
    QAxObject* table = selection->querySubObject("Tables(1)");
    if(nullptr== table)
    {
        qDebug() << "table errr";
        return;
    }
    table->querySubObject("Cell(int, int)",row,col)->querySubObject("Range")->dynamicCall("SetText(QString)",value);
}


////创建表格
bool Bom::insertTable(QAxObject * m_document,QAxObject * m_word,int row,int column)
{

    QAxObject* tables=m_document->querySubObject("Tables");
    if(nullptr==tables)
    {
        return false;
    }
    QAxObject* selection = m_word->querySubObject("Selection");
    if(nullptr==selection)
    {
        return false;
    }
    QAxObject* range = selection->querySubObject("Range");
    if(nullptr==range)
    {
        return false;
    }
    QVariantList params;
    params.append(range->asVariant());
    params.append(row);
    params.append(column);
    tables->querySubObject("Add(QAxObject*, int, int, QVariant&, QVariant&)", params);
    QAxObject* table = selection->querySubObject("Tables(int)",1);
    table->setProperty("Style","网格型");

    QAxObject* Borders = table->querySubObject("Borders");
    if(nullptr==Borders)
    {
        return false;
    }
    Borders->setProperty("InsideLineStyle",1);
    Borders->setProperty("OutsideLineStyle",1);
    return true;
}
//设置行对齐方式
void Bom::setRowAlignment(QAxObject * m_document,int row,int flag)
{
    QAxObject* tables = m_document->querySubObject("Tables");
    if(nullptr== tables)
    {
        return;
    }
    QAxObject* table = tables->querySubObject("Item(int)",1);
    if(nullptr== table )
    {
        return;
    }
    QAxObject* Row= table->querySubObject("Rows(int)",row);
    if(nullptr== Row)
    {
        return;
    }
    QAxObject* range = Row->querySubObject("Range");
    if(nullptr== range)
    {
        return;
    }
    Row->querySubObject("Alignment(int)",flag);
    if(flag == 0)
    {
        range->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphCenter");
    }else if(flag == 1)
    {
        range->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphJustify");
    }else if(flag == 2)
    {
        range->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphRight");
    }else if(flag ==3)
    {
        range->querySubObject("ParagraphFormat")->setProperty("Alignment","wdAlignParagraphLeft");
    }
}
//设置列对齐方式
void Bom::setColumnWidth(QAxObject * m_word,int column, int width)		//设置列宽
{
    QAxObject* selection = m_word->querySubObject("Selection");
    if(nullptr== selection)
    {
        return;
    }
    QAxObject* table = selection->querySubObject("Tables(1)");
    if(nullptr== table)
    {
        return;
    }
    table->querySubObject("Columns(int)",column)->setProperty("Width",width);

}

//设置内容粗体
void Bom::setCellFontBold(QAxObject * m_document,int row,int column)
{
    QAxObject* pTables = m_document->querySubObject("Tables");
    if(nullptr== pTables)
    {
        return;
    }
    QAxObject* table =pTables->querySubObject("Item(int)",1);
    if(nullptr== table)
    {
        return;
    }
    table->querySubObject("Cell(int,int )",row,column)->querySubObject("Range")->dynamicCall("SetBold(int)",true);
}

//QList排重
void Bom::removeListSame(QStringList * list)
{
    for(int i = 0 ; i < list->count();i++)
    {
        for(int k = i+1;k < list->count();k++)
        {
            if(list->at(i) == list->at(k))
            {
                list->removeAt(k);
                k--;
            }
        }
    }
}
//采购申请
void Bom::on_pushButton_cgsq_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        //QMessageBox::warning(this,"提示","请先导入Bom单！  ",QMessageBox::Ok);
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("请先导入Bom单！");
        dontUpdate->show();
        return;
    }
    CGSQ * cgsq = new CGSQ("新增",ui->lineEdit->text());
    connect(cgsq,SIGNAL(emitFlushShowStreamSig(QString)),this,SLOT(getCGSQSigSlot(QString)));
    cgsq->show();
}

void Bom::getCGSQSigSlot(QString type)
{

    emit emitToCGSQToFlushStreamListSig(type);
}
