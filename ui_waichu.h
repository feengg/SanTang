/********************************************************************************
** Form generated from reading UI file 'waichu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAICHU_H
#define UI_WAICHU_H

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

QT_BEGIN_NAMESPACE

class Ui_WaiChu
{
public:
    QPushButton *pushButton_close;
    QGroupBox *groupBox_allLeader;
    QComboBox *comboBox_leader;
    QLabel *label_13;
    QLabel *label_27;
    QComboBox *comboBox_clerk;
    QLabel *label;
    QPushButton *pButtonOk;
    QPushButton *pushButton_min;
    QPushButton *pButtonCancel;
    QGroupBox *groupBox_leader;
    QLabel *label_12;
    QComboBox *comboBox_leaderDeal;
    QLabel *label_15;
    QTextEdit *textEdit_leaderAdvice;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QComboBox *comboBox_department;
    QLabel *label_6;
    QComboBox *comboBox_position;
    QLabel *label_7;
    QLabel *label_8;
    QTimeEdit *timeEdit_startTime;
    QTimeEdit *timeEdit_endTime;
    QToolButton *toolButton_startDay;
    QLineEdit *lineEdit_startDay;
    QLineEdit *lineEdit_endDay;
    QLabel *label_9;
    QLineEdit *lineEdit_toWhere;
    QLabel *label_4;
    QLineEdit *lineEdit_dealTime;
    QToolButton *toolButton_endDay;
    QLabel *label_5;
    QLineEdit *lineEdit_with;
    QLabel *label_11;
    QLineEdit *lineEdit_reason;
    QToolButton *toolButton_realDay;
    QTimeEdit *timeEdit_realTime;
    QLabel *label_10;
    QLineEdit *lineEdit_realDay;
    QLabel *label_14;
    QCheckBox *checkBox_workOn;
    QCheckBox *checkBox_workOff;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox_clerk;
    QLabel *label_25;
    QComboBox *comboBox_clerkDeal;
    QLabel *label_26;
    QTextEdit *textEdit_clerkAdvice;

    void setupUi(QWidget *WaiChu)
    {
        if (WaiChu->objectName().isEmpty())
            WaiChu->setObjectName(QString::fromUtf8("WaiChu"));
        WaiChu->resize(808, 514);
        pushButton_close = new QPushButton(WaiChu);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(780, 0, 24, 16));
        pushButton_close->setMinimumSize(QSize(0, 16));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/close_first.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	\n"
"	background-image: url(:/images/close_after.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}"));
        groupBox_allLeader = new QGroupBox(WaiChu);
        groupBox_allLeader->setObjectName(QString::fromUtf8("groupBox_allLeader"));
        groupBox_allLeader->setGeometry(QRect(10, 260, 181, 201));
        groupBox_allLeader->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        comboBox_leader = new QComboBox(groupBox_allLeader);
        comboBox_leader->setObjectName(QString::fromUtf8("comboBox_leader"));
        comboBox_leader->setGeometry(QRect(80, 50, 81, 22));
        comboBox_leader->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader->setEditable(true);
        label_13 = new QLabel(groupBox_allLeader);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 50, 61, 21));
        label_27 = new QLabel(groupBox_allLeader);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(30, 140, 51, 21));
        comboBox_clerk = new QComboBox(groupBox_allLeader);
        comboBox_clerk->setObjectName(QString::fromUtf8("comboBox_clerk"));
        comboBox_clerk->setGeometry(QRect(80, 140, 81, 22));
        comboBox_clerk->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        comboBox_clerk->setEditable(true);
        label = new QLabel(WaiChu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 71, 16));
        pButtonOk = new QPushButton(WaiChu);
        pButtonOk->setObjectName(QString::fromUtf8("pButtonOk"));
        pButtonOk->setGeometry(QRect(160, 480, 91, 23));
        pButtonOk->setStyleSheet(QString::fromUtf8("QPushButton#pButtonOk\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pButtonOk:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pButtonOk:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        pushButton_min = new QPushButton(WaiChu);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(760, 0, 24, 16));
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
        pButtonCancel = new QPushButton(WaiChu);
        pButtonCancel->setObjectName(QString::fromUtf8("pButtonCancel"));
        pButtonCancel->setGeometry(QRect(500, 480, 81, 23));
        pButtonCancel->setStyleSheet(QString::fromUtf8("QPushButton#pButtonCancel\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pButtonCancel:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pButtonCancel:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        groupBox_leader = new QGroupBox(WaiChu);
        groupBox_leader->setObjectName(QString::fromUtf8("groupBox_leader"));
        groupBox_leader->setGeometry(QRect(200, 260, 601, 91));
        groupBox_leader->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_12 = new QLabel(groupBox_leader);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 30, 61, 41));
        comboBox_leaderDeal = new QComboBox(groupBox_leader);
        comboBox_leaderDeal->setObjectName(QString::fromUtf8("comboBox_leaderDeal"));
        comboBox_leaderDeal->setGeometry(QRect(90, 40, 71, 22));
        comboBox_leaderDeal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(groupBox_leader);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(170, 40, 71, 21));
        textEdit_leaderAdvice = new QTextEdit(groupBox_leader);
        textEdit_leaderAdvice->setObjectName(QString::fromUtf8("textEdit_leaderAdvice"));
        textEdit_leaderAdvice->setGeometry(QRect(240, 20, 351, 61));
        textEdit_leaderAdvice->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        groupBox = new QGroupBox(WaiChu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 791, 221));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 30, 54, 21));
        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(82, 30, 101, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 30, 41, 21));
        comboBox_department = new QComboBox(groupBox);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(240, 30, 111, 22));
        comboBox_department->setEditable(true);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(360, 30, 41, 21));
        comboBox_position = new QComboBox(groupBox);
        comboBox_position->setObjectName(QString::fromUtf8("comboBox_position"));
        comboBox_position->setGeometry(QRect(400, 30, 111, 22));
        comboBox_position->setEditable(true);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 80, 71, 21));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 80, 91, 21));
        timeEdit_startTime = new QTimeEdit(groupBox);
        timeEdit_startTime->setObjectName(QString::fromUtf8("timeEdit_startTime"));
        timeEdit_startTime->setGeometry(QRect(170, 80, 91, 22));
        QFont font;
        font.setPointSize(11);
        timeEdit_startTime->setFont(font);
        timeEdit_startTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        timeEdit_endTime = new QTimeEdit(groupBox);
        timeEdit_endTime->setObjectName(QString::fromUtf8("timeEdit_endTime"));
        timeEdit_endTime->setGeometry(QRect(430, 80, 91, 22));
        QFont font1;
        font1.setPointSize(12);
        timeEdit_endTime->setFont(font1);
        timeEdit_endTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_startDay = new QToolButton(groupBox);
        toolButton_startDay->setObjectName(QString::fromUtf8("toolButton_startDay"));
        toolButton_startDay->setGeometry(QRect(150, 80, 21, 20));
        toolButton_startDay->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_startDay->setArrowType(Qt::DownArrow);
        lineEdit_startDay = new QLineEdit(groupBox);
        lineEdit_startDay->setObjectName(QString::fromUtf8("lineEdit_startDay"));
        lineEdit_startDay->setGeometry(QRect(80, 80, 71, 20));
        lineEdit_startDay->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_endDay = new QLineEdit(groupBox);
        lineEdit_endDay->setObjectName(QString::fromUtf8("lineEdit_endDay"));
        lineEdit_endDay->setGeometry(QRect(340, 80, 71, 20));
        lineEdit_endDay->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 130, 81, 20));
        lineEdit_toWhere = new QLineEdit(groupBox);
        lineEdit_toWhere->setObjectName(QString::fromUtf8("lineEdit_toWhere"));
        lineEdit_toWhere->setGeometry(QRect(80, 130, 151, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(540, 30, 54, 21));
        lineEdit_dealTime = new QLineEdit(groupBox);
        lineEdit_dealTime->setObjectName(QString::fromUtf8("lineEdit_dealTime"));
        lineEdit_dealTime->setGeometry(QRect(610, 30, 171, 20));
        toolButton_endDay = new QToolButton(groupBox);
        toolButton_endDay->setObjectName(QString::fromUtf8("toolButton_endDay"));
        toolButton_endDay->setGeometry(QRect(410, 80, 21, 20));
        toolButton_endDay->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_endDay->setArrowType(Qt::DownArrow);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(500, 130, 54, 21));
        lineEdit_with = new QLineEdit(groupBox);
        lineEdit_with->setObjectName(QString::fromUtf8("lineEdit_with"));
        lineEdit_with->setGeometry(QRect(560, 130, 221, 20));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 180, 71, 21));
        lineEdit_reason = new QLineEdit(groupBox);
        lineEdit_reason->setObjectName(QString::fromUtf8("lineEdit_reason"));
        lineEdit_reason->setGeometry(QRect(80, 180, 701, 25));
        toolButton_realDay = new QToolButton(groupBox);
        toolButton_realDay->setObjectName(QString::fromUtf8("toolButton_realDay"));
        toolButton_realDay->setGeometry(QRect(670, 80, 21, 20));
        toolButton_realDay->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_realDay->setArrowType(Qt::DownArrow);
        timeEdit_realTime = new QTimeEdit(groupBox);
        timeEdit_realTime->setObjectName(QString::fromUtf8("timeEdit_realTime"));
        timeEdit_realTime->setGeometry(QRect(690, 80, 91, 22));
        timeEdit_realTime->setFont(font1);
        timeEdit_realTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(520, 80, 91, 21));
        lineEdit_realDay = new QLineEdit(groupBox);
        lineEdit_realDay->setObjectName(QString::fromUtf8("lineEdit_realDay"));
        lineEdit_realDay->setGeometry(QRect(600, 80, 71, 20));
        lineEdit_realDay->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(250, 130, 61, 21));
        checkBox_workOn = new QCheckBox(groupBox);
        checkBox_workOn->setObjectName(QString::fromUtf8("checkBox_workOn"));
        checkBox_workOn->setGeometry(QRect(320, 130, 81, 21));
        checkBox_workOff = new QCheckBox(groupBox);
        checkBox_workOff->setObjectName(QString::fromUtf8("checkBox_workOff"));
        checkBox_workOff->setGeometry(QRect(410, 130, 81, 21));
        calendarWidget = new QCalendarWidget(groupBox);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(270, 20, 248, 197));
        groupBox_clerk = new QGroupBox(WaiChu);
        groupBox_clerk->setObjectName(QString::fromUtf8("groupBox_clerk"));
        groupBox_clerk->setGeometry(QRect(200, 370, 601, 91));
        groupBox_clerk->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_25 = new QLabel(groupBox_clerk);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(30, 30, 61, 41));
        comboBox_clerkDeal = new QComboBox(groupBox_clerk);
        comboBox_clerkDeal->setObjectName(QString::fromUtf8("comboBox_clerkDeal"));
        comboBox_clerkDeal->setGeometry(QRect(90, 40, 71, 22));
        comboBox_clerkDeal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(groupBox_clerk);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(170, 40, 71, 21));
        textEdit_clerkAdvice = new QTextEdit(groupBox_clerk);
        textEdit_clerkAdvice->setObjectName(QString::fromUtf8("textEdit_clerkAdvice"));
        textEdit_clerkAdvice->setGeometry(QRect(240, 20, 351, 61));
        textEdit_clerkAdvice->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        retranslateUi(WaiChu);

        QMetaObject::connectSlotsByName(WaiChu);
    } // setupUi

    void retranslateUi(QWidget *WaiChu)
    {
        WaiChu->setWindowTitle(QApplication::translate("WaiChu", "Form", nullptr));
        pushButton_close->setText(QString());
        groupBox_allLeader->setTitle(QApplication::translate("WaiChu", "\345\256\241\346\240\270\344\272\272", nullptr));
        label_13->setText(QApplication::translate("WaiChu", "\351\203\250\351\227\250\351\242\206\345\257\274\357\274\232", nullptr));
        label_27->setText(QApplication::translate("WaiChu", "\350\200\203\345\213\244\345\221\230\357\274\232", nullptr));
        label->setText(QApplication::translate("WaiChu", "\345\244\226\345\207\272\347\224\265\345\255\220\346\265\201", nullptr));
        pButtonOk->setText(QApplication::translate("WaiChu", "\347\241\256\345\256\232", nullptr));
        pushButton_min->setText(QString());
        pButtonCancel->setText(QApplication::translate("WaiChu", "\345\217\226\346\266\210", nullptr));
        groupBox_leader->setTitle(QApplication::translate("WaiChu", "\351\203\250\351\227\250\346\204\217\350\247\201", nullptr));
        label_12->setText(QApplication::translate("WaiChu", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_15->setText(QApplication::translate("WaiChu", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("WaiChu", "\347\224\263\350\257\267\344\272\272\357\274\232", nullptr));
        label_3->setText(QApplication::translate("WaiChu", "\351\203\250\351\227\250\357\274\232", nullptr));
        label_6->setText(QApplication::translate("WaiChu", "\350\201\214\344\275\215\357\274\232", nullptr));
        label_7->setText(QApplication::translate("WaiChu", "\345\244\226\345\207\272\346\227\266\351\227\264(*)\357\274\232", nullptr));
        label_8->setText(QApplication::translate("WaiChu", "\351\242\204\350\256\241\350\277\224\346\227\266\351\227\264(*)\357\274\232", nullptr));
        toolButton_startDay->setText(QString());
        label_9->setText(QApplication::translate("WaiChu", "\345\244\226\345\207\272\345\234\260\347\202\271(*)\357\274\232", nullptr));
        label_4->setText(QApplication::translate("WaiChu", "\347\224\263\350\257\267\346\227\266\351\227\264\357\274\232", nullptr));
        lineEdit_dealTime->setText(QString());
        toolButton_endDay->setText(QString());
        label_5->setText(QApplication::translate("WaiChu", "\351\232\217\350\241\214\344\272\272\345\221\230\357\274\232", nullptr));
        label_11->setText(QApplication::translate("WaiChu", "\345\244\226\345\207\272\344\272\213\347\224\261(*)\357\274\232", nullptr));
        toolButton_realDay->setText(QString());
        label_10->setText(QApplication::translate("WaiChu", "\345\256\236\351\231\205\350\277\224\345\233\236\346\227\266\351\227\264\357\274\232", nullptr));
        lineEdit_realDay->setText(QString());
        label_14->setText(QApplication::translate("WaiChu", "\346\211\223\345\215\241\346\203\205\345\206\265\357\274\232", nullptr));
        checkBox_workOn->setText(QApplication::translate("WaiChu", "\344\270\212\347\217\255\346\234\252\346\211\223\345\215\241", nullptr));
        checkBox_workOff->setText(QApplication::translate("WaiChu", "\344\270\213\347\217\255\346\234\252\346\211\223\345\215\241", nullptr));
        groupBox_clerk->setTitle(QApplication::translate("WaiChu", "\350\200\203\345\213\244\345\221\230\346\204\217\350\247\201", nullptr));
        label_25->setText(QApplication::translate("WaiChu", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_26->setText(QApplication::translate("WaiChu", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaiChu: public Ui_WaiChu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAICHU_H
