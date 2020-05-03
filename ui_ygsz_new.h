/********************************************************************************
** Form generated from reading UI file 'ygsz_new.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YGSZ_NEW_H
#define UI_YGSZ_NEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_YGSZ_New
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_staffID;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_sex;
    QLineEdit *lineEdit_position;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_phone;
    QLabel *label_7;
    QLineEdit *lineEdit_ip;
    QLabel *label_8;
    QComboBox *comboBox_marriage;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_workTime;
    QToolButton *toolButton_time;
    QComboBox *comboBox_department;
    QLabel *label_11;
    QComboBox *comboBox_edu;
    QLabel *label_12;
    QLineEdit *lineEdit_idCard;
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton;
    closeButton *toolButton_2;
    QLabel *label_title;

    void setupUi(QWidget *YGSZ_New)
    {
        if (YGSZ_New->objectName().isEmpty())
            YGSZ_New->setObjectName(QString::fromUtf8("YGSZ_New"));
        YGSZ_New->resize(775, 310);
        groupBox = new QGroupBox(YGSZ_New);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 741, 221));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox->setFlat(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 51, 16));
        lineEdit_staffID = new QLineEdit(groupBox);
        lineEdit_staffID->setObjectName(QString::fromUtf8("lineEdit_staffID"));
        lineEdit_staffID->setGeometry(QRect(70, 40, 111, 20));
        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(230, 40, 111, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 40, 31, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 40, 41, 21));
        comboBox_sex = new QComboBox(groupBox);
        comboBox_sex->setObjectName(QString::fromUtf8("comboBox_sex"));
        comboBox_sex->setGeometry(QRect(420, 40, 71, 22));
        comboBox_sex->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        comboBox_sex->setEditable(false);
        lineEdit_position = new QLineEdit(groupBox);
        lineEdit_position->setObjectName(QString::fromUtf8("lineEdit_position"));
        lineEdit_position->setGeometry(QRect(70, 90, 111, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(520, 40, 31, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 90, 41, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(370, 90, 61, 21));
        lineEdit_phone = new QLineEdit(groupBox);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(230, 90, 111, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 90, 31, 20));
        lineEdit_ip = new QLineEdit(groupBox);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(570, 90, 141, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 90, 41, 16));
        comboBox_marriage = new QComboBox(groupBox);
        comboBox_marriage->setObjectName(QString::fromUtf8("comboBox_marriage"));
        comboBox_marriage->setGeometry(QRect(430, 90, 61, 22));
        comboBox_marriage->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        comboBox_marriage->setEditable(false);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 140, 61, 16));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 140, 61, 20));
        lineEdit_address = new QLineEdit(groupBox);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));
        lineEdit_address->setGeometry(QRect(260, 140, 451, 21));
        lineEdit_workTime = new QLineEdit(groupBox);
        lineEdit_workTime->setObjectName(QString::fromUtf8("lineEdit_workTime"));
        lineEdit_workTime->setGeometry(QRect(80, 140, 81, 20));
        lineEdit_workTime->setReadOnly(true);
        toolButton_time = new QToolButton(groupBox);
        toolButton_time->setObjectName(QString::fromUtf8("toolButton_time"));
        toolButton_time->setGeometry(QRect(160, 140, 20, 20));
        toolButton_time->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_time->setArrowType(Qt::DownArrow);
        comboBox_department = new QComboBox(groupBox);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(570, 40, 141, 22));
        comboBox_department->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 182, 41, 20));
        comboBox_edu = new QComboBox(groupBox);
        comboBox_edu->setObjectName(QString::fromUtf8("comboBox_edu"));
        comboBox_edu->setGeometry(QRect(80, 180, 101, 22));
        comboBox_edu->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        comboBox_edu->setEditable(false);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(200, 180, 61, 20));
        lineEdit_idCard = new QLineEdit(groupBox);
        lineEdit_idCard->setObjectName(QString::fromUtf8("lineEdit_idCard"));
        lineEdit_idCard->setGeometry(QRect(260, 180, 231, 21));
        calendarWidget = new QCalendarWidget(groupBox);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(160, 20, 248, 197));
        calendarWidget->setGridVisible(true);
        pushButton = new QPushButton(YGSZ_New);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 280, 71, 23));
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
        toolButton_2 = new closeButton(YGSZ_New);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(760, 0, 13, 13));
        label_title = new QLabel(YGSZ_New);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(10, 0, 101, 16));

        retranslateUi(YGSZ_New);

        QMetaObject::connectSlotsByName(YGSZ_New);
    } // setupUi

    void retranslateUi(QWidget *YGSZ_New)
    {
        YGSZ_New->setWindowTitle(QApplication::translate("YGSZ_New", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("YGSZ_New", "\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("YGSZ_New", "\345\267\245  \345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("YGSZ_New", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("YGSZ_New", "\346\200\247\345\210\253\357\274\232", nullptr));
        comboBox_sex->setCurrentText(QString());
        lineEdit_position->setText(QString());
        label_4->setText(QApplication::translate("YGSZ_New", "\351\203\250\351\227\250\357\274\232", nullptr));
        label_5->setText(QApplication::translate("YGSZ_New", "\350\201\214  \344\275\215\357\274\232", nullptr));
        label_6->setText(QApplication::translate("YGSZ_New", "\345\251\232\345\247\273\347\212\266\345\206\265\357\274\232", nullptr));
        label_7->setText(QApplication::translate("YGSZ_New", "\346\211\213\346\234\272\357\274\232", nullptr));
        label_8->setText(QApplication::translate("YGSZ_New", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_9->setText(QApplication::translate("YGSZ_New", "\345\205\245\350\201\214\346\227\266\351\227\264\357\274\232", nullptr));
        label_10->setText(QApplication::translate("YGSZ_New", "\345\261\205\344\275\217\345\234\260\345\235\200\357\274\232", nullptr));
        toolButton_time->setText(QString());
        label_11->setText(QApplication::translate("YGSZ_New", "\345\255\246  \345\216\206\357\274\232", nullptr));
        comboBox_edu->setCurrentText(QString());
        label_12->setText(QApplication::translate("YGSZ_New", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("YGSZ_New", "\347\241\256 \345\256\232", nullptr));
        toolButton_2->setText(QString());
        label_title->setText(QApplication::translate("YGSZ_New", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YGSZ_New: public Ui_YGSZ_New {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YGSZ_NEW_H
