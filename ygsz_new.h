#ifndef YGSZ_NEW_H
#define YGSZ_NEW_H

#include <QWidget>
#include "widget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class YGSZ_New;
}

class YGSZ_New : public QWidget
{
    Q_OBJECT

public:
    explicit YGSZ_New(int show_model = 0,QWidget *parent = 0,QString staffID = NULL,QString name = NULL,QString sex =NULL,QString department = NULL,QString position=NULL,QString marriage = NULL
            ,QString phone=NULL,QString ip=NULL,QString address=NULL,QString workTime=NULL,QString edu = NULL,QString idCard = NULL);
    ~YGSZ_New();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void emitFlushYgszSig();
private slots:
    void on_toolButton_2_clicked();

    void on_pushButton_clicked();

    void on_toolButton_time_clicked();

    void on_calendarWidget_selectionChanged();



private:
    Ui::YGSZ_New *ui;
    int showModel = 0; //0是新增，1是修改，2是查看
    bool dragWindow;
    QPoint position;
};

#endif // YGSZ_NEW_H
