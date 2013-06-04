#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), startFlag(false)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    showMaximized();

/*    {   //init test Widget
        testWidget = new TestWidget;
        QLayout *layout = new QGridLayout();
        layout->setMargin(0);
        ui->widget->setLayout(layout);
        ui->widget->layout()->addWidget(testWidget);
    }*/ {   //init Location Widget
        conversationWidget = new ConversationWidget;
//        vechicleListWidget = new VechicleListWidget;
        vechicleListWidget = new VehicleList(this);
        vechicleMapWidget = new VechicleMapWidget;
        warringWidget = new WarringWidget;
        QGridLayout *layout = new QGridLayout();
        layout->setMargin(0);
        layout->addWidget(vechicleMapWidget, 0, 0, 2, 1);
        layout->addWidget(warringWidget, 0, 1, 2, 1);
        layout->addWidget(vechicleListWidget, 0, 2);
        layout->addWidget(conversationWidget, 1, 2);
        ui->tab->setLayout(layout);
        ui->tabWidget->setTabText(0, "Location");
        connect(vechicleListWidget, SIGNAL(currentTextChange(QString)),
                conversationWidget, SLOT(talkToUser(QString)));
        connect(vechicleListWidget, SIGNAL(currentTextChange(QString)),
                vechicleMapWidget, SLOT(selectVehicle(QString)));
    } {   //初始化测试窗口
        vanetTestWidget = new VanetTestWidget;
        QGridLayout *layout = new QGridLayout(ui->tab_2);
        layout->addWidget(vanetTestWidget);
        layout->setMargin(0);
        ui->tabWidget->setTabText(1, "Test");
    } {   //初始化多媒体信息显示框
        multiMediaWidget = new MudiamediaWidget;
        QGridLayout *layout = new QGridLayout(ui->tab_3);
        layout->addWidget(multiMediaWidget);
        layout->setMargin(0);
        ui->tabWidget->setTabText(2, "Multimedia");
    } {     //初始化状态栏
        QLabel *label = StaticLabel::label();
        ui->statusBar->addWidget(label);
        label->show();
        label->setText("Welcome, Press \"Alt + t\" to start");

        QProgressBar *bar = StaticProgressBar::progressBar();
        ui->statusBar->addWidget(bar);

        ui->statusBar->addWidget(StatuButtons::statu());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::doRequest(Componet::Name rType,
                           Operations::Type oType,
                           AbstractMessage *message) {
    if (startFlag == false)
        return;

    switch (rType) {
    case Componet::VEHICLE_MAP:
        vechicleMapWidget->handleRequest(oType, message);
        break;
    case Componet::VEHICLE_LIST:
        vechicleListWidget->handleRequest(oType, message);
        break;
    case Componet::CONVERSATION:
        conversationWidget->handleRequest(oType, message->getUserName(),
                                          ((TextMessage *)message)->getText());
        break;
    case Componet::MULTIMEDIA:
        multiMediaWidget->handleRequest(oType, message->getUserName(),
                                        ((MultiMediaMessage *)message)->getFileName(),
                                        "this is a picture");
        ui->tabWidget->setCurrentIndex(2);
        break;
    case Componet::BANDWIDTH_TEST:
    case Componet::RTT_TEST:
    case Componet::TEST_LIST:
        vanetTestWidget->handleRequest(rType, oType, message);
        break;
    default:
        break;
    }

    if (message->getUserName() != "[Me]"){
        vanetTestWidget->addNewTestWidget(message->getUserName());
    }

    //保存本地位置信息
    if (message->getMessageType() == Message::SELF_LOCATION) {
        LocationMessage *m = (LocationMessage *)message;
        LocalLocationInfomation::setLocation(m->getLatitudeNumber(),
                                             m->getLontitudeNumber(),
                                             m->getDirectNumber(),
                                             m->getSpeedNumber());
    }

}


void MainWindow::on_actionLocal_Listen_Port_triggered()
{
    SettingDialog *dialog = new SettingDialog(this);
    dialog->show();
}


void MainWindow::on_actionStart_triggered()
{
    startFlag = true;
    vechicleMapWidget->start();
    ui->actionStart->setEnabled(false);
    StaticLabel::label()->setText("Welcome");
    StatuButtons::statu()->setGraphViewStart(true);
}

void MainWindow::on_actionGraphics_View_Setting_triggered()
{
    GraphicsViewSetting *dialog = new GraphicsViewSetting(this);
    dialog->show();
}

void MainWindow::on_actionConnect_Setting_triggered()
{
    ConnectDialog *dialog = new ConnectDialog(this);
    dialog->show();
}
