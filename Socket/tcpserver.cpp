#include "tcpserver.h"

TcpServer::TcpServer() :
    file(NULL), fileSize(0),
    fileType(""), description("")
{
    LogWriter::log().info("Start TCP Server : " +
                          QString::number(SettingArgument::Setting().getTcpPort()) + "\n");

    server.listen(QHostAddress::Any, SettingArgument::Setting().getTcpPort());
    connect(&server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void TcpServer::newConnection()
{
    while (server.hasPendingConnections()) {
        LogDebug(0) << "new connection\n";
        LogWriter::log().info(QString("new file transmion request\n"));

        QTcpSocket *s = server.nextPendingConnection();
        connect(s, SIGNAL(readyRead()), this, SLOT(readData()));
        connect(s, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this, SLOT(stateChange(QAbstractSocket::SocketState)));
    }
}

void TcpServer::readData()
{
    QTcpSocket *s = (QTcpSocket *)QObject::sender();
    if (file == NULL) {
        QByteArray array = s->readLine(1000);
        LogDebug(0) << array;
        QString st(array);
        QStringList list = st.split(" ", QString::SkipEmptyParts);
        fileName = "My" + list.at(2);
        file = new QFile(fileName);
        file->open(QIODevice::WriteOnly);

        fileSize = list.at(3).toInt();
        fileType = list.at(1);
        description = st;
        userName = list.at(0);

        QProgressBar *bar = StaticProgressBar::progressBar();
        bar->show();
        bar->setMaximum(fileSize);
        bar->setValue(0);
        StaticLabel::label()->setText("new file receive : My" + list.at(2));
        return;
    }

    while (s->bytesAvailable() && fileSize > 0) {
        int readSize = s->bytesAvailable();
        file->write(s->read(readSize));
        fileSize -= readSize;

        StaticProgressBar *bar = StaticProgressBar::progressBar();
        bar->setValue(bar->maximum()-fileSize);

        if (fileSize <= 0) {
            file->close();
            delete file;
            file = NULL;
            s->close();

            StaticLabel::label()->setText("New File : My" + fileName);

            QString st = userName + " [00] " + fileType
                    + " " + fileName + " " + description;
            QUdpSocket udp;
            udp.writeDatagram(st.toAscii(), QHostAddress::LocalHost,
                              SettingArgument::Setting().getUdpPort());
        }
    }
}

void TcpServer::stateChange(QAbstractSocket::SocketState state)
{
    // TODO:需要关闭套接字
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        break;
    default:
        break;
    }
}
