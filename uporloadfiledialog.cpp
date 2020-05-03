#include "uporloadfiledialog.h"
#include "ui_uporloadfiledialog.h"
#include <QDesktopServices>

UpOrLoadFileDialog::UpOrLoadFileDialog(QString showType,int row,QString downFileName,QWidget *parent) :
    QWidget(parent),tableRowNum(row),loadFileName(downFileName),
    ui(new Ui::UpOrLoadFileDialog)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    if(showType == "Up")
    {
        if(row == -1)//邮件上传文件
        {
            Widget::uiInit(this,"发送邮件");
            //ui->progressBar->hide();
            ui->pushButton->hide();
            ui->groupBox->hide();
            ui->label_state->setText("邮件正在发送中...");
            fileName = downFileName;
            //开始连接服务器上传
            sendFileFlag = true;
            connectToServerHost();
        }
        else if(row == -3)
        {
            //nothing;
        }
        else
        {
            ui->progressBar->hide();
            Widget::uiInit(this,"上传附件");
            if(row  == -2)//邮件上传附件
            {
                ui->groupBox->hide();
                ui->pushButton->hide();
                ui->progressBar->reset();
                fileName = downFileName;
                //开始连接服务器上传
                sendFileFlag = true;
                connectToServerHost();
            }
            else
            {
                ui->pushButton->setText("开始上传");
                ui->label_state->setText("请选择上传文件！");
                ui->pushButton->hide();
            }
        }

    }
    else //下载
    {
        if(tableRowNum == -5)
        {
            fileSavePath = downFileName;
            loadFileName = downFileName.mid(downFileName.lastIndexOf("/")+1,100);
            loadFileFlag = true;
            connectToServerHost();
            Widget::uiInit(this,"自动更新");
        }else
        {
            chooseSavePath();
            Widget::uiInit(this,"下载附件");
        }
        ui->groupBox->hide();
        ui->pushButton->hide();

    }
}

UpOrLoadFileDialog::~UpOrLoadFileDialog()
{
    delete ui;
}

void UpOrLoadFileDialog::on_toolButton_clicked()
{
    this->close();
}

bool UpOrLoadFileDialog::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(fileName.isEmpty())
    {
        showDontUpdateDialog * dontUpdate = new showDontUpdateDialog("未选择文件！");
        dontUpdate->show();
        return false;
    }
    ui->progressBar->reset();
    ui->label_state->setText(tr("已选择文件：%1").arg(fileName.mid(fileName.lastIndexOf("/")+1,200)));
}
void UpOrLoadFileDialog::connectToServerHost()
{
    if(tableRowNum != -4) //无界面下载
    {
        ui->progressBar->reset();
    }

    totalBytes = 0;
    payLoadSize = 64*1024;
    bytesWritten = 0;
    bytesToWrite = 0;
    if(tcpClient)
    {
        tcpClient->close();
        tcpClient = nullptr;
    }
    tcpClient = new QTcpSocket(this);
    connect(tcpClient,SIGNAL(connected()),this,SLOT(sendFlagSlot()));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(dealRecvTcpSlot()));
    bytesWritten = 0;
    qDebug() << "Widget::ip" << Widget::serverIP;
    tcpClient->connectToHost(Widget::serverIP,Widget::serverPort);
}

void UpOrLoadFileDialog::startTransfer()
{

    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    totalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    QString currentFileName = fileName.mid(fileName.lastIndexOf("/")+1,200);
    qDebug() << "fileName = " << currentFileName;
    sendOut  <<qint64(0) << qint64(0) << currentFileName;//标识位,文件总大小，文件名大小，文件名
    totalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut << totalBytes << qint64(outBlock.size()-sizeof(qint64)*2);
    bytesToWrite = totalBytes - tcpClient->write(outBlock);
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesWritten);
    outBlock.resize(0);
}

void UpOrLoadFileDialog::updateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0)
    {
        outBlock = localFile->read(qMin(bytesToWrite,payLoadSize));
        bytesToWrite -= (int)tcpClient->write(outBlock);
        outBlock.resize(0);
    }
    else
    {
        localFile->close();
    }
    if(tableRowNum != -3) //不显示界面
    {
        ui->progressBar->setMaximum(totalBytes);
        ui->progressBar->setValue(bytesWritten);
    }

    if(bytesWritten == totalBytes)
    {
        sendFileFlag = false;
        localFile->close();
        tcpClient->close();
        qDebug() << "inter here";
        if(tableRowNum == -3)
        {
            qDebug() << "inter here1";
            upLoadSuccessFlag = true;
            qDebug() << "upLoadFlag = " << upLoadSuccessFlag;
            QThread::msleep(50);
            return;
        }
        qDebug() << "inter here2";
        ui->pushButton->setText("确定");
        ui->pushButton->setEnabled(true);
        ui->pushButton->show();
        if(tableRowNum == -1)//email上传情况
        {
            ui->label_state->setText("邮件发送成功!");
            ui->pushButton->setText("确定");
        }else
        {
            emit sendFileNameAndRowNumToFatherSig(fileName.mid(fileName.lastIndexOf("/")+1,200),tableRowNum);
            ui->label_state->setText("上传完成!");
        }
    }
}

void UpOrLoadFileDialog::chooseSavePath()
{
    qDebug() << "filePath = " << fileSavePath;
    fileSavePath = QFileDialog::getExistingDirectory(this,"选择目录","C:/Users/Administrator/Desktop",QFileDialog::ShowDirsOnly);
    if(fileSavePath.trimmed().isEmpty())
    {
        ;
    }

    fileSavePath += "/"+loadFileName;
    loadFileFlag = true;
    connectToServerHost();
}
void UpOrLoadFileDialog::dealRecvTcpSlot()
{
    if(loadFileFlag == false)
    {
        QByteArray recvMsg = tcpClient->readAll();
        if(recvMsg == "收到上传")
        {
            connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
            startTransfer();
            if(tableRowNum == -3) //不显示界面模式
            {
                return;
            }
            if(tableRowNum != -1)
            {
                ui->label_state->setText("正在上传中...");
            }
            ui->groupBox->hide();
            ui->progressBar->show();
            ui->pushButton->setEnabled(false);

        }
        return;
    }
    else
    {
        startRecvFile();
    }
}

void UpOrLoadFileDialog::sendFlagSlot()
{
    qDebug() << "connected:senfalg = " << sendFileFlag << " loadflag = " << loadFileFlag;
    if(sendFileFlag == true)
    {
        QByteArray sendMsg = "上传";
        tcpClient->write(sendMsg);
    }
    if(loadFileFlag == true)
    {
        if(fileSavePath == "/"+loadFileName)//当没有选择下载保存路径时
        {
            this->close();
            return;
        }
        QByteArray sendMsg = "xiazai" + loadFileName.toLocal8Bit();
        qDebug() << "sendMsg = " << sendMsg;
        tcpClient->write(sendMsg);
    }
}
//
void UpOrLoadFileDialog::startRecvFile()
{
    if(tableRowNum != -4)
    {
        ui->label_state->setText("正在下载...");
        ui->progressBar->show();
    }

    QDataStream in(tcpClient);
    if(bytesReceived <= sizeof(qint64)*2)
    {
        if((tcpClient->bytesAvailable() >= sizeof(qint64)*2) && fileNameSize == 0)
        {

            in >> totalBytes >> fileNameSize;
            qDebug() << "total = " << totalBytes;
            qDebug() << "fileNamesize = " << fileNameSize;
            bytesReceived += sizeof(qint64)*2;
            if(tableRowNum != -4)
            {
                ui->progressBar->setMaximum(totalBytes);
                ui->progressBar->setValue(bytesReceived);
            }

        }
        if(tcpClient->bytesAvailable() >= fileNameSize && fileNameSize != 0)
        {
            in >> fileName;
            bytesReceived += fileNameSize;
            localFile = new QFile(fileSavePath);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "file open error:"  << localFile->errorString();
                return;
            }
        }
        else
        {
            return;
        }
    }
    if(bytesReceived < totalBytes)
    {
        bytesReceived += tcpClient->bytesAvailable();
        if(tableRowNum != -4)
        {
            ui->progressBar->setMaximum(totalBytes);
            ui->progressBar->setValue(bytesReceived);
        }

        inBlock  = tcpClient->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    if(bytesReceived == totalBytes)
    {
        if(tableRowNum != -4)
        {
            ui->progressBar->hide();
            ui->label_state->setText("下载完成！");

            ui->pushButton->show();
            ui->pushButton->setText("打开文件");
            if(tableRowNum == -5)
            {
                ui->label_state->setText("更新完成！");
                ui->pushButton->setText("运行OA");
            }
            ui->groupBox->show();
            ui->pushButton_brower->hide();
            ui->label_path->setText("保存路径:");
            ui->lineEdit_path->setText(fileSavePath);
            ui->progressBar->setMaximum(totalBytes);
            ui->progressBar->setValue(bytesReceived);
        }

        totalBytes = 0;
        bytesReceived = 0;
        fileNameSize = 0;
        loadFileFlag = false;
        localFile->close();
    }
}

void UpOrLoadFileDialog::on_pushButton_brower_clicked()
{
    ui->label_state->setText("正在选择上传文件...");
    if(!openFile())
    {
        return;
    }
    ui->lineEdit_path->setText(fileName);
    ui->pushButton->show();
}

void UpOrLoadFileDialog::on_pushButton_clicked()
{
    QString btnText = ui->pushButton->text();
    if(btnText == "确定")
    {
        this->close();
    }
    if(btnText == "开始上传")
    {
        //开始连接服务器上传
        sendFileFlag = true;
        connectToServerHost();
    }
    if(btnText == "打开文件" || btnText == "运行OA")
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileSavePath));
        this->close();
    }

}

//
void UpOrLoadFileDialog::startUpLoadFile(QString filePath)
{
    fileName = filePath;
    //开始连接服务器上传
    sendFileFlag = true;
    connectToServerHost();
}
bool UpOrLoadFileDialog::getUpLoadSuccessFlag()
{

    return upLoadSuccessFlag;
}

void UpOrLoadFileDialog::startDownFile(const QString fileName)
{
    QDir dir("D:/");
    dir.mkdir("OA-Email-Data");
    dir.cd("OA-Email-Data");
    dir.mkdir("EmailFiles");
    dir.cd(qApp->applicationDirPath());
    dir.mkdir("serverFiles");
    fileSavePath = "D:/OA-Email-Data/EmailFiles/"+fileName;
    loadFileName = fileName;
    loadFileFlag = true;
    connectToServerHost();
}
