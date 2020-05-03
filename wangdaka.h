#ifndef WANGDAKA_H
#define WANGDAKA_H

#include <QWidget>
#include <QMouseEvent>
#include "widget.h"

namespace Ui {
class WangDaKa;
}

class WangDaKa : public QWidget
{
    Q_OBJECT

public:
    explicit WangDaKa(QString showModel,QString name=NULL,QString department=NULL,QString dealTime=NULL,QString position = NULL,
                      QString wdkDay=NULL,QString wdkType=NULL,QString wdkReason=NULL,
                      QString witName=NULL,QString witResult=NULL,QString witAdvice=NULL,
                      QString dptLeader=NULL,QString dptResult=NULL,QString dptAdvice=NULL,QString viceManager=NULL,
                      QString viceResult=NULL,QString viceAdvice=NULL,QString manager=NULL,QString managerResult=NULL
             ,QString managerAdvice=NULL,QString leader=NULL,QWidget *parent = 0);
    ~WangDaKa();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void emitFlushShowStreamSig(QString type);
    void sendFlushDclSig();
private slots:
    void on_toolButton_clicked();

    void on_pushButton_Cancel_clicked();

    void on_toolButton_wdkStart_clicked();



    void on_calendarWidget_wdkStartTime_selectionChanged();





    void on_pushButton_OK_clicked();
    
private:
    Ui::WangDaKa *ui;
    QPoint position;
    bool dragWindow;
    QString dealLeader;//目前处理领导
};

#endif // WANGDAKA_H
