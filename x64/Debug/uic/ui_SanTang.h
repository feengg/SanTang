/********************************************************************************
** Form generated from reading UI file 'SanTang.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SANTANG_H
#define UI_SANTANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgMainWindow
{
public:
    QAction *moActInfoMange;
    QAction *mopActCustomerOrderMan;
    QAction *mopActNewCustomerOrder;
    QAction *mopActWithdrawCustomerOrder;
    QAction *mopActSupplierOrderMan;
    QAction *moActSetMaterial;
    QAction *moActSetUnit;
    QAction *moActSetProject;
    QAction *moActSetEmpolyee;
    QAction *moActCustomerMan;
    QAction *moActSupplierMan;
    QAction *moActCustomerRecon;
    QAction *moActSupplierRecon;
    QAction *moActProductAnalysis;
    QAction *moActCustomerAnalysis;
    QAction *moActFinancialAnalysis;
    QAction *moActMonthAnalysis;
    QAction *moActSetCompanyInfo;
    QAction *moActSetPrintFormat;
    QAction *moActResetPassword;
    QAction *moActAbout;
    QAction *moActPurchase;
    QAction *mopActNewSupplierOrder;
    QAction *mopActWithdrawSupplierOrder;
    QWidget *centralWidget;
    QStackedWidget *mopTableWidget;
    QFrame *mopFormToolBar;
    QStatusBar *statusBar;
    QMenuBar *moMenuBar;
    QMenu *moMenuBaseInfoMan;
    QMenu *moMenuBusinessMan;
    QMenu *moMenuCustomerMan;
    QMenu *moMenuFinancialMan;
    QMenu *moStatisticalAnalysis;
    QMenu *moMenuSysinfoMan;
    QMenu *moMenuAssisant;

    void setupUi(QMainWindow *CDlgMainWindow)
    {
        if (CDlgMainWindow->objectName().isEmpty())
            CDlgMainWindow->setObjectName(QString::fromUtf8("CDlgMainWindow"));
        CDlgMainWindow->resize(1176, 640);
        moActInfoMange = new QAction(CDlgMainWindow);
        moActInfoMange->setObjectName(QString::fromUtf8("moActInfoMange"));
        mopActCustomerOrderMan = new QAction(CDlgMainWindow);
        mopActCustomerOrderMan->setObjectName(QString::fromUtf8("mopActCustomerOrderMan"));
        mopActNewCustomerOrder = new QAction(CDlgMainWindow);
        mopActNewCustomerOrder->setObjectName(QString::fromUtf8("mopActNewCustomerOrder"));
        mopActWithdrawCustomerOrder = new QAction(CDlgMainWindow);
        mopActWithdrawCustomerOrder->setObjectName(QString::fromUtf8("mopActWithdrawCustomerOrder"));
        mopActSupplierOrderMan = new QAction(CDlgMainWindow);
        mopActSupplierOrderMan->setObjectName(QString::fromUtf8("mopActSupplierOrderMan"));
        moActSetMaterial = new QAction(CDlgMainWindow);
        moActSetMaterial->setObjectName(QString::fromUtf8("moActSetMaterial"));
        moActSetUnit = new QAction(CDlgMainWindow);
        moActSetUnit->setObjectName(QString::fromUtf8("moActSetUnit"));
        moActSetProject = new QAction(CDlgMainWindow);
        moActSetProject->setObjectName(QString::fromUtf8("moActSetProject"));
        moActSetEmpolyee = new QAction(CDlgMainWindow);
        moActSetEmpolyee->setObjectName(QString::fromUtf8("moActSetEmpolyee"));
        moActCustomerMan = new QAction(CDlgMainWindow);
        moActCustomerMan->setObjectName(QString::fromUtf8("moActCustomerMan"));
        moActSupplierMan = new QAction(CDlgMainWindow);
        moActSupplierMan->setObjectName(QString::fromUtf8("moActSupplierMan"));
        moActCustomerRecon = new QAction(CDlgMainWindow);
        moActCustomerRecon->setObjectName(QString::fromUtf8("moActCustomerRecon"));
        moActSupplierRecon = new QAction(CDlgMainWindow);
        moActSupplierRecon->setObjectName(QString::fromUtf8("moActSupplierRecon"));
        moActProductAnalysis = new QAction(CDlgMainWindow);
        moActProductAnalysis->setObjectName(QString::fromUtf8("moActProductAnalysis"));
        moActCustomerAnalysis = new QAction(CDlgMainWindow);
        moActCustomerAnalysis->setObjectName(QString::fromUtf8("moActCustomerAnalysis"));
        moActFinancialAnalysis = new QAction(CDlgMainWindow);
        moActFinancialAnalysis->setObjectName(QString::fromUtf8("moActFinancialAnalysis"));
        moActMonthAnalysis = new QAction(CDlgMainWindow);
        moActMonthAnalysis->setObjectName(QString::fromUtf8("moActMonthAnalysis"));
        moActSetCompanyInfo = new QAction(CDlgMainWindow);
        moActSetCompanyInfo->setObjectName(QString::fromUtf8("moActSetCompanyInfo"));
        moActSetPrintFormat = new QAction(CDlgMainWindow);
        moActSetPrintFormat->setObjectName(QString::fromUtf8("moActSetPrintFormat"));
        moActResetPassword = new QAction(CDlgMainWindow);
        moActResetPassword->setObjectName(QString::fromUtf8("moActResetPassword"));
        moActAbout = new QAction(CDlgMainWindow);
        moActAbout->setObjectName(QString::fromUtf8("moActAbout"));
        moActPurchase = new QAction(CDlgMainWindow);
        moActPurchase->setObjectName(QString::fromUtf8("moActPurchase"));
        mopActNewSupplierOrder = new QAction(CDlgMainWindow);
        mopActNewSupplierOrder->setObjectName(QString::fromUtf8("mopActNewSupplierOrder"));
        mopActWithdrawSupplierOrder = new QAction(CDlgMainWindow);
        mopActWithdrawSupplierOrder->setObjectName(QString::fromUtf8("mopActWithdrawSupplierOrder"));
        centralWidget = new QWidget(CDlgMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mopTableWidget = new QStackedWidget(centralWidget);
        mopTableWidget->setObjectName(QString::fromUtf8("mopTableWidget"));
        mopTableWidget->setGeometry(QRect(10, 50, 1111, 541));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mopTableWidget->sizePolicy().hasHeightForWidth());
        mopTableWidget->setSizePolicy(sizePolicy);
        mopTableWidget->setStyleSheet(QString::fromUtf8("QStackWidget{\n"
"rgb(255, 255, 127)\n"
"}"));
        mopFormToolBar = new QFrame(centralWidget);
        mopFormToolBar->setObjectName(QString::fromUtf8("mopFormToolBar"));
        mopFormToolBar->setGeometry(QRect(0, 0, 1111, 51));
        mopFormToolBar->setFrameShape(QFrame::StyledPanel);
        mopFormToolBar->setFrameShadow(QFrame::Raised);
        CDlgMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CDlgMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CDlgMainWindow->setStatusBar(statusBar);
        moMenuBar = new QMenuBar(CDlgMainWindow);
        moMenuBar->setObjectName(QString::fromUtf8("moMenuBar"));
        moMenuBar->setGeometry(QRect(0, 0, 1176, 23));
        moMenuBaseInfoMan = new QMenu(moMenuBar);
        moMenuBaseInfoMan->setObjectName(QString::fromUtf8("moMenuBaseInfoMan"));
        moMenuBusinessMan = new QMenu(moMenuBar);
        moMenuBusinessMan->setObjectName(QString::fromUtf8("moMenuBusinessMan"));
        moMenuCustomerMan = new QMenu(moMenuBar);
        moMenuCustomerMan->setObjectName(QString::fromUtf8("moMenuCustomerMan"));
        moMenuFinancialMan = new QMenu(moMenuBar);
        moMenuFinancialMan->setObjectName(QString::fromUtf8("moMenuFinancialMan"));
        moStatisticalAnalysis = new QMenu(moMenuBar);
        moStatisticalAnalysis->setObjectName(QString::fromUtf8("moStatisticalAnalysis"));
        moMenuSysinfoMan = new QMenu(moMenuBar);
        moMenuSysinfoMan->setObjectName(QString::fromUtf8("moMenuSysinfoMan"));
        moMenuAssisant = new QMenu(moMenuBar);
        moMenuAssisant->setObjectName(QString::fromUtf8("moMenuAssisant"));
        CDlgMainWindow->setMenuBar(moMenuBar);

        moMenuBar->addAction(moMenuBaseInfoMan->menuAction());
        moMenuBar->addAction(moMenuBusinessMan->menuAction());
        moMenuBar->addAction(moMenuCustomerMan->menuAction());
        moMenuBar->addAction(moMenuFinancialMan->menuAction());
        moMenuBar->addAction(moStatisticalAnalysis->menuAction());
        moMenuBar->addAction(moMenuSysinfoMan->menuAction());
        moMenuBar->addAction(moMenuAssisant->menuAction());
        moMenuBaseInfoMan->addAction(moActInfoMange);
        moMenuBaseInfoMan->addAction(moActSetMaterial);
        moMenuBaseInfoMan->addAction(moActSetUnit);
        moMenuBaseInfoMan->addAction(moActSetProject);
        moMenuBaseInfoMan->addAction(moActSetEmpolyee);
        moMenuBusinessMan->addAction(mopActCustomerOrderMan);
        moMenuBusinessMan->addAction(mopActNewCustomerOrder);
        moMenuBusinessMan->addAction(mopActWithdrawCustomerOrder);
        moMenuBusinessMan->addAction(mopActSupplierOrderMan);
        moMenuBusinessMan->addAction(mopActNewSupplierOrder);
        moMenuBusinessMan->addAction(mopActWithdrawSupplierOrder);
        moMenuCustomerMan->addAction(moActCustomerMan);
        moMenuCustomerMan->addAction(moActSupplierMan);
        moMenuFinancialMan->addAction(moActCustomerRecon);
        moMenuFinancialMan->addAction(moActSupplierRecon);
        moStatisticalAnalysis->addAction(moActProductAnalysis);
        moStatisticalAnalysis->addAction(moActCustomerAnalysis);
        moStatisticalAnalysis->addAction(moActFinancialAnalysis);
        moStatisticalAnalysis->addAction(moActMonthAnalysis);
        moMenuSysinfoMan->addAction(moActSetCompanyInfo);
        moMenuSysinfoMan->addAction(moActSetPrintFormat);
        moMenuSysinfoMan->addAction(moActResetPassword);
        moMenuAssisant->addAction(moActAbout);
        moMenuAssisant->addAction(moActPurchase);

        retranslateUi(CDlgMainWindow);

        QMetaObject::connectSlotsByName(CDlgMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CDlgMainWindow)
    {
        CDlgMainWindow->setWindowTitle(QApplication::translate("CDlgMainWindow", "ERP", nullptr));
        moActInfoMange->setText(QApplication::translate("CDlgMainWindow", "\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        mopActCustomerOrderMan->setText(QApplication::translate("CDlgMainWindow", "\350\256\242\345\215\225\347\256\241\347\220\206", nullptr));
        mopActNewCustomerOrder->setText(QApplication::translate("CDlgMainWindow", "\344\270\232\345\212\241\346\226\260\345\215\225", nullptr));
        mopActWithdrawCustomerOrder->setText(QApplication::translate("CDlgMainWindow", "\344\270\232\345\212\241\351\200\200\345\215\225", nullptr));
        mopActSupplierOrderMan->setText(QApplication::translate("CDlgMainWindow", "\345\244\226\345\215\217\345\212\240\345\267\245", nullptr));
        moActSetMaterial->setText(QApplication::translate("CDlgMainWindow", "\350\200\227\346\235\220\350\256\276\347\275\256", nullptr));
        moActSetUnit->setText(QApplication::translate("CDlgMainWindow", "\350\256\241\351\207\217\345\215\225\344\275\215", nullptr));
        moActSetProject->setText(QApplication::translate("CDlgMainWindow", "\351\241\271\347\233\256\350\256\276\347\275\256", nullptr));
        moActSetEmpolyee->setText(QApplication::translate("CDlgMainWindow", "\345\221\230\345\267\245\350\256\276\347\275\256", nullptr));
        moActCustomerMan->setText(QApplication::translate("CDlgMainWindow", "\345\256\242\346\210\267\347\256\241\347\220\206", nullptr));
        moActSupplierMan->setText(QApplication::translate("CDlgMainWindow", "\344\276\233\345\272\224\345\225\206\347\256\241\347\220\206", nullptr));
        moActCustomerRecon->setText(QApplication::translate("CDlgMainWindow", "\345\256\242\346\210\267\345\257\271\350\264\246-\345\272\224\346\224\266", nullptr));
        moActSupplierRecon->setText(QApplication::translate("CDlgMainWindow", "\345\244\226\345\215\217\345\257\271\350\264\246-\345\272\224\344\273\230", nullptr));
        moActProductAnalysis->setText(QApplication::translate("CDlgMainWindow", "\344\272\247\345\223\201\344\270\232\345\212\241\351\207\217\347\273\237\350\256\241", nullptr));
        moActCustomerAnalysis->setText(QApplication::translate("CDlgMainWindow", "\345\256\242\346\210\267\344\270\232\345\212\241\351\207\217\347\273\237\350\256\241", nullptr));
        moActFinancialAnalysis->setText(QApplication::translate("CDlgMainWindow", "\350\264\246\345\212\241\346\224\266\346\224\257\347\273\237\350\256\241\350\241\250", nullptr));
        moActMonthAnalysis->setText(QApplication::translate("CDlgMainWindow", "\346\234\210\345\272\246\347\273\237\350\256\241\346\212\245\350\241\250", nullptr));
        moActSetCompanyInfo->setText(QApplication::translate("CDlgMainWindow", "\345\205\254\345\217\270\344\277\241\346\201\257\350\256\276\347\275\256", nullptr));
        moActSetPrintFormat->setText(QApplication::translate("CDlgMainWindow", "\346\211\223\345\215\260\346\240\274\345\274\217\350\256\276\350\256\241", nullptr));
        moActResetPassword->setText(QApplication::translate("CDlgMainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        moActAbout->setText(QApplication::translate("CDlgMainWindow", "\345\205\263\344\272\216", nullptr));
        moActPurchase->setText(QApplication::translate("CDlgMainWindow", "\350\201\224\347\263\273\350\264\255\344\271\260", nullptr));
        mopActNewSupplierOrder->setText(QApplication::translate("CDlgMainWindow", "\345\244\226\345\215\217\346\226\260\345\215\225", nullptr));
        mopActWithdrawSupplierOrder->setText(QApplication::translate("CDlgMainWindow", "\345\244\226\345\215\217\351\200\200\345\215\225", nullptr));
        moMenuBaseInfoMan->setTitle(QApplication::translate("CDlgMainWindow", "\345\237\272\347\241\200\350\265\204\346\226\231", nullptr));
        moMenuBusinessMan->setTitle(QApplication::translate("CDlgMainWindow", "\344\270\232\345\212\241\347\256\241\347\220\206", nullptr));
        moMenuCustomerMan->setTitle(QApplication::translate("CDlgMainWindow", "\345\256\242\346\210\267\347\256\241\347\220\206", nullptr));
        moMenuFinancialMan->setTitle(QApplication::translate("CDlgMainWindow", "\350\264\242\345\212\241\347\256\241\347\220\206", nullptr));
        moStatisticalAnalysis->setTitle(QApplication::translate("CDlgMainWindow", "\347\273\237\350\256\241\345\210\206\346\236\220", nullptr));
        moMenuSysinfoMan->setTitle(QApplication::translate("CDlgMainWindow", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
        moMenuAssisant->setTitle(QApplication::translate("CDlgMainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgMainWindow: public Ui_CDlgMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SANTANG_H
