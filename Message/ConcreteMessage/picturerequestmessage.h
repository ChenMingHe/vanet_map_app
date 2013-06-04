#ifndef PICTUREREQUESTMESSAGE_H
#define PICTUREREQUESTMESSAGE_H

#include "Message/message.h"

class PictureRequestMessage : public AbstractMessage
{
public:
    explicit PictureRequestMessage(QStringList &list) :
        AbstractMessage(list)
    {
        this->setMessageType(Message::PICTURE_REQUEST);
        this->setUserName(list.at(0));
        fileName = list.at(2);
    }
    const QString &getFileName() { return fileName;}

private:
    QString fileName;
};

#endif // PICTUREREQUESTMESSAGE_H
