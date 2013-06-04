#include "graphicsviewsetting.h"
#include "ui_graphicsviewsetting.h"

GraphicsViewSetting::GraphicsViewSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicsViewSetting)
{
    ui->setupUi(this);
    GraphicsSettingArgument &argument = GraphicsSettingArgument::Setting();
    ui->xPerEdit->setText(QString::number(argument.getXPerDegreed()));
    ui->yPerEdit->setText(QString::number(argument.getYPerDegreed()));
    ui->raudioEdit->setText(QString::number(argument.getWarringRaudio()));

    {
        int decpt, sign;
        char *c = ecvt(argument.getTopLat(), 10, &decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        ui->latTopEdit->setText(s);
//        free(c);
    } {
        int decpt, sign;
        char *c = ecvt(argument.getTopLon(), 10,&decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        ui->lonTopEdit->setText(s);
//        free(c);
    } {
        int decpt, sign;
        char *c = ecvt(argument.getButtomLat(), 10, &decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        ui->latBtmEdit->setText(s);
//        free(c);
    } {
        int decpt, sign;
        char *c = ecvt(argument.getButtomLon(), 10, &decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        ui->lonBtmEdit->setText(s);
//        free(c);
    }

    ui->viewLv1->setText(QString::number(argument.getViewWidth(1)));
    ui->viewLv2->setText(QString::number(argument.getViewWidth(2)));
    ui->viewLv3->setText(QString::number(argument.getViewWidth(3)));
    ui->viewLv4->setText(QString::number(argument.getViewWidth(4)));
    ui->viewLv5->setText(QString::number(argument.getViewWidth(5)));
    ui->deadTimeEdit->setText(QString::number(argument.getDeadTime()));
}

GraphicsViewSetting::~GraphicsViewSetting()
{
    delete ui;
}

void GraphicsViewSetting::on_buttonBox_accepted()
{
    GraphicsSettingArgument &argument = GraphicsSettingArgument::Setting();

    argument.setPerDegree(ui->xPerEdit->text().toInt(),
                          ui->yPerEdit->text().toInt());
    argument.setWarringRaudio(ui->raudioEdit->text().toInt());
    argument.setTopPos(stringToDouble(ui->latTopEdit->text()),
                       stringToDouble(ui->lonTopEdit->text()));
    argument.setButtomPos(stringToDouble(ui->latBtmEdit->text()),
                          stringToDouble(ui->lonBtmEdit->text()));
    argument.setViewRectWidth(ui->viewLv1->text().toInt(),
                              ui->viewLv2->text().toInt(),
                              ui->viewLv3->text().toInt(),
                              ui->viewLv4->text().toInt(),
                              ui->viewLv5->text().toInt());
    argument.setDeadTime(ui->deadTimeEdit->text().toInt());
    argument.saveSetting();
    this->close();
}

void GraphicsViewSetting::on_resetButton_clicked()
{
    ui->xPerEdit->setText("111352");
    ui->yPerEdit->setText("96453");
    ui->raudioEdit->setText("50");
    ui->latTopEdit->setText("0");
    ui->lonTopEdit->setText("0");
    ui->latBtmEdit->setText("0");
    ui->lonBtmEdit->setText("0");
    ui->viewLv1->setText("2000");
    ui->viewLv2->setText("1200");
    ui->viewLv3->setText("800");
    ui->viewLv4->setText("400");
    ui->viewLv5->setText("120");
    ui->deadTimeEdit->setText("1000");
}

qreal GraphicsViewSetting::stringToDouble(QString s)
{
    qreal result = 0.0;
    bool flag = false;
    int j = 10;
    for (int i = 0; i < s.size(); i++) {
        LogDebug(0) << s.at(i);
        if (s.at(i).toAscii() == '.') {
            flag = true;
            continue;
        }
        if (flag) {
            LogDebug(0) << ((double)(s.at(i).toAscii() - '0')) / j;
            result += ((double)(s.at(i).toAscii() - '0')) / j;
            j *= 10;
        } else {
            LogDebug(0) << (s.at(i).toAscii() - '0');
            result = (result * 10) + (s.at(i).toAscii() - '0');
        }
    }
    return result;
}

