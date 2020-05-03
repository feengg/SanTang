#ifndef CHUCHAI_H
#define CHUCHAI_H

#include <QWidget>
#include <QMouseEvent>
#include "widget.h"
#include <QGroupBox>
#include <QComboBox>
#include <QTextEdit>

namespace Ui {
class ChuChai;
}

class ChuChai : public QWidget
{
    Q_OBJECT

public:
    explicit ChuChai(QString showType,QString name = "",QString dealTime = "",QWidget *parent = 0);
    ~ChuChai();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void allComboxInit();
    void trafficCheckBoxInit();
    void showByLookOrRefuse(QString showType,QString name,QString dealTime);
    static void setComboxStyle(QComboBox *,QGroupBox *,QComboBox *,QTextEdit *);
signals:
    void emitFlushShowStreamSig(QString);
    void sendFlushDclSig();

private slots:
    void on_pushButton_min_clicked();

    void on_pushButton_close_clicked();

    void on_calendarWidget_selectionChanged();



    void on_toolButton_startDay_clicked();

    void on_toolButton_endDay_clicked();

    void on_pButtonCancel_clicked();

    void on_pButtonOk_clicked();

    void trafficCheckBoxClickedSlot();
private:
    Ui::ChuChai *ui;
    bool dragWindow;
    QPoint position;

    QString selectDayType;

    QButtonGroup * btnGroup;
    QString trafficWay = "NO";
};

#endif // CHUCHAI_H
