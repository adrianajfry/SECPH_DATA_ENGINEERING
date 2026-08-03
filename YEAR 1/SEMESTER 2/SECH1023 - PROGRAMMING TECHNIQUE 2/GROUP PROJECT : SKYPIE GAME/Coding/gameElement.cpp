#include "GameElement.h"

GameElement::GameElement(int x, int y) : position(x, y) {}

std::pair<int, int> GameElement::getPosition() const {
    return position;
}

void GameElement::setPosition(int x, int y) {
    position = std::make_pair(x, y);
}