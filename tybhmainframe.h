#ifndef TYBHMAINFRAME_H
#define TYBHMAINFRAME_H

#include <QWidget>
#include "widget.h"
#include "tybh_sub.h"
#include "tybh.h"

namespace Ui {
class TybhMainFrame;
}

class TybhMainFrame : public QWidget
{
    Q_OBJECT

public:
    explicit TybhMainFrame(QWidget *parent = 0);
    ~TybhMainFrame();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    static void proTypeComboxInit(QComboBox *,QString type = "");
    void uiInit();
private slots:
    void on_pushButton_min_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_new_clicked();
    void flushTableSlot(); //刷新tablewidget
    void on_comboBox_proType_currentTextChanged(const QString &arg1);
    void dealCellEnteredSlot(int row,int col);
    void dealCellClickedSlot(int,int);
    void dealMenu(QPoint);
    void dealEditSlot();
    void dealDeleteSlot();
private:
    Ui::TybhMainFrame *ui;
    bool dragWindow;
    QPoint position;
};

#endif // TYBHMAINFRAME_H
