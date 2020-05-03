/********************************************************************************
** Form generated from reading UI file 'jiaban.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JIABAN_H
#define UI_JIABAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <closebutton.h>

QT_BEGIN_NAMESPACE

class Ui_Jiaban
{
public:
    closeButton *toolButton;
    QGroupBox *groupBox_jb;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_jbTime1;
    QToolButton *toolButton_2;
    QLabel *label_5;
    QComboBox *comboBox_timeArea;
    QLabel *label_6;
    QTimeEdit *timeEdit;
    QToolButton *toolButton_3;
    QTimeEdit *timeEdit_2;
    QLineEdit *lineEdit_jbTime2;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit_jbReason;
    QLabel *label_9;
    QTextEdit *textEdit_jbContent;
    QLineEdit *lineEdit_dealTime;
    QCalendarWidget *calendarWidget_jbStartTime;
    QLabel *label_10;
    QComboBox *comboBox_leader1;
    QComboBox *comboBox_department;
    QLabel *label_12;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QLabel *label_13;
    QCheckBox *checkBox_2;
    QLabel *label_14;
    QLineEdit *lineEdit_jbFoodMoney;
    QCalendarWidget *calendarWidget_jbEndTime;
    QGroupBox *groupBox_leader;
    QLabel *label_11;
    QComboBox *comboBox_dealResult;
    QLabel *label_15;
    QTextEdit *textEdit_leaderAdvice;
    QPushButton *pushButton;
    QPushButton *pushButton_cancel;
    QLabel *label;

    void setupUi(QWidget *Jiaban)
    {
        if (Jiaban->objectName().isEmpty())
            Jiaban->setObjectName(QString::fromUtf8("Jiaban"));
        Jiaban->resize(874, 650);
        toolButton = new closeButton(Jiaban);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(850, 0, 17, 17));
        toolButton->setMaximumSize(QSize(17, 17));
        groupBox_jb = new QGroupBox(Jiaban);
        groupBox_jb->setObjectName(QString::fromUtf8("groupBox_jb"));
        groupBox_jb->setGeometry(QRect(10, 50, 851, 551));
        groupBox_jb->setCheckable(false);
        label_2 = new QLabel(groupBox_jb);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(53, 30, 61, 21));
        lineEdit_name = new QLineEdit(groupBox_jb);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(120, 30, 113, 20));
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox_jb);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 30, 61, 21));
        label_4 = new QLabel(groupBox_jb);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 32, 54, 20));
        lineEdit_jbTime1 = new QLineEdit(groupBox_jb);
        lineEdit_jbTime1->setObjectName(QString::fromUtf8("lineEdit_jbTime1"));
        lineEdit_jbTime1->setGeometry(QRect(400, 80, 81, 20));
        lineEdit_jbTime1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_2 = new QToolButton(groupBox_jb);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(480, 80, 21, 20));
        toolButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_2->setArrowType(Qt::DownArrow);
        label_5 = new QLabel(groupBox_jb);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 80, 61, 21));
        comboBox_timeArea = new QComboBox(groupBox_jb);
        comboBox_timeArea->setObjectName(QString::fromUtf8("comboBox_timeArea"));
        comboBox_timeArea->setGeometry(QRect(120, 80, 111, 21));
        QFont font;
        font.setPointSize(9);
        comboBox_timeArea->setFont(font);
        comboBox_timeArea->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBox_jb);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 80, 61, 21));
        timeEdit = new QTimeEdit(groupBox_jb);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(500, 80, 101, 22));
        QFont font1;
        font1.setPointSize(11);
        timeEdit->setFont(font1);
        timeEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_3 = new QToolButton(groupBox_jb);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(710, 80, 21, 20));
        toolButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_3->setArrowType(Qt::DownArrow);
        timeEdit_2 = new QTimeEdit(groupBox_jb);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(730, 80, 91, 22));
        QFont font2;
        font2.setPointSize(12);
        timeEdit_2->setFont(font2);
        timeEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_jbTime2 = new QLineEdit(groupBox_jb);
        lineEdit_jbTime2->setObjectName(QString::fromUtf8("lineEdit_jbTime2"));
        lineEdit_jbTime2->setGeometry(QRect(630, 80, 81, 20));
        lineEdit_jbTime2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(groupBox_jb);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(610, 80, 21, 21));
        label_8 = new QLabel(groupBox_jb);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 170, 71, 16));
        textEdit_jbReason = new QTextEdit(groupBox_jb);
        textEdit_jbReason->setObjectName(QString::fromUtf8("textEdit_jbReason"));
        textEdit_jbReason->setGeometry(QRect(110, 130, 731, 91));
        textEdit_jbReason->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(groupBox_jb);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 270, 54, 12));
        textEdit_jbContent = new QTextEdit(groupBox_jb);
        textEdit_jbContent->setObjectName(QString::fromUtf8("textEdit_jbContent"));
        textEdit_jbContent->setGeometry(QRect(110, 240, 731, 91));
        textEdit_jbContent->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_dealTime = new QLineEdit(groupBox_jb);
        lineEdit_dealTime->setObjectName(QString::fromUtf8("lineEdit_dealTime"));
        lineEdit_dealTime->setEnabled(false);
        lineEdit_dealTime->setGeometry(QRect(630, 30, 121, 20));
        lineEdit_dealTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        calendarWidget_jbStartTime = new QCalendarWidget(groupBox_jb);
        calendarWidget_jbStartTime->setObjectName(QString::fromUtf8("calendarWidget_jbStartTime"));
        calendarWidget_jbStartTime->setGeometry(QRect(330, 70, 248, 197));
        label_10 = new QLabel(groupBox_jb);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 470, 71, 21));
        comboBox_leader1 = new QComboBox(groupBox_jb);
        comboBox_leader1->setObjectName(QString::fromUtf8("comboBox_leader1"));
        comboBox_leader1->setGeometry(QRect(110, 470, 81, 22));
        comboBox_leader1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader1->setEditable(true);
        comboBox_department = new QComboBox(groupBox_jb);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(400, 30, 101, 22));
        comboBox_department->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_12 = new QLabel(groupBox_jb);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(50, 360, 71, 16));
        groupBox_2 = new QGroupBox(groupBox_jb);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(110, 350, 731, 41));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 10, 51, 21));
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(250, 10, 51, 21));
        checkBox_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(320, 10, 41, 21));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(160, 10, 51, 21));
        checkBox_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(430, 10, 21, 20));
        lineEdit_jbFoodMoney = new QLineEdit(groupBox_2);
        lineEdit_jbFoodMoney->setObjectName(QString::fromUtf8("lineEdit_jbFoodMoney"));
        lineEdit_jbFoodMoney->setGeometry(QRect(362, 10, 61, 20));
        lineEdit_jbFoodMoney->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        calendarWidget_jbEndTime = new QCalendarWidget(groupBox_jb);
        calendarWidget_jbEndTime->setObjectName(QString::fromUtf8("calendarWidget_jbEndTime"));
        calendarWidget_jbEndTime->setGeometry(QRect(580, 70, 248, 197));
        groupBox_leader = new QGroupBox(groupBox_jb);
        groupBox_leader->setObjectName(QString::fromUtf8("groupBox_leader"));
        groupBox_leader->setGeometry(QRect(210, 460, 641, 131));
        label_11 = new QLabel(groupBox_leader);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 55, 61, 31));
        comboBox_dealResult = new QComboBox(groupBox_leader);
        comboBox_dealResult->setObjectName(QString::fromUtf8("comboBox_dealResult"));
        comboBox_dealResult->setGeometry(QRect(70, 60, 71, 22));
        comboBox_dealResult->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(groupBox_leader);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(150, 60, 71, 21));
        textEdit_leaderAdvice = new QTextEdit(groupBox_leader);
        textEdit_leaderAdvice->setObjectName(QString::fromUtf8("textEdit_leaderAdvice"));
        textEdit_leaderAdvice->setGeometry(QRect(220, 20, 411, 101));
        textEdit_leaderAdvice->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(Jiaban);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 610, 71, 23));
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
        pushButton_cancel = new QPushButton(Jiaban);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(590, 610, 71, 23));
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
        label = new QLabel(Jiaban);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 81, 16));
        QFont font3;
        font3.setPointSize(10);
        label->setFont(font3);
        toolButton->raise();
        pushButton->raise();
        groupBox_jb->raise();
        pushButton_cancel->raise();
        label->raise();

        retranslateUi(Jiaban);

        QMetaObject::connectSlotsByName(Jiaban);
    } // setupUi

    void retranslateUi(QWidget *Jiaban)
    {
        Jiaban->setWindowTitle(QApplication::translate("Jiaban", "Form", nullptr));
        toolButton->setText(QString());
        groupBox_jb->setTitle(QApplication::translate("Jiaban", "\345\212\240\347\217\255\347\224\263\350\257\267", nullptr));
        label_2->setText(QApplication::translate("Jiaban", "\345\247\223    \345\220\215\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Jiaban", "\351\203\250    \351\227\250\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Jiaban", "\345\241\253\350\241\250\346\227\245\346\234\237\357\274\232", nullptr));
        toolButton_2->setText(QString());
        label_5->setText(QApplication::translate("Jiaban", "\345\212\240\347\217\255\346\227\266\346\256\265\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Jiaban", "\345\212\240\347\217\255\346\227\266\351\227\264\357\274\232", nullptr));
        toolButton_3->setText(QString());
        label_7->setText(QApplication::translate("Jiaban", "\345\210\260", nullptr));
        label_8->setText(QApplication::translate("Jiaban", "\345\212\240\347\217\255\345\206\205\345\256\271\357\274\232", nullptr));
        label_9->setText(QApplication::translate("Jiaban", "\345\212\240\347\217\255\345\206\205\345\256\271\357\274\232", nullptr));
        label_10->setText(QApplication::translate("Jiaban", "\344\270\212\347\272\247\350\264\237\350\264\243\344\272\272\357\274\232", nullptr));
        label_12->setText(QApplication::translate("Jiaban", "\345\212\240\347\217\255\351\244\220\350\264\271\357\274\232", nullptr));
        groupBox_2->setTitle(QString());
        checkBox->setText(QApplication::translate("Jiaban", "\346\227\251\351\244\220", nullptr));
        checkBox_3->setText(QApplication::translate("Jiaban", "\346\231\232\351\244\220", nullptr));
        label_13->setText(QApplication::translate("Jiaban", "\345\205\261\350\256\241\357\274\232", nullptr));
        checkBox_2->setText(QApplication::translate("Jiaban", "\345\215\210\351\244\220", nullptr));
        label_14->setText(QApplication::translate("Jiaban", "\345\205\203", nullptr));
        groupBox_leader->setTitle(QApplication::translate("Jiaban", "\350\264\237\350\264\243\344\272\272\345\256\241\346\240\270", nullptr));
        label_11->setText(QApplication::translate("Jiaban", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_15->setText(QApplication::translate("Jiaban", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Jiaban", "\346\217\220\344\272\244", nullptr));
        pushButton_cancel->setText(QApplication::translate("Jiaban", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("Jiaban", "\345\212\240\347\217\255\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Jiaban: public Ui_Jiaban {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JIABAN_H
