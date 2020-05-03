/********************************************************************************
** Form generated from reading UI file 'CDlgNewBill.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGNEWBILL_H
#define UI_CDLGNEWBILL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgNewBill
{
public:
    QPushButton *mopBtnNew;
    QPushButton *mopBtnSave;
    QPushButton *mopBtnEdit;
    QPushButton *mopBtnVerify;
    QPushButton *mopBtnPrint;
    QPushButton *mopBtnCancel;
    QLabel *mopLabData;
    QLabel *mopLabBillID;
    QLabel *mopLabClerk;
    QLabel *mopLabDesigner;
    QLabel *mopLabDeliveryWay;
    QLabel *mopLabDeliveryData;
    QLabel *mopLabCustomerName;
    QLabel *mopLabTel;
    QLineEdit *mopLineEditTel;
    QLabel *mopLabAddress;
    QLineEdit *mopLineEditAddress;
    QPushButton *mopBtnSearch;
    QComboBox *mopComBoxClerk;
    QComboBox *mopComBoxDesigner;
    QPushButton *mopBtnAddItem;
    QPushButton *mopBtnCopyItem;
    QPushButton *mopBtnDeleteItem;
    QTableWidget *mopTabItems;
    QDateEdit *mopDateOrderBuild;
    QDateEdit *mopTimeDeliveryData;
    QComboBox *mopComBoxDeliveryWay;
    QComboBox *mopComCustomers;
    QLineEdit *mopLinEditOrderId;
    QLabel *mopLabEarnestMoney;
    QLabel *mopLabTotalMoney;
    QLabel *mopLabDeliveryMoney;
    QLabel *mopLabOrderStatus;
    QTextEdit *mopTxtRemarks;
    QLabel *mopLabRemarks;
    QLineEdit *mopDeliveryPrice;
    QLineEdit *mopTotalPrice;
    QLineEdit *mopLinePrePay;
    QComboBox *mopComBoxOrderStatus;

    void setupUi(QWidget *CDlgNewBill)
    {
        if (CDlgNewBill->objectName().isEmpty())
            CDlgNewBill->setObjectName(QString::fromUtf8("CDlgNewBill"));
        CDlgNewBill->resize(1146, 585);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CDlgNewBill->sizePolicy().hasHeightForWidth());
        CDlgNewBill->setSizePolicy(sizePolicy);
        mopBtnNew = new QPushButton(CDlgNewBill);
        mopBtnNew->setObjectName(QString::fromUtf8("mopBtnNew"));
        mopBtnNew->setGeometry(QRect(10, 20, 75, 23));
        mopBtnSave = new QPushButton(CDlgNewBill);
        mopBtnSave->setObjectName(QString::fromUtf8("mopBtnSave"));
        mopBtnSave->setGeometry(QRect(100, 20, 75, 23));
        mopBtnEdit = new QPushButton(CDlgNewBill);
        mopBtnEdit->setObjectName(QString::fromUtf8("mopBtnEdit"));
        mopBtnEdit->setGeometry(QRect(190, 20, 75, 23));
        mopBtnVerify = new QPushButton(CDlgNewBill);
        mopBtnVerify->setObjectName(QString::fromUtf8("mopBtnVerify"));
        mopBtnVerify->setGeometry(QRect(280, 20, 75, 23));
        mopBtnPrint = new QPushButton(CDlgNewBill);
        mopBtnPrint->setObjectName(QString::fromUtf8("mopBtnPrint"));
        mopBtnPrint->setGeometry(QRect(360, 20, 75, 23));
        mopBtnCancel = new QPushButton(CDlgNewBill);
        mopBtnCancel->setObjectName(QString::fromUtf8("mopBtnCancel"));
        mopBtnCancel->setGeometry(QRect(440, 20, 75, 23));
        mopLabData = new QLabel(CDlgNewBill);
        mopLabData->setObjectName(QString::fromUtf8("mopLabData"));
        mopLabData->setGeometry(QRect(390, 60, 54, 12));
        mopLabBillID = new QLabel(CDlgNewBill);
        mopLabBillID->setObjectName(QString::fromUtf8("mopLabBillID"));
        mopLabBillID->setGeometry(QRect(590, 60, 54, 12));
        mopLabClerk = new QLabel(CDlgNewBill);
        mopLabClerk->setObjectName(QString::fromUtf8("mopLabClerk"));
        mopLabClerk->setGeometry(QRect(390, 90, 54, 12));
        mopLabDesigner = new QLabel(CDlgNewBill);
        mopLabDesigner->setObjectName(QString::fromUtf8("mopLabDesigner"));
        mopLabDesigner->setGeometry(QRect(390, 120, 54, 12));
        mopLabDeliveryWay = new QLabel(CDlgNewBill);
        mopLabDeliveryWay->setObjectName(QString::fromUtf8("mopLabDeliveryWay"));
        mopLabDeliveryWay->setGeometry(QRect(590, 90, 81, 16));
        mopLabDeliveryData = new QLabel(CDlgNewBill);
        mopLabDeliveryData->setObjectName(QString::fromUtf8("mopLabDeliveryData"));
        mopLabDeliveryData->setGeometry(QRect(590, 120, 91, 16));
        mopLabCustomerName = new QLabel(CDlgNewBill);
        mopLabCustomerName->setObjectName(QString::fromUtf8("mopLabCustomerName"));
        mopLabCustomerName->setGeometry(QRect(30, 70, 91, 16));
        mopLabTel = new QLabel(CDlgNewBill);
        mopLabTel->setObjectName(QString::fromUtf8("mopLabTel"));
        mopLabTel->setGeometry(QRect(30, 100, 54, 12));
        mopLineEditTel = new QLineEdit(CDlgNewBill);
        mopLineEditTel->setObjectName(QString::fromUtf8("mopLineEditTel"));
        mopLineEditTel->setGeometry(QRect(110, 100, 113, 20));
        mopLabAddress = new QLabel(CDlgNewBill);
        mopLabAddress->setObjectName(QString::fromUtf8("mopLabAddress"));
        mopLabAddress->setGeometry(QRect(30, 130, 54, 12));
        mopLineEditAddress = new QLineEdit(CDlgNewBill);
        mopLineEditAddress->setObjectName(QString::fromUtf8("mopLineEditAddress"));
        mopLineEditAddress->setGeometry(QRect(110, 130, 113, 20));
        mopBtnSearch = new QPushButton(CDlgNewBill);
        mopBtnSearch->setObjectName(QString::fromUtf8("mopBtnSearch"));
        mopBtnSearch->setGeometry(QRect(240, 70, 75, 23));
        mopComBoxClerk = new QComboBox(CDlgNewBill);
        mopComBoxClerk->setObjectName(QString::fromUtf8("mopComBoxClerk"));
        mopComBoxClerk->setGeometry(QRect(450, 86, 69, 22));
        mopComBoxDesigner = new QComboBox(CDlgNewBill);
        mopComBoxDesigner->setObjectName(QString::fromUtf8("mopComBoxDesigner"));
        mopComBoxDesigner->setGeometry(QRect(450, 117, 69, 22));
        mopBtnAddItem = new QPushButton(CDlgNewBill);
        mopBtnAddItem->setObjectName(QString::fromUtf8("mopBtnAddItem"));
        mopBtnAddItem->setGeometry(QRect(10, 170, 75, 23));
        mopBtnCopyItem = new QPushButton(CDlgNewBill);
        mopBtnCopyItem->setObjectName(QString::fromUtf8("mopBtnCopyItem"));
        mopBtnCopyItem->setGeometry(QRect(100, 170, 75, 23));
        mopBtnDeleteItem = new QPushButton(CDlgNewBill);
        mopBtnDeleteItem->setObjectName(QString::fromUtf8("mopBtnDeleteItem"));
        mopBtnDeleteItem->setGeometry(QRect(180, 170, 75, 23));
        mopTabItems = new QTableWidget(CDlgNewBill);
        mopTabItems->setObjectName(QString::fromUtf8("mopTabItems"));
        mopTabItems->setGeometry(QRect(10, 200, 1131, 231));
        mopDateOrderBuild = new QDateEdit(CDlgNewBill);
        mopDateOrderBuild->setObjectName(QString::fromUtf8("mopDateOrderBuild"));
        mopDateOrderBuild->setGeometry(QRect(450, 54, 110, 22));
        mopDateOrderBuild->setAcceptDrops(false);
        mopDateOrderBuild->setAutoFillBackground(true);
        mopDateOrderBuild->setAccelerated(false);
        mopDateOrderBuild->setProperty("showGroupSeparator", QVariant(false));
        mopDateOrderBuild->setCalendarPopup(true);
        mopTimeDeliveryData = new QDateEdit(CDlgNewBill);
        mopTimeDeliveryData->setObjectName(QString::fromUtf8("mopTimeDeliveryData"));
        mopTimeDeliveryData->setGeometry(QRect(670, 119, 110, 22));
        mopTimeDeliveryData->setCalendarPopup(true);
        mopComBoxDeliveryWay = new QComboBox(CDlgNewBill);
        mopComBoxDeliveryWay->setObjectName(QString::fromUtf8("mopComBoxDeliveryWay"));
        mopComBoxDeliveryWay->setGeometry(QRect(670, 87, 69, 22));
        mopComCustomers = new QComboBox(CDlgNewBill);
        mopComCustomers->setObjectName(QString::fromUtf8("mopComCustomers"));
        mopComCustomers->setGeometry(QRect(110, 70, 111, 22));
        mopComCustomers->setEditable(true);
        mopLinEditOrderId = new QLineEdit(CDlgNewBill);
        mopLinEditOrderId->setObjectName(QString::fromUtf8("mopLinEditOrderId"));
        mopLinEditOrderId->setGeometry(QRect(670, 56, 113, 20));
        mopLinEditOrderId->setReadOnly(true);
        mopLabEarnestMoney = new QLabel(CDlgNewBill);
        mopLabEarnestMoney->setObjectName(QString::fromUtf8("mopLabEarnestMoney"));
        mopLabEarnestMoney->setGeometry(QRect(320, 450, 41, 16));
        mopLabTotalMoney = new QLabel(CDlgNewBill);
        mopLabTotalMoney->setObjectName(QString::fromUtf8("mopLabTotalMoney"));
        mopLabTotalMoney->setGeometry(QRect(170, 450, 91, 16));
        mopLabDeliveryMoney = new QLabel(CDlgNewBill);
        mopLabDeliveryMoney->setObjectName(QString::fromUtf8("mopLabDeliveryMoney"));
        mopLabDeliveryMoney->setGeometry(QRect(20, 450, 91, 16));
        mopLabOrderStatus = new QLabel(CDlgNewBill);
        mopLabOrderStatus->setObjectName(QString::fromUtf8("mopLabOrderStatus"));
        mopLabOrderStatus->setGeometry(QRect(470, 450, 91, 16));
        mopTxtRemarks = new QTextEdit(CDlgNewBill);
        mopTxtRemarks->setObjectName(QString::fromUtf8("mopTxtRemarks"));
        mopTxtRemarks->setGeometry(QRect(20, 500, 1121, 71));
        mopLabRemarks = new QLabel(CDlgNewBill);
        mopLabRemarks->setObjectName(QString::fromUtf8("mopLabRemarks"));
        mopLabRemarks->setGeometry(QRect(20, 480, 41, 16));
        mopDeliveryPrice = new QLineEdit(CDlgNewBill);
        mopDeliveryPrice->setObjectName(QString::fromUtf8("mopDeliveryPrice"));
        mopDeliveryPrice->setGeometry(QRect(60, 450, 91, 20));
        mopTotalPrice = new QLineEdit(CDlgNewBill);
        mopTotalPrice->setObjectName(QString::fromUtf8("mopTotalPrice"));
        mopTotalPrice->setGeometry(QRect(210, 450, 91, 20));
        mopLinePrePay = new QLineEdit(CDlgNewBill);
        mopLinePrePay->setObjectName(QString::fromUtf8("mopLinePrePay"));
        mopLinePrePay->setGeometry(QRect(360, 450, 91, 20));
        mopComBoxOrderStatus = new QComboBox(CDlgNewBill);
        mopComBoxOrderStatus->setObjectName(QString::fromUtf8("mopComBoxOrderStatus"));
        mopComBoxOrderStatus->setGeometry(QRect(514, 447, 69, 22));

        retranslateUi(CDlgNewBill);

        QMetaObject::connectSlotsByName(CDlgNewBill);
    } // setupUi

    void retranslateUi(QWidget *CDlgNewBill)
    {
        CDlgNewBill->setWindowTitle(QApplication::translate("CDlgNewBill", "\346\226\260\345\242\236\350\256\242\345\215\225", nullptr));
        mopBtnNew->setText(QApplication::translate("CDlgNewBill", "\346\226\260\345\273\272", nullptr));
        mopBtnSave->setText(QApplication::translate("CDlgNewBill", "\344\277\235\345\255\230", nullptr));
        mopBtnEdit->setText(QApplication::translate("CDlgNewBill", "\347\274\226\350\276\221", nullptr));
        mopBtnVerify->setText(QApplication::translate("CDlgNewBill", "\345\256\241\346\240\270", nullptr));
        mopBtnPrint->setText(QApplication::translate("CDlgNewBill", "\346\211\223\345\215\260", nullptr));
        mopBtnCancel->setText(QApplication::translate("CDlgNewBill", "\345\217\226\346\266\210", nullptr));
        mopLabData->setText(QApplication::translate("CDlgNewBill", "\346\227\245\346\234\237\357\274\232", nullptr));
        mopLabBillID->setText(QApplication::translate("CDlgNewBill", "\350\256\242\345\215\225\347\274\226\345\217\267\357\274\232", nullptr));
        mopLabClerk->setText(QApplication::translate("CDlgNewBill", "\344\270\232\345\212\241\345\221\230\357\274\232", nullptr));
        mopLabDesigner->setText(QApplication::translate("CDlgNewBill", "\350\256\276\350\256\241\345\221\230\357\274\232", nullptr));
        mopLabDeliveryWay->setText(QApplication::translate("CDlgNewBill", "\344\272\244\350\264\247\346\226\271\345\274\217\357\274\232", nullptr));
        mopLabDeliveryData->setText(QApplication::translate("CDlgNewBill", "\344\272\244\350\264\247\346\227\245\346\234\237\357\274\232", nullptr));
        mopLabCustomerName->setText(QApplication::translate("CDlgNewBill", "\345\256\242\346\210\267\345\220\215\347\247\260\357\274\232", nullptr));
        mopLabTel->setText(QApplication::translate("CDlgNewBill", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", nullptr));
        mopLabAddress->setText(QApplication::translate("CDlgNewBill", "\350\201\224\347\263\273\345\234\260\345\235\200\357\274\232", nullptr));
        mopBtnSearch->setText(QApplication::translate("CDlgNewBill", "\346\220\234\347\264\242", nullptr));
        mopBtnAddItem->setText(QApplication::translate("CDlgNewBill", "\345\242\236\345\212\240\346\230\216\347\273\206", nullptr));
        mopBtnCopyItem->setText(QApplication::translate("CDlgNewBill", "\345\244\215\345\210\266\346\230\216\347\273\206", nullptr));
        mopBtnDeleteItem->setText(QApplication::translate("CDlgNewBill", "\345\210\240\351\231\244\346\230\216\347\273\206", nullptr));
        mopLabEarnestMoney->setText(QApplication::translate("CDlgNewBill", "\345\256\232\351\207\221\357\274\232", nullptr));
        mopLabTotalMoney->setText(QApplication::translate("CDlgNewBill", "\346\200\273\344\273\267\357\274\232", nullptr));
        mopLabDeliveryMoney->setText(QApplication::translate("CDlgNewBill", "\350\277\220\350\264\271\357\274\232", nullptr));
        mopLabOrderStatus->setText(QApplication::translate("CDlgNewBill", "\347\212\266\346\200\201\357\274\232", nullptr));
        mopLabRemarks->setText(QApplication::translate("CDlgNewBill", "\345\244\207\346\263\250\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgNewBill: public Ui_CDlgNewBill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGNEWBILL_H
