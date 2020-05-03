/********************************************************************************
** Form generated from reading UI file 'choosetype.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSETYPE_H
#define UI_CHOOSETYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseType
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *radioButton_jb;
    QCheckBox *radioButton_qj;
    QCheckBox *radioButton_wdk;
    QCheckBox *radioButton_chuchai;
    QCheckBox *radioButton_waichu;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *chooseType)
    {
        if (chooseType->objectName().isEmpty())
            chooseType->setObjectName(QString::fromUtf8("chooseType"));
        chooseType->resize(431, 173);
        groupBox = new QGroupBox(chooseType);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 411, 101));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(25, -1, 0, -1);
        radioButton_jb = new QCheckBox(groupBox);
        radioButton_jb->setObjectName(QString::fromUtf8("radioButton_jb"));
        radioButton_jb->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(radioButton_jb);

        radioButton_qj = new QCheckBox(groupBox);
        radioButton_qj->setObjectName(QString::fromUtf8("radioButton_qj"));
        radioButton_qj->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(radioButton_qj);

        radioButton_wdk = new QCheckBox(groupBox);
        radioButton_wdk->setObjectName(QString::fromUtf8("radioButton_wdk"));
        radioButton_wdk->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(radioButton_wdk);

        radioButton_chuchai = new QCheckBox(groupBox);
        radioButton_chuchai->setObjectName(QString::fromUtf8("radioButton_chuchai"));
        radioButton_chuchai->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(radioButton_chuchai);

        radioButton_waichu = new QCheckBox(groupBox);
        radioButton_waichu->setObjectName(QString::fromUtf8("radioButton_waichu"));
        radioButton_waichu->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(radioButton_waichu);

        pushButton = new QPushButton(chooseType);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 140, 61, 23));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
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
"}\n"
"\n"
""));
        pushButton_2 = new QPushButton(chooseType);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 140, 61, 23));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_2\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_2:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_2:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));

        retranslateUi(chooseType);

        QMetaObject::connectSlotsByName(chooseType);
    } // setupUi

    void retranslateUi(QWidget *chooseType)
    {
        chooseType->setWindowTitle(QApplication::translate("chooseType", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("chooseType", "\347\224\265\345\255\220\346\265\201\347\261\273\345\236\213\351\200\211\346\213\251", nullptr));
        radioButton_jb->setText(QApplication::translate("chooseType", "\345\212\240\347\217\255", nullptr));
        radioButton_qj->setText(QApplication::translate("chooseType", "\350\257\267\345\201\207", nullptr));
        radioButton_wdk->setText(QApplication::translate("chooseType", "\345\277\230\346\211\223\345\215\241", nullptr));
        radioButton_chuchai->setText(QApplication::translate("chooseType", "\345\207\272\345\267\256", nullptr));
        radioButton_waichu->setText(QApplication::translate("chooseType", "\345\244\226\345\207\272", nullptr));
        pushButton->setText(QApplication::translate("chooseType", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("chooseType", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chooseType: public Ui_chooseType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSETYPE_H
