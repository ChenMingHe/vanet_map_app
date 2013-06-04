#include "handlemediamessage.h"

void HandleMediaMessage::handleMessage(AbstractMessage *message)
{
    if (message->getMessageType() != Message::PICTURE)
        return;

    //更新多媒体信息表
    emit operationRequest(Componet::MULTIMEDIA,
                          Operations::ADD_PICTURE,
                          message);
}
