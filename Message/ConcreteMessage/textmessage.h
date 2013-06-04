#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

#include "Message/message.h"


class TextMessage : public AbstractMessage
{
public:
    TextMessage(QStringList &list):
        AbstractMessage(list)
    {
        for (int i = 3; i < list.size(); i++) {
            text.append(list.at(i) + " ");
        }
        this->setMessageType(Message::TEXT);
        this->setUserName(list.at(0));
    }

    const QString &getText() { return text; }

private:
    QString text;
};

#endif // TEXTMESSAGE_H
