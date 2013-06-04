#ifndef TCPSENDER_H
#define TCPSENDER_H

#include <QTcpSocket>
#include <QFile>
#include <QRegExp>
#include <QErrorMessage>
#include "LogSystem/logwriter.h"
#include "Widget/Menu/connecttionargument.h"
#include "Widget/Label/staticlabel.h"

class TcpSender : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpSender(QObject *parent = 0);
    virtual ~TcpSender();
    void sendFile(const QString &userName, const QString &fileName);

private slots:
    void send();

private:
    QString fileName;
    QString userName;
};

#endif // TCPSENDER_H
