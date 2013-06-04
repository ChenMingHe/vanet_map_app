#ifndef BANDWIDGETTESTWIDGET_H
#define BANDWIDGETTESTWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QTextEdit>
#include "Widget/Menu/Settings.h"
#include "testmachine.h"
#include "Widget/Label/staticlabel.h"
#include "Widget/Statu/statubuttons.h"
#include "MessageAnalyticSystem/Handlers.h"

namespace Ui {
class BandWidgetTestWidget;
}

class BandWidgetTestWidget : public QWidget
{
    Q_OBJECT  
public:
    explicit BandWidgetTestWidget(QWidget *parent = 0);
    ~BandWidgetTestWidget();

public:
    void handleRequest(Operations::Type type, int count, double value);
    void setUserName(const QString &name) {this->userName = name;}

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();

private:
    void initGraphics();
    void addNewPoint();
    void addTestResult();
    double calculateMovingAverage();
    double calculateFinalAverage();

private:
    Ui::BandWidgetTestWidget *ui;
    QGraphicsItemGroup *group;
    QGraphicsItem *pointArray[100];
    double bandWidth[100];

    QGraphicsScene *scene;
    TestMachine tm;

    QString userName;
    int count;
    double value;
};

#endif // BANDWIDGETTESTWIDGET_H
