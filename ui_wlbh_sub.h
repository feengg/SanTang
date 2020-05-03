/********************************************************************************
** Form generated from reading UI file 'wlbh_sub.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WLBH_SUB_H
#define UI_WLBH_SUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_Wlbh_sub
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lineEdit_wlName;
    QLabel *label_3;
    QLineEdit *lineEdit_wlFormat;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_dealName;
    QLineEdit *lineEdit_dealTime;
    QLabel *label_6;
    QLineEdit *lineEdit_provider;
    QLabel *label_7;
    QLineEdit *lineEdit_wlClass;
    QLabel *label_8;
    QLineEdit *lineEdit_wlNum;
    QPushButton *pushButton_newNum;
    QLabel *label;
    closeButton *toolButton;
    QPushButton *pushButton_save;

    void setupUi(QWidget *Wlbh_sub)
    {
        if (Wlbh_sub->objectName().isEmpty())
            Wlbh_sub->setObjectName(QString::fromUtf8("Wlbh_sub"));
        Wlbh_sub->resize(598, 349);
        groupBox = new QGroupBox(Wlbh_sub);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 40, 561, 261));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 92, 71, 20));
        lineEdit_wlName = new QLineEdit(groupBox);
        lineEdit_wlName->setObjectName(QString::fromUtf8("lineEdit_wlName"));
        lineEdit_wlName->setGeometry(QRect(110, 90, 113, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 90, 111, 21));
        lineEdit_wlFormat = new QLineEdit(groupBox);
        lineEdit_wlFormat->setObjectName(QString::fromUtf8("lineEdit_wlFormat"));
        lineEdit_wlFormat->setGeometry(QRect(390, 90, 131, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(330, 30, 61, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 30, 41, 20));
        lineEdit_dealName = new QLineEdit(groupBox);
        lineEdit_dealName->setObjectName(QString::fromUtf8("lineEdit_dealName"));
        lineEdit_dealName->setEnabled(false);
        lineEdit_dealName->setGeometry(QRect(110, 30, 113, 20));
        lineEdit_dealName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_dealTime = new QLineEdit(groupBox);
        lineEdit_dealTime->setObjectName(QString::fromUtf8("lineEdit_dealTime"));
        lineEdit_dealTime->setEnabled(false);
        lineEdit_dealTime->setGeometry(QRect(390, 30, 131, 20));
        lineEdit_dealTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 141, 41, 21));
        lineEdit_provider = new QLineEdit(groupBox);
        lineEdit_provider->setObjectName(QString::fromUtf8("lineEdit_provider"));
        lineEdit_provider->setGeometry(QRect(110, 140, 411, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(33, 190, 71, 20));
        lineEdit_wlClass = new QLineEdit(groupBox);
        lineEdit_wlClass->setObjectName(QString::fromUtf8("lineEdit_wlClass"));
        lineEdit_wlClass->setGeometry(QRect(110, 190, 113, 20));
        QFont font;
        font.setPointSize(11);
        lineEdit_wlClass->setFont(font);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 190, 71, 16));
        lineEdit_wlNum = new QLineEdit(groupBox);
        lineEdit_wlNum->setObjectName(QString::fromUtf8("lineEdit_wlNum"));
        lineEdit_wlNum->setEnabled(false);
        lineEdit_wlNum->setGeometry(QRect(330, 190, 113, 21));
        lineEdit_wlNum->setFont(font);
        lineEdit_wlNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        pushButton_newNum = new QPushButton(groupBox);
        pushButton_newNum->setObjectName(QString::fromUtf8("pushButton_newNum"));
        pushButton_newNum->setGeometry(QRect(450, 190, 71, 21));
        pushButton_newNum->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_newNum\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_newNum:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_newNum:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label = new QLabel(Wlbh_sub);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 54, 16));
        toolButton = new closeButton(Wlbh_sub);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(578, 0, 18, 18));
        pushButton_save = new QPushButton(Wlbh_sub);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(230, 310, 111, 23));
        pushButton_save->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_save\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_save:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_save:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));

        retranslateUi(Wlbh_sub);

        QMetaObject::connectSlotsByName(Wlbh_sub);
    } // setupUi

    void retranslateUi(QWidget *Wlbh_sub)
    {
        Wlbh_sub->setWindowTitle(QApplication::translate("Wlbh_sub", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Wlbh_sub", "\346\226\260\345\242\236\347\211\251\346\226\231\347\274\226\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Wlbh_sub", "\347\211\251\346\226\231\345\220\215\347\247\260(*)\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Wlbh_sub", "\350\247\204\346\240\274\345\236\213\345\217\267/\345\260\201\350\243\205(*)\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Wlbh_sub", "\347\224\263\350\257\267\346\227\245\346\234\237\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Wlbh_sub", "\347\224\263\350\257\267\344\272\272\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Wlbh_sub", "\345\216\202\345\256\266\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Wlbh_sub", "\347\211\251\346\226\231\345\210\206\347\261\273(*)\357\274\232", nullptr));
        label_8->setText(QApplication::translate("Wlbh_sub", "\346\226\260\347\211\251\346\226\231\347\274\226\347\240\201\357\274\232", nullptr));
        pushButton_newNum->setText(QApplication::translate("Wlbh_sub", "\347\202\271\345\207\273\347\224\237\346\210\220", nullptr));
        label->setText(QApplication::translate("Wlbh_sub", "\347\211\251\346\226\231\347\274\226\345\217\267", nullptr));
        toolButton->setText(QString());
        pushButton_save->setText(QApplication::translate("Wlbh_sub", "\346\217\220\344\272\244\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wlbh_sub: public Ui_Wlbh_sub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WLBH_SUB_H
