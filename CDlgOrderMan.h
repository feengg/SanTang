#pragma once

#include <QWidget>
#include "ui_CDlgOrderMan.h"
#include "CDlgOrderToolBar.h"
#include "CDlgNewBill.h"
#include "Global.h"

class CDlgOrderMan : public QWidget
{
    Q_OBJECT

public:
    CDlgOrderMan(QWidget *parent = Q_NULLPTR);
    ~CDlgOrderMan();
    // ����table����
    void mvSetTableWidget(TTabType eDlgType);

signals:
    // ���Ͷ���ID
    void msigSendOrderId(QString msOrderId);
public slots:
    // ���table�����
    void mslotSetTableWidget(TTabType);

private:
    // ��ʼ������
    void mvInitGUI();

    // ��ʼ��Tool
    void mvInitOrderToolBar();

    // ��ʼ���ͻ������б�
    void mvInitCusmerOrdTabTitle();

    // ��ʼ����Э�����б�
    void mvInitSupOrdTabTitle();

private slots:
    // �鿴��
    void mvOnOrderManCheckBtnClicked();

private:

    // ��ʼ������
    void mvInitConnection();

private:
    Ui::CDlgOrderMan ui;                    // �������

    CDlgOrderToolBar *mopOrderToolBar;      // ���߿�

    CDlgNewBill      *mopNewBill;           // �½�ҵ�񶩵�����


};
