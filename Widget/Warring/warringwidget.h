#ifndef WARRINGWIDGET_H
#define WARRINGWIDGET_H

#include <QWidget>
#include <QTimer>
#include <stdlib.h>
#include <stdio.h>
#include "Socket/Sockets.h"
#include "Infomation/locallocationinfomation.h"
#include "Widget/Label/staticlabel.h"
#include "Widget/Statu/statubuttons.h"
#include "Widget/Menu/Settings.h"

namespace Ui {
class WarringWidget;
}

class WarringWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit WarringWidget(QWidget *parent = 0);
    ~WarringWidget();
    
private slots:
    void on_RoadConstruction_clicked(bool checked);
    void on_RoadInfomationRequest_clicked();
    void sendBrokenDownMsg();
    void sendEmergencyVehicleMsg();
    void sendRoadContructionMsg();
    void on_VehicleBroken_clicked(bool checked);
    void on_EmergencyVehicle_clicked(bool checked);

private:
    Ui::WarringWidget *ui;
    QTimer *timer;
    QTimer *timer2;
    QTimer *roadContructTimer;
};

#endif // WARRINGWIDGET_H
