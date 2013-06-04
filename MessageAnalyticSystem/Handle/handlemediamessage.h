#ifndef HANDLEMEDIAMESSAGE_H
#define HANDLEMEDIAMESSAGE_H

#include "MessageAnalyticSystem/handler.h"

class HandleMediaMessage : public Handler
{
public:
    explicit HandleMediaMessage(QObject *parent) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLEMEDIAMESSAGE_H
