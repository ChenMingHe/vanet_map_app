#include "vechicleicon.h"

VechicleIcon::VechicleIcon(QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    QVector<QPointF> v;
    v.push_back(QPointF(0, -10));
    v.push_back(QPointF(10,10));
    v.push_back(QPointF(0, 0));
    v.push_back(QPointF(-10, 10));
    path.addPolygon(QPolygonF(v));
}

QRectF VechicleIcon::boundingRect() const
{
    return path.boundingRect();
}

void VechicleIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawPath(path);
    switch (this->color)
    {
    case KEEP:
        break;
    case RED_ICON:
        painter->fillPath(path, Qt::red);
        break;
    case YELLOW_ICON:
        painter->fillPath(path, Qt::yellow);
        break;
    case GREEN_ICON:
        painter->fillPath(path, Qt::green);
        break;
    case BLUE_ICON:
        painter->fillPath(path, Qt::blue);
        break;
    case MAGENTA_ICON:
        painter->fillPath(path, Qt::magenta);
        break;
    default:
        painter->fillPath(path, Qt::black);
    }
}

void VechicleIcon::fillColor(ColorType color)
{
    this->color = color;
    update();
}


