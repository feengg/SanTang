/********************************************************************************
** Form generated from reading UI file 'bom.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOM_H
#define UI_BOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_Bom
{
public:
    closeButton *toolButton;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_loadBom;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_mxb;
    QPushButton *pushButton_cgqd;
    QPushButton *pushButton_cgsq;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *Bom)
    {
        if (Bom->objectName().isEmpty())
            Bom->setObjectName(QString::fromUtf8("Bom"));
        Bom->resize(606, 254);
        toolButton = new closeButton(Bom);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(590, 0, 15, 15));
        label = new QLabel(Bom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -4, 54, 21));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        groupBox = new QGroupBox(Bom);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 581, 81));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 41, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(50, 30, 491, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        pushButton_loadBom = new QPushButton(groupBox);
        pushButton_loadBom->setObjectName(QString::fromUtf8("pushButton_loadBom"));
        pushButton_loadBom->setEnabled(true);
        pushButton_loadBom->setGeometry(QRect(540, 30, 31, 21));
        pushButton_loadBom->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_loadBom\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_loadBom:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_loadBom:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        groupBox_2 = new QGroupBox(Bom);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 140, 581, 61));
        pushButton_mxb = new QPushButton(groupBox_2);
        pushButton_mxb->setObjectName(QString::fromUtf8("pushButton_mxb"));
        pushButton_mxb->setGeometry(QRect(50, 20, 131, 23));
        pushButton_mxb->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_mxb\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_mxb:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_mxb:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        pushButton_cgqd = new QPushButton(groupBox_2);
        pushButton_cgqd->setObjectName(QString::fromUtf8("pushButton_cgqd"));
        pushButton_cgqd->setGeometry(QRect(220, 20, 141, 23));
        pushButton_cgqd->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_cgqd\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_cgqd:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_cgqd:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        pushButton_cgsq = new QPushButton(groupBox_2);
        pushButton_cgsq->setObjectName(QString::fromUtf8("pushButton_cgsq"));
        pushButton_cgsq->setGeometry(QRect(390, 20, 151, 23));
        pushButton_cgsq->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_cgsq\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_cgsq:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_cgsq:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        pushButton_ok = new QPushButton(Bom);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(250, 210, 75, 23));
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
"	"));

        retranslateUi(Bom);

        QMetaObject::connectSlotsByName(Bom);
    } // setupUi

    void retranslateUi(QWidget *Bom)
    {
        Bom->setWindowTitle(QApplication::translate("Bom", "Form", nullptr));
        toolButton->setText(QString());
        label->setText(QApplication::translate("Bom", "BOM\345\215\225\345\244\204\347\220\206", nullptr));
        groupBox->setTitle(QApplication::translate("Bom", "\345\257\274\345\205\245BOM\345\215\225", nullptr));
        label_2->setText(QApplication::translate("Bom", "Bom\345\215\225\357\274\232", nullptr));
        pushButton_loadBom->setText(QApplication::translate("Bom", "\346\265\217\350\247\210", nullptr));
        groupBox_2->setTitle(QApplication::translate("Bom", "\345\244\204\347\220\206\346\240\217", nullptr));
        pushButton_mxb->setText(QApplication::translate("Bom", "\345\257\274\345\207\272\347\224\265\350\243\205\346\230\216\347\273\206\350\241\250", nullptr));
        pushButton_cgqd->setText(QApplication::translate("Bom", "\345\257\274\345\207\272\351\207\207\350\264\255\346\270\205\345\215\225", nullptr));
        pushButton_cgsq->setText(QApplication::translate("Bom", "\347\224\237\346\210\220\351\207\207\350\264\255\347\224\263\350\257\267\345\215\225", nullptr));
        pushButton_ok->setText(QApplication::translate("Bom", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bom: public Ui_Bom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOM_H
