#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include "LogSystem/logwriter.h"
#include "Test/tcpsendertestunit.h"

namespace Ui {
class TestWidget;
}

class TestWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit TestWidget(QWidget *parent = 0);
    ~TestWidget();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void sendMessage();
    void sendMessage2();
    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::TestWidget *ui;
    QFile *file;
    QFile *file2;
    QUdpSocket sck;
    int picCount;
};

#endif // TESTWIDGET_H
