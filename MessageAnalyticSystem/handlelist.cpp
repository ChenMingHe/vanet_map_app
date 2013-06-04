#include "handlelist.h"

HandleList::HandleList(QObject *parent) :
    QObject(parent)
{
    {    //����ȫ���걨�Ŀ���
        HandleLocationMessage *handle = new HandleLocationMessage(this);
        this->registerHandler(handle);
    }{   //�����ı��Ի���Ϣ
        HandleTextMessage *handle = new HandleTextMessage(this);
        this->registerHandler(handle);
    }{   //������GPSλ����Ϣ����
        HandleNolocationMessage *handle = new HandleNolocationMessage(this);
        this->registerHandler(handle);
    }{   //�����ý���ļ���Ϣ
        HandleMediaMessage *handle = new HandleMediaMessage(this);
        this->registerHandler(handle);
    }{   //����RTT���Է�������
        HandleRttResponseMessage *handle = new HandleRttResponseMessage(this);
        this->registerHandler(handle);
    }{   //���������Է�������
        HandleBandWidthResponseMessage *handle = new HandleBandWidthResponseMessage(this);
        this->registerHandler(handle);
    }{   //������������
        HandleHopMessage *handle = new HandleHopMessage(this);
        this->registerHandler(handle);
    } {
        HandlePictureRequest *handle = new HandlePictureRequest(this);
        this->registerHandler(handle);
    }
}

void HandleList::handleMessage(AbstractMessage *message)
{
    emit newMessage(message);
}

void HandleList::registerHandler(Handler *handle)
{
    connect(this, SIGNAL(newMessage(AbstractMessage*)),
            handle, SLOT(handleMessage(AbstractMessage*)));
    connect(handle, SIGNAL(operationRequest(Componet::Name,Operations::Type,AbstractMessage*)),
            this, SIGNAL(operationRequest(Componet::Name,Operations::Type,AbstractMessage*)));
}
