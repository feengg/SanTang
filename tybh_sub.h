#ifndef TYBH_SUB_H
#define TYBH_SUB_H

#include <QWidget>
#include <QMouseEvent>
#include "dakarecord.h"
#include "tybhmainframe.h"
#include "widget.h"

namespace Ui {
class Tybh_sub;
}

class Tybh_sub : public QWidget
{
    Q_OBJECT

public:
    explicit Tybh_sub(QString proNum = "",QWidget *parent = 0);
    ~Tybh_sub();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);


signals:
    void sendFlushFatherTableSig();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Tybh_sub *ui;
    bool dragWindow;
    QPoint position;
};

#endif // TYBH_SUB_H
