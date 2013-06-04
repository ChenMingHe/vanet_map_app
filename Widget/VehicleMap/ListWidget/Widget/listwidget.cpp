#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent) :
    QListWidget(parent)
{
}

QString ListWidget::getItemFromIndex(const QModelIndex &index) const
{
    return QListWidget::itemFromIndex(index)->text();
}

bool ListWidget::hasUser(const QString &name)
{
    QList<QListWidgetItem *> list = this->findItems(name, Qt::MatchFixedString);
    if (list.size() > 0)
        return true;
    else
        return false;
}

void ListWidget::removeItem(const QString &name)
{
    QList<QListWidgetItem *> list = this->findItems(name, Qt::MatchExactly);
    foreach (QListWidgetItem *i, list) {
        i->setHidden(true);
    }
}

void ListWidget::setIconHop(const QString &userName, HopMessage::HopType type)
{
    QList<QListWidgetItem *> list = this->findItems(userName, Qt::MatchFixedString);
    foreach (QListWidgetItem *i, list) {
        switch (type) {
        case HopMessage::SingleHop:
            i->setIcon(QIcon("./icon/single.png"));
            break;
        case HopMessage::MultiHop:
            i->setIcon(QIcon("./icon/multi.png"));
            break;
        default:break;
        }
        i->setHidden(false);
    }
}

void ListWidget::setItemColor(const QString &userName, Type type)
{
    QList<QListWidgetItem *> list = this->findItems(userName, Qt::MatchFixedString);
    foreach (QListWidgetItem *i, list) {
        switch(type) {
        case Message::NOLOCATION:
            i->setBackground(QBrush(QColor(Qt::blue)));
            break;
        case Message::DANGER:
            i->setBackground(QBrush(QColor(Qt::red)));
            break;
        case Message::DISTANCE_LOCATION:
            i->setBackground(QBrush(QColor(Qt::yellow)));
            break;
        case Message::SELF_LOCATION:
            i->setBackground(QBrush(QColor(Qt::green)));
            break;
        case Message::EMERGENCY_VEHICLE:
            i->setBackground(QBrush(QColor(Qt::cyan)));
            break;
        case Message::WARRING:
            i->setBackground(QBrush(QColor(Qt::magenta)));
            break;
        default:break;
        }
        i->setHidden(false);
    }
}
