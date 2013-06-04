#include "handlelocationmessage.h"

void HandleLocationMessage::handleMessage(AbstractMessage *message)
{
    Message::Type type = message->getMessageType();
    //不处理不含有位置信息的报文
    if (type != Message::DANGER //安全警告车辆
            && type != Message::DISTANCE_LOCATION //普通车辆
            && type != Message::SELF_LOCATION //本地位置信息
            && type != Message::EMERGENCY_VEHICLE) /*救援车辆*/ {
        return;
    }

    //更新地图窗口
    emit operationRequest(Componet::VEHICLE_MAP,
                          Operations::UPDATE_LOCATION,
                          message);

    //更新列表窗口
    emit operationRequest(Componet::VEHICLE_LIST,
                          Operations::UPDATE_LIST,
                          message);
}

