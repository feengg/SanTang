/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QComboBox *accountComboBox;
    QLineEdit *passwordEdit;
    QCheckBox *rememberPsd;
    QPushButton *loginButton;
    QPushButton *pButtonForgetPassword;
    QLabel *userHead;
    QPushButton *pButtongFlicker;
    QCheckBox *autoLogin;
    QPushButton *pushButton_setting;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(430, 330);
        LoginWindow->setMinimumSize(QSize(430, 330));
        LoginWindow->setMaximumSize(QSize(430, 330));
        LoginWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        accountComboBox = new QComboBox(LoginWindow);
        accountComboBox->setObjectName(QString::fromUtf8("accountComboBox"));
        accountComboBox->setGeometry(QRect(130, 190, 190, 30));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(accountComboBox->sizePolicy().hasHeightForWidth());
        accountComboBox->setSizePolicy(sizePolicy);
        accountComboBox->setMinimumSize(QSize(190, 30));
        accountComboBox->setMaximumSize(QSize(190, 30));
        accountComboBox->setFocusPolicy(Qt::WheelFocus);
        accountComboBox->setContextMenuPolicy(Qt::NoContextMenu);
        accountComboBox->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        accountComboBox->setEditable(false);
        accountComboBox->setInsertPolicy(QComboBox::NoInsert);
        passwordEdit = new QLineEdit(LoginWindow);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(130, 220, 190, 30));
        sizePolicy.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy);
        passwordEdit->setMinimumSize(QSize(190, 30));
        passwordEdit->setMaximumSize(QSize(190, 30));
        passwordEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        passwordEdit->setEchoMode(QLineEdit::Password);
        rememberPsd = new QCheckBox(LoginWindow);
        rememberPsd->setObjectName(QString::fromUtf8("rememberPsd"));
        rememberPsd->setGeometry(QRect(130, 260, 71, 16));
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(130, 284, 194, 30));
        loginButton->setMinimumSize(QSize(194, 30));
        loginButton->setMaximumSize(QSize(194, 30));
        loginButton->setFocusPolicy(Qt::NoFocus);
        pButtonForgetPassword = new QPushButton(LoginWindow);
        pButtonForgetPassword->setObjectName(QString::fromUtf8("pButtonForgetPassword"));
        pButtonForgetPassword->setGeometry(QRect(326, 220, 63, 23));
        userHead = new QLabel(LoginWindow);
        userHead->setObjectName(QString::fromUtf8("userHead"));
        userHead->setGeometry(QRect(40, 190, 80, 80));
        userHead->setMinimumSize(QSize(80, 80));
        userHead->setMaximumSize(QSize(80, 80));
        pButtongFlicker = new QPushButton(LoginWindow);
        pButtongFlicker->setObjectName(QString::fromUtf8("pButtongFlicker"));
        pButtongFlicker->setGeometry(QRect(395, 300, 22, 22));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pButtongFlicker->sizePolicy().hasHeightForWidth());
        pButtongFlicker->setSizePolicy(sizePolicy1);
        pButtongFlicker->setMinimumSize(QSize(22, 22));
        pButtongFlicker->setMaximumSize(QSize(22, 22));
        autoLogin = new QCheckBox(LoginWindow);
        autoLogin->setObjectName(QString::fromUtf8("autoLogin"));
        autoLogin->setGeometry(QRect(250, 260, 71, 16));
        pushButton_setting = new QPushButton(LoginWindow);
        pushButton_setting->setObjectName(QString::fromUtf8("pushButton_setting"));
        pushButton_setting->setGeometry(QRect(320, 190, 75, 23));
        pushButton_setting->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_setting\n"
"{\n"
"	color:rgb(38 , 133 , 227);\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"QPushButton#pushButton_setting:hover\n"
"{\n"
"	color:rgb(97 , 179 , 246);\n"
"}\n"
"\n"
"QPushButton#pushButton_setting:pressed\n"
"{\n"
"	color:rgb(0 , 109 , 176);\n"
"}"));
        userHead->raise();
        accountComboBox->raise();
        passwordEdit->raise();
        rememberPsd->raise();
        loginButton->raise();
        pButtonForgetPassword->raise();
        pButtongFlicker->raise();
        autoLogin->raise();
        pushButton_setting->raise();

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Dialog", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        accountComboBox->setAccessibleName(QApplication::translate("LoginWindow", "login_username", nullptr));
#endif // QT_NO_ACCESSIBILITY
        rememberPsd->setText(QApplication::translate("LoginWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        loginButton->setText(QApplication::translate("LoginWindow", "\347\231\273  \345\275\225", nullptr));
#ifndef QT_NO_SHORTCUT
        loginButton->setShortcut(QApplication::translate("LoginWindow", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        pButtonForgetPassword->setText(QApplication::translate("LoginWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        userHead->setText(QString());
#ifndef QT_NO_TOOLTIP
        pButtongFlicker->setToolTip(QApplication::translate("LoginWindow", "\347\224\237\346\210\220\350\200\203\345\213\244\344\272\214\347\273\264\347\240\201", nullptr));
#endif // QT_NO_TOOLTIP
        pButtongFlicker->setText(QString());
        autoLogin->setText(QApplication::translate("LoginWindow", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        pushButton_setting->setText(QApplication::translate("LoginWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
