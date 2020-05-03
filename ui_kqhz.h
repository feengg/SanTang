/********************************************************************************
** Form generated from reading UI file 'kqhz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KQHZ_H
#define UI_KQHZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <closebutton.h>

QT_BEGIN_NAMESPACE

class Ui_KQHZ
{
public:
    QGroupBox *groupBox;
    QComboBox *comboBox_year;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_mouth;
    QPushButton *pushButton_search;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QTableWidget *tableWidget;
    QLabel *label_4;
    closeButton *toolButton;
    QPushButton *pushButton_Ok;

    void setupUi(QWidget *KQHZ)
    {
        if (KQHZ->objectName().isEmpty())
            KQHZ->setObjectName(QString::fromUtf8("KQHZ"));
        KQHZ->resize(929, 782);
        groupBox = new QGroupBox(KQHZ);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 911, 51));
        comboBox_year = new QComboBox(groupBox);
        comboBox_year->setObjectName(QString::fromUtf8("comboBox_year"));
        comboBox_year->setGeometry(QRect(170, 20, 69, 22));
        comboBox_year->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 242);"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 20, 41, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 20, 31, 21));
        comboBox_mouth = new QComboBox(groupBox);
        comboBox_mouth->setObjectName(QString::fromUtf8("comboBox_mouth"));
        comboBox_mouth->setGeometry(QRect(300, 20, 69, 22));
        comboBox_mouth->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 242);"));
        pushButton_search = new QPushButton(groupBox);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(580, 20, 161, 21));
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_search\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_search:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_search:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(390, 21, 41, 21));
        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(430, 20, 101, 21));
        lineEdit_name->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);"));
        tableWidget = new QTableWidget(KQHZ);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 100, 911, 641));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);"));
        label_4 = new QLabel(KQHZ);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 54, 21));
        toolButton = new closeButton(KQHZ);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(910, 0, 18, 18));
        pushButton_Ok = new QPushButton(KQHZ);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setGeometry(QRect(370, 750, 111, 23));
        pushButton_Ok->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Ok\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_Ok:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_Ok:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}\n"
""));

        retranslateUi(KQHZ);

        QMetaObject::connectSlotsByName(KQHZ);
    } // setupUi

    void retranslateUi(QWidget *KQHZ)
    {
        KQHZ->setWindowTitle(QApplication::translate("KQHZ", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("KQHZ", "\346\220\234\347\264\242\346\237\245\350\257\242\346\234\210\344\273\275", nullptr));
        label->setText(QApplication::translate("KQHZ", "\345\271\264\344\273\275\357\274\232", nullptr));
        label_2->setText(QApplication::translate("KQHZ", "\346\234\210\344\273\275\357\274\232", nullptr));
        pushButton_search->setText(QApplication::translate("KQHZ", "\346\237\245\350\257\242", nullptr));
        label_name->setText(QApplication::translate("KQHZ", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("KQHZ", "\350\200\203\345\213\244\346\261\207\346\200\273", nullptr));
        toolButton->setText(QString());
        pushButton_Ok->setText(QApplication::translate("KQHZ", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KQHZ: public Ui_KQHZ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KQHZ_H
