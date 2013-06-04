#include "levelradiobutton.h"

LevelRadioButton::LevelRadioButton(QWidget *parent) :
    QRadioButton(parent), level(0)
{
    connect(this, SIGNAL(toggled(bool)), this, SLOT(initArgument(bool)));
}


void LevelRadioButton::setLevel(int lv)
{
    this->level = lv;
}

void LevelRadioButton::initViewText()
{
    GraphicsArgument &argument = GraphicsArgument::argument();
    setText(QString::number(argument.getViewWidth()) +
            " * " + QString::number(argument.getViewHight()));
}

void LevelRadioButton::initArgument(bool check)
{
    if (!check)
        return;

    GraphicsArgument &argument = GraphicsArgument::argument();
    GraphicsSettingArgument &setting = GraphicsSettingArgument::Setting();

    argument.setPerDegreed(setting.getXPerDegreed(), setting.getYPerDegreed());
    argument.setMapArgument(setting.getTopLat(), setting.getTopLon(),
                            setting.getButtomLat(), setting.getButtomLon());
    argument.setDeadTime(setting.getDeadTime());
    argument.setWarringRadius(setting.getWarringRaudio());
    argument.setViewRect(setting.getViewWidth(level), 0);
}
