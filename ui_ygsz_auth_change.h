/********************************************************************************
** Form generated from reading UI file 'ygsz_auth_change.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YGSZ_AUTH_CHANGE_H
#define UI_YGSZ_AUTH_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_YGSZ_Auth_Change
{
public:
    QGroupBox *groupBox;
    QTableWidget *tableWidget_All;
    QLineEdit *lineEdit_Name;
    QLabel *label;
    QPushButton *pushButton_Push;
    QPushButton *pushButton_Pop;
    QTableWidget *tableWidget_Owner;
    QLabel *label_2;
    closeButton *toolButton;
    QPushButton *pushButton;

    void setupUi(QWidget *YGSZ_Auth_Change)
    {
        if (YGSZ_Auth_Change->objectName().isEmpty())
            YGSZ_Auth_Change->setObjectName(QString::fromUtf8("YGSZ_Auth_Change"));
        YGSZ_Auth_Change->resize(620, 387);
        groupBox = new QGroupBox(YGSZ_Auth_Change);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 50, 551, 291));
        tableWidget_All = new QTableWidget(groupBox);
        tableWidget_All->setObjectName(QString::fromUtf8("tableWidget_All"));
        tableWidget_All->setEnabled(true);
        tableWidget_All->setGeometry(QRect(10, 50, 241, 231));
        tableWidget_All->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 251, 242);"));
        lineEdit_Name = new QLineEdit(groupBox);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setGeometry(QRect(100, 20, 113, 21));
        lineEdit_Name->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 54, 21));
        pushButton_Push = new QPushButton(groupBox);
        pushButton_Push->setObjectName(QString::fromUtf8("pushButton_Push"));
        pushButton_Push->setGeometry(QRect(260, 130, 41, 31));
        pushButton_Push->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Push\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"	background-image: url(:/images/\345\257\274\345\205\245.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_Push:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"	background-image: url(:/images/\345\257\274\345\205\245.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_Push:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"	background-image: url(:/images/\345\257\274\345\205\245.png);\n"
"}\n"
""));
        pushButton_Push->setIconSize(QSize(16, 16));
        pushButton_Pop = new QPushButton(groupBox);
        pushButton_Pop->setObjectName(QString::fromUtf8("pushButton_Pop"));
        pushButton_Pop->setGeometry(QRect(260, 190, 41, 31));
        pushButton_Pop->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_Pop\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"	background-image: url(:/images/\345\257\274\345\207\272.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_Pop:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"	background-image: url(:/images/\345\257\274\345\207\272.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_Pop:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"	background-image: url(:/images/\345\257\274\345\207\272.png);\n"
"}\n"
""));
        tableWidget_Owner = new QTableWidget(groupBox);
        tableWidget_Owner->setObjectName(QString::fromUtf8("tableWidget_Owner"));
        tableWidget_Owner->setEnabled(true);
        tableWidget_Owner->setGeometry(QRect(310, 50, 231, 231));
        tableWidget_Owner->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 242);"));
        label_2 = new QLabel(YGSZ_Auth_Change);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 54, 16));
        toolButton = new closeButton(YGSZ_Auth_Change);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(600, 0, 17, 17));
        pushButton = new QPushButton(YGSZ_Auth_Change);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 350, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));

        retranslateUi(YGSZ_Auth_Change);

        QMetaObject::connectSlotsByName(YGSZ_Auth_Change);
    } // setupUi

    void retranslateUi(QWidget *YGSZ_Auth_Change)
    {
        YGSZ_Auth_Change->setWindowTitle(QApplication::translate("YGSZ_Auth_Change", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("YGSZ_Auth_Change", "\346\267\273\345\212\240\346\235\203\351\231\220", nullptr));
        label->setText(QApplication::translate("YGSZ_Auth_Change", "\345\220\215\345\255\227\346\220\234\347\264\242\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Push->setToolTip(QApplication::translate("YGSZ_Auth_Change", "\346\267\273\345\212\240\346\235\203\351\231\220", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Push->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Pop->setToolTip(QApplication::translate("YGSZ_Auth_Change", "\345\210\240\351\231\244\346\235\203\351\231\220", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Pop->setText(QString());
        label_2->setText(QApplication::translate("YGSZ_Auth_Change", "\346\235\203\351\231\220\344\277\256\346\224\271", nullptr));
        toolButton->setText(QString());
        pushButton->setText(QApplication::translate("YGSZ_Auth_Change", "\347\241\256 \345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YGSZ_Auth_Change: public Ui_YGSZ_Auth_Change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YGSZ_AUTH_CHANGE_H
