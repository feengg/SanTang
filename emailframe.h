#ifndef EMAILFRAME_H
#define EMAILFRAME_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSlider>
#include <QMenu>
#include <QAction>
#include "widget.h"
#include <QGraphicsDropShadowEffect>
#include "mylineedit.h"
#include "widget.h"
#include <QStyleFactory>
#include <QColorDialog>
#include <QTextCursor>
#include <QTextList>
#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QImageReader>
#include <QShortcut>
#include <QTextEdit>
#include <QAction>
#include <QTextDocumentWriter>
#include <QProcess>
#include <QBoxLayout>
#include "mypushbtn.h"
#include <QCheckBox>
#include <QTextCodec>

namespace Ui {
class EmailFrame;
}

class EmailFrame : public QWidget
{
    Q_OBJECT

public:
    explicit EmailFrame(QWidget *parent = 0);
    ~EmailFrame();
    void uiInit();
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    static void setMaxScreen(QWidget * ui,const QString picPath,int midWidth,int midHeight);
    QString MenuStyle();
    //btnGroup
    void havetTheBtnGroup();
    //
    void setLabelShadow();

    //
    static void setWidgetShadow(QWidget *);

    void getAllUserNameToVec();

    void makeTextEditBackPicWidget();

    void initTextColorComboBox();

    void mergeFormatOnWordOrSelection(const QTextCharFormat &);

    void insertFromMimeData(const QMimeData *);

    void dropImage(const QUrl &, const QImage &);

    void dropTextFile(const QUrl &);

    QString makeEmailDataFolder();

    //init receive box
    void initRecvBoxTab();
    //init sent box
    void initSentBoxTab();
    //init look tab ui
    void initLookUi();
    //
    void saveSettingToLocalFile();
    void getParaFromLocalFileAndSet();

signals:
    void sendToWidgetToCheckIfHaveEmailToRead();

private slots:
    void on_pushButton_tr_clicked();

    void on_horizontalSlider_opacity_valueChanged(int value);

    void on_pushButton_min_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_max_clicked();


    void initMoveBtnAndSliderTimerSlot();
    //皮肤设置槽
    void setSkin1Slot();
    void setSkin2Slot();
    void setSkin3Slot();
    void setSkin4Slot();
    void setSkin5Slot();
    void setSkin6Slot();
    void setSkin7Slot();



    void on_pushButton_recvBox_clicked();

    void on_pushButton_sentBox_clicked();

    void on_pushButton_write_clicked();

    void on_pushButton_look_clicked();

    void on_lineEdit_recver_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_recver_returnPressed();

    void on_pushButton_appendix_clicked();

    void on_pushButton_delAppendix_clicked();

    void on_pushButton_addRecver_clicked(bool);

    void dealSendNamesToLineEdit();

    void dealCopyNamesToLineEdit();

    void on_pushButton_backGround_clicked();

    void dealTextEditBackPicBtnSlot();



    void on_pushButton_bold_clicked();

    void on_pushButton_italic_clicked();

    void on_pushButton_underLine_clicked();

    void on_pushButton_textLeft_clicked();

    void on_pushButton_textCenter_clicked();

    void on_pushButton_textRight_clicked();

    void on_pushButton_dayTime_clicked();


    void on_fontComboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_fontSize_currentIndexChanged(int index);

    void on_comboBox_fontColor_currentIndexChanged(int index);

    void on_comboBox_fontBackColor_currentIndexChanged(int index);

    void on_comboBox_orderList_currentIndexChanged(int index);

    void clipboardDataChangedSlot();

    void on_pushButton_emailSend_clicked();

    void on_pushButton_insertPic_clicked();



    void on_pushButton_deleteRecv_clicked();

    void on_pushButton_deleteSent_clicked();

    //show Look
    void showEmailLookSlot(QString emailHtml);

    void on_pushButton_downAppendix_clicked();
    void showEmailToTextEditSlot();

    void on_pushButton_reply_clicked();

    void hideSkinActionSlot();
    //init write tab widget
    void initWriteTab();
    void on_pushButton_addCopy_clicked();

private:
    Ui::EmailFrame *ui;
    bool dragWindow;
    QPoint position;
    int preMidWidth = 0;
    int preMidHeigth = 0;
    QSlider * horizontalSlider_opacity;
    QPushButton * pushButton_skin;

    void setSkinAction();
    QAction * skin1;
    QAction * skin2;
    QAction * skin3;
    QAction * skin4;
    QAction * skin5;
    QAction * skin6;
    QAction * skin7;
    QTimer * moveBtnAndSliderTimer;
    //
    bool actionHideFlag = false;
    QVector<QString>userNameVec;
    QVector<QPushButton *>userNameBtnVec;
    //收件人LineEdit
    MyLineEdit * lineEdit_recver;
    //抄送LineEdit
    MyLineEdit * lineEdit_copy;
    //主题LineEdit
    MyLineEdit * lineEdit_topic;
    //背景图片vector
    QVector<QPushButton*>textBackPicBtnVec;
    //textedit background pic show widget
    QWidget * showNameWidget;
    //color combox
    QMap<int,int>indexToColorMap;
    //font size combox reference
    QMap<int,int>indexToPxMap;
    //save the text pictures filepath into vetor for upload to server
    QVector<QString>textPicPathVec;
    // email sent data flat
    bool sentToServerDataFlag = false;
    //upload appendix fileName
    QString appendixFileName;
    // textEdit background picture No.
    int textEditPicNum = 34;
    //
    bool upLoadSuccessdFlag = false;
    //已选择发送人工号Vec
    QVector<QString>sendStaffIdVec;
    //已选择抄送人工号Vec
    QVector<QString>copyStaffIdVec;
    //udp
    QUdpSocket * sendTipUdp;
    //存储我的Pushbtn
    QVector<QGroupBox *>allMyGroupRecord;
    QVector<QGroupBox *>allMyGroupSent;
    QVector<QCheckBox *>saveCheckBoxVec;
    //
    QTimer * waitDownTimer;
    QString waitLoadEmailFileName;
    QString headerHtmlStr;//回信时的头信息
    //
    bool dealingSkinActionFlag = false;
    //配置变量
    QString mainBackGroundStr = ":./images/background/bg2.jpg";
    QString opacityStr = "95";
    QString textEditBackGroundStr = "34";
    bool hasInitWriteFlag = false;
};

#endif // EMAILFRAME_H
