#include "mudiamediawidget.h"
#include "ui_mudiamediawidget.h"

MudiamediaWidget::MudiamediaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MudiamediaWidget),
    rowCount(0), cloumCount(0),
    userName(""), fileName(""),
    description("")
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
}

MudiamediaWidget::~MudiamediaWidget()
{
    delete ui;
}

void MudiamediaWidget::handleRequest(Operations::Type type,
                                     const QString &userName,
                                     const QString &fileName,
                                     const QString &description)
{
    if (type == Operations::ADD_PICTURE) {
        this->userName = userName;
        this->fileName = fileName;
        this->description = description;
        addPicture();
    }
}


void MudiamediaWidget::addPicture()
{
    Photo *p = new Photo(this);
    p->addPhoto(fileName, this->width()/4, this->height()/4);
    p->addTitle(userName);
    p->addDescription(description);
    p->setAutoFillBackground(false);
    p->resize(this->width()/4, this->height()/3);
    if (cloumCount > 3) {
        rowCount++;
        cloumCount = 0;
    }
    ui->gridLayout->addWidget(p, rowCount, cloumCount++);
}

