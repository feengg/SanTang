#ifndef KCGL_H
#define KCGL_H

#include <QWidget>
#include <QMouseEvent>
#include "widget.h"
#include "bom.h"

namespace Ui {
class KCGL;
}

class KCGL : public QWidget
{
    Q_OBJECT

public:
    explicit KCGL(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    ~KCGL();

    void searchFlush();

    QString getCellValue(QAxObject *axSheet, int row, int col);
    void setCellFontBold(QAxObject * storeWorksheet,int row, int column);
    void setCellString(QAxObject * workSheet,int row, int column, const QString& value);

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void flushStockShow();
    void dealMenu(QPoint pos);
    void dealChuku();
    void dealLook();
    void dealEdit();
    void dealDelete();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_lineEdit_Num_textChanged(const QString &arg1);

    void on_lineEdit_serialID_textChanged(const QString &arg1);

    void on_lineEdit_name_textChanged(const QString &arg1);

    void on_lineEdit_ID_textChanged(const QString &arg1);

    void on_lineEdit_privoder_textChanged(const QString &arg1);

    void on_lineEdit_proID_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_lineEdit_inTime_textChanged(const QString &arg1);

    void on_toolButton_time_clicked();

    void on_calendarWidget_selectionChanged();

    void on_pushButton_wlbh_clicked();

    void on_pushButton_daoru_clicked();

    void on_pushButton_daochu_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::KCGL *ui;
    bool dragWindow;
    QPoint position;
    QAction * action_chuku;
    QAction * action_menu1;
    QAction * action_menu2;
    QAction * action_menu3;
    QMenu * popMenu;
    QSqlQueryModel * model;
};

#endif // KCGL_H
