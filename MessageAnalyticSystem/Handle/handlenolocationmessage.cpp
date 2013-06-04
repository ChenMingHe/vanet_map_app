#include "handlenolocationmessage.h"

void HandleNolocationMessage::handleMessage(AbstractMessage *message)
{
    //����NoLocation��Ϣ�����ô�������Ҫ�������������λ����Ϣ������
    if (message->getMessageType() != Message::NOLOCATION)
        return;

    //���µ�ͼ����
    emit operationRequest(Componet::VEHICLE_MAP,
                          Operations::UPDATE_LOCATION,
                          message);

    //�����б���
    emit operationRequest(Componet::VEHICLE_LIST,
                          Operations::UPDATE_LIST,
                          message);
}
