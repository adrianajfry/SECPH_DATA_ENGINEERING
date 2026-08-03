#include <graphics.h>
#include<cmath>

#include "circle.hpp"

Circle::Circle(int _x, int _y, int _radius): Shape(_x,_y), radius(_radius) {}

int Circle::getRadius() const {
    return radius;
}

void Circle::draw() {
    circle(x, y, radius);
}

void Circle::resize(int amount) {
    radius += amount;
}