/********************************************************************************
** Form generated from reading UI file 'showudptipmsgdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWUDPTIPMSGDIALOG_H
#define UI_SHOWUDPTIPMSGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_showUdpTipMsgDialog
{
public:
    QPushButton *pushButton;
    closeButton *toolButton;
    QLabel *label;
    QLabel *label_pic;

    void setupUi(QDialog *showUdpTipMsgDialog)
    {
        if (showUdpTipMsgDialog->objectName().isEmpty())
            showUdpTipMsgDialog->setObjectName(QString::fromUtf8("showUdpTipMsgDialog"));
        showUdpTipMsgDialog->resize(293, 152);
        pushButton = new QPushButton(showUdpTipMsgDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 120, 75, 23));
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
        toolButton = new closeButton(showUdpTipMsgDialog);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(280, 0, 13, 13));
        toolButton->setIconSize(QSize(15, 15));
        label = new QLabel(showUdpTipMsgDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 281, 41));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"\346\245\267\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);
        label_pic = new QLabel(showUdpTipMsgDialog);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(10, 10, 151, 41));
        label_pic->setPixmap(QPixmap(QString::fromUtf8(":/images/logo_2(1)\345\211\257\346\234\254.png")));
        label_pic->setScaledContents(true);

        retranslateUi(showUdpTipMsgDialog);

        QMetaObject::connectSlotsByName(showUdpTipMsgDialog);
    } // setupUi

    void retranslateUi(QDialog *showUdpTipMsgDialog)
    {
        showUdpTipMsgDialog->setWindowTitle(QApplication::translate("showUdpTipMsgDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("showUdpTipMsgDialog", "\347\241\256\345\256\232", nullptr));
        toolButton->setText(QString());
        label->setText(QString());
        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class showUdpTipMsgDialog: public Ui_showUdpTipMsgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWUDPTIPMSGDIALOG_H
