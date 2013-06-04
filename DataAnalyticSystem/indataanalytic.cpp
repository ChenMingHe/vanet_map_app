#include "indataanalytic.h"

InDataAnalytic::InDataAnalytic(QObject *parent) :
    QObject(parent)
{
}

void InDataAnalytic::doDataAnalytic(QByteArray &datagram)
{
    QStringList list(QString(datagram.data()).split(" ", QString::SkipEmptyParts));
    AbstractMessage *message = NULL;
    //信息由本地节点发出
    if (list.at(0) == "V") {
        //位置信息必须含有8个值
        if (list.size() != 8 && list.at(3) != "N" && list.at(5) != "E")
            message = NULL;
        message = new SelfLocationMessage(list);
    } else if (list.at(0) == "N") {
        LogDebug(0) << "local no gps";
        message = NoLocationMessage::getInstance().creatMessage(list);
    }

    if (message != NULL) {
        emit newMessage(message);
        return;
    }

    //信息由远程节点发出
    if (list.at(2).size() > 1 || list.at(0).at(0) != '[')
        message = NULL;
    char type = (*list.at(2).data()).cell();
    switch (type)
    {
    case 'V':
        if (list.size() != 10 && list.at(5) != "N" && list.at(7) != "E")
            message = NULL;
        message = new DistanceLocationMessage(list);
        break;
    case 'R':
        if (list.size() != 10 && list.at(5) != "N" && list.at(7) != "E")
            message = NULL;
        message = new DangerMessage(list);
        break;
    case 'E':
        if (list.size() != 10 && list.at(5) != "N" && list.at(7) != "E")
            message = NULL;
        message = new EmergencyVehicleMessage(list);
        break;
    case 'P':
        //TODO: creat Picture message
        if (list.size() != 4)
            message = NULL;
        message = new MultiMediaMessage(list);
        break;
    case 'M':
        message = new PictureRequestMessage(list);
        break;
    case 'A':
        if (list.size() < 3)
            message = NULL;
        message = new TextMessage(list);
        break;
    case 'N':
        message = NoLocationMessage::getInstance().creatMessage(list);
        break;
    case 'S':
        if (list.size() != 5)
            message = NULL;
        message = new RttResponseMessage(list);
        break;
    case 'B':
        if (list.size() != 5)
            message = NULL;
        message = new BandWidthResponsMessage(list);
        break;
    case 'H':
        if (list.size() != 4)
            message = NULL;
        message = new HopMessage(list);
        break;
    default:
        message = NULL;
        break;
    }

    if (message != NULL)
        emit newMessage(message);
}
