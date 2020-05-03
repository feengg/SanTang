/********************************************************************************
** Form generated from reading UI file 'kqhz_sub.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KQHZ_SUB_H
#define UI_KQHZ_SUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <closebutton.h>

QT_BEGIN_NAMESPACE

class Ui_KQHZ_Sub
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    closeButton *toolButton;
    QPushButton *pButtonOk;

    void setupUi(QWidget *KQHZ_Sub)
    {
        if (KQHZ_Sub->objectName().isEmpty())
            KQHZ_Sub->setObjectName(QString::fromUtf8("KQHZ_Sub"));
        KQHZ_Sub->resize(1170, 662);
        tableWidget = new QTableWidget(KQHZ_Sub);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 30, 1151, 591));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);"));
        label = new QLabel(KQHZ_Sub);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 61, 16));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        toolButton = new closeButton(KQHZ_Sub);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(1150, 0, 16, 16));
        pButtonOk = new QPushButton(KQHZ_Sub);
        pButtonOk->setObjectName(QString::fromUtf8("pButtonOk"));
        pButtonOk->setGeometry(QRect(500, 630, 181, 23));
        pButtonOk->setStyleSheet(QString::fromUtf8("QPushButton#pButtonOk\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pButtonOk:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pButtonOk:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}\n"
""));

        retranslateUi(KQHZ_Sub);

        QMetaObject::connectSlotsByName(KQHZ_Sub);
    } // setupUi

    void retranslateUi(QWidget *KQHZ_Sub)
    {
        KQHZ_Sub->setWindowTitle(QApplication::translate("KQHZ_Sub", "Form", nullptr));
        label->setText(QApplication::translate("KQHZ_Sub", "\350\200\203\345\213\244\346\237\245\347\234\213", nullptr));
        toolButton->setText(QString());
        pButtonOk->setText(QApplication::translate("KQHZ_Sub", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KQHZ_Sub: public Ui_KQHZ_Sub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KQHZ_SUB_H
