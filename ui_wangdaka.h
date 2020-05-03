/********************************************************************************
** Form generated from reading UI file 'wangdaka.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WANGDAKA_H
#define UI_WANGDAKA_H

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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <closebutton.h>

QT_BEGIN_NAMESPACE

class Ui_WangDaKa
{
public:
    QLabel *label;
    closeButton *toolButton;
    QGroupBox *groupBox_wdk;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_wdkStartTime;
    QToolButton *toolButton_wdkStart;
    QLabel *label_5;
    QComboBox *comboBox_position;
    QLabel *label_6;
    QLabel *label_8;
    QTextEdit *textEdit_wdkReason;
    QLineEdit *lineEdit_dealTime;
    QCalendarWidget *calendarWidget_wdkStartTime;
    QComboBox *comboBox_department;
    QGroupBox *groupBox_wdkType;
    QCheckBox *checkBox_sb;
    QCheckBox *checkBox_xb;
    QCalendarWidget *calendarWidget_wdkEndTime;
    QLabel *label_12;
    QGroupBox *groupBox_leader3;
    QLabel *label_25;
    QComboBox *comboBox_dealResult3;
    QLabel *label_26;
    QTextEdit *textEdit_leaderAdvice3;
    QGroupBox *groupBox_leader2;
    QLabel *label_22;
    QComboBox *comboBox_dealResult2;
    QLabel *label_23;
    QTextEdit *textEdit_leaderAdvice2;
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
    QLabel *label_27;
    QComboBox *comboBox_leader4;
    QLabel *label_18;
    QComboBox *comboBox_leader2;
    QGroupBox *groupBox_leader4;
    QLabel *label_28;
    QComboBox *comboBox_dealResult4;
    QLabel *label_29;
    QTextEdit *textEdit_leaderAdvice4;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;

    void setupUi(QWidget *WangDaKa)
    {
        if (WangDaKa->objectName().isEmpty())
            WangDaKa->setObjectName(QString::fromUtf8("WangDaKa"));
        WangDaKa->resize(874, 700);
        label = new QLabel(WangDaKa);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 2, 81, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        toolButton = new closeButton(WangDaKa);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(846, 0, 18, 18));
        toolButton->setMaximumSize(QSize(18, 18));
        groupBox_wdk = new QGroupBox(WangDaKa);
        groupBox_wdk->setObjectName(QString::fromUtf8("groupBox_wdk"));
        groupBox_wdk->setGeometry(QRect(10, 40, 851, 251));
        groupBox_wdk->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_wdk->setCheckable(false);
        label_2 = new QLabel(groupBox_wdk);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(53, 30, 61, 21));
        lineEdit_name = new QLineEdit(groupBox_wdk);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(120, 30, 151, 20));
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox_wdk);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 30, 61, 21));
        label_4 = new QLabel(groupBox_wdk);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 20, 54, 41));
        lineEdit_wdkStartTime = new QLineEdit(groupBox_wdk);
        lineEdit_wdkStartTime->setObjectName(QString::fromUtf8("lineEdit_wdkStartTime"));
        lineEdit_wdkStartTime->setEnabled(false);
        lineEdit_wdkStartTime->setGeometry(QRect(400, 80, 81, 20));
        lineEdit_wdkStartTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        toolButton_wdkStart = new QToolButton(groupBox_wdk);
        toolButton_wdkStart->setObjectName(QString::fromUtf8("toolButton_wdkStart"));
        toolButton_wdkStart->setGeometry(QRect(480, 80, 21, 20));
        toolButton_wdkStart->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_wdkStart->setArrowType(Qt::DownArrow);
        label_5 = new QLabel(groupBox_wdk);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 80, 71, 21));
        comboBox_position = new QComboBox(groupBox_wdk);
        comboBox_position->setObjectName(QString::fromUtf8("comboBox_position"));
        comboBox_position->setGeometry(QRect(120, 80, 151, 21));
        QFont font1;
        font1.setPointSize(9);
        comboBox_position->setFont(font1);
        comboBox_position->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBox_wdk);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 80, 71, 21));
        label_8 = new QLabel(groupBox_wdk);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 199, 91, 31));
        textEdit_wdkReason = new QTextEdit(groupBox_wdk);
        textEdit_wdkReason->setObjectName(QString::fromUtf8("textEdit_wdkReason"));
        textEdit_wdkReason->setGeometry(QRect(120, 190, 721, 51));
        textEdit_wdkReason->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_dealTime = new QLineEdit(groupBox_wdk);
        lineEdit_dealTime->setObjectName(QString::fromUtf8("lineEdit_dealTime"));
        lineEdit_dealTime->setEnabled(false);
        lineEdit_dealTime->setGeometry(QRect(630, 30, 121, 20));
        lineEdit_dealTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        calendarWidget_wdkStartTime = new QCalendarWidget(groupBox_wdk);
        calendarWidget_wdkStartTime->setObjectName(QString::fromUtf8("calendarWidget_wdkStartTime"));
        calendarWidget_wdkStartTime->setGeometry(QRect(470, 80, 248, 197));
        comboBox_department = new QComboBox(groupBox_wdk);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(400, 30, 101, 22));
        comboBox_department->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        groupBox_wdkType = new QGroupBox(groupBox_wdk);
        groupBox_wdkType->setObjectName(QString::fromUtf8("groupBox_wdkType"));
        groupBox_wdkType->setGeometry(QRect(120, 130, 731, 41));
        groupBox_wdkType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        checkBox_sb = new QCheckBox(groupBox_wdkType);
        checkBox_sb->setObjectName(QString::fromUtf8("checkBox_sb"));
        checkBox_sb->setGeometry(QRect(110, 10, 91, 21));
        checkBox_sb->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        checkBox_xb = new QCheckBox(groupBox_wdkType);
        checkBox_xb->setObjectName(QString::fromUtf8("checkBox_xb"));
        checkBox_xb->setGeometry(QRect(220, 10, 91, 21));
        calendarWidget_wdkEndTime = new QCalendarWidget(groupBox_wdk);
        calendarWidget_wdkEndTime->setObjectName(QString::fromUtf8("calendarWidget_wdkEndTime"));
        calendarWidget_wdkEndTime->setGeometry(QRect(530, 80, 248, 197));
        label_12 = new QLabel(groupBox_wdk);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 140, 91, 20));
        groupBox_leader3 = new QGroupBox(WangDaKa);
        groupBox_leader3->setObjectName(QString::fromUtf8("groupBox_leader3"));
        groupBox_leader3->setGeometry(QRect(210, 480, 651, 81));
        label_25 = new QLabel(groupBox_leader3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(30, 20, 61, 41));
        comboBox_dealResult3 = new QComboBox(groupBox_leader3);
        comboBox_dealResult3->setObjectName(QString::fromUtf8("comboBox_dealResult3"));
        comboBox_dealResult3->setGeometry(QRect(90, 30, 71, 22));
        comboBox_dealResult3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(groupBox_leader3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(180, 30, 71, 21));
        textEdit_leaderAdvice3 = new QTextEdit(groupBox_leader3);
        textEdit_leaderAdvice3->setObjectName(QString::fromUtf8("textEdit_leaderAdvice3"));
        textEdit_leaderAdvice3->setGeometry(QRect(250, 10, 391, 61));
        textEdit_leaderAdvice3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_leader2 = new QGroupBox(WangDaKa);
        groupBox_leader2->setObjectName(QString::fromUtf8("groupBox_leader2"));
        groupBox_leader2->setGeometry(QRect(210, 390, 651, 81));
        label_22 = new QLabel(groupBox_leader2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 20, 61, 41));
        comboBox_dealResult2 = new QComboBox(groupBox_leader2);
        comboBox_dealResult2->setObjectName(QString::fromUtf8("comboBox_dealResult2"));
        comboBox_dealResult2->setGeometry(QRect(90, 30, 71, 22));
        comboBox_dealResult2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_23 = new QLabel(groupBox_leader2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(180, 30, 71, 21));
        textEdit_leaderAdvice2 = new QTextEdit(groupBox_leader2);
        textEdit_leaderAdvice2->setObjectName(QString::fromUtf8("textEdit_leaderAdvice2"));
        textEdit_leaderAdvice2->setGeometry(QRect(250, 10, 391, 61));
        textEdit_leaderAdvice2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_leader1 = new QGroupBox(WangDaKa);
        groupBox_leader1->setObjectName(QString::fromUtf8("groupBox_leader1"));
        groupBox_leader1->setGeometry(QRect(210, 300, 651, 81));
        label_11 = new QLabel(groupBox_leader1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 20, 61, 41));
        comboBox_dealResult1 = new QComboBox(groupBox_leader1);
        comboBox_dealResult1->setObjectName(QString::fromUtf8("comboBox_dealResult1"));
        comboBox_dealResult1->setGeometry(QRect(90, 30, 71, 22));
        comboBox_dealResult1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(groupBox_leader1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 30, 71, 21));
        textEdit_leaderAdvice1 = new QTextEdit(groupBox_leader1);
        textEdit_leaderAdvice1->setObjectName(QString::fromUtf8("textEdit_leaderAdvice1"));
        textEdit_leaderAdvice1->setGeometry(QRect(250, 10, 391, 61));
        textEdit_leaderAdvice1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_allLeader = new QGroupBox(WangDaKa);
        groupBox_allLeader->setObjectName(QString::fromUtf8("groupBox_allLeader"));
        groupBox_allLeader->setGeometry(QRect(10, 300, 191, 351));
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
        comboBox_leader3->setGeometry(QRect(90, 210, 81, 22));
        comboBox_leader3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader3->setEditable(true);
        label_24 = new QLabel(groupBox_allLeader);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 210, 71, 21));
        label_27 = new QLabel(groupBox_allLeader);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 300, 61, 21));
        comboBox_leader4 = new QComboBox(groupBox_allLeader);
        comboBox_leader4->setObjectName(QString::fromUtf8("comboBox_leader4"));
        comboBox_leader4->setGeometry(QRect(90, 300, 81, 22));
        comboBox_leader4->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader4->setEditable(true);
        label_18 = new QLabel(groupBox_allLeader);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 120, 71, 21));
        comboBox_leader2 = new QComboBox(groupBox_allLeader);
        comboBox_leader2->setObjectName(QString::fromUtf8("comboBox_leader2"));
        comboBox_leader2->setGeometry(QRect(90, 120, 81, 22));
        comboBox_leader2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        comboBox_leader2->setEditable(true);
        groupBox_leader4 = new QGroupBox(WangDaKa);
        groupBox_leader4->setObjectName(QString::fromUtf8("groupBox_leader4"));
        groupBox_leader4->setGeometry(QRect(210, 570, 651, 81));
        label_28 = new QLabel(groupBox_leader4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(30, 20, 61, 41));
        comboBox_dealResult4 = new QComboBox(groupBox_leader4);
        comboBox_dealResult4->setObjectName(QString::fromUtf8("comboBox_dealResult4"));
        comboBox_dealResult4->setGeometry(QRect(90, 30, 71, 22));
        comboBox_dealResult4->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);\n"
"color: rgb(0, 0, 0);"));
        label_29 = new QLabel(groupBox_leader4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(180, 30, 71, 21));
        textEdit_leaderAdvice4 = new QTextEdit(groupBox_leader4);
        textEdit_leaderAdvice4->setObjectName(QString::fromUtf8("textEdit_leaderAdvice4"));
        textEdit_leaderAdvice4->setGeometry(QRect(250, 10, 391, 61));
        textEdit_leaderAdvice4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_OK = new QPushButton(WangDaKa);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(190, 660, 75, 23));
        pushButton_OK->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_OK\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_OK:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_OK:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}\n"
""));
        pushButton_Cancel = new QPushButton(WangDaKa);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(540, 660, 75, 23));
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Cancel\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_Cancel:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_Cancel:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));

        retranslateUi(WangDaKa);

        QMetaObject::connectSlotsByName(WangDaKa);
    } // setupUi

    void retranslateUi(QWidget *WangDaKa)
    {
        WangDaKa->setWindowTitle(QApplication::translate("WangDaKa", "Form", nullptr));
        label->setText(QApplication::translate("WangDaKa", "\345\277\230\346\211\223\345\215\241\347\224\263\350\257\267", nullptr));
        toolButton->setText(QString());
        groupBox_wdk->setTitle(QApplication::translate("WangDaKa", "\345\277\230\346\211\223\345\215\241\347\224\263\350\257\267", nullptr));
        label_2->setText(QApplication::translate("WangDaKa", "\345\247\223  \345\220\215(*)\357\274\232", nullptr));
        label_3->setText(QApplication::translate("WangDaKa", "\351\203\250    \351\227\250\357\274\232", nullptr));
        label_4->setText(QApplication::translate("WangDaKa", "\345\241\253\350\241\250\346\227\245\346\234\237\357\274\232", nullptr));
        toolButton_wdkStart->setText(QString());
        label_5->setText(QApplication::translate("WangDaKa", " \350\201\214    \345\212\241\357\274\232", nullptr));
        label_6->setText(QApplication::translate("WangDaKa", "\345\277\230\346\211\223\345\215\241\346\227\245\346\234\237\357\274\232", nullptr));
        label_8->setText(QApplication::translate("WangDaKa", "\345\277\230\346\211\223\345\215\241\345\216\237\345\233\240(*)\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_wdkType->setToolTip(QApplication::translate("WangDaKa", "\345\246\202\346\236\234\346\215\242\344\274\221\357\274\214\350\257\267\345\244\207\346\263\250\346\215\242\344\274\221\346\227\245\346\234\237", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_wdkType->setTitle(QString());
        checkBox_sb->setText(QApplication::translate("WangDaKa", "\344\270\212\347\217\255\345\277\230\346\211\223\345\215\241", nullptr));
        checkBox_xb->setText(QApplication::translate("WangDaKa", "\344\270\213\347\217\255\345\277\230\346\211\223\345\215\241", nullptr));
        label_12->setText(QApplication::translate("WangDaKa", "\345\277\230\346\211\223\345\215\241\346\227\266\346\256\265(*)\357\274\232", nullptr));
        groupBox_leader3->setTitle(QApplication::translate("WangDaKa", "\345\211\257\346\200\273\347\273\217\347\220\206\345\244\204\347\220\206", nullptr));
        label_25->setText(QApplication::translate("WangDaKa", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_26->setText(QApplication::translate("WangDaKa", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox_leader2->setTitle(QApplication::translate("WangDaKa", "\351\203\250\351\227\250\351\242\206\345\257\274\345\244\204\347\220\206", nullptr));
        label_22->setText(QApplication::translate("WangDaKa", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_23->setText(QApplication::translate("WangDaKa", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox_leader1->setTitle(QApplication::translate("WangDaKa", "\350\257\201\346\230\216\344\272\272\345\244\204\347\220\206", nullptr));
        label_11->setText(QApplication::translate("WangDaKa", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_15->setText(QApplication::translate("WangDaKa", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        groupBox_allLeader->setTitle(QApplication::translate("WangDaKa", "\345\256\241\346\240\270\344\272\272", nullptr));
        label_10->setText(QApplication::translate("WangDaKa", "\350\257\201\346\230\216\344\272\272(*)\357\274\232", nullptr));
        label_24->setText(QApplication::translate("WangDaKa", "\345\211\257\346\200\273\347\273\217\347\220\206(*)\357\274\232", nullptr));
        label_27->setText(QApplication::translate("WangDaKa", "\350\200\203\345\213\244\345\221\230(*)\357\274\232", nullptr));
        label_18->setText(QApplication::translate("WangDaKa", "\351\203\250\351\227\250\351\242\206\345\257\274(*)\357\274\232", nullptr));
        groupBox_leader4->setTitle(QApplication::translate("WangDaKa", "\350\200\203\345\213\244\345\221\230\345\244\204\347\220\206", nullptr));
        label_28->setText(QApplication::translate("WangDaKa", "\345\244\204\347\220\206\347\273\223\346\236\234\357\274\232", nullptr));
        label_29->setText(QApplication::translate("WangDaKa", "\346\204\217\350\247\201(\351\200\211\345\241\253)\357\274\232", nullptr));
        pushButton_OK->setText(QApplication::translate("WangDaKa", "\347\241\256\345\256\232", nullptr));
        pushButton_Cancel->setText(QApplication::translate("WangDaKa", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WangDaKa: public Ui_WangDaKa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WANGDAKA_H
