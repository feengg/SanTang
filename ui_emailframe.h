/********************************************************************************
** Form generated from reading UI file 'emailframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILFRAME_H
#define UI_EMAILFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmailFrame
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_skin;
    QSlider *horizontalSlider_opacity;
    QPushButton *pushButton_tr;
    QPushButton *pushButton_min;
    QPushButton *pushButton_max;
    QPushButton *pushButton_close;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_recvBox;
    QPushButton *pushButton_sentBox;
    QPushButton *pushButton_write;
    QPushButton *pushButton_look;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_main;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_recv;
    QHBoxLayout *horizontalLayout_recvDelete;
    QPushButton *pushButton_deleteRecv;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea_sentBox;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_sent;
    QHBoxLayout *horizontalLayout_sentDelete;
    QPushButton *pushButton_deleteSent;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_recver;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_recver;
    QPushButton *pushButton_addRecver;
    QLabel *label_under;
    QGridLayout *gridLayout_copy;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_copy;
    QPushButton *pushButton_addCopy;
    QLabel *label_copyUnder;
    QGridLayout *gridLayout_topic;
    QLabel *label_topic;
    QLabel *label_topicUnder;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_appendix;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_appendixPath;
    QPushButton *pushButton_delAppendix;
    QSpacerItem *horizontalSpacer_11;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_backGround;
    QPushButton *pushButton_bold;
    QPushButton *pushButton_italic;
    QPushButton *pushButton_underLine;
    QPushButton *pushButton_textLeft;
    QPushButton *pushButton_textCenter;
    QPushButton *pushButton_textRight;
    QPushButton *pushButton_insertPic;
    QPushButton *pushButton_dayTime;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox_fontSize;
    QComboBox *comboBox_fontColor;
    QComboBox *comboBox_fontBackColor;
    QComboBox *comboBox_orderList;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_15;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_emailSend;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_recver_3;
    QSpacerItem *horizontalSpacer_24;
    QLabel *label_recver_look_2;
    QLabel *label_under_3;
    QLineEdit *lineEdit_send_look;
    QGridLayout *gridLayout_recver_2;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_recver_look;
    QLabel *label_under_2;
    QLineEdit *lineEdit_recv_look;
    QGridLayout *gridLayout_recver_6;
    QSpacerItem *horizontalSpacer_25;
    QLabel *label_recver_look_3;
    QLabel *label_under_6;
    QLineEdit *lineEdit_copy_look;
    QGridLayout *gridLayout_topic_2;
    QLabel *label_topic_look;
    QLabel *label_topicUnder_2;
    QSpacerItem *horizontalSpacer_23;
    QLineEdit *lineEdit_topic_look;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_16;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEdit_dealTime_look;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pushButton_appendix_look;
    QPushButton *pushButton_appendixPath_look;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pushButton_downAppendix;
    QSpacerItem *horizontalSpacer_22;
    QPushButton *pushButton_reply;
    QLabel *label_4;
    QGroupBox *groupBox_look;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_17;
    QTextEdit *textEdit_look;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *EmailFrame)
    {
        if (EmailFrame->objectName().isEmpty())
            EmailFrame->setObjectName(QString::fromUtf8("EmailFrame"));
        EmailFrame->resize(1300, 881);
        verticalLayout_3 = new QVBoxLayout(EmailFrame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 10);
        label = new QLabel(EmailFrame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_skin = new QPushButton(EmailFrame);
        pushButton_skin->setObjectName(QString::fromUtf8("pushButton_skin"));
        pushButton_skin->setMinimumSize(QSize(32, 32));
        pushButton_skin->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_skin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/EmailImage/face.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"color:transparent;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"background-image: url(:/images/EmailImage/face-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:pressed{\n"
" background-image: url(:/images/EmailImage/face.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_skin);

        horizontalSlider_opacity = new QSlider(EmailFrame);
        horizontalSlider_opacity->setObjectName(QString::fromUtf8("horizontalSlider_opacity"));
        horizontalSlider_opacity->setMinimumSize(QSize(160, 0));
        horizontalSlider_opacity->setMaximumSize(QSize(160, 16777215));
        horizontalSlider_opacity->setStyleSheet(QString::fromUtf8("QHorizontalSlider\n"
"{\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
"QHorizontalSlider:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QHorizontalSlider:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}"));
        horizontalSlider_opacity->setMinimum(70);
        horizontalSlider_opacity->setMaximum(100);
        horizontalSlider_opacity->setSingleStep(5);
        horizontalSlider_opacity->setPageStep(0);
        horizontalSlider_opacity->setValue(95);
        horizontalSlider_opacity->setOrientation(Qt::Horizontal);
        horizontalSlider_opacity->setTickInterval(0);

        horizontalLayout->addWidget(horizontalSlider_opacity);

        pushButton_tr = new QPushButton(EmailFrame);
        pushButton_tr->setObjectName(QString::fromUtf8("pushButton_tr"));
        pushButton_tr->setMinimumSize(QSize(32, 32));
        pushButton_tr->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_tr->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/EmailImage/tr.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_tr);

        pushButton_min = new QPushButton(EmailFrame);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setMinimumSize(QSize(32, 32));
        pushButton_min->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_min->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/EmailImage/min.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_min);

        pushButton_max = new QPushButton(EmailFrame);
        pushButton_max->setObjectName(QString::fromUtf8("pushButton_max"));
        pushButton_max->setMinimumSize(QSize(32, 32));
        pushButton_max->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/EmailImage/max.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_max);

        pushButton_close = new QPushButton(EmailFrame);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(32, 32));
        pushButton_close->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/images/EmailImage/quit.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"background-color: rgba(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout_3->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButton_recvBox = new QPushButton(EmailFrame);
        pushButton_recvBox->setObjectName(QString::fromUtf8("pushButton_recvBox"));
        pushButton_recvBox->setMinimumSize(QSize(100, 35));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_recvBox->setFont(font1);
        pushButton_recvBox->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_recvBox\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_recvBox:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_recvBox:checked\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
""));
        pushButton_recvBox->setCheckable(true);

        gridLayout->addWidget(pushButton_recvBox, 0, 1, 1, 1);

        pushButton_sentBox = new QPushButton(EmailFrame);
        pushButton_sentBox->setObjectName(QString::fromUtf8("pushButton_sentBox"));
        pushButton_sentBox->setMinimumSize(QSize(100, 35));
        pushButton_sentBox->setFont(font1);
        pushButton_sentBox->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_sentBox\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_sentBox:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_sentBox:checked\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));
        pushButton_sentBox->setCheckable(true);

        gridLayout->addWidget(pushButton_sentBox, 0, 2, 1, 1);

        pushButton_write = new QPushButton(EmailFrame);
        pushButton_write->setObjectName(QString::fromUtf8("pushButton_write"));
        pushButton_write->setMinimumSize(QSize(100, 35));
        pushButton_write->setFont(font1);
        pushButton_write->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_write\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_write:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_write:checked\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));
        pushButton_write->setCheckable(true);

        gridLayout->addWidget(pushButton_write, 0, 3, 1, 1);

        pushButton_look = new QPushButton(EmailFrame);
        pushButton_look->setObjectName(QString::fromUtf8("pushButton_look"));
        pushButton_look->setMinimumSize(QSize(100, 35));
        pushButton_look->setFont(font1);
        pushButton_look->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_look\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_look:hover\n"
"{\n"
"    color:black;\n"
"    background-color:rgb(228 , 240 , 250);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_look:checked\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));
        pushButton_look->setCheckable(true);

        gridLayout->addWidget(pushButton_look, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        label_main = new QLabel(EmailFrame);
        label_main->setObjectName(QString::fromUtf8("label_main"));
        label_main->setMaximumSize(QSize(16777215, 2));
        label_main->setStyleSheet(QString::fromUtf8("background-color:rgb(14 , 150 , 254);"));

        gridLayout->addWidget(label_main, 1, 0, 1, 6);


        verticalLayout_3->addLayout(gridLayout);

        tabWidget = new QTabWidget(EmailFrame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_8 = new QVBoxLayout(tab);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1239, 900));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 900));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);"));
        verticalLayout_recv = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_recv->setSpacing(2);
        verticalLayout_recv->setObjectName(QString::fromUtf8("verticalLayout_recv"));
        verticalLayout_recv->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_recvDelete = new QHBoxLayout();
        horizontalLayout_recvDelete->setObjectName(QString::fromUtf8("horizontalLayout_recvDelete"));
        horizontalLayout_recvDelete->setContentsMargins(-1, -1, -1, 10);
        pushButton_deleteRecv = new QPushButton(scrollAreaWidgetContents);
        pushButton_deleteRecv->setObjectName(QString::fromUtf8("pushButton_deleteRecv"));
        pushButton_deleteRecv->setMinimumSize(QSize(72, 26));
        pushButton_deleteRecv->setMaximumSize(QSize(72, 26));
        pushButton_deleteRecv->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_deleteRecv\n"
"{\n"
"    color:blue;\n"
"    background-color:rgb(238 , 238 , 238,100);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_deleteRecv:hover\n"
"{\n"
"    color:white;\n"
"    \n"
"	background-color: rgb(171, 223, 255,100);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_deleteRecv:pressed\n"
"{\n"
"    color:white;	\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));

        horizontalLayout_recvDelete->addWidget(pushButton_deleteRecv);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_recvDelete->addItem(horizontalSpacer_6);


        verticalLayout_recv->addLayout(horizontalLayout_recvDelete);

        verticalSpacer_3 = new QSpacerItem(20, 858, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_recv->addItem(verticalSpacer_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_8->addWidget(scrollArea);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea_sentBox = new QScrollArea(tab_2);
        scrollArea_sentBox->setObjectName(QString::fromUtf8("scrollArea_sentBox"));
        scrollArea_sentBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);"));
        scrollArea_sentBox->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1239, 900));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(0, 900));
        scrollAreaWidgetContents_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);"));
        verticalLayout_sent = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_sent->setSpacing(2);
        verticalLayout_sent->setObjectName(QString::fromUtf8("verticalLayout_sent"));
        verticalLayout_sent->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_sentDelete = new QHBoxLayout();
        horizontalLayout_sentDelete->setObjectName(QString::fromUtf8("horizontalLayout_sentDelete"));
        horizontalLayout_sentDelete->setContentsMargins(-1, -1, -1, 10);
        pushButton_deleteSent = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_deleteSent->setObjectName(QString::fromUtf8("pushButton_deleteSent"));
        pushButton_deleteSent->setMinimumSize(QSize(72, 26));
        pushButton_deleteSent->setMaximumSize(QSize(72, 26));
        pushButton_deleteSent->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_deleteSent\n"
"{\n"
"    color:blue;\n"
"    background-color:rgb(238 , 238 , 238,100);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_deleteSent:hover\n"
"{\n"
"    color:white;\n"
"    \n"
"	background-color: rgb(171, 223, 255,100);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_deleteSent:pressed\n"
"{\n"
"    color:white;	\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));

        horizontalLayout_sentDelete->addWidget(pushButton_deleteSent);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_sentDelete->addItem(horizontalSpacer_9);


        verticalLayout_sent->addLayout(horizontalLayout_sentDelete);

        verticalSpacer_4 = new QSpacerItem(20, 840, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_sent->addItem(verticalSpacer_4);

        scrollArea_sentBox->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_4->addWidget(scrollArea_sentBox);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_recver = new QGridLayout();
        gridLayout_recver->setSpacing(0);
        gridLayout_recver->setObjectName(QString::fromUtf8("gridLayout_recver"));
        horizontalSpacer_5 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_recver->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        label_recver = new QLabel(tab_3);
        label_recver->setObjectName(QString::fromUtf8("label_recver"));
        label_recver->setMinimumSize(QSize(0, 35));
        QFont font2;
        font2.setPointSize(10);
        label_recver->setFont(font2);

        gridLayout_recver->addWidget(label_recver, 0, 1, 1, 1);

        pushButton_addRecver = new QPushButton(tab_3);
        pushButton_addRecver->setObjectName(QString::fromUtf8("pushButton_addRecver"));
        pushButton_addRecver->setMaximumSize(QSize(25, 25));
        pushButton_addRecver->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_addRecver\n"
"{\n"
"	border-image: url(:/images/EmailImage/add.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_addRecver:hover\n"
"{\n"
"	border-image: url(:/images/EmailImage/add-hover.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_addRecver:pressed\n"
"{\n"
"	border-image: url(:/images/EmailImage/add.png);\n"
"}"));

        gridLayout_recver->addWidget(pushButton_addRecver, 0, 2, 1, 1);

        label_under = new QLabel(tab_3);
        label_under->setObjectName(QString::fromUtf8("label_under"));
        label_under->setMaximumSize(QSize(16777215, 1));
        label_under->setStyleSheet(QString::fromUtf8("background-color: rgb(159, 159, 159);"));

        gridLayout_recver->addWidget(label_under, 1, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout_recver);

        gridLayout_copy = new QGridLayout();
        gridLayout_copy->setSpacing(0);
        gridLayout_copy->setObjectName(QString::fromUtf8("gridLayout_copy"));
        horizontalSpacer_19 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_copy->addItem(horizontalSpacer_19, 0, 0, 1, 1);

        label_copy = new QLabel(tab_3);
        label_copy->setObjectName(QString::fromUtf8("label_copy"));
        label_copy->setMinimumSize(QSize(0, 35));
        label_copy->setFont(font2);

        gridLayout_copy->addWidget(label_copy, 0, 1, 1, 1);

        pushButton_addCopy = new QPushButton(tab_3);
        pushButton_addCopy->setObjectName(QString::fromUtf8("pushButton_addCopy"));
        pushButton_addCopy->setMaximumSize(QSize(25, 25));
        pushButton_addCopy->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_addCopy\n"
"{\n"
"	border-image: url(:/images/EmailImage/add.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_addCopy:hover\n"
"{\n"
"	border-image: url(:/images/EmailImage/add-hover.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_addCopy:pressed\n"
"{\n"
"	border-image: url(:/images/EmailImage/add.png);\n"
"}"));

        gridLayout_copy->addWidget(pushButton_addCopy, 0, 2, 1, 1);

        label_copyUnder = new QLabel(tab_3);
        label_copyUnder->setObjectName(QString::fromUtf8("label_copyUnder"));
        label_copyUnder->setMaximumSize(QSize(16777215, 1));
        label_copyUnder->setStyleSheet(QString::fromUtf8("background-color: rgb(159, 159, 159);"));

        gridLayout_copy->addWidget(label_copyUnder, 1, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout_copy);

        gridLayout_topic = new QGridLayout();
        gridLayout_topic->setSpacing(0);
        gridLayout_topic->setObjectName(QString::fromUtf8("gridLayout_topic"));
        label_topic = new QLabel(tab_3);
        label_topic->setObjectName(QString::fromUtf8("label_topic"));
        label_topic->setMinimumSize(QSize(0, 35));
        label_topic->setFont(font2);

        gridLayout_topic->addWidget(label_topic, 0, 1, 1, 1);

        label_topicUnder = new QLabel(tab_3);
        label_topicUnder->setObjectName(QString::fromUtf8("label_topicUnder"));
        label_topicUnder->setMaximumSize(QSize(16777215, 1));
        label_topicUnder->setStyleSheet(QString::fromUtf8("background-color: rgb(159, 159, 159);"));

        gridLayout_topic->addWidget(label_topicUnder, 1, 1, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_topic->addItem(horizontalSpacer_8, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_topic);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_10 = new QSpacerItem(45, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        pushButton_appendix = new QPushButton(tab_3);
        pushButton_appendix->setObjectName(QString::fromUtf8("pushButton_appendix"));
        pushButton_appendix->setMinimumSize(QSize(70, 22));
        pushButton_appendix->setMaximumSize(QSize(70, 22));
        pushButton_appendix->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_appendix\n"
"{\n"
"	border-image: url(:/images/EmailImage/appendix.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_appendix:hover\n"
"{\n"
"	border-image: url(:/images/EmailImage/appendix_pressed.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_appendix:pressed\n"
"{\n"
"	border-image: url(:/images/EmailImage/appendix_pressed.png);\n"
"}\n"
"	\n"
"	"));

        horizontalLayout_3->addWidget(pushButton_appendix);

        horizontalSpacer_12 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        pushButton_appendixPath = new QPushButton(tab_3);
        pushButton_appendixPath->setObjectName(QString::fromUtf8("pushButton_appendixPath"));
        pushButton_appendixPath->setMinimumSize(QSize(0, 22));
        pushButton_appendixPath->setFont(font2);
        pushButton_appendixPath->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_appendixPath\n"
"{\n"
"    color:green;\n"
"    background-color:rgb(238 , 238 , 238,0);\n"
"    border: 0px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_appendixPath:hover\n"
"{\n"
"    color:white;\n"
"    \n"
"	background-color: rgb(221, 245, 255);\n"
"    border: 0px solid rgb(15 , 150 , 255);\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_appendixPath);

        pushButton_delAppendix = new QPushButton(tab_3);
        pushButton_delAppendix->setObjectName(QString::fromUtf8("pushButton_delAppendix"));
        pushButton_delAppendix->setMinimumSize(QSize(30, 22));
        pushButton_delAppendix->setMaximumSize(QSize(30, 16777215));
        QFont font3;
        font3.setPointSize(9);
        pushButton_delAppendix->setFont(font3);
        pushButton_delAppendix->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_delAppendix\n"
"{\n"
"    color:red;\n"
"    background-color:rgb(238 , 238 , 238,0);\n"
"    border: 0px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_delAppendix:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(255 , 0 , 0);\n"
"    border: 0px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_delAppendix:pressed\n"
"{\n"
"    color:white;	\n"
"	background-color: rgb(19, 42, 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_delAppendix);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox#groupBox\n"
"{\n"
"	border:0px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_14);

        pushButton_backGround = new QPushButton(groupBox);
        pushButton_backGround->setObjectName(QString::fromUtf8("pushButton_backGround"));
        pushButton_backGround->setMinimumSize(QSize(27, 26));
        pushButton_backGround->setMaximumSize(QSize(27, 26));
        pushButton_backGround->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{	\n"
"	border-image: url(:/images/EmailImage/backPic.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{	\n"
"	\n"
"	border-image: url(:/images/EmailImage/backPic-hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	\n"
"	border-image: url(:/images/EmailImage/backPic-pressed.png);\n"
"}"));
        pushButton_backGround->setCheckable(false);

        horizontalLayout_4->addWidget(pushButton_backGround);

        pushButton_bold = new QPushButton(groupBox);
        pushButton_bold->setObjectName(QString::fromUtf8("pushButton_bold"));
        pushButton_bold->setMinimumSize(QSize(27, 26));
        pushButton_bold->setMaximumSize(QSize(27, 26));
        pushButton_bold->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image: url(:/images/EmailImage/bold.png);	\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"	\n"
"	border-image: url(:/images/EmailImage/bold-checked.png);\n"
"}"));
        pushButton_bold->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_bold);

        pushButton_italic = new QPushButton(groupBox);
        pushButton_italic->setObjectName(QString::fromUtf8("pushButton_italic"));
        pushButton_italic->setMinimumSize(QSize(27, 26));
        pushButton_italic->setMaximumSize(QSize(27, 26));
        pushButton_italic->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	border-image: url(:/images/EmailImage/xt.png);	\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"	\n"
"	\n"
"	border-image: url(:/images/EmailImage/xt-checked.png);\n"
"}"));
        pushButton_italic->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_italic);

        pushButton_underLine = new QPushButton(groupBox);
        pushButton_underLine->setObjectName(QString::fromUtf8("pushButton_underLine"));
        pushButton_underLine->setMinimumSize(QSize(27, 26));
        pushButton_underLine->setMaximumSize(QSize(27, 26));
        pushButton_underLine->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-image: url(:/images/EmailImage/underline.png);\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"border-image: url(:/images/EmailImage/underline-checked.png);\n"
"}\n"
""));
        pushButton_underLine->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_underLine);

        pushButton_textLeft = new QPushButton(groupBox);
        pushButton_textLeft->setObjectName(QString::fromUtf8("pushButton_textLeft"));
        pushButton_textLeft->setMinimumSize(QSize(27, 26));
        pushButton_textLeft->setMaximumSize(QSize(27, 26));
        pushButton_textLeft->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"border-image: url(:/images/EmailImage/textleft.png);\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"border-image: url(:/images/EmailImage/textleft-checked.png)\n"
"}\n"
""));
        pushButton_textLeft->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_textLeft);

        pushButton_textCenter = new QPushButton(groupBox);
        pushButton_textCenter->setObjectName(QString::fromUtf8("pushButton_textCenter"));
        pushButton_textCenter->setMinimumSize(QSize(27, 26));
        pushButton_textCenter->setMaximumSize(QSize(27, 26));
        pushButton_textCenter->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"border-image: url(:/images/EmailImage/textcenter.png);\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"border-image: url(:/images/EmailImage/textcenter-checked.png);\n"
"}\n"
""));
        pushButton_textCenter->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_textCenter);

        pushButton_textRight = new QPushButton(groupBox);
        pushButton_textRight->setObjectName(QString::fromUtf8("pushButton_textRight"));
        pushButton_textRight->setMinimumSize(QSize(27, 26));
        pushButton_textRight->setMaximumSize(QSize(27, 26));
        pushButton_textRight->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"border-image: url(:/images/EmailImage/textright.png);\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"border-image: url(:/images/EmailImage/textright-checked.png);\n"
"}\n"
""));
        pushButton_textRight->setCheckable(true);

        horizontalLayout_4->addWidget(pushButton_textRight);

        pushButton_insertPic = new QPushButton(groupBox);
        pushButton_insertPic->setObjectName(QString::fromUtf8("pushButton_insertPic"));
        pushButton_insertPic->setMinimumSize(QSize(27, 26));
        pushButton_insertPic->setMaximumSize(QSize(27, 26));
        pushButton_insertPic->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{	\n"
"	border-image: url(:/images/EmailImage/insertPic.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{	\n"
"	\n"
"	border-image: url(:/images/EmailImage/insertPic-hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	\n"
"	border-image: url(:/images/EmailImage/insertPic-pressed.png);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_insertPic);

        pushButton_dayTime = new QPushButton(groupBox);
        pushButton_dayTime->setObjectName(QString::fromUtf8("pushButton_dayTime"));
        pushButton_dayTime->setMinimumSize(QSize(27, 26));
        pushButton_dayTime->setMaximumSize(QSize(27, 26));
        pushButton_dayTime->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{	\n"
"	border-image: url(:/images/EmailImage/daytime.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{	\n"
"	\n"
"	border-image: url(:/images/EmailImage/daytime-hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	\n"
"	border-image: url(:/images/EmailImage/daytime-pressed.png);\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_dayTime);

        fontComboBox = new QFontComboBox(groupBox);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setMinimumSize(QSize(0, 26));
        fontComboBox->setMaximumSize(QSize(150, 16777215));
        fontComboBox->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border:0px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox:hover\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"}\n"
"\n"
"QComboBox:pressed\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(255, 251, 194);\n"
"}\n"
"QComboBox:drop-down\n"
"{\n"
"	border-style:none;\n"
"}"));
        fontComboBox->setEditable(false);

        horizontalLayout_4->addWidget(fontComboBox);

        comboBox_fontSize = new QComboBox(groupBox);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/EmailImage/\351\273\230\350\256\244\345\244\247\345\260\21714px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/EmailImage/\346\236\201\345\260\21710px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/EmailImage/\347\211\271\346\200\24712px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/EmailImage/\345\260\21716px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/EmailImage/\344\270\25518px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon4, QString());
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/EmailImage/\345\244\24724px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/EmailImage/\347\211\271\345\244\24736px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/EmailImage/\346\236\201\345\244\24748px.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_fontSize->addItem(icon7, QString());
        comboBox_fontSize->setObjectName(QString::fromUtf8("comboBox_fontSize"));
        comboBox_fontSize->setMinimumSize(QSize(129, 26));
        comboBox_fontSize->setMaximumSize(QSize(150, 26));
        comboBox_fontSize->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border:0px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox:hover\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"}\n"
"\n"
"QComboBox:pressed\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(255, 251, 194);\n"
"}\n"
"QComboBox:drop-down\n"
"{\n"
"	border-style:none;\n"
"}"));
        comboBox_fontSize->setIconSize(QSize(129, 63));

        horizontalLayout_4->addWidget(comboBox_fontSize);

        comboBox_fontColor = new QComboBox(groupBox);
        comboBox_fontColor->setObjectName(QString::fromUtf8("comboBox_fontColor"));
        comboBox_fontColor->setMinimumSize(QSize(0, 26));
        comboBox_fontColor->setMaximumSize(QSize(90, 16777215));
        comboBox_fontColor->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border:0px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox:hover\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"}\n"
"\n"
"QComboBox:pressed\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(255, 251, 194);\n"
"}\n"
"QComboBox:drop-down\n"
"{\n"
"	border-style:none;\n"
"}"));

        horizontalLayout_4->addWidget(comboBox_fontColor);

        comboBox_fontBackColor = new QComboBox(groupBox);
        comboBox_fontBackColor->setObjectName(QString::fromUtf8("comboBox_fontBackColor"));
        comboBox_fontBackColor->setMinimumSize(QSize(0, 26));
        comboBox_fontBackColor->setMaximumSize(QSize(90, 16777215));
        comboBox_fontBackColor->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border:0px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox:hover\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"}\n"
"\n"
"QComboBox:pressed\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(255, 251, 194);\n"
"}\n"
"QComboBox:drop-down\n"
"{\n"
"	border-style:none;\n"
"}"));

        horizontalLayout_4->addWidget(comboBox_fontBackColor);

        comboBox_orderList = new QComboBox(groupBox);
        comboBox_orderList->addItem(QString());
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/EmailImage/disc.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/EmailImage/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon9, QString());
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/EmailImage/square.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon10, QString());
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/EmailImage/decimal.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon11, QString());
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/EmailImage/roman.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon12, QString());
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/EmailImage/roman_upper.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon13, QString());
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/EmailImage/alpha.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon14, QString());
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/EmailImage/alpha_upper.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox_orderList->addItem(icon15, QString());
        comboBox_orderList->setObjectName(QString::fromUtf8("comboBox_orderList"));
        comboBox_orderList->setMinimumSize(QSize(0, 26));
        comboBox_orderList->setMaximumSize(QSize(40, 30));
        comboBox_orderList->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border:0px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox:hover\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"}\n"
"\n"
"QComboBox:pressed\n"
"{\n"
"	border:1px;\n"
"	\n"
"	background-color: rgb(255, 251, 194);\n"
"}\n"
"QComboBox:drop-down\n"
"{\n"
"	border-style:none;\n"
"}"));

        horizontalLayout_4->addWidget(comboBox_orderList);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit\n"
"{\n"
"	border:0px;\n"
"	\n"
"	border-image: url(:/images/EmailImage/textBackGround/34.png);\n"
"}\n"
""));

        horizontalLayout_5->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(55, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        pushButton_emailSend = new QPushButton(groupBox);
        pushButton_emailSend->setObjectName(QString::fromUtf8("pushButton_emailSend"));
        pushButton_emailSend->setMinimumSize(QSize(72, 26));
        pushButton_emailSend->setMaximumSize(QSize(72, 26));
        pushButton_emailSend->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_emailSend\n"
"{\n"
"	border-image: url(:/images/EmailImage/emailSend.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_emailSend:hover\n"
"{\n"
"	border-image: url(:/images/EmailImage/emailSend_hover.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_emailSend:pressed\n"
"{\n"
"	border-image: url(:/images/EmailImage/emailSend_pressed.png);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_emailSend);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_7 = new QVBoxLayout(tab_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout_recver_3 = new QGridLayout();
        gridLayout_recver_3->setSpacing(0);
        gridLayout_recver_3->setObjectName(QString::fromUtf8("gridLayout_recver_3"));
        horizontalSpacer_24 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_recver_3->addItem(horizontalSpacer_24, 0, 0, 1, 1);

        label_recver_look_2 = new QLabel(tab_4);
        label_recver_look_2->setObjectName(QString::fromUtf8("label_recver_look_2"));
        label_recver_look_2->setMinimumSize(QSize(0, 30));
        label_recver_look_2->setFont(font2);
        label_recver_look_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_recver_3->addWidget(label_recver_look_2, 0, 1, 1, 1);

        label_under_3 = new QLabel(tab_4);
        label_under_3->setObjectName(QString::fromUtf8("label_under_3"));
        label_under_3->setMaximumSize(QSize(16777215, 1));
        label_under_3->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 185, 255);"));

        gridLayout_recver_3->addWidget(label_under_3, 1, 1, 1, 2);

        lineEdit_send_look = new QLineEdit(tab_4);
        lineEdit_send_look->setObjectName(QString::fromUtf8("lineEdit_send_look"));
        lineEdit_send_look->setMinimumSize(QSize(0, 30));
        QFont font4;
        font4.setPointSize(11);
        lineEdit_send_look->setFont(font4);
        lineEdit_send_look->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);\n"
"border:0px;\n"
"color: rgb(170, 0, 255);"));

        gridLayout_recver_3->addWidget(lineEdit_send_look, 0, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout_recver_3);

        gridLayout_recver_2 = new QGridLayout();
        gridLayout_recver_2->setSpacing(0);
        gridLayout_recver_2->setObjectName(QString::fromUtf8("gridLayout_recver_2"));
        horizontalSpacer_13 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_recver_2->addItem(horizontalSpacer_13, 0, 0, 1, 1);

        label_recver_look = new QLabel(tab_4);
        label_recver_look->setObjectName(QString::fromUtf8("label_recver_look"));
        label_recver_look->setMinimumSize(QSize(0, 30));
        label_recver_look->setFont(font2);
        label_recver_look->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_recver_2->addWidget(label_recver_look, 0, 1, 1, 1);

        label_under_2 = new QLabel(tab_4);
        label_under_2->setObjectName(QString::fromUtf8("label_under_2"));
        label_under_2->setMaximumSize(QSize(16777215, 1));
        label_under_2->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 185, 255);"));

        gridLayout_recver_2->addWidget(label_under_2, 1, 1, 1, 2);

        lineEdit_recv_look = new QLineEdit(tab_4);
        lineEdit_recv_look->setObjectName(QString::fromUtf8("lineEdit_recv_look"));
        lineEdit_recv_look->setMinimumSize(QSize(0, 30));
        lineEdit_recv_look->setFont(font2);
        lineEdit_recv_look->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);\n"
"border:0px;\n"
"color: rgb(170, 0, 255);"));

        gridLayout_recver_2->addWidget(lineEdit_recv_look, 0, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout_recver_2);

        gridLayout_recver_6 = new QGridLayout();
        gridLayout_recver_6->setSpacing(0);
        gridLayout_recver_6->setObjectName(QString::fromUtf8("gridLayout_recver_6"));
        horizontalSpacer_25 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_recver_6->addItem(horizontalSpacer_25, 0, 0, 1, 1);

        label_recver_look_3 = new QLabel(tab_4);
        label_recver_look_3->setObjectName(QString::fromUtf8("label_recver_look_3"));
        label_recver_look_3->setMinimumSize(QSize(0, 30));
        label_recver_look_3->setFont(font2);
        label_recver_look_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_recver_6->addWidget(label_recver_look_3, 0, 1, 1, 1);

        label_under_6 = new QLabel(tab_4);
        label_under_6->setObjectName(QString::fromUtf8("label_under_6"));
        label_under_6->setMaximumSize(QSize(16777215, 1));
        label_under_6->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 185, 255);"));

        gridLayout_recver_6->addWidget(label_under_6, 1, 1, 1, 2);

        lineEdit_copy_look = new QLineEdit(tab_4);
        lineEdit_copy_look->setObjectName(QString::fromUtf8("lineEdit_copy_look"));
        lineEdit_copy_look->setMinimumSize(QSize(0, 30));
        lineEdit_copy_look->setFont(font2);
        lineEdit_copy_look->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);\n"
"border:0px;\n"
"color: rgb(170, 0, 255);"));

        gridLayout_recver_6->addWidget(lineEdit_copy_look, 0, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout_recver_6);

        gridLayout_topic_2 = new QGridLayout();
        gridLayout_topic_2->setSpacing(0);
        gridLayout_topic_2->setObjectName(QString::fromUtf8("gridLayout_topic_2"));
        label_topic_look = new QLabel(tab_4);
        label_topic_look->setObjectName(QString::fromUtf8("label_topic_look"));
        label_topic_look->setMinimumSize(QSize(0, 30));
        label_topic_look->setFont(font2);
        label_topic_look->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_topic_2->addWidget(label_topic_look, 0, 1, 1, 1);

        label_topicUnder_2 = new QLabel(tab_4);
        label_topicUnder_2->setObjectName(QString::fromUtf8("label_topicUnder_2"));
        label_topicUnder_2->setMaximumSize(QSize(16777215, 1));
        label_topicUnder_2->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 185, 255);"));

        gridLayout_topic_2->addWidget(label_topicUnder_2, 1, 1, 1, 2);

        horizontalSpacer_23 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_topic_2->addItem(horizontalSpacer_23, 0, 0, 1, 1);

        lineEdit_topic_look = new QLineEdit(tab_4);
        lineEdit_topic_look->setObjectName(QString::fromUtf8("lineEdit_topic_look"));
        lineEdit_topic_look->setMinimumSize(QSize(0, 30));
        lineEdit_topic_look->setFont(font4);
        lineEdit_topic_look->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);\n"
"border:0px;\n"
"color: rgb(170, 0, 255);"));

        gridLayout_topic_2->addWidget(lineEdit_topic_look, 0, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout_topic_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_16 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_16);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        horizontalLayout_6->addWidget(label_3);

        lineEdit_dealTime_look = new QLineEdit(tab_4);
        lineEdit_dealTime_look->setObjectName(QString::fromUtf8("lineEdit_dealTime_look"));
        lineEdit_dealTime_look->setMaximumSize(QSize(200, 200));
        lineEdit_dealTime_look->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);\n"
"border:0px;\n"
"color: rgb(131, 131, 131);"));

        horizontalLayout_6->addWidget(lineEdit_dealTime_look);

        horizontalSpacer_20 = new QSpacerItem(45, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_20);

        pushButton_appendix_look = new QPushButton(tab_4);
        pushButton_appendix_look->setObjectName(QString::fromUtf8("pushButton_appendix_look"));
        pushButton_appendix_look->setMinimumSize(QSize(70, 22));
        pushButton_appendix_look->setMaximumSize(QSize(70, 22));
        pushButton_appendix_look->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_appendix_look\n"
"{\n"
"	color:blue;	\n"
"	background-color: rgb(255, 255, 255,0);\n"
"}\n"
"\n"
"QPushButton#pushButton_appendix_look:hover\n"
"{\n"
"	color:white;\n"
"	background-color: rgb(255, 255, 255,0);\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_appendix_look);

        pushButton_appendixPath_look = new QPushButton(tab_4);
        pushButton_appendixPath_look->setObjectName(QString::fromUtf8("pushButton_appendixPath_look"));
        pushButton_appendixPath_look->setMinimumSize(QSize(0, 22));
        pushButton_appendixPath_look->setFont(font2);
        pushButton_appendixPath_look->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_appendixPath_look\n"
"{\n"
"    color:green;\n"
"    background-color:rgb(238 , 238 , 238,0);\n"
"    border: 0px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_appendixPath_look:hover\n"
"{\n"
"    color:white;\n"
"    \n"
"	background-color: rgb(85, 170, 255);\n"
"    border: 0px solid rgb(15 , 150 , 255);\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_appendixPath_look);

        horizontalSpacer_21 = new QSpacerItem(13, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_21);

        pushButton_downAppendix = new QPushButton(tab_4);
        pushButton_downAppendix->setObjectName(QString::fromUtf8("pushButton_downAppendix"));
        pushButton_downAppendix->setMinimumSize(QSize(30, 22));
        pushButton_downAppendix->setMaximumSize(QSize(30, 16777215));
        pushButton_downAppendix->setFont(font3);
        pushButton_downAppendix->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_downAppendix\n"
"{\n"
"    color:red;\n"
"    background-color:rgb(238 , 238 , 238,0);\n"
"    border: 0px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_downAppendix:hover\n"
"{\n"
"    \n"
"	color: rgb(0, 0, 255);\n"
"    \n"
"	background-color: rgb(221, 245, 255);\n"
"    border: 0px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_downAppendix:pressed\n"
"{\n"
"    color:white;	\n"
"	background-color: rgb(19, 42, 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));

        horizontalLayout_6->addWidget(pushButton_downAppendix);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_22);

        pushButton_reply = new QPushButton(tab_4);
        pushButton_reply->setObjectName(QString::fromUtf8("pushButton_reply"));
        pushButton_reply->setMinimumSize(QSize(72, 26));
        pushButton_reply->setMaximumSize(QSize(72, 26));
        pushButton_reply->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_reply\n"
"{\n"
"	\n"
"	color: rgb(0, 0, 255);\n"
"    background-color:rgb(238 , 238 , 238);\n"
"    border: 1px solid rgb(183 , 183 , 183);\n"
"}\n"
"\n"
"QPushButton#pushButton_reply:hover\n"
"{\n"
"    \n"
"	color: rgb(0, 85, 255);\n"
"	background-color: rgb(221, 245, 255);\n"
"    border: 1px solid rgb(15 , 150 , 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_reply:pressed\n"
"{\n"
"    color:white;	\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}"));

        horizontalLayout_6->addWidget(pushButton_reply);


        verticalLayout_6->addLayout(horizontalLayout_6);

        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 1));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 185, 255);"));

        verticalLayout_6->addWidget(label_4);


        horizontalLayout_8->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_8);

        groupBox_look = new QGroupBox(tab_4);
        groupBox_look->setObjectName(QString::fromUtf8("groupBox_look"));
        groupBox_look->setStyleSheet(QString::fromUtf8("QGroupBox#groupBox_look\n"
"{\n"
"	border:0px;\n"
"}\n"
""));
        verticalLayout_5 = new QVBoxLayout(groupBox_look);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 9, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        textEdit_look = new QTextEdit(groupBox_look);
        textEdit_look->setObjectName(QString::fromUtf8("textEdit_look"));
        textEdit_look->setEnabled(true);
        textEdit_look->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit{border:0px;	border-image: url(:/images/EmailImage/textBackGround/34.png);}\n"
""));
        textEdit_look->setReadOnly(true);

        horizontalLayout_7->addWidget(textEdit_look);


        verticalLayout_5->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(30, 7, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_5->addItem(verticalSpacer_2);


        verticalLayout_7->addWidget(groupBox_look);

        tabWidget->addTab(tab_4, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(EmailFrame);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(EmailFrame);
    } // setupUi

    void retranslateUi(QWidget *EmailFrame)
    {
        EmailFrame->setWindowTitle(QApplication::translate("EmailFrame", "\351\202\256\344\273\266", nullptr));
#ifndef QT_NO_TOOLTIP
        EmailFrame->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("EmailFrame", "OA Email", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_skin->setToolTip(QApplication::translate("EmailFrame", "\346\233\264\346\215\242\347\232\256\350\202\244", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_skin->setText(QString());
#ifndef QT_NO_TOOLTIP
        horizontalSlider_opacity->setToolTip(QApplication::translate("EmailFrame", "\350\256\276\347\275\256\351\200\217\346\230\216\345\272\246", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_tr->setToolTip(QApplication::translate("EmailFrame", "\346\233\264\345\244\232", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_tr->setStatusTip(QApplication::translate("EmailFrame", "\346\233\264\345\244\232", nullptr));
#endif // QT_NO_STATUSTIP
        pushButton_tr->setText(QString());
        pushButton_min->setText(QString());
        pushButton_max->setText(QString());
        pushButton_close->setText(QString());
        pushButton_recvBox->setText(QApplication::translate("EmailFrame", "\346\224\266\344\273\266\347\256\261", nullptr));
        pushButton_sentBox->setText(QApplication::translate("EmailFrame", "\345\267\262\345\217\221\351\200\201", nullptr));
        pushButton_write->setText(QApplication::translate("EmailFrame", "\345\206\231\344\277\241", nullptr));
        pushButton_look->setText(QApplication::translate("EmailFrame", "\346\237\245\347\234\213", nullptr));
        label_main->setText(QString());
        pushButton_deleteRecv->setText(QApplication::translate("EmailFrame", "\345\210\240\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EmailFrame", "\346\224\266\344\273\266\347\256\261", nullptr));
        pushButton_deleteSent->setText(QApplication::translate("EmailFrame", "\345\210\240\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("EmailFrame", "\345\267\262\345\217\221\351\200\201", nullptr));
        label_recver->setText(QApplication::translate("EmailFrame", "\346\224\266\344\273\266\344\272\272\357\274\232", nullptr));
        pushButton_addRecver->setText(QString());
        label_under->setText(QString());
        label_copy->setText(QApplication::translate("EmailFrame", "\346\212\204  \351\200\201\357\274\232", nullptr));
        pushButton_addCopy->setText(QString());
        label_copyUnder->setText(QString());
        label_topic->setText(QApplication::translate("EmailFrame", "\344\270\273  \351\242\230\357\274\232", nullptr));
        label_topicUnder->setText(QString());
        pushButton_appendix->setText(QString());
        pushButton_appendixPath->setText(QString());
        pushButton_delAppendix->setText(QApplication::translate("EmailFrame", "\345\210\240\351\231\244", nullptr));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_backGround->setToolTip(QApplication::translate("EmailFrame", "\350\203\214\346\231\257\345\233\276\347\211\207", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_backGround->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_bold->setToolTip(QApplication::translate("EmailFrame", "\347\262\227\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_bold->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_italic->setToolTip(QApplication::translate("EmailFrame", "\346\226\234\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_italic->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_underLine->setToolTip(QApplication::translate("EmailFrame", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_underLine->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_textLeft->setToolTip(QApplication::translate("EmailFrame", "\345\267\246\345\257\271\351\275\220", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_textLeft->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_textCenter->setToolTip(QApplication::translate("EmailFrame", "\345\261\205\344\270\255", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_textCenter->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_textRight->setToolTip(QApplication::translate("EmailFrame", "\345\217\263\345\257\271\351\275\220", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_textRight->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_insertPic->setToolTip(QApplication::translate("EmailFrame", "\346\217\222\345\205\245\345\233\276\347\211\207", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_insertPic->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_dayTime->setToolTip(QApplication::translate("EmailFrame", "\346\217\222\345\205\245\346\227\245\346\234\237", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_dayTime->setText(QString());
#ifndef QT_NO_TOOLTIP
        fontComboBox->setToolTip(QApplication::translate("EmailFrame", "\351\200\211\346\213\251\345\255\227\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        fontComboBox->setCurrentText(QApplication::translate("EmailFrame", "Arial", nullptr));
        comboBox_fontSize->setItemText(0, QString());
        comboBox_fontSize->setItemText(1, QString());
        comboBox_fontSize->setItemText(2, QString());
        comboBox_fontSize->setItemText(3, QString());
        comboBox_fontSize->setItemText(4, QString());
        comboBox_fontSize->setItemText(5, QString());
        comboBox_fontSize->setItemText(6, QString());
        comboBox_fontSize->setItemText(7, QString());

#ifndef QT_NO_TOOLTIP
        comboBox_fontSize->setToolTip(QApplication::translate("EmailFrame", "\345\255\227\344\275\223\345\244\247\345\260\217", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboBox_fontColor->setToolTip(QApplication::translate("EmailFrame", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboBox_fontBackColor->setToolTip(QApplication::translate("EmailFrame", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        comboBox_orderList->setItemText(0, QApplication::translate("EmailFrame", "\346\227\240", nullptr));
        comboBox_orderList->setItemText(1, QString());
        comboBox_orderList->setItemText(2, QString());
        comboBox_orderList->setItemText(3, QString());
        comboBox_orderList->setItemText(4, QString());
        comboBox_orderList->setItemText(5, QString());
        comboBox_orderList->setItemText(6, QString());
        comboBox_orderList->setItemText(7, QString());
        comboBox_orderList->setItemText(8, QString());

#ifndef QT_NO_TOOLTIP
        comboBox_orderList->setToolTip(QApplication::translate("EmailFrame", "\345\272\217\345\210\227\346\240\207\345\217\267\346\240\267\345\274\217", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QString());
        pushButton_emailSend->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("EmailFrame", "\345\206\231\344\277\241", nullptr));
        label_recver_look_2->setText(QApplication::translate("EmailFrame", "\345\217\221\344\273\266\344\272\272\357\274\232", nullptr));
        label_under_3->setText(QString());
        lineEdit_send_look->setText(QString());
        label_recver_look->setText(QApplication::translate("EmailFrame", "\346\224\266\344\273\266\344\272\272\357\274\232", nullptr));
        label_under_2->setText(QString());
        label_recver_look_3->setText(QApplication::translate("EmailFrame", "\346\212\204  \351\200\201\357\274\232", nullptr));
        label_under_6->setText(QString());
        label_topic_look->setText(QApplication::translate("EmailFrame", "\344\270\273  \351\242\230\357\274\232", nullptr));
        label_topicUnder_2->setText(QString());
        label_3->setText(QApplication::translate("EmailFrame", "\346\227\266  \351\227\264\357\274\232", nullptr));
        pushButton_appendix_look->setText(QApplication::translate("EmailFrame", "\351\231\204\344\273\266\357\274\232", nullptr));
        pushButton_appendixPath_look->setText(QString());
        pushButton_downAppendix->setText(QApplication::translate("EmailFrame", "\344\270\213\350\275\275", nullptr));
        pushButton_reply->setText(QApplication::translate("EmailFrame", "\345\233\236\345\244\215", nullptr));
        label_4->setText(QString());
        groupBox_look->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("EmailFrame", "\346\237\245\347\234\213\351\202\256\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmailFrame: public Ui_EmailFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILFRAME_H
