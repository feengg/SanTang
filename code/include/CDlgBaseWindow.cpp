//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgCDlgBaseWindow.cpp
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CDlgCDlgBaseWindow类
// History			:
//******************************************************************************

#include "CDlgBaseWindow.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QFile>
#include <QStyleOption>

//******************************************************************************
// Function			: CDlgBaseWindow::CDlgBaseWindow
// Description		: 构造函数
// Access			: public 
// Input			: 
// Output			: 
// Return			: 
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
CDlgBaseWindow::CDlgBaseWindow(QWidget *parent)
    : QDialog(parent)
{
    // FramelessWindowHint属性设置窗口去除边框;
    // WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口;
    //Qt::WindowFlags flag = this->windowFlags();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    // 设置窗口背景透明;
    setAttribute(Qt::WA_TranslucentBackground);
    // 关闭窗口时释放资源;
    //setAttribute(Qt::WA_DeleteOnClose);
    // 初始化标题栏;
    mvInitTitleBar();

}

CDlgBaseWindow::~CDlgBaseWindow()
{

}

//******************************************************************************
// Function			: CDlgBaseWindow::mvInitTitleBar
// Description		: 初始化bar
// Access			: protected 
// Input			: 
// Output			: 
// Return			: void
// 
// History			:
// 1 Data			: 2020-03-29
// Author			: SanTang  Jiaofeng
//******************************************************************************
void CDlgBaseWindow::mvInitTitleBar()
{
    mopTitleBar = new CDlgTitleBar(this);
    mopTitleBar->move(0, 0);

    connect(mopTitleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(msotOnBtnMinClicked()));
    connect(mopTitleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(mslotOnBtnRestoreClicked()));
    connect(mopTitleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(mslotOnBtnMaxClicked()));
    connect(mopTitleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(mslotOnBtnCloseClicked()));

}

void CDlgBaseWindow::mvPaintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    //设置背景色;

    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);
    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillPath(pathBack, QBrush(QColor(236, 241, 245)));

    //	return QWidget::paintEvent(event);
}

void CDlgBaseWindow::mvLoadStyleSheet(const QString &sheetName)
{
    QFile file(sheetName);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void CDlgBaseWindow::msotOnBtnMinClicked()
{
    if (Qt::Tool == (windowFlags() & Qt::Tool))
    {
        hide();    //设置了Qt::Tool 如果调用showMinimized()则窗口就销毁了？？？
    }
    else
    {
        showMinimized();
    }
}


void CDlgBaseWindow::mslotOnBtnRestoreClicked()
{
    QPoint windowPos;
    QSize windowSize;
    mopTitleBar->mvGetRestoreInfo(windowPos, windowSize);
    this->setGeometry(QRect(windowPos, windowSize));
}

void CDlgBaseWindow::mslotOnBtnMaxClicked()
{
    mopTitleBar->mvSaveRestoreInfo(this->pos(), QSize(this->width(), this->height()));
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    QRect FactRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3, desktopRect.width() + 6, desktopRect.height() + 6);
    setGeometry(FactRect);
}

void CDlgBaseWindow::mslotOnBtnCloseClicked()
{
    // 注意 ！！！;
    // 如果设置了Qt::Tool 且当前窗口为主窗口调用close()方法只是关闭了当前窗口，并没有结束整个程序进程;
    // 如果只有一个窗口情况下,需要调用qApp->quit();来结束进程;
    // 如果设置了Qt::Tool的窗口是子窗口，则只需要调用close()方法关闭即可;
    // 	if (Qt::Tool == (windowFlags() & Qt::Tool))
    // 	{
    // 		qApp->quit();
    // 	}
    // 	else
    {
        close();
    }
}
