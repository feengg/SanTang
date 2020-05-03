#ifndef QINGJIA_H
#define QINGJIA_H

#include <QWidget>
#include <QMouseEvent>
#include "widget.h"

namespace Ui {
class QingJia;
}

class QingJia : public QWidget
{
    Q_OBJECT

public:
    explicit QingJia(QString showModel,QString name=NULL,QString department=NULL,QString dealTime=NULL,QString position = NULL,
                     QString qjStartTime=NULL,QString qjEndTime=NULL,QString qjType=NULL,QString qjDay=NULL,QString qjReason=NULL,
                     QString tipMsg=NULL,QString dptLeader=NULL,QString dptResult=NULL,QString dptAdvice=NULL,QString viceManager=NULL,
                     QString viceResult=NULL,QString viceAdvice=NULL,QString manager=NULL,QString managerResult=NULL
            ,QString managerAdvice=NULL,QString leader=NULL,QWidget *parent = 0);
    ~QingJia();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void emitFlushShowStreamSig(QString type);
    void sendFlushDclSig();
private slots:
    void on_toolButton_close_clicked();

    void on_pButtonCancel_clicked();

    void on_toolButton_qjStart_clicked();

    void on_toolButton_qjEnd_clicked();

    void on_calendarWidget_qjStartTime_selectionChanged();

    void on_calendarWidget_qjEndTime_selectionChanged();

    void on_pButtonOk_clicked();

    void on_checkBox_hx_stateChanged(int arg1);

private:
    Ui::QingJia *ui;
    bool dragWindow;
    QPoint position;
    QString showType;
    QButtonGroup * btnGroup;
    QString dealLeader;//处理时根据不同leader显示界面
};

#endif // QINGJIA_H
