#ifndef VEHICLETYPEMENU_H
#define VEHICLETYPEMENU_H

#include <QWidget>

namespace Ui {
class VehicleTypeMenu;
}

class VehicleTypeMenu : public QWidget
{
    Q_OBJECT
    
public:
    explicit VehicleTypeMenu(QWidget *parent = 0);
    ~VehicleTypeMenu();
    
private:
    Ui::VehicleTypeMenu *ui;
};

#endif // VEHICLETYPEMENU_H
