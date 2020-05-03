#ifndef KQHZ_SUB_H
#define KQHZ_SUB_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class KQHZ_Sub;
}

class KQHZ_Sub : public QWidget
{
    Q_OBJECT

public:
    explicit KQHZ_Sub(QString time,QString staffId,QWidget *parent = 0);
    ~KQHZ_Sub();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_toolButton_clicked();

    void on_pButtonOk_clicked();

    void clickedToShowSlot(int x,int y);
private:
    Ui::KQHZ_Sub *ui;
    bool dragWindow;
    QPoint position;
};

#endif // KQHZ_SUB_H
