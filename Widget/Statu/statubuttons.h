#ifndef STATUBUTTONS_H
#define STATUBUTTONS_H

#include <QWidget>

namespace Ui {
class StatuButtons;
}

class StatuButtons : public QWidget
{
    Q_OBJECT    
public:
    ~StatuButtons();
    static StatuButtons *statu();
    void setGraphViewStart(bool b);
    void setRttTestStart(bool b);
    void setBandWidthStart(bool b);
    void setWarringState(bool b);
    void setEmergencyState(bool b);
    
private:
    Ui::StatuButtons *ui;
    static StatuButtons *instance;
    explicit StatuButtons(QWidget *parent = 0);
};

#endif // STATUBUTTONS_H
