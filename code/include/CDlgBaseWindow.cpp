//******************************************************************************
//	Copyright (C) 2020, SanTang Technologies
//
//******************************************************************************
// File Name		: CDlgCDlgBaseWindow.cpp
// Version			: 1.0
// Author			: Administrator
// Created			: 2020-03-29
// Description		: CDlgCDlgBaseWindow��
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
// Description		: ���캯��
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
    // FramelessWindowHint�������ô���ȥ���߿�;
    // WindowMinimizeButtonHint ���������ڴ�����С��ʱ��������������ڿ�����ʾ��ԭ����;
    //Qt::WindowFlags flag = this->windowFlags();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    // ���ô��ڱ���͸��;
    setAttribute(Qt::WA_TranslucentBackground);
    // �رմ���ʱ�ͷ���Դ;
    //setAttribute(Qt::WA_DeleteOnClose);
    // ��ʼ��������;
    mvInitTitleBar();

}

CDlgBaseWindow::~CDlgBaseWindow()
{

}

//******************************************************************************
// Function			: CDlgBaseWindow::mvInitTitleBar
// Description		: ��ʼ��bar
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

    //���ñ���ɫ;

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
        hide();    //������Qt::Tool �������showMinimized()�򴰿ھ������ˣ�����
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
    // ע�� ������;
    // ���������Qt::Tool �ҵ�ǰ����Ϊ�����ڵ���close()����ֻ�ǹر��˵�ǰ���ڣ���û�н��������������;
    // ���ֻ��һ�����������,��Ҫ����qApp->quit();����������;
    // ���������Qt::Tool�Ĵ������Ӵ��ڣ���ֻ��Ҫ����close()�����رռ���;
    // 	if (Qt::Tool == (windowFlags() & Qt::Tool))
    // 	{
    // 		qApp->quit();
    // 	}
    // 	else
    {
        close();
    }
}
