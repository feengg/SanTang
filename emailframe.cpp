#include "emailframe.h"
#include "ui_emailframe.h"


EmailFrame::EmailFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmailFrame)
{
    ui->setupUi(this);
    uiInit();
    QTimer * hideSkinActionTimer = new QTimer;
    hideSkinActionTimer->setInterval(30);
    connect(hideSkinActionTimer,SIGNAL(timeout()),this,SLOT(hideSkinActionSlot()));
    hideSkinActionTimer->start();
    getParaFromLocalFileAndSet();

}

EmailFrame::~EmailFrame()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void EmailFrame::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void EmailFrame::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void EmailFrame::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void EmailFrame::uiInit()
{
    setAutoFillBackground(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    QString FileName=":./images/background/bg5.jpg";
    QPixmap pix;
    pix.load(FileName);
    QPalette pal;//调色板
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    ui->horizontalSlider_opacity->setStyle(QStyleFactory::create("fusion"));
    ui->tabWidget->setStyle(QStyleFactory::create("fusion"));
    //ui->tabWidget->setEnabled(false);//设置不可点击

    //设置初始透明度
    if(!QFile::exists(qApp->applicationDirPath()+"/emailSetting.dat"))
    {
        on_horizontalSlider_opacity_valueChanged(95);
    }

    //保存初始ui宽高
    preMidHeigth = this->height();
    preMidWidth = this->width();
    //定时器初始化btn和slider的初始隐藏位置
    moveBtnAndSliderTimer = new QTimer;
    moveBtnAndSliderTimer->setInterval(100);
    connect(moveBtnAndSliderTimer,SIGNAL(timeout()),this,SLOT(initMoveBtnAndSliderTimerSlot()));
    moveBtnAndSliderTimer->start();
    //初始化更换皮肤菜单
    setSkinAction();
    //初始化为晨曦背景
    if(!QFile::exists(qApp->applicationDirPath()+"/emailSetting.dat"))
    {
        setSkin2Slot();
    }
    //初始化btnGroup
    havetTheBtnGroup();
    //给蓝色label增加阴影效果
    setLabelShadow();
    ui->pushButton_recvBox->click();

    //打开数据库
    Widget::openMySql();
    //初始化nameVec
    getAllUserNameToVec();
    //init look tab
    initLookUi();
}
//
void EmailFrame::initMoveBtnAndSliderTimerSlot()
{
    if(ui->pushButton_skin->y() != -32)
    {
        ui->horizontalSlider_opacity->move(ui->pushButton_tr->x()-170,-32);
        ui->pushButton_skin->move(ui->horizontalSlider_opacity->x()-40,-32);
    }
    else
    {
        moveBtnAndSliderTimer->stop();
        delete moveBtnAndSliderTimer;
    }
}
void EmailFrame::on_pushButton_tr_clicked()
{


    QPropertyAnimation *a1 = new QPropertyAnimation(ui->horizontalSlider_opacity,"geometry");
    QPropertyAnimation *a2 = new QPropertyAnimation(ui->pushButton_skin,"geometry");

    a1->setDuration(600);
    a2->setDuration(700);
    ui->horizontalSlider_opacity->show();
    ui->pushButton_skin->show();
    if(ui->horizontalSlider_opacity->y() == -32)
     {
         dealingSkinActionFlag = true;
         a1->setStartValue(QRect(ui->pushButton_tr->x()-170,-32,160,32));
         a1->setEndValue(QRect(ui->pushButton_tr->x()-170,20,160,32));
         a1->setEasingCurve(QEasingCurve::InBounce);

         a2->setStartValue(QRect(ui->pushButton_tr->x()-210,-32,32,32));
         a2->setEndValue(QRect(ui->pushButton_tr->x()-210,20,32,32));
         a2->setEasingCurve(QEasingCurve::InBounce);

     }
     else
     {
        qDebug() << "e";
         dealingSkinActionFlag = false;
         a1->setStartValue(QRect(ui->pushButton_tr->x()-170,20,160,32));
         a1->setEndValue(QRect(ui->pushButton_tr->x()-170,-32,160,32));
         a1->setEasingCurve(QEasingCurve::InBounce);

         a2->setStartValue(QRect(ui->pushButton_tr->x()-210,20,32,32));
         a2->setEndValue(QRect(ui->pushButton_tr->x()-210,-32,32,32));
         a2->setEasingCurve(QEasingCurve::InBounce);

     }

    a1->start();
    a2->start();

}

void EmailFrame::on_horizontalSlider_opacity_valueChanged(int value)
{
    setWindowOpacity(value/100.0);
    opacityStr = QString::number(value);
    saveSettingToLocalFile();
}

void EmailFrame::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void EmailFrame::on_pushButton_close_clicked()
{
    emit sendToWidgetToCheckIfHaveEmailToRead();
    this->close();
}

void EmailFrame::on_pushButton_max_clicked()
{
    setMaxScreen(this,":./images/background/bg2.jpg",preMidWidth,preMidHeigth);
    ui->horizontalSlider_opacity->move(ui->pushButton_tr->x()-170,-32);
    ui->pushButton_skin->move(ui->horizontalSlider_opacity->x()-40,-32);
}

void EmailFrame::setMaxScreen(QWidget * ui,const QString picPath, int midWidth, int midHeight)
{
    QDesktopWidget * desktop = QApplication::desktop();
    if(ui->width() != desktop->screenGeometry().width())
    {
        ui->resize(desktop->screenGeometry().width(),desktop->screenGeometry().height());
        ui->move(0,0);
        //设置背景图片
        ui->autoFillBackground();
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(picPath).scaled(ui->size(),Qt::IgnoreAspectRatio)));
        ui->setPalette(palette);
    }
    else
    {
        ui->resize(midWidth,midHeight);
        ui->move((desktop->screenGeometry().width() - ui->width())/2,(desktop->screenGeometry().height() - ui->height())/2);
        //设置背景图片
        ui->autoFillBackground();
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(picPath).scaled(ui->size(),Qt::IgnoreAspectRatio)));
        ui->setPalette(palette);
    }
}
//
void EmailFrame::setSkinAction()
{
   QAction * skin1 = new QAction(QIcon(":./images/EmailImage/pf_first.png"),"星空",this);
   QAction * skin2 = new QAction(QIcon(":./images/EmailImage/pf_first.png"),"晨曦",this);
   QAction * skin3 = new QAction(QIcon(":./images/EmailImage/pf_first.png"),"蓝天",this);
   QAction * skin4 = new QAction(QIcon(":./images/EmailImage/pf_first.png"),"黄格",this);
   QAction * skin5 = new QAction(QIcon(":./images/EmailImage/pf_first.png"),"朦胧",this);
   QAction * skin6 = new QAction(QIcon(":./images/EmailImage/pf_first.png"),"白云",this);
   QAction * skin7 = new QAction(QIcon(":./images/EmailImage/pf_first.png"),"自定义",this);
   connect(skin1,SIGNAL(triggered(bool)),this,SLOT(setSkin1Slot()));
   connect(skin2,SIGNAL(triggered(bool)),this,SLOT(setSkin2Slot()));
   connect(skin3,SIGNAL(triggered(bool)),this,SLOT(setSkin3Slot()));
   connect(skin4,SIGNAL(triggered(bool)),this,SLOT(setSkin4Slot()));
   connect(skin5,SIGNAL(triggered(bool)),this,SLOT(setSkin5Slot()));
   connect(skin6,SIGNAL(triggered(bool)),this,SLOT(setSkin6Slot()));
   connect(skin7,SIGNAL(triggered(bool)),this,SLOT(setSkin7Slot()));

   QMenu * ChangeBackGroundMenu = new QMenu(this);//设置皮肤菜单
   ChangeBackGroundMenu->addAction(skin1);
   ChangeBackGroundMenu->addAction(skin2);
   ChangeBackGroundMenu->addAction(skin3);
   ChangeBackGroundMenu->addAction(skin4);
   ChangeBackGroundMenu->addAction(skin5);
   ChangeBackGroundMenu->addAction(skin6);
   ChangeBackGroundMenu->addAction(skin7);
   ChangeBackGroundMenu->setStyleSheet(MenuStyle());
   ui->pushButton_skin->setMenu(ChangeBackGroundMenu);
}
void EmailFrame::setSkin1Slot()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/background/bg1.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    mainBackGroundStr = ":./images/background/bg1.jpg";
    saveSettingToLocalFile();
}
void EmailFrame::setSkin2Slot()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/background/bg2.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    mainBackGroundStr = ":./images/background/bg2.jpg";
    saveSettingToLocalFile();
}
void EmailFrame::setSkin3Slot()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/background/bg3.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    mainBackGroundStr = ":./images/background/bg3.jpg";
    saveSettingToLocalFile();
}
void EmailFrame::setSkin4Slot()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/background/bg4.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    mainBackGroundStr = ":./images/background/bg4.jpg";
    saveSettingToLocalFile();
}
void EmailFrame::setSkin5Slot()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/background/bg5.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    mainBackGroundStr = ":./images/background/bg5.jpg";
    saveSettingToLocalFile();
}
void EmailFrame::setSkin6Slot()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":./images/background/bg6.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    mainBackGroundStr = ":./images/background/bg6.jpg";
    saveSettingToLocalFile();
}

void EmailFrame::setSkin7Slot()
{
    QString FileName=QFileDialog::getOpenFileName(this,QString("文件"),"D:/",QString("图片文件(*jpg *png)"));
    if(!FileName.isEmpty())
    {
        QPixmap pix;//图片
        QPalette pal;//调色板
        qDebug() << "picPath = " << FileName;
        pix.load(FileName);
        pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        setPalette(pal);
        mainBackGroundStr = FileName;
        saveSettingToLocalFile();
    }
}

QString EmailFrame::MenuStyle()
 {
     return     " QMenu {"
            " background: white; "
                "border-radius:2px;"
             "border:1px solid rgb(200,200,200);"

       "  }"
       "  QMenu::item {"

            " background-color: transparent;"
            " padding:5px 30px;"
      "       margin:0px 0px;"
            " border-bottom:0px solid #DBDBDB;"
         "}"
        " QMenu::item:selected { "
             "background-color: aqua;"
         "}";

 }

void EmailFrame::havetTheBtnGroup()
{
    QButtonGroup * btnGroup = new QButtonGroup();
    btnGroup->addButton(ui->pushButton_recvBox);
    btnGroup->addButton(ui->pushButton_sentBox);
    btnGroup->addButton(ui->pushButton_write);
    btnGroup->addButton(ui->pushButton_look);
}

void EmailFrame::setLabelShadow()
{
    setWidgetShadow(ui->label_main);
    setWidgetShadow(ui->groupBox);
}

void EmailFrame::on_pushButton_recvBox_clicked()
{
    initRecvBoxTab();
    ui->tabWidget->setCurrentIndex(0);
}

void EmailFrame::on_pushButton_sentBox_clicked()
{
    initSentBoxTab();
    ui->tabWidget->setCurrentIndex(1);
}

void EmailFrame::on_pushButton_write_clicked()
{
    if(hasInitWriteFlag == false)
    {
        initWriteTab();
        hasInitWriteFlag = true;
    }
    ui->tabWidget->setCurrentIndex(2);

}

void EmailFrame::on_pushButton_look_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
//    if (!QFile::exists("D:/OA-Email-Data/EmailFiles/"+QString("20190109113130364.html")))
//    {
//        qDebug()  << "不存在";
//    }else{
//        qDebug()  << "存在";
//    }
}
//
void EmailFrame::initWriteTab()
{
    //收件人
    lineEdit_recver = new MyLineEdit(ui->label_recver,ui->label_under,ui->tab_3);
    lineEdit_recver->move(ui->label_recver->x()+55,ui->label_recver->y());
    lineEdit_recver->setStyleSheet("background-color: rgb(255, 255, 255,0);color: rgb(42, 117, 255);border:0px;");
    lineEdit_recver->setMinimumHeight(35);
    lineEdit_recver->setFont(QFont(QString(),10));
    lineEdit_recver->show();
    ui->gridLayout_recver->addWidget(ui->label_recver,0,1);
    ui->gridLayout_recver->addWidget(lineEdit_recver,0,2);
    ui->gridLayout_recver->addWidget(ui->pushButton_addRecver,0,3);
    //抄送
    lineEdit_copy = new MyLineEdit(ui->label_copy,ui->label_copyUnder,ui->tab_3);
    lineEdit_copy->move(ui->label_copy->x()+55,ui->label_copy->y());
    lineEdit_copy->setStyleSheet("background-color: rgb(255, 255, 255,0);color: rgb(42, 117, 255);border:0px;");
    lineEdit_copy->setMinimumHeight(35);
    lineEdit_copy->setFont(QFont(QString(),10));
    lineEdit_copy->show();
    ui->gridLayout_copy->addWidget(ui->label_copy,0,1);
    ui->gridLayout_copy->addWidget(lineEdit_copy,0,2);
    ui->gridLayout_copy->addWidget(ui->pushButton_addCopy,0,3);
    //主题
    lineEdit_topic = new MyLineEdit(ui->label_topic,ui->label_topicUnder,ui->tab_3);
    lineEdit_topic->move(ui->label_topic->x()+55,ui->label_topic->y());
    lineEdit_topic->setStyleSheet("background-color: rgb(255, 255, 255,0);color: rgb(170, 0, 0);border:0px;");
    lineEdit_topic->setMinimumHeight(35);
    lineEdit_topic->setFont(QFont(QString(),11));
    lineEdit_topic->show();
    ui->gridLayout_topic->addWidget(ui->label_topic,0,1);
    ui->gridLayout_topic->addWidget(lineEdit_topic,0,2);
    //
    ui->pushButton_delAppendix->hide();
    ui->pushButton_appendixPath->hide();
    ui->comboBox_fontColor->setStyle(QStyleFactory::create("fusion"));
    ui->comboBox_fontSize->setStyle(QStyleFactory::create("fusion"));
    ui->comboBox_orderList->setStyle(QStyleFactory::create("fusion"));
    ui->comboBox_fontBackColor->setStyle(QStyleFactory::create("fusion"));
    ui->textEdit->setStyle(QStyleFactory::create("fusion"));
    //
    QButtonGroup * btnGroup = new QButtonGroup();
    btnGroup->addButton(ui->pushButton_textCenter);
    btnGroup->addButton(ui->pushButton_textLeft);
    btnGroup->addButton(ui->pushButton_textRight);
    //make textEdit backgroundPicture show widget
    makeTextEditBackPicWidget();
    //字体颜色combox初始化
    initTextColorComboBox();
    //初始字体大小为14
    QTextCharFormat fmt;
    fmt.setFontPointSize(qreal(14));
    mergeFormatOnWordOrSelection(fmt);
    //绑定复制信号槽
    connect(QApplication::clipboard(),SIGNAL(dataChanged()), this, SLOT(clipboardDataChangedSlot()));
    //添加粘贴快捷键
    on_comboBox_fontColor_currentIndexChanged(0);
    //绑定udp
    sendTipUdp = new QUdpSocket(this);

}

void EmailFrame::on_lineEdit_recver_cursorPositionChanged(int arg1, int arg2)
{
    if(arg1 >= 0 || arg2 >= 0)
    {
        ui->label_recver->setStyleSheet("color: rgb(42, 117, 255);");
        ui->label_main->setStyleSheet("color: rgb(0, 0, 0);");
    }
}

void EmailFrame::on_lineEdit_recver_returnPressed()
{
    ui->label_recver->setStyleSheet("color: rgb(42, 117, 255);");
    ui->label_main->setStyleSheet("color: rgb(0, 0, 0);");
}

void EmailFrame::on_pushButton_appendix_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,QString("请选择上传文件"),"D:/",QString("所有文件(*)"));
    if(!fileName.isEmpty())
    {
        appendixFileName = fileName;

        ui->pushButton_appendixPath->setToolTip(fileName);
        ui->pushButton_appendixPath->setText(fileName.mid(fileName.lastIndexOf("/")+1,500));
        ui->pushButton_delAppendix->show();
        ui->pushButton_appendixPath->show();

        UpOrLoadFileDialog * up = new UpOrLoadFileDialog("Up",-2,ui->pushButton_appendixPath->toolTip());
        connect(up,SIGNAL(sendLoaderResultFlagToEmailSig(bool)),this,SLOT(getLoaderResultFlagSlot(bool)));
        up->show();

    }
}

void EmailFrame::on_pushButton_delAppendix_clicked()
{
    ui->pushButton_appendixPath->setText(QString());
    ui->pushButton_appendixPath->setToolTip(QString());
    ui->pushButton_delAppendix->hide();
    ui->pushButton_appendixPath->hide();
    appendixFileName.clear();
}

void EmailFrame::on_pushButton_addRecver_clicked(bool isCopy)
{
    if(userNameBtnVec.size())
    {
        foreach (auto a, userNameBtnVec) {
           a->close();
        }
    }
    QWidget * showNameWidget = new QWidget;
    showNameWidget->setWindowFlags(Qt::FramelessWindowHint);
    showNameWidget->move(ui->tab_3->width()-400,200);
    //设置阴影
    //setWidgetShadow(showNameWidget);
    //新增closeBtn
    closeButton * closeBtn = new closeButton(showNameWidget);
    closeBtn->resize(17,16);
    connect(closeBtn,SIGNAL(clicked(bool)),showNameWidget,SLOT(close()));
    showNameWidget->setWindowTitle("选择发送人员");

    showNameWidget->resize(500,250);
    //showNameWidget->setStyleSheet("border-image: url(:/images/EmailImage/showNameBack.png);");
    //添加布局器
    QGridLayout * btnGridLayout = new QGridLayout(showNameWidget);
    if(userNameVec.size())
    {
        for(int i = 0;i != userNameVec.size();++i)
        {
            QPushButton * btn = new QPushButton(userNameVec[i]);
            btn->setMinimumSize(65,25);
            btn->setCheckable(true);
            btn->setStyleSheet("QPushButton{color:blue;background-color:rgb(238 , 238 , 238,0);border: 0px solid rgb(183 , 183 , 183);}"
                               "QPushButton:hover{color:green;background-color:rgb(228 , 240 , 250);border: 0px solid rgb(15 , 150 , 255);}"
                                "QPushButton:checked{color:red;background-color:rgb(94 , 167 , 255);border: 0px;}");


            btnGridLayout->addWidget(btn,i/6,i%6);
            userNameBtnVec.push_back(btn);
        }
    }
    //添加确定按钮
    QPushButton * btn = new QPushButton("确定");
    btn->setMinimumSize(65,25);
    if(isCopy)
    {
        connect(btn,SIGNAL(clicked(bool)),this,SLOT(dealCopyNamesToLineEdit()));
    }else
    {
        connect(btn,SIGNAL(clicked(bool)),this,SLOT(dealSendNamesToLineEdit()));
    }
    connect(btn,SIGNAL(clicked(bool)),showNameWidget,SLOT(close()));
    btn->setStyleSheet("QPushButton{color:white;background-color:rgb(14 , 150 , 254);border: 1px solid rgb(11 , 137 , 234);}"
                       "QPushButton:hover{color:white;background-color:rgb(44 , 137 , 255);border: 1px solid rgb(11 , 137 , 234);}"
                       "QPushButton:pressed{color:white;background-color:rgb(14 , 135 , 228);border: 1px solid rgb(12 , 138 , 235);padding-left:3px;padding-top:3px;}");
    btnGridLayout->addWidget(btn,(userNameVec.size()+1)/6,(userNameVec.size()+1)%6);
    //
    closeBtn->move(showNameWidget->width()-17,0);
    closeBtn->show();
    showNameWidget->move(this->x()+this->width()-570,this->y()+90);
    //
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/EmailImage/showNameBack.png").scaled(showNameWidget->size(),Qt::IgnoreAspectRatio)));
    showNameWidget->setPalette(palette);
    //
    showNameWidget->setWindowFlags(Qt::WindowStaysOnTopHint | showNameWidget->windowFlags());
    showNameWidget->show();
}

void EmailFrame::setWidgetShadow(QWidget *widget)
{
    QGraphicsDropShadowEffect * shadow1 = new QGraphicsDropShadowEffect;
    shadow1->setOffset(0,3);
    shadow1->setColor(Qt::black);
    shadow1->setBlurRadius(15);
    widget->setGraphicsEffect(shadow1);
}
//
void EmailFrame::getAllUserNameToVec()
{
    QSqlQuery query;
    if(query.exec("select staffid,name from staffmsg"))
    {
        if(query.size())
        {
            for(int i = 0; i != query.size();++i)
            {
                query.next();
                userNameVec.push_back(query.value(0).toString()+query.value(1).toString());
            }
        }
    }
}
//
void EmailFrame::dealSendNamesToLineEdit()
{
    sendStaffIdVec.clear();
    lineEdit_recver->clear();
    if(userNameBtnVec.size())
    {
        QString nowNames = lineEdit_recver->text();
        for(int i = 0;i != userNameBtnVec.size();++i)
        {
            if(userNameBtnVec[i]->isChecked())
            {
                nowNames += userNameBtnVec[i]->text().toLower()+";";
                sendStaffIdVec.push_back(userNameBtnVec[i]->text().toLower());//保存已选人工号
                userNameBtnVec[i]->click();
            }
        }
        lineEdit_recver->setText(nowNames);
    }
}

void EmailFrame::dealCopyNamesToLineEdit()
{
    copyStaffIdVec.clear();
    lineEdit_copy->clear();
    if(userNameBtnVec.size())
    {
        QString nowNames;
        for(int i = 0;i != userNameBtnVec.size();++i)
        {
            if(userNameBtnVec[i]->isChecked())
            {
                nowNames += userNameBtnVec[i]->text().toLower()+";";
                copyStaffIdVec.push_back(userNameBtnVec[i]->text().toLower());//保存已选人工号
                userNameBtnVec[i]->click();
            }
        }
        lineEdit_copy->setText(nowNames);
    }
}

void EmailFrame::on_pushButton_backGround_clicked()
{
    //
    showNameWidget->show();
}
//
void EmailFrame::dealTextEditBackPicBtnSlot()
{
    if(textBackPicBtnVec.size())
    {
        for(int i = 0;i != textBackPicBtnVec.size();++i)
        {
            if(textBackPicBtnVec[i]->isChecked())
            {
                textEditPicNum = i;
                ui->textEdit->setStyleSheet(tr("QTextEdit{border:0px;	border-image: url(:/images/EmailImage/textBackGround/%1.png);}").arg(i));
                textEditBackGroundStr = QString::number(i);
                saveSettingToLocalFile();
                break;
            }
        }
    }
}
//
void EmailFrame::makeTextEditBackPicWidget()
{
    //把textEdit背景图片按钮生成到vector里
    QButtonGroup * textBackPicBtnBox = new QButtonGroup;
    for(int i = 0;i != 81;++i)
    {
        QPushButton * btn = new QPushButton;
        btn->setCheckable(true);
        connect(btn,SIGNAL(clicked(bool)),this,SLOT(dealTextEditBackPicBtnSlot()));
//        btn->setStyleSheet(tr("QPushButton{border:0px;background-image: url(:/images/EmailImage/textBackGround/%1.png);}").arg(i)+
//                           tr("QPushButton:checked{border:0px;background-image: url(:/images/EmailImage/textBackGround/%1.png);image: url(:/images/EmailImage/textBackGround/ok.png);}").arg(i));
        btn->setText(tr("背景%1").arg(i+1));
        btn->setStyleSheet(tr("QPushButton{border:0px;color:blue;}QPushButton:hover{border:2px;background-color:gray;}")+
                           tr("QPushButton:checked{border:0px;image: url(:/images/EmailImage/textBackGround/ok.png);}"));
        textBackPicBtnBox->addButton(btn);
        btn->setMinimumSize(70,52);
        textBackPicBtnVec.push_back(btn);
    }
    //new
    showNameWidget = new QWidget;
    showNameWidget->setWindowFlags(Qt::FramelessWindowHint);

    //设置阴影
    //setWidgetShadow(showNameWidget);
    //新增closeBtn
    closeButton * closeBtn = new closeButton(showNameWidget);
    //closeBtn->resize(16,15);
    closeBtn->setMaximumSize(15,14);
    connect(closeBtn,SIGNAL(clicked(bool)),showNameWidget,SLOT(hide()));
    showNameWidget->setWindowTitle("设置编辑框背景图片");
    showNameWidget->setWindowFlags(Qt::WindowStaysOnTopHint | showNameWidget->windowFlags());
    showNameWidget->resize(800,450);
    //添加布局器
    QGridLayout * btnGridLayout = new QGridLayout(showNameWidget);

    if(textBackPicBtnVec.size())
    {
        for(int i = 0;i != textBackPicBtnVec.size();++i)
        {
            btnGridLayout->addWidget(textBackPicBtnVec[i],i/10,i%10);
        }
    }
    //
    closeBtn->move(showNameWidget->width()-16,0);
    closeBtn->show();
    showNameWidget->move(this->x()+this->width()-1200,this->y()+250);
    //
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/EmailImage/showNameBack.png").scaled(showNameWidget->size(),Qt::IgnoreAspectRatio)));
    showNameWidget->setPalette(palette);
}


void EmailFrame::initTextColorComboBox()
{
    QPixmap pix(16, 16);
    pix.fill(Qt::black);
    ui->comboBox_fontColor->addItem(pix,"黑色");
    ui->comboBox_fontBackColor->addItem(pix,"黑色");
    indexToColorMap.insert(0,2);
    pix.fill(Qt::red);
    ui->comboBox_fontColor->addItem(pix,"红色");
    ui->comboBox_fontBackColor->addItem(pix,"红色");
    indexToColorMap.insert(1,7);
    pix.fill(Qt::darkRed);
    ui->comboBox_fontColor->addItem(pix,"深红");
    ui->comboBox_fontBackColor->addItem(pix,"深红");
    indexToColorMap.insert(2,13);
    pix.fill(Qt::green);
    ui->comboBox_fontColor->addItem(pix,"绿色");
    ui->comboBox_fontBackColor->addItem(pix,"绿色");
    indexToColorMap.insert(3,8);
    pix.fill(Qt::darkGreen);
    ui->comboBox_fontColor->addItem(pix,"深绿色");
    ui->comboBox_fontBackColor->addItem(pix,"深绿色");
    indexToColorMap.insert(4,14);
    pix.fill(Qt::blue);
    ui->comboBox_fontColor->addItem(pix,"蓝色");
    ui->comboBox_fontBackColor->addItem(pix,"蓝色");
    indexToColorMap.insert(5,9);
    pix.fill(Qt::darkBlue);
    ui->comboBox_fontColor->addItem(pix,"深蓝色");
    ui->comboBox_fontBackColor->addItem(pix,"深蓝色");
    indexToColorMap.insert(6,15);
    pix.fill(Qt::cyan);
    ui->comboBox_fontColor->addItem(pix,"青绿色");
    ui->comboBox_fontBackColor->addItem(pix,"青绿色");
    indexToColorMap.insert(7,10);
    pix.fill(Qt::darkCyan);
    ui->comboBox_fontColor->addItem(pix,"深青色");
    ui->comboBox_fontBackColor->addItem(pix,"深青色");
    indexToColorMap.insert(8,16);
    pix.fill(Qt::magenta);
    ui->comboBox_fontColor->addItem(pix,"红紫色");
    ui->comboBox_fontBackColor->addItem(pix,"红紫色");
    indexToColorMap.insert(9,11);
    pix.fill(Qt::darkMagenta);
    ui->comboBox_fontColor->addItem(pix,"深洋红");
    ui->comboBox_fontBackColor->addItem(pix,"深洋红");
    indexToColorMap.insert(10,17);
    pix.fill(Qt::yellow);
    ui->comboBox_fontColor->addItem(pix,"黄色");
    ui->comboBox_fontBackColor->addItem(pix,"黄色");
    indexToColorMap.insert(11,12);
    pix.fill(Qt::darkYellow);
    ui->comboBox_fontColor->addItem(pix,"深黄色");
    ui->comboBox_fontBackColor->addItem(pix,"深黄色");
    indexToColorMap.insert(12,18);
    pix.fill(Qt::gray);
    ui->comboBox_fontColor->addItem(pix,"灰色");
    ui->comboBox_fontBackColor->addItem(pix,"灰色");
    indexToColorMap.insert(13,5);
    pix.fill(Qt::darkGray);
    ui->comboBox_fontColor->addItem(pix,"深灰色");
    ui->comboBox_fontBackColor->addItem(pix,"深灰色");
    indexToColorMap.insert(14,4);
    pix.fill(Qt::lightGray);
    ui->comboBox_fontColor->addItem(pix,"浅灰色");
    ui->comboBox_fontBackColor->addItem(pix,"浅灰色");
    indexToColorMap.insert(15,6);
    ui->comboBox_fontColor->addItem("自定义");
    pix.fill(Qt::white);
    ui->comboBox_fontBackColor->addItem(pix,"白色");
    ui->comboBox_fontBackColor->addItem("自定义");
    ui->comboBox_fontBackColor->setCurrentText("白色");
    indexToPxMap.insert(0,14);
    indexToPxMap.insert(1,10);
    indexToPxMap.insert(2,12);
    indexToPxMap.insert(3,16);
    indexToPxMap.insert(4,18);
    indexToPxMap.insert(5,24);
    indexToPxMap.insert(6,36);
    indexToPxMap.insert(7,48);
}

void EmailFrame::on_pushButton_bold_clicked()
{

        QTextCharFormat fmt;
        fmt.setFontWeight(ui->pushButton_bold->isChecked() ? QFont::Bold : QFont::Normal);
        mergeFormatOnWordOrSelection(fmt);

}
void EmailFrame::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void EmailFrame::on_pushButton_italic_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->pushButton_italic->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}

void EmailFrame::on_pushButton_underLine_clicked()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->pushButton_underLine->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}

void EmailFrame::on_pushButton_textLeft_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
}

void EmailFrame::on_pushButton_textCenter_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignHCenter);
}

void EmailFrame::on_pushButton_textRight_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
}

void EmailFrame::on_pushButton_dayTime_clicked()
{
    ui->textEdit->textCursor().insertText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
}



void EmailFrame::on_fontComboBox_currentTextChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    mergeFormatOnWordOrSelection(fmt);
}

void EmailFrame::on_comboBox_fontSize_currentIndexChanged(int index)
{
    qreal pointSize = indexToPxMap[index];
    QTextCharFormat fmt;
    fmt.setFontPointSize(pointSize);
    mergeFormatOnWordOrSelection(fmt);
}

void EmailFrame::on_comboBox_fontColor_currentIndexChanged(int index)
{
    if(ui->comboBox_fontColor->currentText() == "自定义")
    {
        QColor col = QColorDialog::getColor();
        if (!col.isValid())
            return;
        QTextCharFormat fmt;
        fmt.setForeground(col);
        mergeFormatOnWordOrSelection(fmt);
    }
    else
    {
        QTextCharFormat fmt;
        fmt.setForeground(QColor((Qt::GlobalColor)indexToColorMap[index]));
        mergeFormatOnWordOrSelection(fmt);
    }
}

void EmailFrame::on_comboBox_fontBackColor_currentIndexChanged(int index)
{
    QTextCharFormat fmt;
    if(ui->comboBox_fontBackColor->currentText() == "自定义")
    {
        QColor col = QColorDialog::getColor();
        if (!col.isValid())
            return;
        fmt.setBackground(col);
        mergeFormatOnWordOrSelection(fmt);
    }
    else if(ui->comboBox_fontBackColor->currentText() == "白色")
    {
        fmt.setBackground(QColor(Qt::white));
        mergeFormatOnWordOrSelection(fmt);
    }
    else
    {
        fmt.setBackground(QColor((Qt::GlobalColor)indexToColorMap[index]));
        mergeFormatOnWordOrSelection(fmt);
    }
}

void EmailFrame::on_comboBox_orderList_currentIndexChanged(int index)
{
    QTextCursor cursor = ui->textEdit->textCursor();

    if (index != 0)
    {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch (index) {
            default:
            case 1:
                style = QTextListFormat::ListDisc;
                break;
            case 2:
                style = QTextListFormat::ListCircle;
                break;
            case 3:
                style = QTextListFormat::ListSquare;
                break;
            case 4:
                style = QTextListFormat::ListDecimal;
                break;
            case 5:
                style = QTextListFormat::ListLowerAlpha;
                style = QTextListFormat::ListLowerRoman;
                break;
            case 6:
                style = QTextListFormat::ListUpperAlpha;
                style = QTextListFormat::ListLowerRoman;
                break;
            case 7:
                style = QTextListFormat::ListLowerRoman;
                style = QTextListFormat::ListLowerAlpha;
                break;
            case 8:
                style = QTextListFormat::ListUpperRoman;
                style = QTextListFormat::ListUpperAlpha;
                break;
        }

        cursor.beginEditBlock();
        QTextBlockFormat blockFmt = cursor.blockFormat();
        QTextListFormat listFmt;
        if (cursor.currentList())
        {
            listFmt = cursor.currentList()->format();
        }
        else
        {
            listFmt.setIndent(blockFmt.indent() + 1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }

        listFmt.setStyle(style);

        cursor.createList(listFmt);

        cursor.endEditBlock();
    }
    else
    {
        // ####
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}
//
void EmailFrame::clipboardDataChangedSlot()
{
    const QMimeData * mimeData = QApplication::clipboard()->mimeData();
    insertFromMimeData(mimeData);
}

void EmailFrame::insertFromMimeData(const QMimeData *source)
{
    if(source->hasImage())
    {
        static int i = 1;
        QUrl url(QString("dropped_image_%1").arg(i++));
        dropImage(url,qvariant_cast<QImage>(source->imageData()));
    }
    else if(source->hasUrls())
    {
        foreach (QUrl url, source->urls())
        {
            QFileInfo info(url.toLocalFile());
            if(QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1()))
            {
                dropImage(url,QImage(info.filePath()));
            }
            else
            {
                //dropTextFile(url);
            }
        }
    }
//    else
//    {
//         //ui->textEdit->insertFromMimeData(source);
//    }
}
void EmailFrame::dropImage(const QUrl &url, const QImage &image)
{
    if(!image.isNull())
    {

        QFileInfo info(url.toLocalFile());
        QString emailPicPath = makeEmailDataFolder();;
        emailPicPath += "/EmailFiles/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz.")+info.suffix().toLower();
        if(!QFile::copy(url.toString().mid(8,300),emailPicPath))
        {
            qDebug() << "copy error:" << url.toString();
            return;
        }
        textPicPathVec.push_back(emailPicPath.mid(emailPicPath.lastIndexOf("/")+1,300));
        QUrl url1(QString("file:///")+emailPicPath);
        ui->textEdit->document()->addResource(QTextDocument::ImageResource,url1,image);
        ui->textEdit->textCursor().insertImage(url1.toString());
    }
}

void EmailFrame::dropTextFile(const QUrl &url)
{
    QFile file(url.toLocalFile());
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->textEdit->textCursor().insertText(file.readAll());
        file.close();
    }
}

void EmailFrame::on_pushButton_emailSend_clicked()
{
//    QString headerHtml = ui->textEdit->toHtml();
//    qDebug() << "headerHtml=" << headerHtml;
//    return;
//    qDebug() << "1=" <<ui->textEdit->toHtml().isEmpty();
//    qDebug() << "2=" <<(lineEdit_recver->text().indexOf("zy") == -1);
//    qDebug() << "3=" <<lineEdit_topic->text().trimmed().isEmpty();
    if(ui->textEdit->toHtml().isEmpty() || lineEdit_recver->text().toLower().indexOf("zy") == -1 || lineEdit_topic->text().trimmed().isEmpty())
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("收件人或主题或内容不能为空！");
        dontUpdate->show();
        return;
    }
    //判断收件人和抄送人是否有重复的
    for(int i = 0; i != (sendStaffIdVec.size() < copyStaffIdVec.size() ? sendStaffIdVec.size() : copyStaffIdVec.size());++i)
    {
        if(sendStaffIdVec[i] == copyStaffIdVec[i])
        {
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("收件人和抄送人有重复！");
            dontUpdate->show();
            return;
        }
    }
    QString emailPath = makeEmailDataFolder();
    emailPath += "/EmailFiles/"+QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz")+QString(".html");
    QTextDocumentWriter writer(emailPath);
    bool success = writer.write(ui->textEdit->document());
    if(success)
    {
        //
        QString text = ui->textEdit->toHtml();
        QVector<QString>tempPathVec;
        if(textPicPathVec.size())
        {
            for(int i = 0;i != textPicPathVec.size();++i)
            {

                if(text.indexOf(textPicPathVec[i]) == -1) //没有找到，即邮件内容没有包含改图片
                {
                    //删除
                    QDir dir("D:/OA-Email-Data/EmailFiles");
                    dir.remove(textPicPathVec[i]);
                }
                else
                {

                    //QFile::copy("D:/OA-Email-Data/EmailFiles/"+textPicPathVec[i],"D:/OA-Email-Data/tempData/"+textPicPathVec[i]);
                    tempPathVec.push_back(textPicPathVec[i]);
                }
            }
        }

        //QFile::copy(emailPath,"D:/OA-Email-Data/tempData/"+emailPath.mid(emailPath.lastIndexOf("/")+1,300));
        tempPathVec.push_back(emailPath.mid(emailPath.lastIndexOf("/")+1,300));
        if(tempPathVec.size())
        {
            //打包
//            QProcess pro;
//            QString cmdExe = qApp->applicationDirPath()+"/Rar.exe";
//            QStringList cmdList;
//            QString uploadFileName = "D:/OA-Email-Data/tempData/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz")+".rar";
//            cmdList << "a" << "-k" << "-r" << "-s" << "-m1" << "-ep1"<< uploadFileName;
//            for(int i = 0 ; i != tempPathVec.size();++i)
//            {
//                cmdList << tr("D:/OA-Email-Data/tempData/%1").arg(tempPathVec[i]);
//            }
//            pro.execute(cmdExe,cmdList);

//            UpOrLoadFileDialog * up = new UpOrLoadFileDialog("Up",-2,uploadFileName);
//            up->show();

            for(int i = 0 ; i != tempPathVec.size();++i)
            {

                qDebug() << tempPathVec[i];
                upLoadSuccessdFlag = false;
                UpOrLoadFileDialog * up = new UpOrLoadFileDialog("Up",-3,"");
                up->startUpLoadFile("D:/OA-Email-Data/EmailFiles/"+tempPathVec[i]);
            }
            //保存信息到数据库
            Widget::openMySql();
            QString dealTime = QDateTime::currentDateTime().toString("yyyy年MM月dd日 hh:mm:ss");
            QString sender = LoginWindow::userName;
            QString topic = lineEdit_topic->text();
            QString appendix = ui->pushButton_appendixPath->text();
            QString eMailHtml = emailPath.mid(emailPath.lastIndexOf("/")+1,300);
            QString backNumStr = QString::number(textEditPicNum);
            QString pictures;
            tempPathVec.pop_back();
            //已#为分隔符拼接pictureNameStr
            if(tempPathVec.size())
            {
                for(int i= 0;i != tempPathVec.size();++i)
                {
                    if(i == tempPathVec.size()-1)
                    {
                        pictures += tempPathVec[i];
                    }
                    else
                    {
                        pictures += tempPathVec[i]+"#"; //
                    }
                }
            }
            QString state = "未读";
            QString allReceiver = lineEdit_recver->text()+"%"+lineEdit_copy->text();
            QSqlQuery query;
            for(int i = 0;i != sendStaffIdVec.size();++i)
            {
                if(!query.exec(tr("insert into emailfiles values('%1','%2','%3','%4 ','%5','%6','%7','%8','%9 ','','%10')")
                              .arg(dealTime).arg(sender).arg(sendStaffIdVec[i]).arg(topic).arg(appendix).arg(eMailHtml)
                              .arg(backNumStr).arg(pictures).arg(state).arg(allReceiver)))
                {
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("发送失败！");
                    dontUpdate->show();
                    return;
                }
            }
            //抄送
            for(int i = 0;i != copyStaffIdVec.size();++i)
            {
                if(!query.exec(tr("insert into emailfiles values('%1','%2','%3','%4 ','%5','%6','%7','%8','%9 ','','%10')")
                              .arg(dealTime).arg(sender).arg(copyStaffIdVec[i]).arg(topic).arg(appendix).arg(eMailHtml)
                              .arg(backNumStr).arg(pictures).arg(state).arg(allReceiver)))
                {
                    showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("发送失败！");
                    dontUpdate->show();
                    return;
                }
            }
            QSqlDatabase::database().commit();
            showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("发送成功！");
            dontUpdate->show();
            lineEdit_recver->clear();
            lineEdit_topic->clear();
            ui->pushButton_delAppendix->hide();
            ui->textEdit->clear();
            //发送收件人通知
            for(int i = 0;i != sendStaffIdVec.size();++i)
            {
                if(query.exec(tr("select ip from staffmsg where staffid = '%1'").arg(sendStaffIdVec[i].mid(0,6))))
                {
                    query.next();
                    QByteArray sendMsg = "您有新的邮件！";
                    sendTipUdp->writeDatagram(sendMsg,QHostAddress(query.value(0).toString()),4512);
                }
            }
            for(int i = 0;i != copyStaffIdVec.size();++i)
            {
                if(query.exec(tr("select ip from staffmsg where staffid = '%1'").arg(copyStaffIdVec[i].mid(0,6))))
                {
                    query.next();
                    QByteArray sendMsg = "您有新的邮件！";
                    sendTipUdp->writeDatagram(sendMsg,QHostAddress(query.value(0).toString()),4512);
                }
            }
            lineEdit_recver->clear();
            lineEdit_copy->clear();
            ui->textEdit->clear();
            ui->pushButton_sentBox->click();
        }

    }else
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("发送失败！");
        dontUpdate->show();
    }
}

void EmailFrame::on_pushButton_insertPic_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择图片","D:/",tr("Bitmap (*.bmp)"
                                                                         "JPEG (*.jpg *.jpeg)"
                                                                        "PNG (*.png)"));
    if(!filePath.isEmpty())
    {
        QUrl url("file:///"+filePath);
        QFileInfo info(url.toLocalFile());
        if(QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1()))
        {
            dropImage(url,QImage(info.filePath()));
        }
    }
}

//
QString EmailFrame::makeEmailDataFolder()
{
    QDir dir("D:/");
    dir.mkdir("OA-Email-Data");
    dir.cd("OA-Email-Data");
    dir.mkdir("EmailFiles");
    return QString("D:/OA-Email-Data");
}
//
void EmailFrame::initSentBoxTab()
{
    ui->pushButton_deleteSent->hide();
    //先清除，然后在显示
    if(allMyGroupSent.size())
    {
        for(int i = 0;i != allMyGroupSent.size();++i)
        {
            allMyGroupSent[i]->close();
        }
    }
    allMyGroupSent.clear();
    saveCheckBoxVec.clear();
    ui->scrollArea_sentBox->setStyle(QStyleFactory::create("fusion"));
    Widget::openMySql();
    QSqlQuery query;
    QSqlQuery query1;
    if(query.exec(tr("select distinct dealtime from emailfiles where sender = '%1' and deleteUsers not like '%%2%' order by dealtime desc").arg(LoginWindow::userName).arg(LoginWindow::staffID.toLower())))
    {
        if(query.size())
        {

             ui->pushButton_deleteSent->show();
             for(int i = 0;i != query.size();++i)
             {
                 query.next();
                 QString spaceStr = "     ";
                 QString recvNames,topic,dealTime,emailHtml;
                 //再次访问拼接同一邮件
                 if(query1.exec(tr("select allReceiver,topic,dealtime,emailHtml from emailfiles where dealtime = '%1'").arg(query.value(0).toString())))
                 {
                     if(query1.size())
                     {

                         for(int j = 0;j != query1.size();++j)
                         {
                             query1.next();
                             recvNames = query1.value(0).toString().mid(0,query1.value(0).toString().indexOf("%"));
                             topic = query1.value(1).toString();
                             dealTime = query1.value(2).toString();
                             emailHtml = query1.value(3).toString();
                             break;
                         }
                     }
                 }
                 //添加
                 //产生每个box剩没行邮件记录
                 QGroupBox * groupBox = new QGroupBox;
                 groupBox->setStyleSheet("border:0px;background-color: rgb(255, 255, 255,100);font: 10pt ""宋体"";");
                 //
                 QHBoxLayout * horizontalLayout = new QHBoxLayout(groupBox);
                 horizontalLayout->setMargin(10);
                 horizontalLayout->setSpacing(0);
                 //
                 QCheckBox * checkBox = new QCheckBox;
                 checkBox->setStyle(QStyleFactory::create("fusion"));
                 checkBox->setMaximumWidth(15);
                 checkBox->setStyleSheet("background-color: rgb(221, 245, 255);");
                 checkBox->setToolTip(emailHtml);
                 //
                 MyPushBtn * recvBtn = new MyPushBtn(groupBox,spaceStr+recvNames,
                                                       emailHtml,300,0,26);
                 MyPushBtn * topicBtn = new MyPushBtn(groupBox,spaceStr+topic
                                                      ,emailHtml,1650,0,26);
                 MyPushBtn * dealTimeBtn = new MyPushBtn(groupBox,dealTime,emailHtml,165,165,26);

                 //绑定信号槽来双击查看邮件
                 connect(recvBtn,SIGNAL(sendDoubleClickedToolTipSig(QString)),this,SLOT(showEmailLookSlot(QString)));
                 connect(topicBtn,SIGNAL(sendDoubleClickedToolTipSig(QString)),this,SLOT(showEmailLookSlot(QString)));
                 connect(dealTimeBtn,SIGNAL(sendDoubleClickedToolTipSig(QString)),this,SLOT(showEmailLookSlot(QString)));
                 horizontalLayout->addWidget(checkBox);
                 horizontalLayout->addWidget(recvBtn);
                 horizontalLayout->addWidget(topicBtn);
                 horizontalLayout->addWidget(dealTimeBtn);
                 //添加到容器保存，以方便删除个刷新
                 allMyGroupSent.push_back(groupBox);
                 saveCheckBoxVec.push_back(checkBox);//存储checkbox方便后续删除邮件
                 //添加到tab_2大的垂直布局器里
                 ui->verticalLayout_sent->insertWidget(i+1,groupBox);
             }
        }
    }
}
//
void EmailFrame::initRecvBoxTab()
{
    ui->pushButton_deleteRecv->hide();
    //先清除，然后在显示
    if(allMyGroupRecord.size())
    {
        for(int i = 0;i != allMyGroupRecord.size();++i)
        {
            allMyGroupRecord[i]->close();
        }
    }
    allMyGroupRecord.clear();
    saveCheckBoxVec.clear();
    ui->scrollArea->setStyle(QStyleFactory::create("fusion"));
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec(tr("select sender,emailHtml,topic,dealTime,state from emailfiles where  receiver like '%1%' and deleteUsers not like '%%2%' order by dealtime desc").arg(LoginWindow::staffID)
                  .arg(LoginWindow::staffID)))
    {
        if(query.size())
        {
            QString spaceStr = "     ";
             ui->pushButton_deleteRecv->show();
             for(int i = 0;i != query.size();++i)
             {
                 query.next();
                 //产生每个box剩没行邮件记录
                 QGroupBox * groupBox = new QGroupBox;
                 groupBox->setStyleSheet("border:0px;background-color: rgb(255, 255, 255,100);font: 10pt ""宋体"";");
                 //
                 QHBoxLayout * horizontalLayout = new QHBoxLayout(groupBox);
                 horizontalLayout->setMargin(10);
                 horizontalLayout->setSpacing(0);
                 //
                 QCheckBox * checkBox = new QCheckBox;
                 checkBox->setStyle(QStyleFactory::create("fusion"));
                 checkBox->setMaximumWidth(15);
                 checkBox->setStyleSheet("background-color: rgb(221, 245, 255);");
                 checkBox->setToolTip(query.value(1).toString());
                 //
                 MyPushBtn * senderBtn = new MyPushBtn(groupBox,spaceStr+query.value(0).toString(),
                                                       query.value(1).toString(),300,0,26);

                 MyPushBtn * topicBtn = new MyPushBtn(groupBox,query.value(2).toString()
                                                      ,query.value(1).toString(),1650,0,26);
                 MyPushBtn * dealTimeBtn = new MyPushBtn(groupBox,query.value(3).toString(),query.value(1).toString(),165,165,26);

                 MyPushBtn * stateBtn = new MyPushBtn(groupBox,query.value(4).toString(),query.value(1).toString()
                                                      ,30,30,26,query.value(4).toString().trimmed()=="未读"?"red":"blue");
                 //绑定信号槽来双击查看邮件
                 connect(senderBtn,SIGNAL(sendDoubleClickedToolTipSig(QString)),this,SLOT(showEmailLookSlot(QString)));
                 connect(topicBtn,SIGNAL(sendDoubleClickedToolTipSig(QString)),this,SLOT(showEmailLookSlot(QString)));
                 connect(dealTimeBtn,SIGNAL(sendDoubleClickedToolTipSig(QString)),this,SLOT(showEmailLookSlot(QString)));
                 connect(stateBtn,SIGNAL(sendDoubleClickedToolTipSig(QString)),this,SLOT(showEmailLookSlot(QString)));
                 horizontalLayout->addWidget(checkBox);
                 horizontalLayout->addWidget(senderBtn);
                 horizontalLayout->addWidget(topicBtn);
                 horizontalLayout->addWidget(dealTimeBtn);
                 horizontalLayout->addWidget(stateBtn);
                 //添加到容器保存，以方便删除个刷新
                 allMyGroupRecord.push_back(groupBox);
                 saveCheckBoxVec.push_back(checkBox);//存储checkbox方便后续删除邮件
                 //添加到tab_2大的垂直布局器里
                 ui->verticalLayout_recv->insertWidget(i+1,groupBox);
             }
        }
    }
}

void EmailFrame::on_pushButton_deleteRecv_clicked()
{
    bool checkedFalg = false;
    if(saveCheckBoxVec.size())
    {
        Widget::openMySql();
        QSqlQuery query;
        for(int i = 0;i != saveCheckBoxVec.size();++i)
        {
            if(saveCheckBoxVec[i]->isChecked())
            {
                checkedFalg = true;
                QString allDeleteNames;
                if(query.exec(tr("select distinct deleteUsers from emailfiles where emailHtml = '%1'").arg(saveCheckBoxVec[i]->toolTip())))
                {
                    if(query.size())
                    {
                        allDeleteNames = query.value(0).toString();
                    }
                }else
                {
                    return;
                }
                allDeleteNames += LoginWindow::staffID.toLower() +';';
                if(query.exec(tr("update emailfiles set deleteUsers = '%1' where emailHtml = '%2'").arg(allDeleteNames).arg(saveCheckBoxVec[i]->toolTip())))
                {
                    QSqlDatabase::database().commit();
                }else{
                    return;
                }
            }
        }
    }
    if(checkedFalg == false)
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("未选择删除项！");
        dontUpdate->show();
    }else
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("删除成功！");
        dontUpdate->show();
    }
    initRecvBoxTab();
}

void EmailFrame::on_pushButton_deleteSent_clicked()
{
    on_pushButton_deleteRecv_clicked();
    initSentBoxTab();
}

void EmailFrame::initLookUi()
{

    setWidgetShadow(ui->groupBox_look);
    ui->pushButton_appendixPath_look->hide();
    ui->pushButton_appendix_look->hide();
    ui->pushButton_downAppendix->hide();
    ui->pushButton_reply->hide();
    ui->textEdit_look->setStyle(QStyleFactory::create("fusion"));
    headerHtmlStr = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: "
                    "pre-wrap; }\n</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; "
                    "font-style:normal;\">\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; "
                    "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                    "<br /></p>\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; "
                    "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                    "<br /></p>\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; "
                    "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                    "text-indent:0px;\"><br /></p>\n<p style=\"-qt-paragraph-type:empty; "
                    "margin-top:0px; margin-bottom:0px; margin-left:0px; "
                    "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                    "<br /></p>\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; "
                    "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                    "text-indent:0px;\"><br /></p>\n<p style=\"-qt-paragraph-type:empty; "
                    "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
                    "-qt-block-indent:0; text-indent:0px;\"><br /></p>\n<p style=\"-qt-paragraph-type:empty; "
                    "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                    "text-indent:0px;\"><br /></p>\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; "
                    "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                    "<br /></p>\n<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; "
                    "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                    "text-indent:0px;\"><br /></p>\n<p style=\" margin-top:0px; "
                    "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                    "text-indent:0px;\"><span style=\" font-family:'黑体'; font-size:12pt;\">"
                    "---------------------原始邮件----------------------</span></p>\n"
                    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
                    "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'黑体'; "
                    "font-size:10pt; font-weight:600;\">发 件 人</span><span style=\" font-family:'黑体'; "
                    "font-size:12pt; font-weight:600;\">：</span><span style=\" font-family:'黑体'; "
                    "font-size:10pt;\">%1</span></p>\n<p style=\" margin-top:0px; margin-bottom:0px; "
                    "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                    "<span style=\" font-family:'黑体'; font-size:10pt; font-weight:600;\">"
                    "发送时间：</span><span style=\" font-family:'黑体'; "
                    "font-size:10pt;\">%2</span></p>\n"
                    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
                    "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" "
                    "font-family:'黑体'; font-size:10pt; font-weight:600;\">"
                    "收 件 人：</span><span style=\" font-family:'黑体'; font-size:10pt;\">%3"
                    "</span></p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
                    "-qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'黑体'; font-size:10pt; "
                    "font-weight:600;\">主    题：</span><span style=\" font-family:'黑体'; "
                    "font-size:10pt;\">%4</span></p>\n<p style=\"-qt-paragraph-type:empty; "
                    "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
                    "-qt-block-indent:0; text-indent:0px; font-family:'黑体'; font-size:10pt;\"><br /></p>\n"
                    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; "
                    "margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'黑体'; font-size:10pt;\">"
                    "<br /></p></body></html>";
}

void EmailFrame::showEmailLookSlot(QString emailHtml)
{
    Widget::openMySql();
    QSqlQuery query;
    if(query.exec(tr("select sender,receiver,topic,dealtime,appendix,editBackGround,pictures,allReceiver from emailfiles where "
                     "emailHtml = '%1'").arg(emailHtml)))
    {
        if(query.size())
        {
            QString allPic,appendix;
            query.next();
            ui->lineEdit_send_look->setText(query.value(0).toString());
            ui->lineEdit_recv_look->setText(query.value(7).toString().mid(0,query.value(7).toString().indexOf("%")));
            ui->lineEdit_copy_look->setText(query.value(7).toString().mid(query.value(7).toString().indexOf("%")+1,200));
            ui->lineEdit_topic_look->setText(query.value(2).toString());
            ui->lineEdit_dealTime_look->setText(query.value(3).toString());
            appendix = query.value(4).toString().trimmed();
            if(!appendix.isEmpty())//如果有附件，则显示下载按钮
            {
                ui->pushButton_appendixPath_look->setText(appendix);
                ui->pushButton_appendix_look->show();
                ui->pushButton_appendixPath_look->show();
                ui->pushButton_downAppendix->show();
            }else{
                ui->pushButton_appendix_look->hide();
                ui->pushButton_appendixPath_look->hide();
                ui->pushButton_downAppendix->hide();
            }
            //设置textEdit背景图片
            ui->textEdit_look->setStyleSheet(tr("QTextEdit{border:0px;	border-image: url(:/images/EmailImage/textBackGround/%1.png);}").arg(query.value(5).toInt()));
            //下载图片
            allPic = query.value(6).toString().trimmed();
            if(!allPic.isEmpty())
            {
                while(allPic.indexOf("#") != -1)
                {
                    QString pic1 = allPic.mid(0,allPic.indexOf("#"));
                    if (!QFile::exists("D:/OA-Email-Data/EmailFiles/"+pic1))
                    {
                        UpOrLoadFileDialog * down = new UpOrLoadFileDialog(-4);
                        down->startDownFile(pic1);
                    }

                    allPic = allPic.mid(allPic.indexOf("#")+1,500);
                }
                //当没有#或者最后一个图片名时
                UpOrLoadFileDialog * down = new UpOrLoadFileDialog(-4);
                down->startDownFile(allPic);
            }
            //下载emailHtml
            if (!QFile::exists("D:/OA-Email-Data/EmailFiles/"+emailHtml))
            {
                UpOrLoadFileDialog * down = new UpOrLoadFileDialog(-4);
                down->startDownFile(emailHtml);
                waitLoadEmailFileName = emailHtml;
                //定时器开启以保证下载完成后打开
                waitDownTimer = new QTimer;
                waitDownTimer->setInterval(40);
                connect(waitDownTimer,SIGNAL(timeout()),this,SLOT(showEmailToTextEditSlot()));
                waitDownTimer->start();
            }
            else
            {
                //加载emailHtml到textEdit
                QFile file("D:/OA-Email-Data/EmailFiles/"+emailHtml);
                if (file.open(QFile::ReadOnly))
                {
                    QByteArray data = file.readAll();
                    QTextCodec *codec = Qt::codecForHtml(data);
                    QString str = codec->toUnicode(data);
                    if (Qt::mightBeRichText(str)) {
                        ui->textEdit_look->setHtml(str);
                        if(ui->lineEdit_send_look->text().trimmed() != LoginWindow::userName)
                        {
                            ui->pushButton_reply->show();
                        }else{
                            ui->pushButton_reply->hide();
                        }
                    }
                    else
                    {
                        str = QString::fromLocal8Bit(data);
                        ui->textEdit_look->setPlainText(str);
                        if(ui->lineEdit_send_look->text().trimmed() != LoginWindow::userName)
                        {
                            ui->pushButton_reply->show();
                        }else{
                            ui->pushButton_reply->hide();
                        }
                    }
                    //更新数据库已读状态
                    Widget::openMySql();
                    QSqlQuery query;
                    if(query.exec(tr("update emailfiles set state='已读' where receiver like '%1%' and emailHtml='%2'")
                                  .arg(LoginWindow::staffID).arg(emailHtml)))
                    {
                        QSqlDatabase::database().commit();
                    }
                }
                //
                ui->pushButton_look->click();
            }

        }
    }
}

void EmailFrame::on_pushButton_downAppendix_clicked()
{
    UpOrLoadFileDialog * loadAppendix = new UpOrLoadFileDialog("Down",5,ui->pushButton_appendixPath_look->text());
    loadAppendix->show();
}

void EmailFrame::showEmailToTextEditSlot()
{
    if(QFile::exists("D:/OA-Email-Data/EmailFiles/"+waitLoadEmailFileName))
    {
        waitDownTimer->stop();
        //加载emailHtml到textEdit
        QFile file("D:/OA-Email-Data/EmailFiles/"+waitLoadEmailFileName);
        if (file.open(QFile::ReadOnly))
        {
            QByteArray data = file.readAll();
            QTextCodec *codec = Qt::codecForHtml(data);
            QString str = codec->toUnicode(data);
            if (Qt::mightBeRichText(str)) {
                ui->textEdit_look->setHtml(str);
            }
            else
            {
                str = QString::fromLocal8Bit(data);
                ui->textEdit_look->setPlainText(str);
            }
            //更新数据库已读状态
            Widget::openMySql();
            QSqlQuery query;
            if(query.exec(tr("update emailfiles set state='已读' where receiver like '%1%' and emailHtml='%2'")
                          .arg(LoginWindow::staffID).arg(waitLoadEmailFileName)))
            {
                QSqlDatabase::database().commit();
            }
        }
        //
        ui->pushButton_look->click();
        if(ui->lineEdit_send_look->text().trimmed() != LoginWindow::userName)
        {
            ui->pushButton_reply->show();
        }else{
            ui->pushButton_reply->hide();
        }

    }
}

void EmailFrame::on_pushButton_reply_clicked()
{
    ui->pushButton_write->click();
    QString recvName = ui->lineEdit_send_look->text().trimmed();
    for(int i = 0;i != userNameVec.size();++i)
    {
        if(userNameVec[i].indexOf(recvName) != -1)
        {
            sendStaffIdVec.clear();
            sendStaffIdVec.push_back(userNameVec[i]);
            lineEdit_recver->clear();
            lineEdit_recver->setText(userNameVec[i]+";");
            break;
        }
    }
    lineEdit_topic->clear();
    lineEdit_topic->setText("Re:"+ui->lineEdit_topic_look->text());
    ui->textEdit->clear();
    ui->textEdit->setHtml(headerHtmlStr.arg(recvName).arg(ui->lineEdit_dealTime_look->text())
                          .arg(ui->lineEdit_recv_look->text()).arg(ui->lineEdit_topic_look->text())+ui->textEdit_look->toHtml());
    //ui->textEdit->insertHtml(ui->textEdit_look->toHtml());

}

void EmailFrame::hideSkinActionSlot()
{
    if(dealingSkinActionFlag == false)
    {
        ui->horizontalSlider_opacity->move(ui->pushButton_tr->x()-170,-32);
        ui->pushButton_skin->move(ui->horizontalSlider_opacity->x()-40,-32);
    }
}

void EmailFrame::saveSettingToLocalFile()
{
    QFile file(qApp->applicationDirPath()+"/emailSetting.dat");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        file.reset();
    }
    file.write((mainBackGroundStr+"\n").toLocal8Bit());
    file.write((opacityStr+"\n").toLocal8Bit());
    file.write((textEditBackGroundStr+"\n").toLocal8Bit());
    file.close();
}

void EmailFrame::getParaFromLocalFileAndSet()
{
    if(QFile::exists(qApp->applicationDirPath()+"/emailSetting.dat"))
    {
        QFile file(qApp->applicationDirPath()+"/emailSetting.dat");
        file.open(QIODevice::ReadOnly);
        QByteArray mainSkin = file.readLine();
        QByteArray opacity = file.readLine();
        QByteArray textEditSkin =file.readLine();
        mainSkin = mainSkin.replace("\n","");
        opacity = opacity.replace("\n","");
        textEditSkin = textEditSkin.replace("\n","");
        qDebug() <<"1 ="<< mainSkin;
        qDebug() << "2="<< opacity;
        qDebug() << "3="<< textEditSkin;
        //
        QPalette palette;
        palette.setBrush(QPalette::Background,QBrush(QPixmap(mainSkin).scaled(this->size(),Qt::IgnoreAspectRatio)));
        this->setPalette(palette);
        //
        ui->horizontalSlider_opacity->setValue(opacity.toInt());
        setWindowOpacity(opacity.toInt()/100.0);
        ui->textEdit->setStyleSheet(tr("QTextEdit{border:0px;	border-image: url(:/images/EmailImage/textBackGround/%1.png);}").arg(textEditSkin.toInt()));
        file.close();
    }
}

void EmailFrame::on_pushButton_addCopy_clicked()
{
    on_pushButton_addRecver_clicked(true);
}
