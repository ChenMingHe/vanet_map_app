#ifndef BANDWIDTHRESPONSMESSAGE_H
#define BANDWIDTHRESPONSMESSAGE_H

#include "Message/message.h"

class BandWidthResponsMessage : public AbstractMessage
{
public:
    explicit BandWidthResponsMessage(QStringList &list):
        AbstractMessage(list)
    {
        this->setMessageType(Message::BANDWIDTH);
        this->setUserName(list.at(0));
        this->round = list.at(3).toInt();
        this->value = list.at(4).toDouble();
    }

    int getRounds() {return round;}
    double getValue() {return value;}

private:
    int round;
    double value;
};

#endif // BANDWIDTHRESPONSMESSAGE_H
