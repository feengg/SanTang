//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CTitleBar.cpp
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CTitleBar��
// History			:
//******************************************************************************

#include "CDlgTitleBar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QDebug>

const int BUTTON_HEIGHT = 30;       // ��ť�߶�
const int BUTTON_WIDTH = 30;        // ��ť���
const int TITLE_HEIGHT = 30;        // �������߶�

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
    // ��ʼ��
    mvInitControl();
    mvInitConn();
    mvLoadStyleSheet("MyTitle");
}

CDlgTitleBar::~CDlgTitleBar()
{

}

//******************************************************************************
// Function			: CTitleBar::mvSetBackGrdColr
// Description		: ���ñ���������ɫ
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
// Description		: ���ñ�����ͼ��
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
// Description		: ���ñ�������
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
    // ���������С
    QFont ofont = mopLabTitleCont->font();
    ofont.setPointSize(titleFontSize);
    mopLabTitleCont->setFont(ofont);

    // ���ñ�������
    mopLabTitleCont->setText(titleContent);
    msTitleContent = titleContent;
}

//******************************************************************************
// Function			: CTitleBar::mvSetTitleWidth
// Description		: ���ñ���������
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
// Description		: ���ñ������ϰ�ť����
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
// Description		: ���ñ������еı����Ƿ���Զ�����
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
// Description		: ���ô��ڿ��
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
// Description		: ���洰�����ǰ���ڵ�λ���Լ���С
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
// Description		: ��ȡ�������ǰ���ڵ�λ���Լ���С
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
// Description		: ���Ʊ���������ɫ
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
        //���ñ���ɫ;
        QPainter painter(this);
        QPainterPath pathBack;
        pathBack.setFillRule(Qt::WindingFill);
        pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.fillPath(pathBack, QBrush(QColor(miR, miG, miB)));
    }

    // ��������󻯻��߻�ԭ�󣬴��ڳ��ȱ��ˣ��������ĳ���Ӧ��һ��ı�;
    if (this->width() != (this->parentWidget()->width() - miWindowBorderWidth))
    {
        this->setFixedWidth(this->parentWidget()->width() - miWindowBorderWidth);
    }
    QWidget::paintEvent(event);

}

//******************************************************************************
// Function			: CTitleBar::mvDoubleClickEvent
// Description		: ˫����Ӧ�¼�����Ҫ��ʵ��˫��������������󻯺���С������
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
    // ֻ�д�����󻯡���ԭ��ťʱ˫������Ч;
    if (meBtnType == eMin_Max_Button)
    {
        // ͨ����󻯰�ť��״̬�жϵ�ǰ�����Ǵ�����󻯻���ԭʼ��С״̬;
        // ����ͨ���������ñ�������ʾ��ǰ����״̬;
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
// Description		: ����ͨ��mousePressEvent��mouseMoveEvent��
//                  : mouseReleaseEvent�����¼�ʵ��������϶��������ƶ����ڵ�Ч��
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
        // �ڴ������ʱ��ֹ�϶�����;
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
// Description		: �ƶ�����
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
// Description		: �ͷ�
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
// Description		: ��ʼ���ؼ�
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
// Description		: �źŲ۵İ�
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
// Description		: ���ر�����ʽ�ļ�
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
// Description		: ��С����ť������Ӧ�Ĳ�
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
// Description		: �ָ�������Ӧ�Ĳ�
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
// Description		: ��󻯰�ť��Ӧ�Ĳ�
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
// Description		: �رհ�ť��Ӧ�Ĳ�
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
// Description		: �ñ������еı�����ʾΪ������Ч��
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
