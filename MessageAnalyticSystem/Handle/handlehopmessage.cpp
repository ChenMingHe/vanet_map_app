#include "handlehopmessage.h"


void HandleHopMessage::handleMessage(AbstractMessage *message)
{
    Message::Type type = message->getMessageType();
    if (type != Message::HOP)
        return;

    //更新VechicleListWidget的Hop信息
    emit operationRequest(Componet::VEHICLE_LIST,
                          Operations::UPDATE_HOP,
                          message);

    //更新TestListWidget的Hop信息
    emit operationRequest(Componet::TEST_LIST,
                          Operations::UPDATE_HOP,
                          message);
}
