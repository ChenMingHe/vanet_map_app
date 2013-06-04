#include "handlelocationmessage.h"

void HandleLocationMessage::handleMessage(AbstractMessage *message)
{
    Message::Type type = message->getMessageType();
    //����������λ����Ϣ�ı���
    if (type != Message::DANGER //��ȫ���泵��
            && type != Message::DISTANCE_LOCATION //��ͨ����
            && type != Message::SELF_LOCATION //����λ����Ϣ
            && type != Message::EMERGENCY_VEHICLE) /*��Ԯ����*/ {
        return;
    }

    //���µ�ͼ����
    emit operationRequest(Componet::VEHICLE_MAP,
                          Operations::UPDATE_LOCATION,
                          message);

    //�����б���
    emit operationRequest(Componet::VEHICLE_LIST,
                          Operations::UPDATE_LIST,
                          message);
}

