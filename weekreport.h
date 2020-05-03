#ifndef WEEKREPORT_H
#define WEEKREPORT_H

#include <QWidget>
#include "widget.h"
#include <QScrollArea>

namespace Ui {
class WeekReport;
}

class WeekReport : public QWidget
{
    Q_OBJECT

public:
    explicit WeekReport(const QString showType,QString name,const QString time,QWidget *parent = 0);
    ~WeekReport();
    void mousePressEvent(QMouseEvent * event);

    void mouseMoveEvent(QMouseEvent * event);

    void mouseReleaseEvent(QMouseEvent *event);

    void initTableForNew();

    void initAllTable();//初始化所以表共同特性

    QTableWidgetItem * getNewLineIconItem(); //实例化一个新的新增一行item

    void showReportToTable(QString );

signals:

    void sendFatherFlushTableSig();

private slots:
    void on_pushButton_min_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_max_clicked();

    void dealNowWorkCellClickedSlot(int,int);

    void dealThisWeekWorkCellClickedSlot(int,int);

    void dealNextWeekWorkCellClickedSlot(int,int);

    void on_pushButton_clicked();

private:
    Ui::WeekReport *ui;
    bool dragWindow;
    QPoint position;
    QString showType;
    QString name;
    QString time;
};

#endif // WEEKREPORT_H
