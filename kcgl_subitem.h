#ifndef KCGL_SUBITEM_H
#define KCGL_SUBITEM_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class KCGL_subItem;
}

class KCGL_subItem : public QWidget
{
    Q_OBJECT

public:
    explicit KCGL_subItem(QString showType,QString itemNum = "",QWidget *parent = 0);
    ~KCGL_subItem();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    emit int emitFlushKCGLModelSig();
private slots:
    void on_toolButton_clicked();

    void on_pushButton_clicked();





    void on_toolButton_inTime_clicked();

    void on_calendarWidget_selectionChanged();

private:
    Ui::KCGL_subItem *ui;
    bool dragWindow;
    QPoint position;
};

#endif // KCGL_SUBITEM_H
