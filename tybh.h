#ifndef TYBH_H
#define TYBH_H
#include "widget.h"
#include <QWidget>
#include <QMouseEvent>
#include <QSet>
#include "uporloadfiledialog.h"

namespace Ui {
class TYBH;
}

class TYBH : public QWidget
{
    Q_OBJECT

public:
    explicit TYBH(QString showType,QString proNum,QWidget *parent = 0);
    ~TYBH();

    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    QTableWidgetItem * newSaveAndNewItem( QString type);

    void tableInit(QString);
    void showTable(QString,QString);
    bool sendNotice(QString name,QByteArray sendMsg);
private:
    Ui::TYBH *ui;
    bool dragWindow;
    QPoint position;
    QComboBox * leaderDealCombox;
    QSet<QString>nameSet;
    bool saveFlag = false;//内容改动后保存开关
    QMap<int,QComboBox *>dealComboMap;

signals:
    void sendFlushFatherTableSig();

private slots:
    void dealTableDoubleClickedSlot(QTableWidgetItem * item);
    void on_toolButton_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_new_clicked();

    void on_flushProjNumComboSlot();
    void on_comboBox_proNum_currentTextChanged(const QString &arg1);

    void dealCellClickedSlot(int x,int y);
    void on_pushButton_sendMsg_clicked();
    void dealItemTextChangedSlot(QTableWidgetItem*);
    void on_pushButton_min_clicked();
    void comboChangeSlot(QString);
    void on_pushButton_getOver_clicked();

    void getFileNameFromUpDialogSlot(QString,int);
};

#endif // TYBH_H
