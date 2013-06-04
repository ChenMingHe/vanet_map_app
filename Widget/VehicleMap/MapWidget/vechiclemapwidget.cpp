#include "vechiclemapwidget.h"
#include "ui_vechiclemapwidget.h"

VechicleMapWidget::VechicleMapWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::VechicleMapWidget),
    menuGroup(NULL), compass(NULL),
    warringLine(NULL), viewRect(NULL),
    lastSelect(NULL), mapItem(NULL) {
    //初始化layout
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->gridLayout_2->setMargin(0);
    ui->horizontalLayout->setMargin(0);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

VechicleMapWidget::~VechicleMapWidget()
{
    delete ui;
}


void VechicleMapWidget::handleRequest(Operations::Type type, AbstractMessage *msg)
{
    if (type == Operations::UPDATE_LOCATION) {
        LocationMessage *m = (LocationMessage*)msg;
        if (m->isSelfMessage()) {
            updateCenterIconLocation(m->getUserName(), m->getLatitudeNumber(),
                                     m->getLontitudeNumber(), m->getDirectNumber());
            // 计算地图与中心节点的相对位置
            mapItem->updatePos(m->getLatitudeNumber(), m->getLontitudeNumber());
        } else {
            bool warring = updateIconLocation(m->getUserName(), m->getLatitudeNumber(), m->getLontitudeNumber(), m->getDirectNumber());
            if (warring) {
                m->setMessageType(Message::WARRING);
            }
        }
        setIconColor(m->getUserName(), m->getMessageType());
    }
}

void VechicleMapWidget::start()
{
    //绘制菜单
    this->drawMenu();
    //绘制指南针
    QPixmap pix("./icon/compass.png");
    compass = scene->addPixmap(pix.scaled(200, 200));
    compass->setZValue(100);

    //init radio
    ui->radioButton->setChecked(true);
    ui->radioButton_2->setChecked(true);
    ui->radioButton_5->setChecked(true);
    ui->radioButton_4->setChecked(true);
    ui->radioButton_3->setChecked(true);
}



void VechicleMapWidget::selectVehicle(QString name)
{
    if (lastSelect != NULL) {
        lastSelect->select(false);
    }

    lastSelect = userManager.get(name);
    if (lastSelect == NULL)
        return;
    lastSelect->select(true);
}

void VechicleMapWidget::initGraphview()
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    qreal sw = argument.getScreenWidth();
    qreal sh = argument.getScreenHight();
    qreal vw = argument.getViewWidth();
    qreal wr = argument.getWarringRadius();

    scene->setSceneRect(-((sw-40)/2), -((sh-40)/2), (sw-40), (sh-40));
    //设定菜单位置
    menuGroup->setPos(sw/2-100, -(sh/2-23));
    compass->setPos(-(sw/2-23), -(sh/2-23));

    //绘制视图范围矩形框
    if (viewRect != NULL)
        delete viewRect;
    qreal w = (sw-40)/2, h = (sh-40)/2;
    viewRect = scene->addRect(-w, -h, 2*w, 2*h);
    viewRect->setZValue(100);
    //绘制警告范围
    if (warringLine != NULL)
        delete warringLine;
    qreal r = wr * sw / vw;
    warringLine = scene->addEllipse(-r, -r, 2*r, 2*r, QPen(QBrush(Qt::red), 3));
    warringLine->setZValue(100);
    //添加地图
    if (mapItem != NULL)
        delete mapItem;
    mapItem = new MapItem;
    mapItem->addToScene(*scene);
}

void VechicleMapWidget::updateCenterIconLocation(const QString &userName, double lat, double lon, double direct)
{
    // 获取中心节点
    VechicleMapUser *centerUser = userManager.get(userName);
    if (centerUser == NULL)
        centerUser = userManager.add(userName, new VechicleMapUser(userName));

    // 确保添加到Scene上
    if (centerUser->iconScene() == NULL) {
        centerUser->addToScene(*scene);
    }

    // 更新中心节点位置
    centerUser->updateIconPos(lat, lon, direct);
//    centerUser->saveCenterPos(lat, lon);

    // 更新所有其他节点。
    QList<VechicleMapUser *> &list = userManager.getAll();
    foreach (VechicleMapUser *user, list) {
//        user->updateIconPos(lat, lon ,direct);
        user->saveCenterPos(lat, lon);
    }
}

bool VechicleMapWidget::updateIconLocation(const QString &userName, double lat, double lon, double direct)
{
    VechicleMapUser *user = userManager.get(userName);
    if (user == NULL) {
        user = userManager.add(userName, new VechicleMapUser(userName));
    }

    if (user->iconScene() == NULL) {
        user->addToScene(*scene);
    }

    // 更新位置信息，
    user->updateIconPos(lat, lon, direct);
    return user->inWarringRaudios();
}

void VechicleMapWidget::initGraphviewArgument()
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    argument.setScreenRect(ui->graphicsView->width()-40, ui->graphicsView->height()-40);

    //初始化warringRadio，xPerDegreed, yPerDegreed
    GraphicsSettingArgument &setting = GraphicsSettingArgument::Setting();
    argument.setPerDegreed(setting.getXPerDegreed(), setting.getYPerDegreed());
    argument.setWarringRadius(setting.getWarringRaudio());
    argument.setMapArgument(setting.getTopLat(), setting.getTopLon(),
                            setting.getButtomLat(), setting.getButtomLon());
    argument.setDeadTime(setting.getDeadTime());
}

void VechicleMapWidget::setViewRect(qreal width)
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    qreal hight = width * (ui->graphicsView->height()-40) / (ui->graphicsView->width() - 40);
    argument.setViewRect(width, hight);
}

void VechicleMapWidget::initRadioText(QRadioButton *radio)
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    radio->setText(QString::number(argument.getViewWidth()) + "*" + QString::number(argument.getViewHight()));
}

void VechicleMapWidget::setIconColor(const QString &userName, Message::Type type)
{
    VechicleMapUser *user = userManager.get(userName);
    if (user == NULL) {
        user = userManager.add(userName, new VechicleMapUser(userName));
    }

    switch (type) {
    case Message::DANGER:   //危险车辆
        user->setIconColor(VechicleIcon::RED_ICON);
        break;
    case Message::NOLOCATION: //无GPS信息车辆
        user->setIconColor(VechicleIcon::BLUE_ICON);
        break;
    case Message::SELF_LOCATION: //本地车辆
        user->setIconColor(VechicleIcon::GREEN_ICON);
        break;
    case Message::DISTANCE_LOCATION: //非本地车辆
        if (user->inWarringRaudios())
            user->setIconColor(VechicleIcon::MAGENTA_ICON);
        else
            user->setIconColor(VechicleIcon::YELLOW_ICON);
        break;
    case Message::WARRING:
        user->setIconColor(VechicleIcon::MAGENTA_ICON);
        break;
    case Message::EMERGENCY_VEHICLE:
        user->setIconColor(VechicleIcon::CYAN_ICON);
        break;
    default:
        break;
    }
}

void VechicleMapWidget::drawMenu()
{
    //绘制说明菜单
    QList<QGraphicsItem *> items;
    {
        QGraphicsItem *icon = scene->addRect(0, 0, 20, 20, QPen(), QBrush(QColor(Qt::green)));
        QGraphicsItem *text = scene->addText("Local");
        text->setPos(23, 0);
        items.push_back(icon);
        items.push_back(text);
    }{
        QGraphicsItem *icon = scene->addRect(0, 22, 20, 20, QPen(), QBrush(QColor(Qt::yellow)));
        QGraphicsItem *text = scene->addText("Distance");
        text->setPos(23, 22);
        items.push_back(icon);
        items.push_back(text);
    }{
        QGraphicsItem *icon = scene->addRect(0, 44, 20, 20, QPen(), QBrush(QColor(Qt::magenta)));
        QGraphicsItem *text = scene->addText("Warring");
        text->setPos(23, 44);
        items.push_back(icon);
        items.push_back(text);
    }{
        QGraphicsItem *icon = scene->addRect(0, 66, 20, 20, QPen(), QBrush(QColor(Qt::red)));
        QGraphicsItem *text = scene->addText("Danger");
        text->setPos(23, 66);
        items.push_back(icon);
        items.push_back(text);
    }{
        QGraphicsItem *icon = scene->addRect(0, 88, 20, 20, QPen(), QBrush(QColor(Qt::blue)));
        QGraphicsItem *text = scene->addText("NoGPS");
        text->setPos(23, 88);
        items.push_back(icon);
        items.push_back(text);
    }{
        QGraphicsItem *icon = scene->addRect(0, 110, 20, 20, QPen(), QBrush(QColor(Qt::cyan)));
        QGraphicsItem *text = scene->addText("Emergency");
        text->setPos(23, 110);
        items.push_back(icon);
        items.push_back(text);
    }
    menuGroup = scene->createItemGroup(items);
    menuGroup->setFlag(QGraphicsItem::ItemIsMovable);
}


void VechicleMapWidget::on_radioButton_toggled(bool checked)
{
    if (checked == false)
        return;
    this->initGraphviewArgument();
    this->setViewRect(GraphicsSettingArgument::Setting().getViewWidth(1));
    this->initGraphview();
    this->initRadioText(ui->radioButton);
}

void VechicleMapWidget::on_radioButton_2_toggled(bool checked)
{
    if (checked == false)
        return;
    this->initGraphviewArgument();
    this->setViewRect(GraphicsSettingArgument::Setting().getViewWidth(2));
    this->initGraphview();
    this->initRadioText(ui->radioButton_2);
}

void VechicleMapWidget::on_radioButton_3_toggled(bool checked)
{
    if (checked == false)
        return;
    this->initGraphviewArgument();
    this->setViewRect(GraphicsSettingArgument::Setting().getViewWidth(3));
    this->initGraphview();
    this->initRadioText(ui->radioButton_3);
}

void VechicleMapWidget::on_radioButton_4_toggled(bool checked)
{
    if (checked == false)
        return;
    this->initGraphviewArgument();
    this->setViewRect(GraphicsSettingArgument::Setting().getViewWidth(4));
    this->initGraphview();
    this->initRadioText(ui->radioButton_4);
}

void VechicleMapWidget::on_radioButton_5_toggled(bool checked)
{
    if (checked == false)
        return;
    this->initGraphviewArgument();
    this->setViewRect(GraphicsSettingArgument::Setting().getViewWidth(5));
    this->initGraphview();
    this->initRadioText(ui->radioButton_5);
}
