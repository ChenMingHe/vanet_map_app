#ifndef CONVERSATIONWIDGET_H
#define CONVERSATIONWIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QFileDialog>
#include "Infomation/locallocationinfomation.h"
#include "MessageAnalyticSystem/Handlers.h"
#include "Socket/Sockets.h"

namespace Ui {
class ConversationWidget;
}

class ConversationWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ConversationWidget(QWidget *parent = 0);
    ~ConversationWidget();
    void handleRequest(Operations::Type type,
                       const QString &userName,
                       const QString &text);

public slots:
    void talkToUser(QString name);

private slots:
    void on_fileSelectButton_clicked();
    void on_sendButton_clicked();
    void clearTextEdit();

private:
    Ui::ConversationWidget *ui;
    QString talkTo;
};

#endif // CONVERSATIONWIDGET_H
