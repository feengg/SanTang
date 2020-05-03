/********************************************************************************
** Form generated from reading UI file 'weekreport.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEEKREPORT_H
#define UI_WEEKREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeekReport
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QTableWidget *tableWidget_nowWork;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_8;
    QTableWidget *tableWidget_thisWeekWork;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_9;
    QTableWidget *tableWidget_nextWeekWork;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_10;
    QTextEdit *textEdit_need;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_11;
    QTextEdit *textEdit_advices;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QLabel *label_4;
    QLineEdit *lineEdit_position;
    QLabel *label_5;
    QLineEdit *lineEdit_department;
    QLabel *label_6;
    QComboBox *comboBox_time;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_min;
    QPushButton *pushButton_max;
    QPushButton *pushButton_close;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_8;

    void setupUi(QWidget *WeekReport)
    {
        if (WeekReport->objectName().isEmpty())
            WeekReport->setObjectName(QString::fromUtf8("WeekReport"));
        WeekReport->resize(1086, 770);
        QFont font;
        font.setPointSize(10);
        WeekReport->setFont(font);
        WeekReport->setAutoFillBackground(false);
        gridLayout_2 = new QGridLayout(WeekReport);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        scrollArea = new QScrollArea(WeekReport);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setStyleSheet(QString::fromUtf8("#srollArea\n"
"{\n"
"	\n"
"	background-color: rgb(226, 226, 226);\n"
"	\n"
"}\n"
"#srollArea *\n"
"{\n"
"	\n"
"	\n"
"}"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -269, 1069, 1200));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1200));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 1200));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, -1, 25, -1);
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        tableWidget_nowWork = new QTableWidget(scrollAreaWidgetContents);
        tableWidget_nowWork->setObjectName(QString::fromUtf8("tableWidget_nowWork"));
        tableWidget_nowWork->setMinimumSize(QSize(0, 0));
        tableWidget_nowWork->setMaximumSize(QSize(16777215, 200));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        tableWidget_nowWork->setFont(font2);

        verticalLayout->addWidget(tableWidget_nowWork);

        verticalSpacer_2 = new QSpacerItem(28, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 25));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        tableWidget_thisWeekWork = new QTableWidget(scrollAreaWidgetContents);
        tableWidget_thisWeekWork->setObjectName(QString::fromUtf8("tableWidget_thisWeekWork"));
        tableWidget_thisWeekWork->setFont(font2);

        verticalLayout->addWidget(tableWidget_thisWeekWork);

        verticalSpacer_3 = new QSpacerItem(28, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 25));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_9);

        tableWidget_nextWeekWork = new QTableWidget(scrollAreaWidgetContents);
        tableWidget_nextWeekWork->setObjectName(QString::fromUtf8("tableWidget_nextWeekWork"));
        tableWidget_nextWeekWork->setFont(font2);

        verticalLayout->addWidget(tableWidget_nextWeekWork);

        verticalSpacer_4 = new QSpacerItem(28, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_4);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 25));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_10);

        textEdit_need = new QTextEdit(scrollAreaWidgetContents);
        textEdit_need->setObjectName(QString::fromUtf8("textEdit_need"));
        textEdit_need->setMaximumSize(QSize(16777215, 100));
        QFont font3;
        font3.setPointSize(11);
        textEdit_need->setFont(font3);

        verticalLayout->addWidget(textEdit_need);

        verticalSpacer_5 = new QSpacerItem(28, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_5);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 25));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_11);

        textEdit_advices = new QTextEdit(scrollAreaWidgetContents);
        textEdit_advices->setObjectName(QString::fromUtf8("textEdit_advices"));
        textEdit_advices->setMaximumSize(QSize(16777215, 80));
        textEdit_advices->setFont(font3);

        verticalLayout->addWidget(textEdit_advices);

        verticalSpacer_6 = new QSpacerItem(28, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(200, 30));
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 150 , 254);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton:hover\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(44 , 137 , 255);\n"
"    border: 1px solid rgb(11 , 137 , 234);\n"
"}\n"
"\n"
"QPushButton#pushButton:pressed\n"
"{\n"
"    color:white;\n"
"    background-color:rgb(14 , 135 , 228);\n"
"    border: 1px solid rgb(12 , 138 , 235);\n"
"    padding-left:3px;\n"
"    padding-top:3px;\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_7 = new QSpacerItem(28, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_7);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 5, 0, 1, 1);

        groupBox = new QGroupBox(WeekReport);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 30));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);
        lineEdit_name->setMinimumSize(QSize(0, 30));
        QFont font5;
        font5.setPointSize(12);
        lineEdit_name->setFont(font5);
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(120, 30));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        lineEdit_position = new QLineEdit(groupBox);
        lineEdit_position->setObjectName(QString::fromUtf8("lineEdit_position"));
        lineEdit_position->setMinimumSize(QSize(0, 30));
        lineEdit_position->setFont(font5);
        lineEdit_position->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_position, 0, 4, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(120, 30));
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_department = new QLineEdit(groupBox);
        lineEdit_department->setObjectName(QString::fromUtf8("lineEdit_department"));
        lineEdit_department->setMinimumSize(QSize(0, 30));
        lineEdit_department->setFont(font5);
        lineEdit_department->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_department, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(120, 30));
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 204, 204);"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        comboBox_time = new QComboBox(groupBox);
        comboBox_time->setObjectName(QString::fromUtf8("comboBox_time"));
        comboBox_time->setMinimumSize(QSize(0, 30));
        comboBox_time->setFont(font5);
        comboBox_time->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        comboBox_time->setEditable(true);

        gridLayout->addWidget(comboBox_time, 1, 4, 1, 1);


        gridLayout_2->addWidget(groupBox, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(WeekReport);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_min = new QPushButton(WeekReport);
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

        horizontalLayout_2->addWidget(pushButton_min);

        pushButton_max = new QPushButton(WeekReport);
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

        horizontalLayout_2->addWidget(pushButton_max);

        pushButton_close = new QPushButton(WeekReport);
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

        horizontalLayout_2->addWidget(pushButton_close);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_2 = new QLabel(WeekReport);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font6;
        font6.setPointSize(19);
        font6.setBold(true);
        font6.setWeight(75);
        label_2->setFont(font6);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer_8, 3, 0, 1, 1);


        retranslateUi(WeekReport);

        QMetaObject::connectSlotsByName(WeekReport);
    } // setupUi

    void retranslateUi(QWidget *WeekReport)
    {
        WeekReport->setWindowTitle(QApplication::translate("WeekReport", "Form", nullptr));
        label_7->setText(QApplication::translate("WeekReport", "\347\233\256\345\211\215\345\217\202\344\270\216\351\241\271\347\233\256\344\273\245\345\217\212\345\256\211\346\216\222\347\232\204\344\273\273\345\212\241", nullptr));
        label_8->setText(QApplication::translate("WeekReport", "\346\234\254\345\221\250\345\267\245\344\275\234", nullptr));
        label_9->setText(QApplication::translate("WeekReport", "\344\270\213\345\221\250\345\267\245\344\275\234\350\256\241\345\210\222", nullptr));
        label_10->setText(QApplication::translate("WeekReport", "\350\265\204\346\272\220\351\234\200\346\261\202", nullptr));
        label_11->setText(QApplication::translate("WeekReport", "\345\267\245\344\275\234\345\273\272\350\256\256\345\217\212\345\205\266\344\273\226\344\272\213\351\241\271", nullptr));
        pushButton->setText(QApplication::translate("WeekReport", "\346\217\220\344\272\244", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("WeekReport", "\346\212\245\345\221\212\344\272\272", nullptr));
        lineEdit_name->setText(QString());
        label_4->setText(QApplication::translate("WeekReport", "\345\262\227\344\275\215", nullptr));
        lineEdit_position->setText(QString());
        label_5->setText(QApplication::translate("WeekReport", "\346\211\200\345\234\250\351\203\250\351\227\250", nullptr));
        lineEdit_department->setText(QString());
        label_6->setText(QApplication::translate("WeekReport", "\346\212\245\345\221\212\346\227\266\351\227\264\346\256\265", nullptr));
        label->setText(QApplication::translate("WeekReport", "\344\270\252\344\272\272\345\221\250\346\212\245", nullptr));
        pushButton_min->setText(QString());
        pushButton_max->setText(QString());
        pushButton_close->setText(QString());
        label_2->setText(QApplication::translate("WeekReport", "\344\270\252\344\272\272\345\267\245\344\275\234\345\221\250\346\212\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeekReport: public Ui_WeekReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKREPORT_H
