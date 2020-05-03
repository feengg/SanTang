/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_staffid;
    QLabel *label_2;
    QLineEdit *lineEdit_oldPassw;
    QLineEdit *lineEdit_newPassw;
    QLabel *label_3;
    QLineEdit *lineEdit_recheckPassw;
    QLabel *label_4;
    QPushButton *pushButton;
    closeButton *toolButton;

    void setupUi(QWidget *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->resize(286, 300);
        groupBox = new QGroupBox(ChangePassword);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 40, 231, 211));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 61, 16));
        lineEdit_staffid = new QLineEdit(groupBox);
        lineEdit_staffid->setObjectName(QString::fromUtf8("lineEdit_staffid"));
        lineEdit_staffid->setGeometry(QRect(90, 40, 113, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 81, 61, 21));
        lineEdit_oldPassw = new QLineEdit(groupBox);
        lineEdit_oldPassw->setObjectName(QString::fromUtf8("lineEdit_oldPassw"));
        lineEdit_oldPassw->setGeometry(QRect(90, 80, 113, 20));
        lineEdit_newPassw = new QLineEdit(groupBox);
        lineEdit_newPassw->setObjectName(QString::fromUtf8("lineEdit_newPassw"));
        lineEdit_newPassw->setGeometry(QRect(90, 120, 113, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 121, 71, 21));
        lineEdit_recheckPassw = new QLineEdit(groupBox);
        lineEdit_recheckPassw->setObjectName(QString::fromUtf8("lineEdit_recheckPassw"));
        lineEdit_recheckPassw->setGeometry(QRect(90, 160, 113, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 161, 71, 21));
        pushButton = new QPushButton(ChangePassword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 260, 91, 23));
        QFont font;
        font.setPointSize(9);
        pushButton->setFont(font);
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
        toolButton = new closeButton(ChangePassword);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(270, 0, 16, 16));

        retranslateUi(ChangePassword);

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QWidget *ChangePassword)
    {
        ChangePassword->setWindowTitle(QApplication::translate("ChangePassword", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("ChangePassword", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("ChangePassword", "\345\267\245  \345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ChangePassword", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ChangePassword", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("ChangePassword", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("ChangePassword", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
