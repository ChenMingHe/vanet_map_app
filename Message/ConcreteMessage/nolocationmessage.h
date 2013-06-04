#ifndef NOLOCATIONMESSAGE_H
#define NOLOCATIONMESSAGE_H

#include <QMap>
#include <time.h>
#include <stdlib.h>
#include "Message/ConcreteMessage/distancelocationmessage.h"
#include "Message/ConcreteMessage/selflocationmessage.h"

class NoLocationMessage
{
public:
    static NoLocationMessage &getInstance();
     AbstractMessage *creatMessage(QStringList &list);

private:
    NoLocationMessage();
    static NoLocationMessage *instance;
    QMap<QString, AbstractMessage *> messageDB;
    double getRandNum();
};

#endif // NOLOCATIONMESSAGE_H
