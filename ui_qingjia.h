/********************************************************************************
** Form generated from reading UI file 'qingjia.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QINGJIA_H
#define UI_QINGJIA_H

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

class Ui_QingJia
{
public:
    QGroupBox *groupBox_qj;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_qjStartTime;
    QToolButton *toolButton_qjStart;
    QLabel *label_5;
    QComboBox *comboBox_position;
    QLabel *label_6;
    QTimeEdit *timeEdit;
    QToolButton *toolButton_qjEnd;
    QTimeEdit *timeEdit_2;
    QLineEdit *lineEdit_qjEndTime;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit_qjReason;
    QLineEdit *lineEdit_dealTime;
    QCalendarWidget *calendarWidget_qjStartTime;
    QComboBox *comboBox_department;
    QGroupBox *groupBox_qjType;
    QLabel *label_13;
    QLineEdit *lineEdit_qjDayNum;
    QCheckBox *checkBox_sj;
    QCheckBox *checkBox_bj;
    QCheckBox *checkBox_shijia;
    QCheckBox *checkBox_hx;
    QCheckBox *checkBox_other;
    QComboBox *comboBox_dw;
    QCalendarWidget *calendarWidget_qjEndTime;
    QLabel *label_12;
    QTextEdit *textEdit_qjRecord;
    QLabel *label_9;
    QGroupBox *groupBox_leader1;
    QLabel *label_11;
    QComboBox *comboBox_dealResult1;
    QLabel *label_15;
    QTextEdit *textEdit_leaderAdvice1;
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
    QPushButton *pButtonOk;
    QPushButton *pButtonCancel;
    closeButton *toolButton_close;
    QGroupBox *groupBox_allLeader;
    QComboBox *comboBox_leader1;
    QLabel *label_10;
    QComboBox *comboBox_leader2;
    QLabel *label_24;
    QLabel *label_27;
    QComboBox *comboBox_leader3;
    QLabel *label;

    void setupUi(QWidget *QingJia)
    {
        if (QingJia->objectName().isEmpty())
            QingJia->setObjectName(QString::fromUtf8("QingJia"));
        QingJia->resize(874, 702);
        groupBox_qj = new QGroupBox(QingJia);
        groupBox_qj->setObjectName(QString::fromUtf8("groupBox_qj"));
        groupBox_qj->setGeometry(QRect(10, 40, 851, 311));
        groupBox_qj->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_qj->setCheckable(false);
        label_2 = new QLabel(groupBox_qj);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(53, 30, 61, 21));
        lineEdit_name = new QLineEdit(groupBox_qj);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(120, 30, 151, 20));
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox_qj);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 30, 61, 21));
        label_4 = new QLabel(groupBox_qj);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 20, 54, 41));
        lineEdit_qjStartTime = new QLineEdit(groupBox_qj);
        lineEdit_qjStartTime->setObjectName(QString::fromUtf8("lineEdit_qjStartTime"));
        lineEdit_qjStartTime->setEnabled(false);
        lineEdit_qjStartTime->setGeometry(QRect(400, 80, 81, 20));
        lineEdit_qjStartTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_qjStart = new QToolButton(groupBox_qj);
        toolButton_qjStart->setObjectName(QString::fromUtf8("toolButton_qjStart"));
        toolButton_qjStart->setGeometry(QRect(480, 80, 21, 20));
        toolButton_qjStart->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_qjStart->setArrowType(Qt::DownArrow);
        label_5 = new QLabel(groupBox_qj);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 80, 71, 21));
        comboBox_position = new QComboBox(groupBox_qj);
        comboBox_position->setObjectName(QString::fromUtf8("comboBox_position"));
        comboBox_position->setGeometry(QRect(120, 80, 151, 21));
        QFont font;
        font.setPointSize(9);
        comboBox_position->setFont(font);
        comboBox_position->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBox_qj);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 80, 61, 21));
        timeEdit = new QTimeEdit(groupBox_qj);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(500, 80, 101, 22));
        QFont font1;
        font1.setPointSize(11);
        timeEdit->setFont(font1);
        timeEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_qjEnd = new QToolButton(groupBox_qj);
        toolButton_qjEnd->setObjectName(QString::fromUtf8("toolButton_qjEnd"));
        toolButton_qjEnd->setGeometry(QRect(710, 80, 21, 20));
        toolButton_qjEnd->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_qjEnd->setArrowType(Qt::DownArrow);
        timeEdit_2 = new QTimeEdit(groupBox_qj);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(730, 80, 101, 22));
        QFont font2;
        font2.setPointSize(12);
        timeEdit_2->setFont(font2);
        timeEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_qjEndTime = new QLineEdit(groupBox_qj);
        lineEdit_qjEndTime->setObjectName(QString::fromUtf8("lineEdit_qjEndTime"));
        lineEdit_qjEndTime->setEnabled(false);
        lineEdit_qjEndTime->setGeometry(QRect(630, 80, 81, 20));
        lineEdit_qjEndTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_7 = new QLabel(groupBox_qj);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(610, 80, 21, 21));
        label_8 = new QLabel(groupBox_qj);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(33, 210, 71, 20));
        textEdit_qjReason = new QTextEdit(groupBox_qj);
        textEdit_qjReason->setObjectName(QString::fromUtf8("textEdit_qjReason"));
        textEdit_qjReason->setGeometry(QRect(110, 190, 731, 51));
        textEdit_qjReason->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_dealTime = new QLineEdit(groupBox_qj);
        lineEdit_dealTime->setObjectName(QString::fromUtf8("lineEdit_dealTime"));
        lineEdit_dealTime->setEnabled(false);
        lineEdit_dealTime->setGeometry(QRect(630, 30, 121, 20));
        lineEdit_dealTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        calendarWidget_qjStartTime = new QCalendarWidget(groupBox_qj);
        calendarWidget_qjStartTime->setObjectName(QString::fromUtf8("calendarWidget_qjStartTime"));
        calendarWidget_qjStartTime->setGeometry(QRect(400, 80, 248, 197));
        comboBox_department = new QComboBox(groupBox_qj);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(400, 30, 101, 22));
        comboBox_department->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        groupBox_qjType = new QGroupBox(groupBox_qj);
        groupBox_qjType->setObjectName(QString::fromUtf8("groupBox_qjType"));
        groupBox_qjType->setGeometry(QRect(110, 130, 741, 41));
        groupBox_qjType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_13 = new QLabel(groupBox_qjType);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(340, 10, 51, 21));
        lineEdit_qjDayNum = new QLineEdit(groupBox_qjType);
        lineEdit_qjDayNum->setObjectName(QString::fromUtf8("lineEdit_qjDayNum"));
        lineEdit_qjDayNum->setGeometry(QRect(392, 10, 61, 20));
        lineEdit_qjDayNum->setFont(font1);
        lineEdit_qjDayNum->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        checkBox_sj = new QCheckBox(groupBox_qjType);
        checkBox_sj->setObjectName(QString::fromUtf8("checkBox_sj"));
        checkBox_sj->setGeometry(QRect(30, 10, 51, 21));
        checkBox_sj->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        checkBox_bj = new QCheckBox(groupBox_qjType);
        checkBox_bj->setObjectName(QString::fromUtf8("checkBox_bj"));
        checkBox_bj->setGeometry(QRect(100, 10, 51, 21));
        checkBox_shijia = new QCheckBox(groupBox_qjType);
        checkBox_shijia->setObjectName(QString::fromUtf8("checkBox_shijia"));
        checkBox_shijia->setGeometry(QRect(160, 10, 61, 21));
        checkBox_hx = new QCheckBox(groupBox_qjType);
        checkBox_hx->setObjectName(QString::fromUtf8("checkBox_hx"));
        checkBox_hx->setGeometry(QRect(220, 10, 51, 21));
        checkBox_other = new QCheckBox(groupBox_qjType);
        checkBox_other->setObjectName(QString::fromUtf8("checkBox_other"));
        checkBox_other->setGeometry(QRect(280, 10, 51, 21));
        comboBox_dw = new QComboBox(groupBox_qjType);
        comboBox_dw->setObjectName(QString::fromUtf8("comboBox_dw"));
        comboBox_dw->setGeometry(QRect(450, 10, 51, 20));
        comboBox_dw->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        calendarWidget_qjEndTime = new QCalendarWidget(groupBox_qj);
        calendarWidget_qjEndTime->setObjectName(QString::fromUtf8("calendarWidget_qjEndTime"));
        calendarWidget_qjEndTime->setGeometry(QRect(600, 70, 248, 197));
        label_12 = new QLabel(groupBox_qj);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 140, 71, 20));
        textEdit_qjRecord = new QTextEdit(groupBox_qj);
        textEdit_qjRecord->setObjectName(QString::fromUtf8("textEdit_qjRecord"));
        textEdit_qjRecord->setGeometry(QRect(110, 250, 731, 51));
        textEdit_qjRecord->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_9 = new QLabel(groupBox_qj);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 270, 54, 12));
        label_2->raise();
        lineEdit_name->raise();
        label_3->raise();
        label_4->raise();
        lineEdit_qjStartTime->raise();
        toolButton_qjStart->raise();
        label_5->raise();
        comboBox_position->raise();
        label_6->raise();
        timeEdit->raise();
        toolButton_qjEnd->raise();
        timeEdit_2->raise();
        lineEdit_qjEndTime->raise();
        label_7->raise();
        label_8->raise();
        textEdit_qjReason->raise();
        lineEdit_dealTime->raise();
        comboBox_department->raise();
        groupBox_qjType->raise();
        calendarWidget_qjEndTime->raise();
        label_12->raise();
        textEdit_qjRecord->raise();
        label_9->raise();
        calendarWidget_qjStartTime->raise();
        groupBox_leader1 = new QGroupBox(QingJia);
        groupBox_leader1->setObjectName(QString::fromUtf8("groupBox_leader1"));
        groupBox_leader1->setGeometry(QRect(210, 360, 651, 91));
        label_11 = new QLabel(groupBox_leader1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 30, 61, 41));
        comboBox_dealResult1 = new QComboBox(groupBox_leader1);
        comboBox_dealResult1->setObjectName(QString::fromUtf8("comboBox_dealResult1"));
        comboBox_dealResult1->setGeometry(QRect(90, 40, 71, 22));
        comboBox_dealResult1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(groupBox_leader1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 40, 71, 21));
        textEdit_leaderAdvice1 = new QTextEdit(groupBox_leader1);
        textEdit_leaderAdvice1->setObjectName(QString::fromUtf8("textEdit_leaderAdvice1"));
        textEdit_leaderAdvice1->setGeometry(QRect(250, 20, 391, 61));
        textEdit_leaderAdvice1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        groupBox_leader2 = new QGroupBox(QingJia);
        groupBox_leader2->setObjectName(QString::fromUtf8("groupBox_leader2"));
        groupBox_leader2->setGeometry(QRect(210, 460, 651, 91));
        label_22 = new QLabel(groupBox_leader2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 30, 61, 41));
        comboBox_dealResult2 = new QComboBox(groupBox_leader2);
        comboBox_dealResult2->setObjectName(QString::fromUtf8("comboBox_dealResult2"));
        comboBox_dealResult2->setGeometry(QRect(90, 40, 71, 22));
        comboBox_dealResult2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_23 = new QLabel(groupBox_leader2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(180, 40, 71, 21));
        textEdit_leaderAdvice2 = new QTextEdit(groupBox_leader2);
        textEdit_leaderAdvice2->setObjectName(QString::fromUtf8("textEdit_leaderAdvice2"));
        textEdit_leaderAdvice2->setGeometry(QRect(250, 20, 391, 61));
        textEdit_leaderAdvice2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_leader3 = new QGroupBox(QingJia);
        groupBox_leader3->setObjectName(QString::fromUtf8("groupBox_leader3"));
        groupBox_leader3->setGeometry(QRect(210, 560, 651, 91));
        label_25 = new QLabel(groupBox_leader3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(30, 30, 61, 41));
        comboBox_dealResult3 = new QComboBox(groupBox_leader3);
        comboBox_dealResult3->setObjectName(QString::fromUtf8("comboBox_dealResult3"));
        comboBox_dealResult3->setGeometry(QRect(90, 40, 71, 22));
        comboBox_dealResult3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(groupBox_leader3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(180, 40, 71, 21));
        textEdit_leaderAdvice3 = new QTextEdit(groupBox_leader3);
        textEdit_leaderAdvice3->setObjectName(QString::fromUtf8("textEdit_leaderAdvice3"));
        textEdit_leaderAdvice3->setGeometry(QRect(250, 20, 391, 61));
        textEdit_leaderAdvice3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pButtonOk = new QPushButton(QingJia);
        pButtonOk->setObjectName(QString::fromUtf8("pButtonOk"));
        pButtonOk->setGeometry(QRect(230, 660, 91, 23));
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
        pButtonCancel = new QPushButton(QingJia);
        pButtonCancel->setObjectName(QString::fromUtf8("pButtonCancel"));
        pButtonCancel->setGeometry(QRect(560, 660, 81, 23));
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
        toolButton_close = new closeButton(QingJia);
        toolButton_close->setObjectName(QString::fromUtf8("toolButton_close"));
        toolButton_close->setGeometry(QRect(850, 0, 18, 18));
        toolButton_close->setMaximumSize(QSize(18, 18));
        groupBox_allLeader = new QGroupBox(QingJia);
        groupBox_allLeader->setObjectName(QString::fromUtf8("groupBox_allLeader"));
        groupBox_allLeader->setGeometry(QRect(10, 360, 191, 291));
        comboBox_leader1 = new QComboBox(groupBox_allLeader);
        comboBox_leader1->setObjectName(QString::fromUtf8("comboBox_leader1"));
        comboBox_leader1->setGeometry(QRect(80, 50, 81, 22));
        comboBox_leader1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader1->setEditable(true);
        label_10 = new QLabel(groupBox_allLeader);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 50, 61, 21));
        comboBox_leader2 = new QComboBox(groupBox_allLeader);
        comboBox_leader2->setObjectName(QString::fromUtf8("comboBox_leader2"));
        comboBox_leader2->setGeometry(QRect(80, 130, 81, 22));
        comboBox_leader2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader2->setEditable(true);
        label_24 = new QLabel(groupBox_allLeader);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 130, 51, 21));
        label_27 = new QLabel(groupBox_allLeader);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(30, 230, 51, 21));
        comboBox_leader3 = new QComboBox(groupBox_allLeader);
        comboBox_leader3->setObjectName(QString::fromUtf8("comboBox_leader3"));
        comboBox_leader3->setGeometry(QRect(80, 230, 81, 22));
        comboBox_leader3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader3->setEditable(true);
        label = new QLabel(QingJia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 2, 71, 16));
        QFont font3;
        font3.setPointSize(10);
        label->setFont(font3);

        retranslateUi(QingJia);

        QMetaObject::connectSlotsByName(QingJia);
    } // setupUi

    void retranslateUi(QWidget *QingJia)
    {
        QingJia->setWindowTitle(QApplication::translate("QingJia", "Form", nullptr));
        groupBox_qj->setTitle(QApplication::translate("QingJia", "\350\257\267\345\201\207\347\224\263\350\257\267", nullptr));
        label_2->setText(QApplication::translate("QingJia", "\345\247\223  \345\220\215(*)\357\274\232", nullptr));
        label_3->setText(QApplication::translate("QingJia", "\351\203\250    \351\227\250\357\274\232", nullptr));
        label_4->setText(QApplication::translate("QingJia", "\345\241\253\350\241\250\346\227\245\346\234\237\357\274\232", nullptr));
        toolButton_qjStart->setText(QString());
        label_5->setText(QApplication::translate("QingJia", " \350\201\214    \345\212\241\357\274\232", nullptr));
        label_6->setText(QApplication::translate("QingJia", "\350\257\267\345\201\207\346\227\266\351\227\264\357\274\232", nullptr));
        toolButton_qjEnd->setText(QString());
        label_7->setText(QApplication::translate("QingJia", "\345\210\260", nullptr));
        label_8->setText(QApplication::translate("QingJia", "\350\257\267\345\201\207\344\272\213\347\224\261(*)\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_qjType->setToolTip(QApplication::translate("QingJia", "\345\246\202\346\236\234\346\215\242\344\274\221\357\274\214\350\257\267\345\244\207\346\263\250\346\215\242\344\274\221\346\227\245\346\234\237", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_qjType->setTitle(QString());
        label_13->setText(QApplication::translate("QingJia", "\345\205\261\350\257\267(*)\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_qjDayNum->setToolTip(QApplication::translate("QingJia", "\345\246\202\357\274\2320.5\345\244\251", nullptr));
#endif // QT_NO_TOOLTIP
        checkBox_sj->setText(QApplication::translate("QingJia", "\344\274\244\345\201\207", nullptr));
        checkBox_bj->setText(QApplication::translate("QingJia", "\347\227\205\345\201\207", nullptr));
        checkBox_shijia->setText(QApplication::translate("QingJia", "\344\272\213\345\201\207", nullptr));
        checkBox_hx->setText(QApplication::translate("QingJia", "\346\215\242\344\274\221", nullptr));
        checkBox_other->setText(QApplication::translate("QingJia", "\345\205\266\344\273\226", nullptr));
        label_12->setText(QApplication::translate("QingJia", "\350\257\267\345\201\207\347\261\273\345\236\213(*)\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        textEdit_qjRecord->setToolTip(QApplication::translate("QingJia", "\345\246\202\346\236\234\346\215\242\344\274\221,\350\257\267\345\244\207\346\263\250\346\215\242\344\274\221\346\227\245\346\234\237", nullptr));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("QingJia", "\345\244\207    \346\263\250\357\274\232", nullptr));
        groupBox_leader1->setTitle(QApplication::translate("QingJia", "\346\211\200\345\234\250\351\203\250\351\227\250\347\233\270\345\205\263\346\204\217\350\247\201", nullptr));
        label_11->setText(QApplication::translate("QingJia", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_15->setText(QApplication::translate("QingJia", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox_leader2->setTitle(QApplication::translate("QingJia", "\346\200\273\347\273\217\345\212\236\346\204\217\350\247\201", nullptr));
        label_22->setText(QApplication::translate("QingJia", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_23->setText(QApplication::translate("QingJia", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox_leader3->setTitle(QApplication::translate("QingJia", "\346\200\273\347\273\217\347\220\206\346\204\217\350\247\201", nullptr));
        label_25->setText(QApplication::translate("QingJia", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_26->setText(QApplication::translate("QingJia", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        pButtonOk->setText(QApplication::translate("QingJia", "\347\241\256\345\256\232", nullptr));
        pButtonCancel->setText(QApplication::translate("QingJia", "\345\217\226\346\266\210", nullptr));
        toolButton_close->setText(QString());
        groupBox_allLeader->setTitle(QApplication::translate("QingJia", "\345\256\241\346\240\270\344\272\272", nullptr));
        label_10->setText(QApplication::translate("QingJia", "\351\203\250\351\227\250\351\242\206\345\257\274\357\274\232", nullptr));
        label_24->setText(QApplication::translate("QingJia", "\346\200\273\347\273\217\345\212\236\357\274\232", nullptr));
        label_27->setText(QApplication::translate("QingJia", "\346\200\273\347\273\217\347\220\206\357\274\232", nullptr));
        label->setText(QApplication::translate("QingJia", "\350\257\267\345\201\207\347\224\263\350\257\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QingJia: public Ui_QingJia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QINGJIA_H
