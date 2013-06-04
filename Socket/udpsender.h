#ifndef UDPSENDER_H
#define UDPSENDER_H
#include <QUdpSocket>
#include "Widget/Menu/connecttionargument.h"
#include "LogSystem/logwriter.h"
class UdpSender
{
public:
    void sendData(const QString &s);
    static UdpSender &socket();

private:
    static UdpSender *instance;
    UdpSender();
    QUdpSocket sk;
};

#endif // UDPSENDER_H
