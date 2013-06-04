#ifndef HANDLETEXTMESSAGE_H
#define HANDLETEXTMESSAGE_H

#include "MessageAnalyticSystem/handler.h"

class HandleTextMessage : public Handler
{
public:
    explicit HandleTextMessage(QObject *parent = 0) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLETEXTMESSAGE_H
