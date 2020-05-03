/********************************************************************************
** Form generated from reading UI file 'weekreportmainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEEKREPORTMAINFRAME_H
#define UI_WEEKREPORTMAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeekReportMainFrame
{
public:
    QPushButton *pushButton_min;
    QPushButton *pushButton_close;
    QGroupBox *groupBox;
    QPushButton *pushButton_newReport;
    QLabel *label_3;
    QComboBox *comboBox_year;
    QLabel *label_4;
    QComboBox *comboBox_period;
    QComboBox *comboBox_name;
    QLabel *label_5;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton_dontSubmit;
    QPushButton *pushButton_sendTipMsg;

    void setupUi(QWidget *WeekReportMainFrame)
    {
        if (WeekReportMainFrame->objectName().isEmpty())
            WeekReportMainFrame->setObjectName(QString::fromUtf8("WeekReportMainFrame"));
        WeekReportMainFrame->resize(660, 741);
        pushButton_min = new QPushButton(WeekReportMainFrame);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(620, 0, 24, 16));
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
        pushButton_close = new QPushButton(WeekReportMainFrame);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(640, 0, 24, 16));
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
        groupBox = new QGroupBox(WeekReportMainFrame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 641, 51));
        pushButton_newReport = new QPushButton(groupBox);
        pushButton_newReport->setObjectName(QString::fromUtf8("pushButton_newReport"));
        pushButton_newReport->setGeometry(QRect(20, 15, 101, 25));
        pushButton_newReport->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_newReport\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_newReport:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_newReport:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 15, 41, 21));
        comboBox_year = new QComboBox(groupBox);
        comboBox_year->setObjectName(QString::fromUtf8("comboBox_year"));
        comboBox_year->setGeometry(QRect(310, 15, 69, 22));
        comboBox_year->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(390, 15, 51, 21));
        comboBox_period = new QComboBox(groupBox);
        comboBox_period->setObjectName(QString::fromUtf8("comboBox_period"));
        comboBox_period->setGeometry(QRect(440, 15, 191, 21));
        QFont font;
        font.setPointSize(10);
        comboBox_period->setFont(font);
        comboBox_period->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_name = new QComboBox(groupBox);
        comboBox_name->setObjectName(QString::fromUtf8("comboBox_name"));
        comboBox_name->setGeometry(QRect(178, 16, 81, 22));
        comboBox_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_name->setEditable(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 16, 31, 21));
        label = new QLabel(WeekReportMainFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 54, 16));
        tableWidget = new QTableWidget(WeekReportMainFrame);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(10, 90, 641, 611));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));
        pushButton_dontSubmit = new QPushButton(WeekReportMainFrame);
        pushButton_dontSubmit->setObjectName(QString::fromUtf8("pushButton_dontSubmit"));
        pushButton_dontSubmit->setGeometry(QRect(110, 710, 111, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        pushButton_dontSubmit->setFont(font1);
        pushButton_sendTipMsg = new QPushButton(WeekReportMainFrame);
        pushButton_sendTipMsg->setObjectName(QString::fromUtf8("pushButton_sendTipMsg"));
        pushButton_sendTipMsg->setGeometry(QRect(404, 710, 121, 25));
        pushButton_sendTipMsg->setFont(font1);

        retranslateUi(WeekReportMainFrame);

        QMetaObject::connectSlotsByName(WeekReportMainFrame);
    } // setupUi

    void retranslateUi(QWidget *WeekReportMainFrame)
    {
        WeekReportMainFrame->setWindowTitle(QApplication::translate("WeekReportMainFrame", "Form", nullptr));
        pushButton_min->setText(QString());
        pushButton_close->setText(QString());
        groupBox->setTitle(QString());
        pushButton_newReport->setText(QApplication::translate("WeekReportMainFrame", "\346\226\260\345\242\236\345\221\250\346\212\245", nullptr));
        label_3->setText(QApplication::translate("WeekReportMainFrame", "\345\271\264\344\273\275\357\274\232", nullptr));
        label_4->setText(QApplication::translate("WeekReportMainFrame", "\346\227\266\351\227\264\346\256\265\357\274\232", nullptr));
        label_5->setText(QApplication::translate("WeekReportMainFrame", "\345\247\223\345\220\215\357\274\232", nullptr));
        label->setText(QApplication::translate("WeekReportMainFrame", "\344\270\252\344\272\272\345\221\250\346\212\245", nullptr));
        pushButton_dontSubmit->setText(QApplication::translate("WeekReportMainFrame", "\346\230\276\347\244\272\346\234\252\344\272\244\344\272\272\345\221\230", nullptr));
        pushButton_sendTipMsg->setText(QApplication::translate("WeekReportMainFrame", "\344\270\200\351\224\256\345\217\221\351\200\201\346\217\220\351\206\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeekReportMainFrame: public Ui_WeekReportMainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKREPORTMAINFRAME_H
