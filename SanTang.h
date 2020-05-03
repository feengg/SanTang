#pragma once

#include <QtWidgets/QMainWindow>
#include "SanTang.h"
#include "ui_SanTang.h"
#include "Global.h"
#include "CSQLDatabase.h"
#include "CDlgCustomerEdit.h"
#include "CDlgOrderToolBar.h"
#include "CDlgOrderMan.h"
#include "CDlgNewBill.h"
#include "CDlgOrderManToolBar.h"

//class CSQLDatabase;
//class CDlgCustomerEdit;
//class CDlgOrderToolBar;
//class CDlgOrderMan;
//class CDlgNewBill;
//class CDlgOrderManToolBar;

class ERP : public QMainWindow
{
    Q_OBJECT

public:
    ERP(QWidget *parent = Q_NULLPTR);

    // ��ʼ��db
    bool mbInitDB();
signals:
    void msigSentCustomerOrderManClicked(TTabType);
private:


private slots:
    // ҵ�����
    // �ͻ���������ť
    void mslotOnBtnCustomerOrderManClicked();

    // ��Э��������ť
    void mslotOnBtnSupOrderManClicked();

    // ��ӿͻ�����
    void mslotOnBtnNewOrderClicked();
    void mslotprint(QString);

    // ҵ�񶩵��鿴
    void mslotOnBtnOrderToolCheck(bool);

private:
    // ���������������
    void mvInitOrderManDlg();

    // ��ʼ���еĽ���
    void mvInitlizeGUI();

    // �������еĽ���
    void mvHideAllGUI();

    // ��ʼ������
    void mvInitConnection();
    
private:
    TTabType    meDlgType;      // ������������

public:
    static sptr<CSQLDatabase>   mSqlDatabase;
    static CSQLDatabase* mSql;

private:
    Ui::CDlgMainWindow      ui;
    CDlgCustomerEdit        *mopDlgCustomerEdit;    // �༭�ͻ���Ϣ
    CDlgOrderToolBar        *mopDlgOrderToolBar;    // �����༭������
    CDlgOrderMan            *mopDlgOrderMan;        // �����������
    CDlgNewBill             *mopNewBill;            // ҵ���µ�
    CDlgOrderManToolBar     *mopOrderManBar;        // ����������
    QLabel                  *mopSanTangLogo;        // logo
private:

 };
