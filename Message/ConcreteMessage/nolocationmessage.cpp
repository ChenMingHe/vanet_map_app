#include "nolocationmessage.h"


NoLocationMessage *NoLocationMessage::instance = NULL;
NoLocationMessage &NoLocationMessage::getInstance()
{
    if (instance == NULL)
        instance = new NoLocationMessage();
    return *instance;
}

AbstractMessage *NoLocationMessage::creatMessage(QStringList &list)
{
    //在数据库中找点
    QMap<QString, AbstractMessage *>::iterator itr;
    if (list.at(0) != "N") {
        itr = messageDB.find(list.at(0));
    } else {
        itr = messageDB.find("[Me]");
    }
    if (itr != messageDB.end()) {
        LocationMessage *message = (LocationMessage *) itr.value();
        message->changeMessageType(Message::NOLOCATION);
        return message;
    }

    //为点找一个随机位置信息
    QString s;
    if (list.at(0) == "N") {
        s = "V"
                + QString(" 0000 ")
                + QString::number(getRandNum())
                + " N "
                + QString::number(getRandNum())
                + " E "
                + " 998"
                + " 180";
    } else {
        s = list.at(0)
                + " 99999"
                + " V"
                + " 0000 "
                + QString::number(getRandNum())
                + " N "
                + QString::number(getRandNum())
                + " E "
                + " 999"
                + " 90";
    }
    QStringList randList(s.split(" ", QString::SkipEmptyParts));
    AbstractMessage *newMessage;
    if (randList.at(0) == "V") {
        newMessage = new SelfLocationMessage(randList);
        messageDB.insert("[Me]", newMessage);
    } else {
        newMessage = new DistanceLocationMessage(randList);
        messageDB.insert(list.at(0), newMessage);
    }
    ((LocationMessage *)newMessage)->changeMessageType(Message::NOLOCATION);
    return newMessage;
}

NoLocationMessage::NoLocationMessage()
{
    //启动随机数
    srand(time(0));
}

double NoLocationMessage::getRandNum()
{
    double n = ((double)(rand() % 10)) / 10000;
    return n;
}
