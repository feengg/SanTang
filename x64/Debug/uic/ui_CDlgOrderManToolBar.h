/********************************************************************************
** Form generated from reading UI file 'CDlgOrderManToolBar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGORDERMANTOOLBAR_H
#define UI_CDLGORDERMANTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgOrderManToolBar
{
public:
    QPushButton *mopBtnCheck;
    QPushButton *mopBtnEdit;
    QPushButton *mopBtnFlush;
    QPushButton *mopBtnReturn;

    void setupUi(QWidget *CDlgOrderManToolBar)
    {
        if (CDlgOrderManToolBar->objectName().isEmpty())
            CDlgOrderManToolBar->setObjectName(QString::fromUtf8("CDlgOrderManToolBar"));
        CDlgOrderManToolBar->resize(387, 55);
        CDlgOrderManToolBar->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:5px;\n"
"	background:rgb(150, 190, 60);\n"
"	color:black;\n"
"	font-size:20px;\n"
"}"));
        mopBtnCheck = new QPushButton(CDlgOrderManToolBar);
        mopBtnCheck->setObjectName(QString::fromUtf8("mopBtnCheck"));
        mopBtnCheck->setGeometry(QRect(20, 10, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        mopBtnCheck->setFont(font);
        mopBtnEdit = new QPushButton(CDlgOrderManToolBar);
        mopBtnEdit->setObjectName(QString::fromUtf8("mopBtnEdit"));
        mopBtnEdit->setGeometry(QRect(110, 10, 71, 31));
        mopBtnEdit->setFont(font);
        mopBtnFlush = new QPushButton(CDlgOrderManToolBar);
        mopBtnFlush->setObjectName(QString::fromUtf8("mopBtnFlush"));
        mopBtnFlush->setGeometry(QRect(190, 10, 81, 31));
        mopBtnFlush->setFont(font);
        mopBtnReturn = new QPushButton(CDlgOrderManToolBar);
        mopBtnReturn->setObjectName(QString::fromUtf8("mopBtnReturn"));
        mopBtnReturn->setGeometry(QRect(280, 10, 81, 31));
        mopBtnReturn->setFont(font);

        retranslateUi(CDlgOrderManToolBar);

        QMetaObject::connectSlotsByName(CDlgOrderManToolBar);
    } // setupUi

    void retranslateUi(QWidget *CDlgOrderManToolBar)
    {
        CDlgOrderManToolBar->setWindowTitle(QApplication::translate("CDlgOrderManToolBar", "CDlgOrderManToolBar", nullptr));
        mopBtnCheck->setText(QApplication::translate("CDlgOrderManToolBar", "\346\237\245\347\234\213", nullptr));
        mopBtnEdit->setText(QApplication::translate("CDlgOrderManToolBar", "\347\274\226\350\276\221", nullptr));
        mopBtnFlush->setText(QApplication::translate("CDlgOrderManToolBar", "\345\210\267\346\226\260", nullptr));
        mopBtnReturn->setText(QApplication::translate("CDlgOrderManToolBar", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgOrderManToolBar: public Ui_CDlgOrderManToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGORDERMANTOOLBAR_H
