#ifndef QRCODE_H
#define QRCODE_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Qrcode;
}

class Qrcode : public QWidget
{
    Q_OBJECT

public:
    explicit Qrcode(QString showString,QWidget *parent = 0);
    ~Qrcode();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::Qrcode *ui;
    bool dragWindow;
    QPoint position;
};

#endif // QRCODE_H
