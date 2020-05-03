/********************************************************************************
** Form generated from reading UI file 'CDlgAddCusmerInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGADDCUSMERINFO_H
#define UI_CDLGADDCUSMERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgAddCusmerInfo
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;

    void setupUi(QWidget *CDlgAddCusmerInfo)
    {
        if (CDlgAddCusmerInfo->objectName().isEmpty())
            CDlgAddCusmerInfo->setObjectName(QString::fromUtf8("CDlgAddCusmerInfo"));
        CDlgAddCusmerInfo->resize(675, 353);
        pushButton = new QPushButton(CDlgAddCusmerInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(CDlgAddCusmerInfo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 30, 81, 31));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(CDlgAddCusmerInfo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 30, 81, 31));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(CDlgAddCusmerInfo);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 30, 81, 31));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(CDlgAddCusmerInfo);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(390, 30, 81, 31));
        pushButton_5->setFont(font);
        label = new QLabel(CDlgAddCusmerInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 51, 21));
        label->setFont(font);

        retranslateUi(CDlgAddCusmerInfo);

        QMetaObject::connectSlotsByName(CDlgAddCusmerInfo);
    } // setupUi

    void retranslateUi(QWidget *CDlgAddCusmerInfo)
    {
        CDlgAddCusmerInfo->setWindowTitle(QApplication::translate("CDlgAddCusmerInfo", "CDlgAddCusmerInfo", nullptr));
        pushButton->setText(QApplication::translate("CDlgAddCusmerInfo", "\345\242\236\345\212\240", nullptr));
        pushButton_2->setText(QApplication::translate("CDlgAddCusmerInfo", "\344\277\235\345\255\230", nullptr));
        pushButton_3->setText(QApplication::translate("CDlgAddCusmerInfo", "\347\274\226\350\276\221", nullptr));
        pushButton_4->setText(QApplication::translate("CDlgAddCusmerInfo", "\345\217\226\346\266\210", nullptr));
        pushButton_5->setText(QApplication::translate("CDlgAddCusmerInfo", "\351\200\200\345\207\272", nullptr));
        label->setText(QApplication::translate("CDlgAddCusmerInfo", "\347\274\226\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgAddCusmerInfo: public Ui_CDlgAddCusmerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGADDCUSMERINFO_H
