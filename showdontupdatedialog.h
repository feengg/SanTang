#ifndef SHOWDONTUPDATEDIALOG_H
#define SHOWDONTUPDATEDIALOG_H

#include <QWidget>

namespace Ui {
class showDontUpdateDialog;
}

class showDontUpdateDialog : public QWidget
{
    Q_OBJECT

public:
    explicit showDontUpdateDialog(QString showMsg,QWidget *parent = 0);
    ~showDontUpdateDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::showDontUpdateDialog *ui;
};

#endif // SHOWDONTUPDATEDIALOG_H
