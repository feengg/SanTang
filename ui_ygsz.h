/********************************************************************************
** Form generated from reading UI file 'ygsz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YGSZ_H
#define UI_YGSZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <minbutton.h>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_YGSZ
{
public:
    closeButton *toolButton_Close;
    QTableWidget *tableView;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QComboBox *comboBox_department;
    QLabel *label_5;
    QComboBox *comboBox_sex;
    QComboBox *comboBox_workState;
    QLabel *label_6;
    QGroupBox *groupBox;
    QToolButton *toolButton_New;
    QToolButton *toolButton_Change;
    QLabel *label_3;
    minButton *toolButton_Mini;

    void setupUi(QWidget *YGSZ)
    {
        if (YGSZ->objectName().isEmpty())
            YGSZ->setObjectName(QString::fromUtf8("YGSZ"));
        YGSZ->resize(1241, 820);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(YGSZ->sizePolicy().hasHeightForWidth());
        YGSZ->setSizePolicy(sizePolicy);
        YGSZ->setCursor(QCursor(Qt::ArrowCursor));
        toolButton_Close = new closeButton(YGSZ);
        toolButton_Close->setObjectName(QString::fromUtf8("toolButton_Close"));
        toolButton_Close->setGeometry(QRect(1220, 0, 18, 18));
        tableView = new QTableWidget(YGSZ);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 170, 1221, 631));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));
        groupBox_2 = new QGroupBox(YGSZ);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 110, 1221, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(10);
        groupBox_2->setFont(font);
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(877, 20, 111, 20));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(692, 19, 101, 20));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(652, 18, 36, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        label->setFont(font1);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(847, 19, 24, 21));
        label_2->setFont(font1);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(307, 20, 54, 21));
        label_4->setFont(font1);
        comboBox_department = new QComboBox(groupBox_2);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(347, 20, 111, 22));
        comboBox_department->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(497, 20, 54, 21));
        label_5->setFont(font1);
        comboBox_sex = new QComboBox(groupBox_2);
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->setObjectName(QString::fromUtf8("comboBox_sex"));
        comboBox_sex->setGeometry(QRect(537, 20, 69, 22));
        comboBox_sex->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_workState = new QComboBox(groupBox_2);
        comboBox_workState->addItem(QString());
        comboBox_workState->addItem(QString());
        comboBox_workState->setObjectName(QString::fromUtf8("comboBox_workState"));
        comboBox_workState->setGeometry(QRect(217, 20, 69, 22));
        comboBox_workState->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 20, 71, 21));
        label_6->setFont(font1);
        groupBox = new QGroupBox(YGSZ);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(11, 40, 1221, 71));
        toolButton_New = new QToolButton(groupBox);
        toolButton_New->setObjectName(QString::fromUtf8("toolButton_New"));
        toolButton_New->setGeometry(QRect(10, 10, 55, 54));
        toolButton_New->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_New->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/images/\345\242\236\345\212\240\345\221\230\345\267\245.png);"));
        toolButton_Change = new QToolButton(groupBox);
        toolButton_Change->setObjectName(QString::fromUtf8("toolButton_Change"));
        toolButton_Change->setGeometry(QRect(80, 10, 55, 55));
        toolButton_Change->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_Change->setAutoFillBackground(false);
        toolButton_Change->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\344\277\256\346\224\271\346\235\203\351\231\220.png);"));
        label_3 = new QLabel(YGSZ);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(13, 0, 61, 21));
        toolButton_Mini = new minButton(YGSZ);
        toolButton_Mini->setObjectName(QString::fromUtf8("toolButton_Mini"));
        toolButton_Mini->setGeometry(QRect(1200, 0, 18, 18));

        retranslateUi(YGSZ);

        QMetaObject::connectSlotsByName(YGSZ);
    } // setupUi

    void retranslateUi(QWidget *YGSZ)
    {
        YGSZ->setWindowTitle(QApplication::translate("YGSZ", "Form", nullptr));
        toolButton_Close->setText(QString());
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QApplication::translate("YGSZ", "\345\217\263\351\224\256\345\217\257\346\237\245\347\234\213\344\277\256\346\224\271\345\210\240\351\231\244", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("YGSZ", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("YGSZ", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("YGSZ", "IP\357\274\232", nullptr));
        label_4->setText(QApplication::translate("YGSZ", "\351\203\250\351\227\250\357\274\232", nullptr));
        label_5->setText(QApplication::translate("YGSZ", "\346\200\247\345\210\253\357\274\232", nullptr));
        comboBox_sex->setItemText(0, QApplication::translate("YGSZ", "\346\211\200\346\234\211", nullptr));
        comboBox_sex->setItemText(1, QApplication::translate("YGSZ", "\347\224\267", nullptr));
        comboBox_sex->setItemText(2, QApplication::translate("YGSZ", "\345\245\263", nullptr));

        comboBox_workState->setItemText(0, QApplication::translate("YGSZ", "\345\234\250\350\201\214", nullptr));
        comboBox_workState->setItemText(1, QApplication::translate("YGSZ", "\347\246\273\350\201\214", nullptr));

        label_6->setText(QApplication::translate("YGSZ", "\344\273\273\350\201\214\347\212\266\346\200\201\357\274\232", nullptr));
        groupBox->setTitle(QString());
        toolButton_New->setText(QString());
        toolButton_Change->setText(QString());
        label_3->setText(QApplication::translate("YGSZ", "\345\221\230\345\267\245\347\256\241\347\220\206", nullptr));
        toolButton_Mini->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class YGSZ: public Ui_YGSZ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YGSZ_H
