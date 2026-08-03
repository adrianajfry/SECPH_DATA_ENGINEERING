#include "Cloud.h"
#include <graphics.h>

void Cloud::draw() const {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    // Drawing the cloud using multiple overlapping circles
    fillellipse(position.first - 20, position.second, 20, 20);
    fillellipse(position.first, position.second - 10, 30, 30);
    fillellipse(position.first + 30, position.second, 20, 20);
    fillellipse(position.first + 15, position.second + 10, 20, 20);
}