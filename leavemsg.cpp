#include "leavemsg.h"
#include "ui_leavemsg.h"
#include "writemsgform.h"

LeaveMsg::LeaveMsg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeaveMsg)
{
    ui->setupUi(this);
    //
    this->setWindowFlags(Qt::FramelessWindowHint);
    //
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/leaveMsgPics/leaveMsgMain.png").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    //设置阴影
    EmailFrame::setWidgetShadow(ui->textEdit);
    //
    ui->textEdit->setStyleSheet(tr("QTextEdit{border:0px;	border-image: url(:/images/EmailImage/textBackGround/7.png);}"));
    this->setWindowTitle("留言反馈");
    //设置透明度
    setWindowOpacity(0.95);
    ui->textEdit->setStyle(QStyleFactory::create("fusion"));
    //
    msgHeader = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" />"
                "<style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                "<img src=\":/images/leaveMsgPics/%1.png\" width=\"60\" height=\"60\" />     </p>\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> "
                "<span style=\" color:#ffffff; background-color:#cc502a;\"> </span><span style=\" font-size:14pt; font-weight:600; color:#ffffff; "
                "background-color:#cc502a;\">%2</span><span style=\" font-size:14pt; color:#ffffff; background-color:#cc502a;\">:</span> "
                "<span style=\" background-color:#ffb560;\">  </span><span style=\" font-size:14pt; background-color:#ffb560;\">"
                "%3</span><span style=\" background-color:#ffb560;\">  </span></p>"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n</body></html>";
    //
    msgHeader = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" />"
                "<style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/leaveMsgPics/%1.png\" width=\"60\" height=\"60\" />     </p>\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> <span style=\" color:#ffffff; background-color:#cc502a;\"> </span>"
                "<span style=\" font-size:16pt; font-weight:600; color:#ffffff; background-color:#cc502a;\">%2</span> </p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                "<span style=\" font-size:16pt; color:#0000ff;\">         <font size='5' >%3</font> </span></p><p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n</body></html>";

    QDir dir("D:/");
    dir.mkdir("OA-Email-Data");
    dir.cd("OA-Email-Data");
    dir.mkdir("EmailFiles");
    //
//    flushHtmlTimer = new QTimer;
//    flushHtmlTimer->setInterval(1000);
//    connect(flushHtmlTimer,SIGNAL(timeout()),this,SLOT(flushTextEditHtmlSlot()));
//    flushHtmlTimer->start();
    showMsgHtmlToTextEdit();
    flushTextEditHtmlSlot();
    ui->textEdit->moveCursor(QTextCursor::End);
}

LeaveMsg::~LeaveMsg()
{
    delete ui;
}

//下面三个函数实现没有边框的窗体鼠标移动功能
void LeaveMsg::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void LeaveMsg::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void LeaveMsg::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void LeaveMsg::on_pushButton_close_clicked()
{
    this->close();
}

void LeaveMsg::on_pushButton_leaveMsg_clicked()
{
    WriteMsgForm * writeMsg = new WriteMsgForm;
    connect(writeMsg,SIGNAL(sendMsgToFatherSig(int,bool,QString)),this,SLOT(getMsgFromSubFormSlot(int,bool,QString)));
    writeMsg->show();
}

void LeaveMsg::getMsgFromSubFormSlot(int picNum, bool ifAnonymous, QString msgContent)
{
    isWrittingMsgFlag = true;
    ui->textEdit->setHtml(ui->textEdit->toHtml()+msgHeader.arg(picNum).arg(ifAnonymous?"匿名":LoginWindow::userName).arg(msgContent));
    //移动光标都文末
    ui->textEdit->moveCursor(QTextCursor::End);

    QString emailPath = "D:/OA-Email-Data/EmailFiles/LeaveMsg.html";
    QTextDocumentWriter writer(emailPath);
    bool success = writer.write(ui->textEdit->document());
    if(success)
    {
        UpOrLoadFileDialog * up = new UpOrLoadFileDialog("Up",-3,"");
        up->startUpLoadFile("D:/OA-Email-Data/EmailFiles/LeaveMsg.html");
    }
    isWrittingMsgFlag = false;
}
void LeaveMsg::showMsgHtmlToTextEdit()
{
    if(QFile::exists("D:/OA-Email-Data/EmailFiles/LeaveMsg.html"))
    {
        //加载emailHtml到textEdit
        QFile file("D:/OA-Email-Data/EmailFiles/LeaveMsg.html");
        if (file.open(QFile::ReadOnly))
        {
            QByteArray data = file.readAll();
            QTextCodec *codec = Qt::codecForHtml(data);
            QString str = codec->toUnicode(data);
            if (Qt::mightBeRichText(str))
            {

                  ui->textEdit->setHtml(str);
                    //移动光标都文末
                  ui->textEdit->moveCursor(QTextCursor::End);
            }
        }
    }
}

void LeaveMsg::flushTextEditHtmlSlot()
{
    if(isWrittingMsgFlag == false)
    {

        UpOrLoadFileDialog * downMsgHtml = new UpOrLoadFileDialog(-4);
        downMsgHtml->startDownFile("LeaveMsg.html");
        QTimer * timer  = new QTimer;
        timer->setInterval(1000);
        connect(timer,SIGNAL(timeout()),this,SLOT(showMsgHtmlToTextEdit()));
        connect(timer,SIGNAL(timeout()),timer,SLOT(stop()));
        timer->start();
    }
}

void LeaveMsg::on_pushButton_flush_clicked()
{
    flushTextEditHtmlSlot();
}
