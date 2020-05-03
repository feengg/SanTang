/********************************************************************************
** Form generated from reading UI file 'tybh.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYBH_H
#define UI_TYBH_H

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

class Ui_TYBH
{
public:
    QLabel *label;
    closeButton *toolButton;
    QGroupBox *groupBox_tyMsg;
    QLabel *label_3;
    QLineEdit *lineEdit_proNum;
    QLabel *label_4;
    QLineEdit *lineEdit_proType;
    QLabel *label_5;
    QLineEdit *lineEdit_productNum;
    QLabel *label_6;
    QLineEdit *lineEdit_productName;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_leaderName;
    QLineEdit *lineEdit_proName;
    QTableWidget *tableWidget;
    QPushButton *pushButton_getOver;
    QLabel *label_2;
    QPushButton *pushButton_min;

    void setupUi(QWidget *TYBH)
    {
        if (TYBH->objectName().isEmpty())
            TYBH->setObjectName(QString::fromUtf8("TYBH"));
        TYBH->resize(1300, 840);
        label = new QLabel(TYBH);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 2, 111, 16));
        toolButton = new closeButton(TYBH);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(1280, 0, 18, 18));
        groupBox_tyMsg = new QGroupBox(TYBH);
        groupBox_tyMsg->setObjectName(QString::fromUtf8("groupBox_tyMsg"));
        groupBox_tyMsg->setGeometry(QRect(10, 60, 1281, 81));
        label_3 = new QLabel(groupBox_tyMsg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 20, 54, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_proNum = new QLineEdit(groupBox_tyMsg);
        lineEdit_proNum->setObjectName(QString::fromUtf8("lineEdit_proNum"));
        lineEdit_proNum->setGeometry(QRect(220, 20, 201, 20));
        lineEdit_proNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_proNum->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_tyMsg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(878, 20, 54, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_proType = new QLineEdit(groupBox_tyMsg);
        lineEdit_proType->setObjectName(QString::fromUtf8("lineEdit_proType"));
        lineEdit_proType->setGeometry(QRect(940, 20, 201, 20));
        lineEdit_proType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_proType->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_tyMsg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(540, 20, 54, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_productNum = new QLineEdit(groupBox_tyMsg);
        lineEdit_productNum->setObjectName(QString::fromUtf8("lineEdit_productNum"));
        lineEdit_productNum->setGeometry(QRect(600, 20, 201, 20));
        lineEdit_productNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        lineEdit_productNum->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_tyMsg);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(540, 50, 54, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_productName = new QLineEdit(groupBox_tyMsg);
        lineEdit_productName->setObjectName(QString::fromUtf8("lineEdit_productName"));
        lineEdit_productName->setGeometry(QRect(600, 50, 201, 20));
        lineEdit_productName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_productName->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(groupBox_tyMsg);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 50, 54, 16));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_8 = new QLabel(groupBox_tyMsg);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(866, 50, 71, 21));
        QFont font;
        font.setPointSize(9);
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_leaderName = new QLineEdit(groupBox_tyMsg);
        lineEdit_leaderName->setObjectName(QString::fromUtf8("lineEdit_leaderName"));
        lineEdit_leaderName->setGeometry(QRect(940, 50, 201, 20));
        lineEdit_leaderName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_leaderName->setAlignment(Qt::AlignCenter);
        lineEdit_proName = new QLineEdit(groupBox_tyMsg);
        lineEdit_proName->setObjectName(QString::fromUtf8("lineEdit_proName"));
        lineEdit_proName->setGeometry(QRect(220, 50, 201, 20));
        lineEdit_proName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_proName->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(TYBH);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 150, 1280, 641));
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 0, 0);"));
        pushButton_getOver = new QPushButton(TYBH);
        pushButton_getOver->setObjectName(QString::fromUtf8("pushButton_getOver"));
        pushButton_getOver->setGeometry(QRect(510, 800, 161, 23));
        pushButton_getOver->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_getOver\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_getOver:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_getOver:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label_2 = new QLabel(TYBH);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(550, 20, 181, 31));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        pushButton_min = new QPushButton(TYBH);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(1250, 0, 28, 16));
        pushButton_min->setMinimumSize(QSize(0, 16));
        pushButton_min->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/min_first.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-image: url(:/images/min_after.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}"));

        retranslateUi(TYBH);

        QMetaObject::connectSlotsByName(TYBH);
    } // setupUi

    void retranslateUi(QWidget *TYBH)
    {
        TYBH->setWindowTitle(QApplication::translate("TYBH", "Form", nullptr));
        label->setText(QApplication::translate("TYBH", "\345\233\276\345\217\267/\346\226\207\344\273\266\347\274\226\345\217\267\346\270\205\345\215\225", nullptr));
        toolButton->setText(QString());
        groupBox_tyMsg->setTitle(QString());
        label_3->setText(QApplication::translate("TYBH", "\351\241\271\347\233\256\344\273\243\345\217\267\357\274\232", nullptr));
        label_4->setText(QApplication::translate("TYBH", "\351\241\271\347\233\256\345\210\206\347\261\273\357\274\232", nullptr));
        label_5->setText(QApplication::translate("TYBH", "\344\272\247\345\223\201\344\273\243\345\217\267\357\274\232", nullptr));
        label_6->setText(QApplication::translate("TYBH", "\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232", nullptr));
        label_7->setText(QApplication::translate("TYBH", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", nullptr));
        label_8->setText(QApplication::translate("TYBH", "\351\241\271\347\233\256\350\264\237\350\264\243\344\272\272\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_getOver->setText(QApplication::translate("TYBH", "\347\202\271\345\207\273\347\273\223\351\241\271", nullptr));
        label_2->setText(QApplication::translate("TYBH", "\345\233\276\345\217\267/\346\226\207\344\273\266\347\274\226\345\217\267\346\270\205\345\215\225", nullptr));
        pushButton_min->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TYBH: public Ui_TYBH {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYBH_H
