#include "connectdialog.h"
#include "ui_connectdialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    ConnecttionArgument &argument = ConnecttionArgument::Setting();
    ui->hostEdit->setText(argument.getHost().toString());
    ui->portEdit->setText(QString::number(argument.getUDPPort()));
    ui->tcpPortEdit->setText(QString::number(argument.getTCPPort()));
    ui->userNameEdit->setText(argument.getLocalUserName());
}


ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::on_buttonBox_accepted()
{
    ConnecttionArgument &argument = ConnecttionArgument::Setting();

    argument.setHost(ui->hostEdit->text());
    argument.setUDPPort(ui->portEdit->text());
    argument.setTCPPort(ui->tcpPortEdit->text());
    argument.setLocalUserName(ui->userNameEdit->text());
    argument.saveSetting();
    this->close();
}
