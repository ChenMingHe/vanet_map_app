#ifndef VIEWLEVEL_H
#define VIEWLEVEL_H

#include <QWidget>
#include "levelradiobutton.h"


namespace Ui {
class ViewLevel;
}

class ViewLevel : public QWidget
{
    Q_OBJECT
    
public:
    explicit ViewLevel(QWidget *parent = 0);
    ~ViewLevel();
    
private:
    Ui::ViewLevel *ui;
    LevelRadioButton *viewLv1, *viewLv2;
    LevelRadioButton *viewLv3, *viewLv4;
    LevelRadioButton *viewLv5;
};

#endif // VIEWLEVEL_H
