#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "basewindow.h"
#include <QWidget>
#include <QMouseEvent>


namespace Ui {
    class LoginWindow;
}

// 登录状态;
typedef enum
{
    ONLINE = 1,     //在线;
    ACTIVE,			//活跃;
    AWAY,           //离开;
    BUSY,           //忙碌;
    NOT_DISTURB,	//请勿打扰;
    HIDE,           //隐身;
    OFFLINE			//离线;
}LoginState;

class LoginWindow : public BaseWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    static QString userName;
    static QString staffID;
    static QString myIP;
    static QString version;
    static QString myPassWord;
    static int userLevel;
private slots:
    void showMinKeyBoardSlot();

    void displayInputContent(QString text);

    void on_pButtongFlicker_clicked();

    void on_loginButton_clicked();

    void on_pButtonForgetPassword_clicked();

    void getCloseThisSlot();
    void on_pushButton_setting_clicked();

private:
    void initMyTitle() ;
    void initWindow();
    bool closeFlag = false;


private:
    Ui::LoginWindow *ui;
    // 密码框小键盘按钮;
    QPushButton* m_keyboardButton;
    bool dragWindow;
    QPoint position;

    QByteArray staffId = NULL;

};

#endif // LOGINWINDOW_H
