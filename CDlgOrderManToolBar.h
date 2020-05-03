#pragma once

#include <QWidget>
namespace Ui { class CDlgOrderManToolBar; };

class CDlgOrderManToolBar : public QWidget
{
    Q_OBJECT

public:
    CDlgOrderManToolBar(QWidget *parent = Q_NULLPTR);
    ~CDlgOrderManToolBar();
signals:
    void msigSentOnBtnCheckClicked(bool);
public slots:
    void mslotOnBtnCheckClicked();

private:
    Ui::CDlgOrderManToolBar *ui;
};
