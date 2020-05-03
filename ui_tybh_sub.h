/********************************************************************************
** Form generated from reading UI file 'tybh_sub.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYBH_SUB_H
#define UI_TYBH_SUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_Tybh_sub
{
public:
    QLabel *label;
    closeButton *toolButton;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLineEdit *lineEdit_proNum;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_productNum;
    QLabel *label_6;
    QLineEdit *lineEdit_productName;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_proName;
    QComboBox *comboBox_proLeader;
    QComboBox *comboBox_proType;
    QPushButton *pushButton;

    void setupUi(QWidget *Tybh_sub)
    {
        if (Tybh_sub->objectName().isEmpty())
            Tybh_sub->setObjectName(QString::fromUtf8("Tybh_sub"));
        Tybh_sub->resize(749, 326);
        label = new QLabel(Tybh_sub);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 54, 16));
        toolButton = new closeButton(Tybh_sub);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(730, 0, 16, 16));
        groupBox_2 = new QGroupBox(Tybh_sub);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 50, 721, 221));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 40, 54, 16));
        lineEdit_proNum = new QLineEdit(groupBox_2);
        lineEdit_proNum->setObjectName(QString::fromUtf8("lineEdit_proNum"));
        lineEdit_proNum->setGeometry(QRect(90, 40, 261, 20));
        lineEdit_proNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 160, 71, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 100, 54, 16));
        lineEdit_productNum = new QLineEdit(groupBox_2);
        lineEdit_productNum->setObjectName(QString::fromUtf8("lineEdit_productNum"));
        lineEdit_productNum->setGeometry(QRect(90, 100, 261, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(370, 100, 54, 16));
        lineEdit_productName = new QLineEdit(groupBox_2);
        lineEdit_productName->setObjectName(QString::fromUtf8("lineEdit_productName"));
        lineEdit_productName->setGeometry(QRect(430, 100, 271, 20));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(370, 40, 54, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(368, 160, 54, 16));
        lineEdit_proName = new QLineEdit(groupBox_2);
        lineEdit_proName->setObjectName(QString::fromUtf8("lineEdit_proName"));
        lineEdit_proName->setGeometry(QRect(430, 40, 271, 20));
        comboBox_proLeader = new QComboBox(groupBox_2);
        comboBox_proLeader->setObjectName(QString::fromUtf8("comboBox_proLeader"));
        comboBox_proLeader->setGeometry(QRect(90, 160, 151, 22));
        comboBox_proLeader->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_proLeader->setEditable(true);
        comboBox_proType = new QComboBox(groupBox_2);
        comboBox_proType->setObjectName(QString::fromUtf8("comboBox_proType"));
        comboBox_proType->setGeometry(QRect(430, 160, 151, 22));
        comboBox_proType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(Tybh_sub);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 290, 161, 23));
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
"}\n"
""));

        retranslateUi(Tybh_sub);

        QMetaObject::connectSlotsByName(Tybh_sub);
    } // setupUi

    void retranslateUi(QWidget *Tybh_sub)
    {
        Tybh_sub->setWindowTitle(QApplication::translate("Tybh_sub", "Form", nullptr));
        label->setText(QApplication::translate("Tybh_sub", "\346\226\260\345\242\236\351\241\271\347\233\256", nullptr));
        toolButton->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Tybh_sub", "\346\226\260\345\242\236\351\241\271\347\233\256\345\233\276\346\240\267\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("Tybh_sub", "\351\241\271\347\233\256\344\273\243\345\217\267\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Tybh_sub", "\351\241\271\347\233\256\350\264\237\350\264\243\344\272\272\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Tybh_sub", "\344\272\247\345\223\201\344\273\243\345\217\267\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Tybh_sub", "\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Tybh_sub", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", nullptr));
        label_8->setText(QApplication::translate("Tybh_sub", "\351\241\271\347\233\256\347\261\273\345\210\253\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Tybh_sub", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tybh_sub: public Ui_Tybh_sub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYBH_SUB_H
