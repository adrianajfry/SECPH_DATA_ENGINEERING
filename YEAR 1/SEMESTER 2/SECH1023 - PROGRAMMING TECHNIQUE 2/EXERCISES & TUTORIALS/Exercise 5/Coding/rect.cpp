#include <graphics.h>

#include "shape.hpp"
#include "rect.hpp"

Rect::Rect(int _x, int _y, int _width, int _height) : Shape(_x, _y), width(_width), height(_height) {}

int Rect::getWidth() const {
    return width;
}

int Rect::getHeight() const {
    return height;
}

void Rect::draw() {
    rectangle(x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}

void Rect::resize(int amount) {
    width += amount;
    height += amount;
}
