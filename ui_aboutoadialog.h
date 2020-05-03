/********************************************************************************
** Form generated from reading UI file 'aboutoadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTOADIALOG_H
#define UI_ABOUTOADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutOADialog
{
public:

    void setupUi(QWidget *AboutOADialog)
    {
        if (AboutOADialog->objectName().isEmpty())
            AboutOADialog->setObjectName(QString::fromUtf8("AboutOADialog"));
        AboutOADialog->resize(450, 300);

        retranslateUi(AboutOADialog);

        QMetaObject::connectSlotsByName(AboutOADialog);
    } // setupUi

    void retranslateUi(QWidget *AboutOADialog)
    {
        AboutOADialog->setWindowTitle(QApplication::translate("AboutOADialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutOADialog: public Ui_AboutOADialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTOADIALOG_H
