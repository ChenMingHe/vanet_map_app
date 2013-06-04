#include "handlelist.h"

HandleList::HandleList(QObject *parent) :
    QObject(parent)
{
    {    //处理安全坐标报文控制
        HandleLocationMessage *handle = new HandleLocationMessage(this);
        this->registerHandler(handle);
    }{   //处理文本对话信息
        HandleTextMessage *handle = new HandleTextMessage(this);
        this->registerHandler(handle);
    }{   //处理无GPS位置信息报文
        HandleNolocationMessage *handle = new HandleNolocationMessage(this);
        this->registerHandler(handle);
    }{   //处理多媒体文件信息
        HandleMediaMessage *handle = new HandleMediaMessage(this);
        this->registerHandler(handle);
    }{   //处理RTT测试反馈数据
        HandleRttResponseMessage *handle = new HandleRttResponseMessage(this);
        this->registerHandler(handle);
    }{   //处理带宽测试反馈数据
        HandleBandWidthResponseMessage *handle = new HandleBandWidthResponseMessage(this);
        this->registerHandler(handle);
    }{   //处理跳数报文
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
