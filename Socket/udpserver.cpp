#include "udpserver.h"

UdpServer::UdpServer(int _port) :
    port(_port)
{
    socket.bind(QHostAddress::Any, port);
    connect(&socket, SIGNAL(readyRead()), this, SLOT(readDataGram()));
}


void UdpServer::readDataGram()
{
    while (socket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket.pendingDatagramSize());
        socket.readDatagram(datagram.data(), datagram.size());
        LogWriter::log().info(QByteArray("Recv : ") + datagram);
        emit newDataGram(datagram);
    }
}

