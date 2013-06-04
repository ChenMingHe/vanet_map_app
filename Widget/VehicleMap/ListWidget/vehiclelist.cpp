#include "vehiclelist.h"
#include "ui_vehiclelist.h"

VehicleList::VehicleList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VehicleList)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);

    connect(ui->obuList, SIGNAL(currentTextChanged(QString)),
            this, SIGNAL(currentTextChange(QString)));
}

VehicleList::~VehicleList()
{
    delete ui;
}

void VehicleList::handleRequest(Operations::Type type, AbstractMessage *msg)
{
    const QString &userName = msg->getUserName();
    if (!ui->obuList->hasUser(userName)) {
        if (userName == "[Me]")
            ui->obuList->addItem(new QListWidgetItem(QIcon("./icon/local.png"), userName, ui->obuList));
        else
            ui->obuList->addItem(new QListWidgetItem(userName, ui->obuList));
        ui->obuInfoStack->addWidget(userName);

        Timer *timer = new Timer(this);
        timer->setUserName(userName);
        userTimer.insert(userName, timer);
        connect(timer, SIGNAL(userTimeOut(QString)), ui->obuInfoStack, SLOT(hideWidget(QString)));
        connect(timer, SIGNAL(userTimeOut(QString)), ui->obuList, SLOT(removeItem(QString)));
        timer->start(GraphicsArgument::argument().getDeadTime());
    }

    // 每次更新定时器。
    QMap<QString, QTimer *>::iterator itr = userTimer.find(userName);
    if (itr != userTimer.end()) {
        qreal deadTime =  GraphicsArgument::argument().getDeadTime();
        ((QTimer *)itr.value())->start(deadTime);
    }

    if (type == Operations::UPDATE_LIST) {
        LocationMessage *m1 = (LocationMessage *) msg;
        QString s("Vehicle Name :  " + userName
                + "\nLocation :\n" + m1->getLatitude() + ", " + m1->getLontitude()
                + "\nSpeed :\t" + m1->getSpeed()
                + "\nDirection :\t" + m1->getDirect()
                + "\nLicense :\t" + m1->getLicense());
        ui->obuInfoStack->updateVehicleInfo(userName, s);
        ui->obuList->setItemColor(userName, m1->getMessageType());
    } else if (type == Operations::UPDATE_HOP) {
        HopMessage *m = (HopMessage *) msg;
        ui->obuList->setIconHop(userName, m->getHopMark());
    }
}



