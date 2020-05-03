#include "mimegame.h"
#include "ui_mimegame.h"
#include <QStyleFactory>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include "mymimebtn.h"
#include <QDebug>
#include <QGridLayout>
#include <QDateTime>
#include "showdontupdatedialog.h"
#include <QTime>
#include <QtGlobal>
#include <QTimer>
#include "widget.h"



MimeGame::MimeGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MimeGame)
{
    ui->setupUi(this);

    this->setWindowTitle("Have Fun");   

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    setWindowOpacity(0.95);
    qDebug() << "0";
    setFusionStyle();
    qDebug() << "1";
    setLabelShadow();
    qDebug() << "2";
    //
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/EmailImage/textBackGround/24.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    //
    qDebug() << "3";
    btnGridLayout = new QGridLayout(ui->groupBox);
    //
    qDebug() << "4";
    initGame();
    qDebug() << "5";
    //getBillBoardRecord();
}

MimeGame::~MimeGame()
{
    delete ui;
}
void MimeGame::setFusionStyle()
{
    this->setStyle(QStyleFactory::create("fusion"));
    ui->pushButton_reStart->setStyle(QStyleFactory::create("fusion"));
    ui->tabWidget->setStyle(QStyleFactory::create("fusion"));
    ui->scrollArea->setStyle(QStyleFactory::create("fusion"));
    ui->scrollArea_2->setStyle(QStyleFactory::create("fusion"));
    ui->scrollArea_3->setStyle(QStyleFactory::create("fusion"));
}
void MimeGame::setLabelShadow()
{
    setWidgetShadow(ui->tabWidget);
    setWidgetShadow(ui->groupBox);
    setWidgetShadow(ui->label_mineNum);
    setWidgetShadow(ui->label_time);
    setWidgetShadow(ui->pushButton_mineNum);
    setWidgetShadow(ui->pushButton_time);
    setWidgetShadow(ui->comboBox_gameLevel);
    setWidgetShadow(ui->pushButton_reStart);
    setWidgetShadow(ui->label_easyBestTime);
    setWidgetShadow(ui->label_easySuccess);
    setWidgetShadow(ui->label_easySum);
    setWidgetShadow(ui->label_easyRate);
    setWidgetShadow(ui->label_midBestTime);
    setWidgetShadow(ui->label_midSuccess);
    setWidgetShadow(ui->label_midSum);
    setWidgetShadow(ui->label_midRate);
    setWidgetShadow(ui->label_hardBestTime);
    setWidgetShadow(ui->label_hardSuccess);
    setWidgetShadow(ui->label_hardSum);
    setWidgetShadow(ui->label_hardRate);
    setWidgetShadow(ui->groupBox_easy);
    setWidgetShadow(ui->groupBox_mid);
    setWidgetShadow(ui->groupBox_hard);
    setWidgetShadow(ui->groupBox_easyBillBoard);
    setWidgetShadow(ui->groupBox_midBillBoard);
    setWidgetShadow(ui->groupBox_hardBillBoard);
    setWidgetShadow(ui->comboBox_rateType);
    setWidgetShadow(ui->label_easy);
    setWidgetShadow(ui->label_easyName);
    setWidgetShadow(ui->label_easyTimes);
    setWidgetShadow(ui->label_mid);
    setWidgetShadow(ui->label_midName);
    setWidgetShadow(ui->label_midTimes);
    setWidgetShadow(ui->label_hard);
    setWidgetShadow(ui->label_hardName);
    setWidgetShadow(ui->label_hardTimes);
    setWidgetShadow(ui->label_tip1);
    setWidgetShadow(ui->label_tip2);
    setWidgetShadow(ui->label_tip3);
    setWidgetShadow(ui->label_tip4);
    setWidgetShadow(ui->label_tip5);
}

void MimeGame::getBillBoardRecord()
{
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec("select * from minerecord"))
    {
        if(query.size())
        {
            if(easyBestTimeMap.size())
            {
                easyBestTimeMap.clear();
                easyWinRateMap.clear();
                midBestTimeMap.clear();
                midWinRateMap.clear();
                hardBestTimeMap.clear();
                hardWinRateMap.clear();
            }

            for(int i = 0 ;i != query.size();++i)
            {
                query.next();
                QMap<QString,int>tempMap;
                tempMap.insert(query.value(0).toString(),query.value(1).toInt());

                easyBestTimeMap.insert(query.value(3).toInt(),tempMap);
                easyWinRateMap.insert(query.value(1).toInt()==0?0:query.value(2).toInt()*100/query.value(1).toInt(),tempMap);

                tempMap.clear();
                tempMap.insert(query.value(0).toString(),query.value(4).toInt());
                midBestTimeMap.insert(query.value(6).toInt(),tempMap);
                midWinRateMap.insert(query.value(4).toInt()==0?0:query.value(5).toInt()*100/query.value(4).toInt(),tempMap);

                tempMap.clear();
                tempMap.insert(query.value(0).toString(),query.value(7).toInt());
                hardBestTimeMap.insert(query.value(9).toInt(),tempMap);
                hardWinRateMap.insert(query.value(7).toInt()==0?0:query.value(8).toInt()*100/query.value(7).toInt(),tempMap);
            }
        }
    }

}

void MimeGame::startGameTimer()
{
    if(gameTimer)
    {
        delete gameTimer;
    }
    gameTimer = new QTimer;
    gameTimer->setInterval(1000);
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(getGameTimerTimeOutSlot()));
    gameTimer->start();
}
void MimeGame::getGameTimerTimeOutSlot()
{
    ui->label_time->setText(QString::number(ui->label_time->text().toInt()+1));
}
void MimeGame::showTimeAndMineNumBtn(bool showFlag)
{
    if(showFlag)
    {
        ui->pushButton_time->show();
        ui->label_time->show();
        ui->pushButton_mineNum->show();
        ui->label_mineNum->show();
    }else
    {
        ui->pushButton_time->hide();
        ui->label_time->hide();
        ui->pushButton_mineNum->hide();
        ui->label_mineNum->hide();
    }
}
void MimeGame::dealMineBtnClickedSlot(int row, int col)
{
    //qDebug() << "row = " << row << "col =" << col;
    if(allMineBtnMap[row*maxColNum+col]->checkIfMine())
    {
        showDontUpdateDialog * tip = new showDontUpdateDialog("Game Over!");
        tip->show();
        allMineBtnMap[row*maxColNum+col]->setMineStyle();
        if(gameTimer)
            gameTimer->stop();
        gameOverShowAllMinesBtn();
        ui->groupBox->setEnabled(false);
    }
    else
    {
        if(isFirstClickedMineBtn == false)
        {
            isFirstClickedMineBtn = true;
            layMines(allMineNum,row * maxColNum + col);
            initAllMineBtnAroundMineNum(maxRowNum,maxColNum);
            showTimeAndMineNumBtn(true);
            ui->label_time->setText("0");
            ui->label_mineNum->setText(QString::number(allMineNum));
            startGameTimer();
            allMineBtnMap[row*maxColNum+col]->setClicked();
        }
        int aroundMineNum = allMineBtnMap[row*maxColNum+col]->getAroundMinesNum();
        if(aroundMineNum == 0)
        {
            recursionShowBlankBtn(row,col);
        }
        else
        {
            allMineBtnMap[row*maxColNum+col]->setNumStyle(aroundMineNum);
            allMineBtnMap[row*maxColNum+col]->setIsNotFirstState();
            allMineBtnMap[row*maxColNum+col]->setClicked();
        }
        checkIfGameSuccess();//排雷计数
    }

}
//double clicked
void MimeGame::dealMineBtnDoubleClickedSlot(int row,int col)
{
    int aroundMarkedNum = 0;
    int aroundMinesNum = 0;
    int aroundMarkedMinesNum = 0;
    for(int i = -1;i != 2;++i)
    {
        for(int j = -1;j != 2;++j)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            int tempRow = row + i;
            int tempCol = col + j;
            if((tempRow >=0&&tempRow<maxRowNum)&&(tempCol>=0&&tempCol<maxColNum))
            {
                if(allMineBtnMap[tempRow*maxColNum+tempCol]->getMarkState())
                {
                    if(allMineBtnMap[tempRow*maxColNum+tempCol]->checkIfMine())
                    {
                        aroundMarkedNum++;
                        aroundMinesNum++;
                        aroundMarkedMinesNum++;
                    }
                    else//标记了但不是雷
                    {
                        aroundMarkedNum++;

                    }
                }
                else
                {
                    if(allMineBtnMap[tempRow*maxColNum+tempCol]->checkIfMine())
                    {
                        aroundMinesNum++;
                    }
                }

            }
        }
    }
    //检查完后，来判断是否正确
    if((aroundMarkedNum == aroundMinesNum)&&(aroundMarkedNum != aroundMarkedMinesNum))
    {
        for(int i = -1;i != 2;++i)
        {
            for(int j = -1;j != 2;++j)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                int tempRow = row + i;
                int tempCol = col + j;
                if((tempRow >=0&&tempRow<maxRowNum)&&(tempCol>=0&&tempCol<maxColNum))
                {
                    if(allMineBtnMap[tempRow*maxColNum+tempCol]->getMarkState() && allMineBtnMap[tempRow*maxColNum+tempCol]->checkIfMine()==false)
                    {
                        allMineBtnMap[tempRow*maxColNum+tempCol]->setErrorMineStyle();
                    }
                }
            }
        }
        showDontUpdateDialog * tip = new showDontUpdateDialog("Game Over:标记错误！");
        tip->show();
        if(gameTimer)
            gameTimer->stop();
        gameOverShowAllMinesBtn();
        ui->groupBox->setEnabled(false);

    }
    if((aroundMinesNum == aroundMarkedMinesNum) && (aroundMarkedNum > aroundMinesNum))
    {
        return;
    }
    //显示周围不是雷的地方
    if((aroundMinesNum == aroundMarkedNum) && (aroundMinesNum == aroundMarkedMinesNum))
    {
        for(int i = -1;i != 2;++i)
        {
            for(int j = -1;j != 2;++j)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                int tempRow = row + i;
                int tempCol = col + j;
                if((tempRow >=0&&tempRow<maxRowNum)&&(tempCol>=0&&tempCol<maxColNum))
                {
                    if(allMineBtnMap[tempRow*maxColNum+tempCol]->getClickState() == false && allMineBtnMap[tempRow*maxColNum+tempCol]->checkIfMine() == false)
                    {
                        if(allMineBtnMap[tempRow*maxColNum+tempCol]->getAroundMinesNum() == 0)
                        {
                            recursionShowBlankBtn(tempRow,tempCol);
                        }
                        else
                        {
                            allMineBtnMap[tempRow*maxColNum+tempCol]->setNumStyle(allMineBtnMap[tempRow*maxColNum+tempCol]->getAroundMinesNum());
                            allMineBtnMap[tempRow*maxColNum+tempCol]->setIsNotFirstState();
                            allMineBtnMap[tempRow*maxColNum+tempCol]->setClicked();
                            if(allMineBtnMap[tempRow*maxColNum+tempCol]->getIsNotFirstState() == false)
                            {
                                allMineBtnMap[tempRow*maxColNum+tempCol]->setClicked();
                            }
                            checkIfGameSuccess();//排雷计数
                        }
                    }
                }
            }
        }
    }
}

void MimeGame::checkIfGameSuccess()
{
    int hasClickedRightBtnNum = 0;
    for(int i = 0; i != allMineBtnMap.size();++i)
    {
        if(allMineBtnMap[i]->getClickState())
        {
            hasClickedRightBtnNum++;
        }
    }

    if(hasClickedRightBtnNum == btnSum - allMineNum)
    {
        if(gameTimer)
            gameTimer->stop();
        //统计
        Data mineData1;
        Data * mineData = &mineData1;
        getMineDataFromSql(mineData);
        QString showMsg;
        if(allMineNum == 10)
        {
            showMsg += "-         恭喜，你赢了！      -   \n\n";
            mineData->easySum += 1;
            mineData->easySuccess += 1;
            if(mineData->easyBestTime > ui->label_time->text().toInt())
            {
                mineData->easyBestTime = ui->label_time->text().toInt();
                showMsg += "   恭喜打破个人初级水平最短记录！  \n\n";                
            }
            showMsg += tr("         时间: %1 秒            \n").arg(ui->label_time->text());
            showMsg += tr("  历史最短时间: %1 秒            \n").arg(mineData->easyBestTime);
            showMsg += tr("     已玩局数: %1               \n").arg(mineData->easySum);
            showMsg += tr("     已胜局数: %1               \n").arg(mineData->easySuccess);
            showMsg += tr("        胜率: %1%              \n").arg(mineData->easySuccess*100/mineData->easySum);
        }
        if(allMineNum == 40)
        {
            showMsg += "         恭喜，你赢了！             \n\n";
            mineData->midSum += 1;
            mineData->midSuccess += 1;
            if(mineData->midBestTime > ui->label_time->text().toInt())
            {
                mineData->midBestTime = ui->label_time->text().toInt();
                showMsg += "   恭喜打破个人中级水平最短记录！  \n\n";
            }
            showMsg += tr("         时间: %1 秒            \n").arg(ui->label_time->text());
            showMsg += tr("  历史最短时间: %1 秒             \n").arg(mineData->midBestTime);
            showMsg += tr("     已玩局数: %1               \n").arg(mineData->midSum);
            showMsg += tr("     已胜局数: %1               \n").arg(mineData->midSuccess);
            showMsg += tr("        胜率: %1%              \n").arg(mineData->midSuccess*100/mineData->midSum);
        }
        if(allMineNum == 99)
        {
            showMsg += "         恭喜，你赢了！            \n\n";
            mineData->hardSum += 1;
            mineData->hardSuccess += 1;
            if(mineData->hardBestTime > ui->label_time->text().toInt())
            {
                mineData->hardBestTime = ui->label_time->text().toInt();
                showMsg += "   恭喜打破个人高级水平最短记录！\n\n";
            }
            showMsg += tr("         时间: %1 秒           \n").arg(ui->label_time->text());
            showMsg += tr("  历史最短时间: %1 秒           \n").arg(mineData->hardBestTime);
            showMsg += tr("     已玩局数: %1              \n").arg(mineData->hardSum);
            showMsg += tr("     已胜局数: %1               \n").arg(mineData->hardSuccess);
            showMsg += tr("        胜率: %1%              \n").arg(mineData->hardSuccess*100/mineData->hardSum);
        }

        //保存到数据库
        setMineDataToSql(mineData);
//        showDontUpdateDialog * tip = new showDontUpdateDialog("恭喜!你赢了！");
//        tip->show();
        QMessageBox::about(this,"恭喜大侠胜出",showMsg);
        ui->groupBox->setEnabled(false);
        gameOverShowAllMinesBtn();
        ui->label_mineNum->setText("0");

    }
}
void MimeGame::getMineDataFromSql(Data *mineData)
{
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec(tr("select * from mineRecord where staffname = '%1'").arg(LoginWindow::userName)))
    {
        if(query.size())
        {
            query.next();
            mineData->easySum = query.value(1).toInt();
            mineData->easySuccess = query.value(2).toInt();
            mineData->easyBestTime = query.value(3).toInt();
            mineData->midSum = query.value(4).toInt();
            mineData->midSuccess = query.value(5).toInt();
            mineData->midBestTime = query.value(6).toInt();
            mineData->hardSum = query.value(7).toInt();
            mineData->hardSuccess = query.value(8).toInt();
            mineData->hardBestTime = query.value(9).toInt();
        }
    }
}
void MimeGame::setMineDataToSql(Data *mineData)
{
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec(tr("select * from minerecord where staffname= '%1'").arg(LoginWindow::userName)))
    {
        if(query.size() > 0)//有记录
        {
            if(query.exec(tr("update minerecord set easySum = %1,easySuccess = %2,easyBestTime= %3,"
                             "midSum = %4,midSuccess=%5,midBestTime=%6,hardSum=%7,hardSuccess=%8,hardBestTime=%9 where staffname = '%10'")
                          .arg(mineData->easySum).arg(mineData->easySuccess).arg(mineData->easyBestTime).arg(mineData->midSum)
                          .arg(mineData->midSuccess).arg(mineData->midBestTime).arg(mineData->hardSum).arg(mineData->hardSuccess)
                          .arg(mineData->hardBestTime).arg(LoginWindow::userName)))
            {
                QSqlDatabase::database().commit();
            }else{
                QSqlDatabase::database().rollback();
            }
        }
        else //没记录则插入
        {
            if(query.exec(tr("insert into minerecord values('%10',%1,%2,%3,%4,%5,%6,%7,%8,%9)")
                          .arg(mineData->easySum).arg(mineData->easySuccess).arg(mineData->easyBestTime).arg(mineData->midSum)
                          .arg(mineData->midSuccess).arg(mineData->midBestTime).arg(mineData->hardSum).arg(mineData->hardSuccess)
                          .arg(mineData->hardBestTime).arg(LoginWindow::userName)))
            {
                QSqlDatabase::database().commit();
            }else{
                QSqlDatabase::database().rollback();
            }
        }
    }

}

void MimeGame::setWidgetShadow(QWidget *widget)
{
    QGraphicsDropShadowEffect * shadow1 = new QGraphicsDropShadowEffect;
    shadow1->setOffset(0,3);
    shadow1->setColor(Qt::black);
    shadow1->setBlurRadius(15);
    widget->setGraphicsEffect(shadow1);
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void MimeGame::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void MimeGame::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void MimeGame::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void MimeGame::on_pushButton_close_clicked()
{
    this->close();
}

void MimeGame::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void MimeGame::on_comboBox_gameLevel_currentIndexChanged(int index)
{
    if(gameTimer)
    {
        gameTimer->stop();
    }
    ui->label_time->setText("0");
    showTimeAndMineNumBtn(false);
    qDebug() << "index = " << index;
    switch (index)
    {
    case 0:
        maxRowNum = 9;
        maxColNum = 9;
        btnSum = 81;
        allMineNum = 10;
        groupBoxWidth = 308;
        groupBoxHeight = 308;
        initGame();
        break;
    case 1:
        maxRowNum = 16;
        maxColNum = 16;
        btnSum = 256;
        allMineNum = 40;
        groupBoxWidth = 530;
        groupBoxHeight = 530;
        initGame();
        break;
    case 2:

        maxRowNum = 16;
        maxColNum = 30;
        btnSum = 480;
        allMineNum = 99;
        groupBoxWidth = 971;
        groupBoxHeight = 530;
        initGame();
        break;
    default:
        break;
    }
    ui->label_mineNum->setText(QString::number(allMineNum));
}

void MimeGame::initGame()
{
    showTimeAndMineNumBtn(true);

    isFirstClickedMineBtn = false;
    ui->groupBox->setEnabled(true);
    //删除之前的btn
    for(auto i = allMineBtnMap.begin();i != allMineBtnMap.end();++i)
    {
        i.value()->close();
    }
    allMineBtnMap.clear();
    //添加布局器
    btnGridLayout->setSpacing(0);

    ui->groupBox->setMinimumSize(groupBoxWidth,groupBoxHeight);
    ui->groupBox->setMaximumSize(groupBoxWidth,groupBoxHeight);
    newMineBtn(maxRowNum,maxColNum);
    //layMines(allMineNum);
    //initAllMineBtnAroundMineNum(maxRowNum,maxColNum);
}

void MimeGame::newMineBtn(int rowMaxNum,int colMaxNum)
{
    for(int row = 0;row != rowMaxNum;++row)
    {
        for(int col = 0; col != colMaxNum;++col)
        {
            MyMimeBtn * mineBtn = new MyMimeBtn(row,col,ui->label_mineNum);
            mineBtn->setMineBtnSize(32);
            connect(mineBtn,SIGNAL(sendPositionSig(int,int)),this,SLOT(dealMineBtnClickedSlot(int,int)));
            connect(mineBtn,SIGNAL(sendDoubleClickedSig(int,int)),this,SLOT(dealMineBtnDoubleClickedSlot(int,int)));
            allMineBtnMap.insert(row*colMaxNum+col,mineBtn);
            btnGridLayout->addWidget(mineBtn,row,col);
        }
    }
}

void MimeGame::layMines(int mineNum,int firstClickNum)
{

    int hasLayMineNum = 0;
    int addNum[150] = {-1,33,44235,6452,42,34234,345,34,8,9,45,345,2,34,6,457487,456,345,7,8,9,86,786,87,5
                     ,8,6,4,5,7,8,6,3,1,23,235,434,6,47,6,97,80,6,78,567,56,74,5,623,4,23,42,35,34,64,57,5,89,576,4
                     ,24234,234,23423,56,65,7,65,98,56,4,56,23,45,23,634,6,34,534,5,34,7,43,56234,87,564,5,2345,2623,4523,7,34
                     ,2434,2,35623,4,236,32,45,346,364,7,345,3,7,345,34,63,47,34,534,6734,5,3476,34,534,534,534534,53453
                     ,234,23,4234,234,23,42,34,234,6,34,67,4,74,56,45,784,56,3452,3423,4,23423,65234,23423,4234,
                     234,23423,4,234};

    while(hasLayMineNum < mineNum)
    {
        if(i == 150)
            i =0;
        qsrand(QDateTime::currentDateTime().toTime_t()+(addNum[i++]));
        int btnNum = qrand()%btnSum;
        if(btnNum == firstClickNum)
        {
            continue;
        }
        if(!allMineBtnMap[btnNum]->checkIfMine())
        {
            allMineBtnMap[btnNum]->setMine();
            hasLayMineNum++;
        }

    }
}

void MimeGame::initAllMineBtnAroundMineNum(int maxRow,int maxCol)
{

    for(int row = 0; row != maxRow;++row)
    {
        for(int col = 0;col != maxCol;++col)
        {
            //判断每个点周围八个点是雷的个数
            int aroundMineNum = 0;
            for(int i = -1;i != 2;++i)
            {
                for(int j = -1;j != 2;++j)
                {
                    //排出该中心点本身
                    if(i == 0 && j == 0)
                    {
                        continue;
                    }
                    if(((row+i) >= 0 && (row+i) < maxRow) && ((col+j) >= 0 && (col+j) < maxCol))
                    {
                        if(allMineBtnMap[(row+i)*maxCol+(col+j)]->checkIfMine())
                        {
                            aroundMineNum++;
                        }
                    }

                }
            }
            allMineBtnMap[row*maxCol+col]->setAroundMinesNum(aroundMineNum);
            //allMineBtnMap[row*maxCol+col]->setNumStyle(aroundMineNum);
        }
    }
}

//递归显示空白
void MimeGame::recursionShowBlankBtn(int row,int col)
{
    for(int i = -1; i != 2;++i)
    {
        for(int j = -1;j != 2;++j)
        {
            if((i == -1 && j == -1) || (i == -1 && j == 1) || (i == 1&& j == -1) || (i == 1 && j == 1))
            {
                continue;
            }
            int nextRowNum = row + i;
            int nextColNum = col +j;
            if((nextRowNum >=0&&nextRowNum<maxRowNum)&&(nextColNum>=0&&nextColNum<maxColNum)&&allMineBtnMap[nextRowNum*maxColNum+nextColNum]->getAroundMinesNum()==0&&allMineBtnMap[nextRowNum*maxColNum+nextColNum]->isBlankChecked()==false
                    &&allMineBtnMap[nextRowNum*maxColNum+nextColNum]->getMarkState()==false)
            {
                allMineBtnMap[nextRowNum*maxColNum+nextColNum]->setBlankStyle();
                allMineBtnMap[nextRowNum*maxColNum+nextColNum]->setBlankChecked();
                allMineBtnMap[nextRowNum*maxColNum+nextColNum]->setIsNotFirstState();
                allMineBtnMap[nextRowNum*maxColNum+nextColNum]->setClicked();
                checkIfGameSuccess();//排雷计数
                recursionShowBlankBtn(nextRowNum,nextColNum);
                //显示空白周围的数字
                for(int k = -1; k != 2;++k)
                {
                    for(int z = -1;z != 2;++z)
                    {
                        int tempRow = nextRowNum+k;
                        int tempCol = nextColNum+z;
                        if((tempRow >=0&&tempRow<maxRowNum)&&(tempCol>=0&&tempCol<maxColNum))
                        {
                            allMineBtnMap[tempRow*maxColNum+tempCol]->setNumStyle(allMineBtnMap[tempRow*maxColNum+tempCol]->getAroundMinesNum());
                            allMineBtnMap[tempRow*maxColNum+tempCol]->setClicked();
                            allMineBtnMap[tempRow*maxColNum+tempCol]->setIsNotFirstState();
                           checkIfGameSuccess();//排雷计数
                        }
                    }
                }
            }
        }
    }
}
//
void MimeGame::gameOverShowAllMinesBtn()
{
    for(int i = 0; i != allMineBtnMap.size();++i)
    {
        allMineBtnMap[i]->setIsNotFirstState();
        if(allMineBtnMap[i]->checkIfMine())
        {
            allMineBtnMap[i]->setMineStyle();
        }
        if(allMineBtnMap[i]->getMarkState() && allMineBtnMap[i]->checkIfMine())
        {
            allMineBtnMap[i]->setMarkedMineStyle();
        }
    }
    isFirstClickedMineBtn = false;
    //保存记录到数据库
    Data mineData1;
    Data * mineData = &mineData1;
    getMineDataFromSql(mineData);
    if(allMineNum == 10)
    {
        mineData->easySum += 1;
    }else if(allMineNum == 40)
    {
        mineData->midSum += 1;
    }else{
        mineData->hardSum += 1;
    }
    setMineDataToSql(mineData);
}

void MimeGame::on_pushButton_reStart_clicked()
{
    if(gameTimer)
        gameTimer->stop();
    ui->label_time->setText("0");
    ui->label_mineNum->setText(QString::number(allMineNum));
    on_comboBox_gameLevel_currentIndexChanged(ui->comboBox_gameLevel->currentIndex());
    isFirstClickedMineBtn = false;
}

void MimeGame::on_tabWidget_tabBarClicked(int index)
{
    if(index == 1)
    {
        Data data;
        Data * mineData = &data;
        getMineDataFromSql(mineData);
        ui->label_easySum->setText(QString::number(mineData->easySum));
        ui->label_easyBestTime->setText(QString::number(mineData->easyBestTime));
        ui->label_easySuccess->setText(QString::number(mineData->easySuccess));
        ui->label_easyRate->setText(QString::number(mineData->easySum==0?0:mineData->easySuccess*100/mineData->easySum)+"%");
        ui->label_midSum->setText(QString::number(mineData->midSum));
        ui->label_midBestTime->setText(QString::number(mineData->midBestTime));
        ui->label_midSuccess->setText(QString::number(mineData->midSuccess));
        ui->label_midRate->setText(QString::number(mineData->midSum==0?0:mineData->midSuccess*100/mineData->midSum)+"%");
        ui->label_hardSum->setText(QString::number(mineData->hardSum));
        ui->label_hardBestTime->setText(QString::number(mineData->hardBestTime));
        ui->label_hardSuccess->setText(QString::number(mineData->hardSuccess));
        ui->label_hardRate->setText(QString::number(mineData->hardSum==0?0:mineData->hardSuccess*100/mineData->hardSum)+"%");
    }
    if(index == 2)
    {
        //获取最新记录
        qDebug() << "i0";
        getBillBoardRecord();
        qDebug() << "i1";
        if(ui->comboBox_rateType->currentText()=="最佳时间")
        {
            //easy
            showBillBoard(easyBestTimeMap.begin(),easyBestTimeMap.end(),allMyGroupEasy,ui->verticalLayout_easy);
            //mid
            showBillBoard(midBestTimeMap.begin(),midBestTimeMap.end(),allMyGroupMid,ui->verticalLayout_mid);
            //hard
            showBillBoard(hardBestTimeMap.begin(),hardBestTimeMap.end(),allMyGroupHard,ui->verticalLayout_hard);
        }
        else
        {
            //easy
            showBillBoard(easyWinRateMap.begin(),easyWinRateMap.end(),allMyGroupEasy,ui->verticalLayout_easy);
            //mid
            showBillBoard(midWinRateMap.begin(),midWinRateMap.end(),allMyGroupMid,ui->verticalLayout_mid);
            //hard
            showBillBoard(hardWinRateMap.begin(),hardWinRateMap.end(),allMyGroupHard,ui->verticalLayout_hard);
        }
    }
}

void MimeGame::showBillBoard(QMultiMap<int,QMap<QString,int>>::iterator mapBegin,QMultiMap<int,QMap<QString,int>>::iterator mapEnd
                             ,QVector<QGroupBox*> &groupVec,QVBoxLayout *verticalLayout)
{
    if(groupVec.size())
    {
        for(int i = 0;i != groupVec.size();++i)
        {
            groupVec[i]->close();
        }
    }
    QMultiMap<int,QMap<QString,int>>::iterator tempBegin;
    QMultiMap<int,QMap<QString,int>>::iterator tempEnd;
    int billNum = 0;
    if(ui->comboBox_rateType->currentText()=="最佳时间")
    {
        tempBegin = mapBegin;
        tempEnd = mapEnd;
        ui->label_easy->setText("最佳时间");
        ui->label_mid->setText("最佳时间");
        ui->label_hard->setText("最佳时间");
    }
    else
    {
        tempBegin = mapEnd-1;
        tempEnd = mapBegin-1;
        ui->label_easy->setText("游戏胜率");
        ui->label_mid->setText("游戏胜率");
        ui->label_hard->setText("游戏胜率");
    }

    for(auto i = tempBegin;i != tempEnd;)
    {

        QMap<QString,int>tempMap = i.value();
        QLabel * labelBest = new QLabel;
        QLabel * labelName = new QLabel;
        QLabel * labelTimes = new QLabel;
        if(ui->comboBox_rateType->currentText() == "最佳时间")
        {
            labelBest->setText(QString::number(i.key())+"秒");
        }
        else
        {
            labelBest->setText(QString::number(i.key())+"%");
        }
        labelBest->setAlignment(Qt::AlignHCenter);
        labelBest->setStyleSheet("color:darkgreen;");

        labelName->setText(tempMap.begin().key());
        labelName->setAlignment(Qt::AlignHCenter);

        labelTimes->setText(QString::number(tempMap.begin().value())+"局");
        labelTimes->setAlignment(Qt::AlignHCenter);
        labelTimes->setStyleSheet("color:blue;");

        //产生每个box剩没行邮件记录
        QGroupBox * groupBox = new QGroupBox;
        setWidgetShadow(groupBox);
        if(billNum == 0)//第一名
        {
            groupBox->setStyleSheet("border:0px;background-color: rgb(211, 168, 9);color: rgb(255, 85, 0);font: 10pt ""宋体"";");
        }
        else if(billNum == 1)//第二名
        {
            groupBox->setStyleSheet("border:0px;background-color: rgb(245, 245, 243);;color: rgb(255, 85, 0);font: 10pt ""宋体"";");
        }
        else if(billNum == 2)//第三名
        {
            groupBox->setStyleSheet("border:0px;background-color: rgb(168, 110, 64);color: rgb(255, 85, 0);font: 10pt ""宋体"";");
        }
        else
        {
            groupBox->setStyleSheet("border:0px;background-color: rgb(216, 222, 235);color: rgb(255, 85, 0);font: 10pt ""宋体"";");
        }
        //
        QHBoxLayout * horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setMargin(10);
        horizontalLayout->setSpacing(0);
        //
        //绑定信号槽来双击查看邮件
        horizontalLayout->addWidget(labelBest);
        horizontalLayout->addWidget(labelName);
        horizontalLayout->addWidget(labelTimes);
        //添加到容器保存，以方便删除个刷新
        groupVec.push_back(groupBox);
        //添加到tab_2大的垂直布局器里
        verticalLayout->insertWidget(billNum,groupBox);
        billNum++;
        if(ui->comboBox_rateType->currentText() == "最佳时间")
        {
            ++i;
        }else{
            --i;
        }
    }
}

void MimeGame::on_comboBox_rateType_currentTextChanged(const QString &)
{
    on_tabWidget_tabBarClicked(2);
}
