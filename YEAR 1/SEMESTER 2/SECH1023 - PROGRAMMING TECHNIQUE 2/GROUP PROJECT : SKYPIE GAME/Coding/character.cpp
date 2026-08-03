#include "Character.h"
#include <graphics.h>

Character::Character(int startX, int startY) : x(startX), y(startY), visible(true) {}

void Character::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void Character::setVisible(bool isVisible) {
    visible = isVisible;
}

bool Character::isVisible() const {
    return visible;
}

void Character::draw() const {
    if (visible) {
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(x, y, 20, 30); // Draw an oval with radius 20x30
    }
}
