/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignIn
{
public:
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_password;

    void setupUi(QWidget *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName(QString::fromUtf8("SignIn"));
        SignIn->resize(600, 300);
        SignIn->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(SignIn);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 122, 61, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label_3 = new QLabel(SignIn);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 36, 291, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font1.setPointSize(25);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setCursor(QCursor(Qt::CrossCursor));
        lineEdit_name = new QLineEdit(SignIn);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(240, 120, 151, 25));
        QFont font2;
        font2.setPointSize(13);
        lineEdit_name->setFont(font2);
        label_2 = new QLabel(SignIn);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 172, 61, 21));
        label_2->setFont(font);
        pushButton = new QPushButton(SignIn);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 240, 75, 25));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        pushButton_2 = new QPushButton(SignIn);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 240, 75, 25));
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        lineEdit_password = new QLineEdit(SignIn);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(240, 170, 151, 25));

        retranslateUi(SignIn);

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QWidget *SignIn)
    {
        SignIn->setWindowTitle(QApplication::translate("SignIn", "Form", nullptr));
        label->setText(QApplication::translate("SignIn", "\345\267\245  \345\217\267:", nullptr));
        label_3->setText(QApplication::translate("SignIn", "\346\255\243\346\211\254\345\215\232\345\210\233OA\347\263\273\347\273\237", nullptr));
        lineEdit_name->setText(QApplication::translate("SignIn", "zy0090", nullptr));
        label_2->setText(QApplication::translate("SignIn", "\345\257\206  \347\240\201:", nullptr));
        pushButton->setText(QApplication::translate("SignIn", "\347\231\273 \345\275\225", nullptr));
        pushButton_2->setText(QApplication::translate("SignIn", "\351\200\200 \345\207\272", nullptr));
        lineEdit_password->setText(QApplication::translate("SignIn", "123456", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
