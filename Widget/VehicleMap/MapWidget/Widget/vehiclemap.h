#ifndef VEHICLEMAP_H
#define VEHICLEMAP_H

#include <QWidget>

namespace Ui {
class VehicleMap;
}

class VehicleMap : public QWidget
{
    Q_OBJECT
    
public:
    explicit VehicleMap(QWidget *parent = 0);
    ~VehicleMap();
    
private:
    Ui::VehicleMap *ui;
};

#endif // VEHICLEMAP_H
