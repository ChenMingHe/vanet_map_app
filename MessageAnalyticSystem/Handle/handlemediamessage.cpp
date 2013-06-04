#include "handlemediamessage.h"

void HandleMediaMessage::handleMessage(AbstractMessage *message)
{
    if (message->getMessageType() != Message::PICTURE)
        return;

    //���¶�ý����Ϣ��
    emit operationRequest(Componet::MULTIMEDIA,
                          Operations::ADD_PICTURE,
                          message);
}
