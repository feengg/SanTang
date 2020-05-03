#ifndef CHUKUFORM_H
#define CHUKUFORM_H

#include <QWidget>

namespace Ui {
class ChuKuForm;
}

class ChuKuForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChuKuForm(QString id,int num,int haveChuku,QWidget *parent = 0);
    ~ChuKuForm();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sendFlushTableSig();
private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_clicked();

private:
    Ui::ChuKuForm *ui;
    QString termID;
    int haveOutNum;
    int kuChuNum;
    bool dragWindow;
    QPoint position;
};

#endif // CHUKUFORM_H
