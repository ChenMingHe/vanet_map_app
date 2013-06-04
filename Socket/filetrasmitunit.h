#ifndef FILETRANSMITUNIT_H
#define FILETRANSMITUNIT_H

#include <QFile>
#include <QTcpSocket>
#include <QStringList>
#include "LogSystem/logwriter.h"
#include "Widget/Label/staticlabel.h"
#include "Widget/ProgressBar/staticprogressbar.h"

class FileTransmitUnit : public QObject
{
    Q_OBJECT
public:
    explicit FileTransmitUnit(QObject *parent);
    virtual ~FileTransmitUnit() {}
    void run(QTcpSocket *sk);

signals:
    void fileRecvFinish();

private slots:
    void recvFile();

private:
    void initFileBaseProperty();
    qint64 recvFileData();

private:
    QString fileName;
    QString userName;
    qint64 fileSize;
    qint64 fileRestSize;
    QTcpSocket *sk;
    QFile *file;
    QString fileType;
    QString desc;
};

#endif // FILETRASMITUNIT_H
