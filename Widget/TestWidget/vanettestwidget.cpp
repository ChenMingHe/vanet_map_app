#include "vanettestwidget.h"
#include "ui_vanettestwidget.h"

VanetTestWidget::VanetTestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VanetTestWidget)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->gridLayout_2->setMargin(0);
    ui->groupBox->layout()->setMargin(0);

    //将测试窗口与列表相关联
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)),
            ui->stackedWidget, SLOT(setCurrentIndex(int)));
}

VanetTestWidget::~VanetTestWidget()
{
    delete ui;
}

void VanetTestWidget::handleRequest(Componet::Name rtype, Operations::Type oType, AbstractMessage *msg)
{
    const QString &userName = msg->getUserName();
    if (!listItemManager.has(userName))
        addNewTestWidget(userName);

    switch (rtype) {
    case Componet::BANDWIDTH_TEST:
        bandwidthManage.get(userName)->handleRequest(oType,
                                                     ((BandWidthResponsMessage *)msg)->getRounds(),
                                                     ((BandWidthResponsMessage *)msg)->getValue());
        break;
    case Componet::RTT_TEST:
        rttManage.get(userName)->handleRequest(oType,
                                               ((RttResponseMessage *)msg)->getRounds(),
                                               ((RttResponseMessage *)msg)->getValue());
        break;
    case Componet::TEST_LIST:
        this->setListHopIcon(userName, ((HopMessage *)msg)->getHopMark());
        break;
    default:
        break;
    }
}

void VanetTestWidget::addNewTestWidget(const QString &name)
{
    if (listItemManager.has(name)) {
        return;
    }
    QListWidgetItem *item = new QListWidgetItem(name, ui->listWidget);
    listItemManager.add(name, item);

    //init layout
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setMargin(0);
    ui->stackedWidget->addWidget(widget);

    //init bandwidth test widget;
    BandWidgetTestWidget *band;
    band = bandwidthManage.get(name);
    if (band == NULL) {
        band = bandwidthManage.add(name, new BandWidgetTestWidget);
        band->setUserName(name);
        layout->addWidget(band);
    }

    //init rtt test widget;
    RttTestWidget *rtt = rttManage.get(name);
    if (rtt == NULL) {
        rtt = rttManage.add(name, new RttTestWidget);
        rtt->setUserName(name);
        layout->addWidget(rtt);
    }
}

void VanetTestWidget::setListHopIcon(const QString &userName, HopMessage::HopType type)
{
    QListWidgetItem *item = listItemManager.get(userName);
    switch(type) {
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


