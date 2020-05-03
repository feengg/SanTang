#ifndef CHOOSETYPE_H
#define CHOOSETYPE_H

#include <QWidget>
#include <QMouseEvent>
#include <QButtonGroup>

namespace Ui {
class chooseType;
}

class chooseType : public QWidget
{
    Q_OBJECT

public:
    explicit chooseType(QWidget *parent = 0);
    ~chooseType();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void emitToJiabanToFlushStreamListSig(QString type);

private slots:
    void on_pushButton_2_clicked();

    void onRadioClickedSlot();

    void on_pushButton_clicked();

    void getJbSigSlot(QString type);

private:
    Ui::chooseType *ui;
    bool dragWindow;
    QPoint position;
    QButtonGroup * btnGroup;
    QString choose_type = "加班";
};

#endif // CHOOSETYPE_H
