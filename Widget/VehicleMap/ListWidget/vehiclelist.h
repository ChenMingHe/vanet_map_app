#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <QWidget>
#include <QMap>
#include <QTimer>
#include "Manager/Manager.h"
#include "MessageAnalyticSystem/Handlers.h"
#include "Widget/VehicleMap/MapWidget/GraphicsArgument.h"
#include "Widget/VehicleMap/ListWidget/timer.h"

namespace Ui {
class VehicleList;
}

class VehicleList : public QWidget
{
    Q_OBJECT
    
public:
    explicit VehicleList(QWidget *parent = 0);
    ~VehicleList();
    void handleRequest(Operations::Type type, AbstractMessage *msg);
    
private:
    Ui::VehicleList *ui;

signals:
    void currentTextChange(QString);

private:
    QMap<QString, QTimer *> userTimer;
};

#endif // VEHICLELIST_H
