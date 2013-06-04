#ifndef HANDLEPICTUREREQUEST_H
#define HANDLEPICTUREREQUEST_H

#include <QFile>
#include "MessageAnalyticSystem/handler.h"
#include "Socket/tcpsender.h"

class HandlePictureRequest : public Handler
{
public:
    explicit HandlePictureRequest(QObject *parent = 0) : Handler(parent) {}

public slots:
    void handleMessage(AbstractMessage *message);
};

#endif // HANDLEPICTUREREQUEST_H
