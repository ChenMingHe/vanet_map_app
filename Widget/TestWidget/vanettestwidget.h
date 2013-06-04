#ifndef VANETTESTWIDGET_H
#define VANETTESTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QListWidgetItem>
#include "Widget/TestWidget/rtttestwidget.h"
#include "Widget/TestWidget/bandwidgettestwidget.h"
#include "MessageAnalyticSystem/Handlers.h"
#include "Manager/Manager.h"

namespace Ui {
class VanetTestWidget;
}

class VanetTestWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit VanetTestWidget(QWidget *parent = 0);
    ~VanetTestWidget();
    void handleRequest(Componet::Name rtype, Operations::Type oType, AbstractMessage *msg);
    void addNewTestWidget(const QString &name);

private:
    void setListHopIcon(const QString &userName, HopMessage::HopType type);

private:
    Ui::VanetTestWidget *ui;
    QMap<QString, QListWidgetItem *> listMap;
    Manager<QListWidgetItem> listItemManager;
    Manager<BandWidgetTestWidget> bandwidthManage;
    Manager<RttTestWidget> rttManage;
};

#endif // VANETTESTWIDGET_H
