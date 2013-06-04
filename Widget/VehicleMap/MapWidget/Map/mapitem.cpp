#include "mapitem.h"

MapItem::MapItem()
{
}

MapItem::~MapItem()
{
    delete pix;
}

void MapItem::addToScene(QGraphicsScene &scene)
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    qreal ptoplat = argument.getMapTopLat();
    qreal ptoplon = argument.getMapTopLon();
    qreal pbuttomlat = argument.getMapButtomLat();
    qreal pbuttomlon = argument.getMapButtomLon();

    //保存图片中心位置坐标
    centerLat = (ptoplat + pbuttomlat) / 2;
    centerLon = (ptoplon + pbuttomlon) / 2;

    qreal latPer = argument.getLatPerDegreed();
    qreal lonPer = argument.getLonPerDegreed();
    qreal sx = argument.getScreenWidth();
    qreal sy = argument.getScreenHight();
    qreal vx = argument.getViewWidth();
    qreal vy = argument.getViewHight();

//    qreal w = (qAbs(ptoplat - pbuttomlat) * latPer * sx) / vx;
//    qreal h = (qAbs(ptoplon - pbuttomlon) * lonPer * sy) / vy;
    qreal w = (qAbs(ptoplon - pbuttomlon) * lonPer * sx) / vx;
    qreal h = (qAbs(ptoplat - pbuttomlat) * latPer * sy) / vy;

    QPixmap map("./map/map.png");
    pix = scene.addPixmap(map.scaled(w, h));

    //设置坐标变换
    QTransform transform;
    transform.translate(-w/2, -h/2);
    pix->setTransform(transform);
}

void MapItem::updatePos(qreal cLat, qreal cLon)
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    qreal latPer = argument.getLatPerDegreed();
    qreal lonPer = argument.getLonPerDegreed();
    qreal sx = argument.getScreenWidth();
    qreal sy = argument.getScreenHight();
    qreal vx = argument.getViewWidth();
    qreal vy = argument.getViewHight();

//    qreal px = (centerLat - cLat) * latPer * sx / vx;
//    qreal py = (centerLon - cLon) * lonPer * sy / vy;
    qreal px = (centerLon - cLon) * lonPer * sx / vx;
    qreal py = (centerLat - cLat) * latPer * sy / vy;
    pix->setPos(px, -py);
}

