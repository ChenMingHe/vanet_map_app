#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include "Widget/VehicleMap/MapWidget/Widget/vehicletypemenu.h"
//#include "Widget/Menu/settingargument.h"
#include "Widget/VehicleMap/MapWidget/GraphicsArgument.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);
    virtual ~GraphicsView() {}
    void init();

signals:
    
public slots:
private:
    QGraphicsProxyWidget *menu;
    QGraphicsPixmapItem *compass;
    QGraphicsItem *warringLine;
    QGraphicsItem *viewRect;
};

#endif // GRAPHICSVIEW_H
