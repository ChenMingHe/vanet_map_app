#include "handlerttresponsemessage.h"

void HandleRttResponseMessage::handleMessage(AbstractMessage *message)
{
    if (message->getMessageType() != Message::RTT)
        return;

    //����RTT���
    emit operationRequest(Componet::RTT_TEST,
                          Operations::UPDATE_RTT,
                          message);
}
