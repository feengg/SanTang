/********************************************************************************
** Form generated from reading UI file 'qrcode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRCODE_H
#define UI_QRCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_Qrcode
{
public:
    closeButton *toolButton;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QWidget *Qrcode)
    {
        if (Qrcode->objectName().isEmpty())
            Qrcode->setObjectName(QString::fromUtf8("Qrcode"));
        Qrcode->resize(385, 392);
        toolButton = new closeButton(Qrcode);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(370, 0, 16, 16));
        label = new QLabel(Qrcode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 61, 280, 280));
        pushButton = new QPushButton(Qrcode);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 360, 75, 23));
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
        label_2 = new QLabel(Qrcode);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 20, 181, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";\n"
"color: rgb(0, 85, 255);"));

        retranslateUi(Qrcode);

        QMetaObject::connectSlotsByName(Qrcode);
    } // setupUi

    void retranslateUi(QWidget *Qrcode)
    {
        Qrcode->setWindowTitle(QApplication::translate("Qrcode", "Form", nullptr));
        toolButton->setText(QString());
        label->setText(QApplication::translate("Qrcode", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("Qrcode", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QApplication::translate("Qrcode", "\346\211\253\347\240\201\350\216\267\345\217\226\350\200\203\345\213\244\346\261\207\346\200\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qrcode: public Ui_Qrcode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODE_H
