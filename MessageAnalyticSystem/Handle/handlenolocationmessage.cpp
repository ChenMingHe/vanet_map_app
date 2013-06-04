#include "handlenolocationmessage.h"

void HandleNolocationMessage::handleMessage(AbstractMessage *message)
{
    //对于NoLocation信息本不该处理，根据要求把它当做含有位置信息处理了
    if (message->getMessageType() != Message::NOLOCATION)
        return;

    //更新地图窗口
    emit operationRequest(Componet::VEHICLE_MAP,
                          Operations::UPDATE_LOCATION,
                          message);

    //更新列表窗口
    emit operationRequest(Componet::VEHICLE_LIST,
                          Operations::UPDATE_LIST,
                          message);
}
