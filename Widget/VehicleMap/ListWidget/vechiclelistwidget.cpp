#include "vechiclelistwidget.h"
#include "ui_vechiclelistwidget.h"

VechicleListWidget::VechicleListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VechicleListWidget)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->gridLayout_2->setMargin(0);
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)),
            ui->stackedWidget, SLOT(setCurrentIndex(int)));

    connect(ui->listWidget, SIGNAL(currentTextChanged(QString)),
            this, SIGNAL(currentTextChange(QString)));
}

VechicleListWidget::~VechicleListWidget()
{
    delete ui;
}

void VechicleListWidget::handleRequest(Operations::Type type, AbstractMessage *msg)
{    
    const QString &userName = msg->getUserName();
    QListWidgetItem *item = listManage.get(userName);
    if (item == NULL)
        this->addNewUser(userName);

    if (type == Operations::UPDATE_LIST) {
        LocationMessage *m1 = (LocationMessage *) msg;
        updateBrowser(m1->getUserName(), m1->getLatitude(), m1->getLontitude(),
                      m1->getSpeed(), m1->getDirect(), m1->getLicense());
        setItemColor(m1->getUserName(), m1->getMessageType());
    } else if (type == Operations::UPDATE_HOP) {
        HopMessage *m = (HopMessage *) msg;
        setIconHop(m->getUserName(), m->getHopMark());
    }
}


void VechicleListWidget::updateBrowser(const QString &userName,
                                       const QString &lat, const QString &lon,
                                       const QString &speed, const QString &direct,
                                       const QString &license)
{
    QString s;
    s = "Vehicle Name :\n" + userName
            + "\nLocation :\n" + lat + ", " + lon
            + "\nSpeed :\n" + speed
            + "\nDirection : \n" + direct
            + "\nLicense : \n" + license;

    QTextBrowser *w = vehicleManage.get(userName);
    if (w != NULL)
        w->setText(s);
}

void VechicleListWidget::addNewUser(const QString &name)
{
    QListWidgetItem *item = new QListWidgetItem(name, ui->listWidget);
    if (name == "[Me]")
        item->setIcon(QIcon("./icon/local.png"));
    listManage.add(name, item);

    QTextBrowser *w = new QTextBrowser;
    w->setFontPointSize(12);
    ui->stackedWidget->addWidget(w);
    vehicleManage.add(name, w);
}

void VechicleListWidget::setIconHop(const QString &userName, HopMessage::HopType type)
{
    QListWidgetItem *item = listManage.get(userName);
    switch (type) {
    case HopMessage::SingleHop:
        item->setIcon(QIcon("./icon/single.png"));
        break;
    case HopMessage::MultiHop:
        item->setIcon(QIcon("./icon/multi.png"));
        break;
    default:
        break;
    }
}

void VechicleListWidget::setItemColor(const QString &userName, Message::Type type)
{
    QListWidgetItem *item = listManage.get(userName);
    switch (type) {
    case Message::NOLOCATION:
        item->setBackground(QBrush(QColor(Qt::blue)));
        break;
    case Message::DANGER:
        item->setBackground(QBrush(QColor(Qt::red)));
        break;
    case Message::DISTANCE_LOCATION:
        item->setBackground(QBrush(QColor(Qt::yellow)));
        break;
    case Message::SELF_LOCATION:
        item->setBackground(QBrush(QColor(Qt::green)));
        break;
    case Message::EMERGENCY_VEHICLE:
        item->setBackground(QBrush(QColor(Qt::cyan)));
        break;
    case Message::WARRING:
        item->setBackground(QBrush(QColor(Qt::magenta)));
    default:
        break;
    }
}

