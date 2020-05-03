#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassword(QString staffid,QWidget *parent = 0);
    ~ChangePassword();

    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::ChangePassword *ui;
    bool dragWindow;
    QPoint position;
};

#endif // CHANGEPASSWORD_H
