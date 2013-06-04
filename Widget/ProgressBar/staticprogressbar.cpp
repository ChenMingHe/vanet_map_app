#include "staticprogressbar.h"

StaticProgressBar *StaticProgressBar::instance = NULL;
StaticProgressBar *StaticProgressBar::progressBar() {
    if (instance == NULL)
        instance = new StaticProgressBar;
    return instance;
}
