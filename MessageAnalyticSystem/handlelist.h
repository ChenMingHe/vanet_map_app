#ifndef HANDLELIST_H
#define HANDLELIST_H

#include <QObject>
#include "Message/message.h"
#include "Handlers.h"

class HandleList : public QObject
{
    Q_OBJECT
public:
    explicit HandleList(QObject *parent = 0);
    
signals:
    void newMessage(AbstractMessage*);
    void operationRequest(Componet::Name, Operations::Type, AbstractMessage*);

public slots:
    void handleMessage(AbstractMessage *message);

private:
    void registerHandler(Handler *handle);
};

#endif // HANDLELIST_H
