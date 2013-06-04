#ifndef INDATAANALYTIC_H
#define INDATAANALYTIC_H

#include <QByteArray>
#include "Message/Messages.h"

class InDataAnalytic :public QObject
{
    Q_OBJECT
public:
    explicit InDataAnalytic(QObject *parent = 0);

signals:
    void newMessage(AbstractMessage *);

public slots:
    void doDataAnalytic(QByteArray &datagram);
};

#endif // INPUTDATAANALYTIC_H
