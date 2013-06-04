#include "rtttestwidget.h"
#include "ui_rtttestwidget.h"


RttTestWidget::RttTestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RttTestWidget),
    group(NULL), count(0)
{
    scene = new QGraphicsScene(this);
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->gridLayout_2->setMargin(0);
    ui->stopButton->setEnabled(false);
    ui->graphicsView->setScene(scene);

    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
}

RttTestWidget::~RttTestWidget()
{
    delete ui;
}

void RttTestWidget::handleRequest(Operations::Type type, int count, double value)
{
    this->count = count;
    this->value = value;

    switch (type) {
    case Operations::UPDATE_RTT:
        if (count < tm.getRounds() || qAbs(rttTime[count]) > 0.01)
            return;

        tm.increaseRounds();
        if (count >= SettingArgument::Setting().getRttTestTimes()-1) {
            ui->label->setText("Test end!");
            StatuButtons::statu()->setRttTestStart(false);
        }
        else {
            ui->label->setText("Wait " + QString::number(tm.getRounds()+1) + "'s Result!");
        }

        addNewPoint();
        addTestResult();
        break;
    default:
        break;
    }
}

void RttTestWidget::addNewPoint()
{
    SettingArgument &argument = SettingArgument::Setting();
    qreal upRange = argument.getRttUpRange();
    qreal lowRange = argument.getRttLowRange();
    int testTimes = argument.getRttTestTimes();

    qreal px = (ui->graphicsView->width() - 90) / (testTimes - 1);
    qreal py = (value-lowRange)*(ui->graphicsView->height()-40)/(upRange-lowRange);
    QGraphicsItem *item = scene->addEllipse(-5, -5, 10, 10, QPen(), QBrush(QColor(Qt::blue)));
    item->setPos(px*count, -py);
    item->setGroup(group);
    pointArray[count] = item;

    if (count != 0 && pointArray[count-1] != NULL) {
        QGraphicsItem *line;
        QPointF point1 = pointArray[count-1]->pos();
        QPointF point2 = pointArray[count]->pos();
        QPen pen(Qt::blue);
        pen.setWidth(3);
        line = scene->addLine(point1.x(), point1.y(), point2.x(), point2.y(), pen);
        line->setGroup(group);
    }
}

void RttTestWidget::addTestResult()
{
    SettingArgument &argument = SettingArgument::Setting();
    int testTimes = argument.getRttTestTimes();
    int interval = argument.getRttAverageInterval();

    ui->tableWidget->setCellWidget(count/10, count%10,
                                   new QTextEdit(QString::number(value) + " ms"));

    //计算滑动平均
    double average = calculateMovingAverage();
    LogDebug(0) << "Moving Average : " << average;
    ui->label_averageRttTime->setText("Moving Average " + QString::number(interval) +
                                      " : " + QString::number(average));

    if (count < testTimes-1)
        return;
    average = calculateFinalAverage();
    ui->label_averageRttTime->setText("Total Average " + QString::number(count+1) +
                                      " : " + QString::number(average));
}

double RttTestWidget::calculateMovingAverage()
{
    rttTime[count] = value;

    SettingArgument &argument = SettingArgument::Setting();
    int interval = argument.getRttAverageInterval();
    if (count+1 < interval)
        return 0.0;

    double average = 0;int i = count; int loop = interval;
    while (loop > 0) {
        average += rttTime[i--];
        loop--;
    }

    return average/interval;
}

double RttTestWidget::calculateFinalAverage()
{
    SettingArgument &argument = SettingArgument::Setting();
    int testTimes = argument.getRttTestTimes();
    double average = 0;
    for (int i = testTimes-1; i >= 0; i--) {
        average += rttTime[i];
    }
    return average/testTimes;
}


void RttTestWidget::initGraphics()
{
    if (group != NULL) {
        delete group;
        group = NULL;
    }

    ui->tableWidget->clear();

    //绘制坐标轴
    QList<QGraphicsItem *> items;
    {
        QGraphicsItem *line;
        line = scene->addLine(0, 0, ui->graphicsView->width() - 90, 0);
        items.push_back(line);
        line = scene->addLine(0, 0, 0, -(ui->graphicsView->height()- 40));
        items.push_back(line);
    }

    SettingArgument &argument = SettingArgument::Setting();
    qreal upRange, lowRange;
    upRange = argument.getRttUpRange();
    lowRange = argument.getRttLowRange();
    int testTimes = argument.getRttTestTimes();
    qreal px = (ui->graphicsView->width() - 90)/(testTimes - 1);
    for (int i = 0; i < testTimes; i++) {
        QGraphicsItem *line;
        line = scene->addLine(i*px, 0, i*px, -10);
        items.push_back(line);

        QGraphicsTextItem *item = scene->addText(QString::number(i+1));
        item->setPos(i*px - (item->boundingRect().width()/2), 0);
        items.push_back(item);
    }

    qreal py = (ui->graphicsView->height() - 40)/8;
    qreal interval = (upRange - lowRange)/8;
    for (int i = 0; i <= 8; i++) {
        QGraphicsItem *line;
        line = scene->addLine(0, -(py*i), 10, -(py*i));
        items.push_back(line);

        QGraphicsTextItem *item = scene->addText(QString::number(i*interval + lowRange));
        item->setPos(-(item->boundingRect().width()),
                     -(i*py + (item->boundingRect().height()/2)));
        items.push_back(item);
    }

    for (int i = 0; i <= 8; i++) {
        QGraphicsItem *line;
        line = scene->addLine(0, -(py*i), ui->graphicsView->width() - 90, -(py*i));
        items.push_back(line);
    }

    {
        QGraphicsTextItem *item = scene->addText("ms");
        item->setPos(0, -(ui->graphicsView->height() - 25));
        items.push_back(item);
    }

    {
        int rowCount = (testTimes - 1)/10 + 1;
        ui->tableWidget->setRowCount(rowCount);
        ui->tableWidget->setColumnCount(10);
    }

    group = scene->createItemGroup(items);
}

void RttTestWidget::on_startButton_clicked()
{
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);

    for (int i = 0; i < 100; i++) {
        pointArray[i] = NULL;
        rttTime[i] = 0.0;
    }

    this->initGraphics();
    SettingArgument &argument = SettingArgument::Setting();
    tm.initArgument(userName, "S ", argument.getRttTestTimes(),
                    argument.getRttTimeInterval());
    StaticLabel::label()->setText("start RTT Test");
    StatuButtons::statu()->setRttTestStart(true);
    tm.start();
}

void RttTestWidget::on_stopButton_clicked()
{
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    StaticLabel::label()->setText("stop RTT Test");
    StatuButtons::statu()->setRttTestStart(false);
    tm.stop();
}
