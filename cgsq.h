#ifndef CGSQ_H
#define CGSQ_H

#include <QWidget>
#include <QMouseEvent>
//#include <QAxObject>

namespace Ui {
class CGSQ;
}

class CGSQ : public QWidget
{
    Q_OBJECT

public:
    explicit CGSQ(QString showModel=NULL,QString bomPath1=NULL,QString name=NULL,QString projectName=NULL,
                  QString department=NULL,QString dealTime=NULL,QString expectTime=NULL,
                  QString recordMsg=NULL,QString groupLeader=NULL,QString groupResult=NULL,
                  QString groupAdvice=NULL,QString dptLeader=NULL,QString dptResult=NULL,
                  QString dptAdvice=NULL,QString manager=NULL,QString managerResult=NULL,
                  QString managerAdvice=NULL,QString num=NULL,QString leader=NULL,QWidget *parent = 0);
    ~CGSQ();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    QVariant getCellValue(QAxObject *axObject, int row, int col);

    int getUsedRowsCount(QAxObject * workSheet);

signals:
    void emitFlushShowStreamSig(QString type);


private slots:
    void on_toolButton_clicked();

    void on_pushButton_cancel_clicked();



    void on_toolButton_expectTime_clicked();



    void on_calendarWidget_expectTime_selectionChanged();

    void on_pushButton_ok_clicked();



    void flushCGSQTableWidgetSlot(); //套数comb变化时，刷新table槽函数

    void on_comboBox_num_currentTextChanged(const QString &arg1);

private:
    Ui::CGSQ *ui;
    bool dragWindow;
    QPoint position;
    QString dealLeader = NULL;
    QString bomPath = NULL;
    QString show_model = NULL;
};

#endif // CGSQ_H
