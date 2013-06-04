#include "handletextmessage.h"

void HandleTextMessage::handleMessage(AbstractMessage *message)
{
    if (message->getMessageType() != Message::TEXT)
        return;

    //文本信息
    emit operationRequest(Componet::CONVERSATION,
                          Operations::APPEND_TEXT,
                          message);
}
