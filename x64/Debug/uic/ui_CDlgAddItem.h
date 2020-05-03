/********************************************************************************
** Form generated from reading UI file 'CDlgAddItem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGADDITEM_H
#define UI_CDLGADDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgAddItem
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *moLabID;
    QLineEdit *moLineEditID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *moLabMaterial;
    QLineEdit *moLineEditMaterial;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *moBtnOk;
    QPushButton *moBtnCancel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CDlgAddItem)
    {
        if (CDlgAddItem->objectName().isEmpty())
            CDlgAddItem->setObjectName(QString::fromUtf8("CDlgAddItem"));
        CDlgAddItem->resize(589, 368);
        gridLayout = new QGridLayout(CDlgAddItem);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 125, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        moLabID = new QLabel(CDlgAddItem);
        moLabID->setObjectName(QString::fromUtf8("moLabID"));

        horizontalLayout->addWidget(moLabID);

        moLineEditID = new QLineEdit(CDlgAddItem);
        moLineEditID->setObjectName(QString::fromUtf8("moLineEditID"));

        horizontalLayout->addWidget(moLineEditID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        moLabMaterial = new QLabel(CDlgAddItem);
        moLabMaterial->setObjectName(QString::fromUtf8("moLabMaterial"));

        horizontalLayout_2->addWidget(moLabMaterial);

        moLineEditMaterial = new QLineEdit(CDlgAddItem);
        moLineEditMaterial->setObjectName(QString::fromUtf8("moLineEditMaterial"));

        horizontalLayout_2->addWidget(moLineEditMaterial);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        moBtnOk = new QPushButton(CDlgAddItem);
        moBtnOk->setObjectName(QString::fromUtf8("moBtnOk"));

        horizontalLayout_3->addWidget(moBtnOk);

        moBtnCancel = new QPushButton(CDlgAddItem);
        moBtnCancel->setObjectName(QString::fromUtf8("moBtnCancel"));

        horizontalLayout_3->addWidget(moBtnCancel);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        QWidget::setTabOrder(moLineEditID, moLineEditMaterial);
        QWidget::setTabOrder(moLineEditMaterial, moBtnOk);
        QWidget::setTabOrder(moBtnOk, moBtnCancel);

        retranslateUi(CDlgAddItem);

        QMetaObject::connectSlotsByName(CDlgAddItem);
    } // setupUi

    void retranslateUi(QWidget *CDlgAddItem)
    {
        CDlgAddItem->setWindowTitle(QApplication::translate("CDlgAddItem", "CDlgAddItem", nullptr));
        moLabID->setText(QApplication::translate("CDlgAddItem", "ID:", nullptr));
        moLabMaterial->setText(QApplication::translate("CDlgAddItem", "material", nullptr));
        moBtnOk->setText(QApplication::translate("CDlgAddItem", "OK", nullptr));
        moBtnCancel->setText(QApplication::translate("CDlgAddItem", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgAddItem: public Ui_CDlgAddItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGADDITEM_H
