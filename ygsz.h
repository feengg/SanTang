#ifndef YGSZ_H
#define YGSZ_H

#include <QWidget>
#include <QMouseEvent>
#include <QSqlQueryModel>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QTableWidgetItem>
#include <QDesktopWidget>
#include "ygsz_new.h"
#include "ygsz_authority.h"
#include <QComboBox>

namespace Ui {
class YGSZ;
}

class YGSZ : public QWidget
{
    Q_OBJECT

public:
    explicit YGSZ(QWidget *parent = 0);
    ~YGSZ();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    void flushStaffShow();
    static void departmentComboBoxInit(QComboBox *);

private slots:
    void on_toolButton_Close_clicked();

    void dealMenu(QPoint pos);
    void dealLook();
    void dealEdit();
    void dealDelete();
    void dealOffWork();
    void flushTableForSearch();
    //void on_toolButton_clicked();

    void on_toolButton_New_clicked();

    void flushShowSlot();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_toolButton_Change_clicked();

    void on_toolButton_Mini_clicked();

    void on_comboBox_department_currentTextChanged(const QString &arg1);

    void on_comboBox_sex_currentTextChanged(const QString &arg1);

    void on_comboBox_workState_currentTextChanged(const QString &arg1);

private:
    Ui::YGSZ *ui;
    bool dragWindow;
    QPoint position;
    QAction * action_menu1;
    QAction * action_menu2;
    QAction * action_menu3;
    QAction * action_menu_offWork;
    QMenu * popMenu;
};

#endif // YGSZ_H
