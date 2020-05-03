#ifndef WAICHU_H
#define WAICHU_H

#include <QWidget>
#include <QMouseEvent>
#include "widget.h"

namespace Ui {
class WaiChu;
}

class WaiChu : public QWidget
{
    Q_OBJECT

public:
    explicit WaiChu(QString showType,QString name = "",QString dealTime = "",QWidget *parent = 0);
    ~WaiChu();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void uiInit();
    void showUI(QString showType,QString name,QString dealTime);

signals:
    void emitFlushShowStreamSig(QString);
    void sendFlushDclSig();
private slots:
    void on_pushButton_min_clicked();

    void on_pushButton_close_clicked();

    void on_toolButton_startDay_clicked();

    void on_toolButton_endDay_clicked();

    void on_toolButton_realDay_clicked();

    void on_calendarWidget_selectionChanged();

    void on_pButtonCancel_clicked();

    void on_pButtonOk_clicked();

private:
    Ui::WaiChu *ui;
    bool dragWindow;
    QPoint position;

    QString dayType;
};

#endif // WAICHU_H
