/********************************************************************************
** Form generated from reading UI file 'chukuform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHUKUFORM_H
#define UI_CHUKUFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChuKuForm
{
public:
    QPushButton *pushButton_close;
    QLabel *label;
    QLabel *label_have;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *ChuKuForm)
    {
        if (ChuKuForm->objectName().isEmpty())
            ChuKuForm->setObjectName(QString::fromUtf8("ChuKuForm"));
        ChuKuForm->resize(442, 241);
        pushButton_close = new QPushButton(ChuKuForm);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(420, 0, 16, 16));
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
        label = new QLabel(ChuKuForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 50, 71, 21));
        label_have = new QLabel(ChuKuForm);
        label_have->setObjectName(QString::fromUtf8("label_have"));
        label_have->setGeometry(QRect(230, 50, 51, 21));
        QFont font;
        font.setPointSize(12);
        label_have->setFont(font);
        label_2 = new QLabel(ChuKuForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 110, 71, 16));
        lineEdit = new QLineEdit(ChuKuForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 110, 61, 20));
        pushButton = new QPushButton(ChuKuForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 170, 131, 23));
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

        retranslateUi(ChuKuForm);

        QMetaObject::connectSlotsByName(ChuKuForm);
    } // setupUi

    void retranslateUi(QWidget *ChuKuForm)
    {
        ChuKuForm->setWindowTitle(QApplication::translate("ChuKuForm", "Form", nullptr));
        pushButton_close->setText(QString());
        label->setText(QApplication::translate("ChuKuForm", "\345\211\251\344\275\231\345\272\223\345\255\230\346\225\260\357\274\232", nullptr));
        label_have->setText(QString());
        label_2->setText(QApplication::translate("ChuKuForm", "\351\200\211\346\213\251\345\207\272\345\272\223\346\225\260\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("ChuKuForm", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChuKuForm: public Ui_ChuKuForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHUKUFORM_H
