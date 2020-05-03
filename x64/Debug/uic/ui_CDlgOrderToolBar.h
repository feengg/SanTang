/********************************************************************************
** Form generated from reading UI file 'CDlgOrderToolBar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGORDERTOOLBAR_H
#define UI_CDLGORDERTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgOrderToolBar
{
public:
    QGridLayout *gridLayout;
    QPushButton *mpBtnReturn;
    QPushButton *mopBtnCheck;
    QPushButton *mopBtnEdit;
    QPushButton *moBtnDelete;
    QPushButton *moBtnExportExcel;
    QPushButton *mopBtnFlush;

    void setupUi(QWidget *CDlgOrderToolBar)
    {
        if (CDlgOrderToolBar->objectName().isEmpty())
            CDlgOrderToolBar->setObjectName(QString::fromUtf8("CDlgOrderToolBar"));
        CDlgOrderToolBar->resize(872, 70);
        gridLayout = new QGridLayout(CDlgOrderToolBar);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mpBtnReturn = new QPushButton(CDlgOrderToolBar);
        mpBtnReturn->setObjectName(QString::fromUtf8("mpBtnReturn"));
        QFont font;
        font.setPointSize(16);
        mpBtnReturn->setFont(font);

        gridLayout->addWidget(mpBtnReturn, 0, 5, 1, 1);

        mopBtnCheck = new QPushButton(CDlgOrderToolBar);
        mopBtnCheck->setObjectName(QString::fromUtf8("mopBtnCheck"));
        mopBtnCheck->setFont(font);

        gridLayout->addWidget(mopBtnCheck, 0, 0, 1, 1);

        mopBtnEdit = new QPushButton(CDlgOrderToolBar);
        mopBtnEdit->setObjectName(QString::fromUtf8("mopBtnEdit"));
        mopBtnEdit->setFont(font);

        gridLayout->addWidget(mopBtnEdit, 0, 1, 1, 1);

        moBtnDelete = new QPushButton(CDlgOrderToolBar);
        moBtnDelete->setObjectName(QString::fromUtf8("moBtnDelete"));
        moBtnDelete->setFont(font);

        gridLayout->addWidget(moBtnDelete, 0, 3, 1, 1);

        moBtnExportExcel = new QPushButton(CDlgOrderToolBar);
        moBtnExportExcel->setObjectName(QString::fromUtf8("moBtnExportExcel"));
        moBtnExportExcel->setFont(font);

        gridLayout->addWidget(moBtnExportExcel, 0, 4, 1, 1);

        mopBtnFlush = new QPushButton(CDlgOrderToolBar);
        mopBtnFlush->setObjectName(QString::fromUtf8("mopBtnFlush"));
        mopBtnFlush->setFont(font);

        gridLayout->addWidget(mopBtnFlush, 0, 2, 1, 1);


        retranslateUi(CDlgOrderToolBar);

        QMetaObject::connectSlotsByName(CDlgOrderToolBar);
    } // setupUi

    void retranslateUi(QWidget *CDlgOrderToolBar)
    {
        CDlgOrderToolBar->setWindowTitle(QApplication::translate("CDlgOrderToolBar", "CDlgOrderToolBar", nullptr));
        mpBtnReturn->setText(QApplication::translate("CDlgOrderToolBar", "\350\277\224\345\233\236", nullptr));
        mopBtnCheck->setText(QApplication::translate("CDlgOrderToolBar", "\346\237\245\347\234\213", nullptr));
        mopBtnEdit->setText(QApplication::translate("CDlgOrderToolBar", "\347\274\226\350\276\221", nullptr));
        moBtnDelete->setText(QApplication::translate("CDlgOrderToolBar", "\345\210\240\351\231\244", nullptr));
        moBtnExportExcel->setText(QApplication::translate("CDlgOrderToolBar", "\345\257\274\345\207\272Excel", nullptr));
        mopBtnFlush->setText(QApplication::translate("CDlgOrderToolBar", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgOrderToolBar: public Ui_CDlgOrderToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGORDERTOOLBAR_H
