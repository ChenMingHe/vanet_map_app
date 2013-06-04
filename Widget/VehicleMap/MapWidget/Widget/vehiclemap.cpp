#include "vehiclemap.h"
#include "ui_vehiclemap.h"

VehicleMap::VehicleMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VehicleMap)
{
    ui->setupUi(this);
}

VehicleMap::~VehicleMap()
{
    delete ui;
}
