#ifndef KQHZ_H
#define KQHZ_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class KQHZ;
}

class KQHZ : public QWidget
{
    Q_OBJECT

public:
    explicit KQHZ(QWidget *parent = 0);
    ~KQHZ();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    void addNewTableItem(QString name);

    void addALLTableItem();

private slots:
    void on_pushButton_search_clicked();

    void on_toolButton_clicked();

    void on_pushButton_Ok_clicked();

    void clickedToShowSlot(int x,int y);


    void on_lineEdit_name_textChanged(const QString &arg1);

private:
    Ui::KQHZ *ui;
    bool dragWindow;
    QPoint position;

};

#endif // KQHZ_H
