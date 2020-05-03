/********************************************************************************
** Form generated from reading UI file 'cgsq.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGSQ_H
#define UI_CGSQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_CGSQ
{
public:
    closeButton *toolButton;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QComboBox *comboBox_department;
    QLabel *label_4;
    QLineEdit *lineEdit_proName;
    QLabel *label_5;
    QLineEdit *lineEdit_dealTime;
    QLineEdit *lineEdit_expectTime;
    QToolButton *toolButton_expectTime;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *textEdit_recordMsg;
    QLabel *label_8;
    QComboBox *comboBox_num;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_leader1;
    QLabel *label_11;
    QComboBox *comboBox_dealResult1;
    QLabel *label_15;
    QTextEdit *textEdit_leaderAdvice1;
    QGroupBox *groupBox_allLeader;
    QComboBox *comboBox_leader1;
    QLabel *label_10;
    QComboBox *comboBox_leader3;
    QLabel *label_24;
    QLabel *label_18;
    QComboBox *comboBox_leader2;
    QGroupBox *groupBox_leader2;
    QLabel *label_22;
    QComboBox *comboBox_dealResult2;
    QLabel *label_23;
    QTextEdit *textEdit_leaderAdvice2;
    QGroupBox *groupBox_leader3;
    QLabel *label_25;
    QComboBox *comboBox_dealResult3;
    QLabel *label_26;
    QTextEdit *textEdit_leaderAdvice3;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QCalendarWidget *calendarWidget_expectTime;

    void setupUi(QWidget *CGSQ)
    {
        if (CGSQ->objectName().isEmpty())
            CGSQ->setObjectName(QString::fromUtf8("CGSQ"));
        CGSQ->resize(842, 932);
        toolButton = new closeButton(CGSQ);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(820, 0, 21, 20));
        label = new QLabel(CGSQ);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 54, 21));
        groupBox = new QGroupBox(CGSQ);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 821, 121));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 41, 21));
        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(60, 30, 61, 20));
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 30, 61, 21));
        comboBox_department = new QComboBox(groupBox);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(390, 30, 71, 22));
        comboBox_department->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 30, 51, 21));
        lineEdit_proName = new QLineEdit(groupBox);
        lineEdit_proName->setObjectName(QString::fromUtf8("lineEdit_proName"));
        lineEdit_proName->setGeometry(QRect(190, 30, 131, 20));
        lineEdit_proName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 30, 54, 21));
        lineEdit_dealTime = new QLineEdit(groupBox);
        lineEdit_dealTime->setObjectName(QString::fromUtf8("lineEdit_dealTime"));
        lineEdit_dealTime->setGeometry(QRect(530, 30, 131, 20));
        lineEdit_dealTime->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_expectTime = new QLineEdit(groupBox);
        lineEdit_expectTime->setObjectName(QString::fromUtf8("lineEdit_expectTime"));
        lineEdit_expectTime->setEnabled(false);
        lineEdit_expectTime->setGeometry(QRect(730, 30, 71, 20));
        lineEdit_expectTime->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        toolButton_expectTime = new QToolButton(groupBox);
        toolButton_expectTime->setObjectName(QString::fromUtf8("toolButton_expectTime"));
        toolButton_expectTime->setGeometry(QRect(800, 30, 21, 21));
        toolButton_expectTime->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        toolButton_expectTime->setArrowType(Qt::DownArrow);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(670, 31, 54, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(170, 80, 121, 16));
        textEdit_recordMsg = new QTextEdit(groupBox);
        textEdit_recordMsg->setObjectName(QString::fromUtf8("textEdit_recordMsg"));
        textEdit_recordMsg->setGeometry(QRect(300, 60, 511, 51));
        textEdit_recordMsg->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 80, 31, 21));
        comboBox_num = new QComboBox(groupBox);
        comboBox_num->setObjectName(QString::fromUtf8("comboBox_num"));
        comboBox_num->setGeometry(QRect(60, 80, 61, 22));
        comboBox_num->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        groupBox_2 = new QGroupBox(CGSQ);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 170, 821, 471));
        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 801, 441));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 234, 235);"));
        groupBox_leader1 = new QGroupBox(CGSQ);
        groupBox_leader1->setObjectName(QString::fromUtf8("groupBox_leader1"));
        groupBox_leader1->setGeometry(QRect(210, 640, 621, 81));
        label_11 = new QLabel(groupBox_leader1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 20, 61, 41));
        comboBox_dealResult1 = new QComboBox(groupBox_leader1);
        comboBox_dealResult1->setObjectName(QString::fromUtf8("comboBox_dealResult1"));
        comboBox_dealResult1->setGeometry(QRect(90, 30, 61, 22));
        comboBox_dealResult1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(groupBox_leader1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(160, 30, 71, 21));
        textEdit_leaderAdvice1 = new QTextEdit(groupBox_leader1);
        textEdit_leaderAdvice1->setObjectName(QString::fromUtf8("textEdit_leaderAdvice1"));
        textEdit_leaderAdvice1->setGeometry(QRect(230, 10, 381, 61));
        textEdit_leaderAdvice1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_allLeader = new QGroupBox(CGSQ);
        groupBox_allLeader->setObjectName(QString::fromUtf8("groupBox_allLeader"));
        groupBox_allLeader->setGeometry(QRect(10, 640, 191, 241));
        comboBox_leader1 = new QComboBox(groupBox_allLeader);
        comboBox_leader1->setObjectName(QString::fromUtf8("comboBox_leader1"));
        comboBox_leader1->setGeometry(QRect(90, 40, 81, 22));
        comboBox_leader1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader1->setEditable(true);
        label_10 = new QLabel(groupBox_allLeader);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 40, 61, 21));
        comboBox_leader3 = new QComboBox(groupBox_allLeader);
        comboBox_leader3->setObjectName(QString::fromUtf8("comboBox_leader3"));
        comboBox_leader3->setGeometry(QRect(90, 200, 81, 22));
        comboBox_leader3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader3->setEditable(true);
        label_24 = new QLabel(groupBox_allLeader);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 200, 71, 21));
        label_18 = new QLabel(groupBox_allLeader);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 120, 71, 21));
        comboBox_leader2 = new QComboBox(groupBox_allLeader);
        comboBox_leader2->setObjectName(QString::fromUtf8("comboBox_leader2"));
        comboBox_leader2->setGeometry(QRect(90, 120, 81, 22));
        comboBox_leader2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader2->setEditable(true);
        groupBox_leader2 = new QGroupBox(CGSQ);
        groupBox_leader2->setObjectName(QString::fromUtf8("groupBox_leader2"));
        groupBox_leader2->setGeometry(QRect(210, 720, 621, 81));
        label_22 = new QLabel(groupBox_leader2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 20, 61, 41));
        comboBox_dealResult2 = new QComboBox(groupBox_leader2);
        comboBox_dealResult2->setObjectName(QString::fromUtf8("comboBox_dealResult2"));
        comboBox_dealResult2->setGeometry(QRect(90, 30, 61, 22));
        comboBox_dealResult2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_23 = new QLabel(groupBox_leader2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(160, 30, 71, 21));
        textEdit_leaderAdvice2 = new QTextEdit(groupBox_leader2);
        textEdit_leaderAdvice2->setObjectName(QString::fromUtf8("textEdit_leaderAdvice2"));
        textEdit_leaderAdvice2->setGeometry(QRect(230, 10, 381, 61));
        textEdit_leaderAdvice2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_leader3 = new QGroupBox(CGSQ);
        groupBox_leader3->setObjectName(QString::fromUtf8("groupBox_leader3"));
        groupBox_leader3->setGeometry(QRect(210, 800, 621, 81));
        label_25 = new QLabel(groupBox_leader3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(30, 20, 61, 41));
        comboBox_dealResult3 = new QComboBox(groupBox_leader3);
        comboBox_dealResult3->setObjectName(QString::fromUtf8("comboBox_dealResult3"));
        comboBox_dealResult3->setGeometry(QRect(90, 30, 61, 22));
        comboBox_dealResult3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(groupBox_leader3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(160, 30, 71, 21));
        textEdit_leaderAdvice3 = new QTextEdit(groupBox_leader3);
        textEdit_leaderAdvice3->setObjectName(QString::fromUtf8("textEdit_leaderAdvice3"));
        textEdit_leaderAdvice3->setGeometry(QRect(230, 10, 381, 61));
        textEdit_leaderAdvice3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_ok = new QPushButton(CGSQ);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(170, 890, 91, 23));
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
""));
        pushButton_cancel = new QPushButton(CGSQ);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(500, 890, 91, 23));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_cancel\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_cancel:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_cancel:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        calendarWidget_expectTime = new QCalendarWidget(CGSQ);
        calendarWidget_expectTime->setObjectName(QString::fromUtf8("calendarWidget_expectTime"));
        calendarWidget_expectTime->setGeometry(QRect(590, 20, 248, 197));

        retranslateUi(CGSQ);

        QMetaObject::connectSlotsByName(CGSQ);
    } // setupUi

    void retranslateUi(QWidget *CGSQ)
    {
        CGSQ->setWindowTitle(QApplication::translate("CGSQ", "Form", nullptr));
        toolButton->setText(QString());
        label->setText(QApplication::translate("CGSQ", "\351\207\207\350\264\255\347\224\263\350\257\267", nullptr));
        groupBox->setTitle(QApplication::translate("CGSQ", "\347\224\263\350\257\267\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("CGSQ", "\347\224\263\350\257\267\344\272\272\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CGSQ", "\347\224\263\350\257\267\351\203\250\351\227\250\357\274\232", nullptr));
        label_4->setText(QApplication::translate("CGSQ", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", nullptr));
        label_5->setText(QApplication::translate("CGSQ", "\347\224\263\350\257\267\346\227\245\346\234\237\357\274\232", nullptr));
        toolButton_expectTime->setText(QString());
        label_6->setText(QApplication::translate("CGSQ", "\350\246\201\346\261\202\346\234\237\351\231\220\357\274\232", nullptr));
        label_7->setText(QApplication::translate("CGSQ", "\345\205\266\344\273\226\345\206\205\345\256\271\346\217\217\350\277\260(\345\244\207\346\263\250)\357\274\232", nullptr));
        label_8->setText(QApplication::translate("CGSQ", "\345\245\227\346\225\260\357\274\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("CGSQ", "\347\224\263\350\264\255\344\272\247\345\223\201\346\217\217\350\277\260", nullptr));
        groupBox_leader1->setTitle(QApplication::translate("CGSQ", "\347\273\204\351\225\277\345\244\204\347\220\206", nullptr));
        label_11->setText(QApplication::translate("CGSQ", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_15->setText(QApplication::translate("CGSQ", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox_allLeader->setTitle(QApplication::translate("CGSQ", "\345\256\241\346\240\270\344\272\272", nullptr));
        label_10->setText(QApplication::translate("CGSQ", "\347\273\204\351\225\277(*)\357\274\232", nullptr));
        label_24->setText(QApplication::translate("CGSQ", "\346\200\273\347\273\217\347\220\206(*)\357\274\232", nullptr));
        label_18->setText(QApplication::translate("CGSQ", "\351\203\250\351\227\250\351\242\206\345\257\274(*)\357\274\232", nullptr));
        groupBox_leader2->setTitle(QApplication::translate("CGSQ", "\351\203\250\351\227\250\351\242\206\345\257\274\345\244\204\347\220\206", nullptr));
        label_22->setText(QApplication::translate("CGSQ", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_23->setText(QApplication::translate("CGSQ", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox_leader3->setTitle(QApplication::translate("CGSQ", "\346\200\273\347\273\217\347\220\206\345\244\204\347\220\206", nullptr));
        label_25->setText(QApplication::translate("CGSQ", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_26->setText(QApplication::translate("CGSQ", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        pushButton_ok->setText(QApplication::translate("CGSQ", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QApplication::translate("CGSQ", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGSQ: public Ui_CGSQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGSQ_H
