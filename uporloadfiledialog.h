#ifndef UPORLOADFILEDIALOG_H
#define UPORLOADFILEDIALOG_H

#include <QWidget>
#include "widget.h"
#include <QTcpSocket>


namespace Ui {
class UpOrLoadFileDialog;
}

class UpOrLoadFileDialog : public QWidget
{
    Q_OBJECT

public:
    explicit UpOrLoadFileDialog(QString showType,int row,QString downFileName = "",QWidget *parent = 0);
    UpOrLoadFileDialog(int showType):tableRowNum(showType){}
    ~UpOrLoadFileDialog();
    void startRecvFile();
    void chooseSavePath();
    void startUpLoadFile(QString filePath);

    bool getUpLoadSuccessFlag();

    void startDownFile(const QString fileName);
signals:
    void sendFileNameAndRowNumToFatherSig(QString,int);


private slots:
    void on_toolButton_clicked();
    bool openFile();
    void connectToServerHost();
    void startTransfer();
    void updateClientProgress(qint64);
    void dealRecvTcpSlot();
    void sendFlagSlot();

    void on_pushButton_brower_clicked();

    void on_pushButton_clicked();

private:
    Ui::UpOrLoadFileDialog *ui;
    int tableRowNum = 0;
    QTcpSocket * tcpClient = nullptr;
    QFile * localFile;
    qint64 totalBytes = 0;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 payLoadSize;
    QString fileName;
    QByteArray outBlock;
    bool sendFileFlag = false;
    bool loadFileFlag = false;
    qint64 bytesReceived = 0;
    QByteArray inBlock;
    qint64 fileNameSize = 0;
    QString fileSavePath;
    QString loadFileName;

    bool upLoadSuccessFlag = false;
};

#endif // UPORLOADFILEDIALOG_H
