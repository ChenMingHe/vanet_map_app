#ifndef VECHICLEMAPWIDGET_H
#define VECHICLEMAPWIDGET_H

#include <QWidget>
#include <QGraphicsLineItem>
#include <QGraphicsItemGroup>
#include <QPolygon>
#include <QRadioButton>
#include "Widget/VehicleMap/MapWidget/VehicleIcon/vechiclemapuser.h"
#include "LogSystem/logwriter.h"
#include "MessageAnalyticSystem/Handlers.h"
#include "Manager/Manager.h"
#include "GraphicsArgument.h"
#include "Widget/Menu/Settings.h"
#include "Map/mapitem.h"


namespace Ui {
class VechicleMapWidget;
}

class VechicleMapWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit VechicleMapWidget(QWidget *parent = 0);
    ~VechicleMapWidget();
    void handleRequest(Operations::Type type, AbstractMessage *msg);
    void start();


public slots:
    void selectVehicle(QString name);

private:
    Ui::VechicleMapWidget *ui;
    QGraphicsScene *scene;

    QGraphicsItemGroup *menuGroup;
    QGraphicsPixmapItem *compass;
    QGraphicsItem *warringLine, *viewRect;

    VechicleMapUser *lastSelect;
    MapItem *mapItem;
    Manager<VechicleMapUser> userManager;

private:
    void initGraphview();
    void updateCenterIconLocation(const QString &userName,
                                  double lat, double lon,
                                  double direct);
    bool updateIconLocation(const QString &userName,
                            double lat, double lon,
                            double direct);
    void initGraphviewArgument();
    void setViewRect(qreal width);
    void initRadioText(QRadioButton *radio);

    void setIconColor(const QString &userName, Message::Type type);
    void drawMenu();

private slots:
    void on_radioButton_toggled(bool checked);
    void on_radioButton_2_toggled(bool checked);
    void on_radioButton_3_toggled(bool checked);
    void on_radioButton_4_toggled(bool checked);
    void on_radioButton_5_toggled(bool checked);
};

#endif // VECHICLEMAPWIDGET_H
