#ifndef MYPUSHBTN_H
#define MYPUSHBTN_H
#include <QPushButton>
#include <QGroupBox>
#include <QMouseEvent>

class MyPushBtn : public QPushButton
{
    Q_OBJECT
public:

    MyPushBtn(QGroupBox * groupbox,QString text,QString tip,int maxWidth,int minWidth,int minHeight,QString color="",QWidget * parent = Q_NULLPTR);
    void setBtnStyleSheet(QString style);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void sendDoubleClickedToolTipSig(QString);
private:

    QGroupBox * groupBox;
    QString btnStyle =  "border:0px;"
                        "text-align:left;"
                        "background-color: rgb(255, 255, 255,0);";
    QString groupBoxEnterStyle = "border:0px;"
                                 "color:blue;"
                                 "background-color: rgb(255, 255, 255);font: 10pt ""宋体"";";
    QString groupBoxLeaveStyle = "border:0px;"
                                 "color:black;"
                                 "background-color: rgb(255, 255, 255,100);font: 10pt ""宋体"";";
};

#endif // MYPUSHBTN_H
