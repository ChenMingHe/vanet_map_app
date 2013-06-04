#ifndef HANDLERTTRESPONSEMESSAGE_H
#define HANDLERTTRESPONSEMESSAGE_H

#include "MessageAnalyticSystem/handler.h"

class HandleRttResponseMessage : public Handler
{
public:
    explicit HandleRttResponseMessage(QObject *parent = 0) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLERTTRESPONSEMESSAGE_H
