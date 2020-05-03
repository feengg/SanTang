/********************************************************************************
** Form generated from reading UI file 'CDlgOrderMan.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDLGORDERMAN_H
#define UI_CDLGORDERMAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgOrderMan
{
public:
    QTableWidget *mopTableOrders;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *mopLabFind;
    QLabel *mopLabFromDate;
    QDateEdit *mopDateTo;
    QLabel *mopLabToDate;
    QDateEdit *mopDateFrom;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *mopBtnQuery;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *CDlgOrderMan)
    {
        if (CDlgOrderMan->objectName().isEmpty())
            CDlgOrderMan->setObjectName(QString::fromUtf8("CDlgOrderMan"));
        CDlgOrderMan->resize(1190, 450);
        CDlgOrderMan->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:5px;\n"
"	background:rgb(150, 190, 60);\n"
"	color:black;\n"
"	font-size:20px;\n"
"}\n"
"\n"
"\n"
"QLable\n"
"{\n"
"	border-radius:5px;\n"
"	background:rgb(255,255,255);\n"
"	color:black;\n"
"	font-size:25px;\n"
"}\n"
"\n"
"\n"
"QTableWidget\n"
"{\n"
"	border-radius:5px;\n"
"	background:rgb(255,255,255);\n"
"	color:black;\n"
"	font-size:15px;\n"
"}\n"
"\n"
""));
        mopTableOrders = new QTableWidget(CDlgOrderMan);
        mopTableOrders->setObjectName(QString::fromUtf8("mopTableOrders"));
        mopTableOrders->setGeometry(QRect(1, 26, 1181, 401));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mopTableOrders->sizePolicy().hasHeightForWidth());
        mopTableOrders->setSizePolicy(sizePolicy);
        mopTableOrders->setMinimumSize(QSize(0, 0));
        mopTableOrders->setRowCount(0);
        mopTableOrders->setColumnCount(0);
        layoutWidget = new QWidget(CDlgOrderMan);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1112, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mopLabFind = new QLabel(layoutWidget);
        mopLabFind->setObjectName(QString::fromUtf8("mopLabFind"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mopLabFind->sizePolicy().hasHeightForWidth());
        mopLabFind->setSizePolicy(sizePolicy1);
        mopLabFind->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"rgb(0, 85, 255)font: 9pt \"Consolas\";\n"
"}"));

        horizontalLayout->addWidget(mopLabFind);

        mopLabFromDate = new QLabel(layoutWidget);
        mopLabFromDate->setObjectName(QString::fromUtf8("mopLabFromDate"));

        horizontalLayout->addWidget(mopLabFromDate);

        mopDateTo = new QDateEdit(layoutWidget);
        mopDateTo->setObjectName(QString::fromUtf8("mopDateTo"));
        mopDateTo->setCalendarPopup(true);

        horizontalLayout->addWidget(mopDateTo);

        mopLabToDate = new QLabel(layoutWidget);
        mopLabToDate->setObjectName(QString::fromUtf8("mopLabToDate"));

        horizontalLayout->addWidget(mopLabToDate);

        mopDateFrom = new QDateEdit(layoutWidget);
        mopDateFrom->setObjectName(QString::fromUtf8("mopDateFrom"));
        mopDateFrom->setTabletTracking(false);
        mopDateFrom->setWrapping(false);
        mopDateFrom->setFrame(true);
        mopDateFrom->setReadOnly(false);
        mopDateFrom->setAccelerated(false);
        mopDateFrom->setCalendarPopup(true);

        horizontalLayout->addWidget(mopDateFrom);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEditable(true);

        horizontalLayout->addWidget(comboBox);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        mopBtnQuery = new QPushButton(layoutWidget);
        mopBtnQuery->setObjectName(QString::fromUtf8("mopBtnQuery"));

        horizontalLayout->addWidget(mopBtnQuery);

        horizontalSpacer = new QSpacerItem(528, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(CDlgOrderMan);

        QMetaObject::connectSlotsByName(CDlgOrderMan);
    } // setupUi

    void retranslateUi(QWidget *CDlgOrderMan)
    {
        CDlgOrderMan->setWindowTitle(QApplication::translate("CDlgOrderMan", "CDlgOrderMan", nullptr));
        mopLabFind->setText(QApplication::translate("CDlgOrderMan", "\346\237\245\346\211\276\346\240\217\357\274\232", nullptr));
        mopLabFromDate->setText(QApplication::translate("CDlgOrderMan", "\346\227\266\351\227\264\346\256\265\357\274\232", nullptr));
        mopLabToDate->setText(QApplication::translate("CDlgOrderMan", "\350\207\263\357\274\232", nullptr));
        mopBtnQuery->setText(QApplication::translate("CDlgOrderMan", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDlgOrderMan: public Ui_CDlgOrderMan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDLGORDERMAN_H
