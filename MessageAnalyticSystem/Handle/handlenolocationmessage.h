#ifndef HANDLENOLOCATIONMESSAGE_H
#define HANDLENOLOCATIONMESSAGE_H

#include "MessageAnalyticSystem/handler.h"

class HandleNolocationMessage : public Handler
{
public:
    explicit HandleNolocationMessage(QObject *parent = 0) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLENOLOCATIONMESSAGE_H
