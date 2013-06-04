#ifndef STATICPROGRESSBAR_H
#define STATICPROGRESSBAR_H

#include <QProgressBar>

class StaticProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    static StaticProgressBar *progressBar();

private:
    static StaticProgressBar *instance;
    StaticProgressBar() {}
};

#endif // STATICPROGRESSBAR_H
