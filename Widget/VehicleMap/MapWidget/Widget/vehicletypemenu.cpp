#include "vehicletypemenu.h"
#include "ui_vehicletypemenu.h"

VehicleTypeMenu::VehicleTypeMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VehicleTypeMenu)
{
    ui->setupUi(this);
}

VehicleTypeMenu::~VehicleTypeMenu()
{
    delete ui;
}
