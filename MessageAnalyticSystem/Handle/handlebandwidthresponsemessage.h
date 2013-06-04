#ifndef HANDLEBANDWIDTHRESPONSEMESSAGE_H
#define HANDLEBANDWIDTHRESPONSEMESSAGE_H

#include "MessageAnalyticSystem/handler.h"

class HandleBandWidthResponseMessage : public Handler
{
public:
    explicit HandleBandWidthResponseMessage(QObject *parent = 0) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLEBANDWIDTHRESPONSEMESSAGE_H
