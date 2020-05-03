#ifndef LEAVEMSG_H
#define LEAVEMSG_H

#include <QWidget>
#include "widget.h"
#include "emailframe.h"

namespace Ui {
class LeaveMsg;
}

class LeaveMsg : public QWidget
{
    Q_OBJECT

public:
    explicit LeaveMsg(QWidget *parent = 0);
    ~LeaveMsg();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);



private slots:
    void on_pushButton_close_clicked();
    void on_pushButton_leaveMsg_clicked();

    void getMsgFromSubFormSlot(int picNum,bool ifAnonymous,QString msgContent);
    void showMsgHtmlToTextEdit();
    void flushTextEditHtmlSlot();//定时下载刷新html

    void on_pushButton_flush_clicked();

private:
    Ui::LeaveMsg *ui;
    bool dragWindow;
    QPoint position;
    QString msgHeader;
    //is write msg falg
    bool isWrittingMsgFlag = false;
    QTimer * flushHtmlTimer = nullptr;
};

#endif // LEAVEMSG_H
