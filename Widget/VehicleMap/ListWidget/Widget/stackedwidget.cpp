#include "stackedwidget.h"

StackedWidget::StackedWidget(QWidget *parent) :
    QStackedWidget(parent)
{
}

int StackedWidget::addWidget(const QString &name)
{
    QTextBrowser *w = new QTextBrowser(this);
    int index = QStackedWidget::addWidget(w);
    w->setParent(this);
    widgetMap.insert(name, index);
    return index;
}

void StackedWidget::updateVehicleInfo(const QString &userName, const QString &info)
{
    QMap<QString, int>::iterator itr = widgetMap.find(userName);
    if (itr == widgetMap.end())
        return;
    QTextBrowser *w = (QTextBrowser *)this->widget(itr.value());
    if (w != NULL) {
        w->setText(info);
        w->show();
    }
}

void StackedWidget::setCurrentWidget(const QString &name)
{
    QMap<QString, int>::iterator itr = widgetMap.find(name);
    if (itr == widgetMap.end())
        return;

    setCurrentIndex(itr.value());
}

void StackedWidget::hideWidget(QString name)
{
    QMap<QString, int>::iterator itr = widgetMap.find(name);
    if (itr == widgetMap.end())
        return;

    QWidget *w = this->widget(itr.value());
    w->hide();
}
