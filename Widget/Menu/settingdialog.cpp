#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    SettingArgument &argument = SettingArgument::Setting();

    //init network
    ui->udpPort->setText(QString::number(argument.getUdpPort()));
    ui->tcpPort->setText(QString::number(argument.getTcpPort()));

    //init bw test
    ui->bwTestTimes->setCurrentIndex(argument.getBWTestTimes()/2-1);
    ui->bwTimeInterval->setCurrentIndex(argument.getBWTimeInterval()-2);
    ui->bwLowRange->setText(QString::number(argument.getBWLowRange()));
    ui->bwUpRange->setText(QString::number(argument.getBWUpRange()));
    setBWAverageIntervalMax();
    ui->bwAverageInterval->setCurrentIndex(argument.getBWAverageInterval()-2);

    //init rtt test
    ui->rttTestTime->setCurrentIndex(argument.getRttTestTimes()/5-1);
    ui->rttTimeInterval->setCurrentIndex(argument.getRttTimeInterval()/300-1);
    ui->rttLowRange->setText(QString::number(argument.getRttLowRange()));
    ui->rttUpRange->setText(QString::number(argument.getRttUpRange()));
    setRTTAverageIntervalMax();
    ui->rttAverageInterval->setCurrentIndex(argument.getRttAverageInterval()-2);

    ui->warringRadius->setText(QString::number(argument.getWarringInterval()));


    connect(ui->bwTestTimes, SIGNAL(currentIndexChanged(int)),
            this, SLOT(setBWAverageIntervalMax()));
    connect(ui->rttTestTime, SIGNAL(currentIndexChanged(int)),
            this, SLOT(setRTTAverageIntervalMax()));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::on_buttonBox_accepted()
{
    SettingArgument &argument = SettingArgument::Setting();
    argument.setUdpPort(ui->udpPort->text().toInt());
    argument.setTcpPort(ui->tcpPort->text().toInt());

    argument.setBWTestTimes(ui->bwTestTimes->currentText().toInt());
    argument.setBWTimeInterval(ui->bwTimeInterval->currentText().toInt());
    argument.setBWLowRange(ui->bwLowRange->text().toInt());
    argument.setBWUpRange(ui->bwUpRange->text().toInt());
    argument.setBWAverageInterval(ui->bwAverageInterval->currentText().toInt());

    argument.setRttTestTimes(ui->rttTestTime->currentText().toInt());
    argument.setRttTimeInterval(ui->rttTimeInterval->currentText().toInt());
    argument.setRttLowRange(ui->rttLowRange->text().toInt());
    argument.setRttUpRange(ui->rttUpRange->text().toInt());
    argument.setRttAverageInterval(ui->rttAverageInterval->currentText().toInt());

    argument.setWarringTimeInterval(ui->warringRadius->text().toInt());
    argument.saveSetting();
    this->close();
}

void SettingDialog::setBWAverageIntervalMax()
{
    ui->bwAverageInterval->clear();
    int max = ui->bwTestTimes->currentText().toInt();
    for (int i = 2; i <= max; i++) {
        ui->bwAverageInterval->addItem(QString::number(i));
    }
}

void SettingDialog::setRTTAverageIntervalMax()
{
    ui->rttAverageInterval->clear();
    int max = ui->rttTestTime->currentText().toInt();
    for (int i = 2; i <= max; i++) {
        ui->rttAverageInterval->addItem(QString::number(i));
    }
}
