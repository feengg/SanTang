/********************************************************************************
** Form generated from reading UI file 'kcgl.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KCGL_H
#define UI_KCGL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "closebutton.h"
#include "minbutton.h"

QT_BEGIN_NAMESPACE

class Ui_KCGL
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    minButton *toolButton;
    QPushButton *pushButton_2;
    closeButton *toolButton_2;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_wlbh;
    QPushButton *pushButton_daoru;
    QPushButton *pushButton_daochu;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QLineEdit *lineEdit_ID;
    QLabel *label_4;
    QLineEdit *lineEdit_privoder;
    QLabel *label_5;
    QLineEdit *lineEdit_proID;
    QLabel *label_7;
    QLineEdit *lineEdit_Num;
    QLabel *label_serialID;
    QLineEdit *lineEdit_serialID;
    QComboBox *comboBox;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *lineEdit_inTime;
    QToolButton *toolButton_time;
    QTableView *tableView;

    void setupUi(QWidget *KCGL)
    {
        if (KCGL->objectName().isEmpty())
            KCGL->setObjectName(QString::fromUtf8("KCGL"));
        KCGL->resize(1375, 779);
        verticalLayout = new QVBoxLayout(KCGL);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(KCGL);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new minButton(KCGL);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(18, 18));
        toolButton->setMaximumSize(QSize(18, 18));

        horizontalLayout->addWidget(toolButton);

        pushButton_2 = new QPushButton(KCGL);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(18, 18));
        pushButton_2->setMaximumSize(QSize(25, 16777215));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{	\n"
"	background-image: url(:/images/max-min_first.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"	border:none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"	background-image: url(:/images/max-min_after.png);\n"
"	border:none;\n"
"}"));

        horizontalLayout->addWidget(pushButton_2);

        toolButton_2 = new closeButton(KCGL);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        toolButton_2->setMinimumSize(QSize(18, 18));
        toolButton_2->setMaximumSize(QSize(18, 18));

        horizontalLayout->addWidget(toolButton_2);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(KCGL);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 70));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 10, 55, 54));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\345\242\236\345\212\240\345\221\230\345\267\245.png);"));
        pushButton_wlbh = new QPushButton(groupBox);
        pushButton_wlbh->setObjectName(QString::fromUtf8("pushButton_wlbh"));
        pushButton_wlbh->setGeometry(QRect(130, 10, 55, 54));
        pushButton_wlbh->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\347\211\251\346\226\231\347\274\226\345\217\267.png);"));
        pushButton_daoru = new QPushButton(groupBox);
        pushButton_daoru->setObjectName(QString::fromUtf8("pushButton_daoru"));
        pushButton_daoru->setGeometry(QRect(210, 10, 51, 54));
        pushButton_daoru->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\345\272\223\345\255\230\345\257\274\345\205\245.png);"));
        pushButton_daochu = new QPushButton(groupBox);
        pushButton_daochu->setObjectName(QString::fromUtf8("pushButton_daochu"));
        pushButton_daochu->setGeometry(QRect(290, 10, 51, 54));
        pushButton_daochu->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\345\272\223\345\255\230\345\257\274\345\207\272.png);"));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(KCGL);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 55));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 20, 54, 21));
        lineEdit_name = new QLineEdit(groupBox_2);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(420, 20, 101, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 20, 54, 21));
        lineEdit_ID = new QLineEdit(groupBox_2);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(590, 20, 91, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1010, 20, 54, 21));
        lineEdit_privoder = new QLineEdit(groupBox_2);
        lineEdit_privoder->setObjectName(QString::fromUtf8("lineEdit_privoder"));
        lineEdit_privoder->setGeometry(QRect(1062, 20, 101, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1180, 20, 54, 21));
        lineEdit_proID = new QLineEdit(groupBox_2);
        lineEdit_proID->setObjectName(QString::fromUtf8("lineEdit_proID"));
        lineEdit_proID->setGeometry(QRect(1230, 20, 113, 20));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 20, 54, 21));
        lineEdit_Num = new QLineEdit(groupBox_2);
        lineEdit_Num->setObjectName(QString::fromUtf8("lineEdit_Num"));
        lineEdit_Num->setGeometry(QRect(250, 20, 101, 20));
        label_serialID = new QLabel(groupBox_2);
        label_serialID->setObjectName(QString::fromUtf8("label_serialID"));
        label_serialID->setGeometry(QRect(680, 20, 81, 21));
        lineEdit_serialID = new QLineEdit(groupBox_2);
        lineEdit_serialID->setObjectName(QString::fromUtf8("lineEdit_serialID"));
        lineEdit_serialID->setGeometry(QRect(770, 20, 101, 20));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(900, 20, 101, 22));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        comboBox->setEditable(true);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(870, 20, 31, 21));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 51, 21));
        lineEdit_inTime = new QLineEdit(groupBox_2);
        lineEdit_inTime->setObjectName(QString::fromUtf8("lineEdit_inTime"));
        lineEdit_inTime->setEnabled(true);
        lineEdit_inTime->setGeometry(QRect(70, 20, 101, 20));
        toolButton_time = new QToolButton(groupBox_2);
        toolButton_time->setObjectName(QString::fromUtf8("toolButton_time"));
        toolButton_time->setGeometry(QRect(170, 20, 16, 21));
        toolButton_time->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 235, 235);"));
        toolButton_time->setArrowType(Qt::DownArrow);

        verticalLayout->addWidget(groupBox_2);

        tableView = new QTableView(KCGL);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 235, 233);"));

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 20);

        retranslateUi(KCGL);

        QMetaObject::connectSlotsByName(KCGL);
    } // setupUi

    void retranslateUi(QWidget *KCGL)
    {
        KCGL->setWindowTitle(QApplication::translate("KCGL", "Form", nullptr));
        label->setText(QApplication::translate("KCGL", "\345\272\223\345\255\230\347\256\241\347\220\206", nullptr));
        toolButton->setText(QString());
        pushButton_2->setText(QString());
        toolButton_2->setText(QString());
        groupBox->setTitle(QApplication::translate("KCGL", "\345\267\245\345\205\267\346\240\217", nullptr));
        pushButton->setText(QString());
        pushButton_wlbh->setText(QString());
        pushButton_daoru->setText(QString());
        pushButton_daochu->setText(QString());
        groupBox_2->setTitle(QApplication::translate("KCGL", "\346\220\234\347\264\242\346\240\217", nullptr));
        label_2->setText(QApplication::translate("KCGL", "\347\211\251\346\226\231\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("KCGL", "\350\247\204\346\240\274\345\236\213\345\217\267\357\274\232", nullptr));
        label_4->setText(QApplication::translate("KCGL", "\344\276\233\345\272\224\345\225\206\357\274\232", nullptr));
        label_5->setText(QApplication::translate("KCGL", "\351\241\271\347\233\256\345\217\267\357\274\232", nullptr));
        label_7->setText(QApplication::translate("KCGL", "\347\211\251\346\226\231\347\274\226\345\217\267\357\274\232", nullptr));
        label_serialID->setText(QApplication::translate("KCGL", "\346\243\200\351\252\214\346\212\245\345\221\212\347\274\226\345\217\267\357\274\232", nullptr));
        comboBox->setCurrentText(QApplication::translate("KCGL", "\346\211\200\346\234\211\344\273\223\344\275\215", nullptr));
        label_6->setText(QApplication::translate("KCGL", "\344\273\223\344\275\215\357\274\232", nullptr));
        label_8->setText(QApplication::translate("KCGL", "\346\243\200\351\252\214\346\227\245\346\234\237\357\274\232", nullptr));
        toolButton_time->setText(QString());
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QApplication::translate("KCGL", "\345\217\263\351\224\256\345\217\257\346\237\245\347\234\213\344\277\256\346\224\271\345\210\240\351\231\244\345\272\223\345\255\230\344\277\241\346\201\257", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class KCGL: public Ui_KCGL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KCGL_H
