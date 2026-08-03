#include "Cookie.h"
#include <graphics.h>

void Cookie::draw() const {
    setcolor(YELLOW);  // Change color to blue
    setfillstyle(SOLID_FILL, YELLOW);  // Change fill color to blue
    fillellipse(position.first, position.second, 10, 10); // Draw a circle with radius 10
}
