#ifndef LOCALLOCATIONINFOMATION_H
#define LOCALLOCATIONINFOMATION_H
#include <QObject>
#include "Widget/Menu/Settings.h"

class LocalLocationInfomation
{
public:
    static LocalLocationInfomation &info();
    static void setLocation(qreal lat,qreal lon, qreal direct, qreal speed);

    const QString getLocalUserName();
    qreal getLatidute() const {return lat;}
    qreal getLontidute() const {return lon;}
    qreal getDirection() const {return direct;}
    qreal getSpeed() const {return speed;}

private:
    static LocalLocationInfomation *instance;
    LocalLocationInfomation();

private:
    qreal lat;
    qreal lon;
    qreal direct;
    qreal speed;
};

#endif // LOCALLOCATIONINFOMATION_H
