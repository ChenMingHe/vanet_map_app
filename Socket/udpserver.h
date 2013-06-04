#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QUdpSocket>
#include <QObject>
#include "LogSystem/logwriter.h"

class UdpServer : public QObject
{
    Q_OBJECT
public:
    UdpServer(int _port);

private slots:
    void readDataGram();

signals:
    void newDataGram(QByteArray &);

private:
    QUdpSocket socket;
    qint16 port;
};

#endif // UDPSERVER_H
