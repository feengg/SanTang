#ifndef YGSZ_AUTHORITY_H
#define YGSZ_AUTHORITY_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class YGSZ_Authority;
}

class YGSZ_Authority : public QWidget
{
    Q_OBJECT

public:
    explicit YGSZ_Authority(QWidget *parent = 0);
    ~YGSZ_Authority();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void flushShowAuth(int level);
private slots:
    void on_toolButton_clicked();
    void flushShowAuthSlot();//获取刷新ygsz_authority.ui里的lineEdit信号
    void on_pushButton_super_clicked();

    void on_pushButton_kcgl_2_clicked();

    void on_pushButton_kcgl_clicked();

    void on_pushButton__kccw_clicked();

    void on_pushButton__store_clicked();

    void on_pushButton__caigou_clicked();

    void on_pushButton__tybh_clicked();

    void on_pushButton__wlbh_clicked();

private:
    Ui::YGSZ_Authority *ui;
    bool dragWindow;
    QPoint position;
};

#endif // YGSZ_AUTHORITY_H
