#ifndef TESTMACHINE_H
#define TESTMACHINE_H

#include <QTimer>
#include "Socket/Sockets.h"

class TestMachine : public QObject
{
    Q_OBJECT
public:
    explicit TestMachine(QObject *parent = 0);
    virtual ~TestMachine();

public slots:
    void start();
    void stop();

public:
    void increaseRounds();
    void initArgument(const QString &userName, const QString &type,int testTimes, int interval);
    int getRounds();

private:
    int testTimes;
    int rounds;
    QString type;
    QString userName;
    QTimer timer;
    int interval;

private slots:
    void emitTestMessage();
};

#endif // TESTMACHINE_H
