#include "testwidget.h"
#include "ui_testwidget.h"

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget),
    picCount(0)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->gridLayout_2->setMargin(0);
}

TestWidget::~TestWidget()
{
    delete ui;
}


void TestWidget::on_pushButton_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s = "V 0.012 10.0006 N 11.1113 E 20.080 180.17";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_2_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s = "[T00] [100] V 0.0102 10.000 N 11.111 E 20.080 1.17";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_3_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s;
    s = "N Location Infomation Without GPS";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
    s = "[T00] [100] N Location Infomation Without GPS";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_4_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s = "[M11] [100] R 0.0102 10.0009 N 11.1107 E 20.080 1.17";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_5_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s = "[M11] [100] A Hello world ";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_6_clicked()
{
    //Test:
    QUdpSocket socket;
    picCount++;
    QString s = "[M11] [100] P ./pic/" + QString::number(picCount)+".jpg";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_7_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s = "[M11] [100] S 2 120.3";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_8_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s = "[M11] [100] B 1 110";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
    s = "[M11] [100] B 2 120.3";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_9_clicked()
{
    QTimer *timer = new QTimer;
    file = new QFile("./send");
    if (!file->open(QIODevice::ReadOnly)) {
        return;
    }

    connect(timer, SIGNAL(timeout()), this, SLOT(sendMessage()));
    timer->start(100);
}

void TestWidget::sendMessage()
{
    QByteArray bay = file->readLine(100);
    //LogDebug(0) << bay;
    sck.writeDatagram(bay, QHostAddress::LocalHost, 40000);
}

void TestWidget::sendMessage2()
{
    QByteArray bay = file2->readLine(100);
    //LogDebug(0) << bay;
    sck.writeDatagram(bay, QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_10_clicked()
{
    QTimer *timer = new QTimer;
    file2 = new QFile("./rcv");
    if (!file2->open(QIODevice::ReadOnly)) {
        return;
    }

    connect(timer, SIGNAL(timeout()), this, SLOT(sendMessage2()));
    timer->start(120);
}

void TestWidget::on_pushButton_11_clicked()
{
    //Test:
    QUdpSocket socket;
    QString s = "[T00] [100] H 2";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}

void TestWidget::on_pushButton_12_clicked()
{
    QFileDialog *dialog = new QFileDialog(this);
    dialog->show();
}

void TestWidget::on_pushButton_13_clicked()
{
    TcpSenderTestUnit *test = new TcpSenderTestUnit();
    test->test();
}

void TestWidget::on_pushButton_14_clicked()
{
    QUdpSocket socket;
    QString s = "[T00] [100] H 2";
    socket.writeDatagram(s.toAscii(), QHostAddress::LocalHost, 40000);
}
