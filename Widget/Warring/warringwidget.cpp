#include "warringwidget.h"
#include "ui_warringwidget.h"

WarringWidget::WarringWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::WarringWidget) {
    ui->setupUi(this);

    ui->VehicleBroken->setIcon(QIcon("./icon/vehicleBroken1.png"));
    ui->VehicleBroken->setIconSize(QSize(60, 50));

    ui->RoadConstruction->setIcon(QIcon("./icon/daolusigong1.png"));
    ui->RoadConstruction->setIconSize(QSize(60, 50));

    ui->EmergencyVehicle->setIcon(QIcon("./icon/jiuhuche1.png"));
    ui->EmergencyVehicle->setIconSize(QSize(60, 50));

    ui->RoadInfomationRequest->setIcon(QIcon("./icon/fangxiangpa1.png"));
    ui->RoadInfomationRequest->setIconSize(QSize(60, 50));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sendBrokenDownMsg()));

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()),this, SLOT(sendEmergencyVehicleMsg()));

    roadContructTimer = new QTimer(this);

    ui->horizontalLayout->setMargin(0);
    ui->verticalLayout->setMargin(0);
}

WarringWidget::~WarringWidget() {
    delete ui;
}

void WarringWidget::on_RoadConstruction_clicked(bool checked) {
    if (checked) {
        StaticLabel::label()->setText("send [Road Contruction message] to [All] OBU");
//        StatuButtons::statu()->set
        roadContructTimer->start(5000);
    } else {
        StaticLabel::label()->setText("STOP! send [Road Contruction message] to [All] OBU");
        StatuButtons::statu()->setEmergencyState(false);
        roadContructTimer->stop();
    }
}

void WarringWidget::on_RoadInfomationRequest_clicked() {
    //注意：这里强制要求RSU名字为[RSU]
    QString msg;
    LocalLocationInfomation &info = LocalLocationInfomation::info();
    msg = "[" + info.getLocalUserName() + "]" + " [123] M ./Pic/1.jpg";
    UdpSender::socket().sendData("A [RSU] " + msg + " \n");
    LogDebug(0) << "A [RSU] " + msg + " \n";
    StaticLabel::label()->setText("request [Road Infomation] from [RSU]");
}

void WarringWidget::sendBrokenDownMsg() {
    QString msg;
    LocalLocationInfomation &info = LocalLocationInfomation::info();
    int decpt, sign;
    char *c = ecvt(info.getLontidute(), 10, &decpt, &sign);
    QString s(c);
    s.insert(decpt, ".");
    msg = "[" + info.getLocalUserName() + "]" +
            " [00] R time " +
            QString::number(info.getLatidute()) + " N " +
            s + " E " +
            QString::number(info.getSpeed()) + " " +
            QString::number(info.getDirection());
    UdpSender::socket().sendData("A [ALL] " + msg + " \n");
}

void WarringWidget::sendEmergencyVehicleMsg(){
    QString msg;
    LocalLocationInfomation &info = LocalLocationInfomation::info();
    int decpt, sign;
    char *c = ecvt(info.getLontidute(), 10, &decpt, &sign);
    QString s(c);
    s.insert(decpt, ".");
    msg = "[" + info.getLocalUserName() + "]" +
            " [00] E time " +
            QString::number(info.getLatidute()) + " N " +
            s + " E " +
            QString::number(info.getSpeed()) + " " +
            QString::number(info.getDirection());
    UdpSender::socket().sendData("A [ALL] " + msg + " \n");
}

void WarringWidget::sendRoadContructionMsg()
{
    QString msg;
    msg = "[RSU] [00] A !!!WARRING!!! Road Construction";
    UdpSender::socket().sendData("A [ALL] " + msg + " \n");
    StaticLabel::label()->setText("send [Road Construction] message to [All]");
}

void WarringWidget::on_VehicleBroken_clicked(bool checked) {
    if (checked) {
        StaticLabel::label()->setText("send [Danger message] to [ALL] OBU");
        StatuButtons::statu()->setWarringState(true);
        timer->start(SettingArgument::Setting().getWarringInterval());
    } else {
        StaticLabel::label()->setText("STOP! send [Danger message] to [ALL] OBU");
        StatuButtons::statu()->setWarringState(false);
        timer->stop();;
    }
}

void WarringWidget::on_EmergencyVehicle_clicked(bool checked) {
    if (checked) {
        StaticLabel::label()->setText("send [Emergency message] to [All] OBU");
        StatuButtons::statu()->setEmergencyState(true);
        timer2->start(SettingArgument::Setting().getWarringInterval());
    } else {
        StaticLabel::label()->setText("STOP! send [Emergency message] to [All] OBU");
        StatuButtons::statu()->setEmergencyState(false);
        timer2->stop();
    }
}
