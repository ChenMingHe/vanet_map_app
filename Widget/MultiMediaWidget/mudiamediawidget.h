#ifndef MUDIAMEDIAWIDGET_H
#define MUDIAMEDIAWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGroupBox>
#include <QLabel>
#include <QWidget>
#include "Widget/PhotoWall/photowall.h"
#include "MessageAnalyticSystem/Handlers.h"

namespace Ui {
class MudiamediaWidget;
}

class MudiamediaWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MudiamediaWidget(QWidget *parent = 0);
    ~MudiamediaWidget();
    void handleRequest(Operations::Type type,
                       const QString &userName,
                       const QString &fileName,
                       const QString &description = "");
    
private:
    void addPicture();

private:
    Ui::MudiamediaWidget *ui;
    int rowCount, cloumCount;

    //±ØÐë²ÎÊý
    QString userName;
    QString fileName;
    QString description;
};

#endif // MUDIAMEDIAWIDGET_H
