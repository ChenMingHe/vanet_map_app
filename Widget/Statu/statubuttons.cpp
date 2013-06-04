#include "statubuttons.h"
#include "ui_statubuttons.h"

StatuButtons::StatuButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatuButtons)
{
    ui->setupUi(this);
    ui->graphView->setEnabled(false);
    ui->rttTest->setEnabled(false);
    ui->bandWidthTest->setEnabled(false);
    ui->warring->setEnabled(false);
    ui->emergency->setEnabled(false);
}

StatuButtons::~StatuButtons()
{
    delete ui;
}

StatuButtons *StatuButtons::instance = NULL;
StatuButtons *StatuButtons::statu()
{
    if (instance == NULL)
        instance = new StatuButtons;
    return instance;
}

void StatuButtons::setGraphViewStart(bool b)
{
    ui->graphView->setChecked(b);
}

void StatuButtons::setRttTestStart(bool b)
{
    ui->rttTest->setChecked(b);
}

void StatuButtons::setBandWidthStart(bool b)
{
    ui->bandWidthTest->setChecked(b);
}

void StatuButtons::setWarringState(bool b)
{
    ui->warring->setChecked(b);
}

void StatuButtons::setEmergencyState(bool b)
{
    ui->emergency->setChecked(b);
}
