#ifndef VEHICLEINFOBROWSER_H
#define VEHICLEINFOBROWSER_H

#include <QWidget>

namespace Ui {
class VehicleInfoBrowser;
}

class VehicleInfoBrowser : public QWidget
{
    Q_OBJECT
    
public:
    explicit VehicleInfoBrowser(QWidget *parent = 0);
    virtual ~VehicleInfoBrowser();
    void setTextBrowserText(const QString &text);
    
private:
    Ui::VehicleInfoBrowser *ui;
};

#endif // VEHICLEINFOWIDGET_H
