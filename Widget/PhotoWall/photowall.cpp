#include "photowall.h"
#include "ui_photowall.h"

Photo::Photo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhotoWall)
{
    ui->setupUi(this);
    ui->openButton->setFlat(true);
}

Photo::~Photo()
{
    delete ui;
}

void Photo::addPhoto(const QString &fileName, int w, int h)
{
    this->fileName = fileName;
    LogDebug(0) << fileName;
    if (!QFile::exists(fileName)) {
        qDebug("can not find file");
        return;
    }
    LogDebug("ready to open file");
    ui->openButton->setIcon(QIcon(QPixmap(fileName)));
    ui->openButton->setIconSize(QSize(w, h));
    ui->openButton->show();
}

void Photo::addTitle(const QString &title)
{
    ui->groupBox->setTitle(title);
}

void Photo::addDescription(const QString &text)
{
    ui->label->setText(text);
}


void Photo::on_openButton_clicked()
{
    QDialog *dialog = new QDialog(this);
    QPixmap p(fileName);
    dialog->resize(p.size());
    QPalette palettle;
    palettle.setBrush(dialog->backgroundRole(), QBrush(p));
    dialog->setPalette(palettle);
    dialog->setAutoFillBackground(true);
    dialog->show();

    QGridLayout *gridLayout = new QGridLayout(dialog);
    gridLayout->setMargin(0);
}
