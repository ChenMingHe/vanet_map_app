#ifndef DANGERMESSAGE_H
#define DANGERMESSAGE_H

#include "distancelocationmessage.h"

class DangerMessage : public DistanceLocationMessage
{
public:
    explicit DangerMessage(QStringList &list):
        DistanceLocationMessage(list)
    {
        this->setLicense("Danger Car");
        this->setMessageType(Message::DANGER);
    }
};

#endif // DANGERMESSAGE_H
