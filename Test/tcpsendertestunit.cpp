#include "tcpsendertestunit.h"

TcpSenderTestUnit::TcpSenderTestUnit()
{
}

void TcpSenderTestUnit::test()
{
    QString fileName = QFileDialog::getOpenFileName();
    TcpSender *sender = new TcpSender();
    sender->sendFile("[VANET-04]", fileName);
}
