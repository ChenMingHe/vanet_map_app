#include "timer.h"

Timer::Timer(QObject *parent) :
    QTimer(parent)
{
    connect(this, SIGNAL(timeout()), this, SLOT(userTimeout()));
}

void Timer::setUserName(const QString &name)
{
    timerName = name;
}

void Timer::userTimeout()
{
    emit userTimeOut(timerName);
}

