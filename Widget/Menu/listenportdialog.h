#ifndef LISTENPORTDIALOG_H
#define LISTENPORTDIALOG_H


//�Ѿ���̭������

#include <QDialog>

namespace Ui {
class ListenPortDialog;
}

class ListenPortDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ListenPortDialog(QWidget *parent = 0);
    ~ListenPortDialog();
    
private:
    Ui::ListenPortDialog *ui;
};

#endif // LISTENPORTDIALOG_H
