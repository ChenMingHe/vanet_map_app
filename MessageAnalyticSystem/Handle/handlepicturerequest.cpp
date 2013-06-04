#include "handlepicturerequest.h"

void HandlePictureRequest::handleMessage(AbstractMessage *message) {
    if (message->getMessageType() != Message::PICTURE_REQUEST)
        return;

    LogDebug(0) << "send picture back";

    PictureRequestMessage *m = (PictureRequestMessage *)message;

    TcpSender *sender = new TcpSender(this);
    sender->sendFile(m->getUserName(), "./pic/1.png");
}
