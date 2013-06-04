#ifndef RTTRESPONSEMESSAGE_H
#define RTTRESPONSEMESSAGE_H

#include "Message/message.h"

class RttResponseMessage : public AbstractMessage
{
public:
    explicit RttResponseMessage(QStringList &list) :
        AbstractMessage(list)
    {
        this->setMessageType(Message::RTT);
        this->setUserName(list.at(0));
        this->round = list.at(3).toInt();
        this->value = list.at(4).toDouble();
    }
    int getRounds() { return round; }
    double getValue() { return value; }

private:
    int round;
    double value;
};

#endif // RTTRESPONSEMESSAGE_H
