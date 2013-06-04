#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include "Manager/Manager.h"
#include "MessageAnalyticSystem/Handlers.h"
#include "LogSystem/logwriter.h"


class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = 0);
    QString getItemFromIndex(const QModelIndex &index) const;

    bool hasUser(const QString &name);

signals:
    
public slots:
    void removeItem(const QString &name);
    void setIconHop(const QString &userName, HopMessage::HopType type);
    void setItemColor(const QString &userName, Message::Type type);
};

#endif // LISTWIDGET_H
