#include "listenportdialog.h"
#include "ui_listenportdialog.h"

ListenPortDialog::ListenPortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListenPortDialog)
{
    ui->setupUi(this);
}

ListenPortDialog::~ListenPortDialog()
{
    delete ui;
}
