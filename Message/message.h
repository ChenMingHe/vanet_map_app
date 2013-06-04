#ifndef ABSTRACTMESSAGE_H
#define ABSTRACTMESSAGE_H

#include "LogSystem/logwriter.h"
#include <QStringList>
#include "MessageEnum.h"

using namespace Message;

class AbstractMessage
{
public:
    explicit AbstractMessage(QStringList &list) : messageType(UNKNOW), userName() {}
    Type getMessageType() { return messageType; }
    const QString &getUserName() { return userName; }
    virtual ~AbstractMessage() {}

private:
    Type messageType;
    QString userName;

public:
    void setMessageType(Type messageType) { this->messageType = messageType;}
protected:
    void setUserName(const QString &userName) {this->userName = userName;}
};

#endif // ABSTRACTMESSAGE_H
