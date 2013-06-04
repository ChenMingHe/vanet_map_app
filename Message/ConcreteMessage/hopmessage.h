#ifndef HOPMESSAGE_H
#define HOPMESSAGE_H

#include "Message/message.h"

class HopMessage : public AbstractMessage
{
public:
    enum HopType {
        UnKnow = 0,
        SingleHop,
        MultiHop
    };

    HopMessage(QStringList &list) : AbstractMessage(list), hop(UnKnow) {
        this->setMessageType(Message::HOP);
        this->setUserName(list.at(0));
        if (list.at(3) == "1"){
            hop = SingleHop;
        } else {
            hop = MultiHop;
        }
    }

    HopType getHopMark() {return this->hop;}

private:
    HopType hop;
};

#endif // HOPMESSAGE_H
