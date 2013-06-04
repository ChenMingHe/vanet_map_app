#include "twinkleicon.h"

TwinkleIcon::TwinkleIcon() :
    isShow(true)
{
}

void TwinkleIcon::twinkle()
{
    if (isShow == true) {
        item->hide();
        isShow = false;
    } else {
        item->show();
        isShow = true;
    }

}

void TwinkleIcon::hideIcon()
{
    group->hide();
}
