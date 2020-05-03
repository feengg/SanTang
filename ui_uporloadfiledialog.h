/********************************************************************************
** Form generated from reading UI file 'uporloadfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPORLOADFILEDIALOG_H
#define UI_UPORLOADFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "closebutton.h"

QT_BEGIN_NAMESPACE

class Ui_UpOrLoadFileDialog
{
public:
    QLabel *label_state;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QPushButton *pushButton_brower;
    QLineEdit *lineEdit_path;
    QLabel *label_path;
    closeButton *toolButton;

    void setupUi(QWidget *UpOrLoadFileDialog)
    {
        if (UpOrLoadFileDialog->objectName().isEmpty())
            UpOrLoadFileDialog->setObjectName(QString::fromUtf8("UpOrLoadFileDialog"));
        UpOrLoadFileDialog->resize(567, 189);
        label_state = new QLabel(UpOrLoadFileDialog);
        label_state->setObjectName(QString::fromUtf8("label_state"));
        label_state->setGeometry(QRect(20, 40, 531, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_state->setFont(font);
        label_state->setStyleSheet(QString::fromUtf8("color: rgb(60, 73, 255);\n"
"font: 75 12pt \"Agency FB\";"));
        label_state->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(UpOrLoadFileDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 100, 531, 23));
        progressBar->setValue(24);
        pushButton = new QPushButton(UpOrLoadFileDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 150, 101, 23));
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
        groupBox = new QGroupBox(UpOrLoadFileDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 90, 551, 41));
        pushButton_brower = new QPushButton(groupBox);
        pushButton_brower->setObjectName(QString::fromUtf8("pushButton_brower"));
        pushButton_brower->setGeometry(QRect(502, 10, 31, 23));
        pushButton_brower->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_brower\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_brower:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_brower:pressed\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(204 , 228 , 247);\n"
"    border: 1px solid rgb(1 , 84 , 153);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}"));
        lineEdit_path = new QLineEdit(groupBox);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));
        lineEdit_path->setEnabled(false);
        lineEdit_path->setGeometry(QRect(70, 10, 431, 23));
        lineEdit_path->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_path = new QLabel(groupBox);
        label_path->setObjectName(QString::fromUtf8("label_path"));
        label_path->setGeometry(QRect(10, 10, 54, 21));
        toolButton = new closeButton(UpOrLoadFileDialog);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(550, 0, 16, 16));

        retranslateUi(UpOrLoadFileDialog);

        QMetaObject::connectSlotsByName(UpOrLoadFileDialog);
    } // setupUi

    void retranslateUi(QWidget *UpOrLoadFileDialog)
    {
        UpOrLoadFileDialog->setWindowTitle(QApplication::translate("UpOrLoadFileDialog", "Form", nullptr));
        label_state->setText(QString());
        pushButton->setText(QApplication::translate("UpOrLoadFileDialog", "\345\274\200\345\247\213\344\270\212\344\274\240", nullptr));
        groupBox->setTitle(QString());
        pushButton_brower->setText(QApplication::translate("UpOrLoadFileDialog", "\346\265\217\350\247\210", nullptr));
        label_path->setText(QApplication::translate("UpOrLoadFileDialog", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UpOrLoadFileDialog: public Ui_UpOrLoadFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPORLOADFILEDIALOG_H
