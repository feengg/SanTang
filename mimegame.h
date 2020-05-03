#ifndef MIMEGAME_H
#define MIMEGAME_H

#include <QWidget>
#include <QMap>
#include "mymimebtn.h"
#include <QGridLayout>
#include <QGroupBox>

namespace Ui {
class MimeGame;
}

typedef struct
{
    QString name;
    int easySum = 0;
    int easySuccess = 0;
    int easyBestTime = 99999;
    int midSum = 0;
    int midSuccess = 0;
    int midBestTime = 99999;
    int hardSum = 0;
    int hardSuccess = 0;
    int hardBestTime = 99999;
}Data;

class MimeGame : public QWidget
{
    Q_OBJECT

public:
    explicit MimeGame(QWidget *parent = 0);
    ~MimeGame();
    void setWidgetShadow(QWidget *widget);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

    void initGame();
    void newMineBtn(int rowMaxNum,int colMaxNum);
    void layMines(int,int);
    void initAllMineBtnAroundMineNum(int maxRow,int maxCol);
    void recursionShowBlankBtn(int row,int col);
    void gameOverShowAllMinesBtn();
    void showTimeAndMineNumBtn(bool showFlag);
    void startGameTimer();
    void checkIfGameSuccess();
    void getMineDataFromSql(Data *);
    void setMineDataToSql(Data *);
    void setLabelShadow();
    void setFusionStyle();
    void getBillBoardRecord();
    void showBillBoard(QMultiMap<int,QMap<QString,int>>::iterator mapBegin,QMultiMap<int,QMap<QString,int>>::iterator mapEnd
                       ,QVector<QGroupBox*> &groupVec,QVBoxLayout *verticalLayout);

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_min_clicked();

    void dealMineBtnClickedSlot(int,int);
    void on_comboBox_gameLevel_currentIndexChanged(int index);
    void dealMineBtnDoubleClickedSlot(int,int);
    void on_pushButton_reStart_clicked();
    void getGameTimerTimeOutSlot();
    void on_tabWidget_tabBarClicked(int index);

    void on_comboBox_rateType_currentTextChanged(const QString &arg1);

private:
    Ui::MimeGame *ui;
    bool dragWindow;
    QPoint position;
    //save mineBtn Map
    QMap<uint,MyMimeBtn*>allMineBtnMap;
    //
    QGridLayout * btnGridLayout;
    //
    int maxRowNum = 16;
    int maxColNum = 30;
    int btnSum = 480;
    int allMineNum = 99;
    int groupBoxWidth = 971;
    int groupBoxHeight = 530;
    //
    bool isFirstClickedMineBtn = false;
    QTimer * gameTimer = nullptr;
    int i = 0;
    //
    QMultiMap<int,QMap<QString,int>>easyBestTimeMap;
    QMultiMap<int,QMap<QString,int>>midBestTimeMap;
    QMultiMap<int,QMap<QString,int>>hardBestTimeMap;
    QMultiMap<int,QMap<QString,int>>easyWinRateMap;
    QMultiMap<int,QMap<QString,int>>midWinRateMap;
    QMultiMap<int,QMap<QString,int>>hardWinRateMap;
    //
    QVector<QGroupBox*>allMyGroupEasy;
    QVector<QGroupBox*>allMyGroupMid;
    QVector<QGroupBox*>allMyGroupHard;
};

#endif // MIMEGAME_H
