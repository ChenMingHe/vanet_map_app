#ifndef HANDLELOCATIONMESSAGE_H
#define HANDLELOCATIONMESSAGE_H

#include "MessageAnalyticSystem/handler.h"

class HandleLocationMessage : public Handler
{
public:
    explicit HandleLocationMessage(QObject *parent = 0) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLELOCATIONMESSAGE_H
