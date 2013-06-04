#include "filetrasmitunit.h"

FileTransmitUnit::FileTransmitUnit(QObject *parent) :
    QObject(parent),fileSize(0), fileRestSize(0),
    sk(NULL), file(NULL)
{
}

void FileTransmitUnit::run(QTcpSocket *sk) {
    this->sk = sk;
    sk->setParent(this);
    connect(sk, SIGNAL(readyRead()), this, SLOT(recvFile()));
}

void FileTransmitUnit::recvFile() {
    if (file == NULL) {
        this->initFileBaseProperty();

        QProgressBar *bar = StaticProgressBar::progressBar();
        bar->show();
        bar->setMaximum(fileSize);
        bar->setValue(0);
        StaticLabel::label()->setText("new file receive : My" + fileName);
        return;
    } else {
        qint64 rest = this->recvFileData();
        StaticProgressBar *bar = StaticProgressBar::progressBar();
        bar->setValue(fileSize - fileRestSize);
        if (rest > 0)
            return;

        file->close();;
        sk->close();
        emit fileRecvFinish();
    }
}

void FileTransmitUnit::initFileBaseProperty() {
    QByteArray msg = sk->readLine(1000);
    qDebug() << msg;
    QString st(msg);
    QStringList list = st.split(" ", QString::SkipEmptyParts);
    fileName = "./Pic/My" + list.at(2);
    fileSize = list.at(3).toInt();
    fileRestSize = fileSize;
    fileType = list.at(1);
    desc = st;

    file = new QFile(fileName);
    file->setParent(this);
    file->open(QIODevice::WriteOnly);
}

qint64 FileTransmitUnit::recvFileData() {

    int readSize = 0;
    while (sk->bytesAvailable()) {
        readSize = sk->bytesAvailable();
        file->write(sk->read(readSize));
        fileRestSize -= readSize;
    }

    return fileRestSize;
}
