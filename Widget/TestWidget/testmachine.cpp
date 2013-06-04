#include "testmachine.h"

TestMachine::TestMachine(QObject *parent) :
    QObject(parent), testTimes(0), rounds(0),
    type(), userName(), interval(100000) {
    connect(&timer, SIGNAL(timeout()), this, SLOT(emitTestMessage()));
}

TestMachine::~TestMachine()
{
}

void TestMachine::start()
{
    rounds = 0;
    timer.start(interval);
}

void TestMachine::stop()
{
    timer.stop();
}

void TestMachine::increaseRounds()
{
    if (++rounds >= testTimes)
        timer.stop();
}

void TestMachine::initArgument(const QString &userName, const QString &type, int testTimes, int interval)
{
    this->userName = userName;
    this->type = type;
    this->testTimes = testTimes;
    this->interval = interval;
}

int TestMachine::getRounds()
{
    return rounds;
}

void TestMachine::emitTestMessage()
{
    UdpSender::socket().sendData(type + userName + " " + QString::number(rounds));
}
