#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QStackedWidget>
#include <QMap>
#include <QTextBrowser>
#include "LogSystem/logwriter.h"

class StackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit StackedWidget(QWidget *parent = 0);
    virtual ~StackedWidget() {}

    int addWidget(const QString &name);
    void updateVehicleInfo(const QString &userName, const QString &info);
signals:
    
public slots:
    void setCurrentWidget(const QString &name);
    void hideWidget(QString name);

private:
    QMap<QString, int> widgetMap;
    
};

#endif // STACKEDWIDGET_H
