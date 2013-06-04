#include "vechiclemapuser.h"

VechicleMapUser::VechicleMapUser(const QString &name) :
    icon(NULL), group(NULL), userName(name),
    centerLat(0), centerLon(0), isSelf(false)
{
    if (userName == "[Me]")
        isSelf = true;
    else
        isSelf = false;

    icon = new VechicleIcon;
}


void VechicleMapUser::addToScene(QGraphicsScene &scene)
{
    QList<QGraphicsItem *> items;
    //绘制图标
    items.push_back(scene.addLine(0, -10, 8, -30));
    items.push_back(scene.addLine(8, -30, 20, -30));
    QGraphicsItem *text = scene.addSimpleText(userName);
    text->setPos(22, -(30+(text->boundingRect().height()/2)));
    items.push_back(text);
    icon->fillColor(VechicleIcon::BLUE_ICON);
    scene.addItem(icon);
    items.push_back((QGraphicsItem *)icon);
    group = scene.createItemGroup(items);

    //启动闪烁功能
    twinkle.setItem(icon);
    twinkle.setGroup(group);
    QObject::connect(&timer, SIGNAL(timeout()), &twinkle, SLOT(twinkle()));
    QObject::connect(&alive, SIGNAL(timeout()), &twinkle, SLOT(hideIcon()));
}

void VechicleMapUser::updateIconPos(double lat, double lon, double direct)
{
    //更新图标位置信息
    if (isSelf) {
        group->setPos(0, 0);
        icon->setRotation(direct);
        return;
    }

    GraphicsArgument &argument = GraphicsArgument::argument();
    qreal latPerDegree = argument.getLatPerDegreed();
    qreal lonPerDegree = argument.getLonPerDegreed();
    qreal screenWidth = argument.getScreenWidth();
    qreal screenHeight = argument.getScreenHight();
    qreal viewWidth = argument.getViewWidth();
    qreal viewHeight = argument.getViewHight();
    qreal warringRadius = argument.getWarringRadius();
    qreal rlat = (lat - centerLat) * latPerDegree; //换算成距离
    qreal rlon = (lon - centerLon) * lonPerDegree;
//    qreal dx = rx * screenWidth / viewWidth;    //换算成坐标
//    qreal dy = ry * screenHeight / viewHeight;
    qreal dx = rlon * screenWidth / viewWidth;
    qreal dy = rlat * screenHeight / viewHeight;


    group->setPos(dx, -dy);
    icon->setRotation(direct);

    if (qSqrt(rlat*rlat + rlon*rlon) < warringRadius)
        inWarring = true;
    else
        inWarring = false;

    // XXX:临时增加，对于Icon的隐藏于显示
    alive.start(argument.getDeadTime());
    group->show();
}

bool VechicleMapUser::inWarringRaudios()
{
    if (isSelf)
        return false;
    return inWarring;
}

void VechicleMapUser::saveCenterPos(double lat, double lon)
{
    centerLat = lat;
    centerLon = lon;
}

void VechicleMapUser::select(bool b)
{
    if (b) {
        timer.start(500);
    } else {
        icon->show();
        timer.stop();
    }
}


