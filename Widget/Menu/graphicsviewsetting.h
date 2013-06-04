#ifndef GRAPHICSVIEWSETTING_H
#define GRAPHICSVIEWSETTING_H

#include <QDialog>
#include <stdlib.h>
#include <stdio.h>
#include "graphicssettingargumeng.h"
#include "LogSystem/logwriter.h"


namespace Ui {
class GraphicsViewSetting;
}

class GraphicsViewSetting : public QDialog
{
    Q_OBJECT
    
public:
    explicit GraphicsViewSetting(QWidget *parent = 0);
    ~GraphicsViewSetting();
    
private slots:
    void on_buttonBox_accepted();
    void on_resetButton_clicked();

private:
    qreal stringToDouble(QString s);
private:
    Ui::GraphicsViewSetting *ui;
};

#endif // GRAPHICSVIEWSETTING_H
