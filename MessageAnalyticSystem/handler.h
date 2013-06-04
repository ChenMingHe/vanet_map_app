#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "Message/Messages.h"
#include "ComponentEnum.h"
#include "OperationsEnum.h"

class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = 0) : QObject(parent) {}
    virtual ~Handler() {}

public slots:
    virtual void handleMessage(AbstractMessage *message) = 0;

signals:
    void operationRequest(Componet::Name, Operations::Type, AbstractMessage *);
};

#endif // ABSTRACTHANDLER_H
