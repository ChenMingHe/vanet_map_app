#ifndef MAPITEM_H
#define MAPITEM_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "Widget/VehicleMap/MapWidget/GraphicsArgument.h"
#include "LogSystem/logwriter.h"

class MapItem
{
public:
    explicit  MapItem();
    virtual ~MapItem();
    void addToScene(QGraphicsScene &scene);
    void updatePos(qreal cLat, qreal cLon);

private:
    QGraphicsPixmapItem *pix;
    qreal centerLat, centerLon;
};

#endif // MAPITEM_H
