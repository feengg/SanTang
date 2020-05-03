/********************************************************************************
** Form generated from reading UI file 'leavemsg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEAVEMSG_H
#define UI_LEAVEMSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeaveMsg
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton_leaveMsg;
    QPushButton *pushButton_close;
    QPushButton *pushButton_flush;

    void setupUi(QWidget *LeaveMsg)
    {
        if (LeaveMsg->objectName().isEmpty())
            LeaveMsg->setObjectName(QString::fromUtf8("LeaveMsg"));
        LeaveMsg->resize(1200, 860);
        textEdit = new QTextEdit(LeaveMsg);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(360, 120, 740, 680));
        textEdit->setReadOnly(true);
        pushButton_leaveMsg = new QPushButton(LeaveMsg);
        pushButton_leaveMsg->setObjectName(QString::fromUtf8("pushButton_leaveMsg"));
        pushButton_leaveMsg->setGeometry(QRect(210, 730, 141, 71));
        pushButton_leaveMsg->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image: url(:/images/leaveMsgPics/writeMsg.png);\n"
"	\n"
"	color: rgb(85, 0, 0);\n"
"	font: 20pt \"\351\232\266\344\271\246\";\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	color: rgb(0, 0, 255);\n"
"	border-image: url(:/images/leaveMsgPics/writeMsg-hover.png);\n"
"	font: 20pt \"\351\232\266\344\271\246\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	font: 20pt \"\351\232\266\344\271\246\";\n"
"	color: rgb(255, 0,0);\n"
"	\n"
"	border-image: url(:/images/leaveMsgPics/writeMsg-pressed.png);\n"
"}"));
        pushButton_close = new QPushButton(LeaveMsg);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(1178, 0, 20, 20));
        pushButton_close->setMinimumSize(QSize(20, 20));
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
        pushButton_flush = new QPushButton(LeaveMsg);
        pushButton_flush->setObjectName(QString::fromUtf8("pushButton_flush"));
        pushButton_flush->setGeometry(QRect(210, 120, 141, 71));
        pushButton_flush->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image: url(:/images/leaveMsgPics/writeMsg.png);\n"
"	\n"
"	color: rgb(85, 0, 0);\n"
"	font: 20pt \"\351\232\266\344\271\246\";\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	color: rgb(0, 0, 255);\n"
"	border-image: url(:/images/leaveMsgPics/writeMsg-hover.png);\n"
"	font: 20pt \"\351\232\266\344\271\246\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	font: 20pt \"\351\232\266\344\271\246\";\n"
"	color: rgb(255, 0,0);\n"
"	\n"
"	border-image: url(:/images/leaveMsgPics/writeMsg-pressed.png);\n"
"}"));

        retranslateUi(LeaveMsg);

        QMetaObject::connectSlotsByName(LeaveMsg);
    } // setupUi

    void retranslateUi(QWidget *LeaveMsg)
    {
        LeaveMsg->setWindowTitle(QApplication::translate("LeaveMsg", "Form", nullptr));
        pushButton_leaveMsg->setText(QApplication::translate("LeaveMsg", " \347\225\231\350\250\200", nullptr));
        pushButton_close->setText(QString());
        pushButton_flush->setText(QApplication::translate("LeaveMsg", " \345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeaveMsg: public Ui_LeaveMsg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEAVEMSG_H
