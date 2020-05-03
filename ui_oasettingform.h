/********************************************************************************
** Form generated from reading UI file 'oasettingform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OASETTINGFORM_H
#define UI_OASETTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OASettingForm
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_sqlBaseName;
    QLineEdit *lineEdit_sqlIP;
    QLineEdit *lineEdit_sqlPort;
    QLineEdit *lineEdit_sqlUserName;
    QLineEdit *lineEdit_sqlPassword;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLineEdit *lineEdit_serverIP;
    QLabel *label_7;
    QLineEdit *lineEdit_serverPort;
    QPushButton *pushButton;
    QPushButton *pushButton_close;

    void setupUi(QWidget *OASettingForm)
    {
        if (OASettingForm->objectName().isEmpty())
            OASettingForm->setObjectName(QString::fromUtf8("OASettingForm"));
        OASettingForm->resize(490, 417);
        QFont font;
        font.setPointSize(11);
        OASettingForm->setFont(font);
        groupBox = new QGroupBox(OASettingForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 40, 431, 221));
        QFont font1;
        font1.setPointSize(9);
        groupBox->setFont(font1);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 30, 71, 21));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 70, 91, 16));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(72, 110, 101, 16));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 150, 85, 16));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(52, 190, 121, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        lineEdit_sqlBaseName = new QLineEdit(groupBox);
        lineEdit_sqlBaseName->setObjectName(QString::fromUtf8("lineEdit_sqlBaseName"));
        lineEdit_sqlBaseName->setGeometry(QRect(190, 190, 211, 23));
        lineEdit_sqlBaseName->setFont(font);
        lineEdit_sqlIP = new QLineEdit(groupBox);
        lineEdit_sqlIP->setObjectName(QString::fromUtf8("lineEdit_sqlIP"));
        lineEdit_sqlIP->setGeometry(QRect(190, 30, 211, 23));
        lineEdit_sqlIP->setFont(font);
        lineEdit_sqlPort = new QLineEdit(groupBox);
        lineEdit_sqlPort->setObjectName(QString::fromUtf8("lineEdit_sqlPort"));
        lineEdit_sqlPort->setGeometry(QRect(190, 70, 211, 23));
        lineEdit_sqlPort->setFont(font);
        lineEdit_sqlUserName = new QLineEdit(groupBox);
        lineEdit_sqlUserName->setObjectName(QString::fromUtf8("lineEdit_sqlUserName"));
        lineEdit_sqlUserName->setGeometry(QRect(190, 110, 211, 23));
        lineEdit_sqlUserName->setFont(font);
        lineEdit_sqlPassword = new QLineEdit(groupBox);
        lineEdit_sqlPassword->setObjectName(QString::fromUtf8("lineEdit_sqlPassword"));
        lineEdit_sqlPassword->setGeometry(QRect(190, 150, 211, 23));
        lineEdit_sqlPassword->setFont(font);
        groupBox_2 = new QGroupBox(OASettingForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 270, 431, 101));
        groupBox_2->setFont(font1);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 60, 91, 16));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        lineEdit_serverIP = new QLineEdit(groupBox_2);
        lineEdit_serverIP->setObjectName(QString::fromUtf8("lineEdit_serverIP"));
        lineEdit_serverIP->setGeometry(QRect(190, 20, 211, 23));
        lineEdit_serverIP->setFont(font);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 20, 71, 21));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        lineEdit_serverPort = new QLineEdit(groupBox_2);
        lineEdit_serverPort->setObjectName(QString::fromUtf8("lineEdit_serverPort"));
        lineEdit_serverPort->setGeometry(QRect(190, 60, 211, 23));
        lineEdit_serverPort->setFont(font);
        pushButton = new QPushButton(OASettingForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(174, 380, 131, 23));
        QFont font2;
        font2.setPointSize(10);
        pushButton->setFont(font2);
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
"}"));
        pushButton_close = new QPushButton(OASettingForm);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(470, 0, 24, 16));
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

        retranslateUi(OASettingForm);

        QMetaObject::connectSlotsByName(OASettingForm);
    } // setupUi

    void retranslateUi(QWidget *OASettingForm)
    {
        OASettingForm->setWindowTitle(QApplication::translate("OASettingForm", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("OASettingForm", "\346\225\260\346\215\256\345\272\223\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("OASettingForm", "\346\225\260\346\215\256\345\272\223IP\357\274\232", nullptr));
        label_2->setText(QApplication::translate("OASettingForm", "\346\225\260\346\215\256\345\272\223\347\253\257\345\217\243\357\274\232", nullptr));
        label_3->setText(QApplication::translate("OASettingForm", "\346\225\260\346\215\256\345\272\223\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("OASettingForm", "\346\225\260\346\215\256\345\272\223\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QApplication::translate("OASettingForm", "\346\225\260\346\215\256\345\272\223BaseName\357\274\232", nullptr));
        lineEdit_sqlBaseName->setText(QApplication::translate("OASettingForm", "mySql5.6", nullptr));
        lineEdit_sqlIP->setText(QApplication::translate("OASettingForm", "192.168.1.44", nullptr));
        lineEdit_sqlPort->setText(QApplication::translate("OASettingForm", "3306", nullptr));
        lineEdit_sqlUserName->setText(QApplication::translate("OASettingForm", "root", nullptr));
        lineEdit_sqlPassword->setText(QApplication::translate("OASettingForm", "123456", nullptr));
        groupBox_2->setTitle(QApplication::translate("OASettingForm", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_6->setText(QApplication::translate("OASettingForm", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_serverIP->setText(QApplication::translate("OASettingForm", "192.168.1.44", nullptr));
        label_7->setText(QApplication::translate("OASettingForm", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        lineEdit_serverPort->setText(QApplication::translate("OASettingForm", "4513", nullptr));
        pushButton->setText(QApplication::translate("OASettingForm", "\347\241\256\345\256\232", nullptr));
        pushButton_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OASettingForm: public Ui_OASettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OASETTINGFORM_H
