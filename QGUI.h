#pragma once

#include <QWidget>
namespace Ui { class QGUI; };

class QGUI : public QWidget
{
    Q_OBJECT

public:
    QGUI(QWidget *parent = Q_NULLPTR);
    ~QGUI();

private:
    Ui::QGUI *ui;
};
