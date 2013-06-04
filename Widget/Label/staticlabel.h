#ifndef STATICLABEL_H
#define STATICLABEL_H

#include <QLabel>

class StaticLabel : public QLabel
{
    Q_OBJECT
public:
    static StaticLabel *label();

private:
    static StaticLabel *instance;
    StaticLabel();
};

#endif // STATICLABEL_H
