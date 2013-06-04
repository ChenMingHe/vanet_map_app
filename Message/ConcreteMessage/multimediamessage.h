#ifndef MULTIMEDIAMESSAGE_H
#define MULTIMEDIAMESSAGE_H

#include "Message/message.h"

class MultiMediaMessage : public AbstractMessage
{
public:
    explicit MultiMediaMessage(QStringList &list):
        AbstractMessage(list)
    {
        LogDebug(0) << "receive MultiMedia Datagram";
        this->setUserName(list.at(0));
        this->fileName = list.at(3);
        if (list.at(2) == "P") {
            this->setMessageType(Message::PICTURE);
        }
    }


    const QString &getFileName() { return fileName; }

private:
    QString fileName;
};

#endif // MULTIMEDIAMESSAGE_H
