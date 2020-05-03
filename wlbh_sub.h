#ifndef WLBH_SUB_H
#define WLBH_SUB_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Wlbh_sub;
}

class Wlbh_sub : public QWidget
{
    Q_OBJECT

public:
    explicit Wlbh_sub(QWidget *parent = 0);
    ~Wlbh_sub();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_toolButton_clicked();

    void on_pushButton_newNum_clicked();

    void on_pushButton_save_clicked();

signals:
    emit int emitFlushWlbhTableSig();

private:
    Ui::Wlbh_sub *ui;
    bool dragWindow;
    QPoint position;
};

#endif // WLBH_SUB_H
