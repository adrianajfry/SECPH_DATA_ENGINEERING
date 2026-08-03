#include <graphics.h>
#include "shape.hpp"

Shape::Shape(int _x, int _y) : x(_x), y(_y), selected(false) {}

void Shape::setLocation(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Shape::setSelected(bool _selected) {
	selected = _selected;
}

int Shape::getX() const {
	return x;
}

int Shape::getY() const {
	return y;
}

bool Shape::isSelected() const {
	return selected;
}