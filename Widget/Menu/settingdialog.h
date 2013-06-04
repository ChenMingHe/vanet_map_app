#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include "LogSystem/logwriter.h"
#include "settingargument.h"


namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();
    
private slots:
    void on_buttonBox_accepted();
    void setBWAverageIntervalMax();
    void setRTTAverageIntervalMax();

private:
    Ui::SettingDialog *ui;
};

#endif // SETTINGDIALOG_H
