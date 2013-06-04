#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widget/ConversationDialog/conversationwidget.h"
#include "Widget/testwidget.h"
#include "Widget/VehicleMap/ListWidget/vechiclelistwidget.h"
#include "Widget/VehicleMap/MapWidget/vechiclemapwidget.h"
#include "Widget/TestWidget/vanettestwidget.h"
#include "Widget/MultiMediaWidget/mudiamediawidget.h"
#include "Widget/Warring/warringwidget.h"
#include "Widget/Menu/connectdialog.h"
#include "Widget/Menu/settingdialog.h"
#include "Widget/Menu/settingargument.h"
#include "Widget/Menu/graphicsviewsetting.h"
#include "Widget/Label/staticlabel.h"
#include "Widget/ProgressBar/staticprogressbar.h"
#include "Widget/Statu/statubuttons.h"
#include "Widget/VehicleMap/ListWidget/vehiclelist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void doRequest(Componet::Name rType,
                   Operations::Type oType,
                   AbstractMessage* message);

private slots:
    void on_actionLocal_Listen_Port_triggered();
    void on_actionStart_triggered();
    void on_actionGraphics_View_Setting_triggered();
    void on_actionConnect_Setting_triggered();

private:
    Ui::MainWindow *ui;
    ConversationWidget *conversationWidget;
    TestWidget *testWidget;
//    VechicleListWidget *vechicleListWidget;
    VehicleList *vechicleListWidget;
    VechicleMapWidget *vechicleMapWidget;
    VanetTestWidget *vanetTestWidget;
    MudiamediaWidget *multiMediaWidget;
    WarringWidget *warringWidget;
    bool startFlag;
};

#endif // MAINWINDOW_H
