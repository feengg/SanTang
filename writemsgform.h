#ifndef WRITEMSGFORM_H
#define WRITEMSGFORM_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class WriteMsgForm;
}

class WriteMsgForm : public QWidget
{
    Q_OBJECT

public:
    explicit WriteMsgForm(QWidget *parent = 0);
    ~WriteMsgForm();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

    void sendMsgToFatherSig(int picNum,bool ifAnonymous,QString msgContent);

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_submit_clicked();

    void on_pushButton_face_clicked();
    void dealFaceBtnCheckedSlot();
private:
    Ui::WriteMsgForm *ui;
    bool dragWindow;
    QPoint position;
    //
    QVector<QPushButton *>allFaceBtnVec;
};

#endif // WRITEMSGFORM_H
