#include "FloatingGround.h"
#include <graphics.h>

void FloatingGround::draw() const {
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    bar(position.first - 50, position.second - 10, position.first + 50, position.second + 10); // Increase the width to 100 pixels
}
