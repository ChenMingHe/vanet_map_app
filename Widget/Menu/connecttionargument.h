#ifndef CONNECTTIONARGUMENT_H
#define CONNECTTIONARGUMENT_H

#include <QHostAddress>
#include <QDomDocument>
#include <QTextStream>
#include <QFile>

class ConnecttionArgument
{
public:
    static ConnecttionArgument &Setting();
    void saveSetting();

    void setHost(const QString &s) {host.setAddress(s);}
    void setHost(const QHostAddress &host) {this->host = host;}
    void setUDPPort(const QString &port) {this->udpPort = port.toInt();}
    void setUDPPort(qint16 port) {this->udpPort = port;}
    void setTCPPort(const QString &port) {this->tcpPort = port.toInt();}
    void setTCPPort(qint16 port) {this->tcpPort = port;}
    void setLocalUserName(const QString &name) {this->userName = name;}

    const QHostAddress &getHost() const {return host;}
    const int getUDPPort() const {return udpPort;}
    const int getTCPPort() const {return tcpPort;}
    const QString &getLocalUserName() const {return userName;}

private:
    QHostAddress host;
    int udpPort;
    int tcpPort;
    QString userName;

private:
    static ConnecttionArgument *instance;
    ConnecttionArgument();
};

#endif // CONNECTTIONARGUMENT_H
