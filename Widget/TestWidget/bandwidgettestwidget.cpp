#include "bandwidgettestwidget.h"
#include "ui_bandwidgettestwidget.h"

BandWidgetTestWidget::BandWidgetTestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BandWidgetTestWidget),
    group(NULL) {
    scene = new QGraphicsScene(this);
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    ui->gridLayout_2->setMargin(0);
    ui->groupBox->layout()->setMargin(0);

    ui->graphicsView->setScene(scene);
    ui->stopButton->setEnabled(false);

    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
}

BandWidgetTestWidget::~BandWidgetTestWidget()
{
    delete ui;
}

void BandWidgetTestWidget::handleRequest(Operations::Type type, int count, double value)
{
    this->count = count;
    this->value = value;

    switch (type) {
    case Operations::UPDATE_BANDWIDTH :
        if (count < tm.getRounds() || qAbs(bandWidth[count] > 0.01))
            return;

        tm.increaseRounds();
        if (tm.getRounds() >= SettingArgument::Setting().getBWTestTimes()) {
            ui->label->setText("Test end!");
            StatuButtons::statu()->setBandWidthStart(false);
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

void BandWidgetTestWidget::addNewPoint()
{
    SettingArgument &argument = SettingArgument::Setting();
    qreal upRange = argument.getBWUpRange();
    qreal lowRange = argument.getBWLowRange();
    int testTimes = argument.getBWTestTimes();

    qreal px = (ui->graphicsView->width()-90)/(testTimes-1);
    qreal py  = (value-lowRange)*(ui->graphicsView->height()-40)/(upRange-lowRange);
    QGraphicsItem *item = scene->addEllipse(-5, -5, 10, 10, QPen(), QBrush(QColor(Qt::blue)));
    item->setPos(px*(count), -py);
    item->setGroup(group);
    pointArray[count] = item;

    //两点之间使用直线连接
    if (count != 0 &&  pointArray[count-1] != NULL) {
        QGraphicsItem *line;
        QPointF point1 = pointArray[count-1]->pos();
        QPointF point2 = pointArray[count]->pos();
        QPen pen(Qt::blue);
        pen.setWidth(3);
        line = scene->addLine(point1.x(), point1.y(), point2.x(), point2.y(), pen);
        line->setGroup(group);
    }
}

void BandWidgetTestWidget::addTestResult()
{
    SettingArgument &argument = SettingArgument::Setting();
    int testTimes = argument.getBWTestTimes();
    int interval = argument.getBWAverageInterval();

    //在table中添加返回结果
    ui->tableWidget->setCellWidget(count/10, count%10,
                                   new QTextEdit(QString::number(value) + "kb"));

    //求解显示滑动平均
    double average = calculateMovingAverage();
    if (average < 0.01)
        return;
    ui->label_everageBandwidth->setText("Moving Average " + QString::number(interval) +
                                      " : " + QString::number(average));

    if (count < testTimes-1)
        return;
    average = calculateFinalAverage();
    ui->label_everageBandwidth->setText("Total Average " + QString::number(count+1) +
                                      " : " + QString::number(average));
}

double BandWidgetTestWidget::calculateMovingAverage()
{
    bandWidth[count] = value;

    //求解滑动平均
    SettingArgument &argument = SettingArgument::Setting();
    int interval = argument.getBWAverageInterval();
    if (count+1 < interval)
        return 0.0;
    double average = 0; int i = count;
    int loop = interval;
    while (loop > 0) {
        average += bandWidth[i--];
        loop--;
    }
    average = average/interval;

    return average;
}

double BandWidgetTestWidget::calculateFinalAverage()
{
    SettingArgument &argument = SettingArgument::Setting();
    int testTimes = argument.getBWTestTimes();
    double average = 0.0;
    for (int i = testTimes-1; i >= 0; i--) {
        average += bandWidth[i];
    }
    return average/testTimes;
}


void BandWidgetTestWidget::initGraphics()
{
    // 删除所有点
    if (group != NULL) {
        delete group;
        group = NULL;
    }

    //清空所有数据
    ui->tableWidget->clear();

    //绘制坐标轴
    QList<QGraphicsItem *> items;
    {
        QGraphicsItem *line;
        line = scene->addLine(0, 0, ui->graphicsView->width() - 90, 0);
        items.push_back(line);
        line = scene->addLine(0, 0, 0, -(ui->graphicsView->height()-40));
        items.push_back(line);
    }

    SettingArgument &argument = SettingArgument::Setting();
    qreal upRange, lowRange;
    upRange = argument.getBWUpRange();
    lowRange = argument.getBWLowRange();
    int testTimes = argument.getBWTestTimes();
    //绘制x轴
    qreal px = (ui->graphicsView->width() - 90)/(testTimes - 1);
    for (int i = 0; i < testTimes; i++) {
        QGraphicsItem *line;
        line = scene->addLine(i*px, 0, i*px, -10);
        items.push_back(line);

        QGraphicsTextItem *item = scene->addText(QString::number(i+1));
        item->setPos(i*px - (item->boundingRect().width()/2), 0);
        items.push_back(item);
    }

    //绘制y轴
    qreal py = (ui->graphicsView->height()-40)/8;
    qreal interval = (upRange - lowRange)/8;
    for (int i = 0; i <= 8; i++) {
        QGraphicsItem *line;
        line = scene->addLine(0, -(py*i), 10, -(py*i));
        items.push_back(line);

        QGraphicsTextItem *item = scene->addText(QString::number(lowRange + i*interval));
        item->setPos(-(item->boundingRect().width()),
                     -(i*py + (item->boundingRect().height()/2)));
        items.push_back(item);
    }

    //绘制等高线
    for (int i = 0; i <= 8; i++) {
        QGraphicsItem *line;
        line = scene->addLine(0, -(py*i), ui->graphicsView->width() - 90, -(py*i));
        items.push_back(line);
    }

    //绘制纵轴单位
    {
        QGraphicsTextItem *item = scene->addText("kb");
        item->setPos(0, -(ui->graphicsView->height() - 25));
        items.push_back(item);
    }

    //初始化数据显示窗口
    {
        int rowCount = (testTimes-1)/10+1;
        ui->tableWidget->setRowCount(rowCount);
        ui->tableWidget->setColumnCount(10);
    }

    //创建图形组
    group = scene->createItemGroup(items);

    ui->label->setText("Wait 1st Result!");
}

void BandWidgetTestWidget::on_startButton_clicked()
{
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);

    //init argument
    for (int i = 0; i < 100; i++) {
        pointArray[i] = NULL;
        bandWidth[i] = 0.0;
    }

    //初始化图形界面环境
    this->initGraphics();

    //测试机启动
    SettingArgument &argument = SettingArgument::Setting();
    tm.initArgument(userName, "B ", argument.getBWTestTimes(),
                    1000*argument.getBWTimeInterval());
    StaticLabel::label()->setText("start BandWidth Test");
    StatuButtons::statu()->setBandWidthStart(true);
    tm.start();
}

void BandWidgetTestWidget::on_stopButton_clicked()
{
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    StaticLabel::label()->setText("stop BandWidth Test");
    StatuButtons::statu()->setBandWidthStart(false);
    tm.stop();
}
