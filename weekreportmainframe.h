#ifndef WEEKREPORTMAINFRAME_H
#define WEEKREPORTMAINFRAME_H

#include <QWidget>
#include "widget.h"

namespace Ui {
class WeekReportMainFrame;
}

class WeekReportMainFrame : public QWidget
{
    Q_OBJECT

public:
    explicit WeekReportMainFrame(QWidget *parent = 0);
    ~WeekReportMainFrame();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void initNameCombox();
    void initYearCombox();
    void initPeriodCombox();

    void initTableWidget();
    void saveAllNameVec();

private slots:
    void on_pushButton_min_clicked();

    void on_pushButton_close_clicked();

    void on_comboBox_name_currentTextChanged(const QString &arg1);

    void on_comboBox_year_currentTextChanged(const QString &arg1);

    void on_comboBox_period_currentTextChanged(const QString &arg1);

    void on_pushButton_newReport_clicked();

    void showReportToTable();

    void dealDeleteSlot();

    void dealMenu(QPoint pos);

    void dealCellClickedSlot(int,int);
    void on_pushButton_dontSubmit_clicked(bool flag = false);

    void on_pushButton_sendTipMsg_clicked();



private:
    Ui::WeekReportMainFrame *ui;
    bool dragWindow;
    QPoint position;
    //保存所有员工名字
    QVector<QString>allNameVec;
    QMap<QString,QString>allNameAndIpMap;
    QVector<QString>dontSentNameVec;
};

#endif // WEEKREPORTMAINFRAME_H
