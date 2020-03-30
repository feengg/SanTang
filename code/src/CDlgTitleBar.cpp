//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CTitleBar.cpp
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CTitleBar类
// History			:
//******************************************************************************

#include "CDlgTitleBar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QDebug>

const int BUTTON_HEIGHT = 30;       // 按钮高度
const int BUTTON_WIDTH = 30;        // 按钮宽度
const int TITLE_HEIGHT = 30;        // 标题栏高度

CDlgTitleBar::CDlgTitleBar(QWidget *parent /* = NULL */)
    : QWidget(parent)
    , miR(153)
    , miG(153)
    , miB(153)
    , mbIsPressed(false)
    , meBtnType(eMin_Max_Button)
    , miWindowBorderWidth(0)
    , mbIsTransparent(false)
{
    // 初始化
    mvInitControl();
    mvInitConn();
    mvLoadStyleSheet("MyTitle");
}

CDlgTitleBar::~CDlgTitleBar()
{

}

//******************************************************************************
// Function			: CTitleBar::mvSetBackGrdColr
// Description		: 设置标题栏背景色
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSetBackGrdColr(int iR, int iG, int iB, bool isTransparent /*= false*/)
{
    miR = iR;
    miG = iG;
    miB = iB;
 
    mbIsTransparent = isTransparent;

    update();

}

//******************************************************************************
// Function			: CTitleBar::mvSetTitleIcon
// Description		: 设置标题栏图标
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSetTitleIcon(QString filePath)
{
    QPixmap otitleIcon(filePath);
    mopLabIcon->setPixmap(otitleIcon.scaled(25, 25));
}

//******************************************************************************
// Function			: CTitleBar::mvSetTitleContent
// Description		: 设置标题内容
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSetTitleContent(QString titleContent, int titleFontSize /*= 9*/)
{
    // 标题字体大小
    QFont ofont = mopLabTitleCont->font();
    ofont.setPointSize(titleFontSize);
    mopLabTitleCont->setFont(ofont);

    // 设置标题内容
    mopLabTitleCont->setText(titleContent);
    msTitleContent = titleContent;
}

//******************************************************************************
// Function			: CTitleBar::mvSetTitleWidth
// Description		: 设置标题栏长度
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSetTitleWidth(int width)
{
    this->setFixedWidth(width);
}

//******************************************************************************
// Function			: CTitleBar::mvSetButtonType
// Description		: 设置标题栏上按钮类型
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSetButtonType(eBtnType buttonType)
{
    meBtnType = buttonType;

    switch (buttonType)
    {
    case eMin_Button: {
        mopBtnRestore->setVisible(false);
        mopBtnMax->setVisible(false);
    }
    break;
    case eMin_Max_Button:
    {
        mopBtnRestore->setVisible(false);
    }
    break;
    case eOnly_Close_Button:
    {
        mopBtnMin->setVisible(false);
        mopBtnRestore->setVisible(false);
        mopBtnMax->setVisible(false);
    }
    break;
    default:
        break;
    }
}

//******************************************************************************
// Function			: CTitleBar::mvSetTitleRoll
// Description		: 设置标题栏中的标题是否会自动滚动
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSetTitleRoll()
{
    connect(&moTitleRollTimer, SIGNAL(timeout()), this, SLOT(mslotOnRollTitle()));
    moTitleRollTimer.start(200);
}

//******************************************************************************
// Function			: CTitleBar::mvSetWindowBorderWidth
// Description		: 设置窗口宽度
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSetWindowBorderWidth(int borderWidth)
{
    miWindowBorderWidth = borderWidth;
}

//******************************************************************************
// Function			: CTitleBar::mvSaveRestoreInfo
// Description		: 保存窗口最大化前窗口的位置以及大小
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvSaveRestoreInfo(const QPoint point, const QSize size)
{
    moRestorePos = point;
    moRestoreSize = size;
}

//******************************************************************************
// Function			: CTitleBar::mvGetRestoreInfo
// Description		: 获取窗口最大化前窗口的位置以及大小
// Access			: public 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvGetRestoreInfo(QPoint& point, QSize& size)
{
    point = moRestorePos;
    size = moRestoreSize;
}

//******************************************************************************
// Function			: CTitleBar::mvPaintEvent
// Description		: 绘制标题栏背景色
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvPaintEvent(QPaintEvent *event)
{
    if (!mbIsTransparent)
    {
        //设置背景色;
        QPainter painter(this);
        QPainterPath pathBack;
        pathBack.setFillRule(Qt::WindingFill);
        pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.fillPath(pathBack, QBrush(QColor(miR, miG, miB)));
    }

    // 当窗口最大化或者还原后，窗口长度变了，标题栏的长度应当一起改变;
    if (this->width() != (this->parentWidget()->width() - miWindowBorderWidth))
    {
        this->setFixedWidth(this->parentWidget()->width() - miWindowBorderWidth);
    }
    QWidget::paintEvent(event);

}

//******************************************************************************
// Function			: CTitleBar::mvDoubleClickEvent
// Description		: 双击响应事件，主要是实现双击标题栏进行最大化和最小化操作
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvDoubleClickEvent(QMouseEvent *event)
{
    // 只有存在最大化、还原按钮时双击才有效;
    if (meBtnType == eMin_Max_Button)
    {
        // 通过最大化按钮的状态判断当前窗口是处于最大化还是原始大小状态;
        // 或者通过单独设置变量来表示当前窗口状态;
        if (mopBtnMax->isVisible())
        {
            mslotOnBtnMaxClicked();
        }
        else
        {
            mslotOnBtnRestoreClicked();
        }
    }

    return QWidget::mouseDoubleClickEvent(event);

}

//******************************************************************************
// Function			: CTitleBar::mvPressEvent
// Description		: 以下通过mousePressEvent、mouseMoveEvent、
//                  : mouseReleaseEvent三个事件实现了鼠标拖动标题栏移动窗口的效果
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvPressEvent(QMouseEvent *event)
{
    if (meBtnType == eMin_Max_Button) {
        // 在窗口最大化时禁止拖动窗口;
        if (mopBtnMax->isVisible())
        {
            mbIsPressed = true;
            moStartMovePos = event->globalPos();
        }
    } else {
        mbIsPressed = true;
        moStartMovePos = event->globalPos();
    }

    return QWidget::mousePressEvent(event);

}

//******************************************************************************
// Function			: CTitleBar::mvMoveEvent
// Description		: 移动窗口
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvMoveEvent(QMouseEvent *event)
{
    if (mbIsPressed) {
        QPoint movePoint = event->globalPos() - moStartMovePos;
        QPoint widgetPos = this->parentWidget()->pos();
        moStartMovePos = event->globalPos();
        this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
    return QWidget::mousePressEvent(event);

}

//******************************************************************************
// Function			: CTitleBar::mvReleaseEvent
// Description		: 释放
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvReleaseEvent(QMouseEvent *event)
{
    mbIsPressed = false;
    return QWidget::mousePressEvent(event);
}

//******************************************************************************
// Function			: CTitleBar::mvInitControl
// Description		: 初始化控件
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvInitControl()
{
    
    mopLabIcon = new QLabel;
    mopLabTitleCont = new QLabel;

    mopBtnMin = new QPushButton;
    mopBtnRestore = new QPushButton;
    mopBtnMax = new QPushButton;
    
    mopBtnClose = new QPushButton;

    mopBtnMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    mopBtnRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    mopBtnMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    mopBtnClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    mopLabTitleCont->setObjectName("TitleContent");
    mopBtnMin->setObjectName("ButtonMin");
    
    mopBtnRestore->setObjectName("ButtonRestore");
    mopBtnMax->setObjectName("ButtonMax");
    mopBtnClose->setObjectName("ButtonClose");

    QHBoxLayout* mylayout = new QHBoxLayout(this);
    mylayout->addWidget(mopLabIcon);
    mylayout->addWidget(mopLabTitleCont);
    mylayout->addWidget(mopBtnMin);
    mylayout->addWidget(mopBtnRestore);
    mylayout->addWidget(mopBtnMax);
    mylayout->addWidget(mopBtnClose);

    mylayout->setContentsMargins(5, 0, 0, 0);
    mylayout->setSpacing(0);

    mopLabTitleCont->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setFixedHeight(TITLE_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

//******************************************************************************
// Function			: CTitleBar::mvInitConn
// Description		: 信号槽的绑定
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvInitConn()
{
    connect(mopBtnMin, SIGNAL(clicked()), this, SLOT(mslotOnBtnMinClicked()));
    connect(mopBtnRestore, SIGNAL(clicked()), this, SLOT(mslotOnBtnRestoreClicked()));
    connect(mopBtnMax, SIGNAL(clicked()), this, SLOT(mslotOnBtnMaxClicked()));
    connect(mopBtnClose, SIGNAL(clicked()), this, SLOT(mslotOnBtnCloseClicked()));
}

//******************************************************************************
// Function			: CTitleBar::mvLoadStyleSheet
// Description		: 加载本地样式文件
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mvLoadStyleSheet(const QString &sheetName)
{
    QFile file("../css/" + sheetName + ".css");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }

}



//******************************************************************************
// Function			: CTitleBar::mslotOnBtnMinClicked
// Description		: 最小化按钮操作响应的槽
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mslotOnBtnMinClicked()
{
    emit msigBtnMinClicked();
}

//******************************************************************************
// Function			: CTitleBar::mslotOnBtnRestoreClicked
// Description		: 恢复窗口响应的槽
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mslotOnBtnRestoreClicked()
{
    mopBtnRestore->setVisible(false);
    mopBtnMax->setVisible(true);
    emit msigBtnRestorClicked();
}

//******************************************************************************
// Function			: CTitleBar::mslotOnBtnMaxClicked
// Description		: 最大化按钮对应的槽
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mslotOnBtnMaxClicked()
{
    mopBtnMax->setVisible(false);
    mopBtnRestore->setVisible(true);
    emit msigBtnMaxClicked();
}

//******************************************************************************
// Function			: CTitleBar::mslotOnBtnCloseClicked
// Description		: 关闭按钮对应的槽
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mslotOnBtnCloseClicked()
{
    emit msigBtnCloseClicked();
}

//******************************************************************************
// Function			: CTitleBar::mslotOnRollTitle
// Description		: 让标题栏中的标题显示为滚动的效果
// Access			: private 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgTitleBar::mslotOnRollTitle()
{
    static int ipos = 0;
    QString title_content = msTitleContent;

    if (ipos > title_content.length()) {
        ipos = 0;
    }

    mopLabTitleCont->setText(title_content.mid(ipos));
    ipos++;

}
