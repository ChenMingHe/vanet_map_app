#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QHostAddress>
#include "LogSystem/logwriter.h"
#include "connecttionargument.h"

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConnectDialog *ui;
};

#endif // CONNECTDIALOG_H
