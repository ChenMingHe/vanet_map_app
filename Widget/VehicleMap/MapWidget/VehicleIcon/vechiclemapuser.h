#ifndef VECHICLEMAPUSER_H
#define VECHICLEMAPUSER_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <qmath.h>
#include "Widget/VehicleMap/MapWidget/VehicleIcon/vechicleicon.h"
#include "twinkleicon.h"
#include "Widget/VehicleMap/MapWidget/GraphicsArgument.h"

class VechicleMapUser
{
public:
    explicit VechicleMapUser(const QString &name);
    QGraphicsScene *iconScene() {return icon->scene();}
    void setIconColor(VechicleIcon::ColorType color = VechicleIcon::KEEP) {icon->fillColor(color);}
    void addToScene(QGraphicsScene &scene);
    void updateIconPos(double lat, double lon, double direct);
    bool inWarringRaudios();
    void saveCenterPos(double lat, double lon);

public slots:
    void select(bool b);

private:
    VechicleIcon *icon;
    QGraphicsItemGroup *group;
    QTimer timer;
    QTimer alive;
    TwinkleIcon twinkle;

    QString userName;
    double centerLat, centerLon;
    bool isSelf, inWarring;
};

#endif // VECHICLEMAPUSER_H
