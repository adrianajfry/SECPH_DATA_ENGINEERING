#ifndef CLOUD_H
#define CLOUD_H

#include "GameElement.h"

class Cloud : public GameElement {
public:
    Cloud(int x, int y) : GameElement(x, y), isSelected(false) {}

    void interact() override {}
    void draw() const override;

    bool isSelected; // To track if the cloud is selected
};

#endif // CLOUD_H