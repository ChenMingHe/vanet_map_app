#ifndef GRAPHICSSETTINGARGUMENG_H
#define GRAPHICSSETTINGARGUMENG_H

#include <QDomDocument>
#include <QTextStream>
#include <QFile>
#include <stdlib.h>
#include "LogSystem/logwriter.h"

class GraphicsSettingArgument
{
public:
    static GraphicsSettingArgument &Setting();
    void saveSetting();

    void setPerDegree(qreal xper,qreal yper);
    void setWarringRaudio(qreal raudio);
    void setTopPos(double x, double y);
    void setButtomPos(double x, double y);
    void setViewRectWidth(qreal lv1, qreal lv2, qreal lv3, qreal lv4, qreal lv5);
    void setDeadTime(qreal t) { deadTime = t; }

    qreal getXPerDegreed() { return xPerDegreed; }
    qreal getYPerDegreed() { return yPerDegreed; }
    qreal getWarringRaudio() { return warringRaudio;}
    double getTopLat() { return lat_top; }
    double getTopLon() { return lon_top; }
    double getButtomLat() { return lat_buttom; }
    double getButtomLon() { return lon_buttom; }
    qreal getViewWidth(int lv);
    qreal getDeadTime() { return deadTime; }

private:
    static GraphicsSettingArgument *instance;
    GraphicsSettingArgument();

private:
    qreal xPerDegreed, yPerDegreed;
    qreal warringRaudio;
    double lat_top;
    double lon_top;
    double lat_buttom;
    double lon_buttom;
    qreal viewLv1;
    qreal viewLv2;
    qreal viewLv3;
    qreal viewLv4;
    qreal viewLv5;
    qreal deadTime;
};

#endif // GRAPHICSSETTINGARGUMENG_H
