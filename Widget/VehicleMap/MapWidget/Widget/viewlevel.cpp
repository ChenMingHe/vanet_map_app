#include "viewlevel.h"
#include "ui_viewlevel.h"

ViewLevel::ViewLevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewLevel)
{
    ui->setupUi(this);
    viewLv1 = new LevelRadioButton(this);
    viewLv2 = new LevelRadioButton(this);
    viewLv3 = new LevelRadioButton(this);
    viewLv4 = new LevelRadioButton(this);
    viewLv5 = new LevelRadioButton(this);

    ui->horizontalLayout->addWidget(viewLv1);
    ui->horizontalLayout->addWidget(viewLv2);
    ui->horizontalLayout->addWidget(viewLv3);
    ui->horizontalLayout->addWidget(viewLv4);
    ui->horizontalLayout->addWidget(viewLv5);

    viewLv1->setLevel(0);
    viewLv2->setLevel(1);
    viewLv3->setLevel(2);
    viewLv4->setLevel(3);
    viewLv5->setLevel(4);

    viewLv1->setText("lv1");
    viewLv2->setText("lv2");
    viewLv3->setText("lv3");
    viewLv4->setText("lv4");
    viewLv5->setText("lv5");
}

ViewLevel::~ViewLevel()
{
    delete ui;
}
