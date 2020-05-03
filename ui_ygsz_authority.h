/********************************************************************************
** Form generated from reading UI file 'ygsz_authority.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YGSZ_AUTHORITY_H
#define UI_YGSZ_AUTHORITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_YGSZ_Authority
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_super;
    QLineEdit *lineEdit_kcgl;
    QLineEdit *lineEdit_kccw;
    QPushButton *pushButton_super;
    QPushButton *pushButton_kcgl;
    QPushButton *pushButton__kccw;
    QLabel *label_3;
    QLineEdit *lineEdit_store;
    QPushButton *pushButton__store;
    QLineEdit *lineEdit_caigou;
    QPushButton *pushButton__caigou;
    QLabel *label_6;
    QPushButton *pushButton__tybh;
    QLineEdit *lineEdit_tybh;
    QLabel *label_7;
    QPushButton *pushButton__wlbh;
    QLineEdit *lineEdit_wlbh;
    QLabel *label_8;
    closeButton *toolButton;
    QLabel *label;
    QPushButton *pushButton_kcgl_2;

    void setupUi(QWidget *YGSZ_Authority)
    {
        if (YGSZ_Authority->objectName().isEmpty())
            YGSZ_Authority->setObjectName(QString::fromUtf8("YGSZ_Authority"));
        YGSZ_Authority->resize(878, 505);
        groupBox = new QGroupBox(YGSZ_Authority);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 811, 381));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 91, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 90, 91, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 140, 81, 20));
        lineEdit_super = new QLineEdit(groupBox);
        lineEdit_super->setObjectName(QString::fromUtf8("lineEdit_super"));
        lineEdit_super->setEnabled(false);
        lineEdit_super->setGeometry(QRect(120, 40, 611, 20));
        lineEdit_super->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 85, 255);"));
        lineEdit_kcgl = new QLineEdit(groupBox);
        lineEdit_kcgl->setObjectName(QString::fromUtf8("lineEdit_kcgl"));
        lineEdit_kcgl->setEnabled(false);
        lineEdit_kcgl->setGeometry(QRect(120, 90, 611, 20));
        lineEdit_kcgl->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 85, 255);"));
        lineEdit_kccw = new QLineEdit(groupBox);
        lineEdit_kccw->setObjectName(QString::fromUtf8("lineEdit_kccw"));
        lineEdit_kccw->setEnabled(false);
        lineEdit_kccw->setGeometry(QRect(120, 140, 611, 20));
        lineEdit_kccw->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 85, 255);"));
        pushButton_super = new QPushButton(groupBox);
        pushButton_super->setObjectName(QString::fromUtf8("pushButton_super"));
        pushButton_super->setGeometry(QRect(740, 40, 51, 23));
        pushButton_super->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_super\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_super:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_super:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        pushButton_kcgl = new QPushButton(groupBox);
        pushButton_kcgl->setObjectName(QString::fromUtf8("pushButton_kcgl"));
        pushButton_kcgl->setGeometry(QRect(740, 90, 51, 23));
        pushButton_kcgl->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_kcgl\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_kcgl:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_kcgl:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        pushButton__kccw = new QPushButton(groupBox);
        pushButton__kccw->setObjectName(QString::fromUtf8("pushButton__kccw"));
        pushButton__kccw->setGeometry(QRect(740, 140, 51, 23));
        pushButton__kccw->setStyleSheet(QString::fromUtf8("QPushButton#pushButton__kccw\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton__kccw:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton__kccw:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 190, 91, 21));
        lineEdit_store = new QLineEdit(groupBox);
        lineEdit_store->setObjectName(QString::fromUtf8("lineEdit_store"));
        lineEdit_store->setEnabled(false);
        lineEdit_store->setGeometry(QRect(120, 190, 611, 20));
        lineEdit_store->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 85, 255);"));
        pushButton__store = new QPushButton(groupBox);
        pushButton__store->setObjectName(QString::fromUtf8("pushButton__store"));
        pushButton__store->setGeometry(QRect(740, 190, 51, 23));
        pushButton__store->setStyleSheet(QString::fromUtf8("QPushButton#pushButton__store\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton__store:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton__store:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        lineEdit_caigou = new QLineEdit(groupBox);
        lineEdit_caigou->setObjectName(QString::fromUtf8("lineEdit_caigou"));
        lineEdit_caigou->setEnabled(false);
        lineEdit_caigou->setGeometry(QRect(120, 240, 611, 20));
        lineEdit_caigou->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 85, 255);"));
        pushButton__caigou = new QPushButton(groupBox);
        pushButton__caigou->setObjectName(QString::fromUtf8("pushButton__caigou"));
        pushButton__caigou->setGeometry(QRect(740, 240, 51, 23));
        pushButton__caigou->setStyleSheet(QString::fromUtf8("QPushButton#pushButton__caigou\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton__caigou:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton__caigou:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 240, 81, 21));
        pushButton__tybh = new QPushButton(groupBox);
        pushButton__tybh->setObjectName(QString::fromUtf8("pushButton__tybh"));
        pushButton__tybh->setGeometry(QRect(740, 290, 51, 23));
        pushButton__tybh->setStyleSheet(QString::fromUtf8("QPushButton#pushButton__tybh\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton__tybh:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton__tybh:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        lineEdit_tybh = new QLineEdit(groupBox);
        lineEdit_tybh->setObjectName(QString::fromUtf8("lineEdit_tybh"));
        lineEdit_tybh->setEnabled(false);
        lineEdit_tybh->setGeometry(QRect(120, 290, 611, 20));
        lineEdit_tybh->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 85, 255);"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 290, 81, 21));
        pushButton__wlbh = new QPushButton(groupBox);
        pushButton__wlbh->setObjectName(QString::fromUtf8("pushButton__wlbh"));
        pushButton__wlbh->setGeometry(QRect(740, 340, 51, 23));
        pushButton__wlbh->setStyleSheet(QString::fromUtf8("QPushButton#pushButton__wlbh\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton__wlbh:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton__wlbh:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        lineEdit_wlbh = new QLineEdit(groupBox);
        lineEdit_wlbh->setObjectName(QString::fromUtf8("lineEdit_wlbh"));
        lineEdit_wlbh->setEnabled(false);
        lineEdit_wlbh->setGeometry(QRect(120, 340, 611, 20));
        lineEdit_wlbh->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);\n"
"color: rgb(0, 85, 255);"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 340, 81, 21));
        toolButton = new closeButton(YGSZ_Authority);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(860, 0, 15, 15));
        label = new QLabel(YGSZ_Authority);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 51, 16));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        pushButton_kcgl_2 = new QPushButton(YGSZ_Authority);
        pushButton_kcgl_2->setObjectName(QString::fromUtf8("pushButton_kcgl_2"));
        pushButton_kcgl_2->setGeometry(QRect(380, 460, 101, 23));
        pushButton_kcgl_2->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_kcgl_2\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_kcgl_2:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton_kcgl_2:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));

        retranslateUi(YGSZ_Authority);

        QMetaObject::connectSlotsByName(YGSZ_Authority);
    } // setupUi

    void retranslateUi(QWidget *YGSZ_Authority)
    {
        YGSZ_Authority->setWindowTitle(QApplication::translate("YGSZ_Authority", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("YGSZ_Authority", "\346\211\200\346\234\211\346\235\203\351\231\220", nullptr));
        label_2->setText(QApplication::translate("YGSZ_Authority", "\350\266\205\347\256\241\346\235\203\351\231\220\357\274\232", nullptr));
        label_4->setText(QApplication::translate("YGSZ_Authority", "\351\203\250\351\227\250\351\242\206\345\257\274\346\235\203\351\231\220\357\274\232", nullptr));
        label_5->setText(QApplication::translate("YGSZ_Authority", "\346\200\273\347\273\217\345\212\236\346\235\203\351\231\220\357\274\232", nullptr));
        lineEdit_super->setText(QString());
        pushButton_super->setText(QApplication::translate("YGSZ_Authority", "\344\277\256\346\224\271", nullptr));
        pushButton_kcgl->setText(QApplication::translate("YGSZ_Authority", "\344\277\256\346\224\271", nullptr));
        pushButton__kccw->setText(QApplication::translate("YGSZ_Authority", "\344\277\256\346\224\271", nullptr));
        label_3->setText(QApplication::translate("YGSZ_Authority", "\345\272\223\345\255\230\347\256\241\347\220\206\346\235\203\351\231\220\357\274\232", nullptr));
        pushButton__store->setText(QApplication::translate("YGSZ_Authority", "\344\277\256\346\224\271", nullptr));
        pushButton__caigou->setText(QApplication::translate("YGSZ_Authority", "\344\277\256\346\224\271", nullptr));
        label_6->setText(QApplication::translate("YGSZ_Authority", "\351\207\207\350\264\255\346\235\203\351\231\220\357\274\232", nullptr));
        pushButton__tybh->setText(QApplication::translate("YGSZ_Authority", "\344\277\256\346\224\271", nullptr));
        label_7->setText(QApplication::translate("YGSZ_Authority", "\346\200\273\345\267\245\345\212\236\346\235\203\351\231\220\357\274\232", nullptr));
        pushButton__wlbh->setText(QApplication::translate("YGSZ_Authority", "\344\277\256\346\224\271", nullptr));
        label_8->setText(QApplication::translate("YGSZ_Authority", "\347\211\251\346\226\231\347\274\226\345\217\267\346\235\203\351\231\220\357\274\232", nullptr));
        toolButton->setText(QString());
        label->setText(QApplication::translate("YGSZ_Authority", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        pushButton_kcgl_2->setText(QApplication::translate("YGSZ_Authority", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YGSZ_Authority: public Ui_YGSZ_Authority {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YGSZ_AUTHORITY_H
