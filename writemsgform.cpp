#include "writemsgform.h"
#include "ui_writemsgform.h"
#include "emailframe.h"

WriteMsgForm::WriteMsgForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WriteMsgForm)
{
    ui->setupUi(this);
    //
    this->setWindowFlags(Qt::FramelessWindowHint);
    //
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/leaveMsgPics/leaveMsg.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(palette);
    //设置阴影
    EmailFrame::setWidgetShadow(ui->textEdit);
    //
    ui->textEdit->setStyleSheet(tr("QTextEdit{border:0px;	border-image: url(:/images/EmailImage/textBackGround/7.png);}"));
    this->setWindowTitle("留言");
    //设置透明度
    setWindowOpacity(0.95);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | this->windowFlags());
    ui->comboBox->setStyle(QStyleFactory::create("fusion"));
    ui->checkBox->setStyle(QStyleFactory::create("fusion"));
    //设置头像combox
    for(int i = 0;i != 29;++i)
    {
        QPixmap icon(50,50);
        icon.load(tr(":/images/leaveMsgPics/%1.png").arg(i));
        ui->comboBox->addItem(icon,"");
    }
    ui->comboBox->setCurrentIndex(QDateTime::currentDateTime().toTime_t()%28);
    //
    ui->scrollArea->setStyle(QStyleFactory::create("fusion"));
    //初始化表情
    if(allFaceBtnVec.size())
        allFaceBtnVec.clear();
    //添加布局器
    QGridLayout * btnGridLayout = new QGridLayout(ui->scrollAreaWidgetContents);
    for(int i = 0;i != 58;++i)
    {
        QPushButton * btn = new QPushButton;
        btn->setCheckable(true);
        btn->setMinimumSize(50,50);
        btn->setMaximumSize(50,50);
        connect(btn,SIGNAL(clicked(bool)),this,SLOT(dealFaceBtnCheckedSlot()));
        btn->setStyleSheet(tr("QPushButton{border:0px;border-image: url(:/images/facePictures/%1.png);}").arg(i));
        allFaceBtnVec.push_back(btn);
        btnGridLayout->addWidget(btn,i/10,i%10);
    }
    ui->scrollArea->hide();
}

WriteMsgForm::~WriteMsgForm()
{
    delete ui;
}

void WriteMsgForm::on_pushButton_close_clicked()
{
    this->close();
}

void WriteMsgForm::on_pushButton_submit_clicked()
{
    if(ui->textEdit->toPlainText().trimmed().isEmpty())
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("未填写留言信息！");
        dontUpdate->show();
        return;
    }
    ui->textEdit->moveCursor(QTextCursor::Start);
    ui->textEdit->insertPlainText(QString("      留言："));
    emit sendMsgToFatherSig(ui->comboBox->currentIndex(),ui->checkBox->isChecked(),ui->textEdit->toHtml());
    this->close();
}
//下面三个函数实现没有边框的窗体鼠标移动功能
void WriteMsgForm::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        position = event->globalPos() - this->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        dragWindow = true;
    }

}

void WriteMsgForm::mouseReleaseEvent(QMouseEvent *)
{
    dragWindow = false;
    setCursor(Qt::ArrowCursor);
}


void WriteMsgForm::mouseMoveEvent(QMouseEvent *event)
{
    if(dragWindow && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - position);
        event->accept();
    }
}

void WriteMsgForm::on_pushButton_face_clicked()
{
    for(int i = 0;i != allFaceBtnVec.size();++i)
    {
        if(allFaceBtnVec[i]->isChecked())
        {
            allFaceBtnVec[i]->click();
        }
    }
    ui->scrollArea->show();
}
void WriteMsgForm::dealFaceBtnCheckedSlot()
{
    for(int i = 0;i != allFaceBtnVec.size();++i)
    {
        if(allFaceBtnVec[i]->isChecked())
        {
            ui->scrollArea->hide();
            ui->textEdit->insertHtml(tr("<img src="":/images/facePictures/%1.png"" />").arg(i));
            break;
        }
    }

}
