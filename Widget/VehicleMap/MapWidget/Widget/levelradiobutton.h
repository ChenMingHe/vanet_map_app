#ifndef LEVELRADIOBUTTON_H
#define LEVELRADIOBUTTON_H

#include <QRadioButton>
#include "Widget/Menu/graphicsviewsetting.h"
#include "Widget/VehicleMap/MapWidget/GraphicsArgument.h"

class LevelRadioButton : public QRadioButton
{
public:
    explicit LevelRadioButton(QWidget *parent = 0);
    virtual ~LevelRadioButton() {}

    void setLevel(int lv);
    void initViewText();

public slots:
    void initArgument(bool check);

private:
    int level;
};

#endif // LEVELRADIOBUTTON_H
