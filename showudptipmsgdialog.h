#ifndef SHOWUDPTIPMSGDIALOG_H
#define SHOWUDPTIPMSGDIALOG_H

#include <QDialog>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QPoint>

namespace Ui {
class showUdpTipMsgDialog;
}

class showUdpTipMsgDialog : public QDialog
{
    Q_OBJECT

public:
    explicit showUdpTipMsgDialog(QString tipMsg = NULL,QWidget *parent = 0);
    ~showUdpTipMsgDialog();
    void showAnimation();

private:
    Ui::showUdpTipMsgDialog *ui;
    QDesktopWidget desktop;
    QPropertyAnimation* animation;

signals:
    emit int emitShowWidgetSig(QString tipMsg = NULL);

private slots:
    void closeAnimation();
    void clearAll();
    void on_pushButton_clicked();

    void on_toolButton_clicked();
};

#endif // SHOWUDPTIPMSGDIALOG_H
