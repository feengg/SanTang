#ifndef WLBH_H
#define WLBH_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Wlbh;
}

class Wlbh : public QWidget
{
    Q_OBJECT

public:
    explicit Wlbh(QWidget *parent = 0);
    ~Wlbh();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    void showSearchResultToTable();

private slots:
    void on_pushButton_new_clicked();

    void on_pushButton_ok_clicked();

    void on_toolButton_clicked();

    void flushTableSlot();

    void on_lineEdit_wlNum_textChanged(const QString &arg1);

    void on_lineEdit_wlName_textChanged(const QString &arg1);

    void on_lineEdit_format_textChanged(const QString &arg1);

private:
    Ui::Wlbh *ui;
    bool dragWindow;
    QPoint position;
};

#endif // WLBH_H
