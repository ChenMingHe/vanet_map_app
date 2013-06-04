#include "tcpsender.h"

TcpSender::TcpSender(QObject *parent) :
    QTcpSocket(parent) {
    connect(this, SIGNAL(connected()), this, SLOT(send()));
}

void TcpSender::sendFile(const QString &userName, const QString &fileName) {
    if (fileName.isEmpty() || userName.isEmpty()) {
        return;
    }

    if (!QFile::exists(fileName)) {
        return;
    }

    //从用户名中抓取
    QRegExp exp("\\[(.*)\\]");
    int pos = exp.indexIn(userName);
    if (pos > -1) {
        this->userName = exp.cap(1);
    } else {
        this->userName = userName;
    }
    this->fileName = fileName;

    ConnecttionArgument &argument = ConnecttionArgument::Setting();
    this->connectToHost(argument.getHost(), argument.getTCPPort());

    StaticLabel::label()->setText("prepare to send file" + fileName +
                                  "to " + userName + ", connecting.........");
    LogWriter::log().info("send file " + fileName + " to " + userName);
}

TcpSender::~TcpSender() {}

void TcpSender::send() {
    QFile *file = new QFile(fileName);
    file->setParent(this);
    if (!file->open(QFile::ReadOnly)) {
        LogWriter::log().info("Warring : can not open file " + fileName);
        return;
    }
    QString name = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    QString s = userName + " P " + name + " " + QString::number(file->size()) + " \n";
    this->write(s.toAscii());
    this->write(file->readAll());

    StaticLabel::label()->setText("Connect ready, Sending file...........");
    LogWriter::log().info("pre send msg : " + s);
}

