#ifndef DISTANCELOCATIONMESSAGE_H
#define DISTANCELOCATIONMESSAGE_H

#include "locationmessage.h"

class DistanceLocationMessage : public LocationMessage
{
public:
    DistanceLocationMessage(QStringList &list) :
        LocationMessage(list)
    {
        this->setCount(list.at(2));
        this->setDirect(list.at(9));
        this->setIsSelf(false);
        this->setLatitude(list.at(4));
        this->setLicense("Distance Car");
        this->setLontitude(list.at(6));
        this->setMessageType(Message::DISTANCE_LOCATION);
        this->setSpeed(list.at(8));
        this->setUserName(list.at(0));
    }


    qint64 getCount() { return count; }

private:
    qint64 count;

private:
    void setCount(const QString &count) { this->count = count.toLongLong(); }
};

#endif // DISTANCELOCATIONMESSAGE_H
