#include "settingargument.h"

SettingArgument *SettingArgument::instance = NULL;
SettingArgument &SettingArgument::Setting()
{
    if (instance == NULL) {
        instance = new SettingArgument();
    }
    return *instance;
}

void SettingArgument::saveSetting()
{
    QFile file("setting.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
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
        //setting UDP port
        element = doc.createElement("UDPport");
        text = doc.createTextNode(QString::number(udpPort));
        element.appendChild(text);
        socket.appendChild(element);

        //setting TCP Port
        element = doc.createElement("TCPPort");
        text = doc.createTextNode(QString::number(tcpPort));
        element.appendChild(text);
        socket.appendChild(element);
        root.appendChild(socket);
    }

    //setting Bandwidth test argument
    {
        QDomElement bwTest = doc.createElement("BandwidthTest");
        element = doc.createElement("BWTestTimes");
        text = doc.createTextNode(QString::number(bwTestTimes));
        element.appendChild(text);
        bwTest.appendChild(element);

        element = doc.createElement("BWTimeInterval");
        text = doc.createTextNode(QString::number(bwTimeInterval));
        element.appendChild(text);
        bwTest.appendChild(element);

        element = doc.createElement("BWLowRange");
        text = doc.createTextNode(QString::number(bwLowRange));
        element.appendChild(text);
        bwTest.appendChild(element);

        element = doc.createElement("BWUpRange");
        text = doc.createTextNode(QString::number(bwUpRange));
        element.appendChild(text);
        bwTest.appendChild(element);

        element = doc.createElement("BWAverageInterval");
        text = doc.createTextNode(QString::number(bwAverageInterval));
        element.appendChild(text);
        bwTest.appendChild(element);

        root.appendChild(bwTest);
    }

    {
        QDomElement rttTest = doc.createElement("RTTTest");
        element = doc.createElement("RTTTestTimes");
        text = doc.createTextNode(QString::number(rttTestTimes));
        element.appendChild(text);
        rttTest.appendChild(element);

        element = doc.createElement("RTTTimeInterval");
        text = doc.createTextNode(QString::number(rttTimeInterval));
        element.appendChild(text);
        rttTest.appendChild(element);

        element = doc.createElement("RTTLowRange");
        text = doc.createTextNode(QString::number(rttLowRange));
        element.appendChild(text);
        rttTest.appendChild(element);

        element = doc.createElement("RTTUpRange");
        text = doc.createTextNode(QString::number(rttUpRange));
        element.appendChild(text);
        rttTest.appendChild(element);

        element = doc.createElement("RTTAverageInterval");
        text = doc.createTextNode(QString::number(rttAverageInterval));
        element.appendChild(text);
        rttTest.appendChild(element);

        root.appendChild(rttTest);
    }

    {
        QDomElement other = doc.createElement("Other");
        element = doc.createElement("WarringTimeInterval");
        text = doc.createTextNode(QString::number(warringTimeInterval));
        element.appendChild(text);
        other.appendChild(element);

        root.appendChild(other);
    }

    QTextStream out( &file );
    doc.save( out, 4 );
}

SettingArgument::SettingArgument() :
    udpPort(9009), tcpPort(9911),
    bwTestTimes(10), bwLowRange(0), bwUpRange(256),
    bwTimeInterval(6), bwAverageInterval(4),
    rttTestTimes(20), rttTimeInterval(1200), rttLowRange(0),
    rttUpRange(1500), rttAverageInterval(5),
    warringTimeInterval(50)
{
    if (QFile::exists("setting.xml")) {
        QDomDocument doc("setting");
        QFile file("setting.xml");

        if (!file.open(QIODevice::ReadOnly))
            return;

        if (!doc.setContent(&file)) {
            file.close();
            return;
        }

        QDomElement root = doc.firstChildElement("VANET");
        if (!root.isNull()) {
            //读取套接字配置信息
            {
                QDomElement socketElement = root.firstChildElement("Socket");
                if (!socketElement.isNull()) {
                    QDomElement udpPortD = socketElement.firstChildElement("UDPport");
                    QDomElement tcpPortD = socketElement.firstChildElement("TCPPort");
                    if (!udpPortD.isNull()) {
                        udpPort = udpPortD.text().toInt();
                    }
                    if (!tcpPortD.isNull()) {
                        tcpPort = tcpPortD.text().toInt();
                    }
                }
            }

            //读取BW配置信息
            {
                QDomElement bwTestD = root.firstChildElement("BandwidthTest");
                if (!bwTestD.isNull()) {
                    QDomElement bwTestTimeD = bwTestD.firstChildElement("BWTestTimes");
                    QDomElement bwTimeIntervalD = bwTestD.firstChildElement("BWTimeInterval");
                    QDomElement bwLowRangeD = bwTestD.firstChildElement("BWLowRange");
                    QDomElement bwUpRangeD = bwTestD.firstChildElement("BWUpRange");
                    QDomElement bwAverageIntervalD = bwTestD.firstChildElement("BWAverageInterval");
                    if (!bwTestTimeD.isNull()) {
                        bwTestTimes = bwTestTimeD.text().toInt();
                    }
                    if (!bwTimeIntervalD.isNull()) {
                        bwTimeInterval = bwTimeIntervalD.text().toInt();
                    }
                    if (!bwLowRangeD.isNull()) {
                        bwLowRange = bwLowRangeD.text().toInt();
                    }
                    if (!bwUpRangeD.isNull()) {
                        bwUpRange = bwUpRangeD.text().toInt();
                    }
                    if (!bwAverageIntervalD.isNull()) {
                        bwAverageInterval = bwAverageIntervalD.text().toInt();
                    }
                }
            }

            //读取rtt配置信息
            {
                QDomElement rttTestD = root.firstChildElement("RTTTest");
                if (!rttTestD.isNull()) {
                    QDomElement rttTestTimeD = rttTestD.firstChildElement("RTTTestTimes");
                    QDomElement rttTimeIntervalD = rttTestD.firstChildElement("RTTTimeInterval");
                    QDomElement rttLowRangeD = rttTestD.firstChildElement("RTTLowRange");
                    QDomElement rttUpRangeD = rttTestD.firstChildElement("RTTUpRange");
                    QDomElement rttAverageIntervalD = rttTestD.firstChildElement("RTTAverageInterval");
                    if (!rttTestTimeD.isNull()) {
                        rttTestTimes = rttTestTimeD.text().toInt();
                    }
                    if (!rttTimeIntervalD.isNull()) {
                        rttTimeInterval = rttTimeIntervalD.text().toInt();
                    }
                    if (!rttLowRangeD.isNull()) {
                        rttLowRange = rttLowRangeD.text().toInt();
                    }
                    if (!rttUpRangeD.isNull()) {
                        rttUpRange = rttUpRangeD.text().toInt();
                    }
                    if (!rttAverageIntervalD.isNull()) {
                        rttAverageInterval = rttAverageIntervalD.text().toInt();
                    }
                }
            }

            //配置警告范围
            {
                QDomElement otherD = root.firstChildElement("Other");
                if (!otherD.isNull()) {
                    QDomElement warringRadiusD = otherD.firstChildElement("WarringTimeInterval");
                    if (!warringRadiusD.isNull()) {
                        warringTimeInterval = warringRadiusD.text().toInt();
                    }
                }
            }
        }
    }
}

