#ifndef TWINKLEICON_H
#define TWINKLEICON_H

#include <QGraphicsItemGroup>

class TwinkleIcon : public QObject
{
    Q_OBJECT
public:
    TwinkleIcon();
    void setGroup(QGraphicsItemGroup *group) {this->group = group;}
    void setItem(QGraphicsItem *item) {this->item = item;}

public slots:
    void twinkle();
    void hideIcon();

private:
    QGraphicsItemGroup *group;
    QGraphicsItem *item;
    bool isShow;
};

#endif // TWINKLEICON_H
