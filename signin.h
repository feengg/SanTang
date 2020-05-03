#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "widget.h"

namespace Ui {
class SignIn;
}



class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    static QString userName;
    static QString staffID;
    static QString myIP;
    static int userLevel;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    bool dragWindow;
    QPoint position;
    Ui::SignIn *ui;
};



#endif // SIGNIN_H
