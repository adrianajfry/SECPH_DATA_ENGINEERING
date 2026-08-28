#ifndef RECT_H
#define RECT_H

#include "shape.hpp"

class Rect : public Shape
{
protected:
    int width, height;

public:
    Rect(int _x = 0, int _y = 0, int _width = 0, int _height=0);

    int getWidth() const;

    int getHeight() const;

    void draw() override;

    void resize(int amount) override;
};

#endif