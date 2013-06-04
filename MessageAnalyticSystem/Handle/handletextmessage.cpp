#include "handletextmessage.h"

void HandleTextMessage::handleMessage(AbstractMessage *message)
{
    if (message->getMessageType() != Message::TEXT)
        return;

    //�ı���Ϣ
    emit operationRequest(Componet::CONVERSATION,
                          Operations::APPEND_TEXT,
                          message);
}
