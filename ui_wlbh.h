/********************************************************************************
** Form generated from reading UI file 'wlbh.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WLBH_H
#define UI_WLBH_H

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

class Ui_Wlbh
{
public:
    QLabel *label;
    closeButton *toolButton;
    QGroupBox *groupBox;
    QPushButton *pushButton_new;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLineEdit *lineEdit_wlNum;
    QLineEdit *lineEdit_wlName;
    QLabel *label_3;
    QLineEdit *lineEdit_format;
    QLabel *label_4;
    QTableWidget *tableWidget;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *Wlbh)
    {
        if (Wlbh->objectName().isEmpty())
            Wlbh->setObjectName(QString::fromUtf8("Wlbh"));
        Wlbh->resize(790, 671);
        label = new QLabel(Wlbh);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 54, 16));
        toolButton = new closeButton(Wlbh);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(770, 0, 18, 18));
        groupBox = new QGroupBox(Wlbh);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 151, 51));
        pushButton_new = new QPushButton(groupBox);
        pushButton_new->setObjectName(QString::fromUtf8("pushButton_new"));
        pushButton_new->setGeometry(QRect(30, 20, 91, 23));
        pushButton_new->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_new\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_new:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_new:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        groupBox_2 = new QGroupBox(Wlbh);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(180, 30, 601, 51));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 20, 54, 16));
        lineEdit_wlNum = new QLineEdit(groupBox_2);
        lineEdit_wlNum->setObjectName(QString::fromUtf8("lineEdit_wlNum"));
        lineEdit_wlNum->setGeometry(QRect(110, 20, 91, 20));
        lineEdit_wlName = new QLineEdit(groupBox_2);
        lineEdit_wlName->setObjectName(QString::fromUtf8("lineEdit_wlName"));
        lineEdit_wlName->setGeometry(QRect(290, 20, 91, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 20, 54, 16));
        lineEdit_format = new QLineEdit(groupBox_2);
        lineEdit_format->setObjectName(QString::fromUtf8("lineEdit_format"));
        lineEdit_format->setGeometry(QRect(480, 20, 91, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 20, 54, 16));
        tableWidget = new QTableWidget(Wlbh);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 90, 771, 541));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);"));
        pushButton_ok = new QPushButton(Wlbh);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(350, 640, 91, 23));
        pushButton_ok->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_ok\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_ok:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_ok:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}\n"
""));

        retranslateUi(Wlbh);

        QMetaObject::connectSlotsByName(Wlbh);
    } // setupUi

    void retranslateUi(QWidget *Wlbh)
    {
        Wlbh->setWindowTitle(QApplication::translate("Wlbh", "Form", nullptr));
        label->setText(QApplication::translate("Wlbh", "\347\211\251\346\226\231\347\274\226\345\217\267", nullptr));
        toolButton->setText(QString());
        groupBox->setTitle(QApplication::translate("Wlbh", "\346\226\260\345\242\236", nullptr));
        pushButton_new->setText(QApplication::translate("Wlbh", "\346\226\260\345\242\236\347\274\226\345\217\267", nullptr));
        groupBox_2->setTitle(QApplication::translate("Wlbh", "\346\237\245\350\257\242\347\274\226\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Wlbh", "\347\211\251\346\226\231\347\274\226\345\217\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Wlbh", "\347\211\251\346\226\231\345\220\215\347\247\260\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Wlbh", "\350\247\204\346\240\274\345\236\213\345\217\267\357\274\232", nullptr));
        pushButton_ok->setText(QApplication::translate("Wlbh", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wlbh: public Ui_Wlbh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WLBH_H
