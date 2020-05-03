#ifndef MYMIMEBTN_H
#define MYMIMEBTN_H
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>


class MyMimeBtn : public QPushButton
{
    Q_OBJECT
public:
    MyMimeBtn(int row,int col,QLabel * label = 0,QWidget *parent = 0);
    int getRow();
    int getCol();
    void setBlankStyle();
    void setNumStyle(int);
    void setMineStyle();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void setMine();
    bool checkIfMine();
    void setMineBtnSize(int);
    void setAroundMinesNum(int num);
    int  getAroundMinesNum();
    void mousePressEvent(QMouseEvent *e);//鼠标邮件标记是雷
    bool getClickState();
    bool isBlankChecked();
    void setBlankChecked();
    bool getMarkState();
    void setClicked();
    void setErrorMineStyle();
    void setMarkedMineStyle();
    void setIsNotFirstState();
    bool getIsNotFirstState();
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    bool isMine = false;
    int row;
    int col;
    bool isClicked = false;
    bool isMarked = false;
    int aroundMinesNum = 0;
    bool blankCheckedState = false;
    bool isFirstState = true;//初始状态，鼠标移进移出显示效果
    QLabel * mineLabel;

signals:
    void sendPositionSig(int row,int col);
    void sendDoubleClickedSig(int row,int col);
private slots:

    void getDoubleClickedSlot();
};

#endif // MYMIMEBTN_H
