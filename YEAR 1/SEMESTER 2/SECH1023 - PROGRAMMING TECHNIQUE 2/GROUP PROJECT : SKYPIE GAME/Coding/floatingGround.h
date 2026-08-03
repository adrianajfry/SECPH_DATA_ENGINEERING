#ifndef FLOATING_GROUND_H
#define FLOATING_GROUND_H

#include "GameElement.h"

class FloatingGround : public GameElement {
public:
    FloatingGround(int x, int y) : GameElement(x, y), hasCookie(false) {}

    void interact() override {}
    void draw() const override;

    bool hasCookie; // Added member variable
};

#endif // FLOATING_GROUND_H