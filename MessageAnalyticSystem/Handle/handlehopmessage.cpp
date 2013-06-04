#include "handlehopmessage.h"


void HandleHopMessage::handleMessage(AbstractMessage *message)
{
    Message::Type type = message->getMessageType();
    if (type != Message::HOP)
        return;

    //����VechicleListWidget��Hop��Ϣ
    emit operationRequest(Componet::VEHICLE_LIST,
                          Operations::UPDATE_HOP,
                          message);

    //����TestListWidget��Hop��Ϣ
    emit operationRequest(Componet::TEST_LIST,
                          Operations::UPDATE_HOP,
                          message);
}
