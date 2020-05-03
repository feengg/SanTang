#ifndef BOM_H
#define BOM_H

#include <QWidget>
#include <QMouseEvent>
//#include <QAxObject>
#include <QFileDialog>
//#include "qexcel.h"
#include <QDebug>
#include <QMessageBox>
#include <QVariantList>
#include "widget.h"
#include "cgsq.h"

namespace Ui {
class Bom;
}

class Bom : public QWidget
{
    Q_OBJECT

public:
    explicit Bom(QWidget *parent = 0);
    ~Bom();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    QVariant static getCellValue(QAxObject * axObject,int row,int col);
    int static getUsedRowsCount(QAxObject * workSheet);
    void static setCellString(QAxObject * workSheet,int row, int column, const QVariant& value);
    void static setCellValue(QAxObject * m_word,int row,int col,QString value);

    bool static insertTable(QAxObject * m_document,QAxObject * m_word,int row,int column);

    void static setRowAlignment(QAxObject * m_document,int row,int flag);

    void static setColumnWidth(QAxObject * m_word,int column, int width);

    void static setCellFontBold(QAxObject * m_document,int row,int column);

    void static removeListSame(QStringList * list);

signals:
    void emitToCGSQToFlushStreamListSig(QString type);

private slots:
    void on_toolButton_clicked();

    void on_pushButton_loadBom_clicked();

    void on_pushButton_ok_clicked();

    void on_pushButton_cgqd_clicked();

    void on_pushButton_mxb_clicked();

    void on_pushButton_cgsq_clicked();

    void getCGSQSigSlot(QString type);

private:
    Ui::Bom *ui;
    bool dragWindow;
    QPoint position;
    QString bomFilePath = NULL;
};

#endif // BOM_H
