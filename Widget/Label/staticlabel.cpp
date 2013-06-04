#include "staticlabel.h"

StaticLabel *StaticLabel::instance = NULL;
StaticLabel::StaticLabel() {
}


StaticLabel *StaticLabel::label()
{
    if (instance == NULL)
        instance = new StaticLabel();
    return instance;
}
