#include "connecttionargument.h"


ConnecttionArgument *ConnecttionArgument::instance = NULL;
ConnecttionArgument &ConnecttionArgument::Setting()
{
    if (instance == NULL) {
        instance = new ConnecttionArgument;
    }
    return *instance;
}

void ConnecttionArgument::saveSetting()
{
    QFile file("ConnectSetting.xml");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;

    QDomDocument doc;
    QDomText text;
    QDomElement element;

    {
        QDomProcessingInstruction instruction;
        instruction = doc.createProcessingInstruction("xml", "version = \"1.0\" encoding=\"GB2312\"");
        doc.appendChild(instruction);
    }

    QDomElement root = doc.createElement("VANET");
    doc.appendChild(root);
    {
        QDomElement socket = doc.createElement("Socket");
        //setting host address
        element = doc.createElement("HostAddress");
        text = doc.createTextNode(host.toString());
        element.appendChild(text);
        socket.appendChild(element);

        element = doc.createElement("UDPPort");
        text = doc.createTextNode(QString::number(udpPort));
        element.appendChild(text);
        socket.appendChild(element);

        element = doc.createElement("TCPPort");
        text = doc.createTextNode(QString::number(tcpPort));
        element.appendChild(text);
        socket.appendChild(element);
        root.appendChild(socket);

        element = doc.createElement("LocalUserName");
        text = doc.createTextNode(userName);
        element.appendChild(text);
        socket.appendChild(element);
        root.appendChild(socket);
    }

    QTextStream out( &file );
    doc.save( out, 4 );
}

ConnecttionArgument::ConnecttionArgument() :
    host("192.168.1.121"), udpPort(9910), tcpPort(1010)
{
    if (QFile::exists("ConnectSetting.xml")) {
        QDomDocument doc("ConnectSetting");
        QFile file("ConnectSetting.xml");

        if (!file.open(QIODevice::ReadOnly))
            return;

        if (!doc.setContent(&file)) {
            file.close();
            return;
        }

        QDomElement root = doc.firstChildElement("VANET");
        if (root.isNull())
            return;

        QDomElement SocketElement = root.firstChildElement("Socket");
        if (!SocketElement.isNull()) {
            QDomElement hostD = SocketElement.firstChildElement("HostAddress");
            QDomElement udpPortD = SocketElement.firstChildElement("UDPPort");
            QDomElement tcpPortD = SocketElement.firstChildElement("TCPPort");
            QDomElement nameD = SocketElement.firstChildElement("LocalUserName");
            if (!hostD.isNull()) {
                host = QHostAddress(QString(hostD.text()));
            }
            if (!udpPortD.isNull()) {
                udpPort = udpPortD.text().toInt();
            }
            if (!tcpPortD.isNull()) {
                tcpPort = tcpPortD.text().toInt();
            }
            if (!nameD.isNull())
                userName = nameD.text();
        }
    }
}
