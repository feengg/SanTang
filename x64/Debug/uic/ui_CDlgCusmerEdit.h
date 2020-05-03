/********************************************************************************
** Form generated from reading UI file 'CDlgCusmerEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGCUSMEREDIT_H
#define UI_CDLGCUSMEREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgCusmerEdit
{
public:
    QTableWidget *mopTableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *mopBtnAdd;
    QPushButton *mopBtnSave;
    QPushButton *mopBtnEdit;
    QPushButton *mopBtnDel;
    QPushButton *mopBtnCancel;
    QPushButton *mopBtnQuit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mopLabQueyType;
    QComboBox *mopBoxQueyType;
    QLabel *mopLabKeyWord;
    QLineEdit *mopLineEditKeyWord;
    QPushButton *mopBtnQuery;

    void setupUi(QWidget *CDlgCusmerEdit)
    {
        if (CDlgCusmerEdit->objectName().isEmpty())
            CDlgCusmerEdit->setObjectName(QString::fromUtf8("CDlgCusmerEdit"));
        CDlgCusmerEdit->resize(959, 409);
        mopTableWidget = new QTableWidget(CDlgCusmerEdit);
        mopTableWidget->setObjectName(QString::fromUtf8("mopTableWidget"));
        mopTableWidget->setGeometry(QRect(10, 110, 911, 291));
        widget = new QWidget(CDlgCusmerEdit);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 482, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mopBtnAdd = new QPushButton(widget);
        mopBtnAdd->setObjectName(QString::fromUtf8("mopBtnAdd"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        mopBtnAdd->setFont(font);

        horizontalLayout->addWidget(mopBtnAdd);

        mopBtnSave = new QPushButton(widget);
        mopBtnSave->setObjectName(QString::fromUtf8("mopBtnSave"));
        mopBtnSave->setFont(font);

        horizontalLayout->addWidget(mopBtnSave);

        mopBtnEdit = new QPushButton(widget);
        mopBtnEdit->setObjectName(QString::fromUtf8("mopBtnEdit"));
        mopBtnEdit->setFont(font);

        horizontalLayout->addWidget(mopBtnEdit);

        mopBtnDel = new QPushButton(widget);
        mopBtnDel->setObjectName(QString::fromUtf8("mopBtnDel"));
        mopBtnDel->setFont(font);

        horizontalLayout->addWidget(mopBtnDel);

        mopBtnCancel = new QPushButton(widget);
        mopBtnCancel->setObjectName(QString::fromUtf8("mopBtnCancel"));
        mopBtnCancel->setFont(font);

        horizontalLayout->addWidget(mopBtnCancel);

        mopBtnQuit = new QPushButton(widget);
        mopBtnQuit->setObjectName(QString::fromUtf8("mopBtnQuit"));
        mopBtnQuit->setFont(font);

        horizontalLayout->addWidget(mopBtnQuit);

        widget1 = new QWidget(CDlgCusmerEdit);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 70, 481, 25));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        mopLabQueyType = new QLabel(widget1);
        mopLabQueyType->setObjectName(QString::fromUtf8("mopLabQueyType"));
        mopLabQueyType->setFont(font);

        horizontalLayout_2->addWidget(mopLabQueyType);

        mopBoxQueyType = new QComboBox(widget1);
        mopBoxQueyType->setObjectName(QString::fromUtf8("mopBoxQueyType"));

        horizontalLayout_2->addWidget(mopBoxQueyType);

        mopLabKeyWord = new QLabel(widget1);
        mopLabKeyWord->setObjectName(QString::fromUtf8("mopLabKeyWord"));
        mopLabKeyWord->setFont(font);

        horizontalLayout_2->addWidget(mopLabKeyWord);

        mopLineEditKeyWord = new QLineEdit(widget1);
        mopLineEditKeyWord->setObjectName(QString::fromUtf8("mopLineEditKeyWord"));

        horizontalLayout_2->addWidget(mopLineEditKeyWord);

        mopBtnQuery = new QPushButton(widget1);
        mopBtnQuery->setObjectName(QString::fromUtf8("mopBtnQuery"));

        horizontalLayout_2->addWidget(mopBtnQuery);


        retranslateUi(CDlgCusmerEdit);

        QMetaObject::connectSlotsByName(CDlgCusmerEdit);
    } // setupUi

    void retranslateUi(QWidget *CDlgCusmerEdit)
    {
        CDlgCusmerEdit->setWindowTitle(QApplication::translate("CDlgCusmerEdit", "CDlgCusmerEdit", nullptr));
        mopBtnAdd->setText(QApplication::translate("CDlgCusmerEdit", "\345\242\236\345\212\240", nullptr));
        mopBtnSave->setText(QApplication::translate("CDlgCusmerEdit", "\344\277\235\345\255\230", nullptr));
        mopBtnEdit->setText(QApplication::translate("CDlgCusmerEdit", "\347\274\226\350\276\221", nullptr));
        mopBtnDel->setText(QApplication::translate("CDlgCusmerEdit", "\345\210\240\351\231\244", nullptr));
        mopBtnCancel->setText(QApplication::translate("CDlgCusmerEdit", "\345\217\226\346\266\210", nullptr));
        mopBtnQuit->setText(QApplication::translate("CDlgCusmerEdit", "\351\200\200\345\207\272", nullptr));
        mopLabQueyType->setText(QApplication::translate("CDlgCusmerEdit", "\346\237\245\350\257\242\347\261\273\345\236\213\357\274\232", nullptr));
        mopLabKeyWord->setText(QApplication::translate("CDlgCusmerEdit", "\345\205\263\351\224\256\345\255\227\357\274\232", nullptr));
        mopBtnQuery->setText(QApplication::translate("CDlgCusmerEdit", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgCusmerEdit: public Ui_CDlgCusmerEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGCUSMEREDIT_H
