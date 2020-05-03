#include "tcpdealthread.h"

TcpDealThread::TcpDealThread(QTcpSocket * tcpskt)
{
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    payLoadSize = 64*1024;
    bytesWritten = 0;
    bytesToWrite = 0;
    tcpServerConnection = tcpskt;
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(dealRecvSlot()),Qt::DirectConnection);
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(disPlayError(QAbstractSocket::SocketError)),Qt::DirectConnection);
}


void TcpDealThread::disPlayError(QAbstractSocket::SocketError)
{
    qDebug() << "tcpSocket Error : " << tcpServerConnection->errorString();
    tcpServerConnection->close();
}
//
void TcpDealThread::dealRecvSlot()
{
    QDataStream in(tcpServerConnection);
    if(recvTcpFlag == false)
    {
        QByteArray recvMsg = tcpServerConnection->readAll();
        qDebug() << "recvMsg = " << recvMsg;
        if(recvMsg == "上传")
        {
            recvTcpFlag = true;
            recvMsg = "收到上传";
            tcpServerConnection->write(recvMsg);
        }
        if(recvMsg.mid(0,6) == "xiazai")
        {
            sendTcpFlag = true;
            fileName = QString::fromLocal8Bit(recvMsg.mid(6,100));
            qDebug() << "recfileName = " << fileName;
        }
    }
    //接收
    if(recvTcpFlag == true)
    {
        if(bytesReceived <= sizeof(qint64)*2)
        {
            if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2) && fileNameSize == 0)
            {
                in >> totalBytes >> fileNameSize;
                bytesReceived += sizeof(qint64)*2;
            }
            if(tcpServerConnection->bytesAvailable() >= fileNameSize && fileNameSize != 0)
            {
                in >> fileName;
                bytesReceived += fileNameSize;
                QDir dir(qApp->applicationDirPath());
                dir.mkdir("serverFiles");
                localFile = new QFile(qApp->applicationDirPath()+"/serverFiles/"+fileName);
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
            bytesReceived += tcpServerConnection->bytesAvailable();
            inBlock  = tcpServerConnection->readAll();
            localFile->write(inBlock);
            inBlock.resize(0);
        }
        if(bytesReceived == totalBytes)
        {
            fileNameSize = 0;
            totalBytes = 0;
            bytesReceived = 0;
            payLoadSize = 64*1024;
            bytesWritten = 0;
            bytesToWrite = 0;
            localFile->close();
            recvTcpFlag = false;
            tcpServerConnection->close();
            tcpServerConnection = nullptr;
        }
    }
    //发送
    if(sendTcpFlag == true)
    {
        qDebug() << "start tran";
        startTransfer();
    }
}

void TcpDealThread::startTransfer()
{

    connect(tcpServerConnection,SIGNAL(bytesWritten(qint64)),this,SLOT(updateSendSlot(qint64)),Qt::DirectConnection);
    localFile = new QFile(qApp->applicationDirPath()+"/serverFiles/"+fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    totalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    QString currentFileName = fileName;
    sendOut  <<qint64(0) << qint64(0) << currentFileName;//文件总大小，文件名大小，文件名
    totalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut << totalBytes << qint64(outBlock.size()-sizeof(qint64)*2);
    bytesToWrite = totalBytes - tcpServerConnection->write(outBlock);
    outBlock.resize(0);
}

void TcpDealThread::updateSendSlot(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0)
    {
        outBlock = localFile->read(qMin(bytesToWrite,payLoadSize));
        bytesToWrite -= (int)tcpServerConnection->write(outBlock);
        outBlock.resize(0);
    }
    else
    {
        localFile->close();
    }
    if(bytesWritten == totalBytes)
    {
        fileNameSize = 0;
        totalBytes = 0;
        bytesReceived = 0;
        payLoadSize = 64*1024;
        bytesWritten = 0;
        bytesToWrite = 0;
        localFile->close();
        sendTcpFlag = false;
        tcpServerConnection->close();
        tcpServerConnection = nullptr;

    }
}
