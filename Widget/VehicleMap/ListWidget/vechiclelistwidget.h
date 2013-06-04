#ifndef VECHICLELISTWIDGET_H
#define VECHICLELISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QMap>
#include <QIcon>
#include <QTextBrowser>
#include <QTimer>
#include "Manager/Manager.h"
#include "MessageAnalyticSystem/Handlers.h"


namespace Ui {
class VechicleListWidget;
}

class VechicleListWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit VechicleListWidget(QWidget *parent = 0);
    ~VechicleListWidget();
    void handleRequest(Operations::Type type, AbstractMessage *msg);

signals:
    void currentTextChange(QString);


private:
    Ui::VechicleListWidget *ui;
    Manager<QTextBrowser> vehicleManage;
    Manager<QListWidgetItem> listManage;

private:
    void updateBrowser(const QString &userName,
                       const QString &lat,
                       const QString &lon,
                       const QString &speed,
                       const QString &direct,
                       const QString &license);
    void addNewUser(const QString &name);
    void setIconHop(const QString &userName, HopMessage::HopType type);
    void setItemColor(const QString &userName, Message::Type type);
};

#endif // VECHICLELISTWIDGET_H
