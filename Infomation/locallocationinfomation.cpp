#include "locallocationinfomation.h"

LocalLocationInfomation *LocalLocationInfomation::instance = NULL;
LocalLocationInfomation &LocalLocationInfomation::info()
{
    if (instance == NULL)
        instance = new LocalLocationInfomation;
    return *instance;
}


void LocalLocationInfomation::setLocation(qreal lat, qreal lon, qreal direct, qreal speed)
{
    if (instance == NULL)
        instance = new LocalLocationInfomation;
    instance->lat = lat;
    instance->lon = lon;
    instance->direct = direct;
    instance->speed = speed;
}

const QString LocalLocationInfomation::getLocalUserName()
{
    return ConnecttionArgument::Setting().getLocalUserName();
}

LocalLocationInfomation::LocalLocationInfomation(): lat(0), lon(0), direct(0) {}
