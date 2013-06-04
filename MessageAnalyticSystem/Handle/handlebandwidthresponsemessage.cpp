#include "handlebandwidthresponsemessage.h"

void HandleBandWidthResponseMessage::handleMessage(AbstractMessage *message) {
    if (message->getMessageType() != Message::BANDWIDTH)
        return;

    emit operationRequest(Componet::BANDWIDTH_TEST,
                          Operations::UPDATE_BANDWIDTH,
                          message);
}


