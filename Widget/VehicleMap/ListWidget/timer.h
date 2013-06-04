#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include "LogSystem/logwriter.h"

class Timer : public QTimer
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = 0);
    
    void setUserName(const QString &name);

signals:
    void userTimeOut(QString);

public slots:
private slots:
    void userTimeout();

private:
    QString timerName;
};

#endif // TIMER_H
