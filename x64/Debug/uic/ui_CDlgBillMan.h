/********************************************************************************
** Form generated from reading UI file 'CDlgBillMan.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGBILLMAN_H
#define UI_CDLGBILLMAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgBillMan
{
public:
    QGridLayout *gridLayout;
    QPushButton *mopBtnAdd;
    QPushButton *mopBtnDelete;
    QTableWidget *tableWidget;

    void setupUi(QWidget *CDlgBillMan)
    {
        if (CDlgBillMan->objectName().isEmpty())
            CDlgBillMan->setObjectName(QString::fromUtf8("CDlgBillMan"));
        CDlgBillMan->resize(600, 354);
        gridLayout = new QGridLayout(CDlgBillMan);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mopBtnAdd = new QPushButton(CDlgBillMan);
        mopBtnAdd->setObjectName(QString::fromUtf8("mopBtnAdd"));

        gridLayout->addWidget(mopBtnAdd, 0, 0, 1, 1);

        mopBtnDelete = new QPushButton(CDlgBillMan);
        mopBtnDelete->setObjectName(QString::fromUtf8("mopBtnDelete"));

        gridLayout->addWidget(mopBtnDelete, 0, 1, 1, 1);

        tableWidget = new QTableWidget(CDlgBillMan);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 2);


        retranslateUi(CDlgBillMan);

        QMetaObject::connectSlotsByName(CDlgBillMan);
    } // setupUi

    void retranslateUi(QWidget *CDlgBillMan)
    {
        CDlgBillMan->setWindowTitle(QApplication::translate("CDlgBillMan", "CDlgBillMan", nullptr));
        mopBtnAdd->setText(QApplication::translate("CDlgBillMan", "\346\267\273\345\212\240", nullptr));
        mopBtnDelete->setText(QApplication::translate("CDlgBillMan", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgBillMan: public Ui_CDlgBillMan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGBILLMAN_H
