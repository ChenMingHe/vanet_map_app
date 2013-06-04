#ifndef EMERGENCYVEHICLEMESSAGE_H
#define EMERGENCYVEHICLEMESSAGE_H

#include "locationmessage.h"

class EmergencyVehicleMessage : public LocationMessage
{
public:
    explicit EmergencyVehicleMessage(QStringList &list):
        LocationMessage(list)
    {
        this->setDirect(list.at(9));
        this->setIsSelf(false);
        this->setLatitude(list.at(4));
        this->setLicense("Emergency Car");
        this->setLontitude(list.at(6));
        this->setMessageType(Message::EMERGENCY_VEHICLE);
        this->setSpeed(list.at(8));
        this->setUserName(list.at(0));
    }

};

#endif // EMERGENCYVEHICLEMESSAGE_H
