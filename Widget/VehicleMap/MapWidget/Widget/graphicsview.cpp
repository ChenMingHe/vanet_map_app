#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent), warringLine(NULL), viewRect(NULL)
{
    QGraphicsScene *s = new QGraphicsScene(this);
    this->setScene(s);

    s->addRect(0, 0, 10, 10);

    menu = s->addWidget(new VehicleTypeMenu(this));

    QPixmap pix("./icon/compass.png");
    compass = s->addPixmap(pix.scaled(200, 200));
    compass->setZValue(100);
}

void GraphicsView::init()
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    // 初始化显示器大小
    qreal sw = this->width() - 40;
    qreal sh = this->width() - 40;
    argument.setScreenRect(sw, sh);

    // 初始化视图范围
    qreal vw = argument.getViewWidth();
    qreal vh = vw * sw /sh;
    argument.setViewRect(vw, vh);

    qreal wr = argument.getWarringRadius();

    QGraphicsScene *scene = this->scene();
    scene->setSceneRect(-sw/2, -sh/2, sw, sh);
    menu->setPos(sw/2-100, -(sh/2-23));
    compass->setPos(-(sw/2-23), -(sh/2-23));

    //绘制视图范围矩形框
    if (viewRect != NULL)
        delete viewRect;
    viewRect = scene->addRect(-sw/2, -sh/2, sw, sh);
    viewRect->setZValue(100);
    //绘制警告范围
    if (warringLine != NULL)
        delete warringLine;
    qreal r = wr * sw / vw;
    warringLine = scene->addEllipse(-r, -r, 2*r, 2*r, QPen(QBrush(Qt::red), 3));
    warringLine->setZValue(100);
}


