/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mytoolbtn.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_min;
    QPushButton *pushButton_max;
    QPushButton *pushButton_close;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_newStream;
    QPushButton *pushButton_email;
    QPushButton *pushButton_leaveMsg;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QToolButton *toolBtn_jb;
    QToolButton *toolBtn_qj;
    QToolButton *toolBtn_wdk;
    QPushButton *pushButton_chuChai;
    QPushButton *pushButton_waiChu;
    QToolButton *toolBtn_cg;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_5;
    MyToolBtn *toolBtn_dcl;
    MyToolBtn *toolBtn_kqhz;
    MyToolBtn *toolBtn_cgjh;
    MyToolBtn *toolBtn_spkc;
    MyToolBtn *toolBtn_ygsz;
    MyToolBtn *toolBtn_tybh;
    MyToolBtn *toolButton_daka;
    MyToolBtn *toolButton_weekReport;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_userName;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_quitAutoRun;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_help;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_haveFun;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1094, 842);
        Widget->setMouseTracking(false);
        Widget->setAutoFillBackground(false);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_min = new QPushButton(Widget);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
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

        horizontalLayout_3->addWidget(pushButton_min);

        pushButton_max = new QPushButton(Widget);
        pushButton_max->setObjectName(QString::fromUtf8("pushButton_max"));
        pushButton_max->setMinimumSize(QSize(0, 16));
        pushButton_max->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/max-min_first.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	background-image: url(:/images/max-min_after.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_max);

        pushButton_close = new QPushButton(Widget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
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

        horizontalLayout_3->addWidget(pushButton_close);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border:none;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(30, 0, -1, -1);
        toolButton_newStream = new QToolButton(groupBox_2);
        toolButton_newStream->setObjectName(QString::fromUtf8("toolButton_newStream"));
        toolButton_newStream->setMinimumSize(QSize(68, 60));
        toolButton_newStream->setMaximumSize(QSize(68, 60));
        toolButton_newStream->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	background-image:url(:/images/newStream_first.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	background-image:url(:/images/newStream_second.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}"));

        horizontalLayout_2->addWidget(toolButton_newStream);

        pushButton_email = new QPushButton(groupBox_2);
        pushButton_email->setObjectName(QString::fromUtf8("pushButton_email"));
        pushButton_email->setMinimumSize(QSize(68, 60));
        pushButton_email->setMaximumSize(QSize(68, 60));
        pushButton_email->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/images/EmailImage/Email.png);}\n"
"QPushButton:hover{border-image: url(:/images/EmailImage/Email_hover.png);}\n"
"\n"
""));

        horizontalLayout_2->addWidget(pushButton_email);

        pushButton_leaveMsg = new QPushButton(groupBox_2);
        pushButton_leaveMsg->setObjectName(QString::fromUtf8("pushButton_leaveMsg"));
        pushButton_leaveMsg->setMinimumSize(QSize(68, 60));
        pushButton_leaveMsg->setMaximumSize(QSize(68, 60));
        pushButton_leaveMsg->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{border-image: url(:/images/leaveMsgPics/leaveMsg.png);}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border-image: url(:/images/leaveMsgPics/leaveMsg-hover.png);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_leaveMsg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(199, 16777215));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border:none;\n"
"}"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 30, 15, -1);
        toolBtn_jb = new QToolButton(groupBox_3);
        toolBtn_jb->setObjectName(QString::fromUtf8("toolBtn_jb"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBtn_jb->sizePolicy().hasHeightForWidth());
        toolBtn_jb->setSizePolicy(sizePolicy);
        toolBtn_jb->setMinimumSize(QSize(170, 35));
        toolBtn_jb->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	\n"
"	background-image: url(:/images/\345\212\240\347\217\2551.jpg);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	\n"
"	background-image: url(:/images/\345\212\240\347\217\2552.jpg);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:checked\n"
"{\n"
"	\n"
"	background-image: url(:/images/\345\212\240\347\217\2553.jpg);\n"
"	background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}"));
        toolBtn_jb->setCheckable(true);

        verticalLayout_4->addWidget(toolBtn_jb);

        toolBtn_qj = new QToolButton(groupBox_3);
        toolBtn_qj->setObjectName(QString::fromUtf8("toolBtn_qj"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBtn_qj->sizePolicy().hasHeightForWidth());
        toolBtn_qj->setSizePolicy(sizePolicy1);
        toolBtn_qj->setMinimumSize(QSize(170, 35));
        toolBtn_qj->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\350\257\267\345\201\2071.jpg);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\350\257\267\345\201\2072.jpg);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:checked\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\350\257\267\345\201\2073.jpg);\n"
"	background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}"));
        toolBtn_qj->setCheckable(true);

        verticalLayout_4->addWidget(toolBtn_qj);

        toolBtn_wdk = new QToolButton(groupBox_3);
        toolBtn_wdk->setObjectName(QString::fromUtf8("toolBtn_wdk"));
        sizePolicy1.setHeightForWidth(toolBtn_wdk->sizePolicy().hasHeightForWidth());
        toolBtn_wdk->setSizePolicy(sizePolicy1);
        toolBtn_wdk->setMinimumSize(QSize(170, 35));
        toolBtn_wdk->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\277\230\346\211\223\345\215\2411.jpg);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\277\230\346\211\223\345\215\2412.jpg);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:checked\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\277\230\346\211\223\345\215\2413.jpg);\n"
"	background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
""));
        toolBtn_wdk->setCheckable(true);

        verticalLayout_4->addWidget(toolBtn_wdk);

        pushButton_chuChai = new QPushButton(groupBox_3);
        pushButton_chuChai->setObjectName(QString::fromUtf8("pushButton_chuChai"));
        pushButton_chuChai->setMinimumSize(QSize(175, 35));
        pushButton_chuChai->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\207\272\345\267\2561.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\207\272\345\267\2562.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\207\272\345\267\2563.png);\n"
"	background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}"));
        pushButton_chuChai->setCheckable(true);

        verticalLayout_4->addWidget(pushButton_chuChai);

        pushButton_waiChu = new QPushButton(groupBox_3);
        pushButton_waiChu->setObjectName(QString::fromUtf8("pushButton_waiChu"));
        pushButton_waiChu->setMinimumSize(QSize(175, 35));
        pushButton_waiChu->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\244\226\345\207\2721.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\244\226\345\207\2722.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\345\244\226\345\207\2723.png);\n"
"	background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}"));
        pushButton_waiChu->setCheckable(true);

        verticalLayout_4->addWidget(pushButton_waiChu);

        toolBtn_cg = new QToolButton(groupBox_3);
        toolBtn_cg->setObjectName(QString::fromUtf8("toolBtn_cg"));
        sizePolicy1.setHeightForWidth(toolBtn_cg->sizePolicy().hasHeightForWidth());
        toolBtn_cg->setSizePolicy(sizePolicy1);
        toolBtn_cg->setMinimumSize(QSize(170, 35));
        toolBtn_cg->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"	\n"
"	background-image: url(:/images/\351\207\207\350\264\2551.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	\n"
"	\n"
"	background-image: url(:/images/\351\207\207\350\264\2552.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}\n"
"QToolButton:checked\n"
"{	\n"
"	background-image: url(:/images/\351\207\207\350\264\2552.png);\n"
"    background-repeat:no-repeat;\n"
"    background-position:center center;\n"
"	border:none;\n"
"}"));
        toolBtn_cg->setCheckable(true);

        verticalLayout_4->addWidget(toolBtn_cg);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(221, 245, 255);"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, 0);
        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout->addWidget(tableWidget);


        horizontalLayout->addWidget(groupBox);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(199, 16777215));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border:none;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        toolBtn_dcl = new MyToolBtn(groupBox_4);
        toolBtn_dcl->setObjectName(QString::fromUtf8("toolBtn_dcl"));
        toolBtn_dcl->setMinimumSize(QSize(65, 75));
        toolBtn_dcl->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	background-image: url(:/images/\345\276\205\345\244\204\347\220\206.jpg);\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolBtn_dcl);

        toolBtn_kqhz = new MyToolBtn(groupBox_4);
        toolBtn_kqhz->setObjectName(QString::fromUtf8("toolBtn_kqhz"));
        toolBtn_kqhz->setMinimumSize(QSize(65, 75));
        toolBtn_kqhz->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	\n"
"	background-image: url(:/images/\350\200\203\345\213\244\346\261\207\346\200\273.png);\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolBtn_kqhz);

        toolBtn_cgjh = new MyToolBtn(groupBox_4);
        toolBtn_cgjh->setObjectName(QString::fromUtf8("toolBtn_cgjh"));
        toolBtn_cgjh->setMinimumSize(QSize(65, 75));
        toolBtn_cgjh->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	\n"
"	background-image: url(:/images/BOM.png);\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolBtn_cgjh);

        toolBtn_spkc = new MyToolBtn(groupBox_4);
        toolBtn_spkc->setObjectName(QString::fromUtf8("toolBtn_spkc"));
        toolBtn_spkc->setMinimumSize(QSize(65, 75));
        toolBtn_spkc->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	\n"
"	background-image: url(:/images/\345\225\206\345\223\201\345\272\223\345\255\230.png);\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolBtn_spkc);

        toolBtn_ygsz = new MyToolBtn(groupBox_4);
        toolBtn_ygsz->setObjectName(QString::fromUtf8("toolBtn_ygsz"));
        toolBtn_ygsz->setMinimumSize(QSize(65, 75));
        toolBtn_ygsz->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	\n"
"	background-image: url(:/images/\345\221\230\345\267\245\350\256\276\347\275\256.png);\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolBtn_ygsz);

        toolBtn_tybh = new MyToolBtn(groupBox_4);
        toolBtn_tybh->setObjectName(QString::fromUtf8("toolBtn_tybh"));
        toolBtn_tybh->setMinimumSize(QSize(65, 75));
        toolBtn_tybh->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	\n"
"	background-image: url(:/images/\345\233\276\346\240\267\347\274\226\345\217\267.png);\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolBtn_tybh);

        toolButton_daka = new MyToolBtn(groupBox_4);
        toolButton_daka->setObjectName(QString::fromUtf8("toolButton_daka"));
        toolButton_daka->setMinimumSize(QSize(65, 75));
        toolButton_daka->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	\n"
"	background-image: url(:/images/\344\270\212\347\217\255\346\211\223\345\215\241\350\256\260\345\275\225.png);\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolButton_daka);

        toolButton_weekReport = new MyToolBtn(groupBox_4);
        toolButton_weekReport->setObjectName(QString::fromUtf8("toolButton_weekReport"));
        toolButton_weekReport->setMinimumSize(QSize(65, 75));
        toolButton_weekReport->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{	\n"
"	\n"
"	background-image: url(:/images/\344\270\252\344\272\272\345\221\250\346\212\245.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"	border:none;\n"
"}"));

        verticalLayout_5->addWidget(toolButton_weekReport);


        horizontalLayout_5->addLayout(verticalLayout_5);

        horizontalSpacer_6 = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        horizontalLayout->addWidget(groupBox_4);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 10);
        horizontalLayout->setStretch(2, 3);

        verticalLayout_2->addLayout(horizontalLayout);

        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border:none;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_5);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 15, -1, 0);
        horizontalSpacer_3 = new QSpacerItem(180, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_userName = new QLabel(groupBox_5);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));

        horizontalLayout_4->addWidget(label_userName);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_quitAutoRun = new QPushButton(groupBox_5);
        pushButton_quitAutoRun->setObjectName(QString::fromUtf8("pushButton_quitAutoRun"));
        pushButton_quitAutoRun->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_quitAutoRun\n"
"{\n"
"	color:rgb(38 , 133 , 227);\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"QPushButton#pushButton_quitAutoRun:hover\n"
"{\n"
"	color:rgb(97 , 179 , 246);\n"
"}\n"
"\n"
"QPushButton#pushButton_quitAutoRun:pressed\n"
"{\n"
"	color:rgb(0 , 109 , 176);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_quitAutoRun);

        horizontalSpacer_4 = new QSpacerItem(174, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_help = new QPushButton(groupBox_5);
        pushButton_help->setObjectName(QString::fromUtf8("pushButton_help"));
        pushButton_help->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_help\n"
"{\n"
"	color:rgb(38 , 133 , 227);\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"QPushButton#pushButton_help:hover\n"
"{\n"
"	color:rgb(97 , 179 , 246);\n"
"}\n"
"\n"
"QPushButton#pushButton_help:pressed\n"
"{\n"
"	color:rgb(0 , 109 , 176);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_help);

        horizontalSpacer_5 = new QSpacerItem(173, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pushButton_haveFun = new QPushButton(groupBox_5);
        pushButton_haveFun->setObjectName(QString::fromUtf8("pushButton_haveFun"));
        pushButton_haveFun->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_haveFun\n"
"{\n"
"	color:rgb(38 , 133 , 227);\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"QPushButton#pushButton_haveFun:hover\n"
"{\n"
"	color:rgb(97 , 179 , 246);\n"
"}\n"
"\n"
"QPushButton#pushButton_haveFun:pressed\n"
"{\n"
"	color:rgb(0 , 109 , 176);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_haveFun);


        verticalLayout_2->addWidget(groupBox_5);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 20);
        verticalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton_min->setText(QString());
        pushButton_max->setText(QString());
        pushButton_close->setText(QString());
        groupBox_2->setTitle(QString());
        toolButton_newStream->setText(QString());
        pushButton_email->setText(QString());
        pushButton_leaveMsg->setText(QString());
        groupBox_3->setTitle(QString());
        toolBtn_jb->setText(QString());
        toolBtn_qj->setText(QString());
        toolBtn_wdk->setText(QString());
        pushButton_chuChai->setText(QString());
        pushButton_waiChu->setText(QString());
        toolBtn_cg->setText(QString());
        groupBox->setTitle(QApplication::translate("Widget", "\347\224\265\345\255\220\346\265\201\346\230\276\347\244\272\345\214\272", nullptr));
        groupBox_4->setTitle(QString());
        toolBtn_dcl->setText(QString());
        toolBtn_kqhz->setText(QString());
        toolBtn_cgjh->setText(QString());
        toolBtn_spkc->setText(QString());
        toolBtn_ygsz->setText(QString());
        toolBtn_tybh->setText(QString());
        toolButton_daka->setText(QString());
        toolButton_weekReport->setText(QString());
        groupBox_5->setTitle(QString());
        label_userName->setText(QApplication::translate("Widget", "\345\220\264\350\203\234\345\205\265", nullptr));
        pushButton_quitAutoRun->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        pushButton_help->setText(QApplication::translate("Widget", "\344\275\277\347\224\250\346\211\213\345\206\214", nullptr));
        pushButton_haveFun->setText(QApplication::translate("Widget", "Have Fun", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
