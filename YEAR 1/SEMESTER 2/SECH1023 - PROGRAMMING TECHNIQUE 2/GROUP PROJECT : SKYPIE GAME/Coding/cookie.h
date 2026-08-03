#ifndef COOKIE_H
#define COOKIE_H

#include "GameElement.h"

class Cookie : public GameElement {
public:
    Cookie(int x, int y) : GameElement(x, y), drawnOnGround(false) {}

    void interact() override {}
    void draw() const override;

    bool drawnOnGround; // Added member variable
};

#endif // COOKIE_H