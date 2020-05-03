#ifndef JIABAN_H
#define JIABAN_H

#include <QWidget>
#include <QMouseEvent>
#include <QButtonGroup>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Jiaban;
}

class Jiaban : public QWidget
{
    Q_OBJECT

public:
    explicit Jiaban(QString showModel,QString name=NULL,QString department=NULL,QString dealTime=NULL,QString jbTimeArea=NULL,
                    QString jbStartTime=NULL,QString jbEndTime=NULL,QString jbReason=NULL,QString jbContent=NULL,
                    QString jbFoodValue=NULL,QString jbFoodMoney=NULL,QString leaderName=NULL,
                    QString dealResult=NULL,QString leaderAdvice=NULL,QWidget *parent = 0);
    ~Jiaban();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void emitFlushShowStreamSig(QString type);
    void sendFlushDclSig();
private slots:


    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_calendarWidget_jbStartTime_selectionChanged();


    void on_calendarWidget_jbEndTime_selectionChanged();



    void on_pushButton_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Jiaban *ui;
    bool dragWindow;
    QPoint position;
    QButtonGroup * btnGroup;
    int jbFoodValue = 0;
    QString showType;
};

#endif // JIABAN_H
