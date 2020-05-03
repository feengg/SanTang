#ifndef TCPDEALTHREAD_H
#define TCPDEALTHREAD_H
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QApplication>
#include <QDataStream>
#include <QDir>
#include <QObject>

class TcpDealThread : public QObject
{
    Q_OBJECT
public:
    TcpDealThread(QTcpSocket * tcpskt);
    void startTransfer();

private slots:
    void disPlayError(QAbstractSocket::SocketError);
    void dealRecvSlot();
    void updateSendSlot(qint64);

private:
    QTcpSocket * tcpServerConnection = nullptr;
    qint64 totalBytes;
    qint64 bytesReceived;
    qint64 fileNameSize;
    QString fileName;
    QFile * localFile;
    QByteArray inBlock;
    bool sendTcpFlag = false;
    bool recvTcpFlag = false;
    QByteArray outBlock;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 payLoadSize;
};

#endif // TCPDEALTHREAD_H
