#ifndef YGSZ_AUTH_CHANGE_H
#define YGSZ_AUTH_CHANGE_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class YGSZ_Auth_Change;
}

class YGSZ_Auth_Change : public QWidget
{
    Q_OBJECT

public:
    explicit YGSZ_Auth_Change(QWidget *parent = 0,int level = 9); //level=权限：0为超级管理员，1为部门主任，2为总经办，9为普通员工权限
    ~YGSZ_Auth_Change();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void showAllName();
    void flushAuthorityName(int level);
private:
    Ui::YGSZ_Auth_Change *ui;
    bool dragWindow;
    QPoint position;
    int userLevel = 9;//用于保存用户权限等级。权限：0为超级管理员，1为库存管理权限，2为库存财务，9为普通员工权限
    bool isClickedLeftTabelWidgetFlag = false;//判断是否点击的tabelWidget
    bool isClickedRightTabelWidgetFlag = false;//判断是否点击的tabelWidget

signals:
    void emitFlushAuthLineEditSig();//向ygsz_authority.cpp发送刷新lineEdit的信号
private slots:

    void on_pushButton_clicked();
    void on_toolButton_clicked();
    void on_pushButton_Push_clicked();
    void on_tableWidget_All_cellClicked(int row, int column);
    void on_lineEdit_Name_textChanged(const QString &arg1);
    void on_pushButton_Pop_clicked();
    void on_tableWidget_Owner_cellClicked(int row, int column);
};

#endif // YGSZ_AUTH_CHANGE_H
