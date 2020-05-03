#ifndef ABOUTOADIALOG_H
#define ABOUTOADIALOG_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class AboutOADialog;
}

class AboutOADialog : public QWidget
{
    Q_OBJECT

public:
    explicit AboutOADialog(QWidget *parent = 0);
    ~AboutOADialog();
    void mousePressEvent(QMouseEvent * event);

private slots:
    void on_toolButton_clicked();

private:
    Ui::AboutOADialog *ui;
};

#endif // ABOUTOADIALOG_H
