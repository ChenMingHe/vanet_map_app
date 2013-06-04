#include "udpsender.h"


void UdpSender::sendData(const QString &s)
{
    ConnecttionArgument &argument = ConnecttionArgument::Setting();
    sk.writeDatagram(s.toAscii(), argument.getHost(), argument.getUDPPort());
    LogDebug(0) << s;
    LogWriter::log().info("Send : " + s);
}


UdpSender *UdpSender::instance = NULL;
UdpSender &UdpSender::socket()
{
    if (instance == NULL) {
        instance = new UdpSender;
    }
    return *instance;
}

UdpSender::UdpSender()
{
}

