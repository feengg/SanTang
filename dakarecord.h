#ifndef DAKARECORD_H
#define DAKARECORD_H

#include <QWidget>
#include <QMouseEvent>
#include "widget.h"

namespace Ui {
class DaKaRecord;
}

class DaKaRecord : public QWidget
{
    Q_OBJECT

public:
    explicit DaKaRecord(QString name,QWidget *parent = 0);
    ~DaKaRecord();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void saveDaKaRecordToSql();
    int getDayOfWeek(QString dayTime);
    void showMonthRecordToTableWidget();
    QString getWeekString(int dayNum);
    void initNameCombox(const QString type = "");

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_inputExcel_clicked();

    void on_pushButton_search_clicked();

    void on_comboBox_name_currentTextChanged(const QString &arg1);

    void on_comboBox_year_currentTextChanged(const QString &arg1);

    void on_comboBox_mouth_currentTextChanged(const QString &arg1);

private:
    Ui::DaKaRecord *ui;
    bool dragWindow;
    QPoint position;
    QString userName;
};

#endif // DAKARECORD_H
