/********************************************************************************
** Form generated from reading UI file 'showdontupdatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDONTUPDATEDIALOG_H
#define UI_SHOWDONTUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showDontUpdateDialog
{
public:
    QLabel *label_msg;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QWidget *showDontUpdateDialog)
    {
        if (showDontUpdateDialog->objectName().isEmpty())
            showDontUpdateDialog->setObjectName(QString::fromUtf8("showDontUpdateDialog"));
        showDontUpdateDialog->resize(375, 161);
        label_msg = new QLabel(showDontUpdateDialog);
        label_msg->setObjectName(QString::fromUtf8("label_msg"));
        label_msg->setGeometry(QRect(100, 40, 271, 51));
        QFont font;
        font.setPointSize(11);
        label_msg->setFont(font);
        pushButton = new QPushButton(showDontUpdateDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 120, 75, 23));
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
"}"));
        label_2 = new QLabel(showDontUpdateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 50, 61, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        retranslateUi(showDontUpdateDialog);

        QMetaObject::connectSlotsByName(showDontUpdateDialog);
    } // setupUi

    void retranslateUi(QWidget *showDontUpdateDialog)
    {
        showDontUpdateDialog->setWindowTitle(QApplication::translate("showDontUpdateDialog", "Form", nullptr));
        label_msg->setText(QApplication::translate("showDontUpdateDialog", "\346\202\250\345\267\262\346\230\257\346\234\200\346\226\260\347\211\210\346\234\254\357\274\214\346\227\240\351\234\200\346\233\264\346\226\260\357\274\201", nullptr));
        pushButton->setText(QApplication::translate("showDontUpdateDialog", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QApplication::translate("showDontUpdateDialog", "OA\346\217\220\347\244\272\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showDontUpdateDialog: public Ui_showDontUpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDONTUPDATEDIALOG_H
