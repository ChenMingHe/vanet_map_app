#ifndef SELFLOCATIONMESSAGE_H
#define SELFLOCATIONMESSAGE_H

#include "locationmessage.h"

class SelfLocationMessage : public LocationMessage
{
public:
    explicit SelfLocationMessage(QStringList &list):
        LocationMessage(list)
    {
        this->setDirect(list.at(7));
        this->setIsSelf();
        this->setLatitude(list.at(2));
        this->setLicense("Super User");
        this->setLontitude(list.at(4));
        this->setMessageType(Message::SELF_LOCATION);
        this->setSpeed(list.at(6));
        this->setUserName("[Me]");
    }
};

#endif // SELFLOCATIONMESSAGE_H
