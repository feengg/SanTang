/********************************************************************************
** Form generated from reading UI file 'mimegame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIMEGAME_H
#define UI_MIMEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MimeGame
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_min;
    QPushButton *pushButton_close;
    QHBoxLayout *horizontalLayout_4;
    QTabWidget *tabWidget;
    QWidget *game;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_time;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *comboBox_gameLevel;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_reStart;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_mineNum;
    QLabel *label_mineNum;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QWidget *history;
    QGroupBox *groupBox_easy;
    QLabel *label;
    QLabel *label_easyBestTime;
    QLabel *label_easySum;
    QLabel *label_4;
    QLabel *label_easySuccess;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_easyRate;
    QGroupBox *groupBox_mid;
    QLabel *label_midRate;
    QLabel *label_midSum;
    QLabel *label_midBestTime;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_midSuccess;
    QLabel *label_16;
    QGroupBox *groupBox_hard;
    QLabel *label_hardRate;
    QLabel *label_hardSum;
    QLabel *label_hardBestTime;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_hardSuccess;
    QLabel *label_24;
    QWidget *billBoard;
    QGroupBox *groupBox_midBillBoard;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_mid;
    QSpacerItem *verticalSpacer_mid;
    QLabel *label_midTimes;
    QLabel *label_midName;
    QLabel *label_mid;
    QGroupBox *groupBox_easyBillBoard;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_easy;
    QSpacerItem *verticalSpacer_easy;
    QLabel *label_easyTimes;
    QLabel *label_easy;
    QLabel *label_easyName;
    QGroupBox *groupBox_hardBillBoard;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_hard;
    QSpacerItem *verticalSpacer_hard;
    QLabel *label_hardTimes;
    QLabel *label_hardName;
    QLabel *label_hard;
    QComboBox *comboBox_rateType;
    QWidget *tab;
    QLabel *label_tip1;
    QLabel *label_tip2;
    QLabel *label_tip3;
    QLabel *label_tip4;
    QLabel *label_tip5;

    void setupUi(QWidget *MimeGame)
    {
        if (MimeGame->objectName().isEmpty())
            MimeGame->setObjectName(QString::fromUtf8("MimeGame"));
        MimeGame->resize(1074, 710);
        verticalLayout_2 = new QVBoxLayout(MimeGame);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(30, 0, 30, 30);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_min = new QPushButton(MimeGame);
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
"	background-color: rgb(255, 255, 255);\n"
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

        horizontalLayout_3->addWidget(pushButton_min);

        pushButton_close = new QPushButton(MimeGame);
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
"background-color: rgba(230,0,0,);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_close);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tabWidget = new QTabWidget(MimeGame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget#tabWidget\n"
"{\n"
"	border:0px;	\n"
"	border-image: url(:/images/EmailImage/textBackGround/0.png);\n"
"}\n"
"\n"
"\n"
""));
        game = new QWidget();
        game->setObjectName(QString::fromUtf8("game"));
        verticalLayout = new QVBoxLayout(game);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_time = new QPushButton(game);
        pushButton_time->setObjectName(QString::fromUtf8("pushButton_time"));
        pushButton_time->setMinimumSize(QSize(100, 30));
        pushButton_time->setStyleSheet(QString::fromUtf8("border-image: url(:/images/mimeGame/time.png);"));

        horizontalLayout->addWidget(pushButton_time);

        label_time = new QLabel(game);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setMinimumSize(QSize(60, 0));
        label_time->setMaximumSize(QSize(60, 16777215));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_time->setFont(font);
        label_time->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #dadbde,stop:1\n"
" #51b5eb);\n"
"\n"
"color: rgb(255, 255, 255);"));
        label_time->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_time);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        comboBox_gameLevel = new QComboBox(game);
        comboBox_gameLevel->addItem(QString());
        comboBox_gameLevel->addItem(QString());
        comboBox_gameLevel->addItem(QString());
        comboBox_gameLevel->setObjectName(QString::fromUtf8("comboBox_gameLevel"));
        comboBox_gameLevel->setMinimumSize(QSize(69, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font1.setPointSize(14);
        comboBox_gameLevel->setFont(font1);

        horizontalLayout->addWidget(comboBox_gameLevel);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        pushButton_reStart = new QPushButton(game);
        pushButton_reStart->setObjectName(QString::fromUtf8("pushButton_reStart"));
        pushButton_reStart->setMinimumSize(QSize(65, 25));
        pushButton_reStart->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pushButton_reStart);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        pushButton_mineNum = new QPushButton(game);
        pushButton_mineNum->setObjectName(QString::fromUtf8("pushButton_mineNum"));
        pushButton_mineNum->setMinimumSize(QSize(99, 31));
        pushButton_mineNum->setStyleSheet(QString::fromUtf8("border-image: url(:/images/mimeGame/mineNum.png);"));

        horizontalLayout->addWidget(pushButton_mineNum);

        label_mineNum = new QLabel(game);
        label_mineNum->setObjectName(QString::fromUtf8("label_mineNum"));
        label_mineNum->setMinimumSize(QSize(40, 0));
        label_mineNum->setMaximumSize(QSize(40, 16777215));
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(true);
        font2.setWeight(75);
        label_mineNum->setFont(font2);
        label_mineNum->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #dadbde,stop:1\n"
" #51b5eb);\n"
"color: rgb(255, 255, 255);"));
        label_mineNum->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_mineNum);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        groupBox = new QGroupBox(game);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"QGroupBox#groupBox\n"
"{\n"
"	border-top-color: rgb(128, 168, 255,100);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(groupBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget->addTab(game, QString());
        history = new QWidget();
        history->setObjectName(QString::fromUtf8("history"));
        groupBox_easy = new QGroupBox(history);
        groupBox_easy->setObjectName(QString::fromUtf8("groupBox_easy"));
        groupBox_easy->setGeometry(QRect(330, 30, 331, 161));
        QFont font3;
        font3.setPointSize(9);
        groupBox_easy->setFont(font3);
        groupBox_easy->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 234, 235);"));
        label = new QLabel(groupBox_easy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 61, 20));
        label_easyBestTime = new QLabel(groupBox_easy);
        label_easyBestTime->setObjectName(QString::fromUtf8("label_easyBestTime"));
        label_easyBestTime->setGeometry(QRect(170, 20, 71, 21));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label_easyBestTime->setFont(font4);
        label_easyBestTime->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"color: rgb(0, 170, 0);"));
        label_easyBestTime->setAlignment(Qt::AlignCenter);
        label_easySum = new QLabel(groupBox_easy);
        label_easySum->setObjectName(QString::fromUtf8("label_easySum"));
        label_easySum->setGeometry(QRect(170, 50, 71, 21));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        label_easySum->setFont(font5);
        label_easySum->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 187);"));
        label_easySum->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_easy);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 50, 61, 20));
        label_easySuccess = new QLabel(groupBox_easy);
        label_easySuccess->setObjectName(QString::fromUtf8("label_easySuccess"));
        label_easySuccess->setGeometry(QRect(170, 80, 71, 21));
        label_easySuccess->setFont(font5);
        label_easySuccess->setStyleSheet(QString::fromUtf8("background-color: rgb(137, 198, 255);\n"
"color: rgb(255, 255, 127);"));
        label_easySuccess->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_easy);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 80, 61, 20));
        label_7 = new QLabel(groupBox_easy);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 110, 61, 20));
        label_easyRate = new QLabel(groupBox_easy);
        label_easyRate->setObjectName(QString::fromUtf8("label_easyRate"));
        label_easyRate->setGeometry(QRect(170, 110, 71, 21));
        label_easyRate->setFont(font5);
        label_easyRate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 213, 176);\n"
"color: rgb(255, 0, 127);"));
        label_easyRate->setAlignment(Qt::AlignCenter);
        groupBox_mid = new QGroupBox(history);
        groupBox_mid->setObjectName(QString::fromUtf8("groupBox_mid"));
        groupBox_mid->setGeometry(QRect(330, 210, 331, 161));
        groupBox_mid->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));
        label_midRate = new QLabel(groupBox_mid);
        label_midRate->setObjectName(QString::fromUtf8("label_midRate"));
        label_midRate->setGeometry(QRect(170, 120, 71, 21));
        label_midRate->setFont(font5);
        label_midRate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 213, 176);\n"
"color: rgb(255, 0, 127);"));
        label_midRate->setAlignment(Qt::AlignCenter);
        label_midSum = new QLabel(groupBox_mid);
        label_midSum->setObjectName(QString::fromUtf8("label_midSum"));
        label_midSum->setGeometry(QRect(170, 60, 71, 21));
        label_midSum->setFont(font5);
        label_midSum->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 187);"));
        label_midSum->setAlignment(Qt::AlignCenter);
        label_midBestTime = new QLabel(groupBox_mid);
        label_midBestTime->setObjectName(QString::fromUtf8("label_midBestTime"));
        label_midBestTime->setGeometry(QRect(170, 30, 71, 21));
        label_midBestTime->setFont(font5);
        label_midBestTime->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"color: rgb(0, 170, 0);"));
        label_midBestTime->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(groupBox_mid);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 90, 61, 20));
        label_13 = new QLabel(groupBox_mid);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 120, 61, 20));
        label_14 = new QLabel(groupBox_mid);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(100, 30, 61, 20));
        label_midSuccess = new QLabel(groupBox_mid);
        label_midSuccess->setObjectName(QString::fromUtf8("label_midSuccess"));
        label_midSuccess->setGeometry(QRect(170, 90, 71, 21));
        label_midSuccess->setFont(font5);
        label_midSuccess->setStyleSheet(QString::fromUtf8("background-color: rgb(137, 198, 255);\n"
"color: rgb(255, 255, 127);"));
        label_midSuccess->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(groupBox_mid);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(100, 60, 61, 20));
        groupBox_hard = new QGroupBox(history);
        groupBox_hard->setObjectName(QString::fromUtf8("groupBox_hard"));
        groupBox_hard->setGeometry(QRect(330, 390, 331, 161));
        groupBox_hard->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 255, 232);"));
        label_hardRate = new QLabel(groupBox_hard);
        label_hardRate->setObjectName(QString::fromUtf8("label_hardRate"));
        label_hardRate->setGeometry(QRect(170, 120, 71, 21));
        label_hardRate->setFont(font5);
        label_hardRate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 213, 176);\n"
"color: rgb(255, 0, 127);"));
        label_hardRate->setAlignment(Qt::AlignCenter);
        label_hardSum = new QLabel(groupBox_hard);
        label_hardSum->setObjectName(QString::fromUtf8("label_hardSum"));
        label_hardSum->setGeometry(QRect(170, 60, 71, 21));
        label_hardSum->setFont(font5);
        label_hardSum->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 255, 187);"));
        label_hardSum->setAlignment(Qt::AlignCenter);
        label_hardBestTime = new QLabel(groupBox_hard);
        label_hardBestTime->setObjectName(QString::fromUtf8("label_hardBestTime"));
        label_hardBestTime->setGeometry(QRect(170, 30, 71, 21));
        label_hardBestTime->setFont(font5);
        label_hardBestTime->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"color: rgb(0, 170, 0);"));
        label_hardBestTime->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(groupBox_hard);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(100, 90, 61, 20));
        label_21 = new QLabel(groupBox_hard);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(100, 120, 61, 20));
        label_22 = new QLabel(groupBox_hard);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(100, 30, 61, 20));
        label_hardSuccess = new QLabel(groupBox_hard);
        label_hardSuccess->setObjectName(QString::fromUtf8("label_hardSuccess"));
        label_hardSuccess->setGeometry(QRect(170, 90, 71, 21));
        label_hardSuccess->setFont(font5);
        label_hardSuccess->setStyleSheet(QString::fromUtf8("background-color: rgb(137, 198, 255);\n"
"color: rgb(255, 255, 127);"));
        label_hardSuccess->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(groupBox_hard);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(100, 60, 61, 20));
        tabWidget->addTab(history, QString());
        billBoard = new QWidget();
        billBoard->setObjectName(QString::fromUtf8("billBoard"));
        groupBox_midBillBoard = new QGroupBox(billBoard);
        groupBox_midBillBoard->setObjectName(QString::fromUtf8("groupBox_midBillBoard"));
        groupBox_midBillBoard->setGeometry(QRect(360, 40, 291, 551));
        groupBox_midBillBoard->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));
        scrollArea_2 = new QScrollArea(groupBox_midBillBoard);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 50, 291, 501));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 272, 550));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(0, 550));
        verticalLayout_mid = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_mid->setSpacing(2);
        verticalLayout_mid->setObjectName(QString::fromUtf8("verticalLayout_mid"));
        verticalSpacer_mid = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_mid->addItem(verticalSpacer_mid);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        label_midTimes = new QLabel(groupBox_midBillBoard);
        label_midTimes->setObjectName(QString::fromUtf8("label_midTimes"));
        label_midTimes->setGeometry(QRect(190, 20, 85, 22));
        label_midTimes->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_midTimes->setAlignment(Qt::AlignCenter);
        label_midName = new QLabel(groupBox_midBillBoard);
        label_midName->setObjectName(QString::fromUtf8("label_midName"));
        label_midName->setGeometry(QRect(106, 20, 84, 22));
        label_midName->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_midName->setAlignment(Qt::AlignCenter);
        label_mid = new QLabel(groupBox_midBillBoard);
        label_mid->setObjectName(QString::fromUtf8("label_mid"));
        label_mid->setGeometry(QRect(21, 20, 85, 22));
        label_mid->setMinimumSize(QSize(0, 22));
        label_mid->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);\n"
""));
        label_mid->setAlignment(Qt::AlignCenter);
        groupBox_easyBillBoard = new QGroupBox(billBoard);
        groupBox_easyBillBoard->setObjectName(QString::fromUtf8("groupBox_easyBillBoard"));
        groupBox_easyBillBoard->setGeometry(QRect(50, 40, 291, 551));
        groupBox_easyBillBoard->setFont(font3);
        groupBox_easyBillBoard->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 234, 235);"));
        scrollArea = new QScrollArea(groupBox_easyBillBoard);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(-1, 49, 291, 501));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 272, 550));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 550));
        verticalLayout_easy = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_easy->setSpacing(2);
        verticalLayout_easy->setObjectName(QString::fromUtf8("verticalLayout_easy"));
        verticalLayout_easy->setContentsMargins(-1, 2, -1, -1);
        verticalSpacer_easy = new QSpacerItem(20, 536, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_easy->addItem(verticalSpacer_easy);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label_easyTimes = new QLabel(groupBox_easyBillBoard);
        label_easyTimes->setObjectName(QString::fromUtf8("label_easyTimes"));
        label_easyTimes->setGeometry(QRect(180, 20, 85, 22));
        label_easyTimes->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_easyTimes->setAlignment(Qt::AlignCenter);
        label_easy = new QLabel(groupBox_easyBillBoard);
        label_easy->setObjectName(QString::fromUtf8("label_easy"));
        label_easy->setGeometry(QRect(11, 20, 85, 22));
        label_easy->setMinimumSize(QSize(0, 22));
        label_easy->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
""));
        label_easy->setAlignment(Qt::AlignCenter);
        label_easyName = new QLabel(groupBox_easyBillBoard);
        label_easyName->setObjectName(QString::fromUtf8("label_easyName"));
        label_easyName->setGeometry(QRect(96, 20, 84, 22));
        label_easyName->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_easyName->setAlignment(Qt::AlignCenter);
        groupBox_hardBillBoard = new QGroupBox(billBoard);
        groupBox_hardBillBoard->setObjectName(QString::fromUtf8("groupBox_hardBillBoard"));
        groupBox_hardBillBoard->setGeometry(QRect(670, 40, 321, 551));
        groupBox_hardBillBoard->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 255, 232);"));
        scrollArea_3 = new QScrollArea(groupBox_hardBillBoard);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(0, 52, 321, 501));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 302, 550));
        scrollAreaWidgetContents_3->setMinimumSize(QSize(0, 550));
        verticalLayout_hard = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_hard->setSpacing(2);
        verticalLayout_hard->setObjectName(QString::fromUtf8("verticalLayout_hard"));
        verticalLayout_hard->setContentsMargins(-1, 2, -1, -1);
        verticalSpacer_hard = new QSpacerItem(20, 536, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_hard->addItem(verticalSpacer_hard);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        label_hardTimes = new QLabel(groupBox_hardBillBoard);
        label_hardTimes->setObjectName(QString::fromUtf8("label_hardTimes"));
        label_hardTimes->setGeometry(QRect(200, 20, 95, 22));
        label_hardTimes->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_hardTimes->setAlignment(Qt::AlignCenter);
        label_hardName = new QLabel(groupBox_hardBillBoard);
        label_hardName->setObjectName(QString::fromUtf8("label_hardName"));
        label_hardName->setGeometry(QRect(106, 20, 94, 22));
        label_hardName->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_hardName->setAlignment(Qt::AlignCenter);
        label_hard = new QLabel(groupBox_hardBillBoard);
        label_hard->setObjectName(QString::fromUtf8("label_hard"));
        label_hard->setGeometry(QRect(11, 20, 95, 22));
        label_hard->setMinimumSize(QSize(0, 22));
        label_hard->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
""));
        label_hard->setAlignment(Qt::AlignCenter);
        comboBox_rateType = new QComboBox(billBoard);
        comboBox_rateType->addItem(QString());
        comboBox_rateType->addItem(QString());
        comboBox_rateType->setObjectName(QString::fromUtf8("comboBox_rateType"));
        comboBox_rateType->setGeometry(QRect(470, 10, 81, 25));
        comboBox_rateType->setMinimumSize(QSize(69, 25));
        QFont font6;
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        comboBox_rateType->setFont(font6);
        tabWidget->addTab(billBoard, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_tip1 = new QLabel(tab);
        label_tip1->setObjectName(QString::fromUtf8("label_tip1"));
        label_tip1->setGeometry(QRect(100, 40, 821, 40));
        label_tip1->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 220, 255);\n"
"color: rgb(0, 0, 255);\n"
"font: 18pt \"\351\232\266\344\271\246\";"));
        label_tip2 = new QLabel(tab);
        label_tip2->setObjectName(QString::fromUtf8("label_tip2"));
        label_tip2->setGeometry(QRect(100, 150, 821, 40));
        label_tip2->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 220, 255);\n"
"color: rgb(0, 0, 255);\n"
"font: 18pt \"\351\232\266\344\271\246\";"));
        label_tip3 = new QLabel(tab);
        label_tip3->setObjectName(QString::fromUtf8("label_tip3"));
        label_tip3->setGeometry(QRect(100, 270, 821, 40));
        label_tip3->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 220, 255);\n"
"color: rgb(0, 0, 255);\n"
"font: 18pt \"\351\232\266\344\271\246\";"));
        label_tip4 = new QLabel(tab);
        label_tip4->setObjectName(QString::fromUtf8("label_tip4"));
        label_tip4->setGeometry(QRect(100, 380, 811, 40));
        label_tip4->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 220, 255);\n"
"color: rgb(0, 0, 255);\n"
"font: 18pt \"\351\232\266\344\271\246\";"));
        label_tip5 = new QLabel(tab);
        label_tip5->setObjectName(QString::fromUtf8("label_tip5"));
        label_tip5->setGeometry(QRect(100, 490, 811, 40));
        label_tip5->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 220, 255);\n"
"color: rgb(0, 0, 255);\n"
"font: 18pt \"\351\232\266\344\271\246\";"));
        tabWidget->addTab(tab, QString());

        horizontalLayout_4->addWidget(tabWidget);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(MimeGame);

        tabWidget->setCurrentIndex(0);
        comboBox_gameLevel->setCurrentIndex(2);
        comboBox_rateType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MimeGame);
    } // setupUi

    void retranslateUi(QWidget *MimeGame)
    {
        MimeGame->setWindowTitle(QApplication::translate("MimeGame", "Form", nullptr));
        pushButton_min->setText(QString());
        pushButton_close->setText(QString());
        pushButton_time->setText(QString());
        label_time->setText(QApplication::translate("MimeGame", "0", nullptr));
        comboBox_gameLevel->setItemText(0, QApplication::translate("MimeGame", "\345\210\235\347\272\247", nullptr));
        comboBox_gameLevel->setItemText(1, QApplication::translate("MimeGame", "\344\270\255\347\272\247", nullptr));
        comboBox_gameLevel->setItemText(2, QApplication::translate("MimeGame", "\351\253\230\347\272\247", nullptr));

        pushButton_reStart->setText(QApplication::translate("MimeGame", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        pushButton_mineNum->setText(QString());
        label_mineNum->setText(QApplication::translate("MimeGame", "99", nullptr));
        groupBox->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(game), QApplication::translate("MimeGame", "\346\270\270\346\210\217", nullptr));
        groupBox_easy->setTitle(QApplication::translate("MimeGame", "\345\210\235\347\272\247", nullptr));
        label->setText(QApplication::translate("MimeGame", "\346\234\200\344\275\263\346\227\266\351\227\264\357\274\232", nullptr));
        label_easyBestTime->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_easySum->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_4->setText(QApplication::translate("MimeGame", "\345\267\262\347\216\251\345\261\200\346\225\260\357\274\232", nullptr));
        label_easySuccess->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_6->setText(QApplication::translate("MimeGame", "\345\267\262\350\203\234\345\261\200\346\225\260\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MimeGame", "\350\203\234    \347\216\207\357\274\232", nullptr));
        label_easyRate->setText(QApplication::translate("MimeGame", "0", nullptr));
        groupBox_mid->setTitle(QApplication::translate("MimeGame", "\344\270\255\347\272\247", nullptr));
        label_midRate->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_midSum->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_midBestTime->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_12->setText(QApplication::translate("MimeGame", "\345\267\262\350\203\234\345\261\200\346\225\260\357\274\232", nullptr));
        label_13->setText(QApplication::translate("MimeGame", "\350\203\234    \347\216\207\357\274\232", nullptr));
        label_14->setText(QApplication::translate("MimeGame", "\346\234\200\344\275\263\346\227\266\351\227\264\357\274\232", nullptr));
        label_midSuccess->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_16->setText(QApplication::translate("MimeGame", "\345\267\262\347\216\251\345\261\200\346\225\260\357\274\232", nullptr));
        groupBox_hard->setTitle(QApplication::translate("MimeGame", "\351\253\230\347\272\247", nullptr));
        label_hardRate->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_hardSum->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_hardBestTime->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_20->setText(QApplication::translate("MimeGame", "\345\267\262\350\203\234\345\261\200\346\225\260\357\274\232", nullptr));
        label_21->setText(QApplication::translate("MimeGame", "\350\203\234    \347\216\207\357\274\232", nullptr));
        label_22->setText(QApplication::translate("MimeGame", "\346\234\200\344\275\263\346\227\266\351\227\264\357\274\232", nullptr));
        label_hardSuccess->setText(QApplication::translate("MimeGame", "0", nullptr));
        label_24->setText(QApplication::translate("MimeGame", "\345\267\262\347\216\251\345\261\200\346\225\260\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(history), QApplication::translate("MimeGame", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        groupBox_midBillBoard->setTitle(QApplication::translate("MimeGame", "\344\270\255\347\272\247", nullptr));
        label_midTimes->setText(QApplication::translate("MimeGame", "\345\267\262\347\216\251\345\261\200\346\225\260", nullptr));
        label_midName->setText(QApplication::translate("MimeGame", "\345\247\223\345\220\215", nullptr));
        label_mid->setText(QApplication::translate("MimeGame", "\346\234\200\344\275\263\346\227\266\351\227\264", nullptr));
        groupBox_easyBillBoard->setTitle(QApplication::translate("MimeGame", "\345\210\235\347\272\247", nullptr));
        label_easyTimes->setText(QApplication::translate("MimeGame", "\345\267\262\347\216\251\345\261\200\346\225\260", nullptr));
        label_easy->setText(QApplication::translate("MimeGame", "\346\234\200\344\275\263\346\227\266\351\227\264", nullptr));
        label_easyName->setText(QApplication::translate("MimeGame", "\345\247\223\345\220\215", nullptr));
        groupBox_hardBillBoard->setTitle(QApplication::translate("MimeGame", "\351\253\230\347\272\247", nullptr));
        label_hardTimes->setText(QApplication::translate("MimeGame", "\345\267\262\347\216\251\345\261\200\346\225\260", nullptr));
        label_hardName->setText(QApplication::translate("MimeGame", "\345\247\223\345\220\215", nullptr));
        label_hard->setText(QApplication::translate("MimeGame", "\346\234\200\344\275\263\346\227\266\351\227\264", nullptr));
        comboBox_rateType->setItemText(0, QApplication::translate("MimeGame", "\346\234\200\344\275\263\346\227\266\351\227\264", nullptr));
        comboBox_rateType->setItemText(1, QApplication::translate("MimeGame", "\346\270\270\346\210\217\350\203\234\347\216\207", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(billBoard), QApplication::translate("MimeGame", "\346\216\222\350\241\214\346\246\234", nullptr));
        label_tip1->setText(QApplication::translate("MimeGame", "1\343\200\201\347\202\271\345\207\273\346\226\271\346\240\274,\346\216\222\351\231\244\346\211\200\346\234\211\351\233\267,\345\246\202\346\236\234\350\270\251\345\210\260\351\233\267\346\270\270\346\210\217\345\244\261\350\264\245", nullptr));
        label_tip2->setText(QApplication::translate("MimeGame", "2\343\200\201\346\226\271\346\240\274\346\230\276\347\244\272\347\232\204\346\225\260\345\255\227\350\241\250\347\244\272\346\255\244\346\240\274\345\221\250\345\233\2648\344\270\252\346\226\271\346\240\274\346\234\211\350\257\245\346\225\260\344\270\252\351\233\267", nullptr));
        label_tip3->setText(QApplication::translate("MimeGame", "3\343\200\201\347\241\256\345\256\232\346\237\220\344\270\252\346\226\271\346\240\274\346\230\257\351\233\267\345\220\216\351\274\240\346\240\207\345\217\263\351\224\256\345\217\257\345\201\232\346\240\207\350\256\260,\345\206\215\347\202\271\345\217\226\346\266\210\346\240\207\350\256\260", nullptr));
        label_tip4->setText(QApplication::translate("MimeGame", "4\343\200\201\345\275\223\346\240\207\350\256\260\345\256\214\344\270\255\345\277\203\346\240\274\345\221\250\345\233\264\346\211\200\346\234\211\351\233\267\346\227\266,\351\274\240\346\240\207\345\217\257\345\217\214\345\207\273\344\270\255\345\277\203\346\240\274,\350\207\252\345\212\250\346\230\276\347\244\272\345\221\250\345\233\264\351\235\236\351\233\267\346\226\271\346\240\274", nullptr));
        label_tip5->setText(QApplication::translate("MimeGame", "5\343\200\201\345\246\202\346\236\234\345\221\250\345\233\264\351\233\267\346\240\207\350\256\260\345\256\214\344\275\206\346\240\207\350\256\260\346\234\211\351\224\231,\345\271\266\345\234\250\345\217\214\345\207\273\344\270\255\345\277\203\346\240\274\346\203\205\345\206\265\344\270\213,\346\270\270\346\210\217\345\244\261\350\264\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MimeGame", "\346\270\270\346\210\217\350\247\204\345\210\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MimeGame: public Ui_MimeGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIMEGAME_H
