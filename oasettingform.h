#ifndef OASETTINGFORM_H
#define OASETTINGFORM_H

#include <QWidget>

namespace Ui {
class OASettingForm;
}

class OASettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit OASettingForm(QWidget *parent = 0);
    ~OASettingForm();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_clicked();

private:
    Ui::OASettingForm *ui;
    bool dragWindow;
    QPoint position;
};

#endif // OASETTINGFORM_H
