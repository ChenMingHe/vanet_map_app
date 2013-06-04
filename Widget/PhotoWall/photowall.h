#ifndef PHOTOWALL_H
#define PHOTOWALL_H

#include <QWidget>
#include <QResizeEvent>
#include <QSize>
#include <QPainter>
#include <QDialog>
#include <QPalette>
#include "LogSystem/logwriter.h"

namespace Ui {
class PhotoWall;
}

class Photo : public QWidget
{
    Q_OBJECT
    
public:
    explicit Photo(QWidget *parent = 0);
    ~Photo();
    void addPhoto(const QString &fileName, int w, int h);
    void addTitle(const QString &title);
    void addDescription(const QString &text);


private slots:
    void on_openButton_clicked();

private:
    Ui::PhotoWall *ui;
    QString fileName;
};

#endif // PHOTOWALL_H
