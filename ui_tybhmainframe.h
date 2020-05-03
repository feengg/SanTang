/********************************************************************************
** Form generated from reading UI file 'tybhmainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYBHMAINFRAME_H
#define UI_TYBHMAINFRAME_H

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

class Ui_TybhMainFrame
{
public:
    QLabel *label;
    QPushButton *pushButton_close;
    QPushButton *pushButton_min;
    QGroupBox *groupBox;
    QPushButton *pushButton_new;
    QLabel *label_2;
    QComboBox *comboBox_proType;
    QTableWidget *tableWidget;

    void setupUi(QWidget *TybhMainFrame)
    {
        if (TybhMainFrame->objectName().isEmpty())
            TybhMainFrame->setObjectName(QString::fromUtf8("TybhMainFrame"));
        TybhMainFrame->resize(1051, 716);
        label = new QLabel(TybhMainFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(480, 20, 91, 21));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        pushButton_close = new QPushButton(TybhMainFrame);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(1030, 0, 28, 16));
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
        pushButton_min = new QPushButton(TybhMainFrame);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setGeometry(QRect(1010, 0, 28, 16));
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
        groupBox = new QGroupBox(TybhMainFrame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 1031, 61));
        pushButton_new = new QPushButton(groupBox);
        pushButton_new->setObjectName(QString::fromUtf8("pushButton_new"));
        pushButton_new->setGeometry(QRect(170, 20, 151, 23));
        QFont font1;
        font1.setPointSize(10);
        pushButton_new->setFont(font1);
        pushButton_new->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_new\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_new:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_new:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(593, 22, 61, 20));
        comboBox_proType = new QComboBox(groupBox);
        comboBox_proType->setObjectName(QString::fromUtf8("comboBox_proType"));
        comboBox_proType->setGeometry(QRect(660, 20, 131, 22));
        comboBox_proType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableWidget = new QTableWidget(TybhMainFrame);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 120, 1031, 591));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));

        retranslateUi(TybhMainFrame);

        QMetaObject::connectSlotsByName(TybhMainFrame);
    } // setupUi

    void retranslateUi(QWidget *TybhMainFrame)
    {
        TybhMainFrame->setWindowTitle(QApplication::translate("TybhMainFrame", "Form", nullptr));
        label->setText(QApplication::translate("TybhMainFrame", "\351\241\271\347\233\256\345\210\227\350\241\250", nullptr));
        pushButton_close->setText(QString());
        pushButton_min->setText(QString());
        groupBox->setTitle(QString());
        pushButton_new->setText(QApplication::translate("TybhMainFrame", "\346\226\260\345\242\236", nullptr));
        label_2->setText(QApplication::translate("TybhMainFrame", "\351\241\271\347\233\256\347\261\273\345\236\213\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TybhMainFrame: public Ui_TybhMainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYBHMAINFRAME_H
