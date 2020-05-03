/********************************************************************************
** Form generated from reading UI file 'writemsgform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITEMSGFORM_H
#define UI_WRITEMSGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WriteMsgForm
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton_submit;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QPushButton *pushButton_close;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_face;

    void setupUi(QWidget *WriteMsgForm)
    {
        if (WriteMsgForm->objectName().isEmpty())
            WriteMsgForm->setObjectName(QString::fromUtf8("WriteMsgForm"));
        WriteMsgForm->resize(656, 377);
        textEdit = new QTextEdit(WriteMsgForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 611, 241));
        pushButton_submit = new QPushButton(WriteMsgForm);
        pushButton_submit->setObjectName(QString::fromUtf8("pushButton_submit"));
        pushButton_submit->setGeometry(QRect(500, 280, 121, 51));
        pushButton_submit->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        comboBox = new QComboBox(WriteMsgForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 270, 131, 91));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(221, 245, 255);\n"
"}\n"
""));
        comboBox->setIconSize(QSize(90, 90));
        checkBox = new QCheckBox(WriteMsgForm);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(210, 280, 51, 16));
        pushButton_close = new QPushButton(WriteMsgForm);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(640, 0, 17, 17));
        pushButton_close->setMinimumSize(QSize(17, 17));
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
        scrollArea = new QScrollArea(WriteMsgForm);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 60, 601, 261));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 245, 255);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 582, 330));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 330));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_face = new QPushButton(WriteMsgForm);
        pushButton_face->setObjectName(QString::fromUtf8("pushButton_face"));
        pushButton_face->setGeometry(QRect(390, 270, 27, 27));
        pushButton_face->setMinimumSize(QSize(27, 27));
        pushButton_face->setMaximumSize(QSize(27, 27));
        pushButton_face->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	border-image: url(:/images/facePictures/face.png);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	border-image: url(:/images/facePictures/face-pressed.png);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	\n"
"	border-image: url(:/images/facePictures/face-hover.png);\n"
"}"));
        pushButton_face->raise();
        textEdit->raise();
        pushButton_submit->raise();
        comboBox->raise();
        checkBox->raise();
        pushButton_close->raise();
        scrollArea->raise();

        retranslateUi(WriteMsgForm);

        QMetaObject::connectSlotsByName(WriteMsgForm);
    } // setupUi

    void retranslateUi(QWidget *WriteMsgForm)
    {
        WriteMsgForm->setWindowTitle(QApplication::translate("WriteMsgForm", "Form", nullptr));
        pushButton_submit->setText(QApplication::translate("WriteMsgForm", " \346\217\220\344\272\244", nullptr));
        checkBox->setText(QApplication::translate("WriteMsgForm", "\345\214\277\345\220\215", nullptr));
        pushButton_close->setText(QString());
        pushButton_face->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WriteMsgForm: public Ui_WriteMsgForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITEMSGFORM_H
