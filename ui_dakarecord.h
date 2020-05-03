/********************************************************************************
** Form generated from reading UI file 'dakarecord.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAKARECORD_H
#define UI_DAKARECORD_H

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

class Ui_DaKaRecord
{
public:
    QPushButton *pushButton_min;
    QPushButton *pushButton_close;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *pushButton_inputExcel;
    QLabel *label_3;
    QComboBox *comboBox_year;
    QLabel *label_4;
    QPushButton *pushButton_search;
    QComboBox *comboBox_mouth;
    QComboBox *comboBox_name;
    QLabel *label_5;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DaKaRecord)
    {
        if (DaKaRecord->objectName().isEmpty())
            DaKaRecord->setObjectName(QString::fromUtf8("DaKaRecord"));
        DaKaRecord->resize(660, 728);
        pushButton_min = new QPushButton(DaKaRecord);
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
        pushButton_close = new QPushButton(DaKaRecord);
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
        label = new QLabel(DaKaRecord);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 54, 16));
        groupBox = new QGroupBox(DaKaRecord);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 641, 51));
        pushButton_inputExcel = new QPushButton(groupBox);
        pushButton_inputExcel->setObjectName(QString::fromUtf8("pushButton_inputExcel"));
        pushButton_inputExcel->setGeometry(QRect(20, 15, 101, 25));
        pushButton_inputExcel->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_inputExcel\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_inputExcel:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_inputExcel:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 15, 51, 21));
        comboBox_year = new QComboBox(groupBox);
        comboBox_year->setObjectName(QString::fromUtf8("comboBox_year"));
        comboBox_year->setGeometry(QRect(320, 15, 69, 22));
        comboBox_year->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 242);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 15, 31, 21));
        pushButton_search = new QPushButton(groupBox);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(530, 15, 91, 25));
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
        comboBox_mouth = new QComboBox(groupBox);
        comboBox_mouth->setObjectName(QString::fromUtf8("comboBox_mouth"));
        comboBox_mouth->setGeometry(QRect(440, 15, 69, 22));
        comboBox_mouth->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 242);"));
        comboBox_name = new QComboBox(groupBox);
        comboBox_name->setObjectName(QString::fromUtf8("comboBox_name"));
        comboBox_name->setGeometry(QRect(188, 16, 81, 22));
        comboBox_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 242);"));
        comboBox_name->setEditable(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 16, 31, 21));
        tableWidget = new QTableWidget(DaKaRecord);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 90, 641, 631));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));

        retranslateUi(DaKaRecord);

        QMetaObject::connectSlotsByName(DaKaRecord);
    } // setupUi

    void retranslateUi(QWidget *DaKaRecord)
    {
        DaKaRecord->setWindowTitle(QApplication::translate("DaKaRecord", "Form", nullptr));
        pushButton_min->setText(QString());
        pushButton_close->setText(QString());
        label->setText(QApplication::translate("DaKaRecord", "\346\211\223\345\215\241\350\256\260\345\275\225", nullptr));
        groupBox->setTitle(QString());
        pushButton_inputExcel->setText(QApplication::translate("DaKaRecord", "\345\257\274\345\205\245\350\200\203\345\213\244Excel", nullptr));
        label_3->setText(QApplication::translate("DaKaRecord", "\345\271\264\344\273\275\357\274\232", nullptr));
        label_4->setText(QApplication::translate("DaKaRecord", "\346\234\210\344\273\275\357\274\232", nullptr));
        pushButton_search->setText(QApplication::translate("DaKaRecord", "\346\237\245\350\257\242", nullptr));
        label_5->setText(QApplication::translate("DaKaRecord", "\345\247\223\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DaKaRecord: public Ui_DaKaRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAKARECORD_H
