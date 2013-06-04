#ifndef VECHICLEICON_H
#define VECHICLEICON_H

#include <QGraphicsItem>
#include <QPainter>
#include "LogSystem/logwriter.h"



class VechicleIcon : public QGraphicsItem
{
public:
    typedef int ColorType;
    explicit VechicleIcon(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void fillColor(ColorType color);
    enum {
        UNKNOWN = 0,
        KEEP,
        YELLOW_ICON, //Distance
        GREEN_ICON,  //Local
        RED_ICON,    //Danger
        BLUE_ICON,   //NoGPS
        MAGENTA_ICON, //Warring
        CYAN_ICON    //Emergency
    };

private:
    QPainterPath path;
    ColorType color;
    QGraphicsTextItem item;
};

#endif // VECHICLEICON_H
