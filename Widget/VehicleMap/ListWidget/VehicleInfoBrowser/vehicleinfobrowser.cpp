#include "vehicleinfobrowser.h"
#include "ui_vehicleinfowidget.h"

VehicleInfoBrowser::VehicleInfoBrowser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VehicleInfoBrowser)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->textBrowser->setFontPointSize(12);
}

VehicleInfoBrowser::~VehicleInfoBrowser()
{
    delete ui;
}

void VehicleInfoBrowser::setTextBrowserText(const QString &text)
{
    ui->textBrowser->setText(text);
}
