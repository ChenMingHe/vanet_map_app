#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QFile>
#include <QByteArray>
#include <QStringList>
#include "Widget/Menu/Settings.h"
#include "LogSystem/logwriter.h"
#include "Widget/ProgressBar/staticprogressbar.h"
#include "Widget/Label/staticlabel.h"

/**
  ׼��ʹ��FileTransmitUnit�滻�ڲ����ļ�����
  */

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer();

private slots:
    void newConnection();
    void readData();
    void stateChange(QAbstractSocket::SocketState state);

private:
    QTcpServer server;
    QFile *file;
    QString fileName;
    qint32 fileSize;
    QString fileType;
    QString description;
    QString userName;
};

#endif // TCPSERVER_H
