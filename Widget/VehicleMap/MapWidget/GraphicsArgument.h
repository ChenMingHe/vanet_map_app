#ifndef GRAPHICSARGUMENT_H
#define GRAPHICSARGUMENT_H

#include <QObject>

class GraphicsArgument {
public:
    static GraphicsArgument &argument() {
        if (instance == NULL)
            instance = new GraphicsArgument;
        return *instance;
    }

    void setPerDegreed(qreal xper, qreal yper) {
        xPerDegreed = xper; yPerDegreed = yper;
    }

    void setScreenRect(qreal w, qreal h) {
        screenWidth = w; screenHight = h;
    }

    void setViewRect(qreal w, qreal h) {
        viewWidth = w; viewHight = h;
    }

    void setWarringRadius(qreal r) {
        warringRadius = r;
    }

    void setMapArgument(double tlat, double tlon, double blat, double blon) {
        topLat = tlat; topLon = tlon;
        buttomLat = blat; buttomLon = blon;
    }

    void setDeadTime(qreal t) { deadTime = t; }

    qreal getLatPerDegreed() { return xPerDegreed; }
    qreal getLonPerDegreed() { return yPerDegreed; }
    qreal getScreenWidth() { return screenWidth; }
    qreal getScreenHight() { return screenHight;}
    qreal getViewWidth() { return viewWidth; }
    qreal getViewHight() { return viewHight; }
    qreal getWarringRadius() { return warringRadius; }
    double getMapTopLat() { return topLat; }
    double getMapTopLon()  { return topLon; }
    double getMapButtomLat()  { return buttomLat; }
    double getMapButtomLon() { return buttomLon; }
    qreal getDeadTime() { return deadTime; }

private:
    GraphicsArgument() :
        xPerDegreed(0), yPerDegreed(0),
        screenWidth(0), screenHight(0),
        viewWidth(0), viewHight(0),
        warringRadius(0) {}
    static GraphicsArgument *instance;

private:
    qreal xPerDegreed, yPerDegreed;
    qreal screenWidth, screenHight;
    qreal viewWidth, viewHight;
    qreal warringRadius;
    double topLat, topLon;
    double buttomLat, buttomLon;
    qreal deadTime;
};
#endif // GRAPHICSARGUMENT_H
