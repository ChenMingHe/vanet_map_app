#ifndef RTTTESTWIDGET_H
#define RTTTESTWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QTextEdit>
#include <QGraphicsItemGroup>
#include "Widget/Menu/Settings.h"
#include "testmachine.h"
#include "Widget/Label/staticlabel.h"
#include "Widget/Statu/statubuttons.h"
#include "MessageAnalyticSystem/Handlers.h"

namespace Ui {
class RttTestWidget;
}

class RttTestWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit RttTestWidget(QWidget *parent = 0);
    ~RttTestWidget();
    void setUserName(const QString userName) {this->userName = userName;}
    void handleRequest(Operations::Type type, int count, double value);

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
    Ui::RttTestWidget *ui;
    QGraphicsItemGroup *group;
    QGraphicsItem *pointArray[100];
    double rttTime[100];

    QGraphicsScene *scene;
    TestMachine tm;

    QString userName;
    int count;
    double value;
};

#endif // RTTTESTWIDGET_H
