#ifndef HANDLEHOPMESSAGE_H
#define HANDLEHOPMESSAGE_H

#include "MessageAnalyticSystem/handler.h"

class HandleHopMessage : public Handler
{
public:
    explicit HandleHopMessage(QObject *parent = 0) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLEHOPMESSAGE_H
